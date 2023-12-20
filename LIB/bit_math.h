/******************************************************************************
 * Module: Library
 *
 * File Name: bit_math.h
 *
 * Description: Contains essential macro-like functions
 *
 *
 *******************************************************************************/


#ifndef BIT_MATH_H_
#define BIT_MATH_H_

/*******************************************************************************
 *                      Global Constant Macros                                 *
 *******************************************************************************/


/*******************************************************************************
 *                      Global Function Macros                                 *
 *******************************************************************************/
 
/* Set a certain bit in any register */
#define SET_BIT(REG, BIT_NO)		(u32)(REG |= (1<<BIT_NO))

/* Clear a certain bit in any register */
#define CLEAR_BIT(REG, BIT_NO)		(u32)(REG=(REG&(~(1<<BIT_NO))))  //(u32)(REG &= ~(1<<BIT_NO))     reg=(reg&(~(1<<bit)))

/* Check a certain bit in any register */
#define CHECK_BIT(REG, BIT_NO)		(u32)((REG>>BIT_NO) & 1)

/* Check if a specific bit is set in any register and return true if yes */
#define BIT_IS_SET(REG,BIT)			(u32)(REG & (1<<BIT))

/* Check if a specific bit is cleared in any register and return true if yes */
#define BIT_IS_CLEAR(REG,BIT)		(u32)(!(REG & (1<<BIT)))

/* Toggle a certain bit in any register */
#define FLIP_BIT(REG, BIT_NO)		(u32)(REG ^= (1<<BIT_NO))


#define WriteValue(value,BitOrder)  (u32)(value<<BitOrder)

/*******************************************************************************
 *                      Global Data Types and Structures                       *
 *******************************************************************************/


/*******************************************************************************
 *                      Global Data Prototypes                                 *
 *******************************************************************************/


/*******************************************************************************
 *                      Global Function Prototypes                             *
 *******************************************************************************/
 
#endif /* BIT_MATH_H_ */
