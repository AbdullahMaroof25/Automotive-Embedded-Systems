/******************************************************************************
 * Module: DIO
 *
 * File Name: dio_types.h
 *
 * Description: User-defined Types Header File for the DIO Driver
 *
 *
 *******************************************************************************/

#ifndef DIO_TYPES_H_
#define DIO_TYPES_H_

/*******************************************************************************
 *                      Includes                                               *
 *******************************************************************************/

/*******************************************************************************
 *                      Global Constant Macros                                 *
 *******************************************************************************/

/*******************************************************************************
 *                      Global Function Macros                                 *
 *******************************************************************************/

/*******************************************************************************
 *                      Global Data Types and Structures                       *
 *******************************************************************************/

/*User-defined Enumeration to identify DIO Port ID*/
typedef enum
{
	PORTA_ID,
	PORTB_ID,
	PORTC_ID,
	PORTD_ID,
	PORTE_ID,
	PORTF_ID,
	PORTG_ID,
	PORTH_ID
}DIO_PortID;

/*User-defined Enumeration to identify DIO Pin ID*/
typedef enum
{
	PIN0_ID,
	PIN1_ID,
	PIN2_ID,
	PIN3_ID,
	PIN4_ID,
	PIN5_ID,
	PIN6_ID,
	PIN7_ID,
	PIN8_ID,
	PIN9_ID,
	PIN10_ID,
	PIN11_ID,
	PIN12_ID,
	PIN13_ID,
	PIN14_ID,
	PIN15_ID
}DIO_PinID;

/*User-defined Enumeration to identify DIO Pin Mode*/
typedef enum
{
	PIN_INPUT,
	PIN_OUTPUT,
	PIN_ALTERNATE,
	PIN_ANALOG
}DIO_PinMode;

/*User-defined Enumeration to identify DIO Pin Output Level (High, Low)*/
typedef enum
{
	LOGIC_LOW,
	LOGIC_HIGH
}DIO_PinLevel;

/*User-defined Enumeration to identify DIO Pin Internal Mode*/
typedef enum
{
	INACTIVE,
	PULL_UP,
	PULL_DOWN,
	RESERVED
}DIO_InternalMode;

/*User-defined Enumeration to identify DIO Pin Alternate Function*/
typedef enum
{
	AF0,
	AF1,
	AF2,
	AF3,
	AF4,
	AF5,
	AF6,
	AF7,
	AF8,
	AF9,
	AF10,
	AF11,
	AF12,
	AF13,
	AF14,
	AF15
}DIO_AltFuncID;

/*******************************************************************************
 *                      Global Data Prototypes                                 *
 *******************************************************************************/


/*******************************************************************************
 *                      Global Function Prototypes                             *
 *******************************************************************************/


#endif

/*******************************************************************************
 *                      End of File: dio_types.h                               *
 *******************************************************************************/
