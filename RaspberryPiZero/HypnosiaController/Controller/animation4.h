#ifndef ANIMATION4_H
#define ANIMATION4_H

#include "controller.h"
#define DELAY_4   4000

class Controller;

class Animation4
{
public:
    Animation4(Controller* host);
    ~Animation4();

private:
    Controller* host;

public:
    //State machine used for count down
    eEventStatus processEventAnim4(const XFEvent* ev);

protected:
    /**
     * Timeout identifier(s) for this state machine
     */
    typedef enum
    {
        TimeoutAnim4 = 1	///< Timeout id for WAIT
    } eTimeoutId;
    /**
     * Enumeration used to have a unique identifier for every
     * state in the state machine.
     */
    typedef enum
    {
        STATE_INIT = 0,
        STATE_WAIT = 1,
        STATE_WRITE = 2,
        STATE_END = 3
    } eAnim4State;

    eAnim4State _currentAnim4;		///< Attribute indicating currently active state
    eAnim4State _oldStateAnim4;     ///< Attribute indicating old state
};


#endif // ANIMATION4_H
