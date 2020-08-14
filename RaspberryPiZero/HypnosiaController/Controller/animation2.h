#ifndef ANIMATION2_H
#define ANIMATION2_H

#include "controller.h"
#define DELAY_2   1000

class Controller;

class Animation2
{
public:
    Animation2(Controller* host);
    ~Animation2();

private:
    Controller* host;

public:
    //State machine used for count down
    eEventStatus processEventAnim2(const XFEvent* ev);

protected:
    /**
     * Timeout identifier(s) for this state machine
     */
    typedef enum
    {
        TimeoutAnim2 = 1	///< Timeout id for WAIT
    } eTimeoutId;
    /**
     * Enumeration used to have a unique identifier for every
     * state in the state machine.
     */
    typedef enum
    {
        STATE_INIT = 0,
        STATE_WAIT = 1,
        STATE_1 = 2,
        STATE_2 = 3,
        STATE_3 = 4,
        STATE_4 = 5,
        STATE_5 = 6,
        STATE_6 = 7,
        STATE_7 = 8,
        STATE_8 = 9,
        STATE_END = 10
    } eAnim2State;

    eAnim2State _currentAnim2;		///< Attribute indicating currently active state
    eAnim2State _oldStateAnim2;     ///< Attribute indicating old state
};

#endif // ANIMATION2_H
