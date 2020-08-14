#include "evDone.h"

evDone::evDone() :
	XFCustomEvent(EventsID::evDoneId)
{
	setDeleteAfterConsume(false);
}

evDone::~evDone()
{}
