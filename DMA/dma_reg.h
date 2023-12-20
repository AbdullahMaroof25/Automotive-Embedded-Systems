

#ifndef DMA_REG_H_
#define DMA_REG_H_

#include "std_types.h"



#define DMA_1_			0
#define DMA_2_			1

#define CH_1_			0
#define CH_2_			1
#define CH_3_			2
#define CH_4_			3
#define CH_5_			4
#define CH_6_			5
#define CH_7_			6


typedef struct
{
	volatile u32 CCR;
	volatile u32 CNDTR;
	volatile u32 CPAR;
	volatile u32 CMAR;
	volatile u32 Reserved;
}DMA_Channel;

typedef struct
{
	volatile u32 ISR;
	volatile u32 IFCR;
	DMA_Channel Channel[7];
}DMA_t;






#define MEM2MEM_BIT_14			(14u)
#define PL_BIT_12_13			(12u)
#define MSIZE_BIT_10_11			(10u)
#define PSIZE_BIT_8_9			(8u)
#define MINC_BIT_7   			(7u)
#define PINC_BIT_6   			(6u)
#define CIRC_BIT_5   			(5u)
#define DIR_BIT_4   			(4u)
#define TEIE_BIT_3              (3u)
#define HTIE_BIT_2              (2u)
#define TCIE_BIT_1              (1u)
#define EN_BIT_0   			    (0u)










#define DMA_1       	((volatile DMA_t*)0x40020000)
#define DMA_2       	((volatile DMA_t*)0x40020400)


#endif /* DMA_REG_H_ */
