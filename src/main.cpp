#include "machine.h"
#include "gps.h"
#include "radio_sx1278.h"
#include "communicator.h"
#include "battery.h"
#include "led.h"
#include "result.h"
#include "scheduler.h"


#ifdef RADIO_IN_USE_SX1278
Radio* radio = new RadioSX1278();
#endif


GPS gps(GPS_UART_RX, GPS_UART_TX, GPS_UART_BAUD);
Led led;
//Communicator com(PROTOCOL_SIMPLE, radio);
//Battery battery(BATTERY_PIN);


Task* tasks[] = {
    {&gps, "GPS", 5},
    {&led, "LED", 5}
};

#define NBR_OF_TASKS (sizeof(tasks) / sizeof(Task))


void setup() {
    Serial.begin(115200);
    Serial.println(F("System initializing..."));

    // Initialize system, eg I/O and other essentials.
    //result_t result = sys_init();
    result_t result = RESULT_OK;
    if (result != RESULT_OK) {
        while (1) {
            Serial.println(F("System failed to initialize properly"));
            Serial.printf("Error: %s\n", resultToString(result).c_str());
            delay(500);
        }
    }

    Serial.println(F("System initialized OK, initializing tasks"));

    // Check result after task initialization
    for (uint32_t i = 0; i < NBR_OF_TASKS; i++) {
        Task* task = tasks[i];
        result_t task_init_result = task->init();

        if (task_init_result != RESULT_OK) {
            Serial.printf("Failed to initialize task: %s\n", task->name().c_str());
        }

        result = (result_t) (result | task_init_result);
    }

    if (result != RESULT_OK) {
        while (1) {
            Serial.println(F("System failed to initialize properly..."));
            delay(500);
        }
    }

    Serial.println(F("System initialized OK, initializing scheduler"));
    scheduler_init(tasks, NBR_OF_TASKS);

    Serial.println(F("Scheduler initialized OK, starting scheduler"));
    scheduler_run();

    //const position_t pos = gps.getPosition();
    //const float batteryVoltage = battery.getVoltage();
    //com.communicate(pos, batteryVoltage);
}

void loop() {

}
