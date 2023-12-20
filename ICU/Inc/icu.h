
#ifndef  _ICU_H_
#define  _ICU_H_

#include "bit_math.h"
#include "std_types.h"
#include "icu_reg.h"
#include "icu_types.h"


#define Enable   0
#define Disable  1


void ICU_Init(void);
void ICU_Control(ICU_Channel channel ,  u8 control);				          // done
void ICU_Read(ICU_Channel channel,u16 * read_ptr );         // done
void ICU_SelectEdge(ICU_Channel channel,ICU_Edge edge);     // done
void ICU_INT_Enable(ICU_Channel channel,void(*ptr)(void));  // done
void ICU_INT_Disable(ICU_Channel channel);                  // done
STD_ReturnState ICU_INT_CheckStatus(ICU_Channel channel);   // done
















#endif   //_ICU_H_
