#ifndef RADIO_H
#define RADIO_H

#include "vsrtos.h"

class Radio {
    public:
        virtual bool send(const uint8_t* data, const uint16_t len) = 0;
        virtual int init() = 0;
};

extern Radio* radio;

#endif /* RADIO_H */
