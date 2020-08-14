#ifndef PROCESSOR_H
#define PROCESSOR_H

//---------------------------------------INCLUDE----------------------------------------
#include "clock.h"
//---------------------------------------DEFINE-----------------------------------------
#define NBR_CLOCK_PER_PROCESSOR 6
//--------------------------------------------------------------------------------------
class Processor
{
public:
    Processor();                            //Constructor

    Clock* getClock(int index);             //Used to use the selected clock

private:
    Clock* clock[NBR_CLOCK_PER_PROCESSOR];
};

#endif // PROCESSOR_H
