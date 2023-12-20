
#include "rcc_types.h"
#include "rcc_reg.h"
#include "bit_math.h"
#include "rcc.h"


void rcc_setSystemClk(rcc_sysClk_t sysClk){
	switch(sysClk){
	case HSI:
		/* ENABLE HSI CLOCK*/
		SET_BIT(RCC_CR_REG,HSION_BIT);
		/* MAKE SURE ITS ENABLED */
		while(CHECK_BIT(RCC_CR_REG,HSION_READY_FLAG_BIT)==0);
		/* select HSI as sys clock*/
		RCC_CFGR_REG|=HSI_SW;
		break;

	case HSE:
		/* ENABLE HSE CLOCK*/
		SET_BIT(RCC_CR_REG,HSEON_BIT);
		/* MAKE SURE ITS ENABLED */
		while(CHECK_BIT(RCC_CR_REG,HSEON_READY_FLAG_BIT)==0);
		/* select HSE as sys clock*/
		RCC_CFGR_REG|=HSE_SW;

		break;

	case PLL:
		/* ENABLE PLL CLOCK*/
		SET_BIT(RCC_CR_REG,PLLON_BIT);
		/* MAKE SURE ITS ENABLED */
		while(CHECK_BIT(RCC_CR_REG,PLLON_READY_FLAG_BIT)==0);
		/* select PLL as sys clock*/
		RCC_CFGR_REG|=PLL_SW;
		break;

	}
}
void rcc_enablePeriClk(rcc_busId_t busId , u8 periId ){
	switch(busId){
	case AHB:
		SET_BIT(RCC_AHBENR_REG,periId);
		break;

	case APB1:
		SET_BIT(RCC_APB1ENR_REG,periId);

		break;

	case APB2:
		SET_BIT(RCC_APB2ENR_REG,periId);

		break;
	}
}
void rcc_disaleclk(rcc_busId_t busId, u8 periId){
	switch(busId){
	case AHB:
		CLEAR_BIT(RCC_AHBENR_REG,periId);
		break;

	case APB1:
		CLEAR_BIT(RCC_APB1ENR_REG,periId);

		break;

	case APB2:
		CLEAR_BIT(RCC_APB2ENR_REG,periId);

		break;
	}
}
