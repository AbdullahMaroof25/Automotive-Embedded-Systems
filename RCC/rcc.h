/*
 * rcc.h
 *
 *  Created on: Nov 5, 2023
 *      Author: Abelrahman
 */

#ifndef RCC_H_
#define RCC_H_


#include "bit_math.h"
#include "std_types.h"
#include "rcc_types.h"
#include "rcc_reg.h"
#define HSI_SW  (u8)(0<<0)
#define HSE_SW  (u8)(1<<0)
#define PLL_SW  (u8)(2<<0)

void rcc_setSystemClk(rcc_sysClk_t sysClk);
void rcc_enablePeriClk(rcc_busId_t busId , u8 periId );
void rcc_disaleclk(rcc_busId_t busId, u8 periId);


#endif /* RCC_H_ */
