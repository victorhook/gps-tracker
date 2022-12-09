#ifndef RADIO_SX1278_H
#define RADIO_SX1278_H

#include "radio.h"


class RadioSX1278 : public Radio {
    public:
        bool send(const uint8_t* data, const uint16_t len) override;
        int init()    override;
        void update() override;
};


#endif /* RADIO_SX1278_H */
