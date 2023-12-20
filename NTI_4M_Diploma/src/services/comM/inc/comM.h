/*
 * comM.h
 *
 * Created: 10/28/2023 10:21:46 AM
 *  Author: 2022
 */ 


#ifndef COMM_H_
#define COMM_H_

#include "bit_math.h"
#include "std_types.h"
#include "uart.h"
#include "comM_Config.h"
#include "queue.h"


typedef enum {
	Tx_Flag,
	Rx_Flag
	}MSG_Status;


void comM_init(void);


void Send_Message(u8 *Tx_Message );
void Receive_Message(u8 *Rx_Message  );
boolean Message_Is_Complete(void); 
void Tx_CallBack_Func(void);
void Rx_CallBack_Func(void);


#endif /* COMM_H_ */