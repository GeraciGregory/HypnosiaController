#include "clock.h"

Clock::Clock()
{
    for(int i=0; i<MAX_WATCHPOINTER; i++)
    {
        watchPointer[i] = new WatchPointer();
    }
}


WatchPointer* Clock::getWatchPointer(int index)
{
    return watchPointer[index];
}

int Clock::getNbrOfWatchPointer()
{
    return MAX_WATCHPOINTER;
}
