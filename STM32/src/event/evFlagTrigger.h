#ifndef EVFLAGTRIGGER_H_
#define EVFLAGTRIGGER_H_

#include "EventsID.h"
#include "xf/customevent.h"

class evFlagTrigger : public XFCustomEvent
{
public:
	evFlagTrigger();
	~evFlagTrigger();
};

#endif /* EVFLAGTRIGGER_H_ */
