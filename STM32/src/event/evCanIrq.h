#ifndef EVCANIRQ_H_
#define EVCANIRQ_H_

#include "EventsID.h"
#include "xf/customevent.h"

class evCanIrq : public XFCustomEvent
{
public:
	evCanIrq();
	virtual ~evCanIrq();
};

#endif /* EVCANIRQ_H_ */
