#ifndef EVENTS_H
#define EVENTS_H

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
	evStepDoneId = 9
} EventIds;

#endif // EVENTS_H
