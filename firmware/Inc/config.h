#pragma once

#include <stdbool.h>
#include <stdint.h>

typedef struct config_t {
  bool alarmActivated;
  uint8_t alarmHours;
  uint8_t alarmMinutes;
  bool syncActivated;
  uint32_t timezone;
} config_t;

void checkConfig(void);
config_t loadConfig(void);
void saveConfig(config_t *config);
