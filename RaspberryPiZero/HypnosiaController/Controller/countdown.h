#ifndef COUNTDOWN_H
#define COUNTDOWN_H

#include "controller.h"

class Controller;

class CountDown
{
public:
    CountDown(Controller* host);
    ~CountDown();

private:
    Controller* host;

public:
    //State machine used for count down
    eEventStatus processEventCntDown(const XFEvent* ev);

protected:
    /**
     * Timeout identifier(s) for this state machine
     */
    typedef enum
    {
        TimeoutCntDown = 1	///< Timeout id for WAIT
    } eTimeoutId;
    /**
     * Enumeration used to have a unique identifier for every
     * state in the state machine.
     */
    typedef enum
    {
        STATE_INIT_CNTDOWN = 0,
        STATE_WAIT_CNTDOWN = 1,
        STATE_3 = 2,
        STATE_2 = 3,
        STATE_1 = 4,
        STATE_END = 5
    } eCntDownState;

    eCntDownState _currentStateCntDown;		///< Attribute indicating currently active state
    eCntDownState _oldStateCntDown;           ///< Attribute indicating old state
};

#endif // COUNTDOWN_H
