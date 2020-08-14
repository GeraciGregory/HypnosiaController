#include "evSpiIrq.h"

evSpiIrq::evSpiIrq() :
	XFCustomEvent(EventsID::evSpiIrqId)
{
	setDeleteAfterConsume(false);
}

evSpiIrq::~evSpiIrq()
{}
