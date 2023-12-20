/*******************************************************************************
 *  FILE DESCRIPTION
 *  ----------------------------------------------------------------------------
 * Module:
 *
 * File Name: NVIC.c
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
#include <NVIC.h>
/*******************************************************************************
 *                      Local Data                                             *
 *******************************************************************************/


/*******************************************************************************
 *                      Global Data                                            *
 *******************************************************************************/


 /*******************************************************************************
 *                      ISR's Definitions                                      *
 *******************************************************************************/


/*******************************************************************************
 *                      Private Functions Prototypes                           *
 *******************************************************************************/


/*******************************************************************************
 *                      Private Functions Definitions                          *
 *******************************************************************************/


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
STD_ReturnState NVIC_EnableIRQ(IRQn_Type IRQn)
{
	STD_ReturnState Ret_Val = RET_NOK;
	if((u8)IRQn >= 0)
	{
		NVIC_ISER->ISER[(IRQn / 32)] |= (1 << (IRQn % 32));
		Ret_Val = RET_OK;
	}
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
STD_ReturnState NVIC_DisableIRQ(IRQn_Type IRQn)
{
	STD_ReturnState Ret_Val = RET_NOK;
	if((u8)IRQn >= 0)
	{
		NVIC_ICER->ICER[(IRQn / 32)] |= (1 << (IRQn % 32));
		Ret_Val = RET_OK;
	}
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
STD_ReturnState NVIC_SetPendingIRQ(IRQn_Type IRQn)
{
	STD_ReturnState Ret_Val = RET_NOK;
	if((u8)IRQn >= 0)
	{
		NVIC_ISPR->ISPR[(IRQn / 32)] |= (1 << (IRQn % 32));
		Ret_Val = RET_OK;
	}
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
STD_ReturnState NVIC_ClearPendingIRQ(IRQn_Type IRQn)
{
	STD_ReturnState Ret_Val = RET_NOK;
	if((u8)IRQn >= 0)
	{
		NVIC_ICPR->ICPR[(IRQn / 32)] |= (1 << (IRQn % 32));
		Ret_Val = RET_OK;
	}
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
STD_ReturnState NVIC_GetPendingIRQ(IRQn_Type IRQn, u8 *GetPending_Val)
{
	STD_ReturnState Ret_Val = RET_NOK;
	if(((u8)IRQn >= 0 ) & (GetPending_Val != NULL))
	{
		*GetPending_Val = (CHECK_BIT(NVIC_ICPR->ICPR[(IRQn / 32)],(IRQn % 32)) );
		Ret_Val = RET_OK;
	}
	else if (GetPending_Val == NULL)
	{
			Ret_Val = RET_NULLPTR;
	}
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
STD_ReturnState NVIC_SetPriority(IRQn_Type IRQn,u32 priority)
{
	STD_ReturnState Ret_Val = RET_NOK;
	if(IRQn >=0)
	{
		NVIC_IPR->IPR[(u32)IRQn] = (u8)(priority <<4)	&(u32)0xff;
		Ret_Val = RET_OK;
	}
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
STD_ReturnState NVIC_GetPriority(IRQn_Type IRQn, u32* GetPriorityVal)
{
	STD_ReturnState Ret_Val = RET_NOK;
	if(IRQn >=0)
	{
		*GetPriorityVal = (NVIC_IPR->IPR[(u32)IRQn] >> 4);
		Ret_Val = RET_OK;		
	}
	else if (GetPriorityVal == NULL)
	{
			Ret_Val = RET_NULLPTR;
	}
	return Ret_Val;
}
/*******************************************************************************
 *                      End of File: NVIC.c                                        *
 *******************************************************************************/

