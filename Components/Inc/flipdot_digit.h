#ifndef __FLIPDOT_DIGIT_H__
#define __FLIPDOT_DIGIT_H__

#include "../../Core/Inc/gpio.h"

typedef struct
{
    void (*flipdot_show_char)(uint8_t digit, char chr);
    void (*flipdot_show_string)(uint8_t *str);
} flipdot_digit_typdef;

void flipdot_digit_init(void);
flipdot_digit_typdef *get_flipdot_unit(void);

#endif