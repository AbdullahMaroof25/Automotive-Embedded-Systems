#include "comM.h"
#include <avr/interrupt.h>


u8 tx_index =0;
u8 tx_1_index = 0;

u8 rx_index =0;

boolean Rx_Is_Complete = FALSE;

boolean First_Send = FALSE;
boolean First_Send_Complete = FALSE;



u8 tx_buffer[Tx_MSG_Len];
u8 tx_1_buffer[Tx_MSG_Len];
u8 rx_buffer[Rx_MSG_Len];

boolean Tx_Start = FALSE;
boolean Rx_Start = FALSE;


void comM_init(void)
{
	UART_Init(UART_BAUDRATE_9600);
	UART_SetCallBacks(Rx_CallBack,Rx_CallBack_Func);
	UART_SetCallBacks(Tx_CallBack,Tx_CallBack_Func);
	Create_Buffer();
}

void Tx_CallBack_Func(void)
{
	
	
	if ( First_Send_Complete == FALSE )
	{
		 tx_1_index++;
		 
		 if ( ( tx_1_buffer[tx_1_index] != '\0' ) )
		 {
			 UART_TransmitChr(tx_1_buffer[tx_1_index]);
		 }
		 else
		 {
			 First_Send_Complete = TRUE; 
			 if ( BufferStatus() != Empty)
			 {
				 Get_From_Buffer(tx_buffer);
				 UART_TransmitChr(tx_buffer[0]);
				 
			 }
			 
		 }
		
	}
	else 
	{
		tx_index++;
		if ( ( tx_buffer[tx_index] != '\0' ) )    
		{
			UART_TransmitChr(tx_buffer[tx_index]);
			
		}
		else
		{
			tx_index=0;
			if ( BufferStatus() != Empty)
			{
				Get_From_Buffer(tx_buffer);
				UART_TransmitChr(tx_buffer[0]);
			}
			
		}
	}
}


void Send_Message(u8 *Tx_Message )
{
	
	if (	First_Send == FALSE )
	{
		First_Send = TRUE;
		for (u8 i = 0 ; i < Tx_MSG_Len ; i++ )
		{
			tx_1_buffer[i] = Tx_Message[i];
		}
		UART_TransmitChr(tx_1_buffer[0]);
	}
	else
	{
		for (u8 i = 0 ; i < Tx_MSG_Len ; i++ )
		{
			tx_buffer[i] = Tx_Message[i];
		}
		
		if (BufferStatus() != Full )
		{
			Add_To_Buffer(tx_buffer);
		}
		else
		{
			
		}
		
	}
	
	
}

void Rx_CallBack_Func(void)
{
	volatile u8 ch;
	ch = UART_ReceiveChr();
	if ( ( ch != '\r' )  &&
	( rx_index < Rx_MSG_Len )
	
	)
	{
		rx_buffer[rx_index] = ch;
		rx_index++;
		
		
	}
	else
	{
		rx_buffer[rx_index] = '\0';
		rx_index = 0;
		Rx_Is_Complete = TRUE;
		
	}
}


boolean Message_Is_Complete(void)
{
	if ( Rx_Is_Complete == TRUE)
	{
		Rx_Is_Complete = FALSE;
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}





void Receive_Message(u8 *Rx_Message  )
{
	for (u8 i = 0 ; i < Rx_MSG_Len ; i++ )
	{
		Rx_Message[i] = rx_buffer[i];
	}

}





