#pragma once

#include <stdbool.h>
#include <stdint.h>

typedef enum inputEvent_t {
  inputEvent_None = 0,
  inputEvent_Button_1 = 1,
  inputEvent_Button_2 = 2,
  inputEvent_Button_3 = 3,
  inputEvent_Button_4 = 4,
  inputEvent_Alarm_A = 5,
  inputEvent_Alarm_B = 6,
  inputEvent_GNSS_Finished = 7,
} inputEvent_t;

typedef enum outputEvent_t {
  outputEvent_None = 0,
  outputEvent_Draw = 1,
  outputEvent_StartAlarm = 2,
  outputEvent_StopAlarm = 3,
  outputEvent_GNSS_Sync = 4,
} outputEvent_t;

typedef enum menu_t {
  menu_watch = 0,
  menu_options = 1,
  menu_debug = 2,
  menu_gnss = 3,
} menu_t;

typedef struct applicationState_t {
  uint8_t currentHours;
  uint8_t currentMinutes;
  bool alarmActive;
  menu_t activeMenu;
  uint8_t selectedItem;
  uint8_t selectedItemValue;
  bool lowBattery;
} applicationState_t;

applicationState_t loadState();
void saveState(applicationState_t *state);
outputEvent_t handleEvent(applicationState_t *state, inputEvent_t in);
