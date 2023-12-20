#include "dma.h"


void DMA_Start( Channel_Config * ch_cfg )
{
	u8 channel = ch_cfg->Chanel;
	switch((ch_cfg->DMA))
	{
	case DMA_1_:

		DMA_1->Channel[channel].CCR = 0x0000;

		DMA_1->Channel[channel].CNDTR = ch_cfg->Block_Size;
		DMA_1->Channel[channel].CPAR  =  ch_cfg->Source_Address;
		DMA_1->Channel[channel].CMAR  =  ch_cfg->Dest_Address;


		DMA_1->Channel[channel].CCR |= WriteValue( ch_cfg->MEM2MEM , MEM2MEM_BIT_14 );
		DMA_1->Channel[channel].CCR |= WriteValue( ch_cfg->PL      , PL_BIT_12_13 );
		DMA_1->Channel[channel].CCR |= WriteValue( ch_cfg->MSIZE   , MSIZE_BIT_10_11 );
		DMA_1->Channel[channel].CCR |= WriteValue( ch_cfg->PSIZE   , PSIZE_BIT_8_9 );
		DMA_1->Channel[channel].CCR |= WriteValue( ch_cfg->MINC    , MINC_BIT_7 );
		DMA_1->Channel[channel].CCR |= WriteValue( ch_cfg->PINC    , PINC_BIT_6 );
		DMA_1->Channel[channel].CCR |= WriteValue( ch_cfg->CIRC    , CIRC_BIT_5 );
		DMA_1->Channel[channel].CCR |= WriteValue( ch_cfg->DIR     , DIR_BIT_4 );
		DMA_1->Channel[channel].CCR |= WriteValue( ch_cfg->TEIE     , TEIE_BIT_3 );
		DMA_1->Channel[channel].CCR |= WriteValue( ch_cfg->HTIE     , HTIE_BIT_2 );
		DMA_1->Channel[channel].CCR |= WriteValue( ch_cfg->TCIE     , TCIE_BIT_1 );

		DMA_1->Channel[channel].CCR |= WriteValue( ch_cfg->EN      , EN_BIT_0 );

		break;

	case DMA_2_:

		DMA_2->Channel[channel].CCR = 0x0000;
		DMA_2->Channel[channel].CCR |= WriteValue( ch_cfg->MEM2MEM , MEM2MEM_BIT_14 );
		DMA_2->Channel[channel].CCR |= WriteValue( ch_cfg->PL      , PL_BIT_12_13 );
		DMA_2->Channel[channel].CCR |= WriteValue( ch_cfg->MSIZE   , MSIZE_BIT_10_11 );
		DMA_2->Channel[channel].CCR |= WriteValue( ch_cfg->PSIZE   , PSIZE_BIT_8_9 );
		DMA_2->Channel[channel].CCR |= WriteValue( ch_cfg->MINC    , MINC_BIT_7 );
		DMA_2->Channel[channel].CCR |= WriteValue( ch_cfg->PINC    , PINC_BIT_6 );
		DMA_2->Channel[channel].CCR |= WriteValue( ch_cfg->CIRC    , CIRC_BIT_5 );
		DMA_2->Channel[channel].CCR |= WriteValue( ch_cfg->DIR     , DIR_BIT_4 );
		DMA_2->Channel[channel].CCR |= WriteValue( ch_cfg->TEIE     , TEIE_BIT_3 );
		DMA_2->Channel[channel].CCR |= WriteValue( ch_cfg->HTIE     , HTIE_BIT_2 );
		DMA_2->Channel[channel].CCR |= WriteValue( ch_cfg->TCIE     , TCIE_BIT_1 );

		DMA_2->Channel[channel].CNDTR = ch_cfg->Block_Size;
		DMA_2->Channel[channel].CPAR  = ch_cfg->Source_Address;
		DMA_2->Channel[channel].CMAR  = ch_cfg->Dest_Address;

		DMA_2->Channel[channel].CCR |= WriteValue( ch_cfg->EN      , EN_BIT_0 );

		break;



	}







}
