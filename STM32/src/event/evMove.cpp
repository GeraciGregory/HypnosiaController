#include "evMove.h"

evMove::evMove() :
	XFCustomEvent(EventsID::evMoveId)
{
	setDeleteAfterConsume(false);
}

evMove::~evMove()
{}



