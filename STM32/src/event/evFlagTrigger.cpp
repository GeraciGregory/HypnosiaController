#include "evFlagTrigger.h"

evFlagTrigger::evFlagTrigger() :
	XFCustomEvent(EventsID::evFlagTriggerId)
{
	setDeleteAfterConsume(false);
}

evFlagTrigger::~evFlagTrigger()
{}
