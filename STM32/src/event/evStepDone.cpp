#include "events.h"
#include "evStepDone.h"

evStepDone::evStepDone() :
	XFCustomEvent(evSpiIrqId)
{
	//setDeleteAfterConsume(false);
}
