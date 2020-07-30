#ifndef WATCHPOINTER_H_
#define WATCHPOINTER_H_

#include "stdint.h"
#include "stm32f0xx_hal.h"
#include "xf/behavior.h"

#define DELAY_ON	30	//3ms
#define DELAY_OFF	140	//14ms

#define QUEUE_SIZE	360	//MAX 2 turns = 2*(360/2)

class WatchPointer : public XFBehavior
{
public:
	WatchPointer(uint8_t outputAngle);
	~WatchPointer();

	void initGPIO(GPIO_TypeDef* A_Port, uint16_t A_Pin,
					GPIO_TypeDef* B_Port, uint16_t B_Pin,
					GPIO_TypeDef* C_Port, uint16_t C_Pin);
	void doOneStep(bool clockwise);
	void generateEvent();

	//Queue of event
	bool eventQueue[QUEUE_SIZE];
	uint16_t indexQueue;

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


	int tata;
	int toto;

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
		STATE_CLKWISE = 2,
		STATE_CNT_CLKWISE = 3,
		STATE_COMMON = 4
	} eMotorsState;

	eMotorsState _currentState;		///< Attribute indicating currently active state
	eMotorsState _oldState;			///< Attribute indicating currently active state

private:
	bool clockwiseStep;
	bool counterClockwiseStep;
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
