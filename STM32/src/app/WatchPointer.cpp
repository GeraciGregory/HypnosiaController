#include <app/WatchPointer.h>
#include <string.h>

//Used for debugging
extern char error[200];

//Constructor
WatchPointer::WatchPointer(uint8_t angle)
{
	this->outputAngle = angle;			//Initialize output angle, 2° or 3°

	_currentState = STATE_INIT;			//Initialize state of the state machine

	//Initialize used variable
	coilSelection = true;
	actualPosition = 0;
	newPosition = 0;
	nbrStepToDo = 0;
}
//Destructor
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

	//Start behavior of state machine
	this->startBehavior();
}

void WatchPointer::onMove()
{
	//Called by the controller
	pushEvent(&_evMove);
}

XFEventStatus WatchPointer::processEvent()
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
					getCurrentEvent()->getId() == EventsID::evMoveId)
		{
			//Check number of step to be taken to set the next state
			if(nbrStepToDo > 0)
			{
				_currentState = STATE_STEP_ON;
			}
			else
			{
				_currentState = STATE_WAIT;
			}
			eventStatus = XFEventStatus::Consumed;
		}
		break;

	case STATE_STEP_ON:
		if (getCurrentEvent()->getEventType() == XFEvent::Timeout &&
						getCurrentTimeout()->getId() == StepTimeout)
		{
			_currentState = STATE_STEP_OFF;
			eventStatus = XFEventStatus::Consumed;
		}
		break;

	case STATE_STEP_OFF:
		if (getCurrentEvent()->getEventType() == XFEvent::Timeout &&
						getCurrentTimeout()->getId() == StepTimeout)
		{
			//Check number of step to be taken to set the next state
			if(nbrStepToDo > 0)
			{
				_currentState = STATE_STEP_ON;
			}
			else
			{
				_currentState = STATE_WAIT;
			}
			eventStatus = XFEventStatus::Consumed;
		}
		break;

	default:
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
			break;

		case STATE_STEP_ON:
			if(_oldState == STATE_WAIT || _oldState == STATE_STEP_OFF)
			{
				nbrStepToDo--;
				changePosition(clockwise);

				if(clockwise==true)
				{
					//Output -> Input
					GPIO_InitStruct.Pin = B_GPIO_Pin;
					GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
					GPIO_InitStruct.Pull = GPIO_NOPULL;
					HAL_GPIO_Init(B_GPIO_Port, &GPIO_InitStruct);

					if(coilSelection == true)
					{
						HAL_GPIO_WritePin(A_GPIO_Port, A_GPIO_Pin, GPIO_PIN_SET);
						HAL_GPIO_WritePin(C_GPIO_Port, C_GPIO_Pin, GPIO_PIN_RESET);
					}
					else
					{
						HAL_GPIO_WritePin(A_GPIO_Port, A_GPIO_Pin, GPIO_PIN_RESET);
						HAL_GPIO_WritePin(C_GPIO_Port, C_GPIO_Pin, GPIO_PIN_SET);
					}
				}
				else
				{
					//Output -> Input
					GPIO_InitStruct.Pin = A_GPIO_Pin;
					GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
					GPIO_InitStruct.Pull = GPIO_NOPULL;
					HAL_GPIO_Init(A_GPIO_Port, &GPIO_InitStruct);

					if(coilSelection == true)
					{
						HAL_GPIO_WritePin(B_GPIO_Port, B_GPIO_Pin, GPIO_PIN_SET);
						HAL_GPIO_WritePin(C_GPIO_Port, C_GPIO_Pin, GPIO_PIN_RESET);
					}
					else
					{
						HAL_GPIO_WritePin(B_GPIO_Port, B_GPIO_Pin, GPIO_PIN_RESET);
						HAL_GPIO_WritePin(C_GPIO_Port, C_GPIO_Pin, GPIO_PIN_SET);
					}
				}

				sprintf(error, "Error at line: %d in file %s", __LINE__, __FILE__);		//Used for debugging
				coilSelection = !coilSelection;
				scheduleTimeout(StepTimeout, DELAY_ON);									//Schedule timeout (ON)
			}
			break;

		case STATE_STEP_OFF:
			if(_oldState == STATE_STEP_ON)
			{
				if(clockwise == true)
				{
					//Input -> Output
					GPIO_InitStruct.Pin = B_GPIO_Pin;
					GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
					GPIO_InitStruct.Pull = GPIO_NOPULL;
					GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
					HAL_GPIO_Init(B_GPIO_Port, &GPIO_InitStruct);
				}
				else
				{
					//Input -> Output
					GPIO_InitStruct.Pin = A_GPIO_Pin;
					GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
					GPIO_InitStruct.Pull = GPIO_NOPULL;
					GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
					HAL_GPIO_Init(A_GPIO_Port, &GPIO_InitStruct);
				}


				HAL_GPIO_WritePin(A_GPIO_Port, A_GPIO_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(B_GPIO_Port, B_GPIO_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(C_GPIO_Port, C_GPIO_Pin, GPIO_PIN_RESET);

				sprintf(error, "Error at line: %d in file %s", __LINE__, __FILE__);		//Used for debugging
				scheduleTimeout(StepTimeout, DELAY_OFF);								//Schedule timeout (OFF)
			}

			break;
		default:
			break;
		}
	}
	//**********************************************************************************
	return eventStatus;
}

void WatchPointer::changePosition(bool clockwise)
{
	//Increment position
	if(clockwise == true)
	{
		//Check limits
		if(actualPosition == ((360/outputAngle)-1))
		{
			actualPosition = 0;

		}
		else
		{
			actualPosition++;
		}
	}
	else
	{
		//Check limits
		if(actualPosition == 0)
		{
			actualPosition = ((360/outputAngle)-1);
		}
		else
		{
			actualPosition--;
		}
	}
}

