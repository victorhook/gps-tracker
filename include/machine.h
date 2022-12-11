#ifndef MACHINE_H
#define MACHINE_H

#define GPS_UART_RX   D2
#define GPS_UART_TX   D1
#define GPS_UART_BAUD 9600

#define BATTERY_PIN   0

#define LED_PIN       0

#define RADIO_PIN_CS 0
#define RADIO_PIN_RESET 0
#define RADIO_PIN_IRQ 0

#define RADIO_IN_USE_SX1278
//#define RADIO_IN_USE_SX1280  <-- Can add more here...

// Protocol selection
#define PROTOCOL_IN_USE_PROTOCOL_SIMPLE
//#define PROTOCOL_SIMPLE_2

#define bit_set(var, bit) (var & (1 << bit))


#endif /* MACHINE_H */
