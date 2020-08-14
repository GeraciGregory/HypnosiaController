#include "evNullTransition.h"

evNullTransition::evNullTransition() :
	XFCustomEvent(EventsID::evNullTransitionId)
{
	setDeleteAfterConsume(false);
}

evNullTransition::~evNullTransition()
{}

