#include <stdio.h>
#include "stm32f407vg.h"

void testLED();

int main()
{
	testLED();

}

void testLED()
{
	GPIOD_PCLK_EN();
	GPIOD->MODER &= 0xfcffffff;
	GPIOD->MODER |= 0x55555555;
	
	GPIOD->ODR |= 1<<12;
	GPIOD->ODR |= 1<<13;
	GPIOD->ODR |= 1<<14;
	GPIOD->ODR |= 1<<15;
}