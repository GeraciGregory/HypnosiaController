#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "xf/behavior.h"
#include "Clock.h"
#include "main.h"

#define NBR_CLOCK_PER_PROCESSOR 6
#define SPI_FRAME_SIZE			11

extern SPI_HandleTypeDef hspi1;

class Controller : public XFBehavior
{
public:
	Controller();
	virtual ~Controller();

	void intitialize();
	void start();

	void initializeMotorsGPIO();

	//Singleton
	static Controller* getInstance();

	void onIrqSPI();
	void onIrqCAN();

	void readDIPSwitch();

	//SPI
	void readSPIFrame();
	void dataFrame();
	void configurationFrame();
	void broadcastConfigurationFrame();
	void resetPositionZeroFrame();
	void readSPIDataBytes(int clkAddr, int nbrBytes);
	void readSPIConfigBytes(int nbrBytes);

	//CAN
	void readCANFrame();
	void writeCANFrame();

private:
	Clock* _clock[NBR_CLOCK_PER_PROCESSOR];
	uint8_t buffer_SPI_rx[SPI_FRAME_SIZE];
	bool test;

	//Configuration variables
	uint8_t myAddress;
	uint8_t nbrWatchPtrClk;
	uint8_t statusBytes;
	uint8_t startTime;
	uint8_t stopTime;

protected:
	virtual XFEventStatus processEvent();

protected:
	/**
	 * Timeout identifier(s) for this state machine
	 */
	typedef enum
	{
		Timeout = 1
	} eTimeoutId;

	/**
	 * Enumeration used to have a unique identifier for every
	 * state in the state machine.
	 */
	typedef enum
	{
		STATE_INIT = 0,
		STATE_WAIT = 1,
		STATE_SPI = 2,
		STATE_CAN = 3,
		STATE_TRIGGER = 4,
		STATE_LED = 5
	} eMainState;

	eMainState _currentState;		///< Attribute indicating currently active state
	eMainState _oldState;			///< Attribute indicating currently active state
};

#endif /* CONTROLLER_H_ */
