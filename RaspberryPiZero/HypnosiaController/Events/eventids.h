#ifndef EVENTIDS_H
#define EVENTIDS_H

/**
 * This class is responsible to distribute to every event
 * used in the project a different event id.
 *
 * Only values grater than zero should be used
 *
 */
class EventId
{
public:
	/**
	 * The event identifiers available
	 */
	typedef enum
	{
		Unknown = 0,		///< Unknown event. Must not be used.
        evRestart = 1,		///< Restart event
        evCntDown = 2,
        evAnim1 = 3,
        evDone = 4,
        evPlus = 5,
        evMinus = 6,
        evRstPos = 7
	} eEventId;
};

#endif // EVENTIDS_H
