#ifndef CLOCK_H
#define CLOCK_H

#include "watchpointer.h"

#define MAX_WATCHPOINTER 3

class Clock
{
public:
    Clock();

    void setNbrWatchPointer(int nbr);
    int getNbrWatchPointer();
    int getNbrOfWatchPointer();
    WatchPointer* getWatchPointer(int index);

private:
    int nbrWatchPointer;
    WatchPointer* watchPointer[MAX_WATCHPOINTER];
};

#endif // CLOCK_H
