#include "evTimeTrigger.h"

evTimeTrigger::evTimeTrigger() :
	XFCustomEvent(EventsID::evTimeTriggerId)
{
	//setDeleteAfterConsume(false);
}

evTimeTrigger::~evTimeTrigger()
{}
