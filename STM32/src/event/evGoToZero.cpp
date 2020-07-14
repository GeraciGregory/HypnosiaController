/*
 * evGoToZero.cpp
 *
 *  Created on: Jul 7, 2020
 *      Author: gerac
 */

#include "events.h"
#include "evGoToZero.h"

evGoToZero::evGoToZero() :
	XFCustomEvent(evGoToZeroId)
{
	//setDeleteAfterConsume(false);
}
