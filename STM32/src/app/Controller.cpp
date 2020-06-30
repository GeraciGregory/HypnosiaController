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
	_clock[0]->getWatchPointer(0)->initGPIO(M1_Ah_GPIO_Port, M1_Ah_Pin, 9,
											M1_Bh_GPIO_Port, M1_Bh_Pin, 10,
											M1_Ch_GPIO_Port, M1_Ch_Pin);
	_clock[0]->getWatchPointer(1)->initGPIO(M1_Am_GPIO_Port, M1_Am_Pin, 14,
											M1_Bm_GPIO_Port, M1_Bm_Pin, 15,
											M1_Cm_GPIO_Port, M1_Cm_Pin);
	//Motor 2 -> triaxes
	_clock[1]->getWatchPointer(0)->initGPIO(M2_Ah_GPIO_Port, M2_Ah_Pin, 15,
											M2_Bh_GPIO_Port, M2_Bh_Pin, 6,
											M2_Ch_GPIO_Port, M2_Ch_Pin);
	_clock[1]->getWatchPointer(1)->initGPIO(M2_Am_GPIO_Port, M2_Am_Pin, 8,
											M2_Bm_GPIO_Port, M2_Bm_Pin, 9,
											M2_Cm_GPIO_Port, M2_Cm_Pin);
	_clock[1]->getWatchPointer(2)->initGPIO(M2_As_GPIO_Port, M2_As_Pin, 12,
											M2_Bs_GPIO_Port, M2_Bs_Pin, 13,
											M2_Cs_GPIO_Port, M2_Cs_Pin);

	//Motor 3 -> triaxes
	_clock[2]->getWatchPointer(0)->initGPIO(M3_Ah_GPIO_Port, M3_Ah_Pin, 11,
											M3_Bh_GPIO_Port, M3_Bh_Pin, 12,
											M3_Ch_GPIO_Port, M3_Ch_Pin);
	_clock[2]->getWatchPointer(1)->initGPIO(M3_Am_GPIO_Port, M3_Am_Pin, 1,
											M3_Bm_GPIO_Port, M3_Bm_Pin, 2,
											M3_Cm_GPIO_Port, M3_Cm_Pin);
	_clock[2]->getWatchPointer(2)->initGPIO(M3_As_GPIO_Port, M3_As_Pin, 6,
											M3_Bs_GPIO_Port, M3_Bs_Pin, 15,
											M3_Cs_GPIO_Port, M3_Cs_Pin);

	//Motor 4 -> biaxes
	_clock[3]->getWatchPointer(0)->initGPIO(M4_Ah_GPIO_Port, M4_Ah_Pin, 9,
											M4_Bh_GPIO_Port, M4_Bh_Pin, 10,
											M4_Ch_GPIO_Port, M4_Ch_Pin);
	_clock[3]->getWatchPointer(1)->initGPIO(M4_Am_GPIO_Port, M4_Am_Pin, 2,
											M4_Bm_GPIO_Port, M4_Bm_Pin, 7,
											M4_Cm_GPIO_Port, M4_Cm_Pin);

	//Motor 5 -> triaxes
	_clock[4]->getWatchPointer(0)->initGPIO(M5_Ah_GPIO_Port, M5_Ah_Pin, 5,
											M5_Bh_GPIO_Port, M5_Bh_Pin, 6,
											M5_Ch_GPIO_Port, M5_Ch_Pin);
	_clock[4]->getWatchPointer(1)->initGPIO(M5_Am_GPIO_Port, M5_Am_Pin, 10,
											M5_Bm_GPIO_Port, M5_Bm_Pin, 0,
											M5_Cm_GPIO_Port, M5_Cm_Pin);
	_clock[4]->getWatchPointer(2)->initGPIO(M5_As_GPIO_Port, M5_As_Pin, 2,
											M5_Bs_GPIO_Port, M5_Bs_Pin, 3,
											M5_Cs_GPIO_Port, M5_Cs_Pin);

	//Motor 6 -> biaxes
	_clock[5]->getWatchPointer(0)->initGPIO(M6_Ah_GPIO_Port, M6_Ah_Pin, 7,
											M6_Bh_GPIO_Port, M6_Bh_Pin, 3,
											M6_Ch_GPIO_Port, M6_Ch_Pin);
	_clock[5]->getWatchPointer(1)->initGPIO(M6_Am_GPIO_Port, M6_Am_Pin, 4,
											M6_Bm_GPIO_Port, M6_Bm_Pin, 5,
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
			_currentState = STATE_TRIGGER;
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
				//HAL_SPI_Receive_IT(&hspi1, buffer_SPI_rx, SPI_FRAME_SIZE);
				HAL_SPI_Receive_DMA(&hspi1, buffer_SPI_rx, SPI_FRAME_SIZE);
				//GEN(XFNullTransition());
			}
			if(_oldState == STATE_SPI)
			{
				//HAL_SPI_Receive_IT(&hspi1, buffer_SPI_rx, SPI_FRAME_SIZE);
				HAL_SPI_Receive_DMA(&hspi1, buffer_SPI_rx, SPI_FRAME_SIZE);
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
				readSPIFrame();
				GEN(XFNullTransition());
			}
			break;

		case STATE_CAN:
			if(_oldState == STATE_WAIT)
			{
				readCANFrame();
				GEN(XFNullTransition());
			}
			break;

		case STATE_TRIGGER:
			if(_oldState == STATE_WAIT)
			{
				test = !test;
				_clock[1]->getWatchPointer(1)->doOneStep(test);
				//GEN(XFNullTransition());
				scheduleTimeout(Timeout, 500);
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
	static uint8_t index=0;

	//Check frame type
	frameType = (buffer_SPI_rx[0] & 0b11000000) >> 6;

	index++;
	switch(frameType)
	{
	//DATA FRAME
	case 0:
		dataFrame();
		break;
	//CONFIGURATION FRAME
	case 1:
		configurationFrame();
		break;
	//BROADCAST CONFIGURATION FRAME
	case 2:
		broadcastConfigurationFrame();
		break;
	//RESET POSITION ZERO FRAME
	case 3:
		resetPositionZeroFrame();
		break;

	default:
		break;
	}

	if(index == 2)
	{
		uint8_t toto = 0;
	}
}

void Controller::dataFrame()
{
	uint8_t readAddress = buffer_SPI_rx[0] & 0b00111111;
	uint8_t clockAddress;
	uint8_t nbrDataBytes;	//Max 8


	//Check Processor address
	if(readAddress == myAddress)
	{
		clockAddress = buffer_SPI_rx[1];
		nbrDataBytes = buffer_SPI_rx[2];
		readSPIDataBytes(clockAddress, nbrDataBytes);
	}
	else
	{
		//Send data via CAN
	}
}

void Controller::configurationFrame()
{
	uint8_t readAddress = buffer_SPI_rx[0] & 0b00111111;
	uint8_t nbrDataBytes;	//Max 8

	//Check Processor address
	if(readAddress == myAddress)
	{
		nbrDataBytes = buffer_SPI_rx[1];
		readSPIConfigBytes(nbrDataBytes);
	}
	else
	{
		//Send data via CAN
	}
}

void Controller::broadcastConfigurationFrame()
{
	uint8_t nbrDataBytes;	//Max 8
	nbrDataBytes = buffer_SPI_rx[1];

	//Write on our variables
	readSPIConfigBytes(nbrDataBytes);

	//Send via CAN for others

}

void Controller::resetPositionZeroFrame()
{
	uint8_t readAddress = buffer_SPI_rx[0] & 0b00111111;
	uint8_t clkAddress;
	uint8_t watchPtrAddress;

	//Check Processor address
	if(readAddress == myAddress)
	{
		clkAddress = (buffer_SPI_rx[1] & 0b11111110) >> 1;
		watchPtrAddress = (buffer_SPI_rx[1] & 0b00000011);
		_clock[clkAddress]->getWatchPointer(watchPtrAddress)->position = 0;
	}
	else
	{
		//Send data via CAN
	}
}

void Controller::readSPIDataBytes(int clkAddr, int nbrBytes)
{
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
			break;
		}
	}
}

void Controller::readSPIConfigBytes(int nbrBytes)
{
	//First, read data bytes
	//Then, write on each variables
	for(uint8_t i=0; i<nbrBytes; i++)
	{
		switch(i)
		{
		case 0:
			statusBytes = buffer_SPI_rx[2];
			if(((statusBytes & 0b00010000)>>4) == true)
			{
				GEN(evFlagTrigger());	//FLAG TRIGGER
			}
			break;
		case 1:
			startTime = buffer_SPI_rx[3];
			break;
		case 2:
			stopTime = buffer_SPI_rx[4];
			break;
		case 3:
			nbrWatchPtrClk = buffer_SPI_rx[5];
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
			break;
		}
	}
}

//---------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------CAN------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------
void Controller::readCANFrame()
{

}

void Controller::writeCANFrame()
{

}
