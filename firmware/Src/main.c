#include "main.h"
#include "button.h"
#include "display.h"
#include "power.h"
#include "time.h"
#include "stm32l0xx_hal.h"

#include <stdbool.h>

const uint32_t BUTTON_TIMEOUT = 10;

LPTIM_HandleTypeDef hlptim1;
UART_HandleTypeDef hlpuart1;
RTC_HandleTypeDef hrtc;
SPI_HandleTypeDef hspi1;
TIM_HandleTypeDef htim2;

void beep(void) {
  // TODO: Interrupt based delay?
  HAL_TIM_PWM_Start_IT(&htim2, TIM_CHANNEL_2);
  HAL_Delay(250);
  HAL_TIM_PWM_Stop_IT(&htim2, TIM_CHANNEL_2);
}

void Run(void) {}

int main(void) {
  bool displayNeedUpdate = false;
  bool displayUsed = false;

  /* Reset of all peripherals, Initializes
   * the Flash interface and the Systick
   */
  HAL_Init();

  /* Initializes normal operation mode */
  initNormalMode();

  /* Reset button history */
  resetBtnState();
  btnBitField field = 0;
  uint32_t timeoutCounter = 0;
  while (1) {
    if (needTimeUpdate() || displayNeedUpdate) {
      displayUsed = true;
      displayNeedUpdate = false;
      initDisplay();
      // TODO: Create a menu config and give it to the drawing function
      drawDisplay();
    }

    if (timeoutCounter >= BUTTON_TIMEOUT) {
      if (displayUsed) {
        while (isDisplayBusy()) {
        };
        powerOffDisplay();
      }
      switchStandbyMode();
    }

    // Test for events (buttons / display update)
    field = getPressedButtonEvent();
    if (field & BTN1_BIT) {
      displayNeedUpdate = true;
      debug("Button 1 pressed\n");
    } else if (field & BTN2_BIT) {
      beep();
      debug("Button 2 pressed\n");
    } else if (field & BTN3_BIT) {
      debug("Button 3 pressed\n");
    } else if (field & BTN4_BIT) {
      debug("Button 4 pressed\n");
    }
    switchStopMode();
    timeoutCounter++;
  }
}

/**
 * @brief  This function is executed in case of error occurrence.
 * @param  file: The file name as string.
 * @param  line: The line in file as a number.
 * @retval None
 */
void _Error_Handler(char *file, int line) {
  debug("Error_Handler() called from %s, %d\n", file, line);
  while (1) {
  }
}
