#pragma once

typedef enum wakeupBy {
    WKUP_PWR        = 0x1,
    WKUP_RTC        = 0x2,
    WKUP_BUTTON     = 0x3,
    WKUP_GNSS       = 0x4,
    WKUP_GNSS_RX    = 0x5

} wakeupBy;

void initLPUART1(void);
void initSPI1(void);

void initNormalMode(void);
void switchStopMode(void);
void switchStandbyMode(void);

wakeupBy getWakeup(void);
void setWakeup(wakeupBy reason);
void clearWakeup(void);

