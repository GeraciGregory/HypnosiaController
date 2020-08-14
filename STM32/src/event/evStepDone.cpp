#include "evStepDone.h"

evStepDone::evStepDone() :
	XFCustomEvent(EventsID::evSpiIrqId)
{
	//setDeleteAfterConsume(false);
}


evStepDone::~evStepDone()
{}
