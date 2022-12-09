#include "led.h"
#include "machine.h"


static const led_state_t default_led_state = {
  .mode = LED_MODE_ON,
  .color = COLOR_BLUE,
};

Led::Led() {

}

int Led::init() {
  _led = new Adafruit_NeoPixel(1, LED_PIN, NEO_RGB + NEO_KHZ800);
  _led->begin();
  return 0;
}

void Led::update() {
  if (_next_state.mode == _curr_state.mode) {
    // No state change since last update, we'll just return.
    return;
  }

  // Get time difference since last time we switched led ON/OFF.
  unsigned long now = millis();
  unsigned long dt_ms = now - _last_time_led_switched;
  bool led_is_on = true;

  switch (_next_state.mode) {
    case LED_MODE_OFF:
      led_is_on = false;
      break;
    case LED_MODE_ON:
      led_is_on = true;
      break;
    case LED_MODE_BLINK_0_25_HZ: // 125 ms
      if (dt_ms >= 125)
        led_is_on = !_led_is_on;
      break;
    case LED_MODE_BLINK_0_5_HZ:  // 250 ms
      if (dt_ms >= 250)
        led_is_on = !_led_is_on;
      break;
    case LED_MODE_BLINK_1_HZ:    // 500 ms
      if (dt_ms >= 500)
        led_is_on = !_led_is_on;
      break;
    case LED_MODE_BLINK_2_HZ:    // 1000 ms
      if (dt_ms >= 1000)
        led_is_on = !_led_is_on;
      break;
  }

  if (led_is_on) {
    _setColor(_next_state.color);
  } else {
    _setColor(LED_OFF);
  }

  if (led_is_on != _led_is_on) {
    _last_time_led_switched = now;
  }

  _curr_state = _next_state;
}

void Led::setLedState(const uint32 color, const led_mode_t mode) {
  _next_state.color = color;
  _next_state.mode = mode;
}

void Led::_setColor(const uint32_t color) {
  static rgb_t rgb;
  memcpy(&rgb, &color, sizeof(rgb_t));
  _led->Color(rgb.r, rgb.g, rgb.b);
  _led->show();
}

// Initialize LED
Led led;
