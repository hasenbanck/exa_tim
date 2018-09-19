#include "time.h"
#include "main.h"
#include "stm32l0xx_hal.h"

extern RTC_HandleTypeDef hrtc;

currentTime_t loadCurrentTime() {
  currentTime_t currentTime = {0};
  currentTime.Hours = HAL_RTCEx_BKUPRead(&hrtc, RTC_BKP_DR0);
  currentTime.Minutes = HAL_RTCEx_BKUPRead(&hrtc, RTC_BKP_DR1);
  return currentTime;
}

void saveCurrentTime(currentTime_t currentTime) {
  HAL_RTCEx_BKUPWrite(&hrtc, RTC_BKP_DR0, currentTime.Hours);
  HAL_RTCEx_BKUPWrite(&hrtc, RTC_BKP_DR1, currentTime.Minutes);
}

bool needTimeUpdate(void) {
  RTC_TimeTypeDef sTime;
  bool ret = false;
  uint32_t nextTick = 0;

  currentTime_t currentTime = loadCurrentTime();

  if (HAL_RTC_GetTime(&hrtc, &sTime, RTC_FORMAT_BCD) != HAL_OK) {
    Error_Handler();
  }

  // PWR ON test
  static bool pwron = true;
  if (pwron) {
    pwron = !(__HAL_PWR_GET_FLAG(PWR_FLAG_SB) && __HAL_PWR_GET_FLAG(PWR_FLAG_WU));
  }

  if (sTime.Hours != currentTime.Hours ||
      sTime.Minutes != currentTime.Minutes || pwron) {
    pwron = false;
    currentTime.Hours = sTime.Hours;
    currentTime.Minutes = sTime.Minutes;
    nextTick = 60 - sTime.Seconds;
    ret = true;
  } else if (sTime.Seconds == 59) {
    currentTime.Hours = sTime.Hours;
    currentTime.Minutes = sTime.Minutes++;
    if (currentTime.Minutes == 60) {
      currentTime.Minutes = 0;
      currentTime.Hours++;
    }
    if (currentTime.Hours == 24) {
      currentTime.Hours = 0;
    }
    nextTick = 61;
    ret = true;
  }

  // TODO temp fix until I know why the RTC returns seconds bigger then 59
  if (nextTick > 61) {
    nextTick = 10;
  }

  // Set next update
  if (nextTick) {
    if (HAL_RTCEx_SetWakeUpTimer_IT(&hrtc, nextTick,
                                    RTC_WAKEUPCLOCK_CK_SPRE_16BITS) != HAL_OK) {
      Error_Handler();
    }
  }

  if (ret) {
    saveCurrentTime(currentTime);
  }

  return ret;
}

currentTime_t getCurrentTime(void) { return loadCurrentTime(); }
