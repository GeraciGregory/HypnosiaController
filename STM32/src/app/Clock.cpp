#include <app/Clock.h>

Clock::Clock(bool nbrWatchPtr)
{
	//False -> 2 watch pointers
	//True -> 3 watch pointers
	if(nbrWatchPtr == false)
	{
		_watchPtr[0] = new WatchPointer(3);	//3° output angle
		_watchPtr[1] = new WatchPointer(2);	//2° output angle
		nbrWatchPointer = 2;
	}
	else
	{
		_watchPtr[0] = new WatchPointer(2);	//2° output angle
		_watchPtr[1] = new WatchPointer(2);	//2° output angle
		_watchPtr[2] = new WatchPointer(6);	//6° output angle
		nbrWatchPointer = 3;
	}
}

Clock::~Clock()
{
	for(int i=0; i<MAX_WATCHPOINTER; i++)
	{
		delete _watchPtr[i];
	}
	delete[] _watchPtr;
}

WatchPointer* Clock::getWatchPointer(int index)
{
	if(index < nbrWatchPointer)
	{
		return _watchPtr[index];
	}
	else
	{
		Error_Handler();
		return 0;
	}
}

uint8_t Clock::getNbrWatchPointer()
{
	return nbrWatchPointer;
}
