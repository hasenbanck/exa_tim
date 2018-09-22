#pragma once

#include "u8g2.h"
#include "logic.h"
#include <stdbool.h>

void initDisplay(void);
void drawDisplay(applicationState_t* state);
void powerOffDisplay(void);
void drawMenu(void);
bool isDisplayBusy(void);