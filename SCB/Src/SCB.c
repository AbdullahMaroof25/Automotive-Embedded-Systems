
/*******************************************************************************
 *  FILE DESCRIPTION
 *  ----------------------------------------------------------------------------
 * Module:
 *
 * File Name: SCB.c
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
#include <SCB.h>
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
STD_ReturnState SCB_SetPriorityGroup(u32 PriorityGroup)
{
	STD_ReturnState Ret_Val = RET_NOK;
	u32 RegisterValue =0;
	u32 PriorityGroup_val= (u32)PriorityGroup &(u32)0x07;

	RegisterValue =SCB_AIRCR;
	RegisterValue &= ~((u32)SCB_AIRCR_PRIGROUP_msk | (u32)SCB_AIRCR_VECTKEY_msk);

	RegisterValue = (RegisterValue | ((u32)0x05FA << SCB_AIRCR_VECTKEY_pos)
			| ((u32)PriorityGroup_val << SCB_AIRCR_PRIGROUP_pos));

	SCB_AIRCR = RegisterValue;
	Ret_Val = RET_OK;
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
STD_ReturnState SCB_GetPriorityGroup(u32 *GetPriorityVal)
{
	STD_ReturnState Ret_Val = RET_NOK;
	if(GetPriorityVal != NULL)
	{
		*GetPriorityVal =((SCB_AIRCR & (u32)SCB_AIRCR_PRIGROUP_msk) >>SCB_AIRCR_PRIGROUP_pos);
		Ret_Val = RET_OK;
	}
	else
	{
		Ret_Val =RET_NULLPTR;
	}
	return Ret_Val;
}
/*******************************************************************************
 *                      End of File: NVIC.c                                        *
 *******************************************************************************/


