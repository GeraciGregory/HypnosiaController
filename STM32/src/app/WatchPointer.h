#ifndef WATCHPOINTER_H_
#define WATCHPOINTER_H_

#include "stdint.h"
#include "stm32f0xx_hal.h"
#include "xf/behavior.h"

#define DELAY_ON	30	//3ms
#define DELAY_OFF	140	//14ms

class WatchPointer : public XFBehavior
{
public:
	WatchPointer();
	virtual ~WatchPointer();

	void initGPIO(GPIO_TypeDef* A_Port, uint16_t A_Pin, uint16_t A_Nbr,
					GPIO_TypeDef* B_Port, uint16_t B_Pin, uint16_t B_Nbr,
					GPIO_TypeDef* C_Port, uint16_t C_Pin);
	void doOneStep(bool clockwise);

	//Configuration
	uint8_t clockwise;
	uint8_t nbrTurns;
	//Position
	uint8_t position;
	//Timing
	uint8_t offsetStartTime;
	uint8_t movmentDurationTime;


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
	GPIO_TypeDef* A_GPIO_Port;
	uint16_t A_GPIO_Pin;
	uint16_t A_Pin_Nbr;

	GPIO_TypeDef* B_GPIO_Port;
	uint16_t B_GPIO_Pin;
	uint16_t B_Pin_Nbr;

	GPIO_TypeDef* C_GPIO_Port;
	uint16_t C_GPIO_Pin;
};

#endif /* WATCHPOINTER_H_ */
