#include "processor.h"

Processor::Processor()
{
    for(int i=0; i<NBR_CLOCK_PER_PROCESSOR; i++)
    {
        clock[i] = new Clock();
    }
}


Clock* Processor::getClock(int index)
{
    return clock[index];
}
