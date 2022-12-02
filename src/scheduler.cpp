#include "scheduler.h"
#include "task.h"

#include <Arduino.h>



typedef struct {
    Task* task;

    float delay_ms;
    uint64_t last_called;
    uint64_t last_executed;
} task_block_t;

static task_block_t* task_blocks[10];
static size_t nbr_of_tasks;

#define IDLE_TASK NULL

#define currentTime() millis()


static task_block_t* getNextTask();


void scheduler_init(Task* tasks[], const size_t number_of_tasks) {
    for (size_t i = 0; i < number_of_tasks; i++) {
        Task* task = tasks[i];
        task_block_t* task_block = (task_block_t*) malloc(sizeof(task_block_t));
        task_block->delay_ms = 1000.0 / task->frequency();
        task_block->task = task;
        task_blocks[i] = task_block;
    }

    nbr_of_tasks = nbr_of_tasks;
}

void scheduler_run() {
    Serial.println("Scheduler starting");

    while (1) {
        task_block_t* next_task = getNextTask();
        if (next_task == IDLE_TASK) {
            // Not much to do, we're just idling.
            continue;
        }

        next_task->last_called = currentTime();
        next_task->task->update();
        next_task->last_executed = currentTime();
    }
}


// -- Private -- /

static task_block_t* getNextTask() {
    uint64_t now = currentTime();

    for (size_t task = 0; task < nbr_of_tasks; task++) {
        task_block_t* next_task = task_blocks[task];

        uint64_t time_since_last_execution = now - next_task->last_executed;
        if (time_since_last_execution > next_task->delay_ms) {
            // Enough time has passed since this task executed,
            // it's time to execute this task.
            return next_task;
        }

    }

    return IDLE_TASK;
}