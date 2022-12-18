#ifndef RADIO_H
#define RADIO_H

#include "vsrtos.h"

class Radio {
    public:
        virtual bool send(const uint8_t* data, const uint16_t len) = 0;
        virtual size_t read(uint8_t* buf, const uint16_t len);
        virtual int init() = 0;
};

extern Radio* radio;

#endif /* RADIO_H */
