#ifndef LED_H
#define LED_H

#include "vsrtos.h"
#include <Adafruit_NeoPixel.h>


#define COLOR_RED   0xff0000
#define COLOR_GREEN 0x00ff00
#define COLOR_BLUE  0x0000ff

typedef enum {
    LED_STATE_OFF,
    LED_STATE_ON,
    LED_STATE_BLINK_0_25_HZ,
    LED_STATE_BLINK_0_5_HZ,
    LED_STATE_BLINK_1_HZ,
    LED_STATE_BLINK_2_HZ,
} led_mode_t;

typedef struct {
    led_mode_t state;
    uint32_t    color;
} led_state_t;

typedef struct {
    uint8_t r;
    uint8_t g;
    uint8_t b;
} rgb_t __attribute__((packed));

class Led : public Task {
    public:
        Led();
        void setColor(const uint32_t color);
        void setLedState(const led_state_t led_state);

        int init()     override;
        void update()  override;
    private:
        Adafruit_NeoPixel* _led;
};


#endif /* LED_H */
