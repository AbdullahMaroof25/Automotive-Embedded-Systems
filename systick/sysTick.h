/*
 * sysTick.h
 *
 *  Created on: Nov 6, 2023
 *      Author: sala7
 */

#ifndef MCAL_SYSTICK_INC_SYSTICK_H_
#define MCAL_SYSTICK_INC_SYSTICK_H_

#include "std_types.h"
#include "bit_math.h"
#include "sysTick_reg.h"

typedef enum
{
	AHB_8,
	AHB_1
}systick_clock_t;

void sysTick_init(systick_clock_t clock, void (*fPtr)(void));
void sysTick_start(u32 loadVal);
void sysTick_stop();


#endif /* MCAL_SYSTICK_INC_SYSTICK_H_ */
