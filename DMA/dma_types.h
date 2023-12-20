
#ifndef DMA_TYPES_H_
#define DMA_TYPES_H_

#include "std_types.h"


typedef enum
{
	_8_bits,
	_16_bits,
	_32_bits

}Size_t;

typedef enum
{
	Low,
	Medium,
	High,
	Very_High

}Priority_Level_t;



typedef struct
{
	u8 DMA;									// DMA_1_ , DMA_2_
	u8 Chanel;								// CH_1_ , CH_2_ , ..... , CH_7_
	u16 Block_Size;
	u32  Source_Address;
	u32  Dest_Address;
	boolean MEM2MEM;					//Memory to memory mode
	Priority_Level_t PL;					//Channel priority level
	Size_t MSIZE;						    //Memory size
	Size_t PSIZE;				            //Peripheral size
	boolean MINC;						//Memory increment mode
	boolean PINC;						//Peripheral increment mode
	boolean CIRC;						//Circular mode
	boolean DIR;						//Data transfer direction ==>  0: Read from peripheral , 1: Read from memory
	boolean TEIE;						//Transfer error interrupt enable
	boolean HTIE;						//Half transfer interrupt enable
	boolean TCIE;						//Transfer complete interrupt enable
	boolean EN;							// Channel enable
}Channel_Config;




#endif /* DMA_TYPES_H_ */
