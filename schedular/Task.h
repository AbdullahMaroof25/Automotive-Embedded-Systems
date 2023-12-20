
#ifndef TASK_H_
#define TASK_H_


#include "bit_math.h"
#include "std_types.h"

#include "Task_Types.h"

#include "sysTick.h"



#define Num_Tasks   10

Task_t * Create_Task( Task_t task );
void Change_Task_State( Task_t * task  , Task_State state );
void Os_Start(void);

#endif /* TASK_H_ */
