
#ifndef ICU_REG_H_
#define ICU_REG_H_

#include "Timers_reg.h"

/*******************************************************************************
 *                      Includes                                               *
 *******************************************************************************/


/*******************************************************************************
 *                      Global Constant Macros                                 *
 *******************************************************************************/


/*************          TIMER 8                *************/

#define TIMER8_BASE_ADDR                (0x40013400ul )      // Base Address for TIMER8 in memory map





/**********************************/

#define TIM8_CNT_REG					( *( volatile u16* ) ( TIMER8_BASE_ADDR + CNT_REG_OFFSET   ))    //control register 1

#define TIM8_CR1_REG					( *( volatile u16* ) ( TIMER8_BASE_ADDR + CR1_REG_OFFSET   ))    //control register 1


/**********************************/
#define TIM8_CR2_REG					( *( volatile u16* ) ( TIMER8_BASE_ADDR + CR2_REG_OFFSET   ))	  //control register 2
/**********************************/

#define TIM8_DIER_REG					( *( volatile u16* ) ( TIMER8_BASE_ADDR + DIER_REG_OFFSET  ))	  //DMA/interrupt enable register




/**********************************/

#define TIM8_SR_REG					( *( volatile u32* ) ( TIMER8_BASE_ADDR + SR_REG_OFFSET    ))	  //status register


/**********************************/

#define TIM8_CCMR1_REG					( *( volatile u32* ) ( TIMER8_BASE_ADDR + CCMR1_REG_OFFSET ))    //capture/compare mode register 1


/**********************************/

#define TIM8_CCMR2_REG					( *( volatile u32* ) ( TIMER8_BASE_ADDR + CCMR2_REG_OFFSET ))    //capture/compare mode register 2



/**********************************/

#define TIM8_CCER_REG					( *( volatile u32* ) ( TIMER8_BASE_ADDR + CCER_REG_OFFSET  ))    //capture/compare enable register



/**********************************/

#define TIM8_PSC_REG					( *( volatile u16* ) ( TIMER8_BASE_ADDR + PSC_REG_OFFSET   ))    //prescaler

/**********************************/

#define TIM8_CCR1_REG					( *( volatile u16* ) ( TIMER8_BASE_ADDR + CCR1_REG_OFFSET  ))    //capture/compare register 1

/**********************************/

#define TIM8_CCR2_REG					( *( volatile u16* ) ( TIMER8_BASE_ADDR + CCR2_REG_OFFSET  ))    //capture/compare register 2

/**********************************/

#define TIM8_CCR3_REG					( *( volatile u16* ) ( TIMER8_BASE_ADDR + CCR3_REG_OFFSET  ))    //capture/compare register 3

/**********************************/

#define TIM8_CCR4_REG					( *( volatile u16* ) ( TIMER8_BASE_ADDR + CCR4_REG_OFFSET  ))    //capture/compare register 4




/**********************************/



#define  TIM8_ARR_REG   ( *( volatile u16* ) ( TIMER8_BASE_ADDR + ARR_REG_OFFSET  ))

#define  TIM8_EGR_REG 	( *( volatile u16* ) ( TIMER8_BASE_ADDR + EGR_REG_OFFSET  ))


/********************   Tim1   *****************************/

#define TIMER1_BASE_ADDR                (0x40012C00ul )      // Base Address for TIMER15 in memory map

#define TIM1_CR1_REG					( *( volatile u16* ) ( TIMER1_BASE_ADDR + CR1_REG_OFFSET   ))    //control register 1
#define TIM1_CR2_REG					( *( volatile u16* ) ( TIMER1_BASE_ADDR + CR2_REG_OFFSET   ))	  //control register 2
#define TIM1_DIER_REG					( *( volatile u16* ) ( TIMER1_BASE_ADDR + DIER_REG_OFFSET  ))	  //DMA/interrupt enable register
#define TIM1_PSC_REG					( *( volatile u16* ) ( TIMER1_BASE_ADDR + PSC_REG_OFFSET   ))    //prescaler
#define TIM1_CCR1_REG					( *( volatile u16* ) ( TIMER1_BASE_ADDR + CCR1_REG_OFFSET  ))    //capture/compare register 1
#define TIM1_CCR2_REG					( *( volatile u16* ) ( TIMER1_BASE_ADDR + CCR2_REG_OFFSET  ))    //capture/compare register 2
#define TIM1_CCR3_REG					( *( volatile u16* ) ( TIMER1_BASE_ADDR + CCR3_REG_OFFSET  ))    //capture/compare register 3


#define TIM1_CCER_REG					( *( volatile u32* ) ( TIMER1_BASE_ADDR + CCER_REG_OFFSET  ))    //capture/compare enable register
#define TIM1_SR_REG				        ( *( volatile u32* ) ( TIMER1_BASE_ADDR + SR_REG_OFFSET    ))	  //status register
#define TIM1_CCMR1_REG					( *( volatile u32* ) ( TIMER1_BASE_ADDR + CCMR1_REG_OFFSET ))    //capture/compare mode register 1
#define TIM1_CCMR2_REG					( *( volatile u32* ) ( TIMER1_BASE_ADDR + CCMR2_REG_OFFSET ))    //capture/compare mode register 2


#define TIM1_CNT_REG					( *( volatile u16* ) ( TIMER1_BASE_ADDR + CNT_REG_OFFSET   ))    //control register 1






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
