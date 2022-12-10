#include "battery.h"
#include "machine.h"
#include <Arduino.h>

Battery::Battery(const uint8_t pin)
: _pin(pin) {

}

bool Battery::init() {
    pinMode(_pin, INPUT);
    return true;
}

float Battery::getVoltage() {
    int raw_value = analogRead(_pin);

    // TODO: This
    float voltage = raw_value * 1.0;

    return voltage;
}

Battery battery(BATTERY_PIN);
