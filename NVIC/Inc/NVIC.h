/******************************************************************************
 * Module:
 *
 * File Name: NVIC.h
 *
 * Description:
 *
 * Created on: Nov 15, 2023
 *
 *
 *******************************************************************************/
#ifndef NVIC_H_
#define NVIC_H_
/*******************************************************************************
 *                      Includes                                               *
 *******************************************************************************/
#include "bit_math.h"
#include "std_types.h"
#include "NVIC_reg.h"

/*******************************************************************************
 *                      Global Constant Macros                                 *
 *******************************************************************************/

/*******************************************************************************
 *                      Global Function Macros                                 *
 *******************************************************************************/


/*******************************************************************************
 *                      Global Data Types and Structures                       *
 *******************************************************************************/
typedef struct {
	volatile u32 ISER[8];
}ISER_type;
typedef struct {
	volatile u32 ICER[8];
}ICER_type;
typedef struct {
	volatile u32 ISPR[8];
}ISPR_type;
typedef struct {
	volatile u32 ICPR[8];
}ICPR_type;
typedef struct {
	volatile u32 IABR[8];
}IABR_type;
typedef struct {
	volatile u8 IPR[240];
}IPR_type;

typedef enum {
	IRQn_WWDG	        	= 0 	,
	IRQn_PVD 	        	= 1 	,
	IRQn_TAMPER_STAMP    	= 2 	,
	IRQn_RTC_WKUP 	    	= 3 	,
	IRQn_FLASH           	= 4 	,
	IRQn_RCC             	= 5 	,
	IRQn_EXTI0           	= 6 	,
	IRQn_EXTI1           	= 7 	,
	IRQn_EXTI2_TS        	= 8 	,
	IRQn_EXTI3           	= 9 	,
	IRQn_EXTI4           	= 10	,
	IRQn_DMA1_Channel1   	= 11	,
	IRQn_DMA1_Channel2   	= 12	,
	IRQn_DMA1_Channel3   	= 13	,
	IRQn_DMA1_Channel4   	= 14	,
	IRQn_DMA1_Channel5   	= 15	,
	IRQn_DMA1_Channel6   	= 16	,
	IRQn_DMA1_Channel7   	= 17	,
	IRQn_ADC1_2          	= 18	,
	IRQn_CAN_TX          	= 19	,
	IRQn_CAN_RX          	= 20	,
	IRQn_CAN_RX1 			= 21	,
	IRQn_CAN_SCE 			= 22	,
	IRQn_EXTI9_5 			= 23	,
	IRQn_TIM1_BRK			= 24	,
	IRQn_TIM1_UP			= 25	,
	IRQn_TIM1_TRG_COM		= 26	,
	IRQn_TIM1_CC			= 27	,
	IRQn_TIM2				= 28	,
	IRQn_TIM3				= 29	,
	IRQn_TIM4				= 30	,
	IRQn_I2C1_EV			= 31	,
	IRQn_I2C1_ER			= 32	,
	IRQn_I2C2_EV			= 33	,
	IRQn_I2C2_ER			= 34	,
	IRQn_SPI1				= 35	,
	IRQn_SPI2				= 36	,
	IRQn_USART1				= 37	,
	IRQn_USART2				= 38	,
	IRQn_USART3				= 39	,
	IRQn_EXTI15_10			= 40	,
	IRQn_RTC_Alarm			= 41	,
	IRQn_USBWakeUp 			= 42	,
	IRQn_TIM8_BRK			= 43	,
	IRQn_TIM8_UP			= 44	,
	IRQn_TIM8_TRG_COM		= 45	,
	IRQn_TIM8_CC			= 46	,
	IRQn_ADC3 				= 47	,
	IRQn_FMC				= 48	,
//	IRQn_					= 49	,
//	IRQn_					= 50	,
	IRQn_SPI3 				= 51	,
	IRQn_UART4				= 52	,
	IRQn_UART5 				= 53	,
	IRQn_TIM6_DAC			= 54	,
	IRQn_TIM7 				= 55	,
	IRQn_DMA2_Channel1		= 56	,
	IRQn_DMA2_Channel2		= 57	,
	IRQn_DMA2_Channel3		= 58	,
	IRQn_DMA2_Channel4		= 59	,
	IRQn_DMA2_Channel5		= 60	,
	IRQn_ADC4				= 61	,
//	IRQn_					= 62	,
//	IRQn_					= 63	,
	IRQn_COMP1_2_3			= 64	,
	IRQn_COMP4_5_6			= 65	,
	IRQn_COMP7 				= 66	,
//	IRQn_					= 67	,
//	IRQn_					= 68	,
//	IRQn_					= 69	,
//	IRQn_					= 70	,
//	IRQn_					= 71	,
	IRQn_I2C3_EV			= 72	,
	IRQn_I2C3_ER			= 73	,
	IRQn_USB_HP				= 74	,
	IRQn_USB_LP				= 75	,
	IRQn_USB_WakeUp_RMP		= 76	,
	IRQn_TIM20_BRK			= 77	,
	IRQn_TIM20_UP			= 78	,
	IRQn_TIM20_TRG_COM		= 79	,
	IRQn_TIM20_CC			= 80	,
	IRQn_FPU					= 81
//	IRQn_					= 82	,
//	IRQn_					= 83	,
//	IRQn_					= 84

}IRQn_Type;

typedef enum {
	GROUPS_16_SUBS_0 		= 3,
	GROUPS_8_SUBS_2 		= 4,
	GROUPS_4_SUBS_4 		= 5,
	GROUPS_2_SUBS_8 		= 6,
	GROUPS_0_SUBS_16 		= 7,
}PRIORITY_GROUPING_Type;

typedef struct{
	IRQn_Type IRQn;
	PRIORITY_GROUPING_Type PriorityGrouping;
}SET_InGroup_Type;


/*******************************************************************************
 *                      Global Data Prototypes                                 *
 *******************************************************************************/

/*******************************************************************************
 *                      Global Function Prototypes                             *
 *******************************************************************************/
STD_ReturnState NVIC_EnableIRQ(IRQn_Type IRQn);
STD_ReturnState NVIC_DisableIRQ(IRQn_Type IRQn);
STD_ReturnState NVIC_SetPendingIRQ(IRQn_Type IRQn);
STD_ReturnState NVIC_ClearPendingIRQ(IRQn_Type IRQn);
STD_ReturnState NVIC_GetPendingIRQ(IRQn_Type IRQn,u8 *GetPending_Val);

STD_ReturnState NVIC_SetPriority(IRQn_Type IRQn,u32 priority);
STD_ReturnState NVIC_GetPriority(IRQn_Type IRQn,u32* GetPriorityVal);

/*******************************************************************************
 *                      End of File: NVIC.h                                        *
 *******************************************************************************/
#endif /* NVIC_H_ */
