

#include "keypad.h"
#define F_CPU 16000000UL
#include <util/delay.h>
#define  no_row		4
#define  no_col		4


static u8 row_channal_arr[no_row] = { KEYPAD_ROW1_CHANNEL,KEYPAD_ROW2_CHANNEL,
									  KEYPAD_ROW3_CHANNEL,KEYPAD_ROW4_CHANNEL};
				  
static u8 col_channal_arr[no_col] = { KEYPAD_COL1_CHANNEL,KEYPAD_COL2_CHANNEL,
									  KEYPAD_COL3_CHANNEL,KEYPAD_COL4_CHANNEL};				  


static u8 row_port_arr[no_row] = { KEYPAD_ROW1_PORT,KEYPAD_ROW2_PORT,
								   KEYPAD_ROW3_PORT,KEYPAD_ROW4_PORT};

static u8 col_port_arr[no_col] = { KEYPAD_COL1_PORT,KEYPAD_COL2_PORT,
								   KEYPAD_COL3_PORT,KEYPAD_COL4_PORT};
							
							



static u8 keys_array[no_row][no_col]={{'7','8','9','/'},
									  {'4','5','6','*'},
									  {'1','2','3','-'},
									  {'c','0','=','+'}};



void keypad_vidInit(void)
{
	u8 i =0;
	for( i = 0 ; i < no_row ; i++)
	{
		dio_vidConfigChannel(row_port_arr[i],row_channal_arr[i],OUTPUT);
	}
	for( i = 0 ; i < no_col ; i++)
	{
		dio_vidConfigChannel(col_port_arr[i],col_channal_arr[i],INPUT);
	}
	for( i = 0 ; i < no_row ; i++)
	{
		dio_vidWriteChannel(row_port_arr[i],row_channal_arr[i],STD_HIGH);
		
	}
	for( i = 0 ; i < no_col ; i++)
	{
		dio_vidWriteChannel(col_port_arr[i],col_channal_arr[i],STD_HIGH);
	}
}
u8 keypad_u8GetKey(void)
{
	u8 row,col,key = 0x55;
	for(row=0;row<no_row;row++)
	{
		dio_vidWriteChannel(row_port_arr[row],row_channal_arr[row],STD_LOW);
		for(col=0;col<no_col;col++)
		{
			if(dio_dioLevelReadChannel(col_port_arr[col],col_channal_arr[col]) == STD_LOW)
			{
				_delay_ms(30);
				key = keys_array[row][col];
				while(dio_dioLevelReadChannel(col_port_arr[col],col_channal_arr[col]) == STD_LOW);
			}
		}
		dio_vidWriteChannel(row_port_arr[row],row_channal_arr[row],STD_HIGH);
		
	}
	
	return key;
}