#ifndef ANIMATION1_H
#define ANIMATION1_H

#include "controller.h"
#define DELAY_1    4000

class Controller;

class Animation1
{
public:
    Animation1(Controller* host);
    ~Animation1();

private:
    Controller* host;

public:
    //State machine used for count down
    eEventStatus processEventAnim1(const XFEvent* ev);

protected:
    /**
     * Timeout identifier(s) for this state machine
     */
    typedef enum
    {
        TimeoutAnim1 = 1	///< Timeout id for WAIT
    } eTimeoutId;
    /**
     * Enumeration used to have a unique identifier for every
     * state in the state machine.
     */
    typedef enum
    {
        STATE_INIT = 0,
        STATE_WAIT = 1,
        STATE_3 = 2,
        STATE_2 = 3,
        STATE_1 = 4,
        STATE_END = 5
    } eAnim1State;

    eAnim1State _currentAnim1;		///< Attribute indicating currently active state
    eAnim1State _oldStateAnim1;     ///< Attribute indicating old state
};

#endif // ANIMATION1_H



