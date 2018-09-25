#include "logic.h"
#include "clock.h"
#include "stm32l0xx_hal.h"

extern RTC_HandleTypeDef hrtc;

applicationState_t loadState() {
  applicationState_t state;
  state.currentHours = 0x000000FF & (HAL_RTCEx_BKUPRead(&hrtc, RTC_BKP_DR0));
  state.currentMinutes =
      0x000000FF & (HAL_RTCEx_BKUPRead(&hrtc, RTC_BKP_DR0) >> 8);
  state.alarmActive =
      0x000000FF & (HAL_RTCEx_BKUPRead(&hrtc, RTC_BKP_DR0) >> 16);
  state.activeMenu =
      0x000000FF & (HAL_RTCEx_BKUPRead(&hrtc, RTC_BKP_DR0) >> 24);
  state.selectedItem = 0x000000FF & (HAL_RTCEx_BKUPRead(&hrtc, RTC_BKP_DR1));
  state.selectedItemValue =
      0x000000FF & (HAL_RTCEx_BKUPRead(&hrtc, RTC_BKP_DR1) >> 8);
  return state;
}

void saveState(applicationState_t *state) {
  HAL_RTCEx_BKUPWrite(&hrtc, RTC_BKP_DR0,
                      (((int32_t)state->activeMenu) << 24) |
                          (((int32_t)state->alarmActive) << 16) |
                          (((int32_t)state->currentMinutes) << 8) |
                          ((int32_t)state->currentHours));
  HAL_RTCEx_BKUPWrite(&hrtc, RTC_BKP_DR1,
                      (((int32_t)state->selectedItemValue) << 8) |
                          ((int32_t)state->selectedItem));
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
      if (state->selectedItem == 0) {
        // TODO toggle edit mode
        return outputEvent_Draw;
      }
    }

    // Up
    if (in == inputEvent_Button_1) {
      if (state->selectedItem == 0)
        state->selectedItem = 6;
      else
        state->selectedItem--;
      return outputEvent_Draw;
    }

    // Down
    if (in == inputEvent_Button_2) {
      if (state->selectedItem == 6)
        state->selectedItem = 0;
      else
        state->selectedItem++;
      return outputEvent_Draw;
    }
  }

  if (state->activeMenu == menu_watch && in == inputEvent_Button_4) {
    state->activeMenu = menu_options;
    state->selectedItem = 0;
    state->selectedItemValue = 0;
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