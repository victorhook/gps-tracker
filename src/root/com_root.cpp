#include "com_root.h"


ComReceiver::ComReceiver(const protocol_t protocol, Radio* radio)
: _protocol(protocol),
  _radio(radio) {

}

int ComReceiver::init() {
    return _radio->init();
}

void ComReceiver::update() {

    switch (_protocol) {
        case PROTOCOL_SIMPLE:
            _handleProtocolSimple();
            break;
        default:
            // Should never occur
            Serial.printf("Failed to recognize protocol %d!\n", _protocol);
            break;
    }

}

void ComReceiver::_handleProtocolSimple() {
    const size_t bytes_to_read = sizeof(protocol_simple_packet_t);
    static protocol_simple_packet_t rx_pkt;
    int bytes_read = _radio->read(_rx_buf, bytes_to_read);
    if (bytes_read < bytes_to_read) {
        // TOOD
    } else {
        memcpy(&rx_pkt, _rx_buf, bytes_read);
    }
}


#ifdef PROTOCOL_IN_USE_PROTOCOL_SIMPLE
ComReceiver com_receiver(PROTOCOL_SIMPLE, radio);
#endif
