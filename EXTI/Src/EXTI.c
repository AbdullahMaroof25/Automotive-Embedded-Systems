/*******************************************************************************
 *  FILE DESCRIPTION
 *  ----------------------------------------------------------------------------
 * Module:
 *
 * File Name: exti.c
 *
 * Description:
 *
 * Created on: Nov 15, 2023
 *
 *
 *******************************************************************************/

/*******************************************************************************
 *                      Includes                                               *
 *******************************************************************************/
#include "EXTI.h"

/*******************************************************************************
 *                      Local Data                                             *
 *******************************************************************************/
static volatile void(*EXTI_HandlerFunc0)(void)  = 0;
static volatile void(*EXTI_HandlerFunc1)(void)  = 0;
static volatile void(*EXTI_HandlerFunc2)(void)  = 0;
static volatile void(*EXTI_HandlerFunc3)(void)  = 0;
static volatile void(*EXTI_HandlerFunc4)(void)  = 0;
static volatile void(*EXTI_HandlerFunc5)(void)  = 0;
static volatile void(*EXTI_HandlerFunc6)(void)  = 0;
static volatile void(*EXTI_HandlerFunc7)(void)  = 0;
static volatile void(*EXTI_HandlerFunc8)(void)  = 0;
static volatile void(*EXTI_HandlerFunc9)(void)  = 0;
static volatile void(*EXTI_HandlerFunc10)(void) = 0;
static volatile void(*EXTI_HandlerFunc11)(void) = 0;
static volatile void(*EXTI_HandlerFunc12)(void) = 0;
static volatile void(*EXTI_HandlerFunc13)(void) = 0;
static volatile void(*EXTI_HandlerFunc14)(void) = 0;
static volatile void(*EXTI_HandlerFunc15)(void) = 0;

/*******************************************************************************
 *                      Global Data                                            *
 *******************************************************************************/


 /*******************************************************************************
 *                      ISR's Definitions                                      *
 *******************************************************************************/


/*******************************************************************************
 *                      Private Functions Prototypes                           *
 *******************************************************************************/
static void EXTI_SelectHandlerFnuc(EXTI_Type *EXTI);

/*******************************************************************************
 *                      Private Functions Definitions                          *
 *******************************************************************************/
static void EXTI_SelectHandlerFnuc(EXTI_Type *EXTI)
{
	if (EXTI->EXTIxSelect == EXTI_0){
		EXTI_HandlerFunc0 = EXTI->EXTI_CallBackFunc;
	}
	else if (EXTI->EXTIxSelect == EXTI_1){
		EXTI_HandlerFunc1 = EXTI->EXTI_CallBackFunc;
	}
	else if (EXTI->EXTIxSelect == EXTI_2){
		EXTI_HandlerFunc2 = EXTI->EXTI_CallBackFunc;
	}
	else if (EXTI->EXTIxSelect == EXTI_3){
		EXTI_HandlerFunc3 = EXTI->EXTI_CallBackFunc;
	}
	else if (EXTI->EXTIxSelect == EXTI_4){
		EXTI_HandlerFunc4 = EXTI->EXTI_CallBackFunc;
	}
	else if (EXTI->EXTIxSelect == EXTI_5){
		EXTI_HandlerFunc5 = EXTI->EXTI_CallBackFunc;
	}
	else if (EXTI->EXTIxSelect == EXTI_6){
		EXTI_HandlerFunc6 = EXTI->EXTI_CallBackFunc;
	}
	else if (EXTI->EXTIxSelect == EXTI_7){
		EXTI_HandlerFunc7 = EXTI->EXTI_CallBackFunc;
	}
	else if (EXTI->EXTIxSelect == EXTI_8){
		EXTI_HandlerFunc8 = EXTI->EXTI_CallBackFunc;
	}
	else if (EXTI->EXTIxSelect == EXTI_9){
		EXTI_HandlerFunc9 = EXTI->EXTI_CallBackFunc;
	}
	else if (EXTI->EXTIxSelect == EXTI_10){
		EXTI_HandlerFunc10 = EXTI->EXTI_CallBackFunc;
	}
	else if (EXTI->EXTIxSelect == EXTI_11){
		EXTI_HandlerFunc11 = EXTI->EXTI_CallBackFunc;
	}
	else if (EXTI->EXTIxSelect == EXTI_12){
		EXTI_HandlerFunc12 = EXTI->EXTI_CallBackFunc;
	}
	else if (EXTI->EXTIxSelect == EXTI_13){
		EXTI_HandlerFunc13 = EXTI->EXTI_CallBackFunc;
		EXTI_HandlerFunc13();
	}
	else if (EXTI->EXTIxSelect == EXTI_14){
		EXTI_HandlerFunc14 = EXTI->EXTI_CallBackFunc;
	}
	else if (EXTI->EXTIxSelect == EXTI_15){
		EXTI_HandlerFunc15 = EXTI->EXTI_CallBackFunc;
	}
}

/*******************************************************************************
  *                      Global Functions Definitions                           *
 *******************************************************************************/


/******************************************************************************
* Syntax          :
* Description     :
*
* Sync\Async      :
* Reentrancy      :
* Parameters () :
* Return value:   : *
*******************************************************************************/
STD_ReturnState EXTI_LineEnable(EXTI_Type *EXTI)
{
	STD_ReturnState Ret_Val = RET_OK;
	if (EXTI->Trig_Stat == FALLING_TRIGGER){
		SET_BIT(EXTI_FTSR1_REG, EXTI->EXTIxSelect);
	}
	else if (EXTI->Trig_Stat  == RISING_TRIGGER){
		SET_BIT(EXTI_RTSR1_REG, EXTI->EXTIxSelect);
	}
	else if (EXTI->Trig_Stat  == ON_CHANGE_TRIGGER){
		SET_BIT(EXTI_FTSR1_REG, EXTI->EXTIxSelect);
		SET_BIT(EXTI_RTSR1_REG, EXTI->EXTIxSelect);
	}
	else{
		Ret_Val = RET_NOK;
	}
	EXTI_SelectHandlerFnuc(EXTI);

	SET_BIT(EXTI_IMR1_REG, EXTI->EXTIxSelect);

	return Ret_Val;
}

/******************************************************************************
* Syntax          :
* Description     :
*
* Sync\Async      :
* Reentrancy      :
* Parameters () :
* Return value:   : *
*******************************************************************************/
STD_ReturnState EXTI_LineDisable(EXTI_Type *EXTI)
{
	STD_ReturnState Ret_Val = RET_NOK;
	CLEAR_BIT(EXTI_IMR1_REG, EXTI->EXTIxSelect);
	 Ret_Val = RET_OK;

	return Ret_Val;
}

/*******************************************************************************
 *                      End of File: exti.c                                        *
 *******************************************************************************/
