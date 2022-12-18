#ifndef COM_RECEIVER_H
#define COM_RECEIVER_H

#include "gps.h"
#include "radio.h"
#include "vsrtos.h"
#include "protocol.h"

#define RX_BUF_MAX_SIZE 128


class ComReceiver : public Task {
    public:
        ComReceiver(const protocol_t protocol, Radio* radio);
        int init() override;
        void update() override;
    private:
        protocol_t _protocol;
        Radio*     _radio;
        uint8_t    _rx_buf[RX_BUF_MAX_SIZE];

        void _handleProtocolSimple();
};

extern ComReceiver com_receiver;


#endif /* COM_RECEIVER_H */
