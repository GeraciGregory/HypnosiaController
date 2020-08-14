#ifndef ANIMATION3_H
#define ANIMATION3_H

#include "controller.h"
#define DELAY_3   4000

class Controller;

class Animation3
{
public:
    Animation3(Controller* host);
    ~Animation3();

private:
    Controller* host;

public:
    //State machine used for count down
    eEventStatus processEventAnim3(const XFEvent* ev);

protected:
    /**
     * Timeout identifier(s) for this state machine
     */
    typedef enum
    {
        TimeoutAnim3 = 1	///< Timeout id for WAIT
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
        STATE_END = 5
    } eAnim3State;

    eAnim3State _currentAnim3;		///< Attribute indicating currently active state
    eAnim3State _oldStateAnim3;     ///< Attribute indicating old state
};


#endif // ANIMATION3_H
