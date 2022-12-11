#ifndef COMMUNICATOR_H
#define COMMUNICATOR_H

#include "gps.h"
#include "radio.h"
#include "vsrtos.h"


#define TX_BUF_MAX_SIZE 128


typedef enum {
    PROTOCOL_SIMPLE
} protocol_t;

typedef struct {
    position_t pos;
    float      batteryVoltage;
    uint64_t   timestamp;
} __attribute__((packed)) protocol_simple_packet_t;


class Communicator : public Task {
    public:
        Communicator(const protocol_t protocol, Radio* radio);
        void communicate(const position_t pos, const float batteryVoltage);

        int init() override;
        void update() override;
    private:
        protocol_t _protocol;
        Radio*     _radio;
        uint8_t    _tx_buf[TX_BUF_MAX_SIZE];
        uint16_t   _tx_len;

        bool _handleProtocolSimple(const position_t* pos, const float batteryVoltage);
};

extern Communicator communicator;


#endif /* COMMUNICATOR_H */
