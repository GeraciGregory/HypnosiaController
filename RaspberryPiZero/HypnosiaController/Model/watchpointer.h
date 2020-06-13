#ifndef WATCHPOINTER_H
#define WATCHPOINTER_H

#include <iostream>
using namespace std;

class WatchPointer
{
public:
    WatchPointer();
    ~WatchPointer();

    void incrementPosition();
    void decrementPosition();

    void setClockWise(bool cw);
    char getClockWise();

    void setNbrTurns(char nt);
    char getNbrTurns();

    void setNewPosition(char np);
    char getNewPosition();

    void setTimeMovementDuration(char tmd);
    char getTimeMovementDuration();

    void setOffsetStartTime(char ost);
    char getOffsetStartTime();

private:
    char clockwise;
    char nbrTurns;
    char actualPosition;
    char newPosition;
    char timeMovementDuration;
    char offsetStartTime;
};

#endif // WATCHPOINTER_H
