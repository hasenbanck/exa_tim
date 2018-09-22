#include "clock.h"
#include "main.h"
#include "stm32l0xx_hal.h"

extern RTC_HandleTypeDef hrtc;

bool needTimeUpdate(applicationState_t* state) {
  RTC_TimeTypeDef sTime;
  bool ret = false;
  uint32_t nextTick = 0;

  if (HAL_RTC_GetTime(&hrtc, &sTime, RTC_FORMAT_BIN) != HAL_OK) {
    Error_Handler();
  }

  // PWR ON test
  static bool pwron = true;
  if (pwron) {
    pwron = !(__HAL_PWR_GET_FLAG(PWR_FLAG_SB) && __HAL_PWR_GET_FLAG(PWR_FLAG_WU));
  }

  if (sTime.Hours != state->currentHours ||
      sTime.Minutes != state->currentMinutes || pwron) {
    pwron = false;
    state->currentHours = sTime.Hours;
    state->currentMinutes = sTime.Minutes;
    nextTick = 60 - sTime.Seconds;
    ret = true;
  }

  // Set next update
  if (nextTick) {
    if (HAL_RTCEx_SetWakeUpTimer_IT(&hrtc, nextTick,
                                    RTC_WAKEUPCLOCK_CK_SPRE_16BITS) != HAL_OK) {
      Error_Handler();
    }
  }

  return ret;
}
