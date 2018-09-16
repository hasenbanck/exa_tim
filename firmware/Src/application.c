#include "button.h"
#include "display.h"
#include "stm32l0xx_hal.h"

extern TIM_HandleTypeDef htim2;

void beep(void) {
  HAL_TIM_PWM_Start_IT(&htim2, TIM_CHANNEL_2);
  HAL_Delay(250);
  HAL_TIM_PWM_Stop_IT(&htim2, TIM_CHANNEL_2);
}

void Run(void) {
  btnBitField field = 0;

  // Print initial screen
  Display_DrawWatchFace();

  // Test the alarm
  beep();

  /* Infinite loop */
  while (1) {
    field = getPressedButtonEvent();
    if (field & BTN1_BIT) {
      debug("Button 1 pressed\n");
      Display_DrawWatchFace();
    } else if (field & BTN2_BIT) {
      debug("Button 2 pressed\n");
      beep();
    } else if (field & BTN3_BIT) {
      debug("Button 3 pressed\n");
    } else if (field & BTN4_BIT) {
      debug("Button 4 pressed\n");
    }
  }
}
