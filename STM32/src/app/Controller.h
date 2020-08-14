#ifndef CONTROLLER_H_
#define CONTROLLER_H_

//************************************INCLUDE***************************************
#include "xf/behavior.h"
#include "Clock.h"
#include "main.h"
//Used events
#include "event/evSpiIrq.h"
#include "event/evCanIrq.h"
#include "event/evFlagTrigger.h"
#include "event/evTimeTrigger.h"
#include "event/evDone.h"
#include "event/evGoToZero.h"
#include "event/evNullTransition.h"
//************************************DEFINE****************************************
#define NBR_CLOCK_PER_PROCESSOR 6
#define SPI_FRAME_SIZE			11
#define MAX_CAN_BYTES			8
//************************************EXTERN****************************************
//Declared in the class "main.c"
extern SPI_HandleTypeDef hspi1;
extern CAN_HandleTypeDef hcan;
extern CAN_RxHeaderTypeDef myRxMessage;
extern CAN_TxHeaderTypeDef myTxMessage;
//**********************************************************************************
class Controller : public XFBehavior
{
public:
	Controller();												//Constructor
	~Controller();												//Desctructor

	void intitialize();											//Initialize system
	void start();												//Start behavior of the system
	void readDIPSwitch();										//Used at startup to set the processor address

	void initializeMotorsGPIO();								//Initialize PIN used to control movements
	void manageMotors();										//Go to the new position
	void goToZeroPosition();									//Go to the zero position
	void incrementPosition(bool clockwise, int i, int x);		//Increment position
	bool bestClockwise(int i, int x);							//Calculating the best direction to go to the new position
	bool bestClockwiseGoToZero(int i, int x);					//Calculating the best direction to go to the zero position

	static Controller* getInstance();							//Singleton

	//Generate events
	void onIrqSPI();											//Called when an SPI interruption has occurred
	void onIrqCAN();											//Called when an CAN interruption has occurred

	//Static events
	evSpiIrq _evSpiIrq;
	evCanIrq _evCanIrq;
	evFlagTrigger _evFlagTrigger;
	evGoToZero _evGoToZero;
	evDone _evDone;
	evNullTransition _evNullTranisiton;
	//---------------------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------SPI------------------------------------------------------
	//---------------------------------------------------------------------------------------------------------------------
	//Read SPI frame
	void SPI_readFrame();

	//Frame type
	void SPI_dataFrame();
	void SPI_configurationFrame();
	void SPI_broadcastConfigurationFrame();
	void SPI_resetPositionZeroFrame();

	//Two types of frame -> data frame or configuration frame
	void SPI_readDataBytes();
	void SPI_readConfigBytes();

	//Write on registers
	void SPI_writeDataRegister(uint8_t clkAddr, uint8_t nbrBytes);
	void SPI_writeDataRegister_0(uint8_t clkAddr, uint8_t nbrBytes);
	void SPI_writeDataRegister_1(uint8_t clkAddr, uint8_t nbrBytes);
	void SPI_writeDataRegister_2(uint8_t clkAddr, uint8_t nbrBytes);
	//---------------------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------CAN------------------------------------------------------
	//---------------------------------------------------------------------------------------------------------------------
	//Read CAN frame
	void CAN_readFrame();

	//Write CAN frame
	void CAN_writeFrame();

	//Frame type
	void CAN_dataFrame();
	void CAN_configurationFrame();
	void CAN_broadcastConfigurationFrame();
	void CAN_resetPositionZeroFrame();

	//Two types of frame -> data frame or configuration frame
	void CAN_readDataBytes();
	void CAN_readConfigBytes();

	//Write on registers
	void CAN_writeDataRegister(uint8_t clkAddr, uint8_t nbrBytes);
	void CAN_writeDataRegister_0(uint8_t clkAddr, uint8_t nbrBytes);
	void CAN_writeDataRegister_1(uint8_t clkAddr, uint8_t nbrBytes);
	void CAN_writeDataRegister_2(uint8_t clkAddr, uint8_t nbrBytes);
	//---------------------------------------------------------------------------------------------------------------------

private:
	Clock* _clock[NBR_CLOCK_PER_PROCESSOR];			//Clock array

	uint8_t buffer_SPI_rx[SPI_FRAME_SIZE];			//Used to receive data via SPI

	uint8_t buffer_CAN_rx[MAX_CAN_BYTES];			//Used to receive data via CAN
	uint32_t TxMailbox;								//Used to send data via CAN

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
		STATE_GO_TO_ZERO = 6,
	} eMainState;

	eMainState _currentState;		///< Attribute indicating currently active state
	eMainState _oldState;			///< Attribute indicating currently active state
};

#endif /* CONTROLLER_H_ */
