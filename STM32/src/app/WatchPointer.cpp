#include <app/WatchPointer.h>
#include "event/evClockwise.h"
#include "event/evCounterClockwise.h"

WatchPointer::WatchPointer()
{
	_currentState = STATE_INIT;
}

WatchPointer::~WatchPointer()
{}

void WatchPointer::initGPIO(GPIO_TypeDef* A_Port, uint16_t A_Pin, uint16_t A_Nbr,
							GPIO_TypeDef* B_Port, uint16_t B_Pin, uint16_t B_Nbr,
							GPIO_TypeDef* C_Port, uint16_t C_Pin)
{
	this->A_GPIO_Port = A_Port;
	this->A_GPIO_Pin = A_Pin;
	this->A_Pin_Nbr = A_Nbr;

	this->B_GPIO_Port = B_Port;
	this->B_GPIO_Pin = B_Pin;
	this->B_Pin_Nbr = B_Nbr;

	this->C_GPIO_Port = C_Port;
	this->C_GPIO_Pin = C_Pin;

	this->startBehavior();
}

void WatchPointer::doOneStep(bool clockwise)
{
	if(clockwise)
	{
		GEN(evClockwise());
	}
	else
	{
		GEN(evCounterClockwise());
	}
}

XFEventStatus WatchPointer::processEvent()
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
		if (getCurrentEvent()->getEventType() == XFEvent::Event &&
						getCurrentEvent()->getId() == EventIds::evClockwiseId)
		{
			_currentState = STATE_CLKWISE;
			eventStatus = XFEventStatus::Consumed;
		}
		if (getCurrentEvent()->getEventType() == XFEvent::Event &&
						getCurrentEvent()->getId() == EventIds::evCounterClockwiseId)
		{
			_currentState = STATE_CNT_CLKWISE;
			eventStatus = XFEventStatus::Consumed;
		}
		break;

	case STATE_CLKWISE:
		if (getCurrentEvent()->getEventType() == XFEvent::Timeout &&
						getCurrentTimeout()->getId() == StepTimeout)
		{
			_currentState = STATE_COMMON;
			eventStatus = XFEventStatus::Consumed;
		}
		break;

	case STATE_CNT_CLKWISE:
		if (getCurrentEvent()->getEventType() == XFEvent::Timeout &&
						getCurrentTimeout()->getId() == StepTimeout)
		{
			_currentState = STATE_COMMON;
			eventStatus = XFEventStatus::Consumed;
		}
		break;

	case STATE_COMMON:
		if (getCurrentEvent()->getEventType() == XFEvent::Timeout &&
						getCurrentTimeout()->getId() == StepTimeout)
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
			break;

		case STATE_CLKWISE:
			if(_oldState == STATE_WAIT)
			{
				// ~ = bitwise NOT
				//From OUTPUT to INPUT
				switch(B_Pin_Nbr)
				{
				case 0: B_GPIO_Port->MODER &= ~(GPIO_MODER_MODER0);
					break;
				case 1: B_GPIO_Port->MODER &= ~(GPIO_MODER_MODER1);
					break;
				case 2: B_GPIO_Port->MODER &= ~(GPIO_MODER_MODER2);
					break;
				case 3: B_GPIO_Port->MODER &= ~(GPIO_MODER_MODER3);
					break;
				case 4: B_GPIO_Port->MODER &= ~(GPIO_MODER_MODER4);
					break;
				case 5: B_GPIO_Port->MODER &= ~(GPIO_MODER_MODER5);
					break;
				case 6: B_GPIO_Port->MODER &= ~(GPIO_MODER_MODER6);
					break;
				case 7: B_GPIO_Port->MODER &= ~(GPIO_MODER_MODER7);
					break;
				case 8: B_GPIO_Port->MODER &= ~(GPIO_MODER_MODER8);
					break;
				case 9: B_GPIO_Port->MODER &= ~(GPIO_MODER_MODER9);
					break;
				case 10: B_GPIO_Port->MODER &= ~(GPIO_MODER_MODER10);
					break;
				case 11: B_GPIO_Port->MODER &= ~(GPIO_MODER_MODER11);
					break;
				case 12: B_GPIO_Port->MODER &= ~(GPIO_MODER_MODER12);
					break;
				case 13: B_GPIO_Port->MODER &= ~(GPIO_MODER_MODER13);
					break;
				case 14: B_GPIO_Port->MODER &= ~(GPIO_MODER_MODER14);
					break;
				case 15: B_GPIO_Port->MODER &= ~(GPIO_MODER_MODER15);
					break;
				default:
					break;
				}
				HAL_GPIO_WritePin(A_GPIO_Port, A_GPIO_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(C_GPIO_Port, C_GPIO_Pin, GPIO_PIN_RESET);
				scheduleTimeout(StepTimeout, DELAY_ON);
			}
			break;

		case STATE_CNT_CLKWISE:
			if(_oldState == STATE_WAIT)
			{
				// ~ = bitwise NOT
				//From OUTPUT to INPUT
				switch(A_Pin_Nbr)
				{
				case 0: A_GPIO_Port->MODER &= ~(GPIO_MODER_MODER0);
					break;
				case 1: A_GPIO_Port->MODER &= ~(GPIO_MODER_MODER1);
					break;
				case 2: A_GPIO_Port->MODER &= ~(GPIO_MODER_MODER2);
					break;
				case 3: A_GPIO_Port->MODER &= ~(GPIO_MODER_MODER3);
					break;
				case 4: A_GPIO_Port->MODER &= ~(GPIO_MODER_MODER4);
					break;
				case 5: A_GPIO_Port->MODER &= ~(GPIO_MODER_MODER5);
					break;
				case 6: A_GPIO_Port->MODER &= ~(GPIO_MODER_MODER6);
					break;
				case 7: A_GPIO_Port->MODER &= ~(GPIO_MODER_MODER7);
					break;
				case 8: A_GPIO_Port->MODER &= ~(GPIO_MODER_MODER8);
					break;
				case 9: A_GPIO_Port->MODER &= ~(GPIO_MODER_MODER9);
					break;
				case 10: A_GPIO_Port->MODER &= ~(GPIO_MODER_MODER10);
					break;
				case 11: A_GPIO_Port->MODER &= ~(GPIO_MODER_MODER11);
					break;
				case 12: A_GPIO_Port->MODER &= ~(GPIO_MODER_MODER12);
					break;
				case 13: A_GPIO_Port->MODER &= ~(GPIO_MODER_MODER13);
					break;
				case 14: A_GPIO_Port->MODER &= ~(GPIO_MODER_MODER14);
					break;
				case 15: A_GPIO_Port->MODER &= ~(GPIO_MODER_MODER15);
					break;
				default:
					break;
				}
				HAL_GPIO_WritePin(B_GPIO_Port, B_GPIO_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(C_GPIO_Port, C_GPIO_Pin, GPIO_PIN_RESET);
				scheduleTimeout(StepTimeout, DELAY_ON);	//3ms
			}
			break;

		case STATE_COMMON:
			if(_oldState == STATE_CLKWISE)
			{
				//INPUT to OUTPUT
				switch(B_Pin_Nbr)
				{
				case 0: B_GPIO_Port->MODER |= GPIO_MODER_MODER0_0;
					break;
				case 1: B_GPIO_Port->MODER |= GPIO_MODER_MODER1_0;
					break;
				case 2: B_GPIO_Port->MODER |= GPIO_MODER_MODER2_0;
					break;
				case 3: B_GPIO_Port->MODER |= GPIO_MODER_MODER3_0;
					break;
				case 4: B_GPIO_Port->MODER |= GPIO_MODER_MODER4_0;
					break;
				case 5: B_GPIO_Port->MODER |= GPIO_MODER_MODER5_0;
					break;
				case 6: B_GPIO_Port->MODER |= GPIO_MODER_MODER6_0;
					break;
				case 7: B_GPIO_Port->MODER |= GPIO_MODER_MODER7_0;
					break;
				case 8: B_GPIO_Port->MODER |= GPIO_MODER_MODER8_0;
					break;
				case 9: B_GPIO_Port->MODER |= GPIO_MODER_MODER9_0;
					break;
				case 10: B_GPIO_Port->MODER |= GPIO_MODER_MODER10_0;
					break;
				case 11: B_GPIO_Port->MODER |= GPIO_MODER_MODER11_0;
					break;
				case 12: B_GPIO_Port->MODER |= GPIO_MODER_MODER12_0;
					break;
				case 13: B_GPIO_Port->MODER |= GPIO_MODER_MODER13_0;
					break;
				case 14: B_GPIO_Port->MODER |= GPIO_MODER_MODER14_0;
					break;
				case 15: B_GPIO_Port->MODER |= GPIO_MODER_MODER15_0;
					break;
				default:
					break;
				}
			}
			if(_oldState == STATE_CNT_CLKWISE)
			{
				//INPUT to OUTPUT
				switch(A_Pin_Nbr)
				{
				case 0: A_GPIO_Port->MODER |= GPIO_MODER_MODER0_0;
					break;
				case 1: A_GPIO_Port->MODER |= GPIO_MODER_MODER1_0;
					break;
				case 2: A_GPIO_Port->MODER |= GPIO_MODER_MODER2_0;
					break;
				case 3: A_GPIO_Port->MODER |= GPIO_MODER_MODER3_0;
					break;
				case 4: A_GPIO_Port->MODER |= GPIO_MODER_MODER4_0;
					break;
				case 5: A_GPIO_Port->MODER |= GPIO_MODER_MODER5_0;
					break;
				case 6: A_GPIO_Port->MODER |= GPIO_MODER_MODER6_0;
					break;
				case 7: A_GPIO_Port->MODER |= GPIO_MODER_MODER7_0;
					break;
				case 8: A_GPIO_Port->MODER |= GPIO_MODER_MODER8_0;
					break;
				case 9: A_GPIO_Port->MODER |= GPIO_MODER_MODER9_0;
					break;
				case 10: A_GPIO_Port->MODER |= GPIO_MODER_MODER10_0;
					break;
				case 11: A_GPIO_Port->MODER |= GPIO_MODER_MODER11_0;
					break;
				case 12: A_GPIO_Port->MODER |= GPIO_MODER_MODER12_0;
					break;
				case 13: A_GPIO_Port->MODER |= GPIO_MODER_MODER13_0;
					break;
				case 14: A_GPIO_Port->MODER |= GPIO_MODER_MODER14_0;
					break;
				case 15: A_GPIO_Port->MODER |= GPIO_MODER_MODER15_0;
					break;
				default:
					break;
				}
			}
			if(_oldState == STATE_CLKWISE || _oldState == STATE_CNT_CLKWISE)
			{
				HAL_GPIO_WritePin(A_GPIO_Port, A_GPIO_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(B_GPIO_Port, B_GPIO_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(C_GPIO_Port, C_GPIO_Pin, GPIO_PIN_RESET);
				scheduleTimeout(StepTimeout, DELAY_OFF);	//14ms
			}
			break;

		default:
			break;
		}
	}
}

