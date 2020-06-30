#include "events.h"
#include "evFlagTrigger.h"

evFlagTrigger::evFlagTrigger() :
	XFCustomEvent(evFlagTriggerId)
{
	//setDeleteAfterConsume(false);
}
