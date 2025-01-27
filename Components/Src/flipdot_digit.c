#include "../Inc/flipdot_digit.h"
#include "../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2/cmsis_os.h"

static user_gpio_typedef *user_gpio = NULL;

static void flipdot_show_char(uint8_t digit, char chr);
static void flipdot_show_string(uint8_t *str);
static void unit_io_set_state(uint8_t digit, uint8_t digit_pin, uint8_t state);

flipdot_digit_typdef flipdot_unit = {
    .flipdot_show_char = flipdot_show_char,
    .flipdot_show_string = flipdot_show_string};

void flipdot_digit_init(void)
{
    user_gpio = get_user_gpio();
}

static void flipdot_show_char(uint8_t digit, char character)
{
    if (character == 'A')
    {
        // show
        unit_io_set_state(digit, 1, 1);
        unit_io_set_state(digit, 2, 1);
        unit_io_set_state(digit, 3, 1);
        unit_io_set_state(digit, 4, 1);
        unit_io_set_state(digit, 5, 1);
        unit_io_set_state(digit, 6, 1);
        // hide
        unit_io_set_state(digit, 7, 0);
    }
    else if (character == 'B')
    {
        // show
        unit_io_set_state(digit, 2, 1);
        unit_io_set_state(digit, 4, 1);
        unit_io_set_state(digit, 5, 1);
        unit_io_set_state(digit, 6, 1);
        unit_io_set_state(digit, 7, 1);
        // hide
        unit_io_set_state(digit, 1, 0);
        unit_io_set_state(digit, 3, 0);
    }
    else if (character == 'C')
    {
        // show
        unit_io_set_state(digit, 1, 1);
        unit_io_set_state(digit, 2, 1);
        unit_io_set_state(digit, 5, 1);
        unit_io_set_state(digit, 7, 1);
        // hide
        unit_io_set_state(digit, 3, 0);
        unit_io_set_state(digit, 4, 0);
        unit_io_set_state(digit, 6, 0);
    }
    else if (character == 'D')
    {
        // show
        unit_io_set_state(digit, 3, 1);
        unit_io_set_state(digit, 4, 1);
        unit_io_set_state(digit, 5, 1);
        unit_io_set_state(digit, 6, 1);
        unit_io_set_state(digit, 7, 1);
        // hide
        unit_io_set_state(digit, 1, 0);
        unit_io_set_state(digit, 2, 0);
    }
    else if (character == 'E')
    {
        // show
        unit_io_set_state(digit, 1, 1);
        unit_io_set_state(digit, 2, 1);
        unit_io_set_state(digit, 4, 1);
        unit_io_set_state(digit, 5, 1);
        unit_io_set_state(digit, 7, 1);
        // hide
        unit_io_set_state(digit, 3, 0);
        unit_io_set_state(digit, 6, 0);
    }
    else if (character == 'F')
    {
        // show
        unit_io_set_state(digit, 1, 1);
        unit_io_set_state(digit, 2, 1);
        unit_io_set_state(digit, 4, 1);
        unit_io_set_state(digit, 5, 1);
        // hide
        unit_io_set_state(digit, 3, 0);
        unit_io_set_state(digit, 6, 0);
        unit_io_set_state(digit, 7, 0);
    }
    else if (character == 'G')
    {
        // show
        unit_io_set_state(digit, 1, 1);
        unit_io_set_state(digit, 2, 1);
        unit_io_set_state(digit, 5, 1);
        unit_io_set_state(digit, 6, 1);
        unit_io_set_state(digit, 7, 1);
        // hide
        unit_io_set_state(digit, 3, 0);
        unit_io_set_state(digit, 4, 0);
    }
    else if (character == 'H')
    {
        // show
        unit_io_set_state(digit, 2, 1);
        unit_io_set_state(digit, 3, 1);
        unit_io_set_state(digit, 4, 1);
        unit_io_set_state(digit, 5, 1);
        unit_io_set_state(digit, 6, 1);
        // hide
        unit_io_set_state(digit, 1, 0);
        unit_io_set_state(digit, 7, 0);
    }
    else if (character == 'I')
    {
        // show
        unit_io_set_state(digit, 5, 1);
        // hide
        unit_io_set_state(digit, 1, 0);
        unit_io_set_state(digit, 2, 0);
        unit_io_set_state(digit, 3, 0);
        unit_io_set_state(digit, 4, 0);
        unit_io_set_state(digit, 6, 0);
        unit_io_set_state(digit, 7, 0);
    }
    else if (character == 'J')
    {
        // show
        unit_io_set_state(digit, 3, 1);
        unit_io_set_state(digit, 5, 1);
        unit_io_set_state(digit, 6, 1);
        unit_io_set_state(digit, 5, 1);
        // hide
        unit_io_set_state(digit, 1, 0);
        unit_io_set_state(digit, 2, 0);
        unit_io_set_state(digit, 4, 0);
    }
    else if (character == 'K')
    {
        // show
        unit_io_set_state(digit, 2, 1);
        unit_io_set_state(digit, 3, 1);
        unit_io_set_state(digit, 4, 1);
        unit_io_set_state(digit, 5, 1);
        unit_io_set_state(digit, 7, 1);
        // hide
        unit_io_set_state(digit, 1, 0);
        unit_io_set_state(digit, 6, 0);
    }
    else if (character == 'L')
    {
        // show
        unit_io_set_state(digit, 2, 1);
        unit_io_set_state(digit, 5, 1);
        unit_io_set_state(digit, 7, 1);
        // hide
        unit_io_set_state(digit, 1, 0);
        unit_io_set_state(digit, 3, 0);
        unit_io_set_state(digit, 4, 0);
        unit_io_set_state(digit, 6, 0);
    }
    else if (character == 'M')
    {
        // show
        unit_io_set_state(digit, 1, 1);
        unit_io_set_state(digit, 4, 1);
        unit_io_set_state(digit, 5, 1);
        unit_io_set_state(digit, 6, 1);
        // hide
        unit_io_set_state(digit, 2, 0);
        unit_io_set_state(digit, 3, 0);
        unit_io_set_state(digit, 7, 0);
    }
    else if (character == 'N')
    {
        // show
        unit_io_set_state(digit, 4, 1);
        unit_io_set_state(digit, 5, 1);
        unit_io_set_state(digit, 6, 1);
        // hide
        unit_io_set_state(digit, 1, 0);
        unit_io_set_state(digit, 2, 0);
        unit_io_set_state(digit, 3, 0);
        unit_io_set_state(digit, 7, 0);
    }
    else if (character == 'O')
    {
        // show
        unit_io_set_state(digit, 4, 1);
        unit_io_set_state(digit, 5, 1);
        unit_io_set_state(digit, 6, 1);
        unit_io_set_state(digit, 7, 1);
        // hide
        unit_io_set_state(digit, 1, 0);
        unit_io_set_state(digit, 2, 0);
        unit_io_set_state(digit, 3, 0);
    }
    else if (character == 'P')
    {
        // show
        unit_io_set_state(digit, 1, 1);
        unit_io_set_state(digit, 2, 1);
        unit_io_set_state(digit, 3, 1);
        unit_io_set_state(digit, 4, 1);
        unit_io_set_state(digit, 5, 1);
        // hide
        unit_io_set_state(digit, 6, 0);
        unit_io_set_state(digit, 7, 0);
    }
    else if (character == 'Q')
    {
        // show
        unit_io_set_state(digit, 1, 1);
        unit_io_set_state(digit, 2, 1);
        unit_io_set_state(digit, 3, 1);
        unit_io_set_state(digit, 4, 1);
        unit_io_set_state(digit, 6, 1);
        // hide
        unit_io_set_state(digit, 5, 0);
        unit_io_set_state(digit, 7, 0);
    }
    else if (character == 'R')
    {
        // show
        unit_io_set_state(digit, 4, 1);
        unit_io_set_state(digit, 5, 1);
        // hide
        unit_io_set_state(digit, 1, 0);
        unit_io_set_state(digit, 2, 0);
        unit_io_set_state(digit, 3, 0);
        unit_io_set_state(digit, 6, 0);
        unit_io_set_state(digit, 7, 0);
    }
    else if (character == 'S')
    {
        // show
        unit_io_set_state(digit, 1, 1);
        unit_io_set_state(digit, 2, 1);
        unit_io_set_state(digit, 4, 1);
        unit_io_set_state(digit, 6, 1);
        // hide
        unit_io_set_state(digit, 3, 0);
        unit_io_set_state(digit, 5, 0);
        unit_io_set_state(digit, 7, 0);
    }
    else if (character == 'T')
    {
        // show
        unit_io_set_state(digit, 2, 1);
        unit_io_set_state(digit, 4, 1);
        unit_io_set_state(digit, 5, 1);
        unit_io_set_state(digit, 7, 1);
        // hide
        unit_io_set_state(digit, 1, 0);
        unit_io_set_state(digit, 3, 0);
        unit_io_set_state(digit, 6, 0);
    }
    else if (character == 'U')
    {
        // show
        unit_io_set_state(digit, 2, 1);
        unit_io_set_state(digit, 3, 1);
        unit_io_set_state(digit, 5, 1);
        unit_io_set_state(digit, 6, 1);
        unit_io_set_state(digit, 7, 1);
        // hide
        unit_io_set_state(digit, 1, 0);
        unit_io_set_state(digit, 4, 0);
    }
    else if (character == 'V')
    {
        // show
        unit_io_set_state(digit, 2, 1);
        unit_io_set_state(digit, 3, 1);
        unit_io_set_state(digit, 4, 1);
        unit_io_set_state(digit, 5, 1);
        unit_io_set_state(digit, 6, 1);
        unit_io_set_state(digit, 7, 1);
        // hide
        unit_io_set_state(digit, 1, 0);
    }
    else if (character == 'W')
    {
        // show
        unit_io_set_state(digit, 1, 1);
        unit_io_set_state(digit, 5, 1);
        unit_io_set_state(digit, 6, 1);
        unit_io_set_state(digit, 7, 1);
        // hide
        unit_io_set_state(digit, 2, 0);
        unit_io_set_state(digit, 3, 0);
        unit_io_set_state(digit, 4, 0);
    }
    else if (character == 'X')
    {
        // show
        unit_io_set_state(digit, 2, 1);
        unit_io_set_state(digit, 3, 1);
        unit_io_set_state(digit, 4, 1);
        unit_io_set_state(digit, 7, 1);
        // hide
        unit_io_set_state(digit, 1, 0);
        unit_io_set_state(digit, 5, 0);
        unit_io_set_state(digit, 6, 0);
    }
    else if (character == 'Y')
    {
        // show
        unit_io_set_state(digit, 2, 1);
        unit_io_set_state(digit, 3, 1);
        unit_io_set_state(digit, 4, 1);
        unit_io_set_state(digit, 6, 1);
        unit_io_set_state(digit, 7, 1);
        // hide
        unit_io_set_state(digit, 1, 0);
        unit_io_set_state(digit, 5, 0);
    }
    else if (character == 'Z')
    {
        // show
        unit_io_set_state(digit, 1, 1);
        unit_io_set_state(digit, 4, 1);
        unit_io_set_state(digit, 7, 1);
        // hide
        unit_io_set_state(digit, 2, 0);
        unit_io_set_state(digit, 3, 0);
        unit_io_set_state(digit, 5, 0);
        unit_io_set_state(digit, 6, 0);
    }
    else if (character == '-')
    {
        // show
        unit_io_set_state(digit, 4, 1);
        // hide
        unit_io_set_state(digit, 1, 0);
        unit_io_set_state(digit, 2, 0);
        unit_io_set_state(digit, 3, 0);
        unit_io_set_state(digit, 5, 0);
        unit_io_set_state(digit, 6, 0);
        unit_io_set_state(digit, 7, 0);
    }
    else if (character == ' ')
    {
        // hide
        unit_io_set_state(digit, 1, 0);
        unit_io_set_state(digit, 2, 0);
        unit_io_set_state(digit, 3, 0);
        unit_io_set_state(digit, 4, 0);
        unit_io_set_state(digit, 5, 0);
        unit_io_set_state(digit, 6, 0);
        unit_io_set_state(digit, 7, 0);
    }
    else if (character == '0')
    {
        // show
        unit_io_set_state(digit, 1, 1);
        unit_io_set_state(digit, 2, 1);
        unit_io_set_state(digit, 3, 1);
        unit_io_set_state(digit, 5, 1);
        unit_io_set_state(digit, 6, 1);
        unit_io_set_state(digit, 7, 1);
        // hide
        unit_io_set_state(digit, 4, 0);
    }
    else if (character == '1')
    {
        unit_io_set_state(digit, 3, 1);
        unit_io_set_state(digit, 6, 1);
        unit_io_set_state(digit, 1, 0);
        unit_io_set_state(digit, 2, 0);
        unit_io_set_state(digit, 4, 0);
        unit_io_set_state(digit, 5, 0);
        unit_io_set_state(digit, 7, 0);
    }
    else if (character == '2')
    {
        unit_io_set_state(digit, 1, 1);
        unit_io_set_state(digit, 3, 1);
        unit_io_set_state(digit, 4, 1);
        unit_io_set_state(digit, 5, 1);
        unit_io_set_state(digit, 7, 1);
        unit_io_set_state(digit, 2, 0);
        unit_io_set_state(digit, 6, 0);
    }
    else if (character == '3')
    {
        unit_io_set_state(digit, 1, 1);
        unit_io_set_state(digit, 3, 1);
        unit_io_set_state(digit, 4, 1);
        unit_io_set_state(digit, 6, 1);
        unit_io_set_state(digit, 7, 1);
        unit_io_set_state(digit, 2, 0);
        unit_io_set_state(digit, 5, 0);
    }
    else if (character == '4')
    {
        unit_io_set_state(digit, 2, 1);
        unit_io_set_state(digit, 3, 1);
        unit_io_set_state(digit, 4, 1);
        unit_io_set_state(digit, 5, 1);
        unit_io_set_state(digit, 1, 0);
        unit_io_set_state(digit, 5, 0);
        unit_io_set_state(digit, 7, 0);
    }
    else if (character == '5')
    {
        unit_io_set_state(digit, 1, 1);
        unit_io_set_state(digit, 2, 1);
        unit_io_set_state(digit, 4, 1);
        unit_io_set_state(digit, 6, 1);
        unit_io_set_state(digit, 7, 1);
        unit_io_set_state(digit, 3, 0);
        unit_io_set_state(digit, 5, 0);
    }
    else if (character == '6')
    {
        unit_io_set_state(digit, 1, 1);
        unit_io_set_state(digit, 2, 1);
        unit_io_set_state(digit, 4, 1);
        unit_io_set_state(digit, 5, 1);
        unit_io_set_state(digit, 6, 1);
        unit_io_set_state(digit, 7, 1);
        unit_io_set_state(digit, 3, 0);
    }
    else if (character == '7')
    {
        unit_io_set_state(digit, 1, 1);
        unit_io_set_state(digit, 3, 1);
        unit_io_set_state(digit, 6, 1);
        unit_io_set_state(digit, 2, 0);
        unit_io_set_state(digit, 4, 0);
        unit_io_set_state(digit, 5, 0);
        unit_io_set_state(digit, 7, 0);
    }
    else if (character == '8')
    {
        unit_io_set_state(digit, 1, 1);
        unit_io_set_state(digit, 2, 1);
        unit_io_set_state(digit, 3, 1);
        unit_io_set_state(digit, 4, 1);
        unit_io_set_state(digit, 5, 1);
        unit_io_set_state(digit, 6, 1);
        unit_io_set_state(digit, 7, 1);
    }
    else if (character == '9')
    {
        unit_io_set_state(digit, 1, 1);
        unit_io_set_state(digit, 2, 1);
        unit_io_set_state(digit, 3, 1);
        unit_io_set_state(digit, 4, 1);
        unit_io_set_state(digit, 6, 1);
        unit_io_set_state(digit, 7, 1);
        unit_io_set_state(digit, 5, 0);
    }
    else
    {
        unit_io_set_state(digit, 1, 0);
        unit_io_set_state(digit, 2, 0);
        unit_io_set_state(digit, 3, 0);
        unit_io_set_state(digit, 4, 0);
        unit_io_set_state(digit, 5, 0);
        unit_io_set_state(digit, 6, 0);
        unit_io_set_state(digit, 7, 0);
    }
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
    uint8_t *pin_def = (uint8_t *)parameter;

    osDelay(100);
    user_gpio->set_en_pin(pin_def[0], pin_def[1], GPIO_PIN_RESET);

    vTaskDelete(NULL);
}

static void unit_io_set_state(uint8_t digit, uint8_t digit_pin, uint8_t state)
{
    // EN
    user_gpio->set_en_pin(digit, digit_pin, GPIO_PIN_SET);
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
    uint8_t pin_info[2] = {digit, digit_pin};
    xTaskCreate(gpio_reset_task, "GPIO_RESET_Task", 256, pin_info, 1, NULL);
}

flipdot_digit_typdef *get_flipdot_unit(void)
{
    return &flipdot_unit;
}