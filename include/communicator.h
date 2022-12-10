#ifndef COMMUNICATOR_H
#define COMMUNICATOR_H

#include "gps.h"
#include "radio.h"
#include "vsrtos.h"


typedef enum {
    PROTOCOL_SIMPLE
} protocol_t;


class Communicator : Task {
    public:
        Communicator(const protocol_t protocol, Radio* radio);
        void communicate(const position_t pos, const float batteryVoltage);

        int init() override;
        void update() override;
    private:
        protocol_t _protocol;
        Radio*     _radio;
};

extern Communicator communicator;


#endif /* COMMUNICATOR_H */
