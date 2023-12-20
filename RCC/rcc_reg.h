

#ifndef RCC_REG_H_
#define RCC_REG_H_

#include "std_types.h"

#define RCC_BASE_ADDRESS		(0x40021000ul)
#define RCC_CR_OFFSET			(0x00u)
#define RCC_CFGR_OFFSET			(0x04u)
#define RCC_AHBENR_OFFSET		(0x14u)
#define RCC_APB2ENR_OFFSET		(0x18u)
#define RCC_APB1ENR_OFFSET		(0x1Cu)

#define HSION_BIT					(0u)
#define HSION_READY_FLAG_BIT		(1u)
#define HSEON_BIT					(16u)
#define HSEON_READY_FLAG_BIT		(17u)
#define PLLON_BIT					(24u)
#define PLLON_READY_FLAG_BIT		(25u)


#define RCC_CR_REG					(*(volatile u32*)(RCC_BASE_ADDRESS+RCC_CR_OFFSET))
#define RCC_CFGR_REG				(*(volatile u32*)(RCC_BASE_ADDRESS+RCC_CFGR_OFFSET))

#define HSI_ON					(0u)
#define HSI_RDY					(1u)
#define HSI_TRIM				(3u)
#define HSI_CAL					(8u)
#define HSE_ON					(16u)
#define HSE_RDY					(17u)
#define HSE_BYP					(18u)
#define CSS_ON					(19u)
#define PLL_ON					(24u)
#define PLL_RDY					(25u)

#define RCC_AHBENR_REG			(*(volatile u32*)(RCC_BASE_ADDRESS+RCC_AHBENR_OFFSET))
#define DMA1_EN					(0u)
#define DMA2_EN					(1u)
#define SRAM_EN					(2u)
#define FLITF_EN				(4u)
#define FMC_EN					(5u)
#define CRC_EN					(6u)
#define IOPH_EN					(16u)
#define IOPA_EN					(17u)
#define IOPB_EN					(18u)
#define IOPC_EN					(19u)
#define IOPD_EN					(20u)
#define IOPE_EN					(21u)
#define IOPF_EN					(22u)
#define IOPG_EN					(23u)
#define TSC_EN					(24u)
#define ADC12_EN				(28u)
#define ADC34_EN				(29u)


#define RCC_APB2ENR_REG			(*(volatile u32*)(RCC_BASE_ADDRESS+RCC_APB2ENR_OFFSET))
#define SYSCFG_EN				(0u)
#define TIM1_EN					(11u)
#define SPI1_EN					(12u)
#define TIM8_EN					(13u)
#define USART1_EN				(14u)
#define SPI4_EN					(15u)
#define TIM15_EN				(16u)
#define TIM16_EN				(17u)
#define TIM17_EN				(18u)
#define TIM20_EN				(20u)


#define RCC_APB1ENR_REG			(*(volatile u32*)(RCC_BASE_ADDRESS+RCC_APB1ENR_OFFSET))
#define TIM2_EN					(0u)
#define TIM3_EN					(1u)
#define TIM4_EN					(2u)
#define TIM6_EN					(4u)
#define TIM7_EN					(5u)
#define WWDG_EN					(11u)
#define SPI2_EN					(14u)
#define SPI3_EN					(15u)
#define USART2_EN				(17u)
#define USART3_EN				(18u)
#define UART4_EN				(19u)
#define UART5_EN				(20u)
#define I2C1_EN					(21u)
#define I2C2_EN					(22u)
#define USB_EN					(23u)
#define CAN_EN					(25u)
#define DAC2_EN					(26u)
#define PWR_EN					(28u)
#define DAC1_EN					(29u)
#define I2C3_EN					(30u)


#endif /* RCC_REG_H_ */
