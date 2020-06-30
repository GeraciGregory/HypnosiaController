#include <app/Clock.h>

Clock::Clock(bool nbrWatchPtr)
{
	for(uint8_t i=0; i<MAX_WATCHPOINTER; i++)
	{
		_watchPtr[i] = new WatchPointer();
	}

	//False -> 2 watch pointers
	//True -> 3 watch pointers
	if(nbrWatchPtr == false)
	{
		delete _watchPtr[2];
	}
}

Clock::~Clock()
{}

WatchPointer* Clock::getWatchPointer(int index)
{
	return _watchPtr[index];
}
