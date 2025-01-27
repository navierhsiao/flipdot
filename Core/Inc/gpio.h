/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file    gpio.h
 * @brief   This file contains all the function prototypes for
 *          the gpio.c file
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
#ifndef __GPIO_H__
#define __GPIO_H__

#ifdef __cplusplus
extern "C"
{
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

  /* USER CODE BEGIN Includes */

  /* USER CODE END Includes */

  /* USER CODE BEGIN Private defines */

  typedef struct
  {
    GPIO_TypeDef *gpio[7];
    uint16_t pin[7];
  } digit_pin_typedef;

  typedef struct
  {
    digit_pin_typedef driver_pin[6];
    digit_pin_typedef en_pin[6];
    void (*set_driver_pin)(uint8_t digit, uint8_t pin_number, uint8_t state);
    void (*set_en_pin)(uint8_t digit, uint8_t pin_number, uint8_t state);
    void (*reset_all)(void);
  } user_gpio_typedef;

  typedef enum
  {
    DIGIT_1,
    DIGIT_2,
    DIGIT_3,
    DIGIT_4,
    DIGIT_5,
    DIGIT_6
  } digit_def;
  /* USER CODE END Private defines */

  void MX_GPIO_Init(void);

  /* USER CODE BEGIN Prototypes */
  user_gpio_typedef *get_user_gpio(void);
  /* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif
#endif /*__ GPIO_H__ */
