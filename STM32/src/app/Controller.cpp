#include <app/Controller.h>
#include "event/evSpiIrq.h"
#include "event/evCanIrq.h"
#include "event/evFlagTrigger.h"
#include "event/evTimeTrigger.h"
#include "Core/Inc/main.h"

Controller::Controller()
{
	_currentState = STATE_INIT;

	test = true;

	//ONLY FOR TEST
	nbrWatchPtrClk = 0b00010110;
}

Controller::~Controller()
{}

//Singleton pattern
//Return the reference of the singleton
Controller* Controller::getInstance()
{
	static Controller _controller;
	return &_controller;
}

void Controller::intitialize()
{
}

void Controller::start()
{
	startBehavior();
}

void Controller::onIrqSPI()
{
	GEN(evSpiIrq());
}

void Controller::onIrqCAN()
{
	HAL_CAN_GetRxMessage(&hcan, CAN_RX_FIFO0, &myRxMessage, buffer_CAN_rx);
	GEN(evCanIrq());
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
	_clock[0] = new Clock((nbrWatchPtrClk & 0b00000001)); //2
	_clock[1] = new Clock((nbrWatchPtrClk & 0b00000010) >> 1); //3
	_clock[2] = new Clock((nbrWatchPtrClk & 0b00000100) >> 2); //3
	_clock[3] = new Clock((nbrWatchPtrClk & 0b00001000) >> 3); //2
	_clock[4] = new Clock((nbrWatchPtrClk & 0b00010000) >> 4); //3
	_clock[5] = new Clock((nbrWatchPtrClk & 0b00100000) >> 5); //2

	//Pin nbr --> see schematic, 0..15
	//Motor 1 -> biaxes
	_clock[0]->getWatchPointer(0)->initGPIO(M1_Ah_GPIO_Port, M1_Ah_Pin,
											M1_Bh_GPIO_Port, M1_Bh_Pin,
											M1_Ch_GPIO_Port, M1_Ch_Pin);
	_clock[0]->getWatchPointer(1)->initGPIO(M1_Am_GPIO_Port, M1_Am_Pin,
											M1_Bm_GPIO_Port, M1_Bm_Pin,
											M1_Cm_GPIO_Port, M1_Cm_Pin);
	//Motor 2 -> triaxes
	_clock[1]->getWatchPointer(0)->initGPIO(M2_Ah_GPIO_Port, M2_Ah_Pin,
											M2_Bh_GPIO_Port, M2_Bh_Pin,
											M2_Ch_GPIO_Port, M2_Ch_Pin);
	_clock[1]->getWatchPointer(1)->initGPIO(M2_Am_GPIO_Port, M2_Am_Pin,
											M2_Bm_GPIO_Port, M2_Bm_Pin,
											M2_Cm_GPIO_Port, M2_Cm_Pin);
	_clock[1]->getWatchPointer(2)->initGPIO(M2_As_GPIO_Port, M2_As_Pin,
											M2_Bs_GPIO_Port, M2_Bs_Pin,
											M2_Cs_GPIO_Port, M2_Cs_Pin);

	//Motor 3 -> triaxes
	_clock[2]->getWatchPointer(0)->initGPIO(M3_Ah_GPIO_Port, M3_Ah_Pin,
											M3_Bh_GPIO_Port, M3_Bh_Pin,
											M3_Ch_GPIO_Port, M3_Ch_Pin);
	_clock[2]->getWatchPointer(1)->initGPIO(M3_Am_GPIO_Port, M3_Am_Pin,
											M3_Bm_GPIO_Port, M3_Bm_Pin,
											M3_Cm_GPIO_Port, M3_Cm_Pin);
	_clock[2]->getWatchPointer(2)->initGPIO(M3_As_GPIO_Port, M3_As_Pin,
											M3_Bs_GPIO_Port, M3_Bs_Pin,
											M3_Cs_GPIO_Port, M3_Cs_Pin);

	//Motor 4 -> biaxes
	_clock[3]->getWatchPointer(0)->initGPIO(M4_Ah_GPIO_Port, M4_Ah_Pin,
											M4_Bh_GPIO_Port, M4_Bh_Pin,
											M4_Ch_GPIO_Port, M4_Ch_Pin);
	_clock[3]->getWatchPointer(1)->initGPIO(M4_Am_GPIO_Port, M4_Am_Pin,
											M4_Bm_GPIO_Port, M4_Bm_Pin,
											M4_Cm_GPIO_Port, M4_Cm_Pin);

	//Motor 5 -> triaxes
	_clock[4]->getWatchPointer(0)->initGPIO(M5_Ah_GPIO_Port, M5_Ah_Pin,
											M5_Bh_GPIO_Port, M5_Bh_Pin,
											M5_Ch_GPIO_Port, M5_Ch_Pin);
	_clock[4]->getWatchPointer(1)->initGPIO(M5_Am_GPIO_Port, M5_Am_Pin,
											M5_Bm_GPIO_Port, M5_Bm_Pin,
											M5_Cm_GPIO_Port, M5_Cm_Pin);
	_clock[4]->getWatchPointer(2)->initGPIO(M5_As_GPIO_Port, M5_As_Pin,
											M5_Bs_GPIO_Port, M5_Bs_Pin,
											M5_Cs_GPIO_Port, M5_Cs_Pin);

	//Motor 6 -> biaxes
	_clock[5]->getWatchPointer(0)->initGPIO(M6_Ah_GPIO_Port, M6_Ah_Pin,
											M6_Bh_GPIO_Port, M6_Bh_Pin,
											M6_Ch_GPIO_Port, M6_Ch_Pin);
	_clock[5]->getWatchPointer(1)->initGPIO(M6_Am_GPIO_Port, M6_Am_Pin,
											M6_Bm_GPIO_Port, M6_Bm_Pin,
											M6_Cm_GPIO_Port, M6_Cm_Pin);
}

XFEventStatus Controller::processEvent()
{

	eEventStatus eventStatus = XFEventStatus::Unknown;
	_oldState = _currentState;


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
		if (getCurrentEvent()->getEventType() == XFEvent::NullTransition)
		{
			//_currentState = STATE_TRIGGER;
			eventStatus = XFEventStatus::Consumed;
		}

		if (getCurrentEvent()->getEventType() == XFEvent::Event &&
				getCurrentEvent()->getId() == EventIds::evSpiIrqId)
		{
			_currentState = STATE_SPI;
			eventStatus = XFEventStatus::Consumed;
		}
		if (getCurrentEvent()->getEventType() == XFEvent::Event &&
				getCurrentEvent()->getId() == EventIds::evCanIrqId)
		{
			_currentState = STATE_CAN;
			eventStatus = XFEventStatus::Consumed;
		}
		if (getCurrentEvent()->getEventType() == XFEvent::Event &&
				getCurrentEvent()->getId() == EventIds::evFlagTriggerId)
		{
			_currentState = STATE_TRIGGER;
			eventStatus = XFEventStatus::Consumed;
		}
		break;

	case STATE_SPI:
		if (getCurrentEvent()->getEventType() == XFEvent::NullTransition)
		{
			_currentState = STATE_WAIT;
			eventStatus = XFEventStatus::Consumed;
		}
		break;

	case STATE_CAN:
		if (getCurrentEvent()->getEventType() == XFEvent::NullTransition)
		{
			_currentState = STATE_WAIT;
			eventStatus = XFEventStatus::Consumed;
		}
		break;

	case STATE_TRIGGER:
		if (getCurrentEvent()->getEventType() == XFEvent::Timeout &&
				getCurrentTimeout()->getId() == Timeout)
		{
			_currentState = STATE_WAIT;
			eventStatus = XFEventStatus::Consumed;
		}
		if (getCurrentEvent()->getEventType() == XFEvent::NullTransition)
		{
			_currentState = STATE_WAIT;
			eventStatus = XFEventStatus::Consumed;
		}
		break;

	case STATE_LED:
		if (getCurrentEvent()->getEventType() == XFEvent::Timeout &&
				getCurrentTimeout()->getId() == Timeout)
		{
			_currentState = STATE_WAIT;
			eventStatus = XFEventStatus::Consumed;
		}
		break;

	default:
		Error_Handler();
		break;
	}
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
				readDIPSwitch();
				initializeMotorsGPIO();
				HAL_SPI_Receive_DMA(&hspi1, buffer_SPI_rx, SPI_FRAME_SIZE);
				GEN(XFNullTransition());
			}
			if(_oldState == STATE_SPI)
			{
				HAL_SPI_Receive_DMA(&hspi1, buffer_SPI_rx, SPI_FRAME_SIZE);
			}
			if(_oldState == STATE_CAN)
			{

			}
			if(_oldState == STATE_LED)
			{
				GEN(XFNullTransition());
			}
			if(_oldState == STATE_TRIGGER)
			{
				GEN(XFNullTransition());
			}
			break;

		case STATE_SPI:
			if(_oldState == STATE_WAIT)
			{
				GEN(XFNullTransition());
				readSPIFrame();
			}
			break;

		case STATE_CAN:
			if(_oldState == STATE_WAIT)
			{
				GEN(XFNullTransition());
				readCANFrame();
			}
			break;

		case STATE_TRIGGER:
			if(_oldState == STATE_WAIT)
			{
				_clock[0]->getWatchPointer(0)->doOneStep(true);
				_clock[0]->getWatchPointer(1)->doOneStep(true);
				_clock[1]->getWatchPointer(0)->doOneStep(true);
				_clock[1]->getWatchPointer(1)->doOneStep(true);
				_clock[2]->getWatchPointer(0)->doOneStep(true);
				_clock[2]->getWatchPointer(1)->doOneStep(true);
				_clock[3]->getWatchPointer(0)->doOneStep(true);
				_clock[3]->getWatchPointer(1)->doOneStep(true);
				_clock[4]->getWatchPointer(0)->doOneStep(true);
				_clock[4]->getWatchPointer(1)->doOneStep(true);
				_clock[5]->getWatchPointer(0)->doOneStep(true);
				_clock[5]->getWatchPointer(1)->doOneStep(true);

				GEN(XFNullTransition());
				//scheduleTimeout(Timeout, 10);
			}
			break;

		case STATE_LED:
			if(_oldState == STATE_WAIT)
			{
				if(HAL_GPIO_ReadPin(SW_0_GPIO_Port, SW_0_Pin) == GPIO_PIN_RESET)
				{
					HAL_GPIO_WritePin(LED_1_GPIO_Port, LED_1_Pin, GPIO_PIN_RESET);
				}
				else
				{
					HAL_GPIO_WritePin(LED_1_GPIO_Port, LED_1_Pin, GPIO_PIN_SET);
				}
				HAL_GPIO_TogglePin(LED_2_GPIO_Port, LED_2_Pin);
				HAL_GPIO_TogglePin(LED_3_GPIO_Port, LED_3_Pin);
				HAL_GPIO_TogglePin(LED_4_GPIO_Port, LED_4_Pin);
				HAL_GPIO_TogglePin(LED_5_GPIO_Port, LED_5_Pin);
				HAL_GPIO_TogglePin(LED_6_GPIO_Port, LED_6_Pin);

				scheduleTimeout(Timeout, 5000);	//5000 = 500ms
				//GEN(XFNullTransition());
			}
			break;
		default:
			Error_Handler();
			break;
		}
	}
	return eventStatus;
}

//---------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------SPI------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------
void Controller::readSPIFrame()
{
	uint8_t frameType;

	//Check frame type
	frameType = (buffer_SPI_rx[0] & 0b11000000) >> 6;

	switch(frameType)
	{
	//DATA FRAME
	case 0:
		dataFrameSPI();
		break;
	//CONFIGURATION FRAME
	case 1:
		configurationFrameSPI();
		break;
	//BROADCAST CONFIGURATION FRAME
	case 2:
		broadcastConfigurationFrameSPI();
		break;
	//RESET POSITION ZERO FRAME
	case 3:
		resetPositionZeroFrameSPI();
		break;
	default:
		Error_Handler();
		break;
	}
}

void Controller::dataFrameSPI()
{
	uint8_t readAddress = buffer_SPI_rx[0] & 0b00111111;

	//Check Processor address
	if(readAddress == myAddress)
	{
		readSPIDataBytes();
	}
	else
	{
		//Send data via CAN
		writeCANFrame();
	}
}

void Controller::configurationFrameSPI()
{
	uint8_t readAddress = buffer_SPI_rx[0] & 0b00111111;

	//Check Processor address
	if(readAddress == myAddress)
	{
		readSPIConfigBytes();
	}
	else
	{
		//Send data via CAN
		writeCANFrame();
	}
}

void Controller::broadcastConfigurationFrameSPI()
{

	//Write on our variables
	readSPIConfigBytes();

	//Send via CAN for others
	writeCANFrame();

}

void Controller::resetPositionZeroFrameSPI()
{
	uint8_t readAddress = buffer_SPI_rx[0] & 0b00111111;
	uint8_t clkAddress;
	uint8_t watchPtrAddress;

	//Check Processor address
	if(readAddress == myAddress)
	{
		clkAddress = (buffer_SPI_rx[1] & 0b00011100) >> 2;	//3 bits
		watchPtrAddress = (buffer_SPI_rx[1] & 0b00000011);	//2 bits
		//Reset position zero
		_clock[clkAddress]->getWatchPointer(watchPtrAddress)->position = 0;
	}
	else
	{
		//Send data via CAN
		writeCANFrame();
	}
}

void Controller::readSPIDataBytes()
{
	uint8_t clkAddr = (buffer_SPI_rx[1] & 0b00011100) >> 2;	//3 bits
	//uint8_t watchPtrAddress = (buffer_SPI_rx[1] & 0b00000011);	//2 bits
	uint8_t nbrBytes = buffer_SPI_rx[2];

	//First, read data bytes
	//Then, write on each variables
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
			_clock[clkAddr]->getWatchPointer(0)->position = buffer_SPI_rx[4];
			break;
		case 2:
			_clock[clkAddr]->getWatchPointer(0)->offsetStartTime = buffer_SPI_rx[5] & 0b00001111;
			_clock[clkAddr]->getWatchPointer(0)->movmentDurationTime = (buffer_SPI_rx[5] & 0b11110000) >> 4;
			break;
		case 3:
			_clock[clkAddr]->getWatchPointer(1)->position = buffer_SPI_rx[6];
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
			_clock[clkAddr]->getWatchPointer(2)->position = buffer_SPI_rx[9];
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

void Controller::readSPIConfigBytes()
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
			if(((statusBytes & 0b00010000)>>4) == true)
			{
				GEN(evFlagTrigger());	//FLAG TRIGGER
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
void Controller::writeCANFrame()
{
	uint8_t frameType = (buffer_SPI_rx[0]&0b11000000) >> 6;
	HAL_StatusTypeDef statusCAN;

	myTxMessage.StdId = 0x00;								//Message identifier -> 11 bits identifier (initialized)
	myTxMessage.StdId += (buffer_SPI_rx[0]&0b11000000) << 3;	//2 bits = frame type (bit 10 & bit 9)
	myTxMessage.StdId += (buffer_SPI_rx[0]&0b00001111) << 5;	//4 bits = Processor Address (bit 8 to bit 5)

	//myTxMessage.ExtId = 0x00;							//Used of 29 bits identifier
	myTxMessage.IDE = CAN_ID_STD;						//Used 11 bits identifier
	myTxMessage.RTR = CAN_RTR_DATA;						//DATA frame

	switch(frameType)
	{
	case 0://Data frame
		myTxMessage.StdId += (buffer_SPI_rx[1]&0b00011100);		//2 bits = ClockAddress (bit 5 to bit 2)
		myTxMessage.StdId += (buffer_SPI_rx[1]&0b00000011);		//4 bits = Watch pointer address (bit 1 & bit 0)

		myTxMessage.DLC = buffer_SPI_rx[2];				//Data Length Code (+1 for clock address
		statusCAN = HAL_CAN_AddTxMessage(&hcan, &myTxMessage, &buffer_SPI_rx[3], &TxMailbox);
		break;
	case 1://Configuration frame
	case 2://Broadcast configuration frame
		myTxMessage.DLC = buffer_SPI_rx[1];				//Data Length Code
		statusCAN = HAL_CAN_AddTxMessage(&hcan, &myTxMessage, &buffer_SPI_rx[2], &TxMailbox);
		break;
	case 3://Reset position frame
		myTxMessage.StdId += (buffer_SPI_rx[1]&0b00011100);		//2 bits = ClockAddress (bit 5 to bit 2)
		myTxMessage.StdId += (buffer_SPI_rx[1]&0b00000011);		//4 bits = Watch pointer address (bit 1 & bit 0)
		myTxMessage.DLC = 0;							//Data Length Code
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


void Controller::readCANFrame()
{
	uint8_t frameType = (myRxMessage.StdId & 0b11000000000) >> 9;
	//uint8_t processorAddress = (myRxMessage.StdId & 0b00111100000) >> 5;
	//uint8_t clockAddress = (myRxMessage.StdId & 0b00000011100) >> 2;
	//uint8_t watchPointerAddress = (myRxMessage.StdId & 0b00000000011);

	switch(frameType)
	{
	case 0:
		dataFrameCAN();
		break;
	case 1:
		configurationFrameCAN();
		break;
	case 2:
		broadcastConfigurationFrameCAN();
		break;
	case 3:
		resetPositionZeroFrameCAN();
		break;
	default:
		Error_Handler();
		break;
	}
}

void Controller::dataFrameCAN()
{
	uint8_t processorAddress = (myRxMessage.StdId & 0b00111100000) >> 5;

	if(processorAddress == myAddress)
	{
		readCANDataBytes();
	}
}

void Controller::configurationFrameCAN()
{
	uint8_t processorAddress = (myRxMessage.StdId & 0b00111100000) >> 5;

	if(processorAddress == myAddress)
	{
		readCANConfigBytes();
	}
}

void Controller::broadcastConfigurationFrameCAN()
{
	//Because broadcast
	readCANConfigBytes();
}

void Controller::resetPositionZeroFrameCAN()
{
	uint8_t processorAddress = (myRxMessage.StdId & 0b00111100000) >> 5;

	if(processorAddress == myAddress)
	{
		uint8_t clockAddress = (myRxMessage.StdId & 0b00000011100) >> 2;
		uint8_t watchPointerAddress = (myRxMessage.StdId & 0b00000000011);
		//Reset position zero
		_clock[clockAddress]->getWatchPointer(watchPointerAddress)->position = 0;
	}
}

void Controller::readCANDataBytes()
{
	uint8_t clkAddr = (myRxMessage.StdId & 0b00000011100) >> 2;	//3 bits
	//uint8_t watchPtrAddress = (buffer_SPI_rx[1] & 0b00000011);	//2 bits
	uint8_t nbrBytes = myRxMessage.DLC;

	//First, read data bytes
	//Then, write on each variables
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
			_clock[clkAddr]->getWatchPointer(0)->position = buffer_CAN_rx[1];
			break;
		case 2:
			_clock[clkAddr]->getWatchPointer(0)->offsetStartTime = buffer_CAN_rx[2] & 0b00001111;
			_clock[clkAddr]->getWatchPointer(0)->movmentDurationTime = (buffer_CAN_rx[2] & 0b11110000) >> 4;
			break;
		case 3:
			_clock[clkAddr]->getWatchPointer(1)->position = buffer_CAN_rx[3];
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
			_clock[clkAddr]->getWatchPointer(2)->position = buffer_CAN_rx[6];
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

void Controller::readCANConfigBytes()
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
			if(((statusBytes & 0b00010000)>>4) == true)
			{
				GEN(evFlagTrigger());	//FLAG TRIGGER
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
