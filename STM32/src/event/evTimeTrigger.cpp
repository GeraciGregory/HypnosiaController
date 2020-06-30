#include "events.h"
#include "evTimeTrigger.h"

evTimeTrigger::evTimeTrigger() :
	XFCustomEvent(evTimeTriggerId)
{
	//setDeleteAfterConsume(false);
}
