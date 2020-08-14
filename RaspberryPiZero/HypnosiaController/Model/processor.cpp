#include "processor.h"

Processor::Processor()
{
    //Create dynamic objects
    //All biaxes
    clock[0] = new Clock(false);
    clock[1] = new Clock(false);
    clock[2] = new Clock(false);
    clock[3] = new Clock(false);
    clock[4] = new Clock(false);
    clock[5] = new Clock(false);
}

Clock* Processor::getClock(int index)
{
    //Return slected clock
    return clock[index];
}
