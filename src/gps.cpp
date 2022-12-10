#include "gps.h"


GPS::GPS(const uint8_t uartRx, const uint8_t uartTx, uint32_t baudRate)
:
_uartRx(uartRx),
_uartTx(uartTx),
_baudRate(baudRate)
{
    _gps = new TinyGPS();
    _uart = new SoftwareSerial(_uartRx, _uartTx);
}

const position_t GPS::getPosition() {

    if (_uart->available()) {
        _getNewPosition();
    }

    position_t pos;
    memcpy(&pos, &_position, sizeof(position_t));
    return pos;
}

int GPS::init() {
    _uart->begin(_baudRate);
    return 0;
}

void GPS::update() {
    while (_uart->available() > 0)
        Serial.write(_uart->read());
}

// -- Private -- /
void GPS::_getNewPosition() {
    while(_uart->available()) {
        while (_uart->available()) {
            _gps->encode(_uart->read());
        }
    }

    _gps->get_position(&_position.latitude, &_position.longitude, &_position.fix_age);
}


// Initialize GPS
GPS gps(GPS_UART_RX, GPS_UART_TX, GPS_UART_BAUD);
