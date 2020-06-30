#ifndef EVSPIIRQ_H_
#define EVSPIIRQ_H_

#include "xf/customevent.h"
#include "events.h"

class evSpiIrq : public XFCustomEvent
{
public:
	evSpiIrq();
};

#endif /* EVSPIIRQ_H_ */
