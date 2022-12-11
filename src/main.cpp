#include "machine.h"
#include "gps.h"
#include "radio_sx1278.h"
#include "communicator.h"
#include "battery.h"
#include "led.h"
#include "result.h"
#include "web.h"
#include "vsrtos.h"

#include <Arduino.h>


task_block_t gps_task = {
    .task = &gps,
    {.name = "GPS"},
    .frequency = 5
};
task_block_t led_task = {
    .task = &led,
    {.name = "LED"},
    .frequency = 10
};
task_block_t web_task = {
    .task = &web,
    {.name = "WEB"},
    .frequency = 20
};
task_block_t com_task = {
    .task = &communicator,
    {.name = "COM"},
    .frequency = 50
};

task_block_t* task_blocks[] = {
    &gps_task,
    &com_task,
    &led_task,
    &web_task
};


#define NBR_OF_TASKS (sizeof(task_blocks) / sizeof(task_block_t*))

static void init_task(const task_block_t* task_block, result_t* result);


void setup() {
    Serial.begin(115200);
    Serial.println(F("System initializing..."));
    result_t result = RESULT_OK;

    init_task(&led_task, &result);
    if (result != RESULT_OK) {
        // Something very serious must have happened if LED driver fails...
        while (1);
    }

    // Set initial led state
    led.setLedState(COLOR_GREEN, LED_MODE_BLINK_1_HZ);

    // Initialize part of system that are not task-bound
    battery.init();

    // Initialize system tasks
    init_task(&gps_task, &result);
    init_task(&web_task, &result);
    init_task(&com_task, &result);

    // Check result after task initialization
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


static void init_task(const task_block_t* task_block, result_t* result) {
    int task_init_result = task_block->task->init();

    if (task_init_result != RESULT_OK) {
        Serial.printf("Failed to initialize task: %s\n", task_block->name);
    }

    *result = (result_t) (*result | task_init_result);
}