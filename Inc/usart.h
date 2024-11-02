<<<<<<< HEAD
/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    usart.h
  * @brief   This file contains all the function prototypes for
  *          the usart.c file
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
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
#ifndef __USART_H__
#define __USART_H__

#ifdef __cplusplus
extern "C" {
=======
/**
  ******************************************************************************
  * File Name          : USART.h
  * Description        : This file provides code for the configuration
  *                      of the USART instances.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __usart_H
#define __usart_H
#ifdef __cplusplus
 extern "C" {
>>>>>>> 21cb47735d7f375d8cec3fc12fde12452cbe2671
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

extern UART_HandleTypeDef huart1;
<<<<<<< HEAD

=======
extern UART_HandleTypeDef huart2;
>>>>>>> 21cb47735d7f375d8cec3fc12fde12452cbe2671
extern UART_HandleTypeDef huart3;

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

void MX_USART1_UART_Init(void);
<<<<<<< HEAD
=======
void MX_USART2_UART_Init(void);
>>>>>>> 21cb47735d7f375d8cec3fc12fde12452cbe2671
void MX_USART3_UART_Init(void);

/* USER CODE BEGIN Prototypes */

<<<<<<< HEAD

=======
>>>>>>> 21cb47735d7f375d8cec3fc12fde12452cbe2671
/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif
<<<<<<< HEAD

#endif /* __USART_H__ */

=======
#endif /*__ usart_H */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
>>>>>>> 21cb47735d7f375d8cec3fc12fde12452cbe2671
