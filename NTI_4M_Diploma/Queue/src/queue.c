/*
 * queue.c
 *
 * Created: 10/29/2023 9:37:16 AM
 *  Author: 2022
 */ 


#include "queue.h"


 u8 Buffer_arr[BufferSize][Tx_Len];
static u8 Add_Index		= 0;
static u8 Get_Index		= 0;
static u8 buffer_size   = 0;


void Create_Buffer(void)
{
	u8 i, j;
	for (i = 0; i < BufferSize; i++) {
		for (j = 0; j < Tx_Len; j++) {
			Buffer_arr[i][j] = 0;
		}
	}	
}


Buffer_Status BufferStatus(void)
{
	
	if (buffer_size == 0) 
		{
			return Empty;
		}
	else if (buffer_size == BufferSize) 
		{
			return Full;
		} 
	else
		{
			return NotEmpty;
		}
}
		


void Add_To_Buffer(u8 *msg)
{
	 if (BufferStatus() != Full) {
		 u8 i;
		 for (i = 0; i < Tx_Len; i++) {
			 Buffer_arr[Add_Index][i] = msg[i];
		 }
		// Add_Index = (Add_Index + 1) % BufferSize;
		 Add_Index++;
		 buffer_size++;
		
	 }
	
}
boolean Get_From_Buffer(u8 *msg) 
{
	if (BufferStatus() != Empty)
	 {
		u8 i;
		for (i = 0; i < Tx_Len; i++) 
		{
			msg[i] = Buffer_arr[Get_Index][i];
		}
		//Get_Index = (Get_Index + 1) % BufferSize;
		Get_Index++;
		buffer_size--;
		return TRUE;
		} 
		else 
		{
		return FALSE;
	}
}

