/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdbool.h>
#include <stdio.h>
#include "application.h"
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */
typedef enum
{	
	KEY_NAME_UP = 0,
	KEY_NAME_DOWN ,
	KEY_NAME_ENTER,
}key_name_t;
/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define E290_GPIO11_Pin GPIO_PIN_2
#define E290_GPIO11_GPIO_Port GPIOA
#define E290_IRQ_Pin GPIO_PIN_3
#define E290_IRQ_GPIO_Port GPIOA
#define SPI_CS_Pin GPIO_PIN_4
#define SPI_CS_GPIO_Port GPIOA
#define E290_RF_SET_Pin GPIO_PIN_0
#define E290_RF_SET_GPIO_Port GPIOB
#define E290_GPIO3_Pin GPIO_PIN_1
#define E290_GPIO3_GPIO_Port GPIOB
#define E290_TXEN_Pin GPIO_PIN_12
#define E290_TXEN_GPIO_Port GPIOB
#define E290_RXEN_Pin GPIO_PIN_13
#define E290_RXEN_GPIO_Port GPIOB
#define LED_TX_Pin GPIO_PIN_15
#define LED_TX_GPIO_Port GPIOA
#define BUZZER_PWM_Pin GPIO_PIN_3
#define BUZZER_PWM_GPIO_Port GPIOB
#define KEY_UP_Pin GPIO_PIN_4
#define KEY_UP_GPIO_Port GPIOB
#define USB_CTRL_Pin GPIO_PIN_5
#define USB_CTRL_GPIO_Port GPIOB
#define LED_RX_Pin GPIO_PIN_6
#define LED_RX_GPIO_Port GPIOB
#define KEY_ENTER_Pin GPIO_PIN_7
#define KEY_ENTER_GPIO_Port GPIOB
#define KEY_DOWN_Pin GPIO_PIN_9
#define KEY_DOWN_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

void usb_printf(const char *format, ...);

void gpio_usb_ctrl_on(void);
void gpio_usb_ctrl_off(void);
void gpio_led_tx_on(void);
void gpio_led_tx_off(void);
void gpio_led_rx_on(void);
void gpio_led_rx_off(void);
void buzzer_on(void);
void buzzer_off(void);
void buzzer_button_push(void);

bool key_check_press( key_name_t name );
void key_set_continue( key_name_t name , bool enable );
void key_timer_1ms_interrupt_callback(void);

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
