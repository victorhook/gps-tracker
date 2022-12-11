#include "communicator.h"
#include "gps.h"
#include "battery.h"


Communicator::Communicator(const protocol_t protocol, Radio* radio)
: _protocol(protocol),
  _radio(radio) {

}

void Communicator::communicate(const position_t pos, const float batteryVoltage) {

}

int Communicator::init() {
    return _radio->init();
}

void Communicator::update() {
    const position_t pos = gps.getPosition();
    const float batteryVoltage = battery.getVoltage();

    bool send_data;

    switch (_protocol) {
        case PROTOCOL_SIMPLE:
            send_data = _handleProtocolSimple(&pos, batteryVoltage);
            break;
        default:
            // Should never occur
            Serial.printf("Failed to recognize protocol %d!\n", _protocol);
            send_data = false;
            break;
    }

    if (!send_data) {
        // Not much to do
        return;
    }

    radio->send(_tx_buf, _tx_len);
}


bool Communicator::_handleProtocolSimple(const position_t* pos, const float batteryVoltage) {
    protocol_simple_packet_t* packet = (protocol_simple_packet_t*) _tx_buf;
    packet->pos = *pos;
    packet->batteryVoltage = batteryVoltage;
    packet->timestamp = millis();
    _tx_len = sizeof(protocol_simple_packet_t);

    return true;
}


#ifdef PROTOCOL_IN_USE_PROTOCOL_SIMPLE
Communicator communicator(PROTOCOL_SIMPLE, radio);
#endif
