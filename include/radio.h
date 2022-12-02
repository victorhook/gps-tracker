#ifndef RADIO_H
#define RADIO_H

#include "task.h"


class Radio : Task {
    public:
        virtual bool send(const uint8_t* data, const uint16_t len) = 0;
        virtual result_t init()      = 0;
        virtual void update()        = 0;
        virtual String name()        = 0;
        virtual uint32_t frequency() = 0;
};


#endif /* RADIO_H */
