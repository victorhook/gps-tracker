#ifndef PROTOCOL_H
#define PROTOCOL_H


typedef enum {
    PROTOCOL_SIMPLE
} protocol_t;

typedef struct {
    position_t pos;
    float      batteryVoltage;
    uint64_t   timestamp;
} __attribute__((packed)) protocol_simple_packet_t;



#endif /* PROTOCOL_H */
