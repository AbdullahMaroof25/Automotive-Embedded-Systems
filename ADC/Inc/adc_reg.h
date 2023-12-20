/******************************************************************************
 * Module: ADC
 *
 * File Name: adc_reg.h
 *
 * Description: Header File for the ADC Driver Contains the The Registers  used in the driver
 *
 * Author: Abdullah Maroof
 *  
 *******************************************************************************/

#ifndef ADC_REG_H_
#define ADC_REG_H_

/*******************************************************************************
 *                      Includes                                               *
 *******************************************************************************/


/*******************************************************************************
 *                      Global Constant Macros                                 *
 *******************************************************************************/


/*   ADC1   Register Defenation */

#define ADC1_BASE_ADDR                (0x50000000ul)      // Base Address for ADC1 in memory map 
#define ADC1_BASE_OFFSET              (0x00u)             // the offset of the ADC1 i memory map when using single mode for master and slave adc check page 411 in dataShet for more info

#define ADC1_ISR_REG_OFFSET           (0x00u)
#define ADC1_IER_REG_OFFSET           (0x04u)
#define ADC1_CR_REG_OFFSET            (0x08u)
#define ADC1_CFGR_REG_OFFSET          (0x0Cu)
#define ADC1_SMPR1_REG_OFFSET         (0x14u)
#define ADC1_SMPR2_REG_OFFSET         (0x18u)
#define ADC1_SQR1_REG_OFFSET          (0x30u)
#define ADC1_SQR2_REG_OFFSET          (0x34u)
#define ADC1_SQR3_REG_OFFSET          (0x38u)
#define ADC1_DR_REG_OFFSET            (0x40u)

/*                        ADC common registers                     */ 

#define Common_REG_STEP_ADDR          (0x300ul)
#define ADC1_CSR_REG_OFFSET           (0x00u)
#define ADC1_CCR_REG_OFFSET           (0x08u)


/*     Regsiters Definitions     */

            /* ADC interrupt and status register */
#define ADC1_ISR_REG 			(*(volatile u32*) (ADC1_BASE_ADDR + ADC1_ISR_REG_OFFSET + ADC1_BASE_OFFSET))

#define EOC_BIT_2           (2u)        // End of conversion flag
#define ADRDY_BIT_0         (0u)       // ADC ready




            /* ADC interrupt enable register */
#define ADC1_IER_REG 			(*(volatile u32*) (ADC1_BASE_ADDR + ADC1_IER_REG_OFFSET + ADC1_BASE_OFFSET ))

#define EOCIE_BIT_2               (2u)   //End of regular conversion interrupt enable
#define ADRDYIE_BIT_0             (0u)   //ADC ready interrupt enable

            /* ADC control register */
#define ADC1_CR_REG 			(*(volatile u32*) (ADC1_BASE_ADDR + ADC1_CR_REG_OFFSET + ADC1_BASE_OFFSET ))

#define ADSTART_BIT_2     (2u) //ADC start of regular conversion
#define ADEN_BIT_0        (0u) //ADC enable control

            /* ADC configuration register */
#define ADC1_CFGR_REG 			(*(volatile u32*) (ADC1_BASE_ADDR + ADC1_CFGR_REG_OFFSET + ADC1_BASE_OFFSET ))

#define DISCEN_BIT_16      (16u)      //  Discontinuous mode for regular channels
#define CONT_BIT_13        (13u)      //Single / continuous conversion mode for regular conversions
#define OVRMOD_BIT12       (12u)      //Overrun Mode This bit is set and cleared by software and configure the way data overrun is managed
#define EXTEN_BIT_10_11    (10u)      //bits 10 & 11 are for External trigger enable and polarity selection for regular channels
#define ALIGN_BIT_5        (5u)      //Data alignment
#define RES_BIT_3_4        (3u)      // Data resolution

            /* ADC sample time register */
#define ADC1_SMPR1_REG			(*(volatile u32*) (ADC1_BASE_ADDR + ADC1_SMPR1_REG_OFFSET + ADC1_BASE_OFFSET ))
#define ADC1_SMPR2_REG			(*(volatile u32*) (ADC1_BASE_ADDR + ADC1_SMPR2_REG_OFFSET + ADC1_BASE_OFFSET ))

// 3 bits for evech Channel for sampling time selection
#define SMP1_BIT_3_4_5          (3u)              // Channel  1
#define SMP2_BIT_6_7_8          (6u)               // Channel 2
#define SMP3_BIT_9_10_11        (9u)               // Channel 3
#define SMP4_BIT_12_13_14       (12u)              // Channel 4 
#define SMP5_BIT_15_16_17       (15u)              // Channel 5
#define SMP6_BIT_18_19_20       (18u)              // Channel 6
#define SMP7_BIT_21_22_23       (21u)              // Channel 7
#define SMP8_BIT_24_25_26       (24u)              // Channel 8
#define SMP9_BIT_27_28_29       (27u)              // Channel 9
                        /* ADC1_SMPR2_REG */
#define SMP10_BIT_0_1_2            (0u)                // Channel 10
#define SMP11_BIT_3_4_5            (3u)               // Channel  12
#define SMP11_BIT_6_7_8            (6u)               // Channel  13
#define SMP11_BIT_9_10_11          (9u)               // Channel  14
#define SMP11_BIT_12_13_14         (12u)              // Channel  15
#define SMP11_BIT_15_16_17         (15u)              // Channel  16
#define SMP11_BIT_18_19_30         (18u)              // Channel  17
#define SMP11_BIT_21_22_23         (21u)              // Channel  18





            /* ADC regular sequence register */
#define ADC1_SQR1_REG 	   		(*(volatile u32*) (ADC1_BASE_ADDR + ADC1_SQR1_REG_OFFSET + ADC1_BASE_OFFSET ))
#define L_BIT_0_1_2_3         (0u) // Regular channel sequence length

            /* ADC regular Data Register */
#define ADC1_DR_REG 			(*(volatile u32*) (ADC1_BASE_ADDR + ADC1_DR_REG_OFFSET + ADC1_BASE_OFFSET ))


/* Check this again  */
/*                        ADC common registers                     */ 

            /* ADC Common status register */
#define ADC1_CSR_REG 			(*(volatile u32*) (ADC1_BASE_ADDR + ADC1_CSR_REG_OFFSET + ADC1_BASE_OFFSET  + Common_REG_STEP_ADDR ))
            /* ADC common control register */
#define ADC1_CCR_REG 			(*(volatile u32*) (ADC1_BASE_ADDR + ADC1_CCR_REG_OFFSET + ADC1_BASE_OFFSET  + Common_REG_STEP_ADDR ))

/******************************************************************************************************************************************/

/*                                             ADC2   Register Defenation                 */

#define ADC2_BASE_OFFSET              (0x100ul)             // the offset of the ADC2 i memory map when using single mode for master and slave adc check page 411 in dataShet for more info

#define ADC2_ISR_REG_OFFSET           (0x00u)
#define ADC2_IER_REG_OFFSET           (0x04u)
#define ADC2_CR_REG_OFFSET            (0x08u)
#define ADC2_CFGR_REG_OFFSET          (0x0Cu)
#define ADC2_SMPR1_REG_OFFSET         (0x14u)
#define ADC2_SMPR2_REG_OFFSET         (0x18u)
#define ADC2_SQR1_REG_OFFSET          (0x30u)
#define ADC2_SQR2_REG_OFFSET          (0x34u)
#define ADC2_SQR3_REG_OFFSET          (0x38u)
#define ADC2_DR_REG_OFFSET            (0x40u)

/*                        ADC common registers                     */ 

#define Common_REG_STEP_ADDR          (0x300ul)
#define ADC2_CSR_REG_OFFSET           (0x00u)
#define ADC2_CCR_REG_OFFSET           (0x08u)


/*     Regsiters Definitions     */

            /* ADC interrupt and status register */
#define ADC2_ISR_REG 			(*(volatile u32*) (ADC1_BASE_ADDR + ADC1_ISR_REG_OFFSET + ADC2_BASE_OFFSET))






            /* ADC interrupt enable register */
#define ADC2_IER_REG 			(*(volatile u32*) (ADC1_BASE_ADDR + ADC1_IER_REG_OFFSET + ADC2_BASE_OFFSET ))



            /* ADC control register */
#define ADC2_CR_REG 			(*(volatile u32*) (ADC1_BASE_ADDR + ADC1_CR_REG_OFFSET + ADC2_BASE_OFFSET ))



            /* ADC configuration register */
#define ADC2_CFGR_REG 			(*(volatile u32*) (ADC1_BASE_ADDR + ADC1_CFGR_REG_OFFSET + ADC2_BASE_OFFSET ))


            /* ADC sample time register */
#define ADC2_SMPR1_REG			(*(volatile u32*) (ADC1_BASE_ADDR + ADC1_SMPR1_REG_OFFSET + ADC2_BASE_OFFSET ))
#define ADC2_SMPR2_REG			(*(volatile u32*) (ADC1_BASE_ADDR + ADC1_SMPR2_REG_OFFSET + ADC2_BASE_OFFSET ))





            /* ADC regular sequence register */
#define ADC2_SQR1_REG 	   		(*(volatile u32*) (ADC1_BASE_ADDR + ADC1_SQR1_REG_OFFSET + ADC2_BASE_OFFSET ))
//#define L_BIT_0_1_2_3         (0u) // Regular channel sequence length

            /* ADC regular Data Register */
#define ADC2_DR_REG 			(*(volatile u32*) (ADC1_BASE_ADDR + ADC1_DR_REG_OFFSET + ADC2_BASE_OFFSET ))


/* Check this again  */
/*                        ADC common registers                     */ 

            /* ADC Common status register */
#define ADC1_CSR_REG 			(*(volatile u32*) (ADC1_BASE_ADDR + ADC1_CSR_REG_OFFSET + ADC1_BASE_OFFSET  + Common_REG_STEP_ADDR ))
            /* ADC common control register */
#define ADC1_CCR_REG 			(*(volatile u32*) (ADC1_BASE_ADDR + ADC1_CCR_REG_OFFSET + ADC1_BASE_OFFSET  + Common_REG_STEP_ADDR ))
#define CKMODE_BIT_16_17     16   // ADC clock mode
#define DUAL_BIT_0_1_2_3_4           0 // Dual ADC mode selection


/*   ADC3 Register Definition   */

#define ADC3_BASE_ADDR                (0x50000400ul)      // Base Address for ADC3 in memory map
#define ADC3_BASE_OFFSET              (0x00u)             // Offset of ADC3 in memory map for single mode master and slave ADC, page 411 in datasheet for more info

#define ADC3_ISR_REG_OFFSET           (0x00u)
#define ADC3_IER_REG_OFFSET           (0x04u)
#define ADC3_CR_REG_OFFSET            (0x08u)
#define ADC3_CFGR_REG_OFFSET          (0x0Cu)
#define ADC3_SMPR1_REG_OFFSET         (0x14u)
#define ADC3_SMPR2_REG_OFFSET         (0x18u)
#define ADC3_SQR1_REG_OFFSET          (0x30u)
#define ADC3_SQR2_REG_OFFSET          (0x34u)
#define ADC3_SQR3_REG_OFFSET          (0x38u)
#define ADC3_DR_REG_OFFSET            (0x40u)

/* ADC common registers for ADC3 */
#define Common_REG_STEP_ADDR          (0x300ul)

/* ADC3 common registers */
#define ADC3_CSR_REG_OFFSET           (Common_REG_STEP_ADDR + 0x00u)
#define ADC3_CCR_REG_OFFSET           (Common_REG_STEP_ADDR + 0x08u)

/* Register Definitions for ADC3 */
#define ADC3_ISR_REG            (*(volatile u32*)(ADC3_BASE_ADDR + ADC3_ISR_REG_OFFSET + ADC3_BASE_OFFSET))

//#define EOC_BIT_2              (2u)        // End of conversion flag
//#define ADRDY_BIT_0            (0u)        // ADC ready

/* ADC3 interrupt enable register */
#define ADC3_IER_REG            (*(volatile u32*)(ADC3_BASE_ADDR + ADC3_IER_REG_OFFSET + ADC3_BASE_OFFSET))

//#define EOCIE_BIT_2             (2u)    // End of regular conversion interrupt enable
//#define ADRDYIE_BIT_0           (0u)    // ADC ready interrupt enable

/* ADC3 control register */
#define ADC3_CR_REG             (*(volatile u32*)(ADC3_BASE_ADDR + ADC3_CR_REG_OFFSET + ADC3_BASE_OFFSET))

//#define ADSTART_BIT_2           (2u)    // ADC start of regular conversion
//#define ADEN_BIT_0              (0u)    // ADC enable control

/* ADC3 configuration register */
#define ADC3_CFGR_REG           (*(volatile u32*)(ADC3_BASE_ADDR + ADC3_CFGR_REG_OFFSET + ADC3_BASE_OFFSET))



/* ADC3 sample time registers */
#define ADC3_SMPR1_REG          (*(volatile u32*)(ADC3_BASE_ADDR + ADC3_SMPR1_REG_OFFSET + ADC3_BASE_OFFSET))
#define ADC3_SMPR2_REG          (*(volatile u32*)(ADC3_BASE_ADDR + ADC3_SMPR2_REG_OFFSET + ADC3_BASE_OFFSET))



/* ADC3 regular sequence register */
#define ADC3_SQR1_REG           (*(volatile u32*)(ADC3_BASE_ADDR + ADC3_SQR1_REG_OFFSET + ADC3_BASE_OFFSET))
//#define L_BIT_0_1_2_3           (0u) // Regular channel sequence length

/* ADC3 regular Data Register */
#define ADC3_DR_REG             (*(volatile u32*)(ADC3_BASE_ADDR + ADC3_DR_REG_OFFSET + ADC3_BASE_OFFSET))

/* ADC3 Common status register */
#define ADC3_CSR_REG            (*(volatile u32*)(ADC3_BASE_ADDR + ADC3_CSR_REG_OFFSET + ADC3_BASE_OFFSET + Common_REG_STEP_ADDR))

/* ADC3 Common control register */
#define ADC3_CCR_REG            (*(volatile u32*)(ADC3_BASE_ADDR + ADC3_CCR_REG_OFFSET + ADC3_BASE_OFFSET + Common_REG_STEP_ADDR))

/******************************************************************************************************************************************/

/*                           ADC4   Register Definition                           */
#define ADC4_BASE_ADDR                (0x50000500ul)
#define ADC4_BASE_OFFSET              (0x100ul)             // the offset of the ADC4 in memory map when using single mode for master and slave adc check page 411 in dataShet for more info

#define ADC4_ISR_REG_OFFSET           (0x00u)
#define ADC4_IER_REG_OFFSET           (0x04u)
#define ADC4_CR_REG_OFFSET            (0x08u)
#define ADC4_CFGR_REG_OFFSET          (0x0Cu)
#define ADC4_SMPR1_REG_OFFSET         (0x14u)
#define ADC4_SMPR2_REG_OFFSET         (0x18u)
#define ADC4_SQR1_REG_OFFSET          (0x30u)
#define ADC4_SQR2_REG_OFFSET          (0x34u)
#define ADC4_SQR3_REG_OFFSET          (0x38u)
#define ADC4_DR_REG_OFFSET            (0x40u)

/*                             ADC4 common registers                                */

#define Common_REG_STEP_ADDR          (0x300ul)
#define ADC4_CSR_REG_OFFSET           (0x00u)
#define ADC4_CCR_REG_OFFSET           (0x08u)

/*                             Registers Definitions                                 */

/*                             ADC interrupt and status register                                 */
#define ADC4_ISR_REG 			(*(volatile u32*) (ADC3_BASE_ADDR + ADC3_ISR_REG_OFFSET + ADC4_BASE_OFFSET))

/* ADC interrupt enable register */
#define ADC4_IER_REG 			(*(volatile u32*) (ADC3_BASE_ADDR + ADC3_IER_REG_OFFSET + ADC4_BASE_OFFSET ))

/*                             ADC control register                                  */
#define ADC4_CR_REG 			(*(volatile u32*) (ADC3_BASE_ADDR + ADC3_CR_REG_OFFSET + ADC4_BASE_OFFSET ))
/*                             ADC3 Common control register                          */
#define ADC4_CCR_REG            (*(volatile u32*)(ADC4_BASE_ADDR + ADC4_CCR_REG_OFFSET + ADC4_BASE_OFFSET + Common_REG_STEP_ADDR))
/*                             ADC configuration register                            */
#define ADC4_CFGR_REG 			(*(volatile u32*) (ADC3_BASE_ADDR + ADC3_CFGR_REG_OFFSET + ADC4_BASE_OFFSET ))
/*                             ADC sample time register                              */
#define ADC4_SMPR1_REG			(*(volatile u32*) (ADC3_BASE_ADDR + ADC3_SMPR1_REG_OFFSET + ADC4_BASE_OFFSET ))
#define ADC4_SMPR2_REG			(*(volatile u32*) (ADC3_BASE_ADDR + ADC3_SMPR2_REG_OFFSET + ADC4_BASE_OFFSET ))

/*                             ADC regular sequence register                         */
#define ADC4_SQR1_REG 	   		(*(volatile u32*) (ADC3_BASE_ADDR + ADC3_SQR1_REG_OFFSET + ADC4_BASE_OFFSET ))

/*                             ADC regular Data Register                             */
#define ADC4_DR_REG 			(*(volatile u32*) (ADC3_BASE_ADDR + ADC3_DR_REG_OFFSET + ADC4_BASE_OFFSET ))




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

 
#endif

/*******************************************************************************
 *                      End of File: .h                                        *
 *******************************************************************************/
