/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * File Name          : freertos.c
 * Description        : Code for freertos applications
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
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "../../Components/Inc/flipdot_digit.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */
flipdot_digit_typdef *flipdot = NULL;
uint8_t pin1_state = 0;
/* USER CODE END Variables */
/* Definitions for defaultTask */
osThreadId_t defaultTaskHandle;
const osThreadAttr_t defaultTask_attributes = {
  .name = "defaultTask",
  .stack_size = 256 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};
/* Definitions for buttonTask */
osThreadId_t buttonTaskHandle;
const osThreadAttr_t buttonTask_attributes = {
  .name = "buttonTask",
  .stack_size = 1024 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};
/* Definitions for button_queue */
osMessageQueueId_t button_queueHandle;
const osMessageQueueAttr_t button_queue_attributes = {
  .name = "button_queue"
};

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void StartDefaultTask(void *argument);
void button_task(void *argument);

extern void MX_USB_DEVICE_Init(void);
void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* Create the queue(s) */
  /* creation of button_queue */
  button_queueHandle = osMessageQueueNew (16, sizeof(uint16_t), &button_queue_attributes);

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* creation of defaultTask */
  defaultTaskHandle = osThreadNew(StartDefaultTask, NULL, &defaultTask_attributes);

  /* creation of buttonTask */
  buttonTaskHandle = osThreadNew(button_task, NULL, &buttonTask_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_EVENTS */
  /* add events, ... */
  /* USER CODE END RTOS_EVENTS */

}

/* USER CODE BEGIN Header_StartDefaultTask */
/**
 * @brief  Function implementing the defaultTask thread.
 * @param  argument: Not used
 * @retval None
 */
/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void *argument)
{
  /* init code for USB_DEVICE */
  MX_USB_DEVICE_Init();
  /* USER CODE BEGIN StartDefaultTask */
  flipdot_digit_init();
  flipdot = get_flipdot_unit();
  /* Infinite loop */
  for (;;)
  {
    osDelay(1000);
  }
  /* USER CODE END StartDefaultTask */
}

/* USER CODE BEGIN Header_button_task */
/**
 * @brief Function implementing the buttonTask thread.
 * @param argument: Not used
 * @retval None
 */
/* USER CODE END Header_button_task */
void button_task(void *argument)
{
  /* USER CODE BEGIN button_task */
  char value[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
  uint8_t count = 0;
  /* Infinite loop */
  for (;;)
  {
    if (flipdot)
    {
      flipdot->flipdot_show_char(DIGIT_1, value[count]);
      // flipdot->flipdot_show_char(DIGIT_2, 0);
      // flipdot->flipdot_show_char(DIGIT_3, 0);
      // flipdot->flipdot_show_char(DIGIT_4, 0);
      // flipdot->flipdot_show_char(DIGIT_5, 0);
      // flipdot->flipdot_show_char(DIGIT_6, 0);
      count++;
      if (count == 10)
      {
        count = 0;
      }
    }
    pin1_state = HAL_GPIO_ReadPin(PWR_BTN_GPIO_Port, PWR_BTN_Pin);
    STUS_LED_TOGGLE;
    osDelay(1000);
  }
  /* USER CODE END button_task */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
  switch (GPIO_Pin)
  {
  case BTN1_Pin:

    break;
  case BTN2_Pin:

    break;
  case BTN3_Pin:

    break;
  case BTN4_Pin:

    break;
  case PWR_BTN_Pin:

    break;
  }
}
/* USER CODE END Application */

