#include "logic.h"
#include "clock.h"
#include "config.h"
#include "stm32l0xx_hal.h"

extern RTC_HandleTypeDef hrtc;

applicationState_t loadState() {
  applicationState_t state = {0};

  state.currentYear = 0x000000FF & (HAL_RTCEx_BKUPRead(&hrtc, RTC_BKP_DR0));

  state.currentMonth =
      0x000000FF & (HAL_RTCEx_BKUPRead(&hrtc, RTC_BKP_DR0) >> 8);

  state.currentDay =
      0x000000FF & (HAL_RTCEx_BKUPRead(&hrtc, RTC_BKP_DR0) >> 16);

  state.currentWeekday =
      0x000000FF & (HAL_RTCEx_BKUPRead(&hrtc, RTC_BKP_DR0) >> 24);

  state.currentHours = 0x000000FF & (HAL_RTCEx_BKUPRead(&hrtc, RTC_BKP_DR1));

  state.currentMinutes =
      0x000000FF & (HAL_RTCEx_BKUPRead(&hrtc, RTC_BKP_DR1) >> 8);

  state.alarmActive =
      0x000000FF & (HAL_RTCEx_BKUPRead(&hrtc, RTC_BKP_DR1) >> 16);

  state.activeMenu =
      0x000000FF & (HAL_RTCEx_BKUPRead(&hrtc, RTC_BKP_DR1) >> 24);

  state.selectedItem = 0x000000FF & (HAL_RTCEx_BKUPRead(&hrtc, RTC_BKP_DR2));

  state.lastAlarmDay =
      0x000000FF & (HAL_RTCEx_BKUPRead(&hrtc, RTC_BKP_DR2) >> 8);

  state.lastGNSSDay =
      0x000000FF & (HAL_RTCEx_BKUPRead(&hrtc, RTC_BKP_DR2) >> 16);

  state.successGNSS =
      0x000000FF & (HAL_RTCEx_BKUPRead(&hrtc, RTC_BKP_DR2) >> 24);

  return state;
}

void saveState(applicationState_t *state) {
  HAL_RTCEx_BKUPWrite(&hrtc, RTC_BKP_DR0,
                      (((int32_t)state->currentWeekday) << 24) |
                          (((int32_t)state->currentDay) << 16) |
                          (((int32_t)state->currentMonth) << 8) |
                          ((int32_t)state->currentYear));
  HAL_RTCEx_BKUPWrite(&hrtc, RTC_BKP_DR1,
                      (((int32_t)state->activeMenu) << 24) |
                          (((int32_t)state->alarmActive) << 16) |
                          (((int32_t)state->currentMinutes) << 8) |
                          ((int32_t)state->currentHours));

  HAL_RTCEx_BKUPWrite(&hrtc, RTC_BKP_DR2,
                      (((int32_t)state->successGNSS) << 24) |
                          (((int32_t)state->lastGNSSDay) << 16) |
                          (((int32_t)state->lastAlarmDay) << 8) |
                          ((int32_t)state->selectedItem));
}

outputEvent_t handleEvent(applicationState_t *state, inputEvent_t in) {
  if (!state->alarmActive && in == inputEvent_Alarm_Timer) {
    return outputEvent_StartAlarm;
  }

  if (state->alarmActive &&
      (in == inputEvent_Button_1 || in == inputEvent_Button_2 ||
       in == inputEvent_Button_3 || in == inputEvent_Button_4)) {
    return outputEvent_StopAlarm;
  }

  if (in == inputEvent_GNSS_Timer) {
    return outputEvent_GNSS_Sync;
  }

  if (state->activeMenu == menu_gnss && in == inputEvent_GNSS_Finished) {
    state->activeMenu = menu_watch;
    return outputEvent_Draw;
  }

  if (state->activeMenu == menu_options) {
    // Exit menu
    if (in == inputEvent_Button_4) {
      state->activeMenu = menu_watch;
      return outputEvent_Draw;
    }

    // Configuration change
    if (in == inputEvent_Button_3) {
      config_t config = loadConfig();
      switch (state->selectedItem) {
      case 0:
        config.alarmActivated = config.alarmActivated ? false : true;
        break;
      case 1:
        config.alarmHours =
            RTC_ByteToBcd2((RTC_Bcd2ToByte(config.alarmHours) >= 23)
                               ? 0
                               : RTC_Bcd2ToByte(config.alarmHours) + 1);
        break;
      case 2:
        config.alarmMinutes =
            RTC_ByteToBcd2((RTC_Bcd2ToByte(config.alarmMinutes) >= 55)
                               ? 0
                               : RTC_Bcd2ToByte(config.alarmMinutes) + 5);
        break;

      case 3:
        config.syncActivated = config.syncActivated ? false : true;
        break;

      case 4:
        config.timezone = (config.timezone >= 100) ? 1 : config.timezone + 1;
        break;

      case 5:
        return outputEvent_GNSS_Sync;

      default:
        break;
      }
      saveConfig(&config);
      return outputEvent_Draw;
    }

    // Up
    if (in == inputEvent_Button_1) {
      if (state->selectedItem == 0)
        state->selectedItem = 5;
      else
        state->selectedItem--;
      return outputEvent_Draw;
    }

    // Down
    if (in == inputEvent_Button_2) {
      if (state->selectedItem == 5)
        state->selectedItem = 0;
      else
        state->selectedItem++;
      return outputEvent_Draw;
    }
  }

  if (state->activeMenu == menu_watch && in == inputEvent_Button_4) {
    state->activeMenu = menu_options;
    state->selectedItem = 0;
    return outputEvent_Draw;
  }

  if (in == inputEvent_Time_Update) {
    if (state->activeMenu == menu_watch)
      return outputEvent_Draw;
  }

  return outputEvent_None;
}