#ifndef CLOCK_H
#define CLOCK_H

#include "watchpointer.h"

#define MAX_WATCHPOINTER 2

class Clock
{
public:
    Clock(bool triaxes);                            //Constructor

    void setNbrWatchPointer(int nbr);               //Set number of watch pointer per clock (2 or 3)
    int getNbrOfWatchPointer();                     //Return number of MAX watch pointer per clock
    WatchPointer* getWatchPointer(int index);       //Used to use the selected watch pointer

private:
    int nbrWatchPointer;
    WatchPointer* watchPointer[MAX_WATCHPOINTER];
};

#endif // CLOCK_H
