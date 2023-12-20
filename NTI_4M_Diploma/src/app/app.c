/*
 * NTI_4M_Diploma.c
 *
 * Created: 10/20/2023 10:00:06 AM
 * Author : Abdullah Maroof
 */ 


#define F_CPU 16000000UL
#include <util/delay.h>

#include "dio.h"
#include "timers.h"
#include "EXT_INT.h"
#include "comM.h"
#include "uart.h"
#include "led.h"
#include "button.h"
#include "lcd.h"

#include "adc.h"
#include "keypad.h"




#define  TrafficLight		0
#define  Lm35				1

#define  Calculator			2
#define  UART			    3


#define app		UART


#if (app == Lm35)


volatile u32 temp = 0;



void ADC_CLB(void)
{
	lcd_vidClear();
	lcd_vidGotoRowColumn(1,0);
	lcd_vidDisplyStr("<<< TEMP  >>>");
	lcd_vidGotoRowColumn(2,0);
	lcd_vidWritenum(temp);

	
}

int main(void)
{
	
	/* Replace with your application code */
	led_init();
	
	//Led_Turn_off();
	led_off(LED_BLUE);
	
	button_vidinit();
	lcd_vidInit();
	
	ADC_Init(VREF_AVCC,ADC_SCALER_64);
	
	SetCallBack_ExtInt(EXT_INT_1,EXT_1_CallBack);
	
	EXT_voidEnableExtInt(EXT_INT_1,RISIN_EDGE);
	
	
	//ADC_SetCallBack(ADC_CLB);
	//ADC_Interrupt(Enable);
	
	temp = TEMP_Read(ch_1);
	
	EXT_voidInitGlobalInterrupts();
	
	lcd_vidGotoRowColumn(1,0);
	lcd_vidDisplyStr("<<< TEMP  >>>");
	while(1)
	{
		temp = TEMP_Read(ch_1);
		lcd_vidClear();
		lcd_vidGotoRowColumn(1,0);
		lcd_vidDisplyStr("<<< TEMP  >>>");
		lcd_vidGotoRowColumn(2,6);
		lcd_vidWritenum(temp);
		Timer0_Delay_ms(5000);
	}
}


#elif ( app == Calculator)




int main(void)
{
	u8  key = 0x55;
	u16 num = 0;
	u16 res =  0;
	u8 op;
	
	keypad_vidInit();
	lcd_vidInit();
	
	lcd_vidGotoRowColumn(0,2);
	lcd_vidDisplyStr("<< Calculator >>");
	lcd_vidGotoRowColumn(1,4);
	while(1)
	{
		key = keypad_u8GetKey();
		if (key != 0x55)
		{
			if ((key >= '0') && (key <= '9'))
			{
				 lcd_vidDisplyChar(key);
				 num = (num*10)+(key - '0');
			}
			else if ( key == '+' || key == '-' ||
				      key == '/' || key == '*'	 )
			{
				lcd_vidGotoRowColumn(2,2);
				lcd_vidDisplyChar(key);
						
				res = num;
				num = 0;
				if( key == '+')
				op = 1;
				else if( key == '-')
				op = 2;
				else if( key == '*')
				op = 3;
				else
				op = 4;
				lcd_vidGotoRowColumn(2,4);
				  
			}
			else if ( key == '=')
			{
				
				switch(op)
				{
					case 1:
						res +=  num; 
					break;
					case 2:
						res -= num ; 
					break;
					case 3:
						res *=num ; 
					break;
					case 4:
						res /=num; 
					break;
				}
				
				lcd_vidGotoRowColumn(3,4);
				lcd_vidWritenum(res);
				
			
			}
			else
			{
				lcd_vidClear();
				lcd_vidGotoRowColumn(0,2);
				lcd_vidDisplyStr("<< Calculator >>");
				lcd_vidGotoRowColumn(1,4);
				res = 0;
				num = 0;
				
			}
		}
		key = 0x55;
	}
	return 0;
}
#elif  (app == TrafficLight)
volatile u8 state = 1;

#define  Red_State			1
#define  Yellow_State		2
#define  Green_State		3


void Led_Turn_off(void)
{
	led_off(LED_RED);
	led_off(LED_GREEN);
	led_off(LED_YELLOW);
	
}


void Turn_ON_State(led_id_t led)
{
	Led_Turn_off();
	led_on(led);
	Timer0_Delay_ms(2000);
}





void Red_Status(void)
{
	lcd_vidClear();
	lcd_vidGotoRowColumn(1,0);
	lcd_vidDisplyStr("<<STOP NO PASSING>>");
	Turn_ON_State(LED_RED);
}

void Yellow_Status(void)
{
	lcd_vidClear();
	lcd_vidGotoRowColumn(1,0);
	lcd_vidDisplyStr("<< STEADY >>");
	Turn_ON_State(LED_YELLOW);
}

void Green_Status(void)
{
	lcd_vidClear();
	lcd_vidGotoRowColumn(1,0);
	lcd_vidDisplyStr("<< GOOOOO >>");
	Turn_ON_State(LED_GREEN);
}


void EXT_1_CallBack(void)
{
	led_toggle(LED_BLUE);
	if ( state == Red_State)
	{
		state = Red_State;
	}
	else if ( state == Yellow_State)
	{
		Timer0_Delay_ms(1000);
		Red_Status();
		state = Red_State;
	}
	else if ( state == Green_State )
	{
		Timer0_Delay_ms(1000);
		Yellow_Status();
		Red_Status();
		
		
		state = Red_State;
		
	}
}




int main()
{
	
	led_init();
	Led_Turn_off();
	led_off(LED_BLUE);
	
	button_vidinit();
	
	lcd_vidInit();
	
	SetCallBack_ExtInt(EXT_INT_1,EXT_1_CallBack);
	EXT_voidEnableExtInt(EXT_INT_1,RISIN_EDGE);
	EXT_voidInitGlobalInterrupts();
	Timer0_Init(TIMER0_CTC_MODE,TIMER0_SCALER_8,OCO_DISCONNECTED);
	
	
	while (1)
	{
		
		switch( state )
		{
			case Red_State:
			
			Red_Status();
			
			break;
			case Yellow_State:
			
			Yellow_Status();
			break;
			case Green_State:
			
			Green_Status();
			break;
		}
		state++;
		if( state > 4)
		state = 1;
		
		
	}

	return 0;
}
#elif ( app ==UART)

int main()
{
	
	        led_init();
	        led_off(LED_RED);
	        
	        comM_init();
	        
	        EXT_voidInitGlobalInterrupts();
	



/*1  */ 	Send_Message("MY ");
/*2  */ 	Send_Message("FULL ");
/*3  */     Send_Message("NAME ");
/*4  */     Send_Message("IS ");
/*5  */     Send_Message("ABDULLAH ");
/*6  */ 	Send_Message("ADEL ");
/*7  */ 	Send_Message("AHMED ");
/*8  */ 	Send_Message("MAROUF ");
/*9  */ 	Send_Message("I ");
/*10 */ 	Send_Message("AM ");
/*11 */ 	Send_Message("EMBEDDED ");
/*12 */ 	Send_Message("SOFTWARE ");
/*13 */ 	Send_Message("ENGINEER ");



			led_on(LED_RED);
	

	
	while(1)
	{
	
	}
	return 0;
}

#endif


