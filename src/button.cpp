#include "button.h"
#include "machine.h"
#include <Arduino.h>


static uint8_t state;
static unsigned long last_button_press = 0;


static void buttonChange() {
    unsigned long now = millis();

    if (last_button_press == 0) {
        last_button_press = now;
    }

    uint8_t next_state = digitalRead(BUTTON_PIN);

    if (state != next_state) {
        // TODO
    }
}


int Button::init() {
    // Active low button
    pinMode(BUTTON_PIN, INPUT_PULLUP);
    state = digitalRead(BUTTON_PIN);
    attachInterrupt(BUTTON_PIN, buttonChange, CHANGE);
    return 0;
}


Button button;
