/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.h
 * @brief          : Header for main.c file.
 *                   This file contains the common defines of the application.
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2025 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
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
#include "stm32h7xx_hal.h"

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
#define PWR_BTN_Pin GPIO_PIN_2
#define PWR_BTN_GPIO_Port GPIOE
#define PWR_BTN_EXTI_IRQn EXTI2_IRQn
#define PWR_CTRL_Pin GPIO_PIN_3
#define PWR_CTRL_GPIO_Port GPIOE
#define D2_EN4_Pin GPIO_PIN_5
#define D2_EN4_GPIO_Port GPIOE
#define D2_DR5_Pin GPIO_PIN_6
#define D2_DR5_GPIO_Port GPIOE
#define D2_EN5_Pin GPIO_PIN_8
#define D2_EN5_GPIO_Port GPIOI
#define D3_DR1_Pin GPIO_PIN_13
#define D3_DR1_GPIO_Port GPIOC
#define D3_EN1_Pin GPIO_PIN_9
#define D3_EN1_GPIO_Port GPIOI
#define D3_DR2_Pin GPIO_PIN_10
#define D3_DR2_GPIO_Port GPIOI
#define D3_EN2_Pin GPIO_PIN_11
#define D3_EN2_GPIO_Port GPIOI
#define D3_DR3_Pin GPIO_PIN_0
#define D3_DR3_GPIO_Port GPIOF
#define D3_EN3_Pin GPIO_PIN_1
#define D3_EN3_GPIO_Port GPIOF
#define D3_DR4_Pin GPIO_PIN_2
#define D3_DR4_GPIO_Port GPIOF
#define D3_EN4_Pin GPIO_PIN_3
#define D3_EN4_GPIO_Port GPIOF
#define D3_DR5_Pin GPIO_PIN_4
#define D3_DR5_GPIO_Port GPIOF
#define D3_EN5_Pin GPIO_PIN_5
#define D3_EN5_GPIO_Port GPIOF
#define D4_DR1_Pin GPIO_PIN_6
#define D4_DR1_GPIO_Port GPIOF
#define D4_EN1_Pin GPIO_PIN_7
#define D4_EN1_GPIO_Port GPIOF
#define D4_DR2_Pin GPIO_PIN_8
#define D4_DR2_GPIO_Port GPIOF
#define D4_EN2_Pin GPIO_PIN_9
#define D4_EN2_GPIO_Port GPIOF
#define D4_DR3_Pin GPIO_PIN_10
#define D4_DR3_GPIO_Port GPIOF
#define D4_EN3_Pin GPIO_PIN_0
#define D4_EN3_GPIO_Port GPIOC
#define D4_DR4_Pin GPIO_PIN_1
#define D4_DR4_GPIO_Port GPIOC
#define D4_EN4_Pin GPIO_PIN_2
#define D4_EN4_GPIO_Port GPIOC
#define D4_DR5_Pin GPIO_PIN_3
#define D4_DR5_GPIO_Port GPIOC
#define D4_EN5_Pin GPIO_PIN_0
#define D4_EN5_GPIO_Port GPIOA
#define D5_DR1_Pin GPIO_PIN_1
#define D5_DR1_GPIO_Port GPIOA
#define D5_EN1_Pin GPIO_PIN_2
#define D5_EN1_GPIO_Port GPIOA
#define D5_DR2_Pin GPIO_PIN_2
#define D5_DR2_GPIO_Port GPIOH
#define D5_EN2_Pin GPIO_PIN_3
#define D5_EN2_GPIO_Port GPIOH
#define D5_DR3_Pin GPIO_PIN_4
#define D5_DR3_GPIO_Port GPIOH
#define D5_EN3_Pin GPIO_PIN_5
#define D5_EN3_GPIO_Port GPIOH
#define D5_DR4_Pin GPIO_PIN_3
#define D5_DR4_GPIO_Port GPIOA
#define D5_EN4_Pin GPIO_PIN_4
#define D5_EN4_GPIO_Port GPIOA
#define D5_DR5_Pin GPIO_PIN_5
#define D5_DR5_GPIO_Port GPIOA
#define VBAT_SENSING_Pin GPIO_PIN_6
#define VBAT_SENSING_GPIO_Port GPIOA
#define D5_EN5_Pin GPIO_PIN_7
#define D5_EN5_GPIO_Port GPIOA
#define D6_DR1_Pin GPIO_PIN_4
#define D6_DR1_GPIO_Port GPIOC
#define D6_EN1_Pin GPIO_PIN_5
#define D6_EN1_GPIO_Port GPIOC
#define D6_DR2_Pin GPIO_PIN_0
#define D6_DR2_GPIO_Port GPIOB
#define D6_EN2_Pin GPIO_PIN_1
#define D6_EN2_GPIO_Port GPIOB
#define D6_DR3_Pin GPIO_PIN_2
#define D6_DR3_GPIO_Port GPIOB
#define D6_EN3_Pin GPIO_PIN_11
#define D6_EN3_GPIO_Port GPIOF
#define D6_DR4_Pin GPIO_PIN_12
#define D6_DR4_GPIO_Port GPIOF
#define D6_EN4_Pin GPIO_PIN_13
#define D6_EN4_GPIO_Port GPIOF
#define D6_DR5_Pin GPIO_PIN_14
#define D6_DR5_GPIO_Port GPIOF
#define D6_EN5_Pin GPIO_PIN_15
#define D6_EN5_GPIO_Port GPIOF
#define BEEP_Pin GPIO_PIN_0
#define BEEP_GPIO_Port GPIOG
#define INDEX_LED_Pin GPIO_PIN_8
#define INDEX_LED_GPIO_Port GPIOE
#define BTN1_Pin GPIO_PIN_12
#define BTN1_GPIO_Port GPIOE
#define BTN1_EXTI_IRQn EXTI15_10_IRQn
#define BTN2_Pin GPIO_PIN_13
#define BTN2_GPIO_Port GPIOE
#define BTN2_EXTI_IRQn EXTI15_10_IRQn
#define BTN3_Pin GPIO_PIN_14
#define BTN3_GPIO_Port GPIOE
#define BTN3_EXTI_IRQn EXTI15_10_IRQn
#define BTN4_Pin GPIO_PIN_15
#define BTN4_GPIO_Port GPIOE
#define BTN4_EXTI_IRQn EXTI15_10_IRQn
#define D6_DR6_Pin GPIO_PIN_11
#define D6_DR6_GPIO_Port GPIOH
#define D6_EN6_Pin GPIO_PIN_12
#define D6_EN6_GPIO_Port GPIOH
#define D6_DR7_Pin GPIO_PIN_12
#define D6_DR7_GPIO_Port GPIOB
#define D6_EN7_Pin GPIO_PIN_13
#define D6_EN7_GPIO_Port GPIOB
#define D5_DR6_Pin GPIO_PIN_14
#define D5_DR6_GPIO_Port GPIOB
#define D5_EN6_Pin GPIO_PIN_15
#define D5_EN6_GPIO_Port GPIOB
#define D5_DR7_Pin GPIO_PIN_8
#define D5_DR7_GPIO_Port GPIOD
#define D5_EN7_Pin GPIO_PIN_9
#define D5_EN7_GPIO_Port GPIOD
#define D4_DR6_Pin GPIO_PIN_10
#define D4_DR6_GPIO_Port GPIOD
#define D4_EN6_Pin GPIO_PIN_11
#define D4_EN6_GPIO_Port GPIOD
#define D4_DR7_Pin GPIO_PIN_14
#define D4_DR7_GPIO_Port GPIOD
#define D4_EN7_Pin GPIO_PIN_15
#define D4_EN7_GPIO_Port GPIOD
#define D3_DR6_Pin GPIO_PIN_6
#define D3_DR6_GPIO_Port GPIOG
#define D3_EN6_Pin GPIO_PIN_7
#define D3_EN6_GPIO_Port GPIOG
#define D3_DR7_Pin GPIO_PIN_8
#define D3_DR7_GPIO_Port GPIOG
#define D3_EN7_Pin GPIO_PIN_6
#define D3_EN7_GPIO_Port GPIOC
#define D2_DR6_Pin GPIO_PIN_7
#define D2_DR6_GPIO_Port GPIOC
#define D2_EN6_Pin GPIO_PIN_13
#define D2_EN6_GPIO_Port GPIOH
#define D2_DR7_Pin GPIO_PIN_14
#define D2_DR7_GPIO_Port GPIOH
#define D2_EN7_Pin GPIO_PIN_15
#define D2_EN7_GPIO_Port GPIOH
#define D1_DR6_Pin GPIO_PIN_0
#define D1_DR6_GPIO_Port GPIOI
#define D1_EN6_Pin GPIO_PIN_1
#define D1_EN6_GPIO_Port GPIOI
#define D1_DR7_Pin GPIO_PIN_2
#define D1_DR7_GPIO_Port GPIOI
#define D1_EN7_Pin GPIO_PIN_3
#define D1_EN7_GPIO_Port GPIOI
#define D1_DR1_Pin GPIO_PIN_12
#define D1_DR1_GPIO_Port GPIOG
#define D1_EN1_Pin GPIO_PIN_13
#define D1_EN1_GPIO_Port GPIOG
#define D1_DR2_Pin GPIO_PIN_14
#define D1_DR2_GPIO_Port GPIOG
#define D1_EN2_Pin GPIO_PIN_15
#define D1_EN2_GPIO_Port GPIOG
#define D1_DR3_Pin GPIO_PIN_3
#define D1_DR3_GPIO_Port GPIOB
#define D1_EN3_Pin GPIO_PIN_4
#define D1_EN3_GPIO_Port GPIOB
#define D1_DR4_Pin GPIO_PIN_5
#define D1_DR4_GPIO_Port GPIOB
#define D1_EN4_Pin GPIO_PIN_6
#define D1_EN4_GPIO_Port GPIOB
#define D1_DR5_Pin GPIO_PIN_7
#define D1_DR5_GPIO_Port GPIOB
#define D1_EN5_Pin GPIO_PIN_8
#define D1_EN5_GPIO_Port GPIOB
#define D2_DR1_Pin GPIO_PIN_9
#define D2_DR1_GPIO_Port GPIOB
#define D2_EN1_Pin GPIO_PIN_0
#define D2_EN1_GPIO_Port GPIOE
#define D2_DR2_Pin GPIO_PIN_1
#define D2_DR2_GPIO_Port GPIOE
#define D2_EN2_Pin GPIO_PIN_4
#define D2_EN2_GPIO_Port GPIOI
#define D2_DR3_Pin GPIO_PIN_5
#define D2_DR3_GPIO_Port GPIOI
#define D2_EN3_Pin GPIO_PIN_6
#define D2_EN3_GPIO_Port GPIOI
#define D2_DR4_Pin GPIO_PIN_7
#define D2_DR4_GPIO_Port GPIOI

/* USER CODE BEGIN Private defines */
#define PWR_CTRL(n) (n ? HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3, GPIO_PIN_SET) : HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3, GPIO_PIN_RESET));
#define STUS_LED(n) (n ? HAL_GPIO_WritePin(GPIOE, GPIO_PIN_8, GPIO_PIN_SET) : HAL_GPIO_WritePin(GPIOE, GPIO_PIN_8, GPIO_PIN_RESET));
#define STUS_LED_TOGGLE HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_8)
/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
