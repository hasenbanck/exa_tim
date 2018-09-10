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
        /* Every interrupt (5ms) we are saving the current history of
         * a button state. We later compare the most recent 3 and
         * and 2 oldest states using the mask 0b11000111 with the
         * expected value of a "good" button press history.
         * We expect to find to find 15ms of HIGH at the start and
         * 10ms of LOW in the end of the history. The middle 3 states
         * are not of interest and maybe bounces.
         * */
        buttonStates[i].history = buttonStates[0].history << 1;
        buttonStates[i].history |= (GPIOB->IDR & (((uint16_t)0x0010U)<<i));
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
