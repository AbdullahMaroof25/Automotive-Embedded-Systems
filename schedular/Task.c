#include "Task.h"


Task_t Task_arr[Num_Tasks];


Task_t * Create_Task( Task_t task )
{
	Task_t * ptr = NULLPTR;

	static u8 index = 0;

	if( ( task.f_ptr != NULLPTR ) &&
		( index < Num_Tasks     )    )
	{
		Task_arr[index] = task;

		ptr = &Task_arr[index];

		index++;
	}
	return ptr;
}

void Change_Task_State( Task_t * task  , Task_State state )
{
	if( task != NULLPTR)
	{
		task->state = state;
	}
}

static void Sort(void)
{
	Task_t temp;
	for(u8 i = 0 ; i < Num_Tasks - 1 ;i++)
	{
		for(u8 j = ( i + 1 ) ; j < Num_Tasks ; j++)
		{
			if( Task_arr[j].periority < Task_arr[i].periority  )
			{
				temp = Task_arr[i];
				Task_arr[i] = Task_arr[j];
				Task_arr[j] = temp;

			}
		}

	}

}

static volatile u32 counter = 0;

 void Os_Init(void)
{
	counter++;

	for( u8 i = 0 ; i < Num_Tasks ; i++ )
	{
		if(  ((  ( counter %  Task_arr[i].periodicity ) - Task_arr[i].offset  )  == 0   )   &&
			  ( Task_arr[i].state == Ready	))
			 {
					Task_arr[i].state == Running;
					Task_arr[i].f_ptr();
					Task_arr[i].state == Ready;

			 }
	}

}


void Os_Start(void)
{
	Sort();
	sysTick_init(AHB_8, Os_Init);
	sysTick_start(1000);

}

