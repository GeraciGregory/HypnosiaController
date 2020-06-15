#ifndef EVRESTART_H
#define EVRESTART_H


//#include "xf-core/customevent.h"
#include "xf/xf-core/customevent.h"
#include "eventids.h"


/**
 * Restart event used to reset a state machine
 */
class evRestart : public XFCustomEvent
{
public:
	evRestart();
	virtual ~evRestart();
};

#endif // EVRESTART_H
