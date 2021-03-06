#pragma once

#define VERSION_MAJOR "1"
#define VERSION_MINOR "0"
#define VERSION_PATCH "0"
#define PRINT_VERSION VERSION_MAJOR "." VERSION_MINOR "." VERSION_PATCH

#define ALARM_Pin GPIO_PIN_1
#define ALARM_GPIO_Port GPIOA
#define GNSS_EN_Pin GPIO_PIN_12
#define GNSS_EN_GPIO_Port GPIOA
#define DISP_EN_Pin GPIO_PIN_4
#define DISP_EN_GPIO_Port GPIOA
#define BUSY_Pin GPIO_PIN_6
#define BUSY_GPIO_Port GPIOA
#define DC_Pin GPIO_PIN_0
#define DC_GPIO_Port GPIOB
#define RESET_Pin GPIO_PIN_1
#define RESET_GPIO_Port GPIOB
#define SCK_Pin GPIO_PIN_5
#define SCK_GPIO_Port GPIOA
#define MOSI_Pin GPIO_PIN_7
#define MOSI_GPIO_Port GPIOA
#define CS_Pin GPIO_PIN_8
#define CS_GPIO_Port GPIOA
#define BTN1_Pin GPIO_PIN_5
#define BTN1_GPIO_Port GPIOB
#define BTN2_Pin GPIO_PIN_4
#define BTN2_GPIO_Port GPIOB
#define BTN3_Pin GPIO_PIN_7
#define BTN3_GPIO_Port GPIOB
#define BTN4_Pin GPIO_PIN_6
#define BTN4_GPIO_Port GPIOB

void _Error_Handler(char *, int);
#define Error_Handler() _Error_Handler(__FILE__, __LINE__)
