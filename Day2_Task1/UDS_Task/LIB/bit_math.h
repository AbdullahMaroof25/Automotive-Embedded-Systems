/*
 * bit_math.h
 *
 * Created: 10/20/2023 11:07:31 AM
 *  Author: reBuyTech
 */ 

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(REG,BIT_NO)			(REG |= (1<<BIT_NO))
#define CLEAR_BIT(REG,BIT_NO)		(REG &= ~(1<<BIT_NO))
#define CHECK_BIT(REG,BIT_NO)		((REG>>BIT_NO)&1)

#endif /* BIT_MATH_H_ */