/*
 * stm32f407vg_gpio_driver.h
 *
 *  Created on: Oct 18, 2021
 *      Author: Linh
 */

#ifndef INC_STM32F407XX_GPIO_DRIVER_H_
#define INC_STM32F407XX_GPIO_DRIVER_H_

#include "stm32f407vg.h"


/*
*   gpio register definition structure
*/
typedef struct
{
    __IO uint32_t MODER;
    __IO uint32_t OTYPER;
    __IO uint32_t OSPEED;
    __IO uint32_t PUPDR;
    __IO uint32_t IDR;
    __IO uint32_t ODR;
    __IO uint32_t OSRR;
    __IO uint32_t LCKR;
    __IO uint32_t AFR[2];                   /*AFR[0] = AFRLow, AFR[1] = AFRHigh*/
}GPIO_RegDef_t;


typedef enum
{
    GPIO_PIN_0 = 0,
    GPIO_PIN_1,
    GPIO_PIN_2,
    GPIO_PIN_3,
    GPIO_PIN_4,
    GPIO_PIN_5,
    GPIO_PIN_6,
    GPIO_PIN_7,
    GPIO_PIN_8,
    GPIO_PIN_9,
    GPIO_PIN_10,
    GPIO_PIN_11,
    GPIO_PIN_12,
    GPIO_PIN_13,
    GPIO_PIN_14,
    GPIO_PIN_15
}GPIO_PIN_NUMBER;

typedef enum
{
	GPIO_MODE_IN = 0,
	GPIO_MODE_OUT,
	GPIO_MODE_ALTFN,
	GPIO_MODE_ANALOG
}GPIO_PinMode_t;

typedef struct
{
    GPIO_PIN_NUMBER GPIO_PinNumber;
    GPIO_PinMode_t GPIO_PinMode;
    uint8_t GPIO_Speed;
    uint8_t GPIO_PuPdControl;
    uint8_t GPIOOPType;
    uint8_t GPIO_PinAltFunMode;
}GPIO_PinConfig_t;


/*
*	GPIO control
*/
void GPIO_Init(GPIO_RegDef_t *pGPIOx, GPIO_PinConfig_t *GPIO_PinConfig);
void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EnorDi);
void GPIO_TogglePin(GPIO_RegDef_t *pGPIOx, GPIO_PIN_NUMBER PinNumber);
uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx);
void GPIO_WriteOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t u16Value);
void GPIO_WriteOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t EnorDi);


/*
 * IRQ Configuration and ISR handling
 */
void GPIO_IRQInterruptConfig(uint8_t IRQNumber, uint8_t EnorDi);
void GPIO_IRQPriorityConfig(uint8_t IRQNumber, uint32_t IRQPriority);
void GPIO_IRQHandling(uint8_t PinNumber);




#endif	/*	INC_STM32F407XX_GPIO_DRIVER_H_	*/



