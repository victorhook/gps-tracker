#ifndef LED_H
#define LED_H

#include "vsrtos.h"
#include <Adafruit_NeoPixel.h>

#define LED_OFF     0
#define COLOR_RED   0xff0000
#define COLOR_GREEN 0x00ff00
#define COLOR_BLUE  0x0000ff

typedef enum {
    LED_MODE_OFF,
    LED_MODE_ON,
    LED_MODE_BLINK_0_25_HZ,
    LED_MODE_BLINK_0_5_HZ,
    LED_MODE_BLINK_1_HZ,
    LED_MODE_BLINK_2_HZ,
} led_mode_t;

typedef struct {
    led_mode_t mode;
    uint32_t   color;
} led_state_t;

typedef struct {
    uint8_t r;
    uint8_t g;
    uint8_t b;
} __attribute__((packed)) rgb_t;

class Led : public Task {
    public:
        Led();
        void setLedState(const uint32 color, const led_mode_t mode);

        int init()     override;
        void update()  override;
    private:
        Adafruit_NeoPixel* _led;
        led_state_t         _curr_state;
        led_state_t         _next_state;
        bool                _led_is_on;
        unsigned long       _last_time_led_switched;

        void _setColor(const uint32_t color);
};

extern Led led;

#endif /* LED_H */
