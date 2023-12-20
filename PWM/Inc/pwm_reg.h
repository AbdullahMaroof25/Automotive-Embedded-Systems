
#ifndef PWM_REG_H_
#define PWM_REG_H_

#include "std_types.h"
#include "Timers_reg.h"


#define TIMER2_BASE_ADDR                (0x40000000ul )      // Base Address for TIMER8 in memory map





#define TIM2_CR1_REG					( *( volatile u32* ) ( TIMER2_BASE_ADDR + CR1_REG_OFFSET   ))
#define TIM2_PSC_REG					( *( volatile u32* ) ( TIMER2_BASE_ADDR + PSC_REG_OFFSET   ))
#define TIM2_CCR1_REG					( *( volatile u32* ) ( TIMER2_BASE_ADDR + CCR1_REG_OFFSET  ))
#define TIM2_CCR2_REG					( *( volatile u32* ) ( TIMER2_BASE_ADDR + CCR2_REG_OFFSET  ))
#define TIM2_CCR3_REG					( *( volatile u32* ) ( TIMER2_BASE_ADDR + CCR3_REG_OFFSET  ))
#define TIM2_CCR4_REG					( *( volatile u32* ) ( TIMER2_BASE_ADDR + CCR4_REG_OFFSET  ))

#define TIM2_CCER_REG					( *( volatile u32* ) ( TIMER2_BASE_ADDR + CCER_REG_OFFSET  ))
#define TIM2_CCMR1_REG					( *( volatile u32* ) ( TIMER2_BASE_ADDR + CCMR1_REG_OFFSET ))
#define TIM2_CCMR2_REG					( *( volatile u32* ) ( TIMER2_BASE_ADDR + CCMR2_REG_OFFSET ))
#define TIM2_CNT_REG					( *( volatile u32* ) ( TIMER2_BASE_ADDR + CNT_REG_OFFSET   ))
#define TIM2_ARR_REG                    ( *( volatile u32* ) ( TIMER2_BASE_ADDR + ARR_REG_OFFSET   ))



#endif /* PWM_REG_H_ */
