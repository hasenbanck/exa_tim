#include "display.h"
#include "font.h"
#include "main.h"
#include "power.h"
#include "stm32l0xx_hal.h"

extern SPI_HandleTypeDef hspi1;
u8g2_t u8g2;

uint8_t u8g2_gpio_and_delay_stm32(U8X8_UNUSED u8x8_t *u8x8,
                                  U8X8_UNUSED uint8_t msg,
                                  U8X8_UNUSED uint8_t arg_int,
                                  U8X8_UNUSED void *arg_ptr) {
  switch (msg) {
  /* Function which implements a delay, arg_int contains the amount of ms */
  case U8X8_MSG_DELAY_MILLI:
    HAL_Delay(arg_int);
    break;

  /* Function which delays 10us */
  case U8X8_MSG_DELAY_10MICRO:
    for (uint16_t n = 0; n < 320; n++) {
      __NOP();
    }
    break;

  /* Function which delays 100ns */
  case U8X8_MSG_DELAY_100NANO:
    __NOP();
    break;

  /* Function to define the logic level of the clockline */
  case U8X8_MSG_GPIO_SPI_CLOCK:
    HAL_GPIO_WritePin(SCK_GPIO_Port, SCK_Pin, arg_int);
    break;

  /* Function to define the logic level of the data line to the display */
  case U8X8_MSG_GPIO_SPI_DATA:
    HAL_GPIO_WritePin(MOSI_GPIO_Port, MOSI_Pin, arg_int);
    break;

  /* Function to define the logic level of the CS line */
  case U8X8_MSG_GPIO_CS:
    HAL_GPIO_WritePin(CS_GPIO_Port, CS_Pin, arg_int);
    break;

  /* Function to define the logic level of the Data/ Command line */
  case U8X8_MSG_GPIO_DC:
    HAL_GPIO_WritePin(DC_GPIO_Port, DC_Pin, arg_int);
    break;

  /* Function to define the logic level of the RESET line */
  case U8X8_MSG_GPIO_RESET:
    HAL_GPIO_WritePin(RESET_GPIO_Port, RESET_Pin, arg_int);
    break;

  default:
    return 0; // A message was received which is not implemented, return 0 to
              // indicate an error
  }
  return 1; // command processed successfully.
}

uint8_t u8x8_byte_4wire_sw_spi_stm32(u8x8_t *u8x8, uint8_t msg, uint8_t arg_int,
                                     void *arg_ptr) {
  switch (msg) {
  case U8X8_MSG_BYTE_INIT:
    asm("NOP");
    break;

  case U8X8_MSG_BYTE_SET_DC:
    HAL_GPIO_WritePin(DC_GPIO_Port, DC_Pin, arg_int);
    break;

  case U8X8_MSG_BYTE_START_TRANSFER:
    HAL_GPIO_WritePin(CS_GPIO_Port, CS_Pin,
                      u8x8->display_info->chip_enable_level);
    asm("NOP");
    break;

  case U8X8_MSG_BYTE_SEND:
    HAL_SPI_Transmit(&hspi1, arg_ptr, arg_int, 100);
    break;

  case U8X8_MSG_BYTE_END_TRANSFER:
    HAL_GPIO_WritePin(CS_GPIO_Port, CS_Pin,
                      u8x8->display_info->chip_disable_level);
    asm("NOP");
    break;

  default:
    return 0; // A message was received which is not implemented, return 0 to
              // indicate an error
  }
  return 1; // command processed successfully.
}

void initDisplay(void) {
  initSPI1();
  u8g2_Setup_ssd1607_200x200_f(&u8g2, U8G2_R3, u8x8_byte_4wire_sw_spi_stm32,
                               u8g2_gpio_and_delay_stm32);
  u8g2_InitDisplay(&u8g2);
}

void drawDisplay(void) {
  u8g2_SetFont(&u8g2, keihansoukaishinumbers96);
  u8g2_DrawUTF8(&u8g2, 4, -4, "0179");
  u8g2_SendBuffer(&u8g2);
}

/* Only call this function when you want to put the whole system in sleep
 * Display need a reset when powering up, since we powered also the clock down */
void powerOffDisplay(void) {
  u8g2_SetPowerSave(&u8g2, 1);
}

bool isDisplayBusy(void) {
  if (HAL_GPIO_ReadPin(BUSY_GPIO_Port, BUSY_Pin) == GPIO_PIN_RESET) {
    return false;
  } else {
    return true;
  }
}
