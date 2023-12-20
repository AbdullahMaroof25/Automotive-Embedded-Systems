/*******************************************************************************
 *  FILE DESCRIPTION
 *  ----------------------------------------------------------------------------
 * Module: DIO
 *
 * File Name: dio.c
 *
 * Description: Source file for the DIO driver
 *
 *
 *******************************************************************************/

/*******************************************************************************
 *                      Includes                                               *
 *******************************************************************************/
#include "dio.h"
#include "dio_reg.h"
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
STD_ReturnState DIO_setupPinMode(DIO_PortID portID, DIO_PinID pinID, DIO_PinMode pinMode)
{
	STD_ReturnState Ret_Val = RET_OK;

	if((portID >= NUM_OF_PORTS) || (pinID >= NUM_OF_PINS_PER_PORT))
	{
		Ret_Val = RET_NOK;
	}

	else
	{
		switch(portID)
		{
		case PORTA_ID:
			DIOA_MODER_REG = (DIOA_MODER_REG & ~(0x03 << (pinID*2))) | (pinMode << (pinID*2));
			break;

		case PORTB_ID:
			DIOB_MODER_REG = (DIOB_MODER_REG & ~(0x03 << (pinID*2))) | (pinMode << (pinID*2));
			break;

		case PORTC_ID:
			DIOC_MODER_REG = (DIOC_MODER_REG & ~(0x03 << (pinID*2))) | (pinMode << (pinID*2));
			break;

		case PORTD_ID:
			DIOD_MODER_REG = (DIOD_MODER_REG & ~(0x03 << (pinID*2))) | (pinMode << (pinID*2));
			break;

		case PORTE_ID:
			DIOE_MODER_REG = (DIOE_MODER_REG & ~(0x03 << (pinID*2))) | (pinMode << (pinID*2));
			break;

		case PORTF_ID:
			DIOF_MODER_REG = (DIOF_MODER_REG & ~(0x03 << (pinID*2))) | (pinMode << (pinID*2));
			break;

		case PORTG_ID:
			DIOG_MODER_REG = (DIOG_MODER_REG & ~(0x03 << (pinID*2))) | (pinMode << (pinID*2));
			break;

		case PORTH_ID:
			DIOH_MODER_REG = (DIOH_MODER_REG & ~(0x03 << (pinID*2))) | (pinMode << (pinID*2));
			break;
		}
	}

	return Ret_Val;
}

STD_ReturnState DIO_writePin(DIO_PortID portID, DIO_PinID pinID, DIO_PinLevel pinLevel)
{
	STD_ReturnState Ret_Val = RET_OK;

	if(portID >= NUM_OF_PORTS || pinID >= NUM_OF_PINS_PER_PORT)
	{
		Ret_Val = RET_NOK;
	}

	else
	{
		switch(portID)
		{
		case PORTA_ID:
			if(pinLevel == LOGIC_LOW)
			{
				CLEAR_BIT(DIOA_ODR_REG, pinID);
			}
			else
			{
				SET_BIT(DIOA_ODR_REG, pinID);
			}
			break;

		case PORTB_ID:
			if(pinLevel == LOGIC_LOW)
			{
				CLEAR_BIT(DIOB_ODR_REG, pinID);
			}
			else
			{
				SET_BIT(DIOB_ODR_REG, pinID);
			}
			break;

		case PORTC_ID:
			if(pinLevel == LOGIC_LOW)
			{
				CLEAR_BIT(DIOC_ODR_REG, pinID);
			}
			else
			{
				SET_BIT(DIOC_ODR_REG, pinID);
			}
			break;

		case PORTD_ID:
			if(pinLevel == LOGIC_LOW)
			{
				CLEAR_BIT(DIOD_ODR_REG, pinID);
			}
			else
			{
				SET_BIT(DIOD_ODR_REG, pinID);
			}
			break;

		case PORTE_ID:
			if(pinLevel == LOGIC_LOW)
			{
				CLEAR_BIT(DIOE_ODR_REG, pinID);
			}
			else
			{
				SET_BIT(DIOE_ODR_REG, pinID);
			}
			break;

		case PORTF_ID:
			if(pinLevel == LOGIC_LOW)
			{
				CLEAR_BIT(DIOF_ODR_REG, pinID);
			}
			else
			{
				SET_BIT(DIOF_ODR_REG, pinID);
			}
			break;

		case PORTG_ID:
			if(pinLevel == LOGIC_LOW)
			{
				CLEAR_BIT(DIOG_ODR_REG, pinID);
			}
			else
			{
				SET_BIT(DIOG_ODR_REG, pinID);
			}
			break;

		case PORTH_ID:
			if(pinLevel == LOGIC_LOW)
			{
				CLEAR_BIT(DIOH_ODR_REG, pinID);
			}
			else
			{
				SET_BIT(DIOH_ODR_REG, pinID);
			}
			break;
		}
	}

	return Ret_Val;
}

STD_ReturnState DIO_togglePin(DIO_PortID portID, DIO_PinID pinID)
{
	STD_ReturnState Ret_Val = RET_OK;

	if(portID >= NUM_OF_PORTS || pinID >= NUM_OF_PINS_PER_PORT)
	{
		Ret_Val = RET_NOK;
	}

	else
	{
		switch(portID)
		{
		case PORTA_ID:
			FLIP_BIT(DIOA_ODR_REG, pinID);
			break;

		case PORTB_ID:
			FLIP_BIT(DIOB_ODR_REG, pinID);
			break;

		case PORTC_ID:
			FLIP_BIT(DIOC_ODR_REG, pinID);
			break;

		case PORTD_ID:
			FLIP_BIT(DIOD_ODR_REG, pinID);
			break;

		case PORTE_ID:
			FLIP_BIT(DIOE_ODR_REG, pinID);
			break;

		case PORTF_ID:
			FLIP_BIT(DIOF_ODR_REG, pinID);
			break;

		case PORTG_ID:
			FLIP_BIT(DIOG_ODR_REG, pinID);
			break;

		case PORTH_ID:
			FLIP_BIT(DIOH_ODR_REG, pinID);
			break;
		}
	}

	return Ret_Val;
}

STD_ReturnState DIO_readPin(DIO_PortID portID, DIO_PinID pinID, DIO_PinLevel *pinLevel)
{
	STD_ReturnState Ret_Val = RET_OK;

	if(portID >= NUM_OF_PORTS || pinID >= NUM_OF_PINS_PER_PORT)
	{
		Ret_Val = RET_NOK;
	}

	else if(pinLevel == NULL)
	{
		Ret_Val = NULL;
	}

	else
	{
		switch(portID)
		{
		case PORTA_ID:
			*pinLevel = CHECK_BIT(DIOA_IDR_REG, pinID);
			break;

		case PORTB_ID:
			*pinLevel = CHECK_BIT(DIOB_IDR_REG, pinID);
			break;

		case PORTC_ID:
			*pinLevel = CHECK_BIT(DIOC_IDR_REG, pinID);
			break;

		case PORTD_ID:
			*pinLevel = CHECK_BIT(DIOD_IDR_REG, pinID);
			break;

		case PORTE_ID:
			*pinLevel = CHECK_BIT(DIOE_IDR_REG, pinID);
			break;

		case PORTF_ID:
			*pinLevel = CHECK_BIT(DIOF_IDR_REG, pinID);
			break;

		case PORTG_ID:
			*pinLevel = CHECK_BIT(DIOG_IDR_REG, pinID);
			break;

		case PORTH_ID:
			*pinLevel = CHECK_BIT(DIOH_IDR_REG, pinID);
			break;
		}
	}

	return Ret_Val;
}

STD_ReturnState DIO_activateInternal(DIO_PortID portID, DIO_PinID pinID, DIO_InternalMode internalMode)
{
	STD_ReturnState Ret_Val = RET_OK;

	if(portID >= NUM_OF_PORTS || pinID >= NUM_OF_PINS_PER_PORT)
	{
		Ret_Val = RET_NOK;
	}

	else
	{
		switch(portID)
		{
		case PORTA_ID:
			DIOA_PUPDR_REG = (DIOA_PUPDR_REG & ~(0x03 << (pinID*2))) | (internalMode << (pinID*2));
			break;

		case PORTB_ID:
			DIOB_PUPDR_REG = (DIOB_PUPDR_REG & ~(0x03 << (pinID*2))) | (internalMode << (pinID*2));
			break;

		case PORTC_ID:
			DIOC_PUPDR_REG = (DIOC_PUPDR_REG & ~(0x03 << (pinID*2))) | (internalMode << (pinID*2));
			break;

		case PORTD_ID:
			DIOD_PUPDR_REG = (DIOD_PUPDR_REG & ~(0x03 << (pinID*2))) | (internalMode << (pinID*2));
			break;

		case PORTE_ID:
			DIOE_PUPDR_REG = (DIOE_PUPDR_REG & ~(0x03 << (pinID*2))) | (internalMode << (pinID*2));
			break;

		case PORTF_ID:
			DIOF_PUPDR_REG = (DIOF_PUPDR_REG & ~(0x03 << (pinID*2))) | (internalMode << (pinID*2));
			break;

		case PORTG_ID:
			DIOG_PUPDR_REG = (DIOG_PUPDR_REG & ~(0x03 << (pinID*2))) | (internalMode << (pinID*2));
			break;

		case PORTH_ID:
			DIOH_PUPDR_REG = (DIOH_PUPDR_REG & ~(0x03 << (pinID*2))) | (internalMode << (pinID*2));
			break;
		}
	}

	return Ret_Val;
}

STD_ReturnState DIO_setAlternateFunction (DIO_PortID portID, DIO_PinID pinID, DIO_AltFuncID altFunID)
{
	STD_ReturnState Ret_Val = RET_OK;

	if(portID >= NUM_OF_PORTS || pinID >= NUM_OF_PINS_PER_PORT)
	{
		Ret_Val = RET_NOK;
	}

	else if(pinID >= PIN0_ID && pinID <= PIN7_ID)
	{
		switch (portID)
		{
		case PORTA_ID:
			DIOA_AFRL_REG = (DIOA_AFRL_REG & ~(0x0F << (pinID*4))) | (altFunID << (pinID*4));
			break;

		case PORTB_ID:
			DIOB_AFRL_REG = (DIOB_AFRL_REG & ~(0x0F << (pinID*4))) | (altFunID << (pinID*4));
			break;

		case PORTC_ID:
			DIOC_AFRL_REG = (DIOC_AFRL_REG & ~(0x0F << (pinID*4))) | (altFunID << (pinID*4));
			break;

		case PORTD_ID:
			DIOD_AFRL_REG = (DIOD_AFRL_REG & ~(0x0F << (pinID*4))) | (altFunID << (pinID*4));
			break;

		case PORTE_ID:
			DIOE_AFRL_REG = (DIOE_AFRL_REG & ~(0x0F << (pinID*4))) | (altFunID << (pinID*4));
			break;

		case PORTF_ID:
			DIOF_AFRL_REG = (DIOF_AFRL_REG & ~(0x0F << (pinID*4))) | (altFunID << (pinID*4));
			break;

		case PORTG_ID:
			DIOG_AFRL_REG = (DIOG_AFRL_REG & ~(0x0F << (pinID*4))) | (altFunID << (pinID*4));
			break;

		case PORTH_ID:
			DIOH_AFRL_REG = (DIOH_AFRL_REG & ~(0x0F << (pinID*4))) | (altFunID << (pinID*4));
			break;
		}
	}

	else if(pinID >= PIN8_ID && pinID <= PIN15_ID)
	{
		pinID = pinID - 8;

		switch (portID)
		{
		case PORTA_ID:
			DIOA_AFRH_REG = (DIOA_AFRH_REG & ~(0x0F << (pinID*4))) | (altFunID << (pinID*4));
			break;

		case PORTB_ID:
			DIOB_AFRH_REG = (DIOB_AFRH_REG & ~(0x0F << (pinID*4))) | (altFunID << (pinID*4));
			break;

		case PORTC_ID:
			DIOC_AFRH_REG = (DIOC_AFRH_REG & ~(0x0F << (pinID*4))) | (altFunID << (pinID*4));
			break;

		case PORTD_ID:
			DIOD_AFRH_REG = (DIOD_AFRH_REG & ~(0x0F << (pinID*4))) | (altFunID << (pinID*4));
			break;

		case PORTE_ID:
			DIOE_AFRH_REG = (DIOE_AFRH_REG & ~(0x0F << (pinID*4))) | (altFunID << (pinID*4));
			break;

		case PORTF_ID:
			DIOF_AFRH_REG = (DIOF_AFRH_REG & ~(0x0F << (pinID*4))) | (altFunID << (pinID*4));
			break;

		case PORTG_ID:
			DIOG_AFRH_REG = (DIOG_AFRH_REG & ~(0x0F << (pinID*4))) | (altFunID << (pinID*4));
			break;

		case PORTH_ID:
			DIOH_AFRH_REG = (DIOH_AFRH_REG & ~(0x0F << (pinID*4))) | (altFunID << (pinID*4));
			break;
		}
	}

	return Ret_Val;
}
/*******************************************************************************
 *                      End of File: dio.c                                        *
 *******************************************************************************/
