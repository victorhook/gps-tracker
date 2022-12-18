#include "imu.h"
#include "machine.h"
#include "Arduino_BMI270_BMM150.h"

IMU::IMU() {

}

void IMU::update() {
    // 1. Read sensor data
    static imu_reading_t reading;

    // Accelerometer
    if (BMI_IMU.accelerationAvailable()) {
        BMI_IMU.readAcceleration(reading.acc.x, reading.acc.y, reading.acc.z);
    }

    // Gyro
    if (BMI_IMU.gyroscopeAvailable()) {
        BMI_IMU.readGyroscope(reading.gyro.x, reading.gyro.y, reading.gyro.z);
    }

    // Temperature
    //reading.temperature = BMI_IMU.getTemperature();

    reading.timestamp = millis();

    memcpy(&_last_reading, &reading, sizeof(imu_reading_t));

    // 2. Filter?
    // 3. Sensor fusion?
}

int IMU::init() {
    return BMI_IMU.begin();
}


IMU imu;
