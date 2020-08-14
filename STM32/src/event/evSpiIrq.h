#ifndef EVSPIIRQ_H_
#define EVSPIIRQ_H_

#include "EventsID.h"
#include "xf/customevent.h"

class evSpiIrq : public XFCustomEvent
{
public:
	evSpiIrq();
	~evSpiIrq();
};

#endif /* EVSPIIRQ_H_ */
