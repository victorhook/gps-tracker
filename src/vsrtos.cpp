#include "vsrtos.h"

#include <Arduino.h>

static task_block_t** all_task_blocks;
static size_t nbr_of_tasks;

#define IDLE_TASK NULL

#define currentTime() millis()


static task_block_t* getNextTask();
static void scheduler_init();
static bool is_init = false;


void scheduler_start(task_block_t* task_blocks[], const size_t number_of_tasks) {
    if (is_init) {
        Serial.println(F("Scheduler already started!"));
        return;
    }

    all_task_blocks = task_blocks;
    nbr_of_tasks = number_of_tasks;

    scheduler_init();
    Serial.printf("Scheduler initialized with %d tasks\n", nbr_of_tasks);

    is_init = true;

    Serial.println(F("Scheduler starting"));

    while (1) {
        task_block_t* next_task = getNextTask();
        if (next_task == IDLE_TASK) {
            // Not much to do, we're just idling.
            yield();
            continue;
        }

        //Serial.printf("[%d] Running task: %s\n", currentTime(), next_task->name);
        next_task->last_called = currentTime();
        next_task->task->update();
        next_task->last_executed = currentTime();
    }
}


vs_result_t Queue::put() {
    return VS_RESULT_OK;
}

vs_result_t Queue::get() {
    return VS_RESULT_OK;
}



// -- Private -- /

static task_block_t* getNextTask() {
    uint64_t now = currentTime();

    for (size_t task = 0; task < nbr_of_tasks; task++) {
        task_block_t* next_task = all_task_blocks[task];

        uint64_t time_since_last_execution = now - next_task->last_executed;

        if (time_since_last_execution > next_task->delay_ms) {
            // Enough time has passed since this task executed,
            // it's time to execute this task.
            return next_task;
        }

    }

    return IDLE_TASK;
}

/*
    Sets some default values for all the task_block structs, to ensure
    that they have proper values before we begin.
*/
static void scheduler_init() {
    for (size_t i = 0; i < nbr_of_tasks; i++) {
        task_block_t* task_block = all_task_blocks[i];
        task_block->delay_ms = 1000.0 / task_block->frequency;
        task_block->last_called = 0;
        task_block->last_executed = 0;
    }
}
