#ifndef CLOCK_H_
#define CLOCK_H_

#include "WatchPointer.h"
#include "main.h"

#define MAX_WATCHPOINTER 3


class Clock
{
public:
	Clock(bool nbrWatchPtr);
	~Clock();

	WatchPointer* getWatchPointer(int index);

	uint8_t getNbrWatchPointer();

private:
	WatchPointer* _watchPtr[MAX_WATCHPOINTER];
	uint8_t nbrWatchPointer;
};

#endif /* CLOCK_H_ */
