#include "../Inc/flipdot_digit.h"
#include "../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2/cmsis_os.h"

static user_gpio_typedef *user_gpio = NULL;

static void flipdot_show_char(uint8_t digit, char chr);
static void flipdot_show_string(uint8_t *str);
static void unit_io_set_state(uint8_t digit, uint8_t digit_pin, uint8_t state);
static void unit_set_all_en(uint8_t digit, uint8_t state);

osThreadId_t resetIOTaskHandle;
const osThreadAttr_t resetIOTask_attributes = {
    .name = "resetIOTask",
    .stack_size = 256 * 4,
    .priority = (osPriority_t)osPriorityNormal,
};

osMessageQueueId_t io_reset_queueHandle;
const osMessageQueueAttr_t io_reset_queue_attributes = {
    .name = "io_reset_queue"};

void gpio_reset_task(void *parameter);

flipdot_digit_typdef flipdot_unit = {
    .flipdot_show_char = flipdot_show_char,
    .flipdot_show_string = flipdot_show_string};

void flipdot_digit_init(void)
{
    user_gpio = get_user_gpio();
    // resetIOTaskHandle = osThreadNew(gpio_reset_task, NULL, &resetIOTask_attributes);
    // io_reset_queueHandle = osMessageQueueNew(5, sizeof(uint8_t) * 10, &io_reset_queue_attributes);
}

static void flipdot_show_char(uint8_t digit, char character)
{
    // if (character == 'A')
    // {
    //     // show
    //     unit_io_set_state(digit, 1, 1);
    //     unit_io_set_state(digit, 2, 1);
    //     unit_io_set_state(digit, 3, 1);
    //     unit_io_set_state(digit, 4, 1);
    //     unit_io_set_state(digit, 5, 1);
    //     unit_io_set_state(digit, 6, 1);
    //     // hide
    //     unit_io_set_state(digit, 7, 0);
    // }
    // else if (character == 'B')
    // {
    //     // show
    //     unit_io_set_state(digit, 2, 1);
    //     unit_io_set_state(digit, 4, 1);
    //     unit_io_set_state(digit, 5, 1);
    //     unit_io_set_state(digit, 6, 1);
    //     unit_io_set_state(digit, 7, 1);
    //     // hide
    //     unit_io_set_state(digit, 1, 0);
    //     unit_io_set_state(digit, 3, 0);
    // }
    // else if (character == 'C')
    // {
    //     // show
    //     unit_io_set_state(digit, 1, 1);
    //     unit_io_set_state(digit, 2, 1);
    //     unit_io_set_state(digit, 5, 1);
    //     unit_io_set_state(digit, 7, 1);
    //     // hide
    //     unit_io_set_state(digit, 3, 0);
    //     unit_io_set_state(digit, 4, 0);
    //     unit_io_set_state(digit, 6, 0);
    // }
    // else if (character == 'D')
    // {
    //     // show
    //     unit_io_set_state(digit, 3, 1);
    //     unit_io_set_state(digit, 4, 1);
    //     unit_io_set_state(digit, 5, 1);
    //     unit_io_set_state(digit, 6, 1);
    //     unit_io_set_state(digit, 7, 1);
    //     // hide
    //     unit_io_set_state(digit, 1, 0);
    //     unit_io_set_state(digit, 2, 0);
    // }
    // else if (character == 'E')
    // {
    //     // show
    //     unit_io_set_state(digit, 1, 1);
    //     unit_io_set_state(digit, 2, 1);
    //     unit_io_set_state(digit, 4, 1);
    //     unit_io_set_state(digit, 5, 1);
    //     unit_io_set_state(digit, 7, 1);
    //     // hide
    //     unit_io_set_state(digit, 3, 0);
    //     unit_io_set_state(digit, 6, 0);
    // }
    // else if (character == 'F')
    // {
    //     // show
    //     unit_io_set_state(digit, 1, 1);
    //     unit_io_set_state(digit, 2, 1);
    //     unit_io_set_state(digit, 4, 1);
    //     unit_io_set_state(digit, 5, 1);
    //     // hide
    //     unit_io_set_state(digit, 3, 0);
    //     unit_io_set_state(digit, 6, 0);
    //     unit_io_set_state(digit, 7, 0);
    // }
    // else if (character == 'G')
    // {
    //     // show
    //     unit_io_set_state(digit, 1, 1);
    //     unit_io_set_state(digit, 2, 1);
    //     unit_io_set_state(digit, 5, 1);
    //     unit_io_set_state(digit, 6, 1);
    //     unit_io_set_state(digit, 7, 1);
    //     // hide
    //     unit_io_set_state(digit, 3, 0);
    //     unit_io_set_state(digit, 4, 0);
    // }
    // else if (character == 'H')
    // {
    //     // show
    //     unit_io_set_state(digit, 2, 1);
    //     unit_io_set_state(digit, 3, 1);
    //     unit_io_set_state(digit, 4, 1);
    //     unit_io_set_state(digit, 5, 1);
    //     unit_io_set_state(digit, 6, 1);
    //     // hide
    //     unit_io_set_state(digit, 1, 0);
    //     unit_io_set_state(digit, 7, 0);
    // }
    // else if (character == 'I')
    // {
    //     // show
    //     unit_io_set_state(digit, 5, 1);
    //     // hide
    //     unit_io_set_state(digit, 1, 0);
    //     unit_io_set_state(digit, 2, 0);
    //     unit_io_set_state(digit, 3, 0);
    //     unit_io_set_state(digit, 4, 0);
    //     unit_io_set_state(digit, 6, 0);
    //     unit_io_set_state(digit, 7, 0);
    // }
    // else if (character == 'J')
    // {
    //     // show
    //     unit_io_set_state(digit, 3, 1);
    //     unit_io_set_state(digit, 5, 1);
    //     unit_io_set_state(digit, 6, 1);
    //     unit_io_set_state(digit, 5, 1);
    //     // hide
    //     unit_io_set_state(digit, 1, 0);
    //     unit_io_set_state(digit, 2, 0);
    //     unit_io_set_state(digit, 4, 0);
    // }
    // else if (character == 'K')
    // {
    //     // show
    //     unit_io_set_state(digit, 2, 1);
    //     unit_io_set_state(digit, 3, 1);
    //     unit_io_set_state(digit, 4, 1);
    //     unit_io_set_state(digit, 5, 1);
    //     unit_io_set_state(digit, 7, 1);
    //     // hide
    //     unit_io_set_state(digit, 1, 0);
    //     unit_io_set_state(digit, 6, 0);
    // }
    // else if (character == 'L')
    // {
    //     // show
    //     unit_io_set_state(digit, 2, 1);
    //     unit_io_set_state(digit, 5, 1);
    //     unit_io_set_state(digit, 7, 1);
    //     // hide
    //     unit_io_set_state(digit, 1, 0);
    //     unit_io_set_state(digit, 3, 0);
    //     unit_io_set_state(digit, 4, 0);
    //     unit_io_set_state(digit, 6, 0);
    // }
    // else if (character == 'M')
    // {
    //     // show
    //     unit_io_set_state(digit, 1, 1);
    //     unit_io_set_state(digit, 4, 1);
    //     unit_io_set_state(digit, 5, 1);
    //     unit_io_set_state(digit, 6, 1);
    //     // hide
    //     unit_io_set_state(digit, 2, 0);
    //     unit_io_set_state(digit, 3, 0);
    //     unit_io_set_state(digit, 7, 0);
    // }
    // else if (character == 'N')
    // {
    //     // show
    //     unit_io_set_state(digit, 4, 1);
    //     unit_io_set_state(digit, 5, 1);
    //     unit_io_set_state(digit, 6, 1);
    //     // hide
    //     unit_io_set_state(digit, 1, 0);
    //     unit_io_set_state(digit, 2, 0);
    //     unit_io_set_state(digit, 3, 0);
    //     unit_io_set_state(digit, 7, 0);
    // }
    // else if (character == 'O')
    // {
    //     // show
    //     unit_io_set_state(digit, 4, 1);
    //     unit_io_set_state(digit, 5, 1);
    //     unit_io_set_state(digit, 6, 1);
    //     unit_io_set_state(digit, 7, 1);
    //     // hide
    //     unit_io_set_state(digit, 1, 0);
    //     unit_io_set_state(digit, 2, 0);
    //     unit_io_set_state(digit, 3, 0);
    // }
    // else if (character == 'P')
    // {
    //     // show
    //     unit_io_set_state(digit, 1, 1);
    //     unit_io_set_state(digit, 2, 1);
    //     unit_io_set_state(digit, 3, 1);
    //     unit_io_set_state(digit, 4, 1);
    //     unit_io_set_state(digit, 5, 1);
    //     // hide
    //     unit_io_set_state(digit, 6, 0);
    //     unit_io_set_state(digit, 7, 0);
    // }
    // else if (character == 'Q')
    // {
    //     // show
    //     unit_io_set_state(digit, 1, 1);
    //     unit_io_set_state(digit, 2, 1);
    //     unit_io_set_state(digit, 3, 1);
    //     unit_io_set_state(digit, 4, 1);
    //     unit_io_set_state(digit, 6, 1);
    //     // hide
    //     unit_io_set_state(digit, 5, 0);
    //     unit_io_set_state(digit, 7, 0);
    // }
    // else if (character == 'R')
    // {
    //     // show
    //     unit_io_set_state(digit, 4, 1);
    //     unit_io_set_state(digit, 5, 1);
    //     // hide
    //     unit_io_set_state(digit, 1, 0);
    //     unit_io_set_state(digit, 2, 0);
    //     unit_io_set_state(digit, 3, 0);
    //     unit_io_set_state(digit, 6, 0);
    //     unit_io_set_state(digit, 7, 0);
    // }
    // else if (character == 'S')
    // {
    //     // show
    //     unit_io_set_state(digit, 1, 1);
    //     unit_io_set_state(digit, 2, 1);
    //     unit_io_set_state(digit, 4, 1);
    //     unit_io_set_state(digit, 6, 1);
    //     // hide
    //     unit_io_set_state(digit, 3, 0);
    //     unit_io_set_state(digit, 5, 0);
    //     unit_io_set_state(digit, 7, 0);
    // }
    // else if (character == 'T')
    // {
    //     // show
    //     unit_io_set_state(digit, 2, 1);
    //     unit_io_set_state(digit, 4, 1);
    //     unit_io_set_state(digit, 5, 1);
    //     unit_io_set_state(digit, 7, 1);
    //     // hide
    //     unit_io_set_state(digit, 1, 0);
    //     unit_io_set_state(digit, 3, 0);
    //     unit_io_set_state(digit, 6, 0);
    // }
    // else if (character == 'U')
    // {
    //     // show
    //     unit_io_set_state(digit, 2, 1);
    //     unit_io_set_state(digit, 3, 1);
    //     unit_io_set_state(digit, 5, 1);
    //     unit_io_set_state(digit, 6, 1);
    //     unit_io_set_state(digit, 7, 1);
    //     // hide
    //     unit_io_set_state(digit, 1, 0);
    //     unit_io_set_state(digit, 4, 0);
    // }
    // else if (character == 'V')
    // {
    //     // show
    //     unit_io_set_state(digit, 2, 1);
    //     unit_io_set_state(digit, 3, 1);
    //     unit_io_set_state(digit, 4, 1);
    //     unit_io_set_state(digit, 5, 1);
    //     unit_io_set_state(digit, 6, 1);
    //     unit_io_set_state(digit, 7, 1);
    //     // hide
    //     unit_io_set_state(digit, 1, 0);
    // }
    // else if (character == 'W')
    // {
    //     // show
    //     unit_io_set_state(digit, 1, 1);
    //     unit_io_set_state(digit, 5, 1);
    //     unit_io_set_state(digit, 6, 1);
    //     unit_io_set_state(digit, 7, 1);
    //     // hide
    //     unit_io_set_state(digit, 2, 0);
    //     unit_io_set_state(digit, 3, 0);
    //     unit_io_set_state(digit, 4, 0);
    // }
    // else if (character == 'X')
    // {
    //     // show
    //     unit_io_set_state(digit, 2, 1);
    //     unit_io_set_state(digit, 3, 1);
    //     unit_io_set_state(digit, 4, 1);
    //     unit_io_set_state(digit, 7, 1);
    //     // hide
    //     unit_io_set_state(digit, 1, 0);
    //     unit_io_set_state(digit, 5, 0);
    //     unit_io_set_state(digit, 6, 0);
    // }
    // else if (character == 'Y')
    // {
    //     // show
    //     unit_io_set_state(digit, 2, 1);
    //     unit_io_set_state(digit, 3, 1);
    //     unit_io_set_state(digit, 4, 1);
    //     unit_io_set_state(digit, 6, 1);
    //     unit_io_set_state(digit, 7, 1);
    //     // hide
    //     unit_io_set_state(digit, 1, 0);
    //     unit_io_set_state(digit, 5, 0);
    // }
    // else if (character == 'Z')
    // {
    //     // show
    //     unit_io_set_state(digit, 1, 1);
    //     unit_io_set_state(digit, 4, 1);
    //     unit_io_set_state(digit, 7, 1);
    //     // hide
    //     unit_io_set_state(digit, 2, 0);
    //     unit_io_set_state(digit, 3, 0);
    //     unit_io_set_state(digit, 5, 0);
    //     unit_io_set_state(digit, 6, 0);
    // }
    // else if (character == '-')
    // {
    //     // show
    //     unit_io_set_state(digit, 4, 1);
    //     // hide
    //     unit_io_set_state(digit, 1, 0);
    //     unit_io_set_state(digit, 2, 0);
    //     unit_io_set_state(digit, 3, 0);
    //     unit_io_set_state(digit, 5, 0);
    //     unit_io_set_state(digit, 6, 0);
    //     unit_io_set_state(digit, 7, 0);
    // }
    // else if (character == ' ')
    // {
    //     // hide
    //     unit_io_set_state(digit, 1, 0);
    //     unit_io_set_state(digit, 2, 0);
    //     unit_io_set_state(digit, 3, 0);
    //     unit_io_set_state(digit, 4, 0);
    //     unit_io_set_state(digit, 5, 0);
    //     unit_io_set_state(digit, 6, 0);
    //     unit_io_set_state(digit, 7, 0);
    // }
    // else if (character == '0')
    // {
    //     // show
    //     unit_io_set_state(digit, 1, 1);
    //     unit_io_set_state(digit, 2, 1);
    //     unit_io_set_state(digit, 3, 1);
    //     unit_io_set_state(digit, 5, 1);
    //     unit_io_set_state(digit, 6, 1);
    //     unit_io_set_state(digit, 7, 1);
    //     // hide
    //     unit_io_set_state(digit, 4, 0);
    // }
    // else if (character == '1')
    // {
    //     unit_io_set_state(digit, 1, 0);
    //     unit_io_set_state(digit, 2, 0);
    //     unit_io_set_state(digit, 3, 1);
    //     unit_io_set_state(digit, 4, 0);
    //     unit_io_set_state(digit, 5, 0);
    //     unit_io_set_state(digit, 6, 1);
    //     unit_io_set_state(digit, 7, 0);
    // }
    // else if (character == '2')
    // {
    //     unit_io_set_state(digit, 1, 1);
    //     unit_io_set_state(digit, 2, 0);
    //     unit_io_set_state(digit, 3, 1);
    //     unit_io_set_state(digit, 4, 1);
    //     unit_io_set_state(digit, 5, 1);
    //     unit_io_set_state(digit, 6, 0);
    //     unit_io_set_state(digit, 7, 1);
    // }
    // else if (character == '3')
    // {
    //     unit_io_set_state(digit, 1, 1);
    //     unit_io_set_state(digit, 2, 0);
    //     unit_io_set_state(digit, 3, 1);
    //     unit_io_set_state(digit, 4, 1);
    //     unit_io_set_state(digit, 5, 0);
    //     unit_io_set_state(digit, 6, 1);
    //     unit_io_set_state(digit, 7, 1);
    // }
    // else if (character == '4')
    // {
    //     unit_io_set_state(digit, 1, 0);
    //     unit_io_set_state(digit, 2, 1);
    //     unit_io_set_state(digit, 3, 1);
    //     unit_io_set_state(digit, 4, 1);
    //     unit_io_set_state(digit, 6, 1);
    //     unit_io_set_state(digit, 5, 0);
    //     unit_io_set_state(digit, 7, 0);
    // }
    // else if (character == '5')
    // {
    //     unit_io_set_state(digit, 1, 1);
    //     unit_io_set_state(digit, 2, 1);
    //     unit_io_set_state(digit, 3, 0);
    //     unit_io_set_state(digit, 4, 1);
    //     unit_io_set_state(digit, 5, 0);
    //     unit_io_set_state(digit, 6, 1);
    //     unit_io_set_state(digit, 7, 1);
    // }
    // else if (character == '6')
    // {
    //     unit_io_set_state(digit, 1, 1);
    //     unit_io_set_state(digit, 2, 1);
    //     unit_io_set_state(digit, 3, 0);
    //     unit_io_set_state(digit, 4, 1);
    //     unit_io_set_state(digit, 5, 1);
    //     unit_io_set_state(digit, 6, 1);
    //     unit_io_set_state(digit, 7, 1);
    // }
    // else if (character == '7')
    // {
    //     unit_io_set_state(digit, 1, 1);
    //     unit_io_set_state(digit, 2, 0);
    //     unit_io_set_state(digit, 3, 1);
    //     unit_io_set_state(digit, 4, 0);
    //     unit_io_set_state(digit, 5, 0);
    //     unit_io_set_state(digit, 6, 1);
    //     unit_io_set_state(digit, 7, 0);
    // }
    // else if (character == '8')
    // {
    //     unit_io_set_state(digit, 1, 1);
    //     unit_io_set_state(digit, 2, 1);
    //     unit_io_set_state(digit, 3, 1);
    //     unit_io_set_state(digit, 4, 1);
    //     unit_io_set_state(digit, 5, 1);
    //     unit_io_set_state(digit, 6, 1);
    //     unit_io_set_state(digit, 7, 1);
    // }
    // else if (character == '9')
    // {
    //     unit_io_set_state(digit, 1, 1);
    //     unit_io_set_state(digit, 2, 1);
    //     unit_io_set_state(digit, 3, 1);
    //     unit_io_set_state(digit, 4, 1);
    //     unit_io_set_state(digit, 5, 0);
    //     unit_io_set_state(digit, 6, 1);
    //     unit_io_set_state(digit, 7, 1);
    // }
    // else
    // {
    //     unit_io_set_state(digit, 1, 0);
    //     unit_io_set_state(digit, 2, 0);
    //     unit_io_set_state(digit, 3, 0);
    //     unit_io_set_state(digit, 4, 0);
    //     unit_io_set_state(digit, 5, 0);
    //     unit_io_set_state(digit, 6, 0);
    //     unit_io_set_state(digit, 7, 0);
    // }

    unit_io_set_state(digit, 1, 1);
    unit_io_set_state(digit, 2, 0);
    unit_io_set_state(digit, 3, 0);
    unit_io_set_state(digit, 4, 0);
    unit_io_set_state(digit, 5, 0);
    unit_io_set_state(digit, 6, 0);
    unit_io_set_state(digit, 7, 0);

    unit_set_all_en(digit, GPIO_PIN_SET);
    osDelay(100);
    unit_set_all_en(digit, GPIO_PIN_RESET);
}

static void flipdot_show_string(uint8_t *str)
{
    flipdot_show_char(DIGIT_1, str[0]);
    flipdot_show_char(DIGIT_2, str[1]);
    flipdot_show_char(DIGIT_3, str[2]);
    flipdot_show_char(DIGIT_4, str[3]);
    flipdot_show_char(DIGIT_5, str[4]);
    flipdot_show_char(DIGIT_6, str[5]);
}

void gpio_reset_task(void *parameter)
{
    uint8_t queue_msg[10];

    while (1)
    {

        if (osMessageQueueGet(io_reset_queueHandle, queue_msg, NULL, osWaitForever) == osOK)
        {
            osDelay(100);
            user_gpio->set_en_pin(queue_msg[0], queue_msg[1], GPIO_PIN_RESET);
        }
    }
}

static void unit_io_set_state(uint8_t digit, uint8_t digit_pin, uint8_t state)
{
    // EN
    // user_gpio->set_en_pin(digit, digit_pin, GPIO_PIN_SET);
    // DR
    if (state == 0)
    {
        user_gpio->set_driver_pin(digit, digit_pin, GPIO_PIN_RESET);
    }
    else if (state == 1)
    {
        user_gpio->set_driver_pin(digit, digit_pin, GPIO_PIN_SET);
    }

    // 回復EN狀態，設為reset
    // uint8_t pin_info[10] = {0};
    // pin_info[0] = digit;
    // pin_info[1] = digit_pin;
    // osMessageQueuePut(io_reset_queueHandle, pin_info, NULL, osWaitForever);
    // xTaskCreate(gpio_reset_task, "GPIO_RESET_Task", 256 * 4, pin_info, 1, NULL);
    // osDelay(30);
    // user_gpio->set_en_pin(digit, digit_pin, GPIO_PIN_RESET);
}

static void unit_set_all_en(uint8_t digit, uint8_t state)
{
    for (int i = 0; i < 7; i++)
    {
        user_gpio->set_en_pin(digit, i + 1, state);
    }
}

flipdot_digit_typdef *get_flipdot_unit(void)
{
    return &flipdot_unit;
}