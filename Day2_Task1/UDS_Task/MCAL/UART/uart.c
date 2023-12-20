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
#include <stdio.h>


void (*txcPtr)(void) = NULL;
void (*rxcPtr)(void) = NULL;

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

void UART_TransmitChrPolling(u8 data)
{
	while (!(CHECK_BIT(UART_UCSRA_REG,UDRE_BIT_NO)));
	/* Put data into buffer, sends the data */
	UART_UDR_REG = data;
}

u8 UART_ReceiveChrPolling(void)
{
		while (!(CHECK_BIT(UART_UCSRA_REG,RXC_BIT_NO)));

	/* Get and return received data from buffer */
	return UART_UDR_REG;
}


void UART_TransmitChrINT(u8 data)
{
	/* Put data into buffer, sends the data */
	UART_UDR_REG = data;
}

u8 UART_ReceiveChrINT(void)
{	
	/* Get and return received data from buffer */
	return UART_UDR_REG;
}


void UART_SendString(u8* str)
{
	while(*str != '\0')
	{
		UART_TransmitChrPolling(*str);
		str++;
	}
}
void UART_ReceiveString(u8* str)
{
	u8 i = 0;
	while(str[i] != '\0')
	{
		str[i++] = UART_ReceiveChrPolling();
		
	}
}



void UART_setTxCallback(void (*ptr)(void))
{
	txcPtr = ptr;
}

void UART_setRxCallback(void (*ptr)(void))
{
	rxcPtr = ptr;
}

ISR(USART_TXC_vect)
{
	if (txcPtr != NULL)
	{
		txcPtr();	
	}
}


ISR(USART_RXC_vect)
{
	if (rxcPtr != NULL)
	{
		rxcPtr();
	}
}