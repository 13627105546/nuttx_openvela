/****************************************************************************
 * drivers/cpufreq/cpufreq.c
 *
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.  The
 * ASF licenses this file to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance with the
 * License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  See the
 * License for the specific language governing permissions and limitations
 * under the License.
 *
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <debug.h>

#include <nuttx/kmalloc.h>
#include <nuttx/notifier.h>
#include <nuttx/sched.h>

#include "cpufreq_internal.h"

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

#define KHZ_PER_MHZ      1000ul

/****************************************************************************
 * Private Data
 ****************************************************************************/

static FAR struct cpufreq_policy *g_cpufreq_policy;

/****************************************************************************
 * Private Function Prototypes
 ****************************************************************************/

static int cpufreq_init_governor(FAR struct cpufreq_policy *policy);
static void cpufreq_exit_governor(FAR struct cpufreq_policy *policy);
static int cpufreq_start_governor(FAR struct cpufreq_policy *policy);
static void cpufreq_stop_governor(FAR struct cpufreq_policy *policy);
static void cpufreq_limits_governor(FAR struct cpufreq_policy *policy);

static int cpufreq_refresh_limits(FAR struct cpufreq_policy *policy);
static int cpufreq_verify_current_freq(FAR struct cpufreq_policy *policy);

static int cpufreq_notifier_min(FAR struct notifier_block *nb,
                                unsigned long freq, FAR void *data);
static int cpufreq_notifier_max(FAR struct notifier_block *nb,
                                unsigned long freq, FAR void *data);
static FAR struct cpufreq_policy *cpufreq_policy_alloc(void);
static void cpufreq_policy_free(FAR struct cpufreq_policy *policy);

/****************************************************************************
 * Private Functions
 ****************************************************************************/

static int cpufreq_init_governor(FAR struct cpufreq_policy *policy)
{
  int ret;

  /* Governor might not be initiated here if ACPI _PPC changed
   * notification happened, so check it.
   */

  if (!policy->governor)
    {
      return -EINVAL;
    }

  if (policy->governor->init)
    {
      ret = policy->governor->init(policy);
      if (ret < 0)
        {
          return ret;
        }
    }

  return 0;
}

static void cpufreq_exit_governor(FAR struct cpufreq_policy *policy)
{
  if (policy->suspended || !policy->governor)
    {
      return;
    }

  if (policy->governor->exit)
    {
      policy->governor->exit(policy);
    }
}

static int cpufreq_start_governor(FAR struct cpufreq_policy *policy)
{
  int ret;

  if (policy->suspended)
    {
      return 0;
    }

  if (!policy->governor)
    {
      return -EINVAL;
    }

  ret = cpufreq_verify_current_freq(policy);
  if (ret < 0)
    {
      return ret;
    }

  if (policy->governor->start)
    {
      ret = policy->governor->start(policy);
      if (ret < 0)
        {
          return ret;
        }
    }

  if (policy->governor->limits)
    {
      policy->governor->limits(policy);
    }

  return 0;
}

static void cpufreq_stop_governor(FAR struct cpufreq_policy *policy)
{
  if (policy->suspended || !policy->governor)
    {
      return;
    }

  if (policy->governor->stop)
    {
      policy->governor->stop(policy);
    }
}

static void cpufreq_limits_governor(FAR struct cpufreq_policy *policy)
{
  if (policy->suspended || !policy->governor)
    {
      return;
    }

  if (policy->governor->limits)
    {
      policy->governor->limits(policy);
    }
}

static int cpufreq_refresh_limits(FAR struct cpufreq_policy *policy)
{
  struct cpufreq_verify cv;
  int ret;

  /* PM QoS framework collects all the requests from users and provide us
   * the final aggregated value here.
   */

  nxmutex_lock(&policy->lock);

  cv.min = freq_qos_read_value(&policy->constraints, FREQ_QOS_MIN);
  cv.max = freq_qos_read_value(&policy->constraints, FREQ_QOS_MAX);

  /* Verify that the CPU speed can be set within these limits and make sure
   * that min <= max.
   */

  ret = cpufreq_table_verify(policy, &cv);
  if (ret < 0)
    {
      nxmutex_unlock(&policy->lock);
      return ret;
    }

  /* Resolve policy min/max to available frequencies. It ensures
   * no frequency resolution will neither overshoot the requested maximum
   * nor undershoot the requested minimum.
   */

  policy->min = cv.min;
  policy->max = cv.max;
  policy->min = cpufreq_table_resolve_freq(policy, cv.min,
                                           CPUFREQ_RELATION_L, NULL);
  policy->max = cpufreq_table_resolve_freq(policy, cv.max,
                                           CPUFREQ_RELATION_H, NULL);

  pwrinfo("user requests (%u-%u) KHz, limits (%u-%u) kHz\n",
          cv.min, cv.max, policy->min, policy->max);

  nxmutex_unlock(&policy->lock);
  cpufreq_limits_governor(policy);
  return 0;
}

static int cpufreq_verify_current_freq(FAR struct cpufreq_policy *policy)
{
  int new_freq;

  new_freq = policy->driver->get_frequency(policy);
  if (new_freq <= 0)
    {
      return new_freq;
    }

  if (policy->cur != new_freq)
    {
      if (abs(policy->cur - new_freq) >= KHZ_PER_MHZ)
        {
          return cpufreq_refresh_limits(policy);
        }
    }

  return 0;
}

static int cpufreq_notifier_min(FAR struct notifier_block *nb,
                                unsigned long freq, FAR void *data)
{
  FAR struct cpufreq_policy *policy =
      container_of(nb, struct cpufreq_policy, nb_min);

  cpufreq_refresh_limits(policy);
  return 0;
}

static int cpufreq_notifier_max(FAR struct notifier_block *nb,
                                unsigned long freq, FAR void *data)
{
  FAR struct cpufreq_policy *policy =
      container_of(nb, struct cpufreq_policy, nb_max);

  cpufreq_refresh_limits(policy);
  return 0;
}

static FAR struct cpufreq_policy *cpufreq_policy_alloc(void)
{
  FAR struct cpufreq_policy *policy;
  int ret;

  policy = kmm_zalloc(sizeof(*policy));
  if (!policy)
    {
      return NULL;
    }

  freq_constraints_init(&policy->constraints);

  policy->nb_min.notifier_call = cpufreq_notifier_min;
  policy->nb_max.notifier_call = cpufreq_notifier_max;

  ret = freq_qos_add_notifier(&policy->constraints, FREQ_QOS_MIN,
                              &policy->nb_min);
  if (ret < 0)
    {
      goto err_min_qos_notifier;
    }

  ret = freq_qos_add_notifier(&policy->constraints, FREQ_QOS_MAX,
                              &policy->nb_max);
  if (ret < 0)
    {
      goto err_max_qos_notifier;
    }

  /* This must be initialized right here to avoid calling
   * freq_qos_remove_request() on uninitialized request in case
   * of errors.
   */

  ret = freq_qos_add_request(&policy->constraints, &policy->min_freq_req,
                             FREQ_QOS_MIN, FREQ_QOS_MIN_DEFAULT_VALUE);
  if (ret < 0)
    {
      /* So we don't call freq_qos_remove_request() for an
       * uninitialized request.
       */

      goto err_min_qos_request;
    }

  ret = freq_qos_add_request(&policy->constraints, &policy->max_freq_req,
                             FREQ_QOS_MAX, FREQ_QOS_MAX_DEFAULT_VALUE);
  if (ret < 0)
    {
      goto err_max_qos_request;
    }

  nxmutex_init(&policy->lock);
  BLOCKING_INIT_NOTIFIER_HEAD(&policy->notifier_list);
#ifdef CONFIG_CPUFREQ_PROCFS_QOS
  list_initialize(&policy->qos_list);
#endif

  return policy;

err_max_qos_request:
  freq_qos_remove_request(&policy->min_freq_req);
err_min_qos_request:
  freq_qos_remove_notifier(&policy->constraints, FREQ_QOS_MAX,
                           &policy->nb_max);
err_max_qos_notifier:
  freq_qos_remove_notifier(&policy->constraints, FREQ_QOS_MIN,
                           &policy->nb_min);
err_min_qos_notifier:
  kmm_free(policy);
  return NULL;
}

static void cpufreq_policy_free(FAR struct cpufreq_policy *policy)
{
  nxmutex_destroy(&policy->lock);

  freq_qos_remove_notifier(&policy->constraints, FREQ_QOS_MAX,
                           &policy->nb_max);
  freq_qos_remove_notifier(&policy->constraints, FREQ_QOS_MIN,
                           &policy->nb_min);

  /* Remove max_freq_req after sending CPUFREQ_REMOVE_POLICY
   * notification, since CPUFREQ_CREATE_POLICY notification was
   * sent after adding max_freq_req earlier.
   */

  freq_qos_remove_request(&policy->max_freq_req);
  freq_qos_remove_request(&policy->min_freq_req);

  kmm_free(policy);
}

/****************************************************************************
 * Public Functions
 ****************************************************************************/

int cpufreq_driver_target(FAR struct cpufreq_policy *policy,
                          unsigned int target_freq,
                          unsigned int relation)
{
  struct cpufreq_freqs freqs;
  unsigned int idx;
  int ret;

  if (!policy)
    {
      return -EINVAL;
    }

  target_freq = cpufreq_table_resolve_freq(policy, target_freq,
                                           relation, &idx);
  if (target_freq == policy->cur)
    {
      return 0;
    }

  freqs.old = policy->cur;
  freqs.new = target_freq;
  pwrinfo("target old %u new %u KHz\n", freqs.old, freqs.new);

  blocking_notifier_call_chain(&policy->notifier_list,
                               CPUFREQ_PRECHANGE, &freqs);
  ret = policy->driver->target_index(policy, idx);
  blocking_notifier_call_chain(&policy->notifier_list,
                               CPUFREQ_POSTCHANGE, &freqs);
  if (ret < 0)
    {
      pwrerr("Failed to change cpu frequency: %u to %u, ret %d\n",
             freqs.old, freqs.new, ret);

      freqs.old = target_freq;
      freqs.new = policy->cur;
      blocking_notifier_call_chain(&policy->notifier_list,
                                   CPUFREQ_PRECHANGE, &freqs);
      blocking_notifier_call_chain(&policy->notifier_list,
                                    CPUFREQ_POSTCHANGE, &freqs);

      return ret;
    }

  policy->cur = target_freq;
  return 0;
}

int cpufreq_init(FAR struct cpufreq_driver *driver)
{
  FAR struct cpufreq_policy *policy;
  int ret;

  if (!driver || !driver->get_table || !driver->get_frequency ||
      !driver->target_index)
    {
      return -EINVAL;
    }

  policy = cpufreq_policy_alloc();
  if (!policy)
    {
      return -ENOMEM;
    }

  policy->governor = cpufreq_default_governor();
  if (!policy->governor)
    {
      ret = -EPERM;
      goto out_free_policy;
    }

  policy->driver = driver;
  policy->freq_table = driver->get_table(policy);
  if (!policy->freq_table)
    {
      ret = -EPERM;
      goto out_free_policy;
    }

  /* The initialization has succeeded and the policy is online.
   * If there is a problem with its frequency table, take it
   * offline and drop it.
   */

  ret = cpufreq_table_validate(policy);
  if (ret < 0)
    {
      goto out_free_policy;
    }

  policy->cur = policy->driver->get_frequency(policy);
  ret = cpufreq_table_get_index(policy, policy->cur);
  if (ret == -EINVAL)
    {
      ret = cpufreq_driver_target(policy, policy->cur - 1,
                                  CPUFREQ_RELATION_L);
      DEBUGASSERT(ret == 0);
    }

  ret = cpufreq_init_governor(policy);
  if (ret < 0)
    {
      goto out_free_policy;
    }

  ret = cpufreq_start_governor(policy);
  if (ret < 0)
    {
      goto out_free_policy;
    }

  g_cpufreq_policy = policy;
  return 0;

out_free_policy:
  cpufreq_policy_free(policy);
  return ret;
}

int cpufreq_uninit(void)
{
  FAR struct cpufreq_policy *policy = cpufreq_policy_get();

  if (!policy)
    {
      return -EINVAL;
    }

  cpufreq_stop_governor(policy);
  cpufreq_exit_governor(policy);
  cpufreq_policy_free(policy);
  return 0;
}

FAR struct cpufreq_policy *cpufreq_policy_get(void)
{
  return g_cpufreq_policy;
}

int cpufreq_suspend(FAR struct cpufreq_policy *policy)
{
  int ret;

  cpufreq_stop_governor(policy);
  if (policy->driver->suspend)
    {
      ret = policy->driver->suspend(policy);
      if (ret < 0)
        {
          return ret;
        }
    }

  policy->suspended = true;
  return 0;
}

int cpufreq_resume(FAR struct cpufreq_policy *policy)
{
  int ret;

  if (!policy)
    {
      return -EINVAL;
    }

  if (!policy->suspended)
    {
      return 0;
    }

  policy->suspended = false;

  if (policy->driver->resume)
    {
      ret = policy->driver->resume(policy);
      if (ret < 0)
        {
          pwrerr("Failed to resume driver: %p\n", policy);
          return ret;
        }
    }

  ret = cpufreq_start_governor(policy);
  if (ret < 0)
    {
      pwrerr("Failed to start governor for policy: %p\n", policy);
      return ret;
    }

  return 0;
}

int cpufreq_register_notifier(FAR struct cpufreq_policy *policy,
                              FAR struct notifier_block *nb)
{
  if (!policy || !nb)
    {
      return -EINVAL;
    }

  nxmutex_lock(&policy->lock);
  blocking_notifier_chain_register(&policy->notifier_list, nb);
  nxmutex_unlock(&policy->lock);
  return 0;
}

int cpufreq_unregister_notifier(FAR struct cpufreq_policy *policy,
                                FAR struct notifier_block *nb)
{
  if (!policy || !nb)
    {
      return -EINVAL;
    }

  nxmutex_lock(&policy->lock);
  blocking_notifier_chain_unregister(&policy->notifier_list, nb);
  nxmutex_unlock(&policy->lock);
  return 0;
}

int cpufreq_get(FAR struct cpufreq_policy *policy)
{
  if (!policy)
    {
      return -EINVAL;
    }

  return policy->driver->get_frequency(policy);
}

FAR struct cpufreq_qos *cpufreq_qos_add_request(
                            FAR struct cpufreq_policy *policy,
                            unsigned int min, unsigned int max)
{
  FAR struct cpufreq_qos *qos;
  int ret;

  if (!policy)
    {
      return NULL;
    }

  qos = kmm_zalloc(sizeof(struct cpufreq_qos));
  if (!qos)
    {
      return NULL;
    }

  ret = freq_qos_add_request(&policy->constraints,
                             &qos->min, FREQ_QOS_MIN, min);
  if (ret < 0)
    {
      goto out;
    }

  ret = freq_qos_add_request(&policy->constraints,
                             &qos->max, FREQ_QOS_MAX, max);
  if (ret < 0)
    {
      freq_qos_remove_request(&qos->min);
      goto out;
    }

#ifdef CONFIG_CPUFREQ_PROCFS_QOS
  qos->caller = return_address(0);
  list_add_tail(&policy->qos_list, &qos->node);
#endif

  return qos;

out:
  kmm_free(qos);
  return NULL;
}

int cpufreq_qos_update_request(FAR struct cpufreq_qos *qos,
                               unsigned int min, unsigned int max)
{
  int ret;

  if (!qos)
    {
      return -EINVAL;
    }

  ret = freq_qos_apply(&qos->min, PM_QOS_UPDATE_REQ, min);
  if (ret < 0)
    {
      return ret;
    }

  ret = freq_qos_apply(&qos->max, PM_QOS_UPDATE_REQ, max);
  if (ret < 0)
    {
      return ret;
    }

  return 0;
}

int cpufreq_qos_remove_request(FAR struct cpufreq_qos *qos)
{
  if (!qos)
    {
      return -EINVAL;
    }

  freq_qos_remove_request(&qos->min);
  freq_qos_remove_request(&qos->max);

#ifdef CONFIG_CPUFREQ_PROCFS_QOS
  list_delete(&qos->node);
#endif

  kmm_free(qos);
  return 0;
}

int cpufreq_table_count_valid_entries(FAR struct cpufreq_policy *policy)
{
  FAR const struct cpufreq_frequency_table *pos;
  int count = 0;

  if (policy == NULL || policy->freq_table == NULL)
    {
      return 0;
    }

  pos = policy->freq_table;
  for (; pos->frequency != CPUFREQ_TABLE_END; pos++)
    {
      if (pos->frequency == CPUFREQ_ENTRY_INVALID)
        {
          continue;
        }
      else
        {
          count++;
        }
    }

  return count;
}
