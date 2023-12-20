 /**************************************************
 *  File		: Uart.c
 *	Module		: UART
 *	Target		: ATMEGA32
 *	Author		: mFawzi
 *  Description	:
 *
 ***************************************************/
#include "uart.h"
#include <avr/interrupt.h>
#include "led.h"






static void ( *Tx_PTR_CLB ) (void) = NULLPTR;
static void ( *Rx_PTR_CLB ) (void) = NULLPTR;



void UART_Init(u16 baudRate)
{
	/* Set baud rate */
	UART_UBRRH_REG = (u8)(baudRate>>8);
	UART_UBRRL_REG = (u8)baudRate;
	/* Enable receiver and transmitter */
	SET_BIT(UART_UCSRB_REG,RXEN_BIT_NO);  /* Enable Receiver*/
	
	SET_BIT(UART_UCSRB_REG,TXEN_BIT_NO);  /* Enable Transmitter */
	/* Set frame format: 8data, 1stop bit, Even Parity */
	UART_UCSRC_REG |= (1 << URSEL_BIT_NO)|UART_8_BIT_DATA | UART_EVEN_PARITY;

	
	
	/*	Enable Rx complete	*/
	SET_BIT(UART_UCSRB_REG,RXC_BIT_NO);
	/*	Enable Tx complete	*/
	SET_BIT(UART_UCSRB_REG,TXC_BIT_NO);
}



void UART_TransmitChr(u8 data)
{
	/* Wait for empty transmit buffer */
//	while (!(CHECK_BIT(UART_UCSRA_REG,UDRE_BIT_NO)))
//			;
	/* Put data into buffer, sends the data */
	UART_UDR_REG = data;
}

u8 UART_ReceiveChr(void)
{
	/* Wait for data to be received */
	//while (!(CHECK_BIT(UART_UCSRA_REG,RXC_BIT_NO)))
			;
	/* Get and return received data from buffer */
	return UART_UDR_REG;
}

void UART_TransmitStrPoll(u8 str[])
{
	while (*str != '\0')
	{
		UART_TransmitChr(*str);
		str++;
	}
}
#if(0)
void UART_TransmitStr(u8 *str)
{
	u8 i=0;
	/*	copy str into global tx buffer	*/
	for (i=0; i < TX_BUFFER_MAX_SIZE; i++)
	{
		tx_buffer[i] = str[i];
	}
	UART_TransmitChr(tx_buffer[tx_index]);
}
#endif


void UART_SetCallBacks(MSG_CLB cpy_CLB,void (*func ) (void))
{
	switch(cpy_CLB)
	{
		case Tx_CallBack:
		Tx_PTR_CLB = func;
		break;
		case Rx_CallBack:
		Rx_PTR_CLB = func;
		break;
	}
}


ISR(USART_TXC_vect)
{
	/*
	*/
	
	if ( Tx_PTR_CLB != NULLPTR)
	{
		Tx_PTR_CLB();
	}
	
	
}

 volatile u8 flag = 0;

ISR (USART_RXC_vect)
{
	/**/
	if ( Rx_PTR_CLB != NULLPTR)
	{
		Rx_PTR_CLB();
	}
	
	
}


uart_status Uart_Satus(void)
{
	if( CHECK_BIT(UART_UDR_REG,5) == 1)
	{
		return ok;
	}
	else
	{
		return busy;
	}
	
}