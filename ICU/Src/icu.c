

#include "icu.h"




static void (* Channel_1_CLB_Ptr)(void) = (void*)RET_NULLPTR;
static void (* Channel_2_CLB_Ptr)(void) = (void*)RET_NULLPTR;
static void (* Channel_3_CLB_Ptr)(void) = (void*)RET_NULLPTR;
static void (* Channel_4_CLB_Ptr)(void) = (void*)RET_NULLPTR;
static void (* Channel_5_CLB_Ptr)(void) = (void*)RET_NULLPTR;
static void (* Channel_6_CLB_Ptr)(void) = (void*)RET_NULLPTR;




void ICU_Init(void)
{
#if(0)

	switch(channel)
	{
	  case channel_1:
		  TIM8_CCMR1_REG |= WriteValue(1,CC1S_BIT_0_1);
		 // SET_BIT(TIM8_CCER_REG , CC1E_BIT_0 );
	  break;
	  case channel_2:
		  TIM8_CCMR1_REG |= WriteValue(1,CC2S_BIT_8_9);
		  //SET_BIT(TIM8_CCER_REG , CC2E_BIT_4 );
	  break;
	  case channel_3:
		  TIM8_CCMR2_REG |= WriteValue(1,CC3S_BIT_0_1);  //01: CC3 channel is configured as input, IC3 is mapped on TI3
		 // SET_BIT(TIM8_CCER_REG , CC3E_BIT_8 );
		  TIM8_PSC_REG = 7;
		  SET_BIT(TIM8_CR1_REG,CEN_BIT_0);
	  break;
	  case channel_4:
		  TIM1_CCMR1_REG |= WriteValue(1,CC1S_BIT_0_1);
		  //SET_BIT(TIM1_CCER_REG , CC1E_BIT_0 );
	  break;
	  case channel_5:

		  TIM1_CCMR1_REG |= WriteValue(1,CC2S_BIT_8_9);
		  //SET_BIT(TIM1_CCER_REG , CC2E_BIT_4 );

	  break;
	  case channel_6:

		  TIM1_CCMR2_REG |= WriteValue(1,CC3S_BIT_0_1);  //01: CC3 channel is configured as input, IC3 is mapped on TI3
		  //SET_BIT(TIM1_CCER_REG , CC3E_BIT_8 );

	      TIM1_PSC_REG = 7;
	      SET_BIT(TIM1_CR1_REG,CEN_BIT_0);
	  break;

	}
#endif

	  /************   Channels 1,2,3 Tim 8 as ICU  ***************/

	  TIM8_CCMR1_REG |= WriteValue(1,CC1S_BIT_0_1); //01: CC1 channel is configured as input, IC1 is mapped on TI1
	  TIM8_CCMR1_REG |= WriteValue(1,CC2S_BIT_8_9); //01: CC2 channel is configured as input, IC2 is mapped on TI2
	  TIM8_CCMR2_REG |= WriteValue(1,CC3S_BIT_0_1); //01: CC3 channel is configured as input, IC3 is mapped on TI3

	  /************   Channels 4,5,6 Tim 1 as ICU  ***************/

	  TIM1_CCMR1_REG |= WriteValue(1,CC1S_BIT_0_1);   //01: CC1 channel is configured as input, IC1 is mapped on TI1
	  TIM1_CCMR1_REG |= WriteValue(1,CC2S_BIT_8_9);   //01: CC2 channel is configured as input, IC2 is mapped on TI2
	  TIM1_CCMR2_REG |= WriteValue(1,CC3S_BIT_0_1);   //01: CC3 channel is configured as input, IC3 is mapped on TI3

	  /*************  Enable Tim8 with 8 Prescaler so tick time is 1 micro sec Sys Clk is 8 M ====> HSI *******/

	  TIM8_PSC_REG = 7;
	  SET_BIT(TIM8_CR1_REG,CEN_BIT_0);
	  /*************  Enable Tim1 with 8 Prescaler so tick time is 1 micro sec Sys Clk is 8 M ====> HSI *******/

      TIM1_PSC_REG = 7;
      SET_BIT(TIM1_CR1_REG,CEN_BIT_0);

}

void ICU_Control(ICU_Channel channel ,  u8 control)
{
	switch(control)
	{
	case Enable:
		if( channel < channel_4 )
		{
			SET_BIT(TIM8_CCER_REG , ( channel * 4 ) );
		}
		else
		{
			SET_BIT(TIM1_CCER_REG , ( ( channel - 3 ) * 4 ) );

		}

	break;
	case Disable:
		if( channel < channel_4 )
		{
			CLEAR_BIT(TIM8_CCER_REG , ( channel * 4 ) );
		}
		else
		{
			CLEAR_BIT(TIM1_CCER_REG , ( ( channel - 3 ) * 4 ) );

		}

	break;


	}

}


void ICU_SelectEdge(ICU_Channel channel,ICU_Edge edge)
{
	switch(channel)
	{
	  case channel_1:
		  	   if( edge == RISING )
		  	  	{
		  		      CLEAR_BIT(TIM8_CCER_REG,CC1P_BIT_1);
		  		      CLEAR_BIT(TIM8_CCER_REG,CC1NP_BIT_3);
		  	  	 }
		  	  	else if (edge == FALLING )
		  	  	  {
		  	  	  	  SET_BIT(TIM8_CCER_REG,CC1P_BIT_1);
		  	  	  	  CLEAR_BIT(TIM8_CCER_REG,CC1NP_BIT_3);
		  	  	  }
		  	  	else
		  	  	{
		  	  		 SET_BIT(TIM8_CCER_REG,CC1P_BIT_1);
		  	  		 SET_BIT(TIM8_CCER_REG,CC1NP_BIT_3);
		  	  	}
	  break;
	  case channel_2:
	  	  	  if( edge == RISING )
	  	  	  {
	  	  		  CLEAR_BIT(TIM8_CCER_REG,CC2P_BIT_5);
	  	  		  CLEAR_BIT(TIM8_CCER_REG,CC2NP_BIT_7);
	  	  	  }
	  	     else if (edge == FALLING )
	  	  	  {
	  	  		  SET_BIT(TIM8_CCER_REG,CC2P_BIT_5);
	  	  		  CLEAR_BIT(TIM8_CCER_REG,CC2NP_BIT_7);
	  	  	  }
	  	     else
	  	     {
	  	  		  SET_BIT(TIM8_CCER_REG,CC2P_BIT_5);
	  	  		  SET_BIT(TIM8_CCER_REG,CC2NP_BIT_7);
	  	     }
	  break;
	  case channel_3:
	  	  	  if( edge == RISING )
	  	  	  {
	  	  		  CLEAR_BIT(TIM8_CCER_REG,CC3P_BIT_9);
	  	  		  CLEAR_BIT(TIM8_CCER_REG,CC3NP_BIT_11);
	  	  	  }
		  	  else if (edge == FALLING )
	  	  	  {
	  	  		  SET_BIT(TIM8_CCER_REG,CC3P_BIT_9);
	  	  		  CLEAR_BIT(TIM8_CCER_REG,CC3NP_BIT_11);
	  	  	  }
		  	  else
		  	  {
		  		 SET_BIT(TIM8_CCER_REG,CC3P_BIT_9);
		  		SET_BIT(TIM8_CCER_REG,CC3NP_BIT_11);
		  	  }
	  break;
	  case channel_4:
	  	   if( edge == RISING )
	  	  	{
	  		      CLEAR_BIT(TIM1_CCER_REG,CC1P_BIT_1);
	  		      CLEAR_BIT(TIM1_CCER_REG,CC1NP_BIT_3);
	  	  	 }
	  	  	else if (edge == FALLING )
	  	  	  {
	  	  	  	  SET_BIT(TIM1_CCER_REG,CC1P_BIT_1);
	  	  	  	  CLEAR_BIT(TIM1_CCER_REG,CC1NP_BIT_3);
	  	  	  }
	  	  	else
	  	  	{
	  	  		 SET_BIT(TIM1_CCER_REG,CC1P_BIT_1);
	  	  		 SET_BIT(TIM1_CCER_REG,CC1NP_BIT_3);
	  	  	}
	  break;
	  case channel_5:
  	  	  if( edge == RISING )
  	  	  {
  	  		  CLEAR_BIT(TIM1_CCER_REG,CC2P_BIT_5);
  	  		  CLEAR_BIT(TIM1_CCER_REG,CC2NP_BIT_7);
  	  	  }
  	     else if (edge == FALLING )
  	  	  {
  	  		  SET_BIT(TIM1_CCER_REG,CC2P_BIT_5);
  	  		  CLEAR_BIT(TIM1_CCER_REG,CC2NP_BIT_7);
  	  	  }
  	     else
  	     {
  	  		  SET_BIT(TIM1_CCER_REG,CC2P_BIT_5);
  	  		  SET_BIT(TIM1_CCER_REG,CC2NP_BIT_7);
  	     }
	  break;
	  case channel_6:
  	  	  if( edge == RISING )
  	  	  {
  	  		  CLEAR_BIT(TIM1_CCER_REG,CC3P_BIT_9);
  	  		  CLEAR_BIT(TIM1_CCER_REG,CC3NP_BIT_11);
  	  	  }
	  	  else if (edge == FALLING )
  	  	  {
  	  		  SET_BIT(TIM1_CCER_REG,CC3P_BIT_9);
  	  		  CLEAR_BIT(TIM1_CCER_REG,CC3NP_BIT_11);
  	  	  }
	  	  else
	  	  {
	  		 SET_BIT(TIM1_CCER_REG,CC3P_BIT_9);
	  		 SET_BIT(TIM1_CCER_REG,CC3NP_BIT_11);
	  	  }
	  break;
	}



}


STD_ReturnState ICU_INT_CheckStatus(ICU_Channel channel)
{
	STD_ReturnState state;

	switch(channel)
	{
	   case channel_1:
		   state = CHECK_BIT( TIM8_SR_REG , CC1IF_BIT_1 );
		   if( state == 0 )
		   	{
		   	   state = RET_NOK;
		   	}
		   	else
		   	{
			   state = RET_OK;
			}
	   break;
	   case channel_2:
	   	   state = CHECK_BIT( TIM8_SR_REG , CC2IF_BIT_2 );
	   	   if( state == 0 )
	   	   {
	   		   state = RET_NOK;
	   	   }
	   	   else
	   	   {
			  state = RET_OK;
	   	   }

	   break;
	   case channel_3:
	   	   state = CHECK_BIT( TIM8_SR_REG , CC3IF_BIT_3 );
	   	   if( state == 0 )
	   	   {
	   		   state = RET_NOK;
	   	   }
	   	   else
	   	   {
			  state = RET_OK;
	   	   }

	   break;
	   case channel_4:
		   state = CHECK_BIT( TIM1_SR_REG , CC1IF_BIT_1 );
	   	   if( state == 0 )
	   	   {
	   		   state = RET_NOK;
	   	   }
	   	   else
	   	   {
			  state = RET_OK;
	   	   }

	   break;
	   case channel_5:
		   state = CHECK_BIT( TIM1_SR_REG , CC2IF_BIT_2 );
	   	   if( state == 0 )
	   	   {
	   		   state = RET_NOK;
	   	   }
	   	   else
	   	   {
			  state = RET_OK;
	   	   }

	   break;
	   case channel_6:
		   state = CHECK_BIT( TIM1_SR_REG , CC3IF_BIT_3 );
	   	   if( state == 0 )
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


void ICU_Read(ICU_Channel channel,u16 * read_ptr )
{

	switch(channel)
	{
	  case channel_1:
		  * read_ptr = TIM8_CCR1_REG;
	  break;
	  case channel_2:
		  * read_ptr = TIM8_CCR2_REG;
	  break;
	  case channel_3:
		  * read_ptr = TIM8_CCR3_REG;
	  break;
	  case channel_4:
		  * read_ptr = TIM1_CCR1_REG;
	  break;
	  case channel_5:
		  * read_ptr = TIM1_CCR2_REG;
	  break;
	  case channel_6:
		  * read_ptr = TIM1_CCR3_REG;
	  break;
	}

}


void ICU_INT_Enable(ICU_Channel channel,void(*ptr)(void))
{
	switch(channel)
	{
	  case channel_1:
	    	SET_BIT(TIM8_DIER_REG,CC1IE_BIT_1);
	    	if(ptr != (void*)RET_NULLPTR)
	    	{
	    		Channel_1_CLB_Ptr = ptr;
	    	}
	  break;
	  case channel_2:
		   SET_BIT(TIM8_DIER_REG,CC2IE_BIT_2);
	    	if(ptr != (void*)RET_NULLPTR)
	    	{
	    		Channel_2_CLB_Ptr = ptr;
	    	}
	  break;
	  case channel_3:
		   SET_BIT(TIM8_DIER_REG,CC3IE_BIT_3);
	    	if( ptr != (void*)RET_NULLPTR)
	    	{
	    		Channel_3_CLB_Ptr = ptr;
	    	}
	  break;
	  case channel_4:
		   SET_BIT(TIM1_DIER_REG,CC1IE_BIT_1);
	    	if( ptr != (void*)RET_NULLPTR)
	    	{
	    		Channel_4_CLB_Ptr = ptr;
	    	}
	  break;
	  case channel_5:
		   SET_BIT(TIM1_DIER_REG,CC2IE_BIT_2);
	    	if( ptr != (void*)RET_NULLPTR)
	    	{
	    		Channel_5_CLB_Ptr = ptr;
	    	}
	  break;
	  case channel_6:
		   SET_BIT(TIM1_DIER_REG,CC3IE_BIT_3);
	    	if( ptr != (void*)RET_NULLPTR)
	    	{
	    		Channel_6_CLB_Ptr = ptr;
	    	}
	  break;


	}

}


void ICU_INT_Disable(ICU_Channel channel)
{

	switch(channel)
	{
	  case channel_1:
	  	CLEAR_BIT(TIM8_DIER_REG,CC1IE_BIT_1);
	  break;
	  case channel_2:
	  	CLEAR_BIT(TIM8_DIER_REG,CC2IE_BIT_2);
	  break;
	  case channel_3:
	  	CLEAR_BIT(TIM8_DIER_REG,CC3IE_BIT_3);
	  break;
	  case channel_4:
	  	CLEAR_BIT(TIM1_DIER_REG,CC1IE_BIT_1);
	  break;
	  case channel_5:
	  	CLEAR_BIT(TIM1_DIER_REG,CC2IE_BIT_2);
	  break;
	  case channel_6:
	  	CLEAR_BIT(TIM1_DIER_REG,CC3IE_BIT_3);
	  break;
	}

}


//TIM8_CC_IRQHandler
void TIM8_CC_IRQHandler(void)
{

	if ( ICU_INT_CheckStatus(channel_1 ) == RET_OK  )
	{
		CLEAR_BIT( TIM8_SR_REG , CC1IF_BIT_1 );
		if( Channel_1_CLB_Ptr != (void*)RET_NULLPTR )
		{
			Channel_1_CLB_Ptr();
		}
	}

	if ( ICU_INT_CheckStatus(channel_2 ) == RET_OK  )
	{
		CLEAR_BIT( TIM8_SR_REG , CC2IF_BIT_2 );
		if( Channel_2_CLB_Ptr != (void*)RET_NULLPTR )
		{
			Channel_2_CLB_Ptr();
		}
	}

	if ( ICU_INT_CheckStatus(channel_3 ) == RET_OK  )
	{
		CLEAR_BIT( TIM8_SR_REG ,CC3IF_BIT_3 );
		if( Channel_3_CLB_Ptr != (void*)RET_NULLPTR )
		{
			Channel_3_CLB_Ptr();
		}
	}

}


void TIM1_CC_IRQHandler(void)
{
	if ( ICU_INT_CheckStatus(channel_4 ) == RET_OK  )
	{
		CLEAR_BIT( TIM1_SR_REG , CC1IF_BIT_1 );
		if( Channel_4_CLB_Ptr != (void*)RET_NULLPTR )
		{
			Channel_4_CLB_Ptr();
		}
	}

	if ( ICU_INT_CheckStatus(channel_5 ) == RET_OK  )
	{
		CLEAR_BIT( TIM1_SR_REG , CC2IF_BIT_2 );
		if( Channel_5_CLB_Ptr != (void*)RET_NULLPTR )
		{
			Channel_5_CLB_Ptr();
		}
	}

	if ( ICU_INT_CheckStatus(channel_6 ) == RET_OK  )
	{
		CLEAR_BIT( TIM1_SR_REG , CC3IF_BIT_3 );
		if( Channel_6_CLB_Ptr != (void*)RET_NULLPTR )
		{
			Channel_6_CLB_Ptr();
		}
	}
}




