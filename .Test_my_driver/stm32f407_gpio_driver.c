/*
 * stm32f407vg_gpio_driver.c
 *
 *  Created on: Oct 18, 2021
 *      Author: Linh
 */
 
 #include "stm32f407_gpio_driver.h"
 
 /*
*	GPIO control
*/

void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EnorDi)
{
	if(EnorDi == ENABLE)
	{
		if(pGPIOx == GPIOA)
		{
			GPIOA_PCLK_EN();
		}else if(pGPIOx == GPIOB)
		{
			GPIOB_PCLK_EN();
		}else if(pGPIOx == GPIOC)
		{
			GPIOC_PCLK_EN();
		}else if(pGPIOx == GPIOD)
		{
			GPIOD_PCLK_EN();
		}else if(pGPIOx == GPIOE)
		{
			GPIOE_PCLK_EN();
		}else if(pGPIOx == GPIOF)
		{
			GPIOF_PCLK_EN();
		}else if(pGPIOx == GPIOG)
		{
			GPIOG_PCLK_EN();
		}else if(pGPIOx == GPIOH)
		{
			GPIOH_PCLK_EN();
		}else if(pGPIOx == GPIOI)
		{
			GPIOI_PCLK_EN();
		}
	}
	
	if(EnorDi == DISABLE)
	{
		if(pGPIOx == GPIOA)
		{
			GPIOA_PCLK_DIS();
		}else if(pGPIOx == GPIOB)
		{
			GPIOB_PCLK_DIS();
		}else if(pGPIOx == GPIOC)
		{
			GPIOC_PCLK_DIS();
		}else if(pGPIOx == GPIOD)
		{
			GPIOD_PCLK_DIS();
		}else if(pGPIOx == GPIOE)
		{
			GPIOE_PCLK_DIS();
		}else if(pGPIOx == GPIOF)
		{
			GPIOF_PCLK_DIS();
		}else if(pGPIOx == GPIOG)
		{
			GPIOG_PCLK_DIS();
		}else if(pGPIOx == GPIOH)
		{
			GPIOH_PCLK_DIS();
		}else if(pGPIOx == GPIOI)
		{
			GPIOI_PCLK_DIS();
		}
	}
}



void GPIO_Init(GPIO_Handle_t *pGPIOHandle)
{
	
}



void GPIO_TogglePin(GPIO_RegDef_t *pGPIOx, GPIO_PIN_NUMBER PinNumber)
{
	
	pGPIOx->ODR  ^= ( 1 << PinNumber);
	/*
	if(pGPIOx->ODR & (1<<PinNumber))
	{
		pGPIOx->ODR &= ~(1<<PinNumber);
	}else
	{
		pGPIOx->ODR |= 1<<PinNumber;
	}
	*/
}



uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber)
{
	uint8_t ReadValue;
	ReadValue = (uint8_t)(0x01 & ((pGPIOx->IDR) >> PinNumber));
	return ReadValue;
}




uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx)
{
	return (uint16_t)(pGPIOx->IDR);
}



void GPIO_WriteOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t u16Value)
{
	pGPIOx->ODR = u16Value;
}



void GPIO_WriteOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t EnorDi)
{
	if(EnorDi == DISABLE)
	{
		pGPIOx->ODR &= ~(1<<PinNumber);
	}else if(EnorDi == ENABLE)
	{
		pGPIOx->ODR |= 1<<PinNumber;
	}
}

/*
 * IRQ Configuration and ISR handling
 */
void GPIO_IRQInterruptConfig(uint8_t IRQNumber, uint8_t EnorDi)
{
	if(EnorDi == ENABLE)
	{
		if(IRQNumber<=31)
		{
			*NVIC_ICER0 |= 1<<IRQNumber;
		}else if(IRQNumber >=32 && IRQNumber<=63)			//32 to 63
		{
			*NVIC_ICER1 |= 1 << (IRQNumber - 32);
		}else if(IRQNumber >=64 && IRQNumber<=95)			//64 to 95
		{
			*NVIC_ICER2 |= 1 << (IRQNumber - 64);
		}else if(IRQNumber >=96 && IRQNumber<=127)			//96 to 127
		{
			*NVIC_ICER3 |= 1 << (IRQNumber - 96);
		}
	}

	if(EnorDi == DISABLE)
	{
		if(IRQNumber <= 31)
		{
			*NVIC_ICER0 &= ~(1 << IRQNumber);
		}else if(IRQNumber >= 32 && IRQNumber <= 63)			//32 to 63
		{
			*NVIC_ICER1 &= ~(1 << (IRQNumber - 32);
		}else if(IRQNumber >=64 && IRQNumber<=95)			//64 to 95
		{
			*NVIC_ICER2 &= ~(1 << (IRQNumber - 64);
		}else if(IRQNumber >=96 && IRQNumber<=127)			//96 to 127
		{
			*NVIC_ICER3 &= ~(1 << (IRQNumber - 96);
		}
	}
}

/*
*	config priority for IRQ
	Co 255 muc priority cho IRQ, duoc gan gia tri bang 8 bit cua cac thanh ghi IPR[]
	Trong vidoe thi bao rang chi co 4/8 bit do dung de quy dinh priority, code duoi dung ca 8 bit
	1 thanh ghi ipr[] gom 4 fileds, dung de dat muc uu tien cho ngat tuong ung
	vdk stm32f4 gan cac ngat vao cac vi tri tu 0-n cua arm
*/

void GPIO_IRQPriorityConfig(uint8_t IRQNumber, uint32_t IRQPriority)
{
	/*1. find out the ipr register of IRQNumber*/
	uint8_t iprx = IRQNumber/4;
	/*2. tim ra field(8 bit) quy dinh priority cua loai IRQ*/
	uint8_t iprx_section = IRQNumber%4;
	/*Dua priority ve 0 truoc, vi neu chuyen tu muc IRQPriority= 1 sang 2 thi IRQPriority|0x02 = 0x03*/
	*(NVIC_IPR_BASE_ADDR + iprx*4) &= ~(0xff << iprx_section)
	/*moi thanh ghi 4 byte nen iprx*4 de ra duoc dia chi thanh ghi*/
	*(NVIC_IPR_BASE_ADDR + iprx*4) |= ~(IRQPriority << iprx_section);
}


void GPIO_IRQHandling(uint8_t PinNumber)
{
	/*	clear pending
		This bit is cleared by writing a ‘1’ into the bit.
	*/
	//clear the exti pr register corresponding to the pin number
	if(EXTI->PR & ( 1 << PinNumber))
	{
		//clear
		EXTI->PR |= ( 1 << PinNumber);
	}
}
