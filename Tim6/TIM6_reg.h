

#ifndef TIM6_REG_H_
#define TIM6_REG_H_

/*******************************************************************************
 *                      Includes                                               *
 *******************************************************************************/
#include "std_types.h"
#include "Timers_reg.h"

/*******************************************************************************
 *                      Global Constant Macros                                 *
 *******************************************************************************/

/*************          TIMER 6                *************/

#define TIMER6_BASE_ADDR                (0x40001000ul)      /*Timer 15 Base Address*/

#define TIM6_CR1_REG					(*(volatile u16*) (TIMER6_BASE_ADDR + CR1_REG_OFFSET)) 		/*Timer 6 Control Register 1*/
#define TIM6_CR2_REG					(*(volatile u16*) (TIMER6_BASE_ADDR + CR2_REG_OFFSET)) 		/*Timer 6 Control Register 2*/
#define TIM6_DIER_REG					(*(volatile u16*) (TIMER6_BASE_ADDR + DIER_REG_OFFSET)) 	/*Timer 6 DMA/Interrupt Enable Register*/
#define TIM6_SR_REG						(*(volatile u16*) (TIMER6_BASE_ADDR + SR_REG_OFFSET)) 		/*Timer 6 Status Register*/
#define TIM6_PSC_REG					(*(volatile u16*) (TIMER6_BASE_ADDR + PSC_REG_OFFSET))		/*Timer 6 Pre-scaler Register*/
#define TIM6_ARR_REG					(*(volatile u16*) (TIMER6_BASE_ADDR + ARR_REG_OFFSET))		/*Timer 6 Auto-reload Register*/

/*******************************************************************************
 *                      Global Function Macros                                 *
 *******************************************************************************/


/*******************************************************************************
 *                      Global Data Types and Structures                       *
 *******************************************************************************/


/*******************************************************************************
 *                      Global Data Prototypes                                 *
 *******************************************************************************/


/*******************************************************************************
 *                      Global Function Prototypes                             *
 *******************************************************************************/


#endif

/*******************************************************************************
 *                      End of File: .h                                        *
 *******************************************************************************/
