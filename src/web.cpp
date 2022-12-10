#include "web.h"
#include "led.h"
#include "wifi_credentials.h"

#include <ESP8266WiFi.h>


Web::Web(const uint16_t port)
: _connected_to_wifi(false),
  _initialized_server(false),
  _client_connected(false),
  _server(port) {

}

int Web::init() {
    WiFi.begin(WIFI_SSID, WIFI_PASS);
    led.setLedState(COLOR_BLUE, LED_MODE_BLINK_0_25_HZ);
    return 0;
}

void Web::update() {
    wl_status_t status = WiFi.status();

    if (status != WL_CONNECTED) {
        if (_connected_to_wifi) {
            // Must have been disconnected, let's try to connect again
            WiFi.begin(WIFI_SSID, WIFI_PASS);
            _connected_to_wifi = false;
        } else {
            // Not initialized yet, we'll just wait until we're connected to WiFi.
        }

        if (_initialized_server) {
            _server.close();
            _initialized_server = false;
            _client_connected = false;
        }

        return;
    } else {
        if (!_connected_to_wifi) {
            led.setLedState(COLOR_BLUE, LED_MODE_BLINK_2_HZ);
            _connected_to_wifi = true;
        }
    }

    if (!_initialized_server) {
        _server.begin();
        _initialized_server = true;
    }

    static WiFiClient client;

    if (!_client_connected) {
        client = _server.available();

        if (client) {
            _client_connected = true;
            led.setLedState(COLOR_BLUE, LED_MODE_ON);
        }
    }

    if (_client_connected) {

        if (client) {
            while(client.available()) {
                client.write(client.read());
            }
        } else {
            // Client disconnected
            _client_connected = false;
            led.setLedState(COLOR_BLUE, LED_MODE_BLINK_2_HZ);
        }

    }

}

Web web;
