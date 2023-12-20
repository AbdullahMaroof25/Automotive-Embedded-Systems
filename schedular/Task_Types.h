

#ifndef TASK_TYPES_H_
#define TASK_TYPES_H_

#include "std_types.h"

typedef enum
{
	Dorminat,
	Ready,
	Running,
	Blocking

}Task_State;


typedef struct
{
	void (* f_ptr)(void);
	Task_State state;
	u16 periodicity;
	u8 periority;
	u16 offset;


}Task_t;




#endif /* TASK_TYPES_H_ */
