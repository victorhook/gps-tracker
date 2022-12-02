#ifndef TASK_H
#define TASK_H

#include "stdint.h"
#include "result.h"


class Task {
    /*
        Abstract class representing a Task.
    */
    public:
        virtual result_t init()      = 0;
        virtual void update()        = 0;
        virtual String name()        = 0;
        virtual uint32_t frequency() = 0;
};



#endif /* TASK_H */
