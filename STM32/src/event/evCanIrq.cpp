#include "events.h"
#include "evCanIrq.h"


evCanIrq::evCanIrq() :
	XFCustomEvent(evCanIrqId)
{
	//setDeleteAfterConsume(false);
}


