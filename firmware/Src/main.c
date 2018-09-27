#include "main.h"
#include "button.h"
#include "clock.h"
#include "config.h"
#include "display.h"
#include "logic.h"
#include "power.h"
#include "stm32l0xx_hal.h"

#include <stdbool.h>

const uint32_t BUTTON_TIMEOUT = 10;

LPTIM_HandleTypeDef hlptim1;
UART_HandleTypeDef hlpuart1;
RTC_HandleTypeDef hrtc;
SPI_HandleTypeDef hspi1;
TIM_HandleTypeDef htim2;

void beep(void) {
  // TODO: Interrupt based delay with a timer
  HAL_TIM_PWM_Start_IT(&htim2, TIM_CHANNEL_2);
  HAL_Delay(250);
  HAL_TIM_PWM_Stop_IT(&htim2, TIM_CHANNEL_2);
}

bool checkAlarmTimer(applicationState_t *state) {
  config_t config = loadConfig();
  if (config.alarmActivated && (state->currentHours == config.alarmHours) &&
      (state->currentMinutes == config.alarmMinutes) &&
      (state->lastAlarmDay != state->currentDay)) {
    state->lastAlarmDay = state->currentDay;
    return true;
  }
  return false;
}

bool checkGNSSTimer(applicationState_t *state) {
  config_t config = loadConfig();
  // Sync is every night at 01:27
  if (config.syncActivated && (state->currentHours == 1) &&
      (state->currentMinutes == 27) &&
      (state->lastGNSSDay != state->currentDay)) {
    state->lastGNSSDay = state->currentDay;
    return true;
  }
  return false;
}

int main(void) {
  /* Reset of all peripherals, Initializes
   * the Flash interface and the Systick
   */
  HAL_Init();

  /* Initializes normal operation mode */
  initNormalMode();

  /* Get current application state */
  applicationState_t state = loadState();

  /* Reset button history */
  inputEvent_t in;
  btnBitField field;
  uint32_t timeoutCounter = 0;
  while (1) {

    // Test for events
    in = needTimeUpdate(&state);
    field = getPressedButtonEvent();
    if (checkAlarmTimer(&state)) {
      in = inputEvent_Alarm_Timer;
    } else if (checkGNSSTimer(&state)) {
      in = inputEvent_GNSS_Timer;
    } else if (field & BTN1_BIT) {
      in = inputEvent_Button_1;
    } else if (field & BTN2_BIT) {
      in = inputEvent_Button_2;
    } else if (field & BTN3_BIT) {
      in = inputEvent_Button_3;
    } else if (field & BTN4_BIT) {
      in = inputEvent_Button_4;
    }

    outputEvent_t out = handleEvent(&state, in);

    if (out == outputEvent_StartAlarm) {
      // TODO: Implement an alarm
      beep();
    }

    if (out == outputEvent_GNSS_Sync) {
      // TODO: Implement GNSS sync
      beep();
    }

    if (out == outputEvent_Draw) {
      initDisplay(&state);
      drawDisplay(&state);
    }

    if ((timeoutCounter >= BUTTON_TIMEOUT) || out == outputEvent_Draw) {
      if (out == outputEvent_Draw) {
        // clang-format off
        while (isDisplayBusy());
        // clang-format on
        powerOffDisplay();
      }
      saveState(&state);
      switchStandbyMode();
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
  UNUSED(file);
  UNUSED(line);
  // clang-format off
  while (1);
  // clang-format on
}
