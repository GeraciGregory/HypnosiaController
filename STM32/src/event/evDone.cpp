#include "events.h"
#include "evDone.h"

evDone::evDone() :
	XFCustomEvent(evDoneId)
{
	//setDeleteAfterConsume(false);
}
