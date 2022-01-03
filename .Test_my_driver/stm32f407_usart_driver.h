

#ifndef INC_STM32F407XX_GPIO_DRIVER_H_
#define INC_STM32F407XX_GPIO_DRIVER_H_

#include "stm32f407vg.h"


/*
*   config struct for usart register
*/
typedef struct
{
    __IO uint32_t SR;
    __IO uint32_t DR;
    __IO uint32_t BRR;
    __IO uint32_t CR1;
    __IO uint32_t CR2;
    __IO uint32_t CR3;
    __IO uint32_t GTPR; 
}USART_RegDef_t;


/*
 * Configuration structure for USARTx peripheral
 */
typedef struct
{
    uint8_t USART_Mode;
    uint32_t USART_Baud;
    uint8_t USART_NumOfStopBits;
    uint8_t USART_WordLength;
    uint8_t USART_ParityControl;
    uint8_t USART_HWFlowControl;
}USART_Config_t;


/*
*   Handle structure for USARTxPeripheral
*/
typedef struct
{
    USART_RegDef_t *pUSARTx;
    USART_Config_t USART_Config;
    uint8_t *pTxBuffer;
    uint8_t *pRxBUffer;
    uint32_t TxLen;
    uint32_t RxLen;
    uint8_t TxBusyState;
    uint8_t RxBusyState;
}USART_Handle_t;


/*
*   USART Baud
*/
#define USART_Baud_1200          1200
#define USART_Baud_2400          2400
#define USART_Baud_9600          9600
#define USART_Baud_19200          19200
#define USART_Baud_38400          38400
#define USART_Baud_57600          57600
#define USART_Baud_115200          115200
#define USART_Baud_230400          230400
#define USART_Baud_460800          460800
#define USART_Baud_921600          921600
#define USART_Baud_2M            2000000
#define USART_Baud_3M            3000000




void USART_PeriClockControl(USART_RegDef_t *pUSARTx, uint8_t EnorDi);
void USART_Init();
void USART_DeInit();
void USART_SentData();
void USART_ReceiveData();
void USART_ITConfig();
void USART_GetITStatus();
void USART_ClearPendingBit();
void USART_GetFlagStatus();
void USART_ClearFlag();

/*
USART Driver for STM32F1
- USART_Init
- USART_SendData
- USART_ReceiveData
- USART_ITConfig
- USART_GetITStatus
- USART_ClearPendingBit
- USART_GetFlagStatus
- USART_ClearFlag
*/


#endif