#include "button.h"
#include "stm32l0xx_hal.h"

static uint32_t const BTN_HISTORY_CLEAR_MASK = 0x01010101U;

typedef struct buttonState{
  uint32_t history;
  btnBitField pressed;
} buttonState;

static buttonState btnState;

void HAL_LPTIM_TriggerCallback(LPTIM_HandleTypeDef *hlptim)
{
  /* Every interrupt (5ms) we are saving the current history of
   * a button state. We later compare the most recent 3 and
   * and 2 oldest states using the mask 0b11000111 with the
   * expected value of a "good" button press history.
   * We expect to find to find 15ms of HIGH at the start and
   * 10ms of LOW in the end of the history. The middle 3 states
   * are not of interest and maybe bounces.
   * */
  uint32_t currentButtonStates = GPIOB->IDR; // Get current button states
  btnState.history <<= 1;                 // Advance history one bit
  btnState.history &= ~BTN_HISTORY_CLEAR_MASK; // Clear history bits we want to write
  btnState.history |= currentButtonStates & BTN1_Pin; // Set state of buttons
  btnState.history |= currentButtonStates & BTN2_Pin;
  btnState.history |= currentButtonStates & BTN3_Pin;
  btnState.history |= currentButtonStates & BTN4_Pin;

  // Test button press history for every button on "good looking" using the mask
  if ((btnState.history & (0b11000111 << 0)) == (0b00000111 << 0)) {
    btnState.pressed |= BTN1_BIT;
    btnState.history |= 0b11111111 << 0;
  }
  if ((btnState.history & (0b11000111 << 8)) == (0b00000111 << 8)) {
    btnState.pressed |= BTN2_BIT;
    btnState.history |= 0b11111111 << 8;
  }
  if ((btnState.history & (0b11000111 << 16)) == (0b00000111 << 16)) {
    btnState.pressed |= BTN3_BIT;
    btnState.history |= 0b11111111 << 16;
  }
  if ((btnState.history & (0b11000111 << 24)) == (0b00000111 << 24)) {
    btnState.pressed |= BTN4_BIT;
    btnState.history |= 0b11111111 << 24;
  }
}

btnBitField getPressedButtonEvent() {
  __disable_irq();
  btnBitField tmp = btnState.pressed;
  btnState.pressed = 0U;
  __enable_irq();
  return tmp;
}