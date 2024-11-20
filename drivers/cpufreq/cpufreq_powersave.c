/****************************************************************************
 * drivers/cpufreq/cpufreq_powersave.c
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

#include "cpufreq_internal.h"

/****************************************************************************
 * Private Function Prototypes
 ****************************************************************************/

static void cpufreq_gov_powersave_limits(
                        FAR struct cpufreq_policy *policy);

/****************************************************************************
 * Private Data
 ****************************************************************************/

static struct cpufreq_governor cpufreq_gov_powersave =
{
  .name     = "powersave",
  .limits   = cpufreq_gov_powersave_limits,
};

/****************************************************************************
 * Private Functions
 ****************************************************************************/

static void cpufreq_gov_powersave_limits(
                        FAR struct cpufreq_policy *policy)
{
  cpufreq_driver_target(policy, policy->min, CPUFREQ_RELATION_L);
}

/****************************************************************************
 * Public Functions
 ****************************************************************************/

FAR struct cpufreq_governor *cpufreq_default_governor(void)
{
  return &cpufreq_gov_powersave;
}
