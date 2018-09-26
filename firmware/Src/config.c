#include "config.h"
#include "stm32l0xx_hal.h"

#define CONFIG_VERSION 0xDEADBEE

void checkConfig(void) {
  if (*(uint32_t *)(DATA_EEPROM_BASE) != CONFIG_VERSION) {
    HAL_FLASHEx_DATAEEPROM_Unlock();
    HAL_FLASHEx_DATAEEPROM_Program(FLASH_TYPEPROGRAMDATA_WORD, DATA_EEPROM_BASE,
                                   CONFIG_VERSION);
    HAL_FLASHEx_DATAEEPROM_Lock();
    config_t config = {0};
    config.syncActivated = true;
    config.alarmHours = 0x18;
    config.alarmMinutes = 0x00;
    config.timezone = 0x01;
    saveConfig(&config);
  }
}

config_t loadConfig(void) {
  config_t config;
  config.alarmActivated = (bool)*(uint32_t *)(DATA_EEPROM_BASE + 4);
  config.alarmHours = (uint8_t) * (uint32_t *)(DATA_EEPROM_BASE + 8);
  config.alarmMinutes = (uint8_t) * (uint32_t *)(DATA_EEPROM_BASE + 12);
  config.syncActivated = (bool)*(uint32_t *)(DATA_EEPROM_BASE + 16);
  config.timezone = *(uint32_t *)(DATA_EEPROM_BASE + 20);
  return config;
}

void saveConfig(config_t *config) {
  config_t old = loadConfig();
  HAL_FLASHEx_DATAEEPROM_Unlock();
  if (old.alarmActivated != config->alarmActivated) {
    HAL_FLASHEx_DATAEEPROM_Program(FLASH_TYPEPROGRAMDATA_WORD,
                                   DATA_EEPROM_BASE + 4,
                                   (uint32_t)config->alarmActivated);
  }
  if (old.alarmHours != config->alarmHours) {
    HAL_FLASHEx_DATAEEPROM_Program(FLASH_TYPEPROGRAMDATA_WORD,
                                   DATA_EEPROM_BASE + 8,
                                   (uint32_t)config->alarmHours);
  }
  if (old.alarmMinutes != config->alarmMinutes) {
    HAL_FLASHEx_DATAEEPROM_Program(FLASH_TYPEPROGRAMDATA_WORD,
                                   DATA_EEPROM_BASE + 12,
                                   (uint32_t)config->alarmMinutes);
  }
  if (old.syncActivated != config->syncActivated) {
    HAL_FLASHEx_DATAEEPROM_Program(FLASH_TYPEPROGRAMDATA_WORD,
                                   DATA_EEPROM_BASE + 16,
                                   (uint32_t)config->syncActivated);
  }
  if (old.timezone != config->timezone) {
    HAL_FLASHEx_DATAEEPROM_Program(FLASH_TYPEPROGRAMDATA_WORD,
                                   DATA_EEPROM_BASE + 20,
                                   (uint32_t)config->timezone);
  }
  HAL_FLASHEx_DATAEEPROM_Lock();
}