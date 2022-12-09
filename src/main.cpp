#include "machine.h"
#include "gps.h"
#include "radio_sx1278.h"
#include "communicator.h"
#include "battery.h"
#include "led.h"
#include "result.h"
#include "vsrtos.h"


#ifdef RADIO_IN_USE_SX1278
Radio* radio = new RadioSX1278();
#endif


GPS gps(GPS_UART_RX, GPS_UART_TX, GPS_UART_BAUD);
Led led;
//Communicator com(PROTOCOL_SIMPLE, radio);
//Battery battery(BATTERY_PIN);


task_block_t task_blocks[] = {
    {
        .task=&gps,
        {.name="GPS"},
        .frequency=5
    }
    //{&led, "LED", 5}
};

#define NBR_OF_TASKS (sizeof(task_blocks) / sizeof(task_block_t))


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
        task_block_t task_block = task_blocks[i];
        int task_init_result = task_block.task->init();

        if (task_init_result != RESULT_OK) {
            Serial.printf("Failed to initialize task: %s\n", task_block.name);
        }

        result = (result_t) (result | task_init_result);
    }

    if (result != RESULT_OK) {
        while (1) {
            Serial.println(F("System failed to initialize properly..."));
            delay(500);
        }
    }

    Serial.println(F("System initialized OK, starting scheduler"));
    scheduler_start(task_blocks, NBR_OF_TASKS);
}

void loop() {

}


//const position_t pos = gps.getPosition();
//const float batteryVoltage = battery.getVoltage();
//com.communicate(pos, batteryVoltage);
