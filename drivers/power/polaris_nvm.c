/****************************************************************************
 * drivers/power/polaris_nvm.c
 *
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements. See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership. The
 * ASF licenses this file to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance with the
 * License. You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
 * License for the specific language governing permissions and limitations
 * under the License.
 *
 ****************************************************************************/

/****************************************************************************
 * The STWLC38 are Li-Ion Battery management
 *
 * This driver requires:
 *
 * CONFIG_BATTERY_CHARGER - Upper half battery driver support
 * CONFIG_I2C - I2C support
 * CONFIG_I2C_STWLC38 - And the driver must be explicitly selected.
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

#ifndef NVM_DATA_H
#define NVM_DATA_H
#define NVM_TARGET_CUT_ID     3
#define NVM_CFG_SIZE          384
#define NVM_CFG_VERSION_ID    0x2001
#define NVM_PATCH_SIZE        4272
#define NVM_PATCH_VERSION_ID  0x1251

/****************************************************************************
 * Private Functions
 ****************************************************************************/

const uint8_t cfg_data[] =
{
  0x01, 0x20, 0x00, 0x00, 0x77, 0x10, 0x00, 0x01,
  0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x14, 0x44,
  0x44, 0x44, 0x00, 0x00, 0x00, 0x3c, 0x00, 0x00,
  0x63, 0x00, 0x03, 0x0d, 0x5a, 0x0a, 0x00, 0xff,
  0x43, 0x0f, 0x08, 0x3f, 0x03, 0x00, 0x0d, 0x08,
  0x17, 0x12, 0x0a, 0x00, 0x82, 0x82, 0x82, 0x82,
  0x50, 0x8a, 0x8a, 0x8a, 0x8a, 0x69, 0x07, 0x06,
  0x12, 0x00, 0x2d, 0x00, 0x00, 0x00, 0x00, 0x40,
  0x23, 0x1e, 0x2c, 0x42, 0x58, 0x6e, 0x84, 0x04,
  0x04, 0x04, 0x04, 0x04, 0x04, 0x7d, 0x7d, 0x7d,
  0x7d, 0x7d, 0x7d, 0xc8, 0x08, 0x03, 0x05, 0x07,
  0x19, 0x8a, 0xbe, 0x00, 0x25, 0x06, 0x03, 0x00,
  0x28, 0x0a, 0x00, 0x00, 0x00, 0x0a, 0x00, 0x00,
  0x08, 0x94, 0x02, 0x00, 0x08, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x02, 0x00, 0x55, 0x5f, 0xa5, 0x6b,
  0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x19, 0x00, 0x00, 0x00, 0x07, 0x19,
  0x11, 0x00, 0x02, 0x00, 0x6e, 0x11, 0x22, 0x33,
  0x44, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77,
  0x88, 0x05, 0x1e, 0x00, 0x12, 0x84, 0x1e, 0x5d,
  0x5d, 0x54, 0x80, 0x37, 0x9c, 0x14, 0x8e, 0x10,
  0x08, 0x04, 0x03, 0x11, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x0a, 0x00, 0xd0, 0x00,
  0x05, 0x00, 0xfa, 0x00, 0xf0, 0x28, 0x0e, 0x05,
  0xd4, 0x00, 0x18, 0x00, 0x00, 0x01, 0x00, 0x03,
  0x1e, 0x00, 0xf4, 0x01, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe1, 0x00,
  0x22, 0xc3, 0x05, 0x06, 0x09, 0x0d, 0x03, 0x1e,
  0x96, 0x01, 0x06, 0x2d, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x0c, 0x63, 0x20, 0x32, 0xdf, 0xff, 0x03, 0x00,
  0x22, 0x24, 0xdb, 0x1a, 0xf6, 0x20, 0x32, 0x18,
  0x32, 0x32, 0x50, 0x30, 0x28, 0x14, 0x55, 0xa3,
  0x00, 0x03, 0x1e, 0xc8, 0xa5, 0x0f, 0x14, 0x1e,
  0x32, 0x32, 0x19, 0x28, 0x37, 0x02, 0x00, 0x0a,
  0x1e, 0x1e, 0x0c, 0x00, 0x00, 0x00, 0x18, 0x00,
  0xff, 0x50, 0x38, 0x00, 0x0f, 0x2c, 0x51, 0x64,
  0x04, 0x3e, 0x0a, 0x53, 0x0a, 0x66, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x60, 0xe9, 0x17, 0x00, 0x72, 0x29, 0x17, 0x00,
  0x03, 0x11, 0x1a, 0x00, 0x03, 0x11, 0x1a, 0x00,
  0x00, 0x1a, 0x1d, 0x1d, 0x10, 0x10, 0x10, 0x10,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0xc5, 0xbe, 0x19, 0x91,
};

const uint8_t patch_data[] =
{
  0x2b, 0x04, 0xd4, 0xfb, 0xf8, 0xb5, 0x3e, 0x48,
  0x81, 0x69, 0xc9, 0x06, 0x04, 0xd5, 0x81, 0x69,
  0x10, 0x22, 0x91, 0x43, 0x81, 0x61, 0xf8, 0xbd,
  0x3b, 0x49, 0x3a, 0x48, 0x49, 0x68, 0x3a, 0x4f,
  0x88, 0x71, 0x00, 0x0a, 0xc8, 0x71, 0xc0, 0x3f,
  0x78, 0x6b, 0x10, 0x30, 0x81, 0x08, 0x37, 0x48,
  0x81, 0x63, 0x36, 0x49, 0x36, 0x4a, 0x80, 0x31,
  0x8a, 0x63, 0x7a, 0x6b, 0x6c, 0x32, 0x92, 0x08,
  0xc2, 0x63, 0x34, 0x4a, 0xca, 0x63, 0x30, 0x4d,
  0x40, 0x3d, 0x29, 0x6b, 0x09, 0x1d, 0x8a, 0x08,
  0x2e, 0x49, 0x40, 0x31, 0x0a, 0x60, 0x2d, 0x4a,
  0x2f, 0x4b, 0xc0, 0x32, 0x13, 0x60, 0x28, 0x23,
  0x8b, 0x60, 0x2e, 0x49, 0x91, 0x60, 0x2e, 0x21,
  0x01, 0x63, 0x2f, 0x4e, 0x9c, 0x22, 0x2c, 0x49,
  0x2c, 0x48, 0xb0, 0x47, 0x2b, 0x48, 0x2d, 0x49,
  0x80, 0x30, 0x01, 0x60, 0x2c, 0x49, 0x80, 0x38,
  0x01, 0x61, 0x21, 0x49, 0x80, 0x39, 0x08, 0x60,
  0x2a, 0x48, 0x00, 0x24, 0x04, 0x70, 0x2a, 0x48,
  0x04, 0x70, 0x2a, 0x48, 0xf8, 0x61, 0x1c, 0x4f,
  0x29, 0x48, 0x40, 0x37, 0x38, 0x60, 0x3c, 0x22,
  0x28, 0x49, 0x29, 0x48, 0xb0, 0x47, 0x28, 0x48,
  0x28, 0x49, 0xc1, 0x61, 0x28, 0x49, 0x01, 0x62,
  0x28, 0x49, 0x81, 0x63, 0x28, 0x49, 0x81, 0x60,
  0xe8, 0x63, 0x00, 0xf0, 0x27, 0xfc, 0x27, 0x48,
  0xc1, 0x7c, 0x11, 0x4a, 0xc9, 0x09, 0xd2, 0x68,
  0xc9, 0x01, 0x12, 0x7a, 0x52, 0x06, 0x52, 0x0e,
  0x11, 0x43, 0xc1, 0x74, 0x22, 0x48, 0x04, 0x70,
  0x22, 0x48, 0x04, 0x70, 0x22, 0x48, 0xf8, 0x60,
  0x22, 0x48, 0x28, 0x61, 0x20, 0x22, 0x22, 0x49,
  0x22, 0x48, 0xb0, 0x47, 0x21, 0x48, 0x22, 0x49,
  0x41, 0x60, 0x22, 0x49, 0x01, 0x60, 0x22, 0x49,
  0x48, 0x61, 0x22, 0x48, 0xc8, 0x60, 0xf8, 0xbd,
  0x00, 0xfc, 0x01, 0x20, 0x51, 0x12, 0x00, 0x00,
  0x80, 0x05, 0x05, 0x00, 0x00, 0xc0, 0x01, 0x20,
  0x49, 0x08, 0x08, 0x00, 0x61, 0x08, 0x08, 0x00,
  0xf9, 0x10, 0x05, 0x00, 0xed, 0x10, 0x05, 0x00,
  0x50, 0x7c, 0x04, 0x00, 0xe8, 0x0d, 0x05, 0x00,
  0x47, 0x6e, 0x04, 0x00, 0x8d, 0x08, 0x08, 0x00,
  0xa3, 0x08, 0x08, 0x00, 0xb3, 0x0d, 0x05, 0x00,
  0xb4, 0x0d, 0x05, 0x00, 0x54, 0x0c, 0x08, 0x00,
  0x04, 0x0d, 0x08, 0x00, 0xbc, 0x7e, 0x04, 0x00,
  0x84, 0x0e, 0x05, 0x00, 0x91, 0x11, 0x05, 0x00,
  0xad, 0x11, 0x05, 0x00, 0xe9, 0x11, 0x05, 0x00,
  0x05, 0x12, 0x05, 0x00, 0x40, 0xc1, 0x01, 0x20,
  0xb0, 0x0d, 0x05, 0x00, 0xb1, 0x0d, 0x05, 0x00,
  0x24, 0x0d, 0x08, 0x00, 0xf4, 0x0c, 0x08, 0x00,
  0x94, 0x7a, 0x04, 0x00, 0xc8, 0x0d, 0x05, 0x00,
  0x85, 0x02, 0x08, 0x00, 0xb5, 0x02, 0x08, 0x00,
  0x80, 0x04, 0x05, 0x00, 0x44, 0x0c, 0x08, 0x00,
  0x40, 0xba, 0x70, 0x47, 0x40, 0xba, 0x70, 0x47,
  0xc0, 0xba, 0x70, 0x47, 0xc0, 0xba, 0x70, 0x47,
  0x2f, 0x49, 0x0a, 0x78, 0x52, 0x08, 0x52, 0x00,
  0x0a, 0x70, 0x00, 0x28, 0x03, 0xd0, 0x08, 0x78,
  0x04, 0x22, 0x10, 0x43, 0x08, 0x70, 0x02, 0x20,
  0x08, 0x72, 0x2a, 0x49, 0x00, 0x20, 0x48, 0x60,
  0x48, 0x70, 0x70, 0x47, 0xf8, 0xb5, 0x26, 0x4c,
  0x05, 0x21, 0x61, 0x70, 0xc8, 0x21, 0x21, 0x70,
  0x88, 0x21, 0x21, 0x70, 0x00, 0x25, 0xa5, 0x70,
  0x65, 0x81, 0x22, 0x4e, 0x22, 0x4f, 0xb0, 0x60,
  0x39, 0x46, 0x00, 0xf0, 0x79, 0xfc, 0x40, 0x1e,
  0xa0, 0x81, 0xe5, 0x81, 0x25, 0x82, 0xa5, 0x74,
  0xa5, 0x82, 0x00, 0x20, 0xff, 0xf7, 0xd4, 0xff,
  0xa0, 0x79, 0x20, 0x72, 0x02, 0x20, 0x20, 0x71,
  0x01, 0x20, 0x30, 0x70, 0x19, 0x48, 0x45, 0x60,
  0x07, 0x60, 0x85, 0x60, 0xf8, 0xbd, 0x17, 0x49,
  0x0e, 0xc9, 0x0e, 0xc0, 0x70, 0x47, 0x12, 0x49,
  0x00, 0x28, 0x48, 0x78, 0x03, 0xd0, 0x80, 0x22,
  0x10, 0x43, 0x48, 0x70, 0x70, 0x47, 0x40, 0x06,
  0x40, 0x0e, 0xfa, 0xe7, 0x0c, 0x49, 0x00, 0x28,
  0x48, 0x78, 0x03, 0xd0, 0x02, 0x22, 0x10, 0x43,
  0x48, 0x70, 0x70, 0x47, 0xfd, 0x22, 0x10, 0x40,
  0xfa, 0xe7, 0x07, 0x48, 0x01, 0x78, 0x05, 0x22,
  0x11, 0x43, 0x01, 0x70, 0x70, 0x47, 0x01, 0x20,
  0xa6, 0xe7, 0x04, 0x49, 0x08, 0x70, 0x70, 0x47,
  0x02, 0x48, 0x00, 0x78, 0x70, 0x47, 0x00, 0x00,
  0x00, 0x58, 0x01, 0x20, 0xa4, 0x0d, 0x05, 0x00,
  0x40, 0x42, 0x0f, 0x00, 0xbc, 0x0d, 0x05, 0x00,
  0x10, 0xb5, 0x04, 0x48, 0x80, 0x47, 0x04, 0x48,
  0x41, 0x7d, 0xef, 0x22, 0x11, 0x40, 0x41, 0x75,
  0x10, 0xbd, 0x00, 0x00, 0x59, 0x0c, 0x04, 0x00,
  0x40, 0xc1, 0x01, 0x20, 0x70, 0xb5, 0x05, 0x46,
  0x12, 0x48, 0x80, 0x68, 0xa0, 0x30, 0x01, 0x7d,
  0x88, 0x07, 0x0b, 0xd5, 0x10, 0x48, 0x00, 0x78,
  0x00, 0x28, 0x07, 0xd0, 0x0f, 0x4c, 0xc8, 0x07,
  0x03, 0xd0, 0x01, 0x20, 0x00, 0xf0, 0xe3, 0xf9,
  0x02, 0x20, 0xa0, 0x47, 0x0c, 0x49, 0x28, 0x46,
  0x88, 0x47, 0x70, 0xbd, 0x0a, 0x49, 0x10, 0xb5,
  0x24, 0x31, 0x88, 0x47, 0x05, 0x48, 0x80, 0x68,
  0xa0, 0x30, 0x00, 0x7d, 0x80, 0x07, 0x01, 0xd5,
  0x06, 0x48, 0x80, 0x47, 0x10, 0xbd, 0x03, 0x49,
  0x00, 0x20, 0x08, 0x47, 0x80, 0x05, 0x05, 0x00,
  0xb2, 0x0d, 0x05, 0x00, 0x15, 0x07, 0x04, 0x00,
  0x31, 0x0e, 0x04, 0x00, 0x7b, 0x09, 0x04, 0x00,
  0x70, 0xb5, 0xfb, 0x48, 0xfb, 0x4b, 0xc2, 0x79,
  0xf9, 0x48, 0xfb, 0x4c, 0xc0, 0x30, 0x80, 0x68,
  0x01, 0x46, 0xff, 0x31, 0x61, 0x31, 0x03, 0x2a,
  0x16, 0xd0, 0x02, 0x2a, 0x27, 0xd0, 0x01, 0x2a,
  0x1a, 0x7a, 0x3a, 0xd0, 0xcd, 0x78, 0x52, 0x09,
  0x52, 0x01, 0xed, 0x06, 0xed, 0x0e, 0x2a, 0x43,
  0x1a, 0x72, 0x9a, 0x7a, 0xc9, 0x79, 0x52, 0x09,
  0x52, 0x01, 0xc9, 0x06, 0xc9, 0x0e, 0x0a, 0x43,
  0x9a, 0x72, 0xff, 0x30, 0x5d, 0x30, 0x24, 0xe0,
  0x1a, 0x7a, 0x0d, 0x78, 0x52, 0x09, 0x52, 0x01,
  0xed, 0x06, 0xed, 0x0e, 0x2a, 0x43, 0x1a, 0x72,
  0x9a, 0x7a, 0x09, 0x79, 0x52, 0x09, 0x52, 0x01,
  0xc9, 0x06, 0xc9, 0x0e, 0x0a, 0x43, 0x9a, 0x72,
  0xff, 0x30, 0x51, 0x30, 0x11, 0xe0, 0x1a, 0x7a,
  0x4d, 0x78, 0x52, 0x09, 0x52, 0x01, 0xed, 0x06,
  0xed, 0x0e, 0x2a, 0x43, 0x1a, 0x72, 0x9a, 0x7a,
  0x49, 0x79, 0x52, 0x09, 0x52, 0x01, 0xc9, 0x06,
  0xc9, 0x0e, 0x0a, 0x43, 0x9a, 0x72, 0xff, 0x30,
  0x55, 0x30, 0x00, 0xf0, 0x98, 0xfb, 0xa0, 0x60,
  0x70, 0xbd, 0x8d, 0x78, 0x52, 0x09, 0x52, 0x01,
  0xed, 0x06, 0xed, 0x0e, 0x2a, 0x43, 0x1a, 0x72,
  0x9a, 0x7a, 0x89, 0x79, 0x52, 0x09, 0x52, 0x01,
  0xc9, 0x06, 0xc9, 0x0e, 0x0a, 0x43, 0x9a, 0x72,
  0xff, 0x30, 0x59, 0x30, 0xe9, 0xe7, 0xcc, 0x48,
  0xc0, 0x30, 0x80, 0x68, 0xa0, 0x30, 0x00, 0x7d,
  0x81, 0x07, 0x08, 0xd4, 0xca, 0x49, 0x89, 0x78,
  0x00, 0x29, 0x04, 0xd0, 0xc9, 0x49, 0xc0, 0x07,
  0x00, 0xd0, 0x02, 0x20, 0x08, 0x47, 0x70, 0x47,
  0x10, 0xb5, 0x01, 0x20, 0xc6, 0x49, 0xc0, 0x02,
  0x88, 0x47, 0x01, 0x20, 0xc4, 0x49, 0x00, 0x05,
  0x40, 0x31, 0x88, 0x47, 0xc0, 0x49, 0x01, 0x20,
  0x88, 0x70, 0xff, 0xf7, 0xe0, 0xff, 0x10, 0xbd,
  0xf8, 0xb5, 0xbb, 0x48, 0xbc, 0x4c, 0xc0, 0x30,
  0x81, 0x68, 0x62, 0x78, 0x08, 0x7f, 0x00, 0x2a,
  0x01, 0xd0, 0x49, 0x7f, 0x08, 0x18, 0xbb, 0x49,
  0x02, 0x22, 0x8a, 0x5e, 0xc0, 0x00, 0x00, 0x25,
  0x01, 0x26, 0x82, 0x42, 0x01, 0xdd, 0x65, 0x70,
  0x00, 0xe0, 0x66, 0x70, 0xb0, 0x4f, 0x60, 0x78,
  0x38, 0x70, 0xb5, 0x48, 0x80, 0x47, 0xae, 0x48,
  0x23, 0x78, 0xc0, 0x30, 0x81, 0x68, 0x0a, 0x46,
  0x60, 0x32, 0x10, 0x78, 0x00, 0x2b, 0x01, 0xd0,
  0x52, 0x78, 0x10, 0x18, 0xad, 0x4b, 0x02, 0x22,
  0x9a, 0x5e, 0xc0, 0x00, 0x82, 0x42, 0x0a, 0xdd,
  0x25, 0x70, 0x08, 0x46, 0x20, 0x30, 0x42, 0x7d,
  0xbb, 0x8a, 0x64, 0x24, 0x62, 0x43, 0x93, 0x42,
  0x0c, 0xd9, 0x80, 0x7c, 0x0d, 0xe0, 0x26, 0x70,
  0x08, 0x46, 0x20, 0x30, 0x42, 0x7d, 0xbb, 0x8a,
  0x64, 0x24, 0x62, 0x43, 0x93, 0x42, 0x03, 0xd9,
  0x00, 0x7d, 0x02, 0xe0, 0x40, 0x7c, 0x00, 0xe0,
  0xc0, 0x7c, 0x9a, 0x4a, 0x83, 0x07, 0x93, 0x7a,
  0x02, 0xd0, 0x40, 0x24, 0x23, 0x43, 0x01, 0xe0,
  0xbf, 0x24, 0x23, 0x40, 0x93, 0x72, 0x03, 0x07,
  0x9b, 0x0f, 0x93, 0x7a, 0x02, 0xd0, 0x80, 0x24,
  0x23, 0x43, 0x01, 0xe0, 0x5b, 0x06, 0x5b, 0x0e,
  0x93, 0x72, 0x96, 0x4a, 0x90, 0x70, 0x8f, 0x4a,
  0x20, 0x3a, 0x53, 0x7d, 0x9f, 0x24, 0x23, 0x40,
  0xc4, 0x09, 0xa4, 0x01, 0x40, 0x06, 0xc0, 0x0f,
  0x23, 0x43, 0x40, 0x01, 0x03, 0x43, 0x53, 0x75,
  0x50, 0x7d, 0xc0, 0x07, 0x15, 0xd1, 0x48, 0x7d,
  0x00, 0x28, 0x12, 0xd0, 0x64, 0x21, 0x89, 0x4b,
  0x48, 0x43, 0x20, 0x3b, 0x18, 0x21, 0x59, 0x5e,
  0x81, 0x42, 0x0a, 0xdd, 0x50, 0x7d, 0x30, 0x43,
  0x50, 0x75, 0x7f, 0x48, 0x64, 0x21, 0x80, 0x30,
  0x45, 0x83, 0x86, 0x4b, 0x84, 0x4a, 0x08, 0x20,
  0x98, 0x47, 0xff, 0xf7, 0xfd, 0xfe, 0xf8, 0xbd,
  0xf8, 0xb5, 0x7b, 0x4c, 0x78, 0x4a, 0x21, 0x79,
  0x02, 0x27, 0x49, 0x1c, 0xcd, 0xb2, 0x25, 0x71,
  0xc6, 0x7a, 0x21, 0x46, 0x01, 0x23, 0xc9, 0x78,
  0xc0, 0x32, 0x00, 0x2e, 0x1e, 0xd1, 0x10, 0x29,
  0x05, 0xd0, 0x46, 0x78, 0x11, 0x29, 0x17, 0xd0,
  0x18, 0x2e, 0x2c, 0xd0, 0x16, 0xe0, 0x46, 0x78,
  0x38, 0x2e, 0x13, 0xd1, 0x86, 0x78, 0x3b, 0x2e,
  0x10, 0xd1, 0xc6, 0x78, 0x02, 0x2e, 0x0d, 0xd1,
  0x00, 0x79, 0xbc, 0x28, 0x0a, 0xd1, 0xe3, 0x70,
  0x50, 0x68, 0xe0, 0x30, 0x01, 0x78, 0x89, 0x08,
  0x89, 0x00, 0x49, 0x1c, 0x01, 0x70, 0x2a, 0xe0,
  0x18, 0x2e, 0x07, 0xd0, 0x03, 0x2d, 0x2e, 0xd2,
  0x10, 0x29, 0x27, 0xd0, 0x11, 0x29, 0x28, 0xd0,
  0xe7, 0x70, 0xf8, 0xbd, 0xe7, 0x70, 0x51, 0x68,
  0xf3, 0x25, 0xe0, 0x31, 0x0b, 0x78, 0x2b, 0x40,
  0x1b, 0x1d, 0x0b, 0x70, 0x81, 0x78, 0x50, 0x68,
  0xe0, 0x30, 0x41, 0x70, 0x13, 0xe0, 0xf0, 0x21,
  0xe1, 0x70, 0x51, 0x68, 0xcf, 0x26, 0xe0, 0x31,
  0x0d, 0x78, 0x35, 0x40, 0x10, 0x35, 0x0d, 0x70,
  0x81, 0x78, 0x50, 0x68, 0xe0, 0x30, 0x81, 0x70,
  0x50, 0x68, 0x80, 0x30, 0xc1, 0x7a, 0x19, 0x43,
  0xc1, 0x72, 0x59, 0x48, 0x80, 0x47, 0x00, 0x20,
  0x20, 0x71, 0xf8, 0xbd, 0x00, 0x20, 0xe0, 0x70,
  0xf8, 0xbd, 0xe3, 0x70, 0xf8, 0xbd, 0x10, 0x29,
  0x12, 0xd0, 0x50, 0x68, 0x11, 0x29, 0x16, 0xd0,
  0xe0, 0x30, 0x01, 0x78, 0xcf, 0x25, 0x29, 0x40,
  0x20, 0x31, 0x01, 0x70, 0xf0, 0x20, 0xe0, 0x70,
  0x50, 0x68, 0x80, 0x30, 0xc1, 0x7a, 0x19, 0x43,
  0xc1, 0x72, 0x4b, 0x48, 0x80, 0x47, 0xf8, 0xbd,
  0x50, 0x68, 0xe0, 0x30, 0x01, 0x78, 0x89, 0x08,
  0x89, 0x00, 0x89, 0x1c, 0xed, 0xe7, 0xe0, 0x30,
  0x01, 0x78, 0xf3, 0x25, 0x29, 0x40, 0x08, 0x31,
  0xe7, 0xe7, 0x7f, 0xb5, 0x04, 0x46, 0x38, 0x48,
  0xc0, 0x69, 0x00, 0x69, 0x80, 0x47, 0x38, 0x4d,
  0xe9, 0x78, 0x10, 0x29, 0x24, 0xd2, 0x00, 0x2c,
  0x00, 0xda, 0x64, 0x42, 0x32, 0x48, 0xc0, 0x30,
  0x80, 0x68, 0xa0, 0x30, 0x40, 0x78, 0x00, 0x07,
  0x00, 0x0f, 0x84, 0x42, 0x18, 0xdc, 0x00, 0x20,
  0x00, 0x90, 0x01, 0x90, 0x02, 0x90, 0x03, 0x90,
  0x01, 0x20, 0x6a, 0x46, 0x10, 0x73, 0x35, 0x4b,
  0x68, 0x46, 0x00, 0x29, 0x0d, 0xd0, 0x01, 0x29,
  0x12, 0xd0, 0x02, 0x22, 0x32, 0x49, 0x40, 0x1c,
  0x98, 0x47, 0x12, 0x20, 0xe8, 0x70, 0x32, 0x4b,
  0x30, 0x4a, 0x00, 0x21, 0x68, 0x46, 0x98, 0x47,
  0x7f, 0xbd, 0x2d, 0x49, 0x04, 0x22, 0x89, 0x1c,
  0x40, 0x1c, 0x98, 0x47, 0x10, 0x20, 0xf1, 0xe7,
  0x29, 0x49, 0x02, 0x22, 0x89, 0x1e, 0x40, 0x1c,
  0x98, 0x47, 0x11, 0x20, 0xea, 0xe7, 0x70, 0xb5,
  0x19, 0x4d, 0x28, 0x4b, 0xc0, 0x35, 0xac, 0x68,
  0x27, 0x4a, 0xa0, 0x34, 0x21, 0x7d, 0x09, 0x07,
  0x8e, 0x0f, 0x04, 0xd0, 0x89, 0x0f, 0x01, 0x29,
  0x0a, 0xd0, 0x02, 0x29, 0x0b, 0xd0, 0x58, 0x7d,
  0x00, 0x07, 0x81, 0x0f, 0x10, 0x7a, 0x80, 0x00,
  0x08, 0x43, 0x00, 0xf0, 0xae, 0xf8, 0x10, 0xe0,
  0x0f, 0x48, 0xc0, 0x88, 0x0d, 0xe0, 0x00, 0x28,
  0x15, 0xd0, 0x10, 0x49, 0x18, 0x20, 0x20, 0x39,
  0x08, 0x5e, 0x1a, 0x49, 0x80, 0x02, 0x00, 0xf0,
  0x15, 0xfa, 0x19, 0x21, 0x61, 0x56, 0x08, 0x18,
  0x80, 0xb2, 0x06, 0x49, 0xc8, 0x72, 0xaa, 0x68,
  0x80, 0x05, 0xa0, 0x32, 0x92, 0x7d, 0xd2, 0x00,
  0x80, 0x0f, 0x02, 0x43, 0x0a, 0x73, 0x70, 0xbd,
  0xc0, 0x04, 0x05, 0x00, 0x60, 0xc1, 0x01, 0x20,
  0xb0, 0x0d, 0x05, 0x00, 0x15, 0x07, 0x04, 0x00,
  0xf7, 0x25, 0x04, 0x00, 0x40, 0x08, 0x05, 0x00,
  0x91, 0x1f, 0x04, 0x00, 0x00, 0x20, 0x01, 0x20,
  0xc9, 0x03, 0x08, 0x00, 0x4d, 0x0a, 0x04, 0x00,
  0x4d, 0x62, 0x04, 0x00, 0x47, 0x6e, 0x04, 0x00,
  0x4e, 0x0c, 0x08, 0x00, 0xf1, 0x04, 0x08, 0x00,
  0xab, 0x1b, 0x04, 0x00, 0x40, 0xc1, 0x01, 0x20,
  0x80, 0xc1, 0x01, 0x20, 0x48, 0x4e, 0x00, 0x00,
  0x70, 0xb5, 0x3d, 0x48, 0x80, 0x47, 0x3d, 0x48,
  0x41, 0x7d, 0xef, 0x22, 0x11, 0x40, 0x41, 0x75,
  0x3b, 0x4c, 0x00, 0x25, 0xa0, 0x68, 0x20, 0x30,
  0x81, 0x7e, 0x60, 0x68, 0xa0, 0x30, 0x81, 0x74,
  0x60, 0x68, 0xa2, 0x68, 0xa0, 0x30, 0x20, 0x32,
  0x41, 0x7c, 0x52, 0x7e, 0x89, 0x06, 0x92, 0x09,
  0x89, 0x0e, 0x92, 0x01, 0x11, 0x43, 0x41, 0x74,
  0x32, 0x48, 0x85, 0x70, 0xa0, 0x68, 0xa2, 0x30,
  0x41, 0x7e, 0x02, 0x7e, 0x08, 0x02, 0x61, 0x68,
  0x10, 0x43, 0xe0, 0x31, 0x08, 0x74, 0x00, 0x0a,
  0x48, 0x74, 0x2d, 0x49, 0x28, 0x46, 0x88, 0x47,
  0x2c, 0x4a, 0x15, 0x77, 0x27, 0x49, 0x24, 0x20,
  0x20, 0x31, 0x48, 0x73, 0xa0, 0x68, 0xa0, 0x30,
  0x80, 0x7d, 0x41, 0x06, 0x89, 0x0f, 0x89, 0x00,
  0xc0, 0x09, 0xc0, 0x01, 0x01, 0x43, 0x51, 0x70,
  0x00, 0x20, 0xff, 0xf7, 0x68, 0xff, 0xff, 0xf7,
  0xa3, 0xfd, 0xa0, 0x68, 0xc2, 0x30, 0x41, 0x7a,
  0x02, 0x7a, 0x08, 0x02, 0x10, 0x43, 0x21, 0x4a,
  0x1f, 0x49, 0x90, 0x47, 0x8f, 0xe7, 0x10, 0xb5,
  0x1f, 0x48, 0x80, 0x47, 0x17, 0x49, 0x48, 0x7d,
  0xf3, 0x22, 0x10, 0x40, 0x16, 0x4a, 0x52, 0x68,
  0xa0, 0x32, 0x52, 0x7c, 0x92, 0x09, 0x92, 0x00,
  0x10, 0x43, 0x48, 0x75, 0x00, 0x20, 0xff, 0xf7,
  0x4a, 0xff, 0xff, 0xf7, 0xe4, 0xfd, 0x10, 0xbd,
  0x10, 0xb5, 0x16, 0x48, 0x80, 0x47, 0x0e, 0x48,
  0x40, 0x68, 0xe0, 0x30, 0x41, 0x7c, 0x02, 0x7c,
  0x08, 0x02, 0x0c, 0x49, 0x10, 0x43, 0xc8, 0x80,
  0x10, 0xbd, 0x11, 0x49, 0xb8, 0x22, 0x48, 0x43,
  0x10, 0x49, 0x40, 0x13, 0x40, 0x18, 0x06, 0x49,
  0x89, 0x68, 0x8a, 0x56, 0x91, 0x01, 0x08, 0x18,
  0x80, 0x02, 0x00, 0x0c, 0x70, 0x47, 0x00, 0x00,
  0x05, 0x1c, 0x04, 0x00, 0x40, 0xc1, 0x01, 0x20,
  0x80, 0x05, 0x05, 0x00, 0xb0, 0x0d, 0x05, 0x00,
  0xed, 0x06, 0x04, 0x00, 0x00, 0x50, 0x01, 0x20,
  0xcf, 0x02, 0x08, 0x00, 0x53, 0x09, 0x04, 0x00,
  0x3d, 0x1f, 0x04, 0x00, 0x97, 0x23, 0x04, 0x00,
  0x40, 0x38, 0x0a, 0x00, 0x63, 0x06, 0x00, 0x00,
  0x0e, 0x49, 0x00, 0x20, 0x89, 0x79, 0x01, 0x29,
  0x04, 0xd0, 0x0c, 0x4a, 0x01, 0x21, 0x20, 0x32,
  0x51, 0x73, 0x70, 0x47, 0x01, 0x20, 0x70, 0x47,
  0x08, 0x49, 0xc0, 0x31, 0x89, 0x68, 0x60, 0x31,
  0xca, 0x7d, 0xd2, 0x07, 0x08, 0xd0, 0x49, 0x7a,
  0x49, 0x07, 0x05, 0xd5, 0x04, 0x49, 0x8a, 0x7b,
  0x20, 0x23, 0x1a, 0x43, 0x8a, 0x73, 0x88, 0x74,
  0x70, 0x47, 0x00, 0x00, 0xc0, 0x04, 0x05, 0x00,
  0x60, 0xc1, 0x01, 0x20, 0x11, 0x49, 0x4a, 0x7b,
  0x00, 0x2a, 0x04, 0xd1, 0x42, 0x1c, 0x02, 0x2a,
  0x01, 0xd8, 0x01, 0x22, 0x4a, 0x73, 0x0e, 0x49,
  0x08, 0x47, 0x10, 0xb5, 0x0d, 0x48, 0x40, 0x7d,
  0xc0, 0x07, 0x10, 0xd1, 0x09, 0x48, 0xa0, 0x30,
  0x80, 0x68, 0x41, 0x7d, 0x00, 0x29, 0x0a, 0xd0,
  0x64, 0x20, 0x41, 0x43, 0x08, 0x4a, 0x18, 0x20,
  0x10, 0x5e, 0x96, 0x31, 0x08, 0x1a, 0xc0, 0x03,
  0x00, 0xf0, 0x0c, 0xf9, 0x10, 0xbd, 0x05, 0x48,
  0x80, 0x47, 0x10, 0xbd, 0xe0, 0x04, 0x05, 0x00,
  0x13, 0x33, 0x04, 0x00, 0x40, 0xc1, 0x01, 0x20,
  0x20, 0x08, 0x05, 0x00, 0x33, 0x37, 0x04, 0x00,
  0x10, 0xb5, 0x05, 0x48, 0x80, 0x47, 0x05, 0x48,
  0x40, 0x7e, 0x20, 0x28, 0x02, 0xd1, 0x04, 0x49,
  0x25, 0x20, 0x88, 0x47, 0x10, 0xbd, 0x00, 0x00,
  0x7d, 0x4e, 0x04, 0x00, 0xe0, 0x04, 0x05, 0x00,
  0xad, 0x5e, 0x04, 0x00, 0x05, 0x4b, 0x02, 0x49,
  0x02, 0x48, 0x03, 0x4a, 0x18, 0x47, 0x00, 0x00,
  0x54, 0x0d, 0x08, 0x00, 0xdc, 0x0f, 0x05, 0x00,
  0x58, 0x03, 0x00, 0x00, 0x47, 0x6e, 0x04, 0x00,
  0x10, 0xb5, 0x19, 0x48, 0x40, 0x68, 0x20, 0x30,
  0x00, 0x78, 0x40, 0x06, 0x09, 0xd5, 0x17, 0x48,
  0x81, 0x69, 0x10, 0x22, 0x11, 0x43, 0x81, 0x61,
  0x13, 0x48, 0x40, 0x30, 0x00, 0x68, 0xc0, 0x69,
  0x80, 0x47, 0x13, 0x48, 0x80, 0x47, 0x10, 0xbd,
  0xf8, 0xb5, 0x0f, 0x4f, 0x38, 0x69, 0xc0, 0x08,
  0xc0, 0x07, 0x14, 0xd0, 0x7e, 0x68, 0x00, 0x24,
  0x30, 0x36, 0x35, 0x5d, 0x0d, 0x4a, 0xe0, 0xb2,
  0x29, 0x46, 0x90, 0x47, 0x06, 0x2d, 0x03, 0xd1,
  0x0b, 0x4a, 0xe0, 0xb2, 0x02, 0x21, 0x90, 0x47,
  0x64, 0x1c, 0x04, 0x2c, 0xf1, 0xdb, 0x38, 0x69,
  0x08, 0x21, 0x88, 0x43, 0x38, 0x61, 0x04, 0x48,
  0xf0, 0x38, 0x80, 0x47, 0xf8, 0xbd, 0x00, 0x00,
  0x80, 0x05, 0x05, 0x00, 0x00, 0xfc, 0x01, 0x20,
  0xcf, 0x68, 0x04, 0x00, 0xc3, 0x5e, 0x04, 0x00,
  0x65, 0x05, 0x04, 0x00, 0xf8, 0xb5, 0x31, 0x4e,
  0xb0, 0x69, 0x02, 0x27, 0x80, 0x07, 0x30, 0x4d,
  0x00, 0x28, 0x15, 0xdb, 0x2f, 0x48, 0x00, 0x24,
  0x80, 0x47, 0x01, 0x22, 0x00, 0x28, 0x01, 0xd0,
  0x2a, 0x62, 0x0b, 0xe0, 0x7d, 0x21, 0x09, 0x01,
  0x06, 0xe0, 0x2b, 0x4b, 0x1b, 0x78, 0x1b, 0x06,
  0x01, 0xd5, 0x01, 0x24, 0x00, 0xe0, 0x00, 0xbf,
  0x49, 0x1e, 0xf6, 0xd2, 0x84, 0x43, 0x01, 0xd0,
  0x2f, 0x62, 0x00, 0xe0, 0x2a, 0x62, 0xb0, 0x69,
  0x0e, 0x21, 0x88, 0x43, 0xb0, 0x61, 0x6d, 0x68,
  0x00, 0x24, 0x22, 0x4e, 0x30, 0x35, 0x28, 0x5d,
  0x06, 0x28, 0x02, 0xd1, 0xe0, 0xb2, 0x02, 0x21,
  0xb0, 0x47, 0x64, 0x1c, 0x04, 0x2c, 0xf6, 0xdb,
  0xf8, 0xbd, 0x70, 0xb5, 0x18, 0x4c, 0x1a, 0x4d,
  0x20, 0x6a, 0x20, 0x3d, 0x02, 0x28, 0x24, 0xd1,
  0xa0, 0x68, 0x40, 0x7d, 0x00, 0x28, 0x20, 0xd0,
  0x01, 0x20, 0x17, 0x49, 0x00, 0x05, 0x88, 0x47,
  0x69, 0x7d, 0x7d, 0x20, 0x01, 0x40, 0xa0, 0x68,
  0x02, 0x7b, 0x92, 0x07, 0xd2, 0x0f, 0x52, 0x00,
  0x11, 0x43, 0x23, 0x22, 0x12, 0x5c, 0x92, 0x07,
  0xd2, 0x0f, 0xd2, 0x01, 0x11, 0x43, 0x69, 0x75,
  0xc0, 0x78, 0xc0, 0x06, 0x03, 0xd5, 0x0d, 0x48,
  0x80, 0x78, 0x03, 0x28, 0x04, 0xd2, 0x0c, 0x48,
  0x01, 0x69, 0x04, 0x22, 0x91, 0x43, 0x01, 0x61,
  0x70, 0xbd, 0x68, 0x7d, 0x01, 0x21, 0x08, 0x43,
  0x68, 0x75, 0xdd, 0xe7, 0x00, 0xfc, 0x01, 0x20,
  0x80, 0x05, 0x05, 0x00, 0xbf, 0x65, 0x04, 0x00,
  0x60, 0xc1, 0x01, 0x20, 0x65, 0x05, 0x04, 0x00,
  0xf7, 0x25, 0x04, 0x00, 0x00, 0xc0, 0x01, 0x20,
  0x00, 0xed, 0x00, 0xe0, 0x10, 0xb5, 0x20, 0x2a,
  0x04, 0xdb, 0x08, 0x46, 0x20, 0x3a, 0xd0, 0x40,
  0x00, 0x21, 0x10, 0xbd, 0x0b, 0x46, 0x20, 0x24,
  0xd3, 0x40, 0xd0, 0x40, 0xa2, 0x1a, 0x91, 0x40,
  0x08, 0x43, 0x19, 0x46, 0x10, 0xbd, 0x03, 0x78,
  0xc2, 0x78, 0x19, 0x46, 0x43, 0x78, 0x12, 0x06,
  0x1b, 0x02, 0x19, 0x43, 0x83, 0x78, 0xc0, 0x78,
  0x1b, 0x04, 0x19, 0x43, 0x11, 0x43, 0x09, 0x02,
  0x09, 0x0a, 0x00, 0x06, 0x08, 0x43, 0x70, 0x47,
  0x00, 0x22, 0x03, 0x09, 0x8b, 0x42, 0x2c, 0xd3,
  0x03, 0x0a, 0x8b, 0x42, 0x11, 0xd3, 0x00, 0x23,
  0x9c, 0x46, 0x4e, 0xe0, 0x03, 0x46, 0x0b, 0x43,
  0x3c, 0xd4, 0x00, 0x22, 0x43, 0x08, 0x8b, 0x42,
  0x31, 0xd3, 0x03, 0x09, 0x8b, 0x42, 0x1c, 0xd3,
  0x03, 0x0a, 0x8b, 0x42, 0x01, 0xd3, 0x94, 0x46,
  0x3f, 0xe0, 0xc3, 0x09, 0x8b, 0x42, 0x01, 0xd3,
  0xcb, 0x01, 0xc0, 0x1a, 0x52, 0x41, 0x83, 0x09,
  0x8b, 0x42, 0x01, 0xd3, 0x8b, 0x01, 0xc0, 0x1a,
  0x52, 0x41, 0x43, 0x09, 0x8b, 0x42, 0x01, 0xd3,
  0x4b, 0x01, 0xc0, 0x1a, 0x52, 0x41, 0x03, 0x09,
  0x8b, 0x42, 0x01, 0xd3, 0x0b, 0x01, 0xc0, 0x1a,
  0x52, 0x41, 0xc3, 0x08, 0x8b, 0x42, 0x01, 0xd3,
  0xcb, 0x00, 0xc0, 0x1a, 0x52, 0x41, 0x83, 0x08,
  0x8b, 0x42, 0x01, 0xd3, 0x8b, 0x00, 0xc0, 0x1a,
  0x52, 0x41, 0x43, 0x08, 0x8b, 0x42, 0x01, 0xd3,
  0x4b, 0x00, 0xc0, 0x1a, 0x52, 0x41, 0x41, 0x1a,
  0x00, 0xd2, 0x01, 0x46, 0x52, 0x41, 0x10, 0x46,
  0x70, 0x47, 0x5d, 0xe0, 0xca, 0x0f, 0x00, 0xd0,
  0x49, 0x42, 0x03, 0x10, 0x00, 0xd3, 0x40, 0x42,
  0x53, 0x40, 0x00, 0x22, 0x9c, 0x46, 0x03, 0x09,
  0x8b, 0x42, 0x2d, 0xd3, 0x03, 0x0a, 0x8b, 0x42,
  0x12, 0xd3, 0xfc, 0x22, 0x89, 0x01, 0x12, 0xba,
  0x03, 0x0a, 0x8b, 0x42, 0x0c, 0xd3, 0x89, 0x01,
  0x92, 0x11, 0x8b, 0x42, 0x08, 0xd3, 0x89, 0x01,
  0x92, 0x11, 0x8b, 0x42, 0x04, 0xd3, 0x89, 0x01,
  0x3a, 0xd0, 0x92, 0x11, 0x00, 0xe0, 0x89, 0x09,
  0xc3, 0x09, 0x8b, 0x42, 0x01, 0xd3, 0xcb, 0x01,
  0xc0, 0x1a, 0x52, 0x41, 0x83, 0x09, 0x8b, 0x42,
  0x01, 0xd3, 0x8b, 0x01, 0xc0, 0x1a, 0x52, 0x41,
  0x43, 0x09, 0x8b, 0x42, 0x01, 0xd3, 0x4b, 0x01,
  0xc0, 0x1a, 0x52, 0x41, 0x03, 0x09, 0x8b, 0x42,
  0x01, 0xd3, 0x0b, 0x01, 0xc0, 0x1a, 0x52, 0x41,
  0xc3, 0x08, 0x8b, 0x42, 0x01, 0xd3, 0xcb, 0x00,
  0xc0, 0x1a, 0x52, 0x41, 0x83, 0x08, 0x8b, 0x42,
  0x01, 0xd3, 0x8b, 0x00, 0xc0, 0x1a, 0x52, 0x41,
  0xd9, 0xd2, 0x43, 0x08, 0x8b, 0x42, 0x01, 0xd3,
  0x4b, 0x00, 0xc0, 0x1a, 0x52, 0x41, 0x41, 0x1a,
  0x00, 0xd2, 0x01, 0x46, 0x63, 0x46, 0x52, 0x41,
  0x5b, 0x10, 0x10, 0x46, 0x01, 0xd3, 0x40, 0x42,
  0x00, 0x2b, 0x00, 0xd5, 0x49, 0x42, 0x70, 0x47,
  0x63, 0x46, 0x5b, 0x10, 0x00, 0xd3, 0x40, 0x42,
  0x01, 0xb5, 0x00, 0x20, 0xc0, 0x46, 0xc0, 0x46,
  0x02, 0xbd, 0x30, 0xb4, 0x74, 0x46, 0x64, 0x1e,
  0x25, 0x78, 0x64, 0x1c, 0xab, 0x42, 0x00, 0xd2,
  0x1d, 0x46, 0x63, 0x5d, 0x5b, 0x00, 0xe3, 0x18,
  0x30, 0xbc, 0x18, 0x47, 0x79, 0x0c, 0x04, 0x00,
  0x69, 0x02, 0x08, 0x00, 0x18, 0x0b, 0x18, 0x0c,
  0x38, 0x3b, 0x02, 0xbb, 0xb7, 0x07, 0x08, 0x00,
  0xe9, 0x03, 0x08, 0x00, 0x31, 0x24, 0x04, 0x00,
  0xdf, 0x23, 0x04, 0x00, 0x6b, 0x24, 0x04, 0x00,
  0xf3, 0x05, 0x08, 0x00, 0xc7, 0x1d, 0x04, 0x00,
  0xeb, 0x20, 0x04, 0x00, 0x37, 0x26, 0x04, 0x00,
  0xb9, 0x25, 0x04, 0x00, 0x8f, 0x22, 0x04, 0x00,
  0xe7, 0x24, 0x04, 0x00, 0xe9, 0x24, 0x04, 0x00,
  0x21, 0x07, 0x08, 0x00, 0x69, 0x1d, 0x04, 0x00,
  0x0d, 0x19, 0x04, 0x00, 0xf3, 0x1a, 0x04, 0x00,
  0x4b, 0x26, 0x04, 0x00, 0x31, 0x1b, 0x04, 0x00,
  0x15, 0x22, 0x04, 0x00, 0x3f, 0x22, 0x04, 0x00,
  0xf3, 0x21, 0x04, 0x00, 0xc1, 0x21, 0x04, 0x00,
  0x8d, 0x21, 0x04, 0x00, 0x99, 0x19, 0x04, 0x00,
  0x8b, 0x1b, 0x04, 0x00, 0xab, 0x1b, 0x04, 0x00,
  0x9f, 0x22, 0x04, 0x00, 0xe1, 0x07, 0x08, 0x00,
  0x41, 0x25, 0x04, 0x00, 0xf5, 0x1b, 0x04, 0x00,
  0xf3, 0x1b, 0x04, 0x00, 0xf7, 0x25, 0x04, 0x00,
  0x77, 0x1e, 0x04, 0x00, 0x6d, 0x1e, 0x04, 0x00,
  0xfb, 0x1e, 0x04, 0x00, 0xdf, 0x1e, 0x04, 0x00,
  0xd1, 0x1d, 0x04, 0x00, 0x95, 0x1e, 0x04, 0x00,
  0x41, 0x26, 0x04, 0x00, 0x4f, 0x4f, 0x04, 0x00,
  0x47, 0x4f, 0x04, 0x00, 0xe9, 0x08, 0x08, 0x00,
  0x55, 0x4e, 0x04, 0x00, 0xd5, 0x67, 0x04, 0x00,
  0x51, 0x09, 0x08, 0x00, 0x09, 0x6b, 0x04, 0x00,
  0x1f, 0x6b, 0x04, 0x00, 0x29, 0x6a, 0x04, 0x00,
  0x0b, 0x6b, 0x04, 0x00, 0x29, 0x09, 0x08, 0x00,
  0xfd, 0x6a, 0x04, 0x00, 0xa5, 0x09, 0x08, 0x00,
  0x69, 0x6c, 0x04, 0x00, 0x5d, 0x6c, 0x04, 0x00,
  0x0b, 0x0a, 0x08, 0x00, 0x5b, 0x6c, 0x04, 0x00,
  0x99, 0x6c, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0xf7, 0xb5, 0x82, 0xb0,
  0x05, 0x00, 0x47, 0xd0, 0x28, 0x68, 0x00, 0x90,
  0x00, 0x28, 0x43, 0xd0, 0xaf, 0x88, 0x00, 0x2f,
  0x40, 0xd0, 0x3a, 0x48, 0x19, 0x21, 0x89, 0x01,
  0x06, 0x78, 0x8f, 0x42, 0x01, 0xd3, 0x00, 0x2e,
  0x38, 0xd0, 0x19, 0x21, 0x49, 0x01, 0x8f, 0x42,
  0x01, 0xd9, 0x00, 0x2e, 0x32, 0xd1, 0x41, 0x78,
  0x00, 0x29, 0x2f, 0xd1, 0x31, 0x48, 0x00, 0x99,
  0x80, 0x68, 0x2f, 0xf0, 0x59, 0xfd, 0x08, 0x21,
  0x69, 0x56, 0x0c, 0x18, 0x60, 0x1e, 0x2e, 0x49,
  0x01, 0x90, 0x88, 0x42, 0x22, 0xd2, 0x00, 0x2e,
  0x09, 0xd0, 0x19, 0x20, 0x40, 0x01, 0xc0, 0x1b,
  0x19, 0x21, 0x66, 0x10, 0x60, 0x43, 0x89, 0x01,
  0x2f, 0xf0, 0x50, 0xfd, 0x07, 0xe0, 0x19, 0x21,
  0x89, 0x01, 0xc8, 0x1b, 0x60, 0x43, 0x2f, 0xf0,
  0x49, 0xfd, 0x06, 0x46, 0x00, 0x20, 0x23, 0x4a,
  0x91, 0x7c, 0x21, 0x4b, 0x98, 0x42, 0x09, 0xd8,
  0x43, 0x18, 0xb3, 0x42, 0x06, 0xd2, 0x9b, 0x19,
  0xa3, 0x42, 0x03, 0xd2, 0x93, 0x8a, 0x59, 0x18,
  0xb1, 0x42, 0x02, 0xd3, 0x00, 0x20, 0x05, 0xb0,
  0xf0, 0xbd, 0x1b, 0x49, 0x00, 0x9b, 0xaf, 0x68,
  0x6c, 0x68, 0x98, 0xc1, 0x01, 0x99, 0x91, 0x81,
  0x16, 0x82, 0xe9, 0x88, 0xd1, 0x81, 0x90, 0x82,
  0x12, 0x4c, 0x03, 0x98, 0x01, 0x21, 0x60, 0x60,
  0x61, 0x70, 0x04, 0x99, 0x00, 0x29, 0x0c, 0xd0,
  0x11, 0x78, 0x04, 0x23, 0x19, 0x43, 0x11, 0x70,
  0x11, 0x78, 0xc9, 0x07, 0x05, 0xd1, 0x00, 0x25,
  0x00, 0x28, 0x01, 0xd0, 0x65, 0x60, 0x80, 0x47,
  0x65, 0x70, 0x01, 0x20, 0xdb, 0xe7, 0x10, 0xb5,
  0x08, 0x49, 0x88, 0x79, 0x08, 0x72, 0x80, 0x07,
  0x07, 0xd5, 0x04, 0x49, 0x00, 0x22, 0x48, 0x68,
  0x4a, 0x60, 0x4a, 0x70, 0x00, 0x28, 0x00, 0xd0,
  0x80, 0x47, 0x10, 0xbd, 0xa4, 0x0d, 0x05, 0x00,
  0xff, 0xff, 0x00, 0x00, 0x00, 0x58, 0x01, 0x20,
  0xbc, 0x0d, 0x05, 0x00, 0x10, 0xb5, 0x01, 0x48,
  0x80, 0x47, 0x10, 0xbd, 0x9f, 0x08, 0x04, 0x00,
  0x03, 0x22, 0x00, 0xb5, 0x12, 0x02, 0x23, 0x49,
  0x90, 0x42, 0x3f, 0xd2, 0x85, 0x28, 0x37, 0xd0,
  0x17, 0xdc, 0x33, 0x28, 0x36, 0xd0, 0x0c, 0xdc,
  0x30, 0x28, 0x33, 0xd0, 0x04, 0xdc, 0x20, 0x28,
  0x28, 0xd0, 0x21, 0x28, 0x32, 0xd1, 0x25, 0xe0,
  0x31, 0x28, 0x2b, 0xd0, 0x32, 0x28, 0x2d, 0xd1,
  0x28, 0xe0, 0x80, 0x38, 0x03, 0x00, 0x2f, 0xf0,
  0x7c, 0xfd, 0x05, 0x21, 0x21, 0x21, 0x21, 0x23,
  0x29, 0x00, 0xb2, 0x28, 0x20, 0xd0, 0x0c, 0xdc,
  0x90, 0x28, 0x15, 0xd0, 0x04, 0xdc, 0x86, 0x28,
  0x16, 0xd0, 0x87, 0x28, 0x1a, 0xd1, 0x13, 0xe0,
  0x91, 0x28, 0x0d, 0xd0, 0xb1, 0x28, 0x15, 0xd1,
  0x12, 0xe0, 0xb4, 0x28, 0x10, 0xd0, 0xb5, 0x28,
  0x0e, 0xd0, 0xf0, 0x28, 0x0c, 0xd0, 0xf1, 0x28,
  0x0c, 0xd1, 0x09, 0xe0, 0x01, 0x20, 0x08, 0xe0,
  0x20, 0x20, 0x06, 0xe0, 0x02, 0x20, 0x04, 0xe0,
  0x04, 0x20, 0x02, 0xe0, 0x08, 0x20, 0x00, 0xe0,
  0x10, 0x20, 0x88, 0x60, 0x40, 0x20, 0x88, 0x60,
  0x00, 0xbd, 0x00, 0x00, 0x00, 0xfc, 0x01, 0x20,
  0x10, 0xb5, 0x2a, 0x4c, 0x60, 0x43, 0x40, 0x12,
  0x48, 0x43, 0x0b, 0x33, 0x18, 0x41, 0xe3, 0x00,
  0x59, 0x43, 0x89, 0x0a, 0x89, 0x18, 0x08, 0x18,
  0x00, 0xb2, 0x10, 0xbd, 0x70, 0xb5, 0x24, 0x4c,
  0x25, 0x4e, 0x64, 0x68, 0x70, 0x43, 0x65, 0x7b,
  0x24, 0x7b, 0x2d, 0x02, 0x25, 0x43, 0x21, 0x4c,
  0xc0, 0x12, 0x4c, 0x43, 0x48, 0x43, 0xa4, 0x0a,
  0x0d, 0x33, 0x18, 0x41, 0x7f, 0x21, 0x00, 0x1b,
  0x49, 0x01, 0x06, 0x2d, 0x01, 0xd3, 0x80, 0x18,
  0x03, 0xe0, 0x1c, 0x4b, 0x5a, 0x43, 0xd2, 0x11,
  0x80, 0x1a, 0x40, 0x18, 0x00, 0xb2, 0x70, 0xbd,
  0x40, 0x11, 0xcf, 0x23, 0x58, 0x43, 0x00, 0x14,
  0x48, 0x43, 0x17, 0x4b, 0x80, 0x12, 0x59, 0x43,
  0x89, 0x0a, 0x89, 0x18, 0x08, 0x18, 0x40, 0x1d,
  0x00, 0xb2, 0x70, 0x47, 0x70, 0xb5, 0x0e, 0x49,
  0x8a, 0x68, 0xcc, 0x68, 0xd2, 0x7b, 0x21, 0x46,
  0x52, 0x06, 0x53, 0x0f, 0x22, 0x31, 0x4a, 0x7a,
  0x09, 0x7a, 0x12, 0x06, 0x12, 0x14, 0x0a, 0x43,
  0x21, 0x46, 0x20, 0x31, 0x4c, 0x7a, 0x0d, 0x7a,
  0x21, 0x02, 0x05, 0x4c, 0x29, 0x43, 0x40, 0x3c,
  0xe4, 0x6b, 0xe4, 0x69, 0xa0, 0x47, 0x40, 0x10,
  0x70, 0xbd, 0x00, 0x00, 0x8c, 0x0a, 0x00, 0x00,
  0x80, 0x05, 0x05, 0x00, 0x72, 0x14, 0x00, 0x00,
  0x1c, 0xd7, 0xff, 0xff, 0xc3, 0x02, 0x00, 0x00,
  0x92, 0x07, 0x00, 0x00, 0x70, 0xb5, 0x05, 0x46,
  0x34, 0x48, 0x01, 0x23, 0x00, 0x24, 0x28, 0x40,
  0x9b, 0x02, 0x98, 0x42, 0x00, 0xd0, 0x03, 0x24,
  0xe8, 0x05, 0x00, 0x0e, 0x08, 0x70, 0x11, 0x46,
  0x2f, 0x4a, 0x90, 0x47, 0x01, 0x21, 0x49, 0x02,
  0x0d, 0x40, 0x40, 0x02, 0x85, 0x42, 0x02, 0xd0,
  0x00, 0x2c, 0x00, 0xd1, 0x02, 0x24, 0x20, 0x46,
  0x70, 0xbd, 0xfe, 0xb5, 0x05, 0x46, 0x00, 0x20,
  0x00, 0x90, 0x28, 0x89, 0x6c, 0x89, 0x00, 0x1b,
  0x87, 0xb2, 0x68, 0x7b, 0x00, 0x28, 0x01, 0xd0,
  0x7f, 0x1c, 0xbf, 0xb2, 0x28, 0x7b, 0x00, 0x28,
  0x01, 0xd0, 0x7f, 0x1e, 0xbf, 0xb2, 0x01, 0x28,
  0x00, 0xd1, 0x64, 0x1c, 0x00, 0x26, 0x01, 0x96,
  0x31, 0xe0, 0x61, 0x09, 0x68, 0x68, 0x89, 0x00,
  0x40, 0x18, 0x03, 0x68, 0xe2, 0x06, 0x41, 0x68,
  0xd2, 0x0e, 0x18, 0x46, 0x2f, 0xf0, 0xde, 0xfb,
  0x0b, 0x34, 0x00, 0x2e, 0x02, 0xd1, 0x69, 0x7b,
  0x01, 0x29, 0x07, 0xd0, 0x31, 0x46, 0x0b, 0x31,
  0xb9, 0x42, 0x0b, 0xd3, 0x69, 0x7b, 0x02, 0x29,
  0x03, 0xd0, 0x07, 0xe0, 0x40, 0x00, 0x64, 0x1e,
  0x04, 0xe0, 0xba, 0x1b, 0x01, 0x21, 0x52, 0x1e,
  0x91, 0x40, 0x08, 0x43, 0x01, 0x99, 0xaa, 0x7b,
  0x2b, 0x68, 0x49, 0x1c, 0x01, 0x91, 0x59, 0x18,
  0xff, 0xf7, 0xa4, 0xff, 0x01, 0x99, 0xc9, 0xb2,
  0x01, 0x91, 0x00, 0x99, 0x00, 0x29, 0x00, 0xd1,
  0x00, 0x90, 0x0b, 0x36, 0xb6, 0xb2, 0xbe, 0x42,
  0x02, 0xd2, 0x01, 0x98, 0x0a, 0x28, 0xc8, 0xd3,
  0x00, 0x98, 0xfe, 0xbd, 0x01, 0x04, 0x00, 0x00,
  0x79, 0x55, 0x04, 0x00, 0xce, 0x7c, 0xbc, 0x0b,
};

#endif
