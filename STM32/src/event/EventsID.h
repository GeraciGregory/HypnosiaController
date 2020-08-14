#ifndef EVENTSID_H_
#define EVENTSID_H_

//Customized events ID
class EventsID
{
public:
	typedef enum
	{
		evSpiIrqId = 1,
		evCanIrqId = 2,
		evClockwiseId = 3,
		evCounterClockwiseId = 4,
		evFlagTriggerId = 5,
		evTimeTriggerId = 6,
		evDoneId = 7,
		evGoToZeroId = 8,
		evStepDoneId = 9,
		evMoveId = 10,
		evNullTransitionId = 11
	} eEventsID;
};

#endif /* EVENTSID_H_ */
