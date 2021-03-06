#include "display.h"
#include "clock.h"
#include "config.h"
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

void initDisplay(applicationState_t *state) {
  HAL_GPIO_WritePin(GPIOA, DISP_EN_Pin, GPIO_PIN_SET);
  initSPI1();

  // Do a full refresh every hour, a fast refresh every other minute
  if (state->activeMenu == menu_watch && state->currentMinutes == 0)
    u8g2_Setup_ssd1607_200x200_f(&u8g2, U8G2_R3, u8x8_byte_4wire_sw_spi_stm32,
                                 u8g2_gpio_and_delay_stm32, false);
  else
    u8g2_Setup_ssd1607_200x200_f(&u8g2, U8G2_R3, u8x8_byte_4wire_sw_spi_stm32,
                                 u8g2_gpio_and_delay_stm32, true);
  u8g2_InitDisplay(&u8g2);
}

void drawDisplay(applicationState_t *state) {
  config_t config = loadConfig();
  if (state->activeMenu == menu_watch) {

    u8g2_SetFont(&u8g2, u8g2_font_open_iconic_embedded_2x_t);

    if (config.alarmActivated)
      u8g2_DrawGlyph(&u8g2, 0, 16, 65);

    // Checks if PVDO is set (low battery)
    if (__HAL_PWR_GET_FLAG(
            PWR_FLAG_PVDO)) /* We can't move this into the logic handling,
                             * since it would be too early for the PVD to
                             *  have a valid value
                             */
      u8g2_DrawGlyph(&u8g2, 92, 16, 64);

    if (state->successGNSS)
      u8g2_DrawGlyph(&u8g2, 184, 16, 70);

    // TODO Change to exa_pico mode with a button press
    char s[25];
    sprintf(&s[0], "%02d%02d", state->currentHours, state->currentMinutes);
    u8g2_SetFont(&u8g2, keihansoukaishinumbers96);
    u8g2_DrawUTF8(&u8g2, 4, -4, &s[0]);
    //u8g2_SetFont(&u8g2, u8g2_font_inb46_mr);
    //u8g2_DrawUTF8(&u8g2, 4, 120, &s[0]);

    u8g2_SetFont(&u8g2, u8g2_font_logisoso16_tf);
    char day[10];
    getWeekdayName(state->currentWeekday, day);
    sprintf(&s[0], "%d-%02d-%02d %s", 1900+state->currentYear, state->currentMonth + 1, state->currentDay, day);
    u8g2_DrawUTF8(&u8g2, 0, 190, s);

    u8g2_SendBuffer(&u8g2);
  }
  if (state->activeMenu == menu_options) {
    u8g2_SetFont(&u8g2, u8g2_font_logisoso16_tf);
    u8g2_DrawUTF8(&u8g2, 3, 20, "Alarm:");
    u8g2_DrawUTF8(&u8g2, 3, 40, "Alarm Time:");
    u8g2_DrawUTF8(&u8g2, 3, 60, "Time Sync:");
    u8g2_DrawUTF8(&u8g2, 3, 80, "Timezone:");
    if (config.alarmActivated) {
      u8g2_DrawUTF8(&u8g2, 120, 20, "ON");
    } else {
      u8g2_DrawUTF8(&u8g2, 120, 20, "OFF");
    }

    char s[17];
    sprintf(&s[0], "%02x:%02x", config.alarmHours, config.alarmMinutes);
    u8g2_DrawUTF8(&u8g2, 120, 40, &s[0]);

    if (config.syncActivated) {
      u8g2_DrawUTF8(&u8g2, 120, 60, "ON");
    } else {
      u8g2_DrawUTF8(&u8g2, 120, 60, "OFF");
    }

    getTimeZoneName(config.timezone, s);
    u8g2_DrawUTF8(&u8g2, 3, 100, s);

    u8g2_DrawUTF8(&u8g2, 3, 140, "Manual Time Sync");

    u8g2_DrawUTF8(&u8g2, 3, 200, "Firmware: " PRINT_VERSION);

    // Draw selection frame
    switch (state->selectedItem) {
    case 0:
      u8g2_DrawFrame(&u8g2, 103, 1, 97, 22);
      break;

    case 1:
      u8g2_DrawFrame(&u8g2, 116, 21, 30, 22);
      break;

    case 2:
      u8g2_DrawFrame(&u8g2, 140, 21, 30, 22);
      break;

    case 3:
      u8g2_DrawFrame(&u8g2, 103, 41, 97, 22);
      break;

    case 4:
      u8g2_DrawFrame(&u8g2, 1, 81, 197, 22);
      break;

    case 5:
      u8g2_DrawFrame(&u8g2, 1, 121, 164, 22);
      break;

    case 6:
      u8g2_DrawFrame(&u8g2, 1, 141, 110, 22);
      break;

    default:
      break;
    }

    u8g2_SendBuffer(&u8g2);
  }
}

/* Only call this function when you want to put the whole system in sleep
 * Display need a reset when powering up, since we powered also the clock down
 * TODO: Shut down the whole module via DISP_EN
 */
void powerOffDisplay(void) {
  u8g2_SetPowerSave(&u8g2, 1);
  HAL_GPIO_WritePin(GPIOA, DISP_EN_Pin, GPIO_PIN_RESET);
}

bool isDisplayBusy(void) {
  if (HAL_GPIO_ReadPin(BUSY_GPIO_Port, BUSY_Pin) == GPIO_PIN_RESET) {
    return false;
  } else {
    return true;
  }
}
