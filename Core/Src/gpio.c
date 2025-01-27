/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    gpio.c
  * @brief   This file provides code for the configuration
  *          of all used GPIO pins.
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

/* Includes ------------------------------------------------------------------*/
#include "gpio.h"

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/*----------------------------------------------------------------------------*/
/* Configure GPIO                                                             */
/*----------------------------------------------------------------------------*/
/* USER CODE BEGIN 1 */

/* USER CODE END 1 */

/** Configure pins
     PC14-OSC32_IN (OSC32_IN)   ------> RCC_OSC32_IN
     PC15-OSC32_OUT (OSC32_OUT)   ------> RCC_OSC32_OUT
     PH0-OSC_IN (PH0)   ------> RCC_OSC_IN
     PH1-OSC_OUT (PH1)   ------> RCC_OSC_OUT
     PA13 (JTMS/SWDIO)   ------> DEBUG_JTMS-SWDIO
     PA14 (JTCK/SWCLK)   ------> DEBUG_JTCK-SWCLK
*/
void MX_GPIO_Init(void)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOE_CLK_ENABLE();
  __HAL_RCC_GPIOI_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOF_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOG_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOE, PWR_CTRL_Pin|D2_EN4_Pin|D2_DR5_Pin|INDEX_LED_Pin
                          |D2_EN1_Pin|D2_DR2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOI, D2_EN5_Pin|D3_EN1_Pin|D3_DR2_Pin|D3_EN2_Pin
                          |D1_DR6_Pin|D1_EN6_Pin|D1_DR7_Pin|D1_EN7_Pin
                          |D2_EN2_Pin|D2_DR3_Pin|D2_EN3_Pin|D2_DR4_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, D3_DR1_Pin|D4_EN3_Pin|D4_DR4_Pin|D4_EN4_Pin
                          |D4_DR5_Pin|D6_DR1_Pin|D6_EN1_Pin|D3_EN7_Pin
                          |D2_DR6_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOF, D3_DR3_Pin|D3_EN3_Pin|D3_DR4_Pin|D3_EN4_Pin
                          |D3_DR5_Pin|D3_EN5_Pin|D4_DR1_Pin|D4_EN1_Pin
                          |D4_DR2_Pin|D4_EN2_Pin|D4_DR3_Pin|D6_EN3_Pin
                          |D6_DR4_Pin|D6_EN4_Pin|D6_DR5_Pin|D6_EN5_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, D4_EN5_Pin|D5_DR1_Pin|D5_EN1_Pin|D5_DR4_Pin
                          |D5_EN4_Pin|D5_DR5_Pin|D5_EN5_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOH, D5_DR2_Pin|D5_EN2_Pin|D5_DR3_Pin|D5_EN3_Pin
                          |D6_DR6_Pin|D6_EN6_Pin|D2_EN6_Pin|D2_DR7_Pin
                          |D2_EN7_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, D6_DR2_Pin|D6_EN2_Pin|D6_DR3_Pin|D6_DR7_Pin
                          |D6_EN7_Pin|D5_DR6_Pin|D5_EN6_Pin|D1_DR3_Pin
                          |D1_EN3_Pin|D1_DR4_Pin|D1_EN4_Pin|D1_DR5_Pin
                          |D1_EN5_Pin|D2_DR1_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOG, BEEP_Pin|D3_DR6_Pin|D3_EN6_Pin|D3_DR7_Pin
                          |D1_DR1_Pin|D1_EN1_Pin|D1_DR2_Pin|D1_EN2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOD, D5_DR7_Pin|D5_EN7_Pin|D4_DR6_Pin|D4_EN6_Pin
                          |D4_DR7_Pin|D4_EN7_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : PWR_BTN_Pin BTN1_Pin BTN3_Pin BTN4_Pin */
  GPIO_InitStruct.Pin = PWR_BTN_Pin|BTN1_Pin|BTN3_Pin|BTN4_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

  /*Configure GPIO pins : PWR_CTRL_Pin D2_EN4_Pin D2_DR5_Pin INDEX_LED_Pin
                           D2_EN1_Pin D2_DR2_Pin */
  GPIO_InitStruct.Pin = PWR_CTRL_Pin|D2_EN4_Pin|D2_DR5_Pin|INDEX_LED_Pin
                          |D2_EN1_Pin|D2_DR2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

  /*Configure GPIO pins : D2_EN5_Pin D3_EN1_Pin D3_DR2_Pin D3_EN2_Pin
                           D1_DR6_Pin D1_EN6_Pin D1_DR7_Pin D1_EN7_Pin
                           D2_EN2_Pin D2_DR3_Pin D2_EN3_Pin D2_DR4_Pin */
  GPIO_InitStruct.Pin = D2_EN5_Pin|D3_EN1_Pin|D3_DR2_Pin|D3_EN2_Pin
                          |D1_DR6_Pin|D1_EN6_Pin|D1_DR7_Pin|D1_EN7_Pin
                          |D2_EN2_Pin|D2_DR3_Pin|D2_EN3_Pin|D2_DR4_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOI, &GPIO_InitStruct);

  /*Configure GPIO pins : D3_DR1_Pin D4_EN3_Pin D4_DR4_Pin D4_EN4_Pin
                           D4_DR5_Pin D6_DR1_Pin D6_EN1_Pin D3_EN7_Pin
                           D2_DR6_Pin */
  GPIO_InitStruct.Pin = D3_DR1_Pin|D4_EN3_Pin|D4_DR4_Pin|D4_EN4_Pin
                          |D4_DR5_Pin|D6_DR1_Pin|D6_EN1_Pin|D3_EN7_Pin
                          |D2_DR6_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : D3_DR3_Pin D3_EN3_Pin D3_DR4_Pin D3_EN4_Pin
                           D3_DR5_Pin D3_EN5_Pin D4_DR1_Pin D4_EN1_Pin
                           D4_DR2_Pin D4_EN2_Pin D4_DR3_Pin D6_EN3_Pin
                           D6_DR4_Pin D6_EN4_Pin D6_DR5_Pin D6_EN5_Pin */
  GPIO_InitStruct.Pin = D3_DR3_Pin|D3_EN3_Pin|D3_DR4_Pin|D3_EN4_Pin
                          |D3_DR5_Pin|D3_EN5_Pin|D4_DR1_Pin|D4_EN1_Pin
                          |D4_DR2_Pin|D4_EN2_Pin|D4_DR3_Pin|D6_EN3_Pin
                          |D6_DR4_Pin|D6_EN4_Pin|D6_DR5_Pin|D6_EN5_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOF, &GPIO_InitStruct);

  /*Configure GPIO pins : D4_EN5_Pin D5_DR1_Pin D5_EN1_Pin D5_DR4_Pin
                           D5_EN4_Pin D5_DR5_Pin D5_EN5_Pin */
  GPIO_InitStruct.Pin = D4_EN5_Pin|D5_DR1_Pin|D5_EN1_Pin|D5_DR4_Pin
                          |D5_EN4_Pin|D5_DR5_Pin|D5_EN5_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : D5_DR2_Pin D5_EN2_Pin D5_DR3_Pin D5_EN3_Pin
                           D6_DR6_Pin D6_EN6_Pin D2_EN6_Pin D2_DR7_Pin
                           D2_EN7_Pin */
  GPIO_InitStruct.Pin = D5_DR2_Pin|D5_EN2_Pin|D5_DR3_Pin|D5_EN3_Pin
                          |D6_DR6_Pin|D6_EN6_Pin|D2_EN6_Pin|D2_DR7_Pin
                          |D2_EN7_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOH, &GPIO_InitStruct);

  /*Configure GPIO pins : D6_DR2_Pin D6_EN2_Pin D6_DR3_Pin D6_DR7_Pin
                           D6_EN7_Pin D5_DR6_Pin D5_EN6_Pin D1_DR3_Pin
                           D1_EN3_Pin D1_DR4_Pin D1_EN4_Pin D1_DR5_Pin
                           D1_EN5_Pin D2_DR1_Pin */
  GPIO_InitStruct.Pin = D6_DR2_Pin|D6_EN2_Pin|D6_DR3_Pin|D6_DR7_Pin
                          |D6_EN7_Pin|D5_DR6_Pin|D5_EN6_Pin|D1_DR3_Pin
                          |D1_EN3_Pin|D1_DR4_Pin|D1_EN4_Pin|D1_DR5_Pin
                          |D1_EN5_Pin|D2_DR1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : BEEP_Pin D3_DR6_Pin D3_EN6_Pin D3_DR7_Pin
                           D1_DR1_Pin D1_EN1_Pin D1_DR2_Pin D1_EN2_Pin */
  GPIO_InitStruct.Pin = BEEP_Pin|D3_DR6_Pin|D3_EN6_Pin|D3_DR7_Pin
                          |D1_DR1_Pin|D1_EN1_Pin|D1_DR2_Pin|D1_EN2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOG, &GPIO_InitStruct);

  /*Configure GPIO pins : D5_DR7_Pin D5_EN7_Pin D4_DR6_Pin D4_EN6_Pin
                           D4_DR7_Pin D4_EN7_Pin */
  GPIO_InitStruct.Pin = D5_DR7_Pin|D5_EN7_Pin|D4_DR6_Pin|D4_EN6_Pin
                          |D4_DR7_Pin|D4_EN7_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI2_IRQn, 5, 0);
  HAL_NVIC_EnableIRQ(EXTI2_IRQn);

  HAL_NVIC_SetPriority(EXTI15_10_IRQn, 5, 0);
  HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);

}

/* USER CODE BEGIN 2 */

/* USER CODE END 2 */
