#ifndef EVSTEPDONE_H_
#define EVSTEPDONE_H_

#include "EventsID.h"
#include "xf/customevent.h"

class evStepDone : public XFCustomEvent
{
public:
	evStepDone();
	~evStepDone();
};

#endif /* EVSTEPDONE_H_ */
