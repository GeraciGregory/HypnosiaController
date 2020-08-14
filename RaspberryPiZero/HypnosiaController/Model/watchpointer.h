#ifndef WATCHPOINTER_H
#define WATCHPOINTER_H

#include <iostream>
using namespace std;

class WatchPointer
{
public:
    WatchPointer(char outputAngle);             //Constructor, define output angle of the watch pointer

    void resetPositionZero();                   //Reset position

    void incrementPosition();                   //Increment position
    void decrementPosition();                   //Decrement position

    //Setter and getter for clockwise variable
    void setClockWise(bool cw);
    char getClockWise();

    //Setter and getter for nbrTurns variable
    void setNbrTurns(char nt);
    char getNbrTurns();

    //Setter and getter for newPosition variable
    void setNewPosition(char np);
    char getNewPosition();

    //Setter and getter for timeMovementDuration variable
    void setTimeMovementDuration(char tmd);
    char getTimeMovementDuration();

    //Setter and getter for offsetStartTime variable
    void setOffsetStartTime(char ost);
    char getOffsetStartTime();

    char getOutputAngle();                      //Get output angle (2° or 3°)

private:
    char clockwise;
    char nbrTurns;
    char actualPosition;
    char newPosition;
    char timeMovementDuration;
    char offsetStartTime;
    char outputAngle;
};

#endif // WATCHPOINTER_H
