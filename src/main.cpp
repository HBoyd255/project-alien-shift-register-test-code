/**
 * @file main.cpp
 * @brief The main file and entry point of the project.
 *
 * @author Harry Boyd - https://github.com/HBoyd255
 * @date 2024-07-31
 * @copyright Copyright (c) 2024
 */

//  ██████╗ ██████╗  ██████╗      ██╗███████╗ ██████╗████████╗
//  ██╔══██╗██╔══██╗██╔═══██╗     ██║██╔════╝██╔════╝╚══██╔══╝
//  ██████╔╝██████╔╝██║   ██║     ██║█████╗  ██║        ██║
//  ██╔═══╝ ██╔══██╗██║   ██║██   ██║██╔══╝  ██║        ██║
//  ██║     ██║  ██║╚██████╔╝╚█████╔╝███████╗╚██████╗   ██║
//  ╚═╝     ╚═╝  ╚═╝ ╚═════╝  ╚════╝ ╚══════╝ ╚═════╝   ╚═╝
//
//   █████╗    ██╗        ██╗   ███████╗   ███╗   ██╗
//  ██╔══██╗   ██║        ██║   ██╔════╝   ████╗  ██║
//  ███████║   ██║        ██║   █████╗     ██╔██╗ ██║
//  ██╔══██║   ██║        ██║   ██╔══╝     ██║╚██╗██║
//  ██║  ██║██╗███████╗██╗██║██╗███████╗██╗██║ ╚████║██╗
//  ╚═╝  ╚═╝╚═╝╚══════╝╚═╝╚═╝╚═╝╚══════╝╚═╝╚═╝  ╚═══╝╚═╝

// Ascii text generated at https://patorjk.com/software/taag/
// Font used - ANSI Shadow

#include <Arduino.h>
#include <NESControllerInterface.h>

#include "systemInfo.h"

NESControllerInterface nes(NES_SHIFT_REG_DATA, COMMON_SHIFT_REG_LOAD,
                           COMMON_SHIFT_REG_CLOCK);

void setup() {
    // Initialize serial communication
    Serial.begin(SERIAL_BAUD_RATE);
}

void loop() {
    // Test the NES controller
    NESInput NESData = nes.getNESInput();
    Serial.println(NESData);
}
