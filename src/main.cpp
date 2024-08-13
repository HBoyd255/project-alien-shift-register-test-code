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

#include "binary.h"
#include "systemInfo.h"

/**
 * @brief Reads two bytes from two separate 4021 shift registers.
 * Both shift registers are connected to the same clock and load pin, but have
 * separate data pins.
 *
 * @param dataPin1 The data pin for the first shift register.
 * @param dataPin2 The data pin for the second shift register.
 * @param loadPin The load pin for both shift registers.
 * @param clockPin The clock pin for both shift registers.
 * @param byte1 The byte to store the data from the first shift register.
 * @param byte2 The byte to store the data from the second shift register.
 */
void readTwoSeparateBytes(int dataPin1, int dataPin2, int loadPin, int clockPin,
                          uint8_t *byte1, uint8_t *byte2) {
    // Create a byte for storing the received data from the shift register.
    uint8_t shiftRegister1Contents = 0;
    uint8_t shiftRegister2Contents = 0;

    // Pulse the load pin to load the button states into the shift
    // register.
    digitalWrite(loadPin, LOW);
    delayMicroseconds(10);
    digitalWrite(loadPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(loadPin, LOW);

    // For each button,
    for (uint8_t i = 0; i < 8; i++) {
        // Shift the received data up by one.
        shiftRegister1Contents <<= 1;
        shiftRegister2Contents <<= 1;

        // Load the available bit from the shift registers into the lsb of the
        // received data byte.
        shiftRegister1Contents |= digitalRead(dataPin1);
        shiftRegister2Contents |= digitalRead(dataPin2);

        // Pulse the clock pin to shift the data inside the shift registers.
        digitalWrite(clockPin, LOW);
        delayMicroseconds(10);
        digitalWrite(clockPin, HIGH);
        delayMicroseconds(10);
    }
    *byte1 = shiftRegister1Contents;
    *byte2 = shiftRegister2Contents;
}

void setup() {
    // Initialize serial communication
    Serial.begin(SERIAL_BAUD_RATE);

    pinMode(NES_SHIFT_REG_DATA, INPUT_PULLUP);
    pinMode(BUMPER_SHIFT_REG_DATA, INPUT_PULLUP);
    pinMode(COMMON_SHIFT_REG_LOAD, OUTPUT);
    pinMode(COMMON_SHIFT_REG_CLOCK, OUTPUT);
}

void loop() {
    byte bumper1, NESValue;

    readTwoSeparateBytes(BUMPER_SHIFT_REG_DATA, NES_SHIFT_REG_DATA,
                         COMMON_SHIFT_REG_LOAD, COMMON_SHIFT_REG_CLOCK,
                         &bumper1, &NESValue);

    Serial.println("Bumper Values:");
    printByte(bumper1, ",");
    Serial.println("NES Values:");
    printByte(NESValue, ",");
    Serial.println();
    delay(100);
}
