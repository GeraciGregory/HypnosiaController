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
        evAnim2 = 4,
        evAnim3 = 5,
        evAnim4 = 6,
        evDone = 7,
        evPlus = 8,
        evMinus = 9,
        evRstPos = 10,
        evGoToZero = 11,
        evBluetoothConnected = 12,
        evCalibration = 13
	} eEventId;
};

#endif // EVENTIDS_H
