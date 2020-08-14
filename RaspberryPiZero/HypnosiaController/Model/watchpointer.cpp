#include "watchpointer.h"

//------------------------------------------------------------------------
//Constructor
WatchPointer::WatchPointer(char outputAngle)
{
    this->outputAngle = outputAngle;

    clockwise = true;
    this->nbrTurns = 0x00;
    this->actualPosition = 0x00;
    this->newPosition = 0x00;
    this->timeMovementDuration = 0x00;
    this->offsetStartTime = 0x00;
}
//------------------------------------------------------------------------
char WatchPointer::getOutputAngle()
{
    return this->outputAngle;           //Return 2 or 3
}
//------------------------------------------------------------------------
void WatchPointer::resetPositionZero()
{
    this->actualPosition = 0;
    this->newPosition = 0;
}
//------------------------------------------------------------------------
void WatchPointer::incrementPosition()
{
    if(actualPosition == ((360/outputAngle)-1) )
    {
        newPosition = 0;
    }
    else
    {
        newPosition = actualPosition+1;
    }
    clockwise = true;
    actualPosition = newPosition;
}
void WatchPointer::decrementPosition()
{
    if(actualPosition == 0)
    {
        newPosition = ((360/outputAngle)-1);
    }
    else
    {
        newPosition = actualPosition-1;
    }
    clockwise = false;
    actualPosition = newPosition;
}
//------------------------------------------------------------------------
void WatchPointer::setClockWise(bool cw)
{
    if(cw == true)
    {
        clockwise = 0x01;
    }
    else
    {
        clockwise = 0x00;
    }
}
char WatchPointer::getClockWise()
{
    return  clockwise;
}
//------------------------------------------------------------------------
void WatchPointer::setNbrTurns(char nt)
{
    this->nbrTurns = nt;
}
char WatchPointer::getNbrTurns()
{
    return nbrTurns;
}
//------------------------------------------------------------------------
void WatchPointer::setNewPosition(char np)
{
    this->newPosition = np;
    this->actualPosition = this->newPosition;
}
char WatchPointer::getNewPosition()
{
    return newPosition;
}
//------------------------------------------------------------------------
void WatchPointer::setTimeMovementDuration(char tmd)
{
    this->timeMovementDuration = tmd;
}
char WatchPointer::getTimeMovementDuration()
{
    return timeMovementDuration;
}
//------------------------------------------------------------------------
void WatchPointer::setOffsetStartTime(char ost)
{
    this->offsetStartTime = ost;
}
char WatchPointer::getOffsetStartTime()
{
    return  offsetStartTime;
}
//------------------------------------------------------------------------
