/******************************************************************************
 * Module: DIO
 *
 * File Name: dio_reg.h
 *
 * Description: Header File for the DIO Driver registers
 * 
 *******************************************************************************/

#ifndef DIO_REG_H_
#define DIO_REG_H_

/*******************************************************************************
 *                      Includes                                               *
 *******************************************************************************/
#include "std_types.h"

/*******************************************************************************
 *                      Global Constant Macros                                 *
 *******************************************************************************/

/*********************** DIO Ports(A-H) Base Addresses *************************/
#define DIOA_BASE_ADDRESS				(0x48000000ul)
#define DIOB_BASE_ADDRESS				(0x48000400ul)
#define DIOC_BASE_ADDRESS				(0x48000800ul)
#define DIOD_BASE_ADDRESS				(0x48000C00ul)
#define DIOE_BASE_ADDRESS				(0x48001000ul)
#define DIOF_BASE_ADDRESS				(0x48001400ul)
#define DIOG_BASE_ADDRESS				(0x48001800ul)
#define DIOH_BASE_ADDRESS				(0x48001C00ul)

/*************************** DIO Registers Offsets *****************************/
#define DIOx_MODER_OFFSET				(0x00u)		/*DIO Port Mode Register*/
#define DIOx_OTYPER_OFFSET				(0x04u)		/*DIO Port Output Type Register*/
#define DIOx_OSPEEDR_OFFSET				(0x08u)		/*DIO Port Output Speed Register*/
#define DIOx_PUPDR_OFFSET				(0x0Cu)		/*DIO Port Pull-up/Pull-down Register*/
#define DIOx_IDR_OFFSET					(0x10u)		/*DIO Port Input Data Register*/
#define DIOx_ODR_OFFSET					(0x14u) 	/*DIO Port Output Data Register*/
#define DIOx_BSRR_OFFSET				(0x18u)		/*DIO Port Bit Set/Reset Register*/
#define DIOx_LCKR_OFFSET				(0x1Cu)		/*DIO Port Configuration Lock Register*/
#define DIOx_AFRL_OFFSET				(0x20u)		/*DIO Alternate Function Low Register*/
#define DIOx_AFRH_OFFSET				(0x24u)		/*DIO Alternate Function High Register*/
#define DIOx_BRR_OFFSET					(0x28u)		/*DIO Port Bit Reset Register*/

/************************** DIO Ports(A-H) Registers ***************************/
#define DIOA_MODER_REG					(*(volatile u32*) (DIOA_BASE_ADDRESS + DIOx_MODER_OFFSET))
#define DIOA_OTYPER_REG					(*(volatile u32*) (DIOA_BASE_ADDRESS + DIOx_OTYPER_OFFSET))
#define DIOA_OSPEEDR_REG				(*(volatile u32*) (DIOA_BASE_ADDRESS + DIOx_OSPEEDR_OFFSET))
#define DIOA_PUPDR_REG					(*(volatile u32*) (DIOA_BASE_ADDRESS + DIOx_PUPDR_OFFSET))
#define DIOA_IDR_REG					(*(volatile u32*) (DIOA_BASE_ADDRESS + DIOx_IDR_OFFSET))
#define DIOA_ODR_REG					(*(volatile u32*) (DIOA_BASE_ADDRESS + DIOx_ODR_OFFSET))
#define DIOA_BSRR_REG					(*(volatile u32*) (DIOA_BASE_ADDRESS + DIOx_BSRR_OFFSET))
#define DIOA_LCKR_REG					(*(volatile u32*) (DIOA_BASE_ADDRESS + DIOx_LCKR_OFFSET))
#define DIOA_AFRL_REG					(*(volatile u32*) (DIOA_BASE_ADDRESS + DIOx_AFRL_OFFSET))
#define DIOA_AFRH_REG					(*(volatile u32*) (DIOA_BASE_ADDRESS + DIOx_AFRH_OFFSET))
#define DIOA_BRR_REG					(*(volatile u32*) (DIOA_BASE_ADDRESS + DIOx_BRR_OFFSET))

#define DIOB_MODER_REG					(*(volatile u32*) (DIOB_BASE_ADDRESS + DIOx_MODER_OFFSET))
#define DIOB_OTYPER_REG					(*(volatile u32*) (DIOB_BASE_ADDRESS + DIOx_OTYPER_OFFSET))
#define DIOB_OSPEEDR_REG				(*(volatile u32*) (DIOB_BASE_ADDRESS + DIOx_OSPEEDR_OFFSET))
#define DIOB_PUPDR_REG					(*(volatile u32*) (DIOB_BASE_ADDRESS + DIOx_PUPDR_OFFSET))
#define DIOB_IDR_REG					(*(volatile u32*) (DIOB_BASE_ADDRESS + DIOx_IDR_OFFSET))
#define DIOB_ODR_REG					(*(volatile u32*) (DIOB_BASE_ADDRESS + DIOx_ODR_OFFSET))
#define DIOB_BSRR_REG					(*(volatile u32*) (DIOB_BASE_ADDRESS + DIOx_BSRR_OFFSET))
#define DIOB_LCKR_REG					(*(volatile u32*) (DIOB_BASE_ADDRESS + DIOx_LCKR_OFFSET))
#define DIOB_AFRL_REG					(*(volatile u32*) (DIOB_BASE_ADDRESS + DIOx_AFRL_OFFSET))
#define DIOB_AFRH_REG					(*(volatile u32*) (DIOB_BASE_ADDRESS + DIOx_AFRH_OFFSET))
#define DIOB_BRR_REG					(*(volatile u32*) (DIOB_BASE_ADDRESS + DIOx_BRR_OFFSET))

#define DIOC_MODER_REG					(*(volatile u32*) (DIOC_BASE_ADDRESS + DIOx_MODER_OFFSET))
#define DIOC_OTYPER_REG					(*(volatile u32*) (DIOC_BASE_ADDRESS + DIOx_OTYPER_OFFSET))
#define DIOC_OSPEEDR_REG				(*(volatile u32*) (DIOC_BASE_ADDRESS + DIOx_OSPEEDR_OFFSET))
#define DIOC_PUPDR_REG					(*(volatile u32*) (DIOC_BASE_ADDRESS + DIOx_PUPDR_OFFSET))
#define DIOC_IDR_REG					(*(volatile u32*) (DIOC_BASE_ADDRESS + DIOx_IDR_OFFSET))
#define DIOC_ODR_REG					(*(volatile u32*) (DIOC_BASE_ADDRESS + DIOx_ODR_OFFSET))
#define DIOC_BSRR_REG					(*(volatile u32*) (DIOC_BASE_ADDRESS + DIOx_BSRR_OFFSET))
#define DIOC_LCKR_REG					(*(volatile u32*) (DIOC_BASE_ADDRESS + DIOx_LCKR_OFFSET))
#define DIOC_AFRL_REG					(*(volatile u32*) (DIOC_BASE_ADDRESS + DIOx_AFRL_OFFSET))
#define DIOC_AFRH_REG					(*(volatile u32*) (DIOC_BASE_ADDRESS + DIOx_AFRH_OFFSET))
#define DIOC_BRR_REG					(*(volatile u32*) (DIOC_BASE_ADDRESS + DIOx_BRR_OFFSET))

#define DIOD_MODER_REG					(*(volatile u32*) (DIOD_BASE_ADDRESS + DIOx_MODER_OFFSET))
#define DIOD_OTYPER_REG					(*(volatile u32*) (DIOD_BASE_ADDRESS + DIOx_OTYPER_OFFSET))
#define DIOD_OSPEEDR_REG				(*(volatile u32*) (DIOD_BASE_ADDRESS + DIOx_OSPEEDR_OFFSET))
#define DIOD_PUPDR_REG					(*(volatile u32*) (DIOD_BASE_ADDRESS + DIOx_PUPDR_OFFSET))
#define DIOD_IDR_REG					(*(volatile u32*) (DIOD_BASE_ADDRESS + DIOx_IDR_OFFSET))
#define DIOD_ODR_REG					(*(volatile u32*) (DIOD_BASE_ADDRESS + DIOx_ODR_OFFSET))
#define DIOD_BSRR_REG					(*(volatile u32*) (DIOD_BASE_ADDRESS + DIOx_BSRR_OFFSET))
#define DIOD_LCKR_REG					(*(volatile u32*) (DIOD_BASE_ADDRESS + DIOx_LCKR_OFFSET))
#define DIOD_AFRL_REG					(*(volatile u32*) (DIOD_BASE_ADDRESS + DIOx_AFRL_OFFSET))
#define DIOD_AFRH_REG					(*(volatile u32*) (DIOD_BASE_ADDRESS + DIOx_AFRH_OFFSET))
#define DIOD_BRR_REG					(*(volatile u32*) (DIOD_BASE_ADDRESS + DIOx_BRR_OFFSET))

#define DIOE_MODER_REG					(*(volatile u32*) (DIOE_BASE_ADDRESS + DIOx_MODER_OFFSET))
#define DIOE_OTYPER_REG					(*(volatile u32*) (DIOE_BASE_ADDRESS + DIOx_OTYPER_OFFSET))
#define DIOE_OSPEEDR_REG				(*(volatile u32*) (DIOE_BASE_ADDRESS + DIOx_OSPEEDR_OFFSET))
#define DIOE_PUPDR_REG					(*(volatile u32*) (DIOE_BASE_ADDRESS + DIOx_PUPDR_OFFSET))
#define DIOE_IDR_REG					(*(volatile u32*) (DIOE_BASE_ADDRESS + DIOx_IDR_OFFSET))
#define DIOE_ODR_REG					(*(volatile u32*) (DIOE_BASE_ADDRESS + DIOx_ODR_OFFSET))
#define DIOE_BSRR_REG					(*(volatile u32*) (DIOE_BASE_ADDRESS + DIOx_BSRR_OFFSET))
#define DIOE_LCKR_REG					(*(volatile u32*) (DIOE_BASE_ADDRESS + DIOx_LCKR_OFFSET))
#define DIOE_AFRL_REG					(*(volatile u32*) (DIOE_BASE_ADDRESS + DIOx_AFRL_OFFSET))
#define DIOE_AFRH_REG					(*(volatile u32*) (DIOE_BASE_ADDRESS + DIOx_AFRH_OFFSET))
#define DIOE_BRR_REG					(*(volatile u32*) (DIOE_BASE_ADDRESS + DIOx_BRR_OFFSET))

#define DIOF_MODER_REG					(*(volatile u32*) (DIOF_BASE_ADDRESS + DIOx_MODER_OFFSET))
#define DIOF_OTYPER_REG					(*(volatile u32*) (DIOF_BASE_ADDRESS + DIOx_OTYPER_OFFSET))
#define DIOF_OSPEEDR_REG				(*(volatile u32*) (DIOF_BASE_ADDRESS + DIOx_OSPEEDR_OFFSET))
#define DIOF_PUPDR_REG					(*(volatile u32*) (DIOF_BASE_ADDRESS + DIOx_PUPDR_OFFSET))
#define DIOF_IDR_REG					(*(volatile u32*) (DIOF_BASE_ADDRESS + DIOx_IDR_OFFSET))
#define DIOF_ODR_REG					(*(volatile u32*) (DIOF_BASE_ADDRESS + DIOx_ODR_OFFSET))
#define DIOF_BSRR_REG					(*(volatile u32*) (DIOF_BASE_ADDRESS + DIOx_BSRR_OFFSET))
#define DIOF_LCKR_REG					(*(volatile u32*) (DIOF_BASE_ADDRESS + DIOx_LCKR_OFFSET))
#define DIOF_AFRL_REG					(*(volatile u32*) (DIOF_BASE_ADDRESS + DIOx_AFRL_OFFSET))
#define DIOF_AFRH_REG					(*(volatile u32*) (DIOF_BASE_ADDRESS + DIOx_AFRH_OFFSET))
#define DIOF_BRR_REG					(*(volatile u32*) (DIOF_BASE_ADDRESS + DIOx_BRR_OFFSET))

#define DIOG_MODER_REG					(*(volatile u32*) (DIOG_BASE_ADDRESS + DIOx_MODER_OFFSET))
#define DIOG_OTYPER_REG					(*(volatile u32*) (DIOG_BASE_ADDRESS + DIOx_OTYPER_OFFSET))
#define DIOG_OSPEEDR_REG				(*(volatile u32*) (DIOG_BASE_ADDRESS + DIOx_OSPEEDR_OFFSET))
#define DIOG_PUPDR_REG					(*(volatile u32*) (DIOG_BASE_ADDRESS + DIOx_PUPDR_OFFSET))
#define DIOG_IDR_REG					(*(volatile u32*) (DIOG_BASE_ADDRESS + DIOx_IDR_OFFSET))
#define DIOG_ODR_REG					(*(volatile u32*) (DIOG_BASE_ADDRESS + DIOx_ODR_OFFSET))
#define DIOG_BSRR_REG					(*(volatile u32*) (DIOG_BASE_ADDRESS + DIOx_BSRR_OFFSET))
#define DIOG_LCKR_REG					(*(volatile u32*) (DIOG_BASE_ADDRESS + DIOx_LCKR_OFFSET))
#define DIOG_AFRL_REG					(*(volatile u32*) (DIOG_BASE_ADDRESS + DIOx_AFRL_OFFSET))
#define DIOG_AFRH_REG					(*(volatile u32*) (DIOG_BASE_ADDRESS + DIOx_AFRH_OFFSET))
#define DIOG_BRR_REG					(*(volatile u32*) (DIOG_BASE_ADDRESS + DIOx_BRR_OFFSET))

#define DIOH_MODER_REG					(*(volatile u32*) (DIOH_BASE_ADDRESS + DIOx_MODER_OFFSET))
#define DIOH_OTYPER_REG					(*(volatile u32*) (DIOH_BASE_ADDRESS + DIOx_OTYPER_OFFSET))
#define DIOH_OSPEEDR_REG				(*(volatile u32*) (DIOH_BASE_ADDRESS + DIOx_OSPEEDR_OFFSET))
#define DIOH_PUPDR_REG					(*(volatile u32*) (DIOH_BASE_ADDRESS + DIOx_PUPDR_OFFSET))
#define DIOH_IDR_REG					(*(volatile u32*) (DIOH_BASE_ADDRESS + DIOx_IDR_OFFSET))
#define DIOH_ODR_REG					(*(volatile u32*) (DIOH_BASE_ADDRESS + DIOx_ODR_OFFSET))
#define DIOH_BSRR_REG					(*(volatile u32*) (DIOH_BASE_ADDRESS + DIOx_BSRR_OFFSET))
#define DIOH_LCKR_REG					(*(volatile u32*) (DIOH_BASE_ADDRESS + DIOx_LCKR_OFFSET))
#define DIOH_AFRL_REG					(*(volatile u32*) (DIOH_BASE_ADDRESS + DIOx_AFRL_OFFSET))
#define DIOH_AFRH_REG					(*(volatile u32*) (DIOH_BASE_ADDRESS + DIOx_AFRH_OFFSET))
#define DIOH_BRR_REG					(*(volatile u32*) (DIOH_BASE_ADDRESS + DIOx_BRR_OFFSET))

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


#endif /* DIO_REG_H_ */
