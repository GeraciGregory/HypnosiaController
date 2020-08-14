#ifndef CLOCK_H_
#define CLOCK_H_

//************************************INCLUDE***************************************
#include "WatchPointer.h"
#include "main.h"
//************************************DEFINE****************************************
#define MAX_WATCHPOINTER 3
//**********************************************************************************
class Clock
{
public:
	Clock();									//Constructor
	~Clock();									//Destructor

	void initialize(bool nbrWatchPtr);			//Initialize the number of used watch pointers

	WatchPointer* getWatchPointer(int index);	//Return the selected watch pointer object
	uint8_t getNbrWatchPointer();				//Return the number of used watch pointers

private:
	WatchPointer* _watchPtr[MAX_WATCHPOINTER];	//Watch pointer array
	uint8_t nbrWatchPointer;					//Number of used watch pointers
};

#endif /* CLOCK_H_ */
