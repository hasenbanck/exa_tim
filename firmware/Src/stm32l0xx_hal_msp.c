#include "stm32l0xx_hal.h"

extern void _Error_Handler(char *, int);

/* Initializes the Global MSP */
void HAL_MspInit(void) {
  __HAL_RCC_SYSCFG_CLK_ENABLE();
  __HAL_RCC_PWR_CLK_ENABLE();

  /* System interrupt init */
  /* SVC_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(SVC_IRQn, 0, 0);
  /* PendSV_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(PendSV_IRQn, 0, 0);
  /* SysTick_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(SysTick_IRQn, 0, 0);

  /* Peripheral interrupt init */
  /* PVD_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(PVD_IRQn, 1, 0);
  HAL_NVIC_EnableIRQ(PVD_IRQn);
  /* RCC_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(RCC_IRQn, 1, 0);
  HAL_NVIC_EnableIRQ(RCC_IRQn);
}

void HAL_LPTIM_MspInit(LPTIM_HandleTypeDef *hlptim) {
  if (hlptim->Instance == LPTIM1) {
    /* Peripheral clock enable */
    __HAL_RCC_LPTIM1_CLK_ENABLE();
    /* LPTIM1 interrupt Init */
    HAL_NVIC_SetPriority(LPTIM1_IRQn, 2, 0);
    HAL_NVIC_EnableIRQ(LPTIM1_IRQn);
  }
}

void HAL_LPTIM_MspDeInit(LPTIM_HandleTypeDef *hlptim) {
  if (hlptim->Instance == LPTIM1) {
    /* Peripheral clock disable */
    __HAL_RCC_LPTIM1_CLK_DISABLE();
    /* LPTIM1 interrupt DeInit */
    HAL_NVIC_DisableIRQ(LPTIM1_IRQn);
  }
}

void HAL_UART_MspInit(UART_HandleTypeDef *huart) {
  GPIO_InitTypeDef GPIO_InitStruct;
  if (huart->Instance == LPUART1) {
    /* Peripheral clock enable */
    __HAL_RCC_LPUART1_CLK_ENABLE();

    /** LPUART1 GPIO Configuration
     *  PA2     ------> LPUART1_TX
     *  PA3     ------> LPUART1_RX
     */
    GPIO_InitStruct.Pin = GPIO_PIN_2 | GPIO_PIN_3;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF6_LPUART1;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    /* LPUART1 interrupt Init */
    HAL_NVIC_SetPriority(AES_RNG_LPUART1_IRQn, 1, 0);
    HAL_NVIC_EnableIRQ(AES_RNG_LPUART1_IRQn);
  }
}

void HAL_UART_MspDeInit(UART_HandleTypeDef *huart) {
  if (huart->Instance == LPUART1) {
    /* Peripheral clock disable */
    __HAL_RCC_LPUART1_CLK_DISABLE();

    /** LPUART1 GPIO Configuration
     *  PA2     ------> LPUART1_TX
     *  PA3     ------> LPUART1_RX
     */
    HAL_GPIO_DeInit(GPIOA, GPIO_PIN_2 | GPIO_PIN_3);

    /* LPUART1 interrupt DeInit */
    HAL_NVIC_DisableIRQ(AES_RNG_LPUART1_IRQn);
  }
}

void HAL_RTC_MspInit(RTC_HandleTypeDef *hrtc) {
  if (hrtc->Instance == RTC) {
    /* Peripheral clock enable */
    __HAL_RCC_RTC_ENABLE();
    /* RTC interrupt Init */
    HAL_NVIC_SetPriority(RTC_IRQn, 1, 0);
    HAL_NVIC_EnableIRQ(RTC_IRQn);
  }
}

void HAL_RTC_MspDeInit(RTC_HandleTypeDef *hrtc) {
  if (hrtc->Instance == RTC) {
    /* Peripheral clock disable */
    __HAL_RCC_RTC_DISABLE();

    /* RTC interrupt DeInit */
    HAL_NVIC_DisableIRQ(RTC_IRQn);
  }
}

void HAL_SPI_MspInit(SPI_HandleTypeDef *hspi) {
  GPIO_InitTypeDef GPIO_InitStruct;
  if (hspi->Instance == SPI1) {
    /* Peripheral clock enable */
    __HAL_RCC_SPI1_CLK_ENABLE();

    /** SPI1 GPIO Configuration
     *  PA5     ------> SPI1_SCK
     *  PA7     ------> SPI1_MOSI
     */
    GPIO_InitStruct.Pin = GPIO_PIN_5 | GPIO_PIN_7;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF0_SPI1;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    /* SPI1 interrupt Init */
    HAL_NVIC_SetPriority(SPI1_IRQn, 1, 0);
    HAL_NVIC_EnableIRQ(SPI1_IRQn);
  }
}

void HAL_SPI_MspDeInit(SPI_HandleTypeDef *hspi) {
  if (hspi->Instance == SPI1) {
    /* Peripheral clock disable */
    __HAL_RCC_SPI1_CLK_DISABLE();

    /** SPI1 GPIO Configuration
     *  PA5     ------> SPI1_SCK
     *  PA7     ------> SPI1_MOSI
     */
    HAL_GPIO_DeInit(GPIOA, GPIO_PIN_5 | GPIO_PIN_7);

    /* SPI1 interrupt DeInit */
    HAL_NVIC_DisableIRQ(SPI1_IRQn);
  }
}

void HAL_TIM_PWM_MspInit(TIM_HandleTypeDef *htim_pwm) {
  if (htim_pwm->Instance == TIM2) {
    /* Peripheral clock enable */
    __HAL_RCC_TIM2_CLK_ENABLE();
  }
}

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim) {
  GPIO_InitTypeDef GPIO_InitStruct;
  if (htim->Instance == TIM2) {
    /** TIM2 GPIO Configuration
     *  PA1     ------> TIM2_CH2
     */
    GPIO_InitStruct.Pin = ALARM_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF2_TIM2;
    HAL_GPIO_Init(ALARM_GPIO_Port, &GPIO_InitStruct);
  }
}

void HAL_TIM_PWM_MspDeInit(TIM_HandleTypeDef *htim_pwm) {
  if (htim_pwm->Instance == TIM2) {
    /* Peripheral clock disable */
    __HAL_RCC_TIM2_CLK_DISABLE();
  }
}
