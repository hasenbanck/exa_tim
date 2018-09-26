#include "clock.h"
#include "config.h"
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

  uzone_t active_zone;
  config_t config = loadConfig();
  char s[17];
  getTimeZoneName(config.timezone, &s[0]);
  get_zone_by_name(&s[0], &active_zone);
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

void getTimeZoneName(uint32_t num, char *s) {
  switch (num) {
  case 1:
    strcpy(s, "Adelaide");
    return;
  case 2:
    strcpy(s, "Ahmedabad");
    return;
  case 3:
    strcpy(s, "Anchorage");
    return;
  case 4:
    strcpy(s, "Ankara");
    return;
  case 5:
    strcpy(s, "Atlanta");
    return;
  case 6:
    strcpy(s, "Auckland");
    return;
  case 7:
    strcpy(s, "Bangalore");
    return;
  case 8:
    strcpy(s, "Bangkok");
    return;
  case 9:
    strcpy(s, "Barcelona");
    return;
  case 10:
    strcpy(s, "Beijing");
    return;
  case 11:
    strcpy(s, "Belgrade");
    return;
  case 12:
    strcpy(s, "Belo Horizonte");
    return;
  case 13:
    strcpy(s, "Berlin");
    return;
  case 14:
    strcpy(s, "Boston");
    return;
  case 15:
    strcpy(s, "Brazzaville");
    return;
  case 16:
    strcpy(s, "Brisbane");
    return;
  case 17:
    strcpy(s, "Buenos Aires");
    return;
  case 18:
    strcpy(s, "Cairo");
    return;
  case 19:
    strcpy(s, "Calcutta");
    return;
  case 20:
    strcpy(s, "Changzhou");
    return;
  case 21:
    strcpy(s, "Chengdu");
    return;
  case 22:
    strcpy(s, "Chennai");
    return;
  case 23:
    strcpy(s, "Chicago");
    return;
  case 24:
    strcpy(s, "Chongqing");
    return;
  case 25:
    strcpy(s, "DallasFort Worth");
    return;
  case 26:
    strcpy(s, "Darwin");
    return;
  case 27:
    strcpy(s, "Delhi");
    return;
  case 28:
    strcpy(s, "Denver");
    return;
  case 29:
    strcpy(s, "Dubai");
    return;
  case 30:
    strcpy(s, "Guadalajara");
    return;
  case 31:
    strcpy(s, "Guam");
    return;
  case 32:
    strcpy(s, "Guangzhou");
    return;
  case 33:
    strcpy(s, "Halifax");
    return;
  case 34:
    strcpy(s, "Hamburg");
    return;
  case 35:
    strcpy(s, "Hangzhou");
    return;
  case 36:
    strcpy(s, "Harare");
    return;
  case 37:
    strcpy(s, "Helsinki");
    return;
  case 38:
    strcpy(s, "Hobart");
    return;
  case 39:
    strcpy(s, "Hong Kong");
    return;
  case 40:
    strcpy(s, "Honolulu");
    return;
  case 41:
    strcpy(s, "Houston");
    return;
  case 42:
    strcpy(s, "Hyderabad");
    return;
  case 43:
    strcpy(s, "Inland Empire");
    return;
  case 44:
    strcpy(s, "Istanbul");
    return;
  case 45:
    strcpy(s, "Jerusalem");
    return;
  case 46:
    strcpy(s, "Jinan");
    return;
  case 47:
    strcpy(s, "Karachi");
    return;
  case 48:
    strcpy(s, "Katmandu");
    return;
  case 49:
    strcpy(s, "Kolkata");
    return;
  case 50:
    strcpy(s, "Kuwait");
    return;
  case 51:
    strcpy(s, "Lahore");
    return;
  case 52:
    strcpy(s, "London");
    return;
  case 53:
    strcpy(s, "Los Angeles");
    return;
  case 54:
    strcpy(s, "Madrid");
    return;
  case 55:
    strcpy(s, "Manaus");
    return;
  case 56:
    strcpy(s, "Mexico City");
    return;
  case 57:
    strcpy(s, "Miami");
    return;
  case 58:
    strcpy(s, "Midway");
    return;
  case 59:
    strcpy(s, "Milan");
    return;
  case 60:
    strcpy(s, "Moscow");
    return;
  case 61:
    strcpy(s, "Mumbai");
    return;
  case 62:
    strcpy(s, "Munich");
    return;
  case 63:
    strcpy(s, "Nagoya");
    return;
  case 64:
    strcpy(s, "Nairobi");
    return;
  case 65:
    strcpy(s, "Nanchang");
    return;
  case 66:
    strcpy(s, "Nanjing");
    return;
  case 67:
    strcpy(s, "New York");
    return;
  case 68:
    strcpy(s, "Osaka");
    return;
  case 69:
    strcpy(s, "Perth");
    return;
  case 70:
    strcpy(s, "Philadelphia");
    return;
  case 71:
    strcpy(s, "Phoenix");
    return;
  case 72:
    strcpy(s, "Pune");
    return;
  case 73:
    strcpy(s, "Qingdao");
    return;
  case 74:
    strcpy(s, "Rangoon");
    return;
  case 75:
    strcpy(s, "Regina");
    return;
  case 76:
    strcpy(s, "Rhine-Ruhr");
    return;
  case 77:
    strcpy(s, "Rio de Janeiro");
    return;
  case 78:
    strcpy(s, "Rome");
    return;
  case 79:
    strcpy(s, "San Francisco");
    return;
  case 80:
    strcpy(s, "Santiago");
    return;
  case 81:
    strcpy(s, "Sao Paulo");
    return;
  case 82:
    strcpy(s, "Sarajevo");
    return;
  case 83:
    strcpy(s, "Seoul");
    return;
  case 84:
    strcpy(s, "Shanghai");
    return;
  case 85:
    strcpy(s, "Shenyang");
    return;
  case 86:
    strcpy(s, "Shenzhen");
    return;
  case 87:
    strcpy(s, "St Johns");
    return;
  case 88:
    strcpy(s, "Stuttgart");
    return;
  case 89:
    strcpy(s, "Surat");
    return;
  case 90:
    strcpy(s, "Sydney");
    return;
  case 91:
    strcpy(s, "Taipei");
    return;
  case 92:
    strcpy(s, "Tehran");
    return;
  case 93:
    strcpy(s, "Tianjin");
    return;
  case 94:
    strcpy(s, "Tijuana");
    return;
  case 95:
    strcpy(s, "Tokyo");
    return;
  case 96:
    strcpy(s, "Washington, D.C.");
    return;
  case 97:
    strcpy(s, "Wenzhou");
    return;
  case 98:
    strcpy(s, "Wuhan");
    return;
  case 99:
    strcpy(s, "Xi'an");
    return;
  case 100:
    strcpy(s, "Zhengzhou");
    return;

  default:
    Error_Handler();
  }
}