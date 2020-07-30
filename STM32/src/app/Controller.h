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
	~Controller();

	void intitialize();
	void start();

	void initializeMotorsGPIO();
	void manageMotors();
	void goToZeroPosition();
	void incrementPosition(bool clockwise, int i, int x);
	bool bestClockwise(int i, int x);

	bool bestClockwiseGoToZero(int i, int x);

	//Singleton
	static Controller* getInstance();

	//Generate events
	void onIrqSPI();
	void onIrqCAN();

	void readDIPSwitch();



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
	Clock* _clock[NBR_CLOCK_PER_PROCESSOR];
	uint8_t buffer_SPI_rx[SPI_FRAME_SIZE];
	uint8_t buffer_CAN_rx[MAX_CAN_BYTES];
	uint8_t test;
	uint32_t TxMailbox;
	uint8_t bufferTest[4] = {0x00, 0x01, 0x02, 0x03};
	bool goToZero;


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
		STATE_WAIT_TRIGGER = 5,
		STATE_GO_TO_ZERO = 6,
		STATE_WAIT_ZERO = 7,
		STATE_LED = 8
	} eMainState;

	eMainState _currentState;		///< Attribute indicating currently active state
	eMainState _oldState;			///< Attribute indicating currently active state
};

#endif /* CONTROLLER_H_ */
