/****************************************************************************
 * libs/libc/net/lib_nametoindex.c
 *
 * SPDX-License-Identifier: Apache-2.0
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

#include <net/if.h>
#include <sys/ioctl.h>
#include <string.h>
#include <unistd.h>

#include <netinet/in.h>
#include <nuttx/net/netconfig.h>

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: if_nametoindex
 *
 * Description:
 *   The if_nametoindex() function returns the interface index corresponding
 *   to name ifname.
 *
 * Input Parameters:
 *   ifname - The interface name
 *
 * Returned Value:
 *   The corresponding index if ifname is the name of an interface;
 *   otherwise, zero.  Although not specified, the errno value will be set.
 *
 ****************************************************************************/

unsigned int if_nametoindex(FAR const char *ifname)
{
  int sockfd = socket(NET_SOCK_FAMILY, NET_SOCK_TYPE, NET_SOCK_PROTOCOL);
  if (sockfd >= 0)
    {
      struct ifreq req;
      strlcpy(req.ifr_name, ifname, IF_NAMESIZE);
      if (ioctl(sockfd, SIOCGIFINDEX, (unsigned long)&req) >= 0)
        {
          close(sockfd);
          return req.ifr_ifindex;
        }

      close(sockfd);
    }

  return 0;
}
