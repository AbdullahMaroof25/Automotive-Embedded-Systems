/*
 * EXT_INT_types.h
 *
 * Created: 10/22/2023 2:24:05 PM
 *  Author: 2022
 */ 


#ifndef EXT_INT_TYPES_H_
#define EXT_INT_TYPES_H_


typedef enum
{
	EXT_INT_0 ,
	EXT_INT_1 ,
	EXT_INT_2
}t_EXT_INT;

typedef enum
{
	LOW_LEVEL ,
	ON_CHANGE ,
	FALLIN_EDGE ,
	RISIN_EDGE
}t_TRIGGERING_CONDITION;


#endif /* EXT_INT_TYPES_H_ */