#include "logic.h"
#include "clock.h"
#include "stm32l0xx_hal.h"

extern RTC_HandleTypeDef hrtc;

applicationState_t loadState(void) {
  applicationState_t state = {0};
  state.currentHours = 0x000000FF & (HAL_RTCEx_BKUPRead(&hrtc, RTC_BKP_DR0));
  state.currentMinutes =
      0x000000FF & (HAL_RTCEx_BKUPRead(&hrtc, RTC_BKP_DR0) >> 8);
  state.alarmActive =
      0x000000FF & (HAL_RTCEx_BKUPRead(&hrtc, RTC_BKP_DR0) >> 16);
  state.activeMenu =
      0x000000FF & (HAL_RTCEx_BKUPRead(&hrtc, RTC_BKP_DR0) >> 24);
  state.selectedItemLevel =
      0x000000FF & (HAL_RTCEx_BKUPRead(&hrtc, RTC_BKP_DR1));
  state.selectedItemMain =
      0x000000FF & (HAL_RTCEx_BKUPRead(&hrtc, RTC_BKP_DR1) >> 8);
  state.selectedItemSub =
      0x000000FF & (HAL_RTCEx_BKUPRead(&hrtc, RTC_BKP_DR1) >> 8);
  return state;
}

void saveLogic(applicationState_t *state) {
  HAL_RTCEx_BKUPWrite(&hrtc, RTC_BKP_DR0,
                      (((int32_t)state->activeMenu) << 24) |
                          (((int32_t)state->alarmActive) << 16) |
                          (((int32_t)state->currentMinutes) << 8) |
                          ((int32_t)state->currentHours));
  HAL_RTCEx_BKUPWrite(&hrtc, RTC_BKP_DR1,
                      (((int32_t)state->selectedItemSub) << 16) |
                          (((int32_t)state->selectedItemMain) << 8) |
                          ((int32_t)state->selectedItemLevel));
}

outputEvent_t handleEvent(applicationState_t *state, inputEvent_t in) {
  if (state->alarmActive &&
      (in == inputEvent_Button_1 || in == inputEvent_Button_2 ||
       in == inputEvent_Button_3 || in == inputEvent_Button_4)) {
    return outputEvent_StopAlarm;
  }

  if (!state->alarmActive && in == inputEvent_Alarm_A) {
    return outputEvent_StartAlarm;
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

    // Enter
    if (in == inputEvent_Button_3) {
      if (state->selectedItemLevel == 0) {
        // TODO change selected config item, special case for time entry
        return outputEvent_Draw;
      }
    }

    // Up
    if (in == inputEvent_Button_1) {
      // Main Level
      if (state->selectedItemLevel == 0) {
        if (state->selectedItemMain == 0)
          state->selectedItemMain = 6;
        else
          state->selectedItemMain--;
        return outputEvent_Draw;
      }
      // Alarm time setting (+)
      if (state->selectedItemLevel == 1 && state->selectedItemMain == 1) {
        // TODO
      }
    }

    // Down
    if (in == inputEvent_Button_2) {
      if (state->selectedItemLevel == 0) {
        if (state->selectedItemMain == 6)
          state->selectedItemMain = 0;
        else
          state->selectedItemMain++;
        return outputEvent_Draw;
      }
    }
    // Alarm time setting (-)
    if (state->selectedItemLevel == 1 && state->selectedItemMain == 1) {
      // TODO
    }
  }

  if (state->activeMenu == menu_watch && in == inputEvent_Button_4) {
    state->activeMenu = menu_options;
    state->selectedItemLevel = 0;
    state->selectedItemMain = 0;
    state->selectedItemSub = 0;
    return outputEvent_Draw;
  }

  if (in == inputEvent_Alarm_B) {
    return outputEvent_GNSS_Sync;
  }

  if (needTimeUpdate(state)) {
    if (state->activeMenu == menu_watch)
      return outputEvent_Draw;
  }

  return outputEvent_None;
}