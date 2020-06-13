#ifndef PROCESSOR_H
#define PROCESSOR_H

#include "clock.h"

#define NBR_CLOCK_PER_PROCESSOR 6
#define SIZE_REGISTER           111 //0x00 to 0x6F = 111*8bits

class Processor
{
public:
    Processor();

    Clock* getClock(int index);

private:
    Clock* clock[NBR_CLOCK_PER_PROCESSOR];
};

#endif // PROCESSOR_H
