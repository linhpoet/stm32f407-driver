#include <stdio.h>
#include "stm32f407vg.h"

uint32_t *pSyst_CSR = (uint32_t*)0xE000E010;
uint32_t *pSYST_RVR = (uint32_t*)0xE000E014;
uint32_t *pSYST_CVR = (uint32_t*)0xE000E018;

typedef struct
{
	volatile uint32_t CSR;
	volatile uint32_t RVR;
	volatile uint32_t CVR;
	volatile uint32_t CALIB;
}SYSTICK_RegDef_t;

#define SysTick_BaseAddr	0xE000E010
#define Systick		((SYSTICK_RegDef_t*)SysTick_BaseAddr)

void testLED();
void Systick_Delay_ms(uint32_t u32Delay);

int main()
{
	testLED();
	while(1)
	{
		GPIO_TogglePin(GPIOD, GPIO_PIN_12);
		Systick_Delay_ms(1000);
	}
}

void Systick_Delay_ms(uint32_t u32Delay)
{
	while(u32Delay)
	{
		/*Cortex System timer clock max 168/8 MHz*/
		Systick->RVR = 21000-1;
		Systick->CVR = 0;
		
		/*no exception*/
		/*clear counter flag*/
		/*enable counter*/
		/*processor clock - 72M*/
		Systick->CSR = 0x05;
	
		while(((Systick->CSR) & (1<<16)) == 0)
		{
			
		}
		--u32Delay;
	}
}

void testLED()
{
	GPIO_PeriClockControl(GPIOD, ENABLE);
	GPIOD->MODER &= 0xfcffffff;
	GPIOD->MODER |= 0x55555555;
	
	GPIOD->ODR |= 1<<12;
	GPIOD->ODR |= 1<<13;
	GPIOD->ODR |= 1<<14;
	GPIOD->ODR |= 1<<15;
	//GPIO_TogglePin(GPIOD, GPIO_PIN_12);
	//GPIO_TogglePin(GPIOD, GPIO_PIN_13);
}