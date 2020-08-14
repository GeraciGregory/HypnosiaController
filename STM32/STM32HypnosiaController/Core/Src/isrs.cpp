#include "main.h"
#include "app/Controller.h"
#include "stm32f0xx_it.h"
extern CAN_RxHeaderTypeDef myRxMessage;

//Called when an SPI interruption has occurred
extern "C" void HAL_SPI_RxCpltCallback(SPI_HandleTypeDef *hspi)
{
	Controller::getInstance()->onIrqSPI();	//Generate event for state machine
}

//Called when an CAN interruption has occurred
extern "C" void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *hcan)
{
	Controller::getInstance()->onIrqCAN();	//Generate event for state machine
}


