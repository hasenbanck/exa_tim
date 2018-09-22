#pragma once

#include "u8g2.h"
#include <stdbool.h>

void initDisplay(void);
void drawDisplay(void);
void powerOffDisplay(void);
void drawMenu(void);
bool isDisplayBusy(void);