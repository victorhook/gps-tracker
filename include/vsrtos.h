#ifndef VSRTOS_H
#define VSRTOS_H

// Very simple RTOS

#include "stdint.h"
#include "cstddef"


typedef enum {
    VS_RESULT_OK = 0
} vs_result_t;


class Task {
    /*
        Abstract class representing a Task.
    */
    public:
        virtual int init()    = 0;
        virtual void update() = 0;
};



template<typename T>
struct element_t {
    T t;
};

class Queue {
    public:
        Queue(const size_t size_of_element, const size_t max_nbr_of_elements);
        vs_result_t put();
        vs_result_t get();
    private:
        size_t _size_of_element;
        size_t _max_nbr_of_elements;
};


typedef struct {
    Task*          task;
    const char     name[10];
    const uint16_t frequency;

    float          delay_ms;
    uint64_t       last_called;
    uint64_t       last_executed;
} task_block_t;


void scheduler_start(task_block_t* task_blocks[], const size_t number_of_tasks);


#endif /* VSRTOS_H */
