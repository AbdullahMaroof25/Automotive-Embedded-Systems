/*******************************************************************************
 *  FILE DESCRIPTION
 *  ----------------------------------------------------------------------------
 * Module: ADC
 *
 * File Name: adc.c
 *
 * Description: Source file for the ADC driver
 *
 * Author: Abdullah Maroof
 *
 *******************************************************************************/

/*******************************************************************************
 *                      Includes                                               *
 *******************************************************************************/
#include "adc.h"

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


/**************************************************************************************************************
* Syntax                : void ADC1_Init(ADC1_Channel_t channel)
* Description           : Init ADC 1 Channel
*
* Sync\Async            : Synchronous
* Reentrancy            : Non Reentrant
* Parameters (in)       : channel
* Parameter Description : Required Channel to be Initialized for ADC 1
* Return value:         : void
*
***************************************************************************************************************/
void ADC1_Init(ADC_Channel_t channel)
{
    ADC1_CR_REG   = 0x00000000;
    //  12-bit Resolution , Single conversion mode ,  Right alignment
    ADC1_CFGR_REG = 0x00000000;
    SET_BIT(ADC1_CFGR_REG,DISCEN_BIT_16);   // 1: Discontinuous mode for regular channels enabled
    SET_BIT(ADC1_CFGR_REG,OVRMOD_BIT12);   // enable x_DR register is overwritten with the last conversion result when an overrun is detected
    ADC1_CFGR_REG |= WriteValue(0 , EXTEN_BIT_10_11 ); // : Hardware trigger detection disabled (conversions can be launched by software
    //  4.5 ADC clock cycles
    if ( channel < 10 )
    {
       ADC1_SMPR1_REG  |=  WriteValue(2 , ( SMP1_BIT_3_4_5  * channel ) );
    }
    else if (channel < 19)
    {
       ADC1_SMPR2_REG  |=  WriteValue(2 , ( SMP10_BIT_0_1_2 * (channel - 10 ) ) );
    }
    //  1 conversion
    ADC1_SQR1_REG  = 0x00000000;
    ADC1_SQR1_REG  |= WriteValue(0 , L_BIT_0_1_2_3 );
  /* DC common control register */
    ADC1_CCR_REG |= WriteValue(0 , DUAL_BIT_0_1_2_3_4 );  // Independent mode
    ADC1_CCR_REG |= WriteValue(2 , CKMODE_BIT_16_17 );   // Synchronous clock mode clk/2

    
}

/**************************************************************************************************************
* Syntax                : void ADC2_Init(ADC1_Channel_t channel)
* Description           : Init ADC 2 Channel
*
* Sync\Async            : Synchronous
* Reentrancy            : Non Reentrant
* Parameters (in)       : channel
* Parameter Description : Required Channel to be Initialized for ADC 2
* Return value:         : void
*
***************************************************************************************************************/
void ADC2_Init(ADC_Channel_t channel)
{
    ADC2_CR_REG   = 0x00000000;
    //  12-bit Resolution , Single conversion mode ,  Right alignment
    ADC2_CFGR_REG = 0x00000000;
    SET_BIT(ADC2_CFGR_REG,DISCEN_BIT_16);   // 1: Discontinuous mode for regular channels enabled
    SET_BIT(ADC2_CFGR_REG,OVRMOD_BIT12);   // enable x_DR register is overwritten with the last conversion result when an overrun is detected
    ADC2_CFGR_REG |= WriteValue(0 , EXTEN_BIT_10_11 ); // : Hardware trigger detection disabled (conversions can be launched by software
    //  4.5 ADC clock cycles
    if ( channel < 10 )
    {
       ADC2_SMPR1_REG  |=  WriteValue(2 , ( SMP1_BIT_3_4_5  * channel ) );
    }
    else if (channel < 19)
    {
       ADC2_SMPR2_REG  |=  WriteValue(2 , ( SMP10_BIT_0_1_2 * (channel - 10 ) ) );
    }
    //  1 conversion
    ADC2_SQR1_REG  = 0x000011111;
    ADC2_SQR1_REG  |= WriteValue(0 , L_BIT_0_1_2_3 );
  /* DC common control register */
    ADC1_CCR_REG |= WriteValue(0 , DUAL_BIT_0_1_2_3_4 );  // Independent mode
    ADC1_CCR_REG |= WriteValue(2 , CKMODE_BIT_16_17 );   // Synchronous clock mode clk/2


    
}

/**************************************************************************************************************
* Syntax                : void ADC3_Init(ADC3_Channel_t channel)
* Description           : Init ADC 3 Channel
*
* Sync\Async            : Synchronous
* Reentrancy            : Non Reentrant
* Parameters (in)       : channel
* Parameter Description : Required Channel to be Initialized for ADC 3
* Return value:         : void
*
***************************************************************************************************************/
void ADC3_Init(ADC_Channel_t channel)
{
    ADC3_CR_REG   = 0x00000000;
    //  12-bit Resolution, Single conversion mode, Right alignment
    ADC3_CFGR_REG = 0x00000000;
    SET_BIT(ADC3_CFGR_REG, DISCEN_BIT_16);   // 1: Discontinuous mode for regular channels enabled
    SET_BIT(ADC3_CFGR_REG, OVRMOD_BIT12);   // Enable x_DR register is overwritten with the last conversion result when an overrun is detected
    ADC3_CFGR_REG |= WriteValue(0x00, EXTEN_BIT_10_11); // Hardware trigger detection disabled (conversions can be launched by software
    //  4.5 ADC clock cycles
    if (channel < 10)
    {
        ADC3_SMPR1_REG  |=  WriteValue(0x02, (SMP1_BIT_3_4_5 * channel));
    }
    else if (channel < 19)
    {
        ADC3_SMPR2_REG  |=  WriteValue(0x02, (SMP10_BIT_0_1_2 * (channel - 10)));
    }
    //  1 conversion
    ADC3_SQR1_REG  = 0x00000000;
    ADC3_SQR1_REG  |= WriteValue(0x00, L_BIT_0_1_2_3);
    /* DC common control register */
    ADC3_CCR_REG |= WriteValue(0x00, DUAL_BIT_0_1_2_3_4);  // Independent mode
    ADC3_CCR_REG |= WriteValue(2 , CKMODE_BIT_16_17 );   // Synchronous clock mode clk/2
}
/*****************************************************************************************************************
* Syntax                : void ADC4_Init(ADC4_Channel_t channel)
* Description           : Init ADC 4 Channel
*
* Sync\Async            : Synchronous
* Reentrancy            : Non Reentrant
* Parameters (in)       : channel
* Parameter Description : Required Channel to be Initialized for ADC 4
* Return value:         : void
*
******************************************************************************************************************/
void ADC4_Init(ADC_Channel_t channel)
{
    ADC4_CR_REG   = 0x00000000;
    //  12-bit Resolution, Single conversion mode, Right alignment
    ADC4_CFGR_REG = 0x00000000;
    SET_BIT(ADC4_CFGR_REG, DISCEN_BIT_16);   // 1: Discontinuous mode for regular channels enabled
    SET_BIT(ADC4_CFGR_REG, OVRMOD_BIT12);   // Enable x_DR register is overwritten with the last conversion result when an overrun is detected
    ADC4_CFGR_REG |= WriteValue(0x00, EXTEN_BIT_10_11); // Hardware trigger detection disabled (conversions can be launched by software
    //  4.5 ADC clock cycles
    if (channel < 10)
    {
        ADC4_SMPR1_REG  |=  WriteValue(0x02, (SMP1_BIT_3_4_5 * channel));
    }
    else if (channel < 19)
    {
        ADC4_SMPR2_REG  |=  WriteValue(0x02, (SMP10_BIT_0_1_2 * (channel - 10)));
    }
    //  1 conversion
    ADC4_SQR1_REG  = 0x00000000;
    ADC4_SQR1_REG  |= WriteValue(0x00, L_BIT_0_1_2_3);
    /* DC common control register */
    ADC3_CCR_REG |= WriteValue(0x00, DUAL_BIT_0_1_2_3_4);  // Independent mode
    ADC3_CCR_REG |= WriteValue(2 , CKMODE_BIT_16_17 );   // Synchronous clock mode clk/2
}



/*******************************************************************************************************************
* Syntax                : void ADC_Start(ADC_t adc)
* Description           : Starts conversion for the specified ADC.
*
* Sync\Async            : Synchronous
* Reentrancy            : Non Reentrant
* Parameters (in)       : adc
* Parameter Description : ADC to start conversion (ADC_1 or ADC_2 or ADC_3 or ADC_4 )
* Return value          : void
*******************************************************************************************************************/
void ADC_Start(ADC_t adc)
{
    
    switch (adc)
    {
        case ADC_1:
            /* code */
             SET_BIT(ADC1_CR_REG , ADSTART_BIT_2 );
        break;
        case ADC_2:
            /* code */
             SET_BIT(ADC2_CR_REG , ADSTART_BIT_2 );
        break;  
		case ADC_3:
            /* code */
             SET_BIT(ADC3_CR_REG , ADSTART_BIT_2 );
        break;
        case ADC_4:
            /* code */
             SET_BIT(ADC4_CR_REG , ADSTART_BIT_2 );
        break;

    }

    
}


/******************************************************************************************************************
* Syntax                : STD_ReturnState ADC_CheckStatus(ADC_t adc, ADC_Status_t Status)
* Description           : Checks the specified status for the given ADC.
*
* Sync\Async            : Synchronous
* Reentrancy            : Non Reentrant
* Parameters (in)       : adc
* Parameter Description : ADC to check status(ADC_1 or ADC_2 or ADC_3 or ADC_4 )
* Return value          : STD_ReturnState - RET_OK if the status is set, RET_NOK otherwise
*******************************************************************************************************************/
STD_ReturnState ADC_CheckStatus(ADC_t adc, ADC_Status_t Status)
{
    STD_ReturnState state;
    switch (adc)
    {
    case ADC_1:
        /* code */
            if( CHECK_BIT(ADC1_ISR_REG , Status )  == 0 )
            {
            	state = RET_NOK;
            }
            else
            {
            	state = RET_OK;
            }
    break;
    case ADC_2:
        /* code */
            if( CHECK_BIT(ADC2_ISR_REG , Status )  == 0 )
            {
            	state = RET_NOK;
            }
            else
            {
            	state = RET_OK;
            }
    break;
        case ADC_3:
            /* code */
                if( CHECK_BIT(ADC3_ISR_REG , Status )  == 0 )
                {
                	state = RET_NOK;
                }
                else
                {
                	state = RET_OK;
                }
        break;
        case ADC_4:
            /* code */
                if( CHECK_BIT(ADC4_ISR_REG , Status )  == 0 )
                {
                	state = RET_NOK;
                }
                else
                {
                	state = RET_OK;
                }
        break;


    }

    return state;

    
}


/******************************************************************************************************************
* Syntax                : void ADC_Enable(ADC_t adc)
* Description           : Enables the specified ADC.
*
* Sync\Async            : Synchronous
* Reentrancy            : Non Reentrant
* Parameters (in)       : adc
* Parameter Description : ADC to be enabled (ADC_1 or ADC_2 or ADC_3 or ADC_4 )
* Return value          : void
*******************************************************************************************************************/

void ADC_Enable(ADC_t adc)
{
    switch (adc)
    {
        case ADC_1:
            /* code */
             SET_BIT(ADC1_CR_REG , ADEN_BIT_0 );
        break;
        case ADC_2:
            /* code */
             SET_BIT(ADC2_CR_REG , ADEN_BIT_0 );
        break;   
		 case ADC_3:
            /* code */
             SET_BIT(ADC3_CR_REG , ADEN_BIT_0 );
        break;
        case ADC_4:
            /* code */
             SET_BIT(ADC4_CR_REG , ADEN_BIT_0 );
        break;

    }
}


/******************************************************************************************************************
* Syntax                : u16  ADC_Read(ADC_t adc)
* Description           : Reads the converted value from the specified ADC.
*
* Sync\Async            : Synchronous
* Reentrancy            : Non Reentrant
* Parameters (in)       : adc
* Parameter Description : ADC to read value from (ADC_1 or ADC_2 or ADC_3 or ADC_4 )
* Return value          : u16 - Converted ADC value
*******************************************************************************************************************/

void  ADC_Read(ADC_t adc , u16 *Read_Ptr)
{
    switch (adc)
    {
        case ADC_1:
            /* code */
        	*Read_Ptr  = ADC1_DR_REG;
        break;
        case ADC_2:
            /* code */
        	*Read_Ptr = ADC2_DR_REG;
        break; 
        case ADC_3:
            /* code */
        	*Read_Ptr  = ADC3_DR_REG;
        break;
        case ADC_4:
            /* code */
        	*Read_Ptr  = ADC4_DR_REG;
        break;		

    }
}


/******************************************************************************************************************
* Syntax                : void ADC_Disable(ADC_t adc)
* Description           : Disables the specified ADC.
*
* Sync\Async            : Synchronous
* Reentrancy            : Non Reentrant
* Parameters (in)       : adc
* Parameter Description : ADC to be disabled (ADC_1 or ADC_2 or ADC_3 or ADC_4 )
* Return value          : void
*******************************************************************************************************************/

void ADC_Disable(ADC_t adc)
{
    switch (adc)
    {
        case ADC_1:
            /* code */
             CLEAR_BIT(ADC1_CR_REG , ADEN_BIT_0 );
        break;
        case ADC_2:
            /* code */
             CLEAR_BIT(ADC2_CR_REG , ADEN_BIT_0 );
        break;   
        case ADC_3:
            /* code */
             CLEAR_BIT(ADC3_CR_REG , ADEN_BIT_0 );
        break;
        case ADC_4:
            /* code */
             CLEAR_BIT(ADC4_CR_REG , ADEN_BIT_0 );
        break;		

    }
}


/*******************************************************************************
 *                      End of File: .c                                        *
 *******************************************************************************/
