#include "evCanIrq.h"


evCanIrq::evCanIrq() :
	XFCustomEvent(EventsID::evCanIrqId)
{
	setDeleteAfterConsume(false);
}

evCanIrq::~evCanIrq()
{}


