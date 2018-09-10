#pragma once

#include "main.h"
#include "stm32l0xx_hal.h"

void NMI_Handler(void);
void HardFault_Handler(void);
void SVC_Handler(void);
void PendSV_Handler(void);
void SysTick_Handler(void);
void PVD_IRQHandler(void);
void RTC_IRQHandler(void);
void RCC_IRQHandler(void);
void DMA1_Channel2_3_IRQHandler(void);
void DMA1_Channel4_5_6_7_IRQHandler(void);
void LPTIM1_IRQHandler(void);
void SPI1_IRQHandler(void);
