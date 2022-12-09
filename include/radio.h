#ifndef RADIO_H
#define RADIO_H

#include "vsrtos.h"

class Radio : Task {
    public:
        virtual bool send(const uint8_t* data, const uint16_t len) = 0;
        virtual int init()    = 0;
        virtual void update() = 0;
};

extern Radio* radio;

#endif /* RADIO_H */
