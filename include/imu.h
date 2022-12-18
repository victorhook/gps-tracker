#ifndef IMU_H
#define IMU_H

#include "vsrtos.h"


typedef struct {
    float x;
    float y;
    float z;
} gyro_t;

typedef struct {
    float x;
    float y;
    float z;
} acc_t;

typedef struct {
    gyro_t   gyro;
    acc_t    acc;
    float    temperature;
    uint64_t timestamp;
} imu_reading_t;


class IMU : public Task {
    public:
        IMU();
        void update() override;
        int init() override;
    private:
        imu_reading_t _last_reading;
};

extern IMU imu;


#endif /* IMU_H */
