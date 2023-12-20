/*
 * keypad.h
 *
 * Created: 10/24/2023 2:08:00 PM
 *  Author: 2022
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "std_types.h"
#include "bit_math.h"
#include "dio.h"


	



/*	Rows Configurations	*/

#define KEYPAD_ROW_PORT  				DIO_PORTC

#define KEYPAD_ROW1_PORT				DIO_PORTC
#define KEYPAD_ROW2_PORT				DIO_PORTC
#define KEYPAD_ROW3_PORT				DIO_PORTC
#define KEYPAD_ROW4_PORT				DIO_PORTC

#define KEYPAD_ROW1_CHANNEL				DIO_PIN5
#define KEYPAD_ROW2_CHANNEL				DIO_PIN4
#define KEYPAD_ROW3_CHANNEL				DIO_PIN3
#define KEYPAD_ROW4_CHANNEL				DIO_PIN2

/*	Columns Configurations	*/

#define KEYPAD_COL_PORT				    DIO_PORTD

#define KEYPAD_COL1_PORT				DIO_PORTD
#define KEYPAD_COL2_PORT				DIO_PORTD
#define KEYPAD_COL3_PORT				DIO_PORTD
#define KEYPAD_COL4_PORT				DIO_PORTD

#define KEYPAD_COL1_CHANNEL				DIO_PIN7
#define KEYPAD_COL2_CHANNEL				DIO_PIN6
#define KEYPAD_COL3_CHANNEL				DIO_PIN5
#define KEYPAD_COL4_CHANNEL				DIO_PIN3


void keypad_vidInit(void);
u8 keypad_u8GetKey(void);



#endif /* KEYPAD_H_ */