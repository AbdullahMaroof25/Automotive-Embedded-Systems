/*
 * queue.h
 *
 * Created: 10/29/2023 9:36:58 AM
 *  Author: 2022
 */ 


#ifndef QUEUE_H_
#define QUEUE_H_

#include "std_types.h"

#define BufferSize	(25)
#define Tx_Len  (20)   

typedef enum
{
	Empty,
	Full,
	NotEmpty
}Buffer_Status;

void Create_Buffer(void);
Buffer_Status BufferStatus(void);
void Add_To_Buffer(u8 *msg);
boolean Get_From_Buffer(u8 *msg);






#endif /* QUEUE_H_ */