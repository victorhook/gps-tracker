#ifndef STATE_ROOT_H
#define STATE_ROOT_H

#include "gps.h"


typedef struct {
    position_t position_root;
    position_t position_leaf;
    
} state_t;

extern state_t state;


#endif /* STATE_ROOT_H */
