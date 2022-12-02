#ifndef BATTERY_H
#define BATTERY_H

#include "stdint.h"


class Battery {
    public:
        Battery(const uint8_t pin);
        bool init();
        float getVoltage();
    private:
        uint8_t _pin;
};


#endif /* BATTERY_H */
