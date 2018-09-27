#include "stm32l0xx_it.h"
#include "button.h"
#include "stm32l0xx.h"
#include "stm32l0xx_hal.h"

extern LPTIM_HandleTypeDef hlptim1;
extern UART_HandleTypeDef hlpuart1;
extern RTC_HandleTypeDef hrtc;
extern SPI_HandleTypeDef hspi1;
extern TIM_HandleTypeDef htim2;

void NMI_Handler(void) {}

void HardFault_Handler(void) {
  // clang-format off
  while (1);
  // clang-format on
}

void SVC_Handler(void) {}

void PendSV_Handler(void) {}

void SysTick_Handler(void) {
  HAL_IncTick();
  HAL_SYSTICK_IRQHandler();
}

/******************************************************************************/
/* STM32L0xx Peripheral Interrupt Handlers                                    */
/* Add here the Interrupt Handlers for the used peripherals.                  */
/* For the available peripheral interrupt handler names,                      */
/* please refer to the startup file (startup_stm32l0xx.s).                    */
/******************************************************************************/

void PVD_IRQHandler(void) { HAL_PWR_PVD_IRQHandler(); }

void RTC_IRQHandler(void) {
  HAL_RTC_AlarmIRQHandler(&hrtc);
  HAL_RTCEx_WakeUpTimerIRQHandler(&hrtc);
}

void RCC_IRQHandler(void) {}

void LPTIM1_IRQHandler(void) { HAL_LPTIM_IRQHandler(&hlptim1); }

void SPI1_IRQHandler(void) { HAL_SPI_IRQHandler(&hspi1); }

void TIM2_IRQHandler(void) { HAL_TIM_IRQHandler(&htim2); }

void AES_RNG_LPUART1_IRQHandler(void) { HAL_UART_IRQHandler(&hlpuart1); }