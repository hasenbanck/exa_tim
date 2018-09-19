#pragma once

#include <stdbool.h>
#include <stdint.h>

typedef struct currentTime {
  uint8_t Hours;
  uint8_t Minutes;
} currentTime_t;

bool needTimeUpdate(void);
currentTime_t getCurrentTime(void);
