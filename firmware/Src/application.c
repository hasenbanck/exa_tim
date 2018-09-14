#include "button.h"
#include "stm32l0xx_hal.h"

void Run(void) {
  btnBitField field = 0;

  /* Infinite loop */
  while (1) {
    field = getPressedButtonEvent();
    if (field & BTN1_BIT) {
      debug("Button 1 pressed");
    }
    else if (field & BTN2_BIT) {
      debug("Button 2 pressed");
    }
    else if (field & BTN3_BIT) {
      debug("Button 3 pressed");
    }
    else if (field & BTN4_BIT) {
      debug("Button 4 pressed");
    }
    HAL_Delay(1);
  }
}
