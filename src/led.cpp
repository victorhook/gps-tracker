#include "led.h"
#include "machine.h"


static const led_state_t default_led_state = {
  .state = LED_STATE_ON,
  .color = COLOR_BLUE,
};

Led::Led() {

}

int Led::init() {
  _led = new Adafruit_NeoPixel(1, LED_PIN, NEO_RGB + NEO_KHZ800);
  _led->begin();

  // (const Task* task, const uint16_t frequency)

  return 0;
}

void Led::update() {

}

void Led::setColor(const uint32_t color) {
  static rgb_t rgb;
  memcpy(&rgb, &color, sizeof(rgb_t));
  _led->Color(rgb.r, rgb.g, rgb.b);
  _led->show();
}

void Led::setLedState(const led_state_t led_state) {
  switch (led_state.state) {
    case LED_STATE_OFF:
      break;
    case LED_STATE_ON:
      break;
    case LED_STATE_BLINK_0_25_HZ:
      break;
    case LED_STATE_BLINK_0_5_HZ:
      break;
    case LED_STATE_BLINK_1_HZ:
      break;
    case LED_STATE_BLINK_2_HZ:
      break;
  }
}