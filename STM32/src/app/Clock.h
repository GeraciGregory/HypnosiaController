#ifndef CLOCK_H_
#define CLOCK_H_

#include "WatchPointer.h"

#define MAX_WATCHPOINTER 3


class Clock
{
public:
	Clock(bool nbrWatchPtr);
	virtual ~Clock();

	WatchPointer* getWatchPointer(int index);

private:
	WatchPointer* _watchPtr[MAX_WATCHPOINTER];
};

#endif /* CLOCK_H_ */
