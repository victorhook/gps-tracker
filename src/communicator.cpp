#include "communicator.h"


Communicator::Communicator(const protocol_t protocol, Radio* radio)
: _protocol(protocol),
  _radio(radio) {

}

void Communicator::communicate(const position_t pos, const float batteryVoltage) {

}