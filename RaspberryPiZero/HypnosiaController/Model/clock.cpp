#include "clock.h"

//Constructor
Clock::Clock(bool triaxes)
{
    //Define if we use biaxes or triaxes movements
    if(triaxes == true)
    {
        watchPointer[0] = new WatchPointer(2);  //2° output angle
        watchPointer[1] = new WatchPointer(2);  //2° output angle
    }
    else
    {
        watchPointer[0] = new WatchPointer(3);  //3° output angle
        watchPointer[1] = new WatchPointer(2);  //2° output angle
    }
}

WatchPointer* Clock::getWatchPointer(int index)
{
    return watchPointer[index];                 //Return selected watch pointer
}

int Clock::getNbrOfWatchPointer()
{
    return MAX_WATCHPOINTER;                    //Return number of MAX watch pointer per clock
}
