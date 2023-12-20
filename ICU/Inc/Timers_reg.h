
#ifndef MCAL_ICU_INC_TIMERS_REG_H_
#define MCAL_ICU_INC_TIMERS_REG_H_



#define CR1_REG_OFFSET  		  (0x00U)	//16b

#define CR2_REG_OFFSET  		  (0x04U)	//16b
#define DIER_REG_OFFSET           (0x0CU)   //16b
#define SR_REG_OFFSET  			  (0x10U)   //32b
#define CCMR1_REG_OFFSET          (0x18U)   //32b
#define CCMR2_REG_OFFSET          (0x1CU)   //32b
#define CCER_REG_OFFSET           (0x20U)   //32b
#define PSC_REG_OFFSET            (0x28U)   //16b
#define CCR1_REG_OFFSET           (0x34U)	//16b
#define CCR2_REG_OFFSET           (0x38U)	//16b
#define CCR3_REG_OFFSET           (0x3Cu)	//16b
#define CCR4_REG_OFFSET           (0x40u)	//16b
#define EGR_REG_OFFSET			  (0x14U)
#define ARR_REG_OFFSET  		  (0x2CU)
#define CNT_REG_OFFSET            (0x24U)   //16b




#define CEN_BIT_0		(0u)			//Bit 0 CEN: Counter enable
#define ARPE_BIT_7		(7u)
#define OPM_BIT_3				  (3u)

#define UIF_BIT_0				  (0u)


#define  CC4DE_BIT_12	(12u)
#define  CC3DE_BIT_11	(11u)
#define  CC2DE_BIT_10	(10u)
#define  CC1DE_BIT_9	(9u)

#define  CC4IE_BIT_4	(4u)	//Bit 4 CC4IE: Capture/Compare 4 interrupt enable
#define  CC3IE_BIT_3	(3u)	//Bit 3 CC3IE: Capture/Compare 3 interrupt enable
#define  CC2IE_BIT_2	(2u)	//Bit 2 CC2IE: Capture/Compare 2 interrupt enable
#define  CC1IE_BIT_1	(1u)	//Bit 1 CC1IE: Capture/Compare 1 interrupt enable


#define  CC4IF_BIT_4	(4u)	//Bit 4 CC4IE: Capture/Compare 4 interrupt flag
#define  CC3IF_BIT_3	(3u)	//Bit 3 CC3IE: Capture/Compare 3 interrupt flag
#define  CC2IF_BIT_2	(2u)	//Bit 2 CC2IE: Capture/Compare 2 interrupt flag
#define  CC1IF_BIT_1	(1u)	//Bit 1 CC1IE: Capture/Compare 1 interrupt flag

#define CC2S_BIT_8_9      (8u)		//Bits 9:8 CC2S: Capture/Compare 2 selection
#define CC1S_BIT_0_1      (0u)		//Bits 1:0 CC1S: Capture/Compare 1 selection

#define CC4S_BIT_8_9      (8u)		//Bits 9:8 CC4S: Capture/Compare 4 selection
#define CC3S_BIT_0_1      (0u)		//Bits 1:0 CC3S: Capture/Compare 3 selection

#define CC1E_BIT_0   (0u)     //Bit 0 CC1E: Capture/Compare 1 output enable
#define CC1P_BIT_1	 (1u)	  //Bit 1 CC1P: Capture/Compare 1 output polarity
#define CC1NP_BIT_3  (3u)	  //Bit 3 CC1NP: Capture/Compare 1 complementary output polarity

#define CC2E_BIT_4   (4u)     //Bit 4 CC1E: Capture/Compare 2 output enable
#define CC2P_BIT_5	 (5u)	  //Bit 5 CC1P: Capture/Compare 2 output polarity
#define CC2NP_BIT_7  (7u)	  //Bit 7 CC1NP: Capture/Compare 2 complementary output polarity

#define CC3E_BIT_8   (8u)     //Bit 8 CC1E: Capture/Compare 3 output enable
#define CC3P_BIT_9	 (9u)	  //Bit 9 CC1P: Capture/Compare 3 output polarity
#define CC3NP_BIT_11  (11u)	  //Bit 11 CC1NP: Capture/Compare 3 complementary output polarity

#define CC4E_BIT_12   (12u)     //Bit 12 CC1E: Capture/Compare 4 output enable
#define CC4P_BIT_13	 (13u)	  //Bit 13 CC1P: Capture/Compare 4 output polarity
#define CC4NP_BIT_15  (15u)	  //Bit 15 CC1NP: Capture/Compare 4 complementary output polarity



#define OC1M_BIT_4_5_6	    	(4u)
#define OC2M_BIT_12_13_14		(12u)

#define OC1PE_BIT_3			(3u)
#define OC2PE_BIT_11		(11u)

#endif /* MCAL_ICU_INC_TIMERS_REG_H_ */
