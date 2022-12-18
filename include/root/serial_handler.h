#ifndef SERIAL_HANDLER_H
#define SERIAL_HANDLER_H

#include "vsrtos.h"
#include <Arduino.h>

/*
    Handles serial communication between the device and the computer.
    This is only activated on the receiver, for instance to display the
    GPS data.
*/
class SerialHandler : public Task {
    public:
        SerialHandler();
        int init() override;
        void update() override;
    private:
        HardwareSerial* _serial;
};


extern SerialHandler serial_handler;


#endif /* SERIAL_HANDLER_H */
