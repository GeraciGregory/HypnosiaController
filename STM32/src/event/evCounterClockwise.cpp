#include "evCounterClockwise.h"

evCounterClockwise::evCounterClockwise() :
	XFCustomEvent(EventsID::evCounterClockwiseId)
{
	//setDeleteAfterConsume(false);
}

evCounterClockwise::~evCounterClockwise()
{}
