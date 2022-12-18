#ifndef RADIO_SX1278_H
#define RADIO_SX1278_H

#include "radio.h"


class RadioSX1278 : public Radio {
    public:
        RadioSX1278(const long frequency = 443e6);
        bool send(const uint8_t* data, const uint16_t len) override;
        size_t read(uint8_t* buf, const uint16_t len) override;
        int init() override;

    private:
        long _frequency;
};


#endif /* RADIO_SX1278_H */
