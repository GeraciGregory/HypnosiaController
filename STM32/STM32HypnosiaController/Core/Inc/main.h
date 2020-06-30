/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f0xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define M5_As_Pin GPIO_PIN_2
#define M5_As_GPIO_Port GPIOE
#define M5_Bs_Pin GPIO_PIN_3
#define M5_Bs_GPIO_Port GPIOE
#define M5_Cs_Pin GPIO_PIN_4
#define M5_Cs_GPIO_Port GPIOE
#define M5_Ah_Pin GPIO_PIN_5
#define M5_Ah_GPIO_Port GPIOE
#define M5_Bh_Pin GPIO_PIN_6
#define M5_Bh_GPIO_Port GPIOE
#define M5_Ch_Pin GPIO_PIN_9
#define M5_Ch_GPIO_Port GPIOF
#define M5_Am_Pin GPIO_PIN_10
#define M5_Am_GPIO_Port GPIOF
#define M5_Bm_Pin GPIO_PIN_0
#define M5_Bm_GPIO_Port GPIOC
#define M5_Cm_Pin GPIO_PIN_1
#define M5_Cm_GPIO_Port GPIOC
#define STBY_Pin GPIO_PIN_2
#define STBY_GPIO_Port GPIOF
#define SW_4_Pin GPIO_PIN_3
#define SW_4_GPIO_Port GPIOF
#define SW_3_Pin GPIO_PIN_0
#define SW_3_GPIO_Port GPIOA
#define SW_2_Pin GPIO_PIN_1
#define SW_2_GPIO_Port GPIOA
#define SW_1_Pin GPIO_PIN_2
#define SW_1_GPIO_Port GPIOA
#define SW_0_Pin GPIO_PIN_3
#define SW_0_GPIO_Port GPIOA
#define LED_6_Pin GPIO_PIN_4
#define LED_6_GPIO_Port GPIOC
#define LED_5_Pin GPIO_PIN_5
#define LED_5_GPIO_Port GPIOC
#define LED_3_Pin GPIO_PIN_0
#define LED_3_GPIO_Port GPIOB
#define LED_2_Pin GPIO_PIN_1
#define LED_2_GPIO_Port GPIOB
#define M4_Am_Pin GPIO_PIN_2
#define M4_Am_GPIO_Port GPIOB
#define M4_Bm_Pin GPIO_PIN_7
#define M4_Bm_GPIO_Port GPIOE
#define M4_Cm_Pin GPIO_PIN_8
#define M4_Cm_GPIO_Port GPIOE
#define M4_Ah_Pin GPIO_PIN_9
#define M4_Ah_GPIO_Port GPIOE
#define M4_Bh_Pin GPIO_PIN_10
#define M4_Bh_GPIO_Port GPIOE
#define M4_Ch_Pin GPIO_PIN_11
#define M4_Ch_GPIO_Port GPIOE
#define M4_As_Pin GPIO_PIN_12
#define M4_As_GPIO_Port GPIOE
#define M4_Bs_Pin GPIO_PIN_13
#define M4_Bs_GPIO_Port GPIOE
#define M4_Cs_Pin GPIO_PIN_14
#define M4_Cs_GPIO_Port GPIOE
#define LED_4_Pin GPIO_PIN_15
#define LED_4_GPIO_Port GPIOE
#define LED_1_Pin GPIO_PIN_10
#define LED_1_GPIO_Port GPIOB
#define M1_As_Pin GPIO_PIN_11
#define M1_As_GPIO_Port GPIOB
#define M1_Bs_Pin GPIO_PIN_12
#define M1_Bs_GPIO_Port GPIOB
#define M1_Cs_Pin GPIO_PIN_13
#define M1_Cs_GPIO_Port GPIOB
#define M1_Am_Pin GPIO_PIN_14
#define M1_Am_GPIO_Port GPIOB
#define M1_Bm_Pin GPIO_PIN_15
#define M1_Bm_GPIO_Port GPIOB
#define M1_Cm_Pin GPIO_PIN_8
#define M1_Cm_GPIO_Port GPIOD
#define M1_Ah_Pin GPIO_PIN_9
#define M1_Ah_GPIO_Port GPIOD
#define M1_Bh_Pin GPIO_PIN_10
#define M1_Bh_GPIO_Port GPIOD
#define M1_Ch_Pin GPIO_PIN_11
#define M1_Ch_GPIO_Port GPIOD
#define M2_As_Pin GPIO_PIN_12
#define M2_As_GPIO_Port GPIOD
#define M2_Bs_Pin GPIO_PIN_13
#define M2_Bs_GPIO_Port GPIOD
#define M2_Cs_Pin GPIO_PIN_14
#define M2_Cs_GPIO_Port GPIOD
#define M2_Ah_Pin GPIO_PIN_15
#define M2_Ah_GPIO_Port GPIOD
#define M2_Bh_Pin GPIO_PIN_6
#define M2_Bh_GPIO_Port GPIOC
#define M2_Ch_Pin GPIO_PIN_7
#define M2_Ch_GPIO_Port GPIOC
#define M2_Am_Pin GPIO_PIN_8
#define M2_Am_GPIO_Port GPIOC
#define M2_Bm_Pin GPIO_PIN_9
#define M2_Bm_GPIO_Port GPIOC
#define M2_Cm_Pin GPIO_PIN_8
#define M2_Cm_GPIO_Port GPIOA
#define M3_As_Pin GPIO_PIN_6
#define M3_As_GPIO_Port GPIOF
#define M3_Bs_Pin GPIO_PIN_15
#define M3_Bs_GPIO_Port GPIOA
#define M3_Cs_Pin GPIO_PIN_10
#define M3_Cs_GPIO_Port GPIOC
#define M3_Ah_Pin GPIO_PIN_11
#define M3_Ah_GPIO_Port GPIOC
#define M3_Bh_Pin GPIO_PIN_12
#define M3_Bh_GPIO_Port GPIOC
#define M3_Ch_Pin GPIO_PIN_0
#define M3_Ch_GPIO_Port GPIOD
#define M3_Am_Pin GPIO_PIN_1
#define M3_Am_GPIO_Port GPIOD
#define M3_Bm_Pin GPIO_PIN_2
#define M3_Bm_GPIO_Port GPIOD
#define M3_Cm_Pin GPIO_PIN_3
#define M3_Cm_GPIO_Port GPIOD
#define M6_Am_Pin GPIO_PIN_4
#define M6_Am_GPIO_Port GPIOD
#define M6_Bm_Pin GPIO_PIN_5
#define M6_Bm_GPIO_Port GPIOD
#define M6_Cm_Pin GPIO_PIN_6
#define M6_Cm_GPIO_Port GPIOD
#define M6_Ah_Pin GPIO_PIN_7
#define M6_Ah_GPIO_Port GPIOD
#define M6_Bh_Pin GPIO_PIN_3
#define M6_Bh_GPIO_Port GPIOB
#define M6_Ch_Pin GPIO_PIN_4
#define M6_Ch_GPIO_Port GPIOB
#define M6_As_Pin GPIO_PIN_5
#define M6_As_GPIO_Port GPIOB
#define M6_Bs_Pin GPIO_PIN_6
#define M6_Bs_GPIO_Port GPIOB
#define M6_Cs_Pin GPIO_PIN_7
#define M6_Cs_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
