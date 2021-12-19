/*
 * stm32f407vg_driver.h
 *
 *  Created on: Oct 18, 2021
 *      Author: Linh
 */
 
#ifndef INC_STM32F407XX_H_
#define INC_STM32F407XX_H_

#include <stdint.h>
#define __IO volatile
#include "stm32f407_rcc_driver.h"
#include "stm32f407_gpio_driver.h"


/*
*   base address of FLASH and SRAM memory
*/
#define FLASH_BASEADDRESS   0x08000000U
#define SRAM1_BASEADDRESS   0x20000000U
#define SRAM2_BASEADDRESS   0x2001C000U
#define ROM_BASEADDRESS     0x1FFF0000U                     /*System Memory*/
#define SRAM_BASEADDRESS    SRAM1_BASEADDRESS

/*
*   AHBx and APBx Bus Peripheeral base addresses
*/
#define PERIPH_BASE         0X40000000u
#define APB1PERIPH_BASE     0X40000000U
#define APB2PERIPH_BASE     0X40010000U
#define AHP1PERIPH_BASE     0X40020000U
#define AHP2PERIPH_BASE     0X50000000U


/*
*  BASE_ADDRESS of peripherals which are hanging on AHB1 bus 
*/
#define GPIOA_BASEADDRESS   (AHP1PERIPH_BASE + 0X0000U)
#define GPIOB_BASEADDRESS   (AHP1PERIPH_BASE + 0X0400U)
#define GPIOC_BASEADDRESS   (AHP1PERIPH_BASE + 0X0800U)
#define GPIOD_BASEADDRESS   (AHP1PERIPH_BASE + 0X0C00U)
#define GPIOE_BASEADDRESS   (AHP1PERIPH_BASE + 0X1000U)
#define GPIOF_BASEADDRESS   (AHP1PERIPH_BASE + 0X1400U)
#define GPIOG_BASEADDRESS   (AHP1PERIPH_BASE + 0X1800U)
#define GPIOH_BASEADDRESS   (AHP1PERIPH_BASE + 0X1C00U)
#define GPIOI_BASEADDRESS   (AHP1PERIPH_BASE + 0X2000U)
#define GPIOJ_BASEADDRESS   (AHP1PERIPH_BASE + 0X2400U)
#define GPIOK_BASEADDRESS   (AHP1PERIPH_BASE + 0X2800U)
#define CRC_BASEADDRESS     (AHP1PERIPH_BASE + 0x3000U)
#define RCC_BASEADDRESS     (AHP1PERIPH_BASE + 0X3800U)
#define Flash_Interface_ADDR    (AHP1PERIPH_BASE + 0x3C00U)
#define BKPSRAM_BASEADDRESS (AHP1PERIPH_BASE + 0x4000U)
#define DMA1_BASEADDRESS    (AHP1PERIPH_BASE + 0x6000U)
#define DMA2_BASEADDRESS    (AHP1PERIPH_BASE + 0x6400U)

/*
*  BASE_ADDRESS of peripherals which are hanging on AHB2 bus 
*/


/*
*   GPIO definition
*/
#define GPIOA       ((GPIO_RegDef_t*)GPIOA_BASEADDRESS)
#define GPIOB       ((GPIO_RegDef_t*)GPIOB_BASEADDRESS)
#define GPIOC       ((GPIO_RegDef_t*)GPIOC_BASEADDRESS)
#define GPIOD       ((GPIO_RegDef_t*)GPIOD_BASEADDRESS)
#define GPIOE       ((GPIO_RegDef_t*)GPIOE_BASEADDRESS)
#define GPIOF       ((GPIO_RegDef_t*)GPIOF_BASEADDRESS)
#define GPIOG       ((GPIO_RegDef_t*)GPIOG_BASEADDRESS)
#define GPIOH       ((GPIO_RegDef_t*)GPIOH_BASEADDRESS)
#define GPIOI       ((GPIO_RegDef_t*)GPIOI_BASEADDRESS)
#define GPIOJ       ((GPIO_RegDef_t*)GPIOJ_BASEADDRESS)
#define GPIOK       ((GPIO_RegDef_t*)GPIOK_BASEADDRESS)

#define RCC         ((RCC_RegDef_t *)(RCC_BASEADDRESS))
/*
*   Clock enable marcro for GPIOx peripheral
*/
#define GPIOA_PCLK_EN()     ((((RCC_RegDef_t*)RCC_BASEADDRESS)->AHB1ENR) = 1<<0)
#define GPIOB_PCLK_EN()     ((((RCC_RegDef_t*)RCC_BASEADDRESS)->AHB1ENR) = 1<<1)
#define GPIOC_PCLK_EN()     ((((RCC_RegDef_t*)RCC_BASEADDRESS)->AHB1ENR) = 1<<2)
#define GPIOD_PCLK_EN()     ((((RCC_RegDef_t*)RCC_BASEADDRESS)->AHB1ENR) = 1<<3)
#define GPIOE_PCLK_EN()     ((((RCC_RegDef_t*)RCC_BASEADDRESS)->AHB1ENR) = 1<<4)
#define GPIOF_PCLK_EN()     ((((RCC_RegDef_t*)RCC_BASEADDRESS)->AHB1ENR) = 1<<5)
#define GPIOG_PCLK_EN()     ((((RCC_RegDef_t*)RCC_BASEADDRESS)->AHB1ENR) = 1<<6)
#define GPIOH_PCLK_EN()     ((((RCC_RegDef_t*)RCC_BASEADDRESS)->AHB1ENR) = 1<<7)
#define GPIOI_PCLK_EN()     ((((RCC_RegDef_t*)RCC_BASEADDRESS)->AHB1ENR) = 1<<8)


#endif  /*INC_STM32F407XX_H_*/