#ifndef RADIO_SX1278_H
#define RADIO_SX1278_H

#include "radio.h"


class RadioSX1278 : public Radio {
    public:
        bool init() override;
        bool send(const uint8_t* data, const uint16_t len) override;
};


#endif /* RADIO_SX1278_H */
