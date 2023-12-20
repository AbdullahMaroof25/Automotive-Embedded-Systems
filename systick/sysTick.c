
#include "sysTick.h"


static volatile void(*g_callBackPtr)(void) = (void*)RET_NULLPTR;
/*
void SysTick_Handler (void)
{
	if(g_callBackPtr != (void*)RET_NULLPTR)
	{
		(*g_callBackPtr)();
	}
}*/

void sysTick_init(systick_clock_t clock, void (*fPtr)(void))
{
	if(fPtr != (void*)RET_NULLPTR)
	{
		CLEAR_BIT(SYSTICK_STK_CTRL_REG, 1);
	}
	else
	{
		SET_BIT(SYSTICK_STK_CTRL_REG, 1);
		g_callBackPtr = fPtr;
	}

	SYSTICK_STK_CTRL_REG |= (clock<<2);
}

void sysTick_start(u32 loadVal)
{
	SYSTICK_STK_LOAD_REG = loadVal;

	SET_BIT(SYSTICK_STK_CTRL_REG, 0);

	while(CHECK_BIT(SYSTICK_STK_CTRL_REG,16) == 0 )
	{
		;
	}
}

void sysTick_stop()
{
	CLEAR_BIT(SYSTICK_STK_CTRL_REG, 0);
}
