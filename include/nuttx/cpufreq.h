/****************************************************************************
 * include/nuttx/cpufreq.h
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

#ifndef __INCLUDE_NUTTX_CPUFREQ_H
#define __INCLUDE_NUTTX_CPUFREQ_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/notifier.h>
#include <sys/types.h>

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

#define CPUFREQ_PRECHANGE       (0)
#define CPUFREQ_POSTCHANGE      (1)

/* Special Values of .frequency field */

#define CPUFREQ_ENTRY_INVALID       ~0u
#define CPUFREQ_TABLE_END           ~1u

/****************************************************************************
 * Public Types
 ****************************************************************************/

struct cpufreq_frequency_table
{
  unsigned int frequency;       /* kHz - should be in order */
};

struct cpufreq_freqs
{
  unsigned int old;
  unsigned int new;
};

struct cpufreq_driver
{
  FAR const struct cpufreq_frequency_table *
      (*get_table)(FAR struct cpufreq_driver *driver);
  int (*target_index)(FAR struct cpufreq_driver *driver, unsigned int index);
  int (*get_frequency)(FAR struct cpufreq_driver *driver);
  int (*suspend)(FAR struct cpufreq_driver *driver);
  int (*resume)(FAR struct cpufreq_driver *driver);
};

struct cpufreq_policy;
struct cpufreq_qos;

/****************************************************************************
 * Public Function Prototypes
 ****************************************************************************/

/**
 * cpufreq_int - init cpufreq with driver
 * @driver: lower driver
 */

int cpufreq_init(FAR struct cpufreq_driver *driver);

/**
 * cpufreq_unint - uninit cpufreq
 */

int cpufreq_uninit(void);

/**
 * cpufreq_plicy_get - get cpufreq_policy handler
 */

FAR struct cpufreq_policy *cpufreq_policy_get(void);

/**
 * cpufreq_suspend() - Suspend CPUFreq governors.
 * @policy: cpufreq_policy handle
 *
 * Called during system wide Suspend/Hibernate cycles for suspending
 * governors as some platforms can't change frequency after this
 * point in suspend cycle.
 * Because some of the devices (like: i2c, regulators, etc) they use
 * for changing frequency are suspended quickly after this point.
 */

int cpufreq_suspend(FAR struct cpufreq_policy *policy);

/**
 * cpufreq_resume() - Resume CPUFreq governors.
 * @policy: cpufreq_policy handle
 *
 * Called during system wide Suspend/Hibernate cycle for resuming governors
 *that
 * are suspended with cpufreq_suspend().
 */

int cpufreq_resume(FAR struct cpufreq_policy *policy);

/**
 * cpufreq_register_notifier - Register a notifier with cpufreq.
 * @policy: cpufreq_policy handle
 * @nb: notifier function to register.
 *
 * Add a notifier to one of two lists: either a list of notifiers that run on
 * clock rate changes (once before and once after every transition), or a
 * list of notifiers that ron on cpufreq policy changes.
 *
 * This function may sleep and it has the same return values as
 * blocking_notifier_chain_register().
 */

int cpufreq_register_notifier(FAR struct cpufreq_policy *policy,
                              FAR struct notifier_block *nb);

/**
 * cpufreq_unregister_notifier - Unregister a notifier from cpufreq.
 * @policy: cpufreq_policy handle
 * @nb: notifier block to be unregistered.
 *
 * Remove a notifier from one of the cpufreq notifier lists.
 *
 * This function may sleep and it has the same return values as
 * blocking_notifier_chain_unregister().
 */

int cpufreq_unregister_notifier(FAR struct cpufreq_policy *policy,
                                FAR struct notifier_block *nb);

/**
 * cpufreq_get - get the current CPU frequency (in kHz)
 * @policy: cpufreq_policy handle
 *
 * Get the CPU current (static) CPU frequency
 */

unsigned int cpufreq_get(FAR struct cpufreq_policy *policy);

/**
 * cpufreq_qos_add_request - Insert new frequency QoS request
 * @policy: cpufreq_policy handle
 * @min: min freq
 * @max: max freq
 *
 * Insert a new entry into the @qos list of requests, recompute the effective
 * QoS constraint value for that list and initialize the @req object.  The
 * caller needs to save that object for later use in updates and removal.
 *
 * Return qos handle for update and remove, or NULL if fail
 */

FAR struct cpufreq_qos *cpufreq_qos_add_request(
                            FAR struct cpufreq_policy *policy,
                            unsigned int min, unsigned int max);

/**
 * cpufreq_qos_update_request - Update frequency QoS request from its list.
 * @qos: Request to remove.
 * @min: min freq
 * @max: max freq
 *
 * Update an existing frequency QoS request along with the effective
 * constraint value for the list of requests it belongs to.
 */

int cpufreq_qos_update_request(FAR struct cpufreq_qos *qos,
                               unsigned int min, unsigned int max);

/**
 * cpufreq_qos_remove_request - Remove frequency QoS request from its list.
 * @qos: Request to remove.
 *
 * Remove the given frequency QoS request from the list of constraints it
 * belongs to and recompute the effective constraint value for that list.
 */

int cpufreq_qos_remove_request(FAR struct cpufreq_qos *qos);

#endif /* __INCLUDE_NUTTX_CPUFREQ_H */
