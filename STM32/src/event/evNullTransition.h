#ifndef EVNULLTRANSITION_H_
#define EVNULLTRANSITION_H_

#include "EventsID.h"
#include "xf/customevent.h"

class evNullTransition : public XFCustomEvent
{
public:
	evNullTransition();
	~evNullTransition();
};

#endif /* EVNULLTRANSITION_H_ */
