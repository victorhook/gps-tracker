#ifndef RESULT_H
#define RESULT_H

#include <Arduino.h>


typedef enum {
    RESULT_OK               = 0,
    RESULT_ERR_GPS_INIT     = 0b00000001,
    RESULT_ERR_BATTERY_INIT = 0b00000010,
    RESULT_ERR_RADIO_INIT   = 0b00000100,
    RESULT_ERR_LED_INIT     = 0b00001000,
    RESULT_ERR
} result_t;


const String resultToString(const result_t result);


#endif /* RESULT_H */
