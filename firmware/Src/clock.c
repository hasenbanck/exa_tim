#include "clock.h"
#include "main.h"
#include "stm32l0xx_hal.h"
#include "utz.h"
#include "zones.h"

extern RTC_HandleTypeDef hrtc;

/* Chip time = UTC */
struct tm getTime() {
  RTC_DateTypeDef rtcDate;
  RTC_TimeTypeDef rtcTime;
  if (HAL_RTC_GetTime(&hrtc, &rtcTime, RTC_FORMAT_BIN) != HAL_OK) {
    Error_Handler();
  }
  if (HAL_RTC_GetDate(&hrtc, &rtcDate, RTC_FORMAT_BIN) != HAL_OK) {
    Error_Handler();
  }
  uint8_t hh = rtcTime.Hours;
  uint8_t mm = rtcTime.Minutes;
  uint8_t ss = rtcTime.Seconds;
  uint8_t d = rtcDate.Date;
  uint8_t m = rtcDate.Month;
  uint16_t y = rtcDate.Year;
  uint16_t yr = (uint16_t)(y + 2000 - 1900);

  // Calculate offset
  udatetime_t dt;
  dt.date.year = yr;
  dt.date.month = m;
  dt.date.dayofmonth = d;
  dt.time.hour = hh;
  dt.time.minute = mm;
  dt.time.second = ss;
  // TODO: Get zone from config
  uzone_t active_zone;
  get_zone_by_name("Berlin", &active_zone);
  uoffset_t offset;
  get_current_offset(&active_zone, &dt, &offset);
  time_t offsetSeconds = (offset.hours * 60 * 60) + (offset.minutes * 60);

  // Create local time
  time_t currentTime = {0};
  struct tm tim = {0};
  tim.tm_year = yr;
  tim.tm_mon = m - 1;
  tim.tm_mday = d;
  tim.tm_hour = hh;
  tim.tm_min = mm;
  tim.tm_sec = ss;
  currentTime = mktime(&tim) + offsetSeconds;
  struct tm printTm = {0};
  printTm = *(localtime(&currentTime));
  return printTm;
}

bool needTimeUpdate(applicationState_t *state) {
  RTC_TimeTypeDef sTime;
  bool ret = false;
  uint8_t nextTick = 0;

  getTime();

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
