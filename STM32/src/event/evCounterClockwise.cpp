#include "events.h"
#include "evCounterClockwise.h"

evCounterClockwise::evCounterClockwise() :
	XFCustomEvent(evCounterClockwiseId)
{
	//setDeleteAfterConsume(false);
}
