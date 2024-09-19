/****************************************************************************
 * arch/xtensa/src/common/xtensa_cpupause.c
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

#include <nuttx/config.h>

#include <stdint.h>
#include <assert.h>

#include <nuttx/arch.h>
#include <nuttx/sched.h>
#include <nuttx/spinlock.h>
#include <nuttx/sched_note.h>

#include "xtensa.h"
#include "sched/sched.h"

#ifdef CONFIG_SMP

/****************************************************************************
 * Private Data
 ****************************************************************************/

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: xtensa_pause_handler
 *
 * Description:
 *   This is the handler for CPU_INTCODE_PAUSE CPU interrupt.  This
 *   implements up_cpu_pause() by performing the following operations:
 *
 *   1. The current task state at the head of the current assigned task
 *      list was saved when the interrupt was entered.
 *   2. This function simply waits on a spinlock, then returns.
 *   3. Upon return, the interrupt exit logic will restore the state of
 *      the new task at the head of the ready to run list.
 *
 * Input Parameters:
 *   None
 *
 * Returned Value:
 *   None
 *
 ****************************************************************************/

void xtensa_pause_handler(int irq, void *context, void *arg)
{
  nxsched_smp_call_handler(irq, context, arg);
  nxsched_process_delivered(this_cpu());
}

/****************************************************************************
 * Name: up_cpu_pause_async
 *
 * Description:
 *   pause task execution on the CPU
 *   check whether there are tasks delivered to specified cpu
 *   and try to run them.
 *
 * Input Parameters:
 *   cpu - The index of the CPU to be paused.
 *
 * Returned Value:
 *   Zero on success; a negated errno value on failure.
 *
 * Assumptions:
 *   Called from within a critical section;
 *
 ****************************************************************************/

inline_function int up_cpu_pause_async(int cpu)
{
  /* Execute the intercpu interrupt */

  xtensa_intercpu_interrupt(cpu, CPU_INTCODE_PAUSE);

  return OK;
}

/****************************************************************************
 * Name: up_send_smp_call
 *
 * Description:
 *   Send smp call to target cpu.
 *
 * Input Parameters:
 *   cpuset - The set of CPUs to receive the SGI.
 *
 * Returned Value:
 *   None.
 *
 ****************************************************************************/

void up_send_smp_call(cpu_set_t cpuset)
{
  int cpu;

  for (; cpuset != 0; cpuset &= ~(1 << cpu))
    {
      cpu = ffs(cpuset) - 1;
      up_cpu_pause_async(cpu);
    }
}

#endif /* CONFIG_SMP */
