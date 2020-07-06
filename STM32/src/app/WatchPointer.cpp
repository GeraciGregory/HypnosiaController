#include <app/WatchPointer.h>
#include "event/evClockwise.h"
#include "event/evCounterClockwise.h"

WatchPointer::WatchPointer()
{
	_currentState = STATE_INIT;

	clockwiseStep = true;
	counterClockwiseStep = true;
}

WatchPointer::~WatchPointer()
{}

void WatchPointer::initGPIO(GPIO_TypeDef* A_Port, uint16_t A_Pin,
							GPIO_TypeDef* B_Port, uint16_t B_Pin,
							GPIO_TypeDef* C_Port, uint16_t C_Pin)
{
	this->A_GPIO_Port = A_Port;
	this->A_GPIO_Pin = A_Pin;

	this->B_GPIO_Port = B_Port;
	this->B_GPIO_Pin = B_Pin;

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
				//Output -> Input
				GPIO_InitStruct.Pin = B_GPIO_Pin;
				GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
				GPIO_InitStruct.Pull = GPIO_NOPULL;
				HAL_GPIO_Init(B_GPIO_Port, &GPIO_InitStruct);

				if(clockwiseStep == true)
				{
					HAL_GPIO_WritePin(A_GPIO_Port, A_GPIO_Pin, GPIO_PIN_SET);
					HAL_GPIO_WritePin(C_GPIO_Port, C_GPIO_Pin, GPIO_PIN_RESET);
				}
				else
				{
					HAL_GPIO_WritePin(A_GPIO_Port, A_GPIO_Pin, GPIO_PIN_RESET);
					HAL_GPIO_WritePin(C_GPIO_Port, C_GPIO_Pin, GPIO_PIN_SET);
				}
				clockwiseStep = !clockwiseStep;
				scheduleTimeout(StepTimeout, DELAY_ON);
			}
			break;

		case STATE_CNT_CLKWISE:
			if(_oldState == STATE_WAIT)
			{
				//Output -> Input
				GPIO_InitStruct.Pin = A_GPIO_Pin;
				GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
				GPIO_InitStruct.Pull = GPIO_NOPULL;
				HAL_GPIO_Init(A_GPIO_Port, &GPIO_InitStruct);

				if(counterClockwiseStep == true)
				{
					HAL_GPIO_WritePin(B_GPIO_Port, B_GPIO_Pin, GPIO_PIN_SET);
					HAL_GPIO_WritePin(C_GPIO_Port, C_GPIO_Pin, GPIO_PIN_RESET);
				}
				else
				{
					HAL_GPIO_WritePin(B_GPIO_Port, B_GPIO_Pin, GPIO_PIN_RESET);
					HAL_GPIO_WritePin(C_GPIO_Port, C_GPIO_Pin, GPIO_PIN_SET);
				}
				counterClockwiseStep = !counterClockwiseStep;
				scheduleTimeout(StepTimeout, DELAY_ON);	//3ms
			}
			break;

		case STATE_COMMON:
			if(_oldState == STATE_CLKWISE)
			{
				//Input -> Output
				GPIO_InitStruct.Pin = B_GPIO_Pin;
				GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
				GPIO_InitStruct.Pull = GPIO_NOPULL;
				GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
				HAL_GPIO_Init(B_GPIO_Port, &GPIO_InitStruct);

			}
			if(_oldState == STATE_CNT_CLKWISE)
			{
				//Input -> Output
				GPIO_InitStruct.Pin = A_GPIO_Pin;
				GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
				GPIO_InitStruct.Pull = GPIO_NOPULL;
				GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
				HAL_GPIO_Init(A_GPIO_Port, &GPIO_InitStruct);
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

