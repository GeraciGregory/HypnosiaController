#include "evGoToZero.h"

evGoToZero::evGoToZero() :
	XFCustomEvent(EventsID::evGoToZeroId)
{
	setDeleteAfterConsume(false);
}

evGoToZero::~evGoToZero()
{}
