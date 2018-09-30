#pragma once

#include "logic.h"

#include <stdbool.h>
#include <stdint.h>
#include <time.h>

struct tm getTime();
inputEvent_t needTimeUpdate(applicationState_t *state);
void getWeekdayName(uint32_t weekdaynum, char *s);
void getTimeZoneName(uint32_t timezonenum, char* s);