#include "radio_sx1278.h"

#include <LoRa.h>
#include "machine.h"

RadioSX1278::RadioSX1278(const long frequency)
: _frequency(frequency) {

}

bool RadioSX1278::send(const uint8_t* data, const uint16_t len) {
    LoRa.beginPacket();
    LoRa.write(data, len);
    LoRa.endPacket();
    return true;
}

size_t RadioSX1278::read(uint8_t* buf, const uint16_t len) {
    LoRa.readBytes(buf, len);
}

int RadioSX1278::init() {
    LoRa.setPins(RADIO_PIN_CS, RADIO_PIN_RESET, RADIO_PIN_IRQ);
    LoRa.setSpreadingFactor(6);  // 6-12
    LoRa.setSignalBandwidth(7.8E3);
    LoRa.begin(_frequency);
    return 0;
}

Radio* radio = new RadioSX1278();
