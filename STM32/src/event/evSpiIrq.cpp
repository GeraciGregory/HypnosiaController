#include "events.h"
#include "evSpiIrq.h"


evSpiIrq::evSpiIrq() :
	XFCustomEvent(evSpiIrqId)
{
	//setDeleteAfterConsume(false);
}
