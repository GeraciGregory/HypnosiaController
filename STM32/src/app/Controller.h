#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "xf/behavior.h"
#include "Clock.h"
#include "main.h"

#define NBR_CLOCK_PER_PROCESSOR 6
#define SPI_FRAME_SIZE			11
#define MAX_CAN_BYTES			8

extern SPI_HandleTypeDef hspi1;
extern CAN_HandleTypeDef hcan;
extern CAN_RxHeaderTypeDef myRxMessage;
extern CAN_TxHeaderTypeDef myTxMessage;

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
	void dataFrameSPI();
	void configurationFrameSPI();
	void broadcastConfigurationFrameSPI();
	void resetPositionZeroFrameSPI();
	void readSPIDataBytes();
	void readSPIConfigBytes();

	//CAN
	void readCANFrame();
	void dataFrameCAN();
	void configurationFrameCAN();
	void broadcastConfigurationFrameCAN();
	void resetPositionZeroFrameCAN();
	void readCANDataBytes();
	void readCANConfigBytes();
	void writeCANFrame();

private:
	Clock* _clock[NBR_CLOCK_PER_PROCESSOR];
	uint8_t buffer_SPI_rx[SPI_FRAME_SIZE];
	uint8_t buffer_CAN_rx[MAX_CAN_BYTES];
	bool test;
	uint32_t TxMailbox;
	uint8_t bufferTest[4] = {0x00, 0x01, 0x02, 0x03};


	//Configuration variables
	uint8_t myAddress;
	uint8_t nbrWatchPtrClk;
	uint8_t statusBytes;
	uint8_t startTime;
	uint8_t stopTime;

	//Used for test
	uint8_t i;

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
