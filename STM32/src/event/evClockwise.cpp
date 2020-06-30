#include "events.h"
#include "evClockwise.h"

evClockwise::evClockwise() :
	XFCustomEvent(evClockwiseId)
{
	//setDeleteAfterConsume(false);
}
