

#ifndef EXT_INT_H_
#define EXT_INT_H_


#include "bit_math.h"
#include "std_types.h"


#include "EXT_INT_reg.h"
#include "EXT_INT_types.h"



void EXT_voidEnableExtInt(t_EXT_INT cpy_ext_int , t_TRIGGERING_CONDITION cpy_condition);
void EXT_voidDisableExtInt(t_EXT_INT cpy_ext_int);
void EXT_voidInitGlobalInterrupts(void);
void SetCallBack_ExtInt(t_EXT_INT cpy_ext_int ,void(*func)(void));



#endif /* EXT_INT_H_ */