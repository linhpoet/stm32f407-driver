

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


typedef struct
{
    uint8_t GPIO_PinNumber;
    uint8_t GPIO_PinMode;
    uint8_t GPIO_Speed;
    uint8_t GPIO_PuPdControl;
    uint8_t GPIOOPType;
    uint8_t GPIO_PinAltFunMode;
}GPIO_PinConfig_t;

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

void GPIO_Init(void);
void GPIO_PeriClockControl();
void GPIO_TogglePin();
void GPIO_ReadFromInputPin();
void GPIO_ReadFromInputPort();
void GPIO_WriteOutputPort();
void GPIO_WriteOutputPin();



#endif