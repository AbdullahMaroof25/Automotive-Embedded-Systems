/******************************************************************************
 * Module:
 *
 * File Name: exti_reg.h
 *
 * Description:
 *
 * Created on: Nov 15, 2023
 *
 *
 *******************************************************************************/
#ifndef EXTI_REG_H_
#define EXTI_REG_H_
/*******************************************************************************
 *                      Includes                                               *
 *******************************************************************************/

/*******************************************************************************
 *                      Global Constant Macros                                 *
 *******************************************************************************/
#define EXTI_IMR1_REG				(*(volatile u32*)(0x40010400))
#define EXTI_EMR1_REG				(*(volatile u32*)(0x40010404))
#define EXTI_RTSR1_REG				(*(volatile u32*)(0x40010408))
#define EXTI_FTSR1_REG				(*(volatile u32*)(0x4001040C))
#define EXTI_SWIER1_REG				(*(volatile u32*)(0x40010410))
#define EXTI_PR1_REG				(*(volatile u32*)(0x40010414))
#define EXTI_IMR2_REG				(*(volatile u32*)(0x40010420))
#define EXTI_EMR2_REG				(*(volatile u32*)(0x40010424))
#define EXTI_RTSR2_REG				(*(volatile u32*)(0x40010428))
#define EXTI_FTSR2_REG 				(*(volatile u32*)(0x4001042C))
#define EXTI_SWIER2_REG				(*(volatile u32*)(0x40010430))
#define EXTI_PR2_REG				(*(volatile u32*)(0x40010434))
//////
#define SYSCFG_REG_BASE				(0x40010000)  					//page 249
#define SYSCFG_REG0_OFFEST			(0x08)
#define SYSCFG_REG4_OFFEST			(0x14)

#define SYSCFG_EXTICR0				(*(volatile u32*)(SYSCFG_REG_BASE +SYSCFG_REG_OFFEST))  //page 249
#define SYSCFG_EXTICR4				(*(volatile u32*)(SYSCFG_REG_BASE +SYSCFG_REG4_OFFEST))  //page 254

/*******************************************************************************
 *                      Global Function Macros                                 *
 *******************************************************************************/


/*******************************************************************************
 *                      Global Data Types and Structures                       *
 *******************************************************************************/

/*******************************************************************************
 *                      Global Data Prototypes                                 *
 *******************************************************************************/

/*******************************************************************************
 *                      Global Function Prototypes                             *
 *******************************************************************************/

/*******************************************************************************
 *                      End of File: EXTI_reg.h                                        *
 *******************************************************************************/
#endif /* EXTI_REG_H_ */
