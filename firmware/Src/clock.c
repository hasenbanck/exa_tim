#include "clock.h"
#include "main.h"
#include "stm32l0xx_hal.h"
#include "time.h"

extern RTC_HandleTypeDef hrtc;

bool needTimeUpdate(applicationState_t *state) {
  RTC_TimeTypeDef sTime;
  bool ret = false;
  uint8_t nextTick = 0;

  if (HAL_RTC_GetTime(&hrtc, &sTime, RTC_FORMAT_BCD) != HAL_OK) {
    Error_Handler();
  }

  // PWR ON test
  static bool pwron = true;
  if (pwron) {
    pwron =
        !(__HAL_PWR_GET_FLAG(PWR_FLAG_SB) && __HAL_PWR_GET_FLAG(PWR_FLAG_WU));
  }

  if (sTime.Hours != state->currentHours ||
      sTime.Minutes != state->currentMinutes || pwron) {
    pwron = false;
    state->currentHours = sTime.Hours;
    state->currentMinutes = sTime.Minutes;
    nextTick = 60 - RTC_Bcd2ToByte(sTime.Seconds);
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

void updateRTC(time_t now) {
  RTC_TimeTypeDef sTime;
  RTC_DateTypeDef sDate;
  struct tm time_tm;
  time_tm = *(localtime(&now));
  sTime.Hours = (uint8_t)time_tm.tm_hour;
  sTime.Minutes = (uint8_t)time_tm.tm_min;
  sTime.Seconds = (uint8_t)time_tm.tm_sec;
  if (HAL_RTC_SetTime(&hrtc, &sTime, RTC_FORMAT_BIN) != HAL_OK) {
    Error_Handler();
  }
  if (time_tm.tm_wday == 0) {
    time_tm.tm_wday = 7;
  }
  sDate.WeekDay = (uint8_t)time_tm.tm_wday;
  sDate.Month = (uint8_t)time_tm.tm_mon + 1;
  sDate.Date = (uint8_t)time_tm.tm_mday;
  sDate.Year =
      (uint16_t)(time_tm.tm_year + 1900 -
                 2000); // time.h is years since 1900, chip is years since 2000
  if (HAL_RTC_SetDate(&hrtc, &sDate, RTC_FORMAT_BIN) != HAL_OK) {
    Error_Handler();
  }
}

time_t getTime(void) {
  RTC_DateTypeDef rtcDate;
  RTC_TimeTypeDef rtcTime;
  HAL_RTC_GetTime(&hrtc, &rtcTime, RTC_FORMAT_BIN);
  HAL_RTC_GetDate(&hrtc, &rtcDate, RTC_FORMAT_BIN);
  uint8_t hh = rtcTime.Hours;
  uint8_t mm = rtcTime.Minutes;
  uint8_t ss = rtcTime.Seconds;
  uint8_t d = rtcDate.Date;
  uint8_t m = rtcDate.Month;
  uint16_t y = rtcDate.Year;
  uint16_t yr = (uint16_t)(y + 2000 - 1900);
  time_t currentTime = {0};
  struct tm tim = {0};
  tim.tm_year = yr;
  tim.tm_mon = m - 1;
  tim.tm_mday = d;
  tim.tm_hour = hh;
  tim.tm_min = mm;
  tim.tm_sec = ss;
  currentTime = mktime(&tim);
  // struct tm printTm = {0};
  // printTm = *(localtime(&currentTime));
  return currentTime;
}