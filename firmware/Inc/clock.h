#pragma once

#include "logic.h"

#include <stdbool.h>
#include <stdint.h>
#include <time.h>

struct tm getTime();
inputEvent_t needTimeUpdate(applicationState_t *state);
void getTimeZoneName(uint32_t num, char* s);