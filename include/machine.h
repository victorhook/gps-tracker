#ifndef MACHINE_H
#define MACHINE_H

#include <Arduino.h>

// Some defines
#define SERIAL Serial

#define DEBUG_PRINT(msg)       (SERIAL.print(msg))
#define DEBUG_PRINTLN(msg)     (SERIAL.println(msg))
#define DEBUG_PRINTF(msg, ...) (SERIAL.printf(msg, __VA_ARGS__))

// Uncomment only 1 of these, depending on if you're building for sender or receiver
#define MACHINE_IS_SENDER
#define MACHINE_IS_RECEIVER

// GPS
#define GPS_UART_RX     D2
#define GPS_UART_TX     D1
#define GPS_UART_BAUD   9600

// Battery
#define BATTERY_PIN     0

// LED
#define LED_PIN         0

// Button
#define BUTTON_PIN      0

// Radio
#define RADIO_PIN_CS    0
#define RADIO_PIN_RESET 0
#define RADIO_PIN_IRQ   0
#define RADIO_IN_USE_SX1278
//#define RADIO_IN_USE_SX1280

// Protocol selection
#define PROTOCOL_IN_USE_PROTOCOL_SIMPLE
//#define PROTOCOL_SIMPLE_2

#endif /* MACHINE_H */
