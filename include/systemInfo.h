/**
 * @file systemInfo.h
 * @brief Definition for constant values related to the hardware setup for the
 * shift registers.
 *
 * @author Harry Boyd - https://github.com/HBoyd255
 * @date 2024-07-31
 * @copyright Copyright (c) 2024
 */

#ifndef SYSTEM_INFO_H
#define SYSTEM_INFO_H

// Serial
#define SERIAL_BAUD_RATE 230400

// Shift registers
#define BUMPER_SHIFT_REG_DATA A6
#define NES_SHIFT_REG_DATA D8
#define COMMON_SHIFT_REG_LOAD A3
#define COMMON_SHIFT_REG_CLOCK A2

#endif  // SYSTEM_INFO_H