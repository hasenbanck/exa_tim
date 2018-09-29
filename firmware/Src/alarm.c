#include "alarm.h"
#include "stm32l0xx_hal.h"

#include <stdbool.h>

extern TIM_HandleTypeDef htim2;

static bool toneActive = false;

void startAlarmTone(void) {
  toneActive = true;
}

void stopAlarmTone(void) {
  toneActive = false;
  HAL_TIM_PWM_Stop_IT(&htim2, TIM_CHANNEL_2);
}

void toggleAlarmTone(void) {
  if (toneActive)
    HAL_TIM_PWM_Stop_IT(&htim2, TIM_CHANNEL_2);
  else
    HAL_TIM_PWM_Start_IT(&htim2, TIM_CHANNEL_2);
  toneActive = !toneActive;
}