#include "button.h"
#include "stm32l0xx_hal.h"
#include <stdbool.h>

typedef struct
{
    bool pressed;
    uint8_t history;
} buttonState;

static buttonState buttonStates[4] = {0};

void HAL_LPTIM_TriggerCallback(LPTIM_HandleTypeDef *hlptim)
{
    for (uint8_t i = 0; i < 4; i++)
    {
        buttonStates[i].history = buttonStates[0].history << 1;
        buttonStates[i].history |= (GPIOB->IDR & (i << ((uint16_t)0x0010U)));
        if ((buttonStates[0].history & 0b11000111) == 0b00000111)
        {
            buttonStates[i].pressed = true;
            buttonStates[i].history = 0b11111111;
        }
    }
}

btn_pressed_event getPressedButtonEvent()
{
    btn_pressed_event evt = no_button_pressed;
    if (buttonStates[0].pressed == true)
    {
        buttonStates[0].pressed = false;
        evt = btn1_pressed;
    }
    if (buttonStates[1].pressed == true)
    {
        buttonStates[1].pressed = false;
        evt = btn2_pressed;
    }
    if (buttonStates[2].pressed == true)
    {
        buttonStates[2].pressed = false;
        evt = btn3_pressed;
    }
    if (buttonStates[3].pressed == true)
    {
        buttonStates[3].pressed = false;
        evt = btn4_pressed;
    }
    return evt;
}
