#ifndef EVDONE_H_
#define EVDONE_H_

#include "EventsID.h"
#include "xf/customevent.h"

class evDone : public XFCustomEvent
{
public:
	evDone();
	~evDone();
};

#endif /* EVDONE_H_ */
