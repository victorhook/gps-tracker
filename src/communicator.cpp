#include "communicator.h"


Communicator::Communicator(const protocol_t protocol, Radio* radio)
: _protocol(protocol),
  _radio(radio) {

}

void Communicator::communicate(const position_t pos, const float batteryVoltage) {

}

int Communicator::init() {

    return 0;
}

void Communicator::update() {
    
}


#ifdef PROTOCOL_IN_USE_PROTOCOL_SIMPLE
Communicator communicator(PROTOCOL_SIMPLE, radio);
#endif
