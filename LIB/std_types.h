/******************************************************************************
 * Module: Library
 *
 * File Name: std_types.h
 *
 * Description: Contains essential standard types
 *
 *
 *******************************************************************************/


#ifndef STD_TYPES_H
#define STD_TYPES_H

/*******************************************************************************
 *                      Global Constant Macros                                 *
 *******************************************************************************/
//#define NULL_PTR    ((void*)0)

#define NULLPTR   ((void*)0)
#define NULL (0u)


#define STD_HIGH		(1u)
#define STD_LOW		(0u)

/*******************************************************************************
 *                      Global Function Macros                                 *
 *******************************************************************************/

/*******************************************************************************
 *                      Global Data Types and Structures                       *
 *******************************************************************************/

typedef unsigned char u8;				/*           0 .. 255              */
typedef signed char s8;					/*        -128 .. +127             */

typedef unsigned short  u16;			/*           0 .. 65535            */
typedef signed short s16;				/*      -32768 .. +32767           */

typedef unsigned long u32;				/*           0 .. 4294967295       */
typedef signed long s32;				/* -2147483648 .. +2147483647      */

typedef unsigned long long u64;			/*       0 .. 18446744073709551615  */
typedef signed long long s64;			/* -9223372036854775808 .. 9223372036854775807 */

typedef float f32;						
typedef double f64;


typedef enum 
{
	FALSE,
	TRUE
}STD_Boolean;

typedef enum
{
	E_OK,
	E_NOT_OK,
	NULL_PTR
}STD_ReturnState;

/*******************************************************************************
 *                      Global Data Prototypes                                 *
 *******************************************************************************/


/*******************************************************************************
 *                      Global Function Prototypes                             *
 *******************************************************************************/
 
#endif  /* STD_TYPES_H */
