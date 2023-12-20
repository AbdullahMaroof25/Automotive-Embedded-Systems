 /***************************************
 *  File		: Uart.h
 *	Module		: UART
 *	Target		: ATMEGA32
 *	Author		: mFawzi
 *  Description	:
 ****************************************/
#ifndef UART_H
#define UART_H

#include "Std_Types.h"
#include "uart_reg.h"
#include "bit_math.h"
#include "uart.h"

#define UART_BAUDRATE_1200			(0x340)
#define UART_BAUDRATE_2400			(0x19F)
#define UART_BAUDRATE_4800			(0xCF)
#define UART_BAUDRATE_9600			(0x67)
#define UART_BAUDRATE_19200			(0x51)
#define UART_BAUDRATE_115200		(0x7)


#define UART_5_BIT_DATA				(0<<UCSZ0_BIT_NO)
#define UART_6_BIT_DATA				(1<<UCSZ0_BIT_NO)
#define UART_7_BIT_DATA				(2<<UCSZ0_BIT_NO)
#define UART_8_BIT_DATA				(3<<UCSZ0_BIT_NO)

#define UART_1_STOP_BIT				(0<<USBS_BIT_NO)
#define UART_2_STOP_BIT				(1<<USBS_BIT_NO)

#define UART_EVEN_PARITY			(2<<UPM0_BIT_NO)
#define UART_ODD_PARITY				(3<<UPM0_BIT_NO)

void UART_Init(u16 baudRate);
void UART_TransmitChrPolling(u8 data);
u8 UART_ReceiveChrPolling(void);
void UART_TransmitChrINT(u8 data);
u8 UART_ReceiveChrINT(void);

void UART_SendString(u8* str);
void UART_ReceiveString(u8* str);



void UART_setTxCallback(void (*ptr)(void));
void UART_setRxCallback(void (*ptr)(void));

#endif  /* UART_H */
