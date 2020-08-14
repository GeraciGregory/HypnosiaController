#include <app/Controller.h>
#include "Core/Inc/main.h"

//Constructor
Controller::Controller()
{
	//Define first state for the state machine
	_currentState = STATE_INIT;

	//Configure number of biaxes and triaxes used movements
	//0 = biaxe
	//1 = triaxe
	nbrWatchPtrClk = 0b00000000;					//6 biaxes

	//Initialize pointer
	for(int i=0; i<NBR_CLOCK_PER_PROCESSOR; i++)
	{
		_clock[i] = nullptr;
	}
}

//Desctructor
Controller::~Controller()
{
	//Never used
	for(int i=0; i<NBR_CLOCK_PER_PROCESSOR; i++)
	{
		delete _clock[i];
	}
	delete[] _clock;
}

//Singleton pattern
//Return the reference of the singleton
Controller* Controller::getInstance()
{
	static Controller _controller;
	return &_controller;
}


void Controller::intitialize()
{
	//Dynamic allocation
	for(int i=0; i<NBR_CLOCK_PER_PROCESSOR; i++)
	{
		_clock[i] = new Clock();
	}
	initializeMotorsGPIO();
}

void Controller::start()
{
	startBehavior();			//Start behavior of the XF
}

void Controller::onIrqSPI()
{
	pushEvent(&_evSpiIrq);
}
void Controller::onIrqCAN()
{
	//Read data
	HAL_CAN_GetRxMessage(&hcan, CAN_RX_FIFO0, &myRxMessage, buffer_CAN_rx);
	pushEvent(&_evCanIrq);
}

void Controller::readDIPSwitch()
{
	//Read DIP switchs used for the processor address
	// |= <=> XOR
	myAddress |= HAL_GPIO_ReadPin(SW_4_GPIO_Port, SW_4_Pin) << 4;
	myAddress |= HAL_GPIO_ReadPin(SW_3_GPIO_Port, SW_3_Pin) << 3;
	myAddress |= HAL_GPIO_ReadPin(SW_2_GPIO_Port, SW_2_Pin) << 2;
	myAddress |= HAL_GPIO_ReadPin(SW_1_GPIO_Port, SW_1_Pin) << 1;
	myAddress |= HAL_GPIO_ReadPin(SW_0_GPIO_Port, SW_0_Pin) << 0;
}

void Controller::initializeMotorsGPIO()
{
	//False -> 2 watch pointers
	//True -> 3 watch pointers
	_clock[0]->initialize((nbrWatchPtrClk & 0b00000001)); //2
	_clock[1]->initialize((nbrWatchPtrClk & 0b00000010) >> 1); //3
	_clock[2]->initialize((nbrWatchPtrClk & 0b00000100) >> 2); //3
	_clock[3]->initialize((nbrWatchPtrClk & 0b00001000) >> 3); //2
	_clock[4]->initialize((nbrWatchPtrClk & 0b00010000) >> 4); //3
	_clock[5]->initialize((nbrWatchPtrClk & 0b00100000) >> 5); //2



	//Define PIN number --> see schematic, 0..15
	//Motor 1 -> biaxe
	_clock[0]->getWatchPointer(0)->initGPIO(M1_Ah_GPIO_Port, M1_Ah_Pin,
											M1_Bh_GPIO_Port, M1_Bh_Pin,
											M1_Ch_GPIO_Port, M1_Ch_Pin);
	_clock[0]->getWatchPointer(1)->initGPIO(M1_Am_GPIO_Port, M1_Am_Pin,
											M1_Bm_GPIO_Port, M1_Bm_Pin,
											M1_Cm_GPIO_Port, M1_Cm_Pin);
	//Motor 2 -> biaxe
	_clock[1]->getWatchPointer(0)->initGPIO(M2_Ah_GPIO_Port, M2_Ah_Pin,
											M2_Bh_GPIO_Port, M2_Bh_Pin,
											M2_Ch_GPIO_Port, M2_Ch_Pin);
	_clock[1]->getWatchPointer(1)->initGPIO(M2_Am_GPIO_Port, M2_Am_Pin,
											M2_Bm_GPIO_Port, M2_Bm_Pin,
											M2_Cm_GPIO_Port, M2_Cm_Pin);
	//Motor 3 -> biaxe
	_clock[2]->getWatchPointer(0)->initGPIO(M3_Ah_GPIO_Port, M3_Ah_Pin,
											M3_Bh_GPIO_Port, M3_Bh_Pin,
											M3_Ch_GPIO_Port, M3_Ch_Pin);
	_clock[2]->getWatchPointer(1)->initGPIO(M3_Am_GPIO_Port, M3_Am_Pin,
											M3_Bm_GPIO_Port, M3_Bm_Pin,
											M3_Cm_GPIO_Port, M3_Cm_Pin);
	//Motor 4 -> biaxes
	_clock[3]->getWatchPointer(0)->initGPIO(M4_Ah_GPIO_Port, M4_Ah_Pin,
											M4_Bh_GPIO_Port, M4_Bh_Pin,
											M4_Ch_GPIO_Port, M4_Ch_Pin);
	_clock[3]->getWatchPointer(1)->initGPIO(M4_Am_GPIO_Port, M4_Am_Pin,
											M4_Bm_GPIO_Port, M4_Bm_Pin,
											M4_Cm_GPIO_Port, M4_Cm_Pin);
	//Motor 5 -> biaxe
	_clock[4]->getWatchPointer(0)->initGPIO(M5_Ah_GPIO_Port, M5_Ah_Pin,
											M5_Bh_GPIO_Port, M5_Bh_Pin,
											M5_Ch_GPIO_Port, M5_Ch_Pin);
	_clock[4]->getWatchPointer(1)->initGPIO(M5_Am_GPIO_Port, M5_Am_Pin,
											M5_Bm_GPIO_Port, M5_Bm_Pin,
											M5_Cm_GPIO_Port, M5_Cm_Pin);
	//Motor 6 -> biaxes
	_clock[5]->getWatchPointer(0)->initGPIO(M6_Ah_GPIO_Port, M6_Ah_Pin,
											M6_Bh_GPIO_Port, M6_Bh_Pin,
											M6_Ch_GPIO_Port, M6_Ch_Pin);
	_clock[5]->getWatchPointer(1)->initGPIO(M6_Am_GPIO_Port, M6_Am_Pin,
											M6_Bm_GPIO_Port, M6_Bm_Pin,
											M6_Cm_GPIO_Port, M6_Cm_Pin);
}

//Reactive class --> state machine
XFEventStatus Controller::processEvent()
{

	eEventStatus eventStatus = XFEventStatus::Unknown;
	_oldState = _currentState;

	//**********************************************************************************
	//Transition switch
	switch(_currentState)
	{
	case STATE_INIT:
		if (getCurrentEvent()->getEventType() == XFEvent::Initial)
		{
			_currentState = STATE_WAIT;
			eventStatus = XFEventStatus::Consumed;
		}
		break;

	case STATE_WAIT:
		if (getCurrentEvent()->getEventType() == XFEvent::Event &&
				getCurrentEvent()->getId() == EventsID::evNullTransitionId)
		{
			//Consumed event but do nothing
			eventStatus = XFEventStatus::Consumed;
		}
		if (getCurrentEvent()->getEventType() == XFEvent::Event &&
				getCurrentEvent()->getId() == EventsID::evSpiIrqId)
		{
			_currentState = STATE_SPI;
			eventStatus = XFEventStatus::Consumed;
		}
		if (getCurrentEvent()->getEventType() == XFEvent::Event &&
				getCurrentEvent()->getId() == EventsID::evCanIrqId)
		{
			_currentState = STATE_CAN;
			eventStatus = XFEventStatus::Consumed;
		}
		if (getCurrentEvent()->getEventType() == XFEvent::Event &&
				getCurrentEvent()->getId() == EventsID::evFlagTriggerId)
		{
			_currentState = STATE_TRIGGER;
			eventStatus = XFEventStatus::Consumed;
		}
		if (getCurrentEvent()->getEventType() == XFEvent::Event &&
				getCurrentEvent()->getId() == EventsID::evGoToZeroId)
		{
			_currentState = STATE_GO_TO_ZERO;
			eventStatus = XFEventStatus::Consumed;
		}
		break;

	case STATE_SPI:
		if (getCurrentEvent()->getEventType() == XFEvent::Event &&
				getCurrentEvent()->getId() == EventsID::evNullTransitionId)
		{
			_currentState = STATE_WAIT;
			eventStatus = XFEventStatus::Consumed;
		}
		break;

	case STATE_CAN:
		if (getCurrentEvent()->getEventType() == XFEvent::Event &&
				getCurrentEvent()->getId() == EventsID::evNullTransitionId)
		{
			_currentState = STATE_WAIT;
			eventStatus = XFEventStatus::Consumed;
		}
		break;

	case STATE_TRIGGER:
		if (getCurrentEvent()->getEventType() == XFEvent::Event &&
				getCurrentEvent()->getId() == EventsID::evDoneId)
		{
			_currentState = STATE_WAIT;
			eventStatus = XFEventStatus::Consumed;
		}
		break;

	case STATE_GO_TO_ZERO:
		if (getCurrentEvent()->getEventType() == XFEvent::Event &&
				getCurrentEvent()->getId() == EventsID::evDoneId)
		{
			_currentState = STATE_WAIT;
			eventStatus = XFEventStatus::Consumed;
		}
		break;

	default:
		Error_Handler();
		break;
	}
	//**********************************************************************************
	//Action switch
	if(_oldState != _currentState)
	{
		switch(_currentState)
		{
		case STATE_INIT:
			break;

		case STATE_WAIT:
			if(_oldState == STATE_INIT)
			{
				//Do at startup of the system
				HAL_GPIO_WritePin(LED_1_GPIO_Port, LED_1_Pin, GPIO_PIN_RESET);
				readDIPSwitch();
				HAL_SPI_Receive_DMA(&hspi1, buffer_SPI_rx, SPI_FRAME_SIZE);
				pushEvent(&_evNullTranisiton);
			}
			if(_oldState == STATE_SPI)
			{
				HAL_SPI_Receive_DMA(&hspi1, buffer_SPI_rx, SPI_FRAME_SIZE);
			}
			if(_oldState == STATE_CAN)
			{}
			if(_oldState == STATE_TRIGGER)
			{}
			if(_oldState == STATE_GO_TO_ZERO)
			{}
			break;

		case STATE_SPI:
			if(_oldState == STATE_WAIT)
			{
				pushEvent(&_evNullTranisiton);
				SPI_readFrame();
			}
			break;

		case STATE_CAN:
			if(_oldState == STATE_WAIT)
			{
				pushEvent(&_evNullTranisiton);
				CAN_readFrame();
			}
			break;

		case STATE_TRIGGER:
			if(_oldState == STATE_WAIT)
			{
				manageMotors();
			}
			break;

		case STATE_GO_TO_ZERO:
			if(_oldState == STATE_WAIT)
			{
				goToZeroPosition();
			}
			break;

		default:
			Error_Handler();
			break;
		}
	}
	//**********************************************************************************
	return eventStatus;
}

void Controller::goToZeroPosition()
{
	for(uint8_t i=0; i<NBR_CLOCK_PER_PROCESSOR; i++)
	{
		for(uint8_t x=0; x<(MAX_WATCHPOINTER-1); x++)
		{
			//Check best clockwise
			_clock[i]->getWatchPointer(x)->clockwise = bestClockwiseGoToZero(i, x);
			//Move state machine
			_clock[i]->getWatchPointer(x)->onMove();
		}
	}

	//Used to go to the WAIT state
	pushEvent(&_evDone);
}

void Controller::manageMotors()
{
	for(uint8_t i=0; i<NBR_CLOCK_PER_PROCESSOR; i++)
	{
		for(uint8_t x=0; x<(MAX_WATCHPOINTER-1); x++)
		{
			//Check best clockwise
			_clock[i]->getWatchPointer(x)->clockwise = bestClockwise(i,x);
			//Move state machine
			_clock[i]->getWatchPointer(x)->onMove();
		}
	}

	//Used to go to the WAIT state
	pushEvent(&_evDone);
}


//Calculating the best direction to go to the new position
bool Controller::bestClockwise(int i, int x)
{
	bool clockwise;
	uint8_t newPos = _clock[i]->getWatchPointer(x)->newPosition;
	uint8_t actualPos = _clock[i]->getWatchPointer(x)->actualPosition;

	if(newPos > actualPos)
	{
		//New position > actual position
		if((newPos-actualPos) > ((360/_clock[i]->getWatchPointer(x)->outputAngle) / 2))	//Superior at 180°
		{
			clockwise = false;
			_clock[i]->getWatchPointer(x)->nbrStepToDo = (360/_clock[i]->getWatchPointer(x)->outputAngle) -
																(_clock[i]->getWatchPointer(x)->newPosition -
																_clock[i]->getWatchPointer(x)->actualPosition);
		}
		else
		{
			clockwise = true;
			_clock[i]->getWatchPointer(x)->nbrStepToDo = _clock[i]->getWatchPointer(x)->newPosition -
																_clock[i]->getWatchPointer(x)->actualPosition;
		}
	}
	else if (newPos < actualPos)
	{
		//New position < actual position
		if((actualPos-newPos) > ((360/_clock[i]->getWatchPointer(x)->outputAngle) / 2))
		{
			clockwise = true;
			_clock[i]->getWatchPointer(x)->nbrStepToDo = (360/_clock[i]->getWatchPointer(x)->outputAngle) -
																(_clock[i]->getWatchPointer(x)->actualPosition -
																_clock[i]->getWatchPointer(x)->newPosition);
		}
		else
		{
			clockwise = false;
			_clock[i]->getWatchPointer(x)->nbrStepToDo = _clock[i]->getWatchPointer(x)->actualPosition -
																_clock[i]->getWatchPointer(x)->newPosition;
		}
	}
	return clockwise;
}

//Calculating the best direction to go to the zero position
bool Controller::bestClockwiseGoToZero(int i, int x)
{
	bool clockwise;

	uint8_t actualPos = _clock[i]->getWatchPointer(x)->actualPosition;

	if(actualPos > ((360/_clock[i]->getWatchPointer(x)->outputAngle) / 2))	//Superior at 180°
	{
		clockwise = true;
		_clock[i]->getWatchPointer(x)->nbrStepToDo = (360/_clock[i]->getWatchPointer(x)->outputAngle) -
															_clock[i]->getWatchPointer(x)->actualPosition;
	}
	else
	{
		clockwise = false;
		_clock[i]->getWatchPointer(x)->nbrStepToDo = _clock[i]->getWatchPointer(x)->actualPosition;
	}
	return clockwise;
}

void Controller::incrementPosition(bool clockwise, int i, int x)
{
	//Increment position
	if(clockwise == true)
	{
		//Check limit
		if(_clock[i]->getWatchPointer(x)->actualPosition == ((360/_clock[i]->getWatchPointer(x)->outputAngle)-1))
		{
			_clock[i]->getWatchPointer(x)->actualPosition = 0;

		}
		else
		{
			_clock[i]->getWatchPointer(x)->actualPosition++;
		}
	}
	else
	{
		//Check limit
		if(_clock[i]->getWatchPointer(x)->actualPosition == 0)
		{
			_clock[i]->getWatchPointer(x)->actualPosition = ((360/_clock[i]->getWatchPointer(x)->outputAngle)-1);
		}
		else
		{
			_clock[i]->getWatchPointer(x)->actualPosition--;
		}
	}
}

//---------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------SPI------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------
void Controller::SPI_readFrame()
{
	uint8_t frameType;

	//Check frame type
	frameType = (buffer_SPI_rx[0] & 0b11000000) >> 6;

	switch(frameType)
	{
	//DATA FRAME
	case 0:
		SPI_dataFrame();
		break;
	//CONFIGURATION FRAME
	case 1:
		SPI_configurationFrame();
		break;
	//BROADCAST CONFIGURATION FRAME
	case 2:
		SPI_broadcastConfigurationFrame();
		break;
	//RESET POSITION ZERO FRAME
	case 3:
		SPI_resetPositionZeroFrame();
		break;
	default:
		Error_Handler();
		break;
	}
}

void Controller::SPI_dataFrame()
{
	uint8_t readAddress = buffer_SPI_rx[0] & 0b00111111;

	//Check Processor address
	if(readAddress == myAddress)
	{
		SPI_readDataBytes();
	}
	else
	{
		//Send data via CAN
		CAN_writeFrame();
	}
}

void Controller::SPI_configurationFrame()
{
	uint8_t readAddress = buffer_SPI_rx[0] & 0b00111111;

	//Check Processor address
	if(readAddress == myAddress)
	{
		SPI_readConfigBytes();
	}
	else
	{
		//Send data via CAN
		CAN_writeFrame();
	}
}

void Controller::SPI_broadcastConfigurationFrame()
{
	//Write on our variables
	SPI_readConfigBytes();

	//Send via CAN for others
	CAN_writeFrame();
}

void Controller::SPI_resetPositionZeroFrame()
{
	uint8_t readAddress = buffer_SPI_rx[0] & 0b00111111;
	uint8_t clkAddress;
	uint8_t watchPtrAddress;

	//Check Processor address
	if(readAddress == myAddress)
	{
		clkAddress = (buffer_SPI_rx[1] & 0b00011100) >> 2;		//3 bits
		watchPtrAddress = (buffer_SPI_rx[1] & 0b00000011);		//2 bits
		//Reset position zero
		_clock[clkAddress]->getWatchPointer(watchPtrAddress)->newPosition = 0;
		_clock[clkAddress]->getWatchPointer(watchPtrAddress)->actualPosition = 0;
	}
	else
	{
		//Send data via CAN
		CAN_writeFrame();
	}
}

void Controller::SPI_readDataBytes()
{
	uint8_t clkAddr = (buffer_SPI_rx[1] & 0b00011100) >> 2;		//3 bits
	uint8_t watchPtrAddress = (buffer_SPI_rx[1] & 0b00000011);	//2 bits
	uint8_t nbrBytes = buffer_SPI_rx[2];

	//Write on registers
	switch(watchPtrAddress)
	{
	case 0:
		SPI_writeDataRegister_0(clkAddr, nbrBytes);	//Data frame for watch pointer 0
		break;

	case 1:
		SPI_writeDataRegister_1(clkAddr, nbrBytes); //Data frame for watch pointer 1
		break;

	case 2:
		SPI_writeDataRegister_2(clkAddr, nbrBytes); //Data frame for watch pointer 2
		break;

	case 3:
		SPI_writeDataRegister(clkAddr, nbrBytes); 	//Data frame for all watch pointer
		break;

	default:
		Error_Handler();
		break;
	}
}

void Controller::SPI_writeDataRegister(uint8_t clkAddr, uint8_t nbrBytes)
{
	//Data register for all watch pointers
	for(uint8_t i=0; i<nbrBytes; i++)
	{
		switch(i)
		{
		case 0:
			_clock[clkAddr]->getWatchPointer(0)->nbrTurns = buffer_SPI_rx[3] & 0b00000111;
			_clock[clkAddr]->getWatchPointer(0)->clockwise = (buffer_SPI_rx[3] & 0b00001000) >> 3;
			_clock[clkAddr]->getWatchPointer(1)->nbrTurns = (buffer_SPI_rx[3] & 0b01110000) >> 4;
			_clock[clkAddr]->getWatchPointer(1)->clockwise = (buffer_SPI_rx[3] & 0b10000000) >> 7;
			break;
		case 1:
			_clock[clkAddr]->getWatchPointer(0)->newPosition = buffer_SPI_rx[4];
			break;
		case 2:
			_clock[clkAddr]->getWatchPointer(0)->offsetStartTime = buffer_SPI_rx[5] & 0b00001111;
			_clock[clkAddr]->getWatchPointer(0)->movmentDurationTime = (buffer_SPI_rx[5] & 0b11110000) >> 4;
			break;
		case 3:
			_clock[clkAddr]->getWatchPointer(1)->newPosition = buffer_SPI_rx[6];
			break;
		case 4:
			_clock[clkAddr]->getWatchPointer(1)->offsetStartTime = buffer_SPI_rx[7] & 0b00001111;
			_clock[clkAddr]->getWatchPointer(1)->movmentDurationTime = (buffer_SPI_rx[7] & 0b11110000) >> 4;
			break;
		case 5:
			_clock[clkAddr]->getWatchPointer(2)->nbrTurns = buffer_SPI_rx[8] & 0b00000111;
			_clock[clkAddr]->getWatchPointer(2)->clockwise = (buffer_SPI_rx[8] & 0b00001000) >> 3;
			break;
		case 6:
			_clock[clkAddr]->getWatchPointer(2)->newPosition = buffer_SPI_rx[9];
			break;
		case 7:
			_clock[clkAddr]->getWatchPointer(2)->offsetStartTime = buffer_SPI_rx[10] & 0b00001111;
			_clock[clkAddr]->getWatchPointer(2)->movmentDurationTime = (buffer_SPI_rx[10] & 0b11110000) >> 4;
			break;
		default:
			Error_Handler();
			break;
		}
	}
}

void Controller::SPI_writeDataRegister_0(uint8_t clkAddr, uint8_t nbrBytes)
{
	//Data register for watch pointer n°0
	for(uint8_t i=0; i<nbrBytes; i++)
	{
		switch(i)
		{
		case 0:
			_clock[clkAddr]->getWatchPointer(0)->nbrTurns = buffer_SPI_rx[3] & 0b00000111;
			_clock[clkAddr]->getWatchPointer(0)->clockwise = (buffer_SPI_rx[3] & 0b00001000) >> 3;
			break;
		case 1:
			_clock[clkAddr]->getWatchPointer(0)->newPosition = buffer_SPI_rx[4];
			break;
		case 2:
			_clock[clkAddr]->getWatchPointer(0)->offsetStartTime = buffer_SPI_rx[5] & 0b00001111;
			_clock[clkAddr]->getWatchPointer(0)->movmentDurationTime = (buffer_SPI_rx[5] & 0b11110000) >> 4;
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		default:
			Error_Handler();
			break;
		}
	}
}

void Controller::SPI_writeDataRegister_1(uint8_t clkAddr, uint8_t nbrBytes)
{
	//Data register for watch pointer n°1
	for(uint8_t i=0; i<nbrBytes; i++)
	{
		switch(i)
		{
		case 0:
			_clock[clkAddr]->getWatchPointer(1)->nbrTurns = buffer_SPI_rx[3] & 0b00000111;
			_clock[clkAddr]->getWatchPointer(1)->clockwise = (buffer_SPI_rx[3] & 0b00001000) >> 3;
			break;
		case 1:
			_clock[clkAddr]->getWatchPointer(1)->newPosition = buffer_SPI_rx[4];
			break;
		case 2:
			_clock[clkAddr]->getWatchPointer(1)->offsetStartTime = buffer_SPI_rx[5] & 0b00001111;
			_clock[clkAddr]->getWatchPointer(1)->movmentDurationTime = (buffer_SPI_rx[5] & 0b11110000) >> 4;
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		default:
			Error_Handler();
			break;
		}
	}
}

//Data register for watch pointer n°2
//Used only with triaxes movments
void Controller::SPI_writeDataRegister_2(uint8_t clkAddr, uint8_t nbrBytes)
{}

void Controller::SPI_readConfigBytes()
{
	uint8_t nbrBytes = buffer_SPI_rx[1];
	uint8_t indexRegister = buffer_SPI_rx[2];

	//First, read data bytes
	//Then, write on each variables
	for(uint8_t i=indexRegister; i<nbrBytes; i++)
	{
		switch(i)
		{
		case 0:
			statusBytes = buffer_SPI_rx[i+3];
			//Check flags
			if(((statusBytes & 0b00100000) >> 5) == true)
			{
				pushEvent(&_evGoToZero);
			}
			else if(((statusBytes & 0b00010000)>>4) == true)
			{
				pushEvent(&_evFlagTrigger);
			}
			break;
		case 1:
			startTime = buffer_SPI_rx[i+3];
			break;
		case 2:
			stopTime = buffer_SPI_rx[i+3];
			break;
		case 3:
			nbrWatchPtrClk = buffer_SPI_rx[i+3];
			break;
		case 4:
			//Free
			break;
		case 5:
			//Free
			break;
		case 6:
			//Free
			break;
		case 7:
			//Free
			break;
		default:
			Error_Handler();
			break;
		}
	}
}

//---------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------CAN------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------
void Controller::CAN_writeFrame()
{
	uint8_t frameType = (buffer_SPI_rx[0]&0b11000000) >> 6;
	HAL_StatusTypeDef statusCAN;

	myTxMessage.StdId = 0x00;									//Message identifier -> 11 bits identifier (initialized)
	myTxMessage.StdId += (buffer_SPI_rx[0]&0b11000000) << 3;	//2 bits = frame type (bit 10 & bit 9)
	myTxMessage.StdId += (buffer_SPI_rx[0]&0b00001111) << 5;	//4 bits = Processor Address (bit 8 to bit 5)

	//myTxMessage.ExtId = 0x00;									//Used of 29 bits identifier
	myTxMessage.IDE = CAN_ID_STD;								//Used 11 bits identifier
	myTxMessage.RTR = CAN_RTR_DATA;								//DATA frame

	switch(frameType)
	{
	case 0://Data frame
		myTxMessage.StdId += (buffer_SPI_rx[1]&0b00011100);		//3 bits = ClockAddress (bit 5 to bit 2)
		myTxMessage.StdId += (buffer_SPI_rx[1]&0b00000011);		//2 bits = Watch pointer address (bit 1 & bit 0)

		myTxMessage.DLC = buffer_SPI_rx[2];						//Data Length Code
		statusCAN = HAL_CAN_AddTxMessage(&hcan, &myTxMessage, &buffer_SPI_rx[3], &TxMailbox);
		break;
	case 1://Configuration frame
	case 2://Broadcast configuration frame
		myTxMessage.DLC = buffer_SPI_rx[1];						//Data Length Code
		statusCAN = HAL_CAN_AddTxMessage(&hcan, &myTxMessage, &buffer_SPI_rx[2], &TxMailbox);
		break;
	case 3://Reset position frame
		myTxMessage.StdId += (buffer_SPI_rx[1]&0b00011100);		//2 bits = ClockAddress (bit 5 to bit 2)
		myTxMessage.StdId += (buffer_SPI_rx[1]&0b00000011);		//4 bits = Watch pointer address (bit 1 & bit 0)
		myTxMessage.DLC = 0;									//Data Length Code
		statusCAN = HAL_CAN_AddTxMessage(&hcan, &myTxMessage, &buffer_SPI_rx[0], &TxMailbox);
		break;
	default:
		Error_Handler();
		break;
	}

	if( statusCAN != HAL_OK )
	{
		Error_Handler();
	}
}

void Controller::CAN_readFrame()
{
	//Check frame type
	uint8_t frameType = (myRxMessage.StdId & 0b11000000000) >> 9;

	switch(frameType)
	{
	//DATA FRAME
	case 0:
		CAN_dataFrame();
		break;
	//CONFIGURATION FRAME
	case 1:
		CAN_configurationFrame();
		break;
	//BROADCAST CONFIGURATION FRAME
	case 2:
		CAN_broadcastConfigurationFrame();
		break;
	//RESET POSITION ZERO FRAME
	case 3:
		CAN_resetPositionZeroFrame();
		break;
	default:
		Error_Handler();
		break;
	}
}

void Controller::CAN_dataFrame()
{
	uint8_t processorAddress = (myRxMessage.StdId & 0b00111100000) >> 5;

	//Check processor address
	if(processorAddress == myAddress)
	{
		CAN_readDataBytes();
	}
}

void Controller::CAN_configurationFrame()
{
	uint8_t processorAddress = (myRxMessage.StdId & 0b00111100000) >> 5;

	//Check processor address
	if(processorAddress == myAddress)
	{
		CAN_readConfigBytes();
	}
}

void Controller::CAN_broadcastConfigurationFrame()
{
	//Because broadcast, do not check processor address
	CAN_readConfigBytes();
}

void Controller::CAN_resetPositionZeroFrame()
{
	//Get processor address
	uint8_t processorAddress = (myRxMessage.StdId & 0b00111100000) >> 5;

	if(processorAddress == myAddress)
	{
		//Get clock and watch pointer address
		uint8_t clockAddress = (myRxMessage.StdId & 0b00000011100) >> 2;
		uint8_t watchPointerAddress = (myRxMessage.StdId & 0b00000000011);

		//Reset position zero
		_clock[clockAddress]->getWatchPointer(watchPointerAddress)->newPosition = 0;
		_clock[clockAddress]->getWatchPointer(watchPointerAddress)->actualPosition = 0;
	}
}

void Controller::CAN_readDataBytes()
{
	//Get clock and watch pointer address
	uint8_t clkAddr = (myRxMessage.StdId & 0b00000011100) >> 2;	//3 bits
	uint8_t watchPtrAddress = (myRxMessage.StdId & 0b00000011);	//2 bits
	//Get number of bytes to read
	uint8_t nbrBytes = myRxMessage.DLC;

	//First, read data bytes
	//Then, write on each variables
	switch(watchPtrAddress)
	{
	case 0:
		CAN_writeDataRegister_0(clkAddr, nbrBytes);	//Data frame for watch pointer 0
		break;

	case 1:
		CAN_writeDataRegister_1(clkAddr, nbrBytes); //Data frame for watch pointer 1
		break;

	case 2:
		CAN_writeDataRegister_2(clkAddr, nbrBytes); //Data frame for watch pointer 2
		break;

	case 3:
		CAN_writeDataRegister(clkAddr, nbrBytes); //Data frame for all watch pointer
		break;

	default:
		Error_Handler();
		break;
	}
}

void Controller::CAN_writeDataRegister(uint8_t clkAddr, uint8_t nbrBytes)
{
	//Data register for all watch pointers
	for(uint8_t i=0; i<nbrBytes; i++)
	{
		switch(i)
		{
		case 0:
			_clock[clkAddr]->getWatchPointer(0)->nbrTurns = buffer_CAN_rx[0] & 0b00000111;
			_clock[clkAddr]->getWatchPointer(0)->clockwise = (buffer_CAN_rx[0] & 0b00001000) >> 3;
			_clock[clkAddr]->getWatchPointer(1)->nbrTurns = (buffer_CAN_rx[0] & 0b01110000) >> 4;
			_clock[clkAddr]->getWatchPointer(1)->clockwise = (buffer_CAN_rx[0] & 0b10000000) >> 7;
			break;
		case 1:
			_clock[clkAddr]->getWatchPointer(0)->newPosition = buffer_CAN_rx[1];
			break;
		case 2:
			_clock[clkAddr]->getWatchPointer(0)->offsetStartTime = buffer_CAN_rx[2] & 0b00001111;
			_clock[clkAddr]->getWatchPointer(0)->movmentDurationTime = (buffer_CAN_rx[2] & 0b11110000) >> 4;
			break;
		case 3:
			_clock[clkAddr]->getWatchPointer(1)->newPosition = buffer_CAN_rx[3];
			break;
		case 4:
			_clock[clkAddr]->getWatchPointer(1)->offsetStartTime = buffer_CAN_rx[4] & 0b00001111;
			_clock[clkAddr]->getWatchPointer(1)->movmentDurationTime = (buffer_CAN_rx[4] & 0b11110000) >> 4;
			break;
		case 5:
			_clock[clkAddr]->getWatchPointer(2)->nbrTurns = buffer_CAN_rx[5] & 0b00000111;
			_clock[clkAddr]->getWatchPointer(2)->clockwise = (buffer_CAN_rx[5] & 0b00001000) >> 3;
			break;
		case 6:
			_clock[clkAddr]->getWatchPointer(2)->newPosition = buffer_CAN_rx[6];
			break;
		case 7:
			_clock[clkAddr]->getWatchPointer(2)->offsetStartTime = buffer_CAN_rx[7] & 0b00001111;
			_clock[clkAddr]->getWatchPointer(2)->movmentDurationTime = (buffer_CAN_rx[7] & 0b11110000) >> 4;
			break;
		default:
			Error_Handler();
			break;
		}
	}
}

void Controller::CAN_writeDataRegister_0(uint8_t clkAddr, uint8_t nbrBytes)
{
	//Data register for watch pointer n°0
	for(uint8_t i=0; i<nbrBytes; i++)
	{
		switch(i)
		{
		case 0:
			_clock[clkAddr]->getWatchPointer(0)->nbrTurns = buffer_CAN_rx[0] & 0b00000111;
			_clock[clkAddr]->getWatchPointer(0)->clockwise = (buffer_CAN_rx[0] & 0b00001000) >> 3;
			break;
		case 1:
			_clock[clkAddr]->getWatchPointer(0)->newPosition = buffer_CAN_rx[1];
			break;
		case 2:
			_clock[clkAddr]->getWatchPointer(0)->offsetStartTime = buffer_CAN_rx[2] & 0b00001111;
			_clock[clkAddr]->getWatchPointer(0)->movmentDurationTime = (buffer_CAN_rx[2] & 0b11110000) >> 4;
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		default:
			Error_Handler();
			break;
		}
	}
}

void Controller::CAN_writeDataRegister_1(uint8_t clkAddr, uint8_t nbrBytes)
{
	//Data register for watch pointer n°1
	for(uint8_t i=0; i<nbrBytes; i++)
	{
		switch(i)
		{
		case 0:
			_clock[clkAddr]->getWatchPointer(1)->nbrTurns = buffer_CAN_rx[0] & 0b00000111;
			_clock[clkAddr]->getWatchPointer(1)->clockwise = (buffer_CAN_rx[0] & 0b00001000) >> 3;
			break;
		case 1:
			_clock[clkAddr]->getWatchPointer(1)->newPosition = buffer_CAN_rx[1];
			break;
		case 2:
			_clock[clkAddr]->getWatchPointer(1)->offsetStartTime = buffer_CAN_rx[2] & 0b00001111;
			_clock[clkAddr]->getWatchPointer(1)->movmentDurationTime = (buffer_CAN_rx[2] & 0b11110000) >> 4;
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		default:
			Error_Handler();
			break;
		}
	}
}

//Data register for watch pointer n°2
//Used only with triaxes movments
void Controller::CAN_writeDataRegister_2(uint8_t clkAddr, uint8_t nbrBytes)
{}


void Controller::CAN_readConfigBytes()
{
	uint8_t nbrBytes = myRxMessage.DLC;
	uint8_t indexRegister = buffer_CAN_rx[0];

	//First, read data bytes
	//Then, write on each variables
	for(uint8_t i=indexRegister; i<nbrBytes; i++)
	{
		switch(i)
		{
		case 0:
			statusBytes = buffer_CAN_rx[i+1];
			//Check flags
			if(((statusBytes & 0b00100000) >> 5) == true)
			{
				pushEvent(&_evGoToZero);
			}
			else if(((statusBytes & 0b00010000)>>4) == true)
			{
				pushEvent(&_evFlagTrigger);
			}
			break;
		case 1:
			startTime = buffer_CAN_rx[i+1];
			break;
		case 2:
			stopTime = buffer_CAN_rx[i+1];
			break;
		case 3:
			nbrWatchPtrClk = buffer_CAN_rx[i+1];
			break;
		case 4:
			//Free
			break;
		case 5:
			//Free
			break;
		case 6:
			//Free
			break;
		case 7:
			//Free
			break;
		default:
			Error_Handler();
			break;
		}
	}
}
