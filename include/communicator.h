#ifndef COMMUNICATOR_H
#define COMMUNICATOR_H

#include "gps.h"
#include "radio.h"


typedef enum {
    PROTOCOL_SIMPLE
} protocol_t;


class Communicator {
    public:
        Communicator(const protocol_t protocol, Radio* radio);
        void communicate(const position_t pos, const float batteryVoltage);
    private:
        protocol_t _protocol;
        Radio*     _radio;
};

/*
Communicator com(PROTOCOL_SIMPLE, &radio);


com.communicate(data);

*/


#endif /* COMMUNICATOR_H */
