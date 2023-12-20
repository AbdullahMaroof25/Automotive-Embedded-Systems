

/*******************************************************************************
 *                      Includes                                               *
 *******************************************************************************/
#include "TIM6_reg.h"
#include "TIM6.h"
#include "bit_math.h"

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
 * Syntax          : Std_ReturnType FunctionName(AnyType parameterName)
 * Description     : Describe this service
 *
 * Sync\Async      : Synchronous
 * Reentrancy      : Non Reentrant
 * Parameters (in) : parameterName   Parameter Description
 * Return value:   : Std_ReturnType  E_OK
 *                                    E_NOT_OK
 *******************************************************************************/
void TIM6_Init(u16 prescaler)
{
	/*Auto-reload pre-load enable*/
	SET_BIT(TIM6_CR1_REG, ARPE_BIT_7);


	SET_BIT(TIM6_CR1_REG, OPM_BIT_3);
	/*Set pre-scaler*/
	TIM6_PSC_REG = prescaler;

}

/******************************************************************************
 * Syntax          : Std_ReturnType FunctionName(AnyType parameterName)
 * Description     : Describe this service
 *
 * Sync\Async      : Synchronous
 * Reentrancy      : Non Reentrant
 * Parameters (in) : parameterName   Parameter Description
 * Return value:   : Std_ReturnType  E_OK
 *                                    E_NOT_OK
 *******************************************************************************/
void TIM6_Delay (u16 loadVal)
{
	/*Set auto-reload value*/
	TIM6_ARR_REG = loadVal;

	/*Start the counter*/
	SET_BIT(TIM6_CR1_REG, CEN_BIT_0);

	/*Polling on the flag*/
	while(CHECK_BIT(TIM6_SR_REG, UIF_BIT_0) == STD_LOW);

	/*Clear flag by software*/
	CLEAR_BIT(TIM6_SR_REG, UIF_BIT_0);


}


/*******************************************************************************
 *                      End of File: .c                                        *
 *******************************************************************************/
