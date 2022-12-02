#ifndef MACHINE_H
#define MACHINE_H

#define GPS_UART_RX   0
#define GPS_UART_TX   0
#define GPS_UART_BAUD 0

#define BATTERY_PIN   0

#define LED_PIN       0

#define RADIO_IN_USE_SX1278
// #define RADIO_IN_USE_SX1280  <-- Can add more here...


#define bit_set(var, bit) (var & (1 << bit))


#endif /* MACHINE_H */
