#ifndef VSRTOS_H
#define VSRTOS_H

// Very simple RTOS

#include "stdint.h"
#include "cstddef"

class Task {
    /*
        Abstract class representing a Task.
    */
    public:
        virtual int init()    = 0;
        virtual void update() = 0;
};


typedef struct {
    Task*          task;
    const char     name[10];
    const uint16_t frequency;

    float          delay_ms;
    uint64_t       last_called;
    uint64_t       last_executed;
} task_block_t;


void scheduler_start(task_block_t task_blocks[], const size_t number_of_tasks);


#endif /* VSRTOS_H */
