#ifndef GPS_H
#define GPS_H

#include "machine.h"
#include "vsrtos.h"

#include <SoftwareSerial.h>
#include <TinyGPS.h>


typedef struct {
    long latitude;
    long longitude;
    unsigned long fix_age;
} position_t;


class GPS : public Task {
    public:
        GPS(const uint8_t uartRx, const uint8_t uartTx, uint32_t baudRate = 4800);
        const position_t getPosition();

        int init()    override;
        void update() override;

    private:
        position_t      _position;
        TinyGPS*        _gps;
        SoftwareSerial* _uart;
        uint8_t         _uartRx;
        uint8_t         _uartTx;
        uint32_t        _baudRate;

        void _getNewPosition();
};

extern GPS gps;

#endif /* GPS_H */
