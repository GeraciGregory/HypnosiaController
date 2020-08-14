#ifndef WATCHPOINTER_H_
#define WATCHPOINTER_H_

//************************************INCLUDE***************************************
#include "stdint.h"
#include "stm32f0xx_hal.h"
#include "xf/behavior.h"
//Used events
#include "event/evClockwise.h"
#include "event/evCounterClockwise.h"
#include "event/evMove.h"
//************************************DEFINE****************************************
#define DELAY_ON	30	//3ms
#define DELAY_OFF	140	//14ms
//**********************************************************************************
class WatchPointer : public XFBehavior
{
public:
	WatchPointer(uint8_t angle);							//Constructor, initialize the output angle of the movement
	~WatchPointer();										//Destructor

	void initGPIO(GPIO_TypeDef* A_Port, uint16_t A_Pin,		//Initialize GPIO in order to drive the movement
					GPIO_TypeDef* B_Port, uint16_t B_Pin,
					GPIO_TypeDef* C_Port, uint16_t C_Pin);
	void onMove();											//Generate event for the state machine
	void changePosition(bool clockwise);					//Update position


	//WATCH POINTER PROPERTIES
	uint8_t outputAngle;
	//Configuration
	uint8_t clockwise;
	uint8_t nbrTurns;
	//Position
	uint8_t newPosition;
	uint8_t actualPosition;
	//Timing
	uint8_t offsetStartTime;
	uint8_t movmentDurationTime;
	//Step to do
	uint8_t nbrStepToDo;

	//Static event
	evMove _evMove;

protected:
	virtual XFEventStatus processEvent();

protected:
	/**
	 * Timeout identifier(s) for this state machine
	 */
	typedef enum
	{
		StepTimeout = 1
	} eTimeoutId;

	/**
	 * Enumeration used to have a unique identifier for every
	 * state in the state machine.
	 */
	typedef enum
	{
		STATE_INIT = 0,
		STATE_WAIT = 1,
		STATE_STEP_ON = 3,
		STATE_STEP_OFF = 4
	} eMotorsState;

	eMotorsState _currentState;		///< Attribute indicating currently active state
	eMotorsState _oldState;			///< Attribute indicating currently active state

private:
	//Used to drive the movement
	bool coilSelection;
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	GPIO_TypeDef* A_GPIO_Port;
	uint16_t A_GPIO_Pin;
	GPIO_TypeDef* B_GPIO_Port;
	uint16_t B_GPIO_Pin;
	GPIO_TypeDef* C_GPIO_Port;
	uint16_t C_GPIO_Pin;
};

#endif /* WATCHPOINTER_H_ */
