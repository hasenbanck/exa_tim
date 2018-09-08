#include "stm32l0xx_hal.h"

extern DMA_HandleTypeDef hdma_lpuart1_tx;
extern DMA_HandleTypeDef hdma_lpuart1_rx;
extern DMA_HandleTypeDef hdma_spi1_tx;

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
  HAL_NVIC_SetPriority(PVD_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(PVD_IRQn);
  /* RCC_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(RCC_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(RCC_IRQn);
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

    /* LPUART1 DMA Init */
    /* LPUART1_TX Init */
    hdma_lpuart1_tx.Instance = DMA1_Channel2;
    hdma_lpuart1_tx.Init.Request = DMA_REQUEST_5;
    hdma_lpuart1_tx.Init.Direction = DMA_MEMORY_TO_PERIPH;
    hdma_lpuart1_tx.Init.PeriphInc = DMA_PINC_DISABLE;
    hdma_lpuart1_tx.Init.MemInc = DMA_MINC_ENABLE;
    hdma_lpuart1_tx.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
    hdma_lpuart1_tx.Init.MemDataAlignment = DMA_MDATAALIGN_BYTE;
    hdma_lpuart1_tx.Init.Mode = DMA_NORMAL;
    hdma_lpuart1_tx.Init.Priority = DMA_PRIORITY_LOW;
    if (HAL_DMA_Init(&hdma_lpuart1_tx) != HAL_OK) {
      _Error_Handler(__FILE__, __LINE__);
    }

    __HAL_LINKDMA(huart, hdmatx, hdma_lpuart1_tx);

    /* LPUART1_RX Init */
    hdma_lpuart1_rx.Instance = DMA1_Channel6;
    hdma_lpuart1_rx.Init.Request = DMA_REQUEST_5;
    hdma_lpuart1_rx.Init.Direction = DMA_PERIPH_TO_MEMORY;
    hdma_lpuart1_rx.Init.PeriphInc = DMA_PINC_DISABLE;
    hdma_lpuart1_rx.Init.MemInc = DMA_MINC_ENABLE;
    hdma_lpuart1_rx.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
    hdma_lpuart1_rx.Init.MemDataAlignment = DMA_MDATAALIGN_BYTE;
    hdma_lpuart1_rx.Init.Mode = DMA_NORMAL;
    hdma_lpuart1_rx.Init.Priority = DMA_PRIORITY_LOW;
    if (HAL_DMA_Init(&hdma_lpuart1_rx) != HAL_OK) {
      _Error_Handler(__FILE__, __LINE__);
    }

    __HAL_LINKDMA(huart, hdmarx, hdma_lpuart1_rx);
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

    /* LPUART1 DMA DeInit */
    HAL_DMA_DeInit(huart->hdmatx);
    HAL_DMA_DeInit(huart->hdmarx);
  }
}

void HAL_RTC_MspInit(RTC_HandleTypeDef *hrtc) {
  if (hrtc->Instance == RTC) {
    /* Peripheral clock enable */
    __HAL_RCC_RTC_ENABLE();
    /* RTC interrupt Init */
    HAL_NVIC_SetPriority(RTC_IRQn, 0, 0);
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

    /* SPI1 DMA Init */
    /* SPI1_TX Init */
    hdma_spi1_tx.Instance = DMA1_Channel3;
    hdma_spi1_tx.Init.Request = DMA_REQUEST_1;
    hdma_spi1_tx.Init.Direction = DMA_MEMORY_TO_PERIPH;
    hdma_spi1_tx.Init.PeriphInc = DMA_PINC_DISABLE;
    hdma_spi1_tx.Init.MemInc = DMA_MINC_ENABLE;
    hdma_spi1_tx.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
    hdma_spi1_tx.Init.MemDataAlignment = DMA_MDATAALIGN_BYTE;
    hdma_spi1_tx.Init.Mode = DMA_NORMAL;
    hdma_spi1_tx.Init.Priority = DMA_PRIORITY_LOW;
    if (HAL_DMA_Init(&hdma_spi1_tx) != HAL_OK) {
      _Error_Handler(__FILE__, __LINE__);
    }

    __HAL_LINKDMA(hspi, hdmatx, hdma_spi1_tx);

    /* SPI1 interrupt Init */
    HAL_NVIC_SetPriority(SPI1_IRQn, 0, 0);
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

    /* SPI1 DMA DeInit */
    HAL_DMA_DeInit(hspi->hdmatx);

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
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
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
