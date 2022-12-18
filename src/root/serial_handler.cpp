#include "serial_handler.h"


SerialHandler::SerialHandler()
: _serial(&Serial) {

}

int SerialHandler::init() {
    Serial.begin(115200);
    return 0;
}

void SerialHandler::update() {

}

SerialHandler serial_handler;
