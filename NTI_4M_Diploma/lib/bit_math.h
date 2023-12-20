/*
 * bit_math.h
 *
 * Created: 10/20/2023 11:07:36 AM
 *  Author: 2022
 */ 


#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(REG,BIT_NO)		  (REG |= (1<<BIT_NO))
#define CLEAR_BIT(REG,BIT_NO)     (REG &= ~(1<<BIT_NO))
#define CHECK_BIT(REG,BIT_NO)	  ((REG>>BIT_NO)&1)
#define FLIP_BIT(REG,BIT_NO)	  (REG=(REG^(1<<BIT_NO)))



#endif /* BIT_MATH_H_ */