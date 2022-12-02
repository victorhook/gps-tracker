#ifndef SCHEDULER_H
#define SCHEDULER_H


#include "task.h"


void scheduler_init(Task* tasks[], const size_t number_of_tasks);


void scheduler_run();


#endif /* SCHEDULER_H */
