

#define F_CPU   16000000UL
#include "util/delay.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "uart.h"
#include "dio.h"
#include "lcd.h"



void int2HexStr(unsigned long num, char *str);
void RX_CallBack(void);

volatile u8 RX_Index = 0;
volatile u8 doneFlag = 0;
u8 securityAccess = 0;
u8 data[20];
u8 key[] = "250899";
u8 successfulAccess[] = "6701";
u8 cipher[9];
u8 sendstr[20];
u8 errorFlag = 0;



int main(void)
{
	int random_number;
	dio_vidConfigChannel(DIO_PORTC,DIO_PIN7,OUTPUT);
	dio_vidWriteChannel(DIO_PORTC,DIO_PIN7,STD_LOW);
	lcd_vidInit();
	lcd_vidDisplyStr("Hello");
	UART_setRxCallback(RX_CallBack);
	UART_Init(UART_BAUDRATE_9600);
    srand(time(NULL));
    random_number = rand();
	int2HexStr(random_number , sendstr );
    while (1) 
    {
		if( doneFlag == 1 )
		{
			doneFlag = 0;
			if(memcmp(data, "2701", 4) == 0)
			{
				strcat(successfulAccess, sendstr);
				lcd_vidDisplyStr(successfulAccess);
				for(u8 i = 4; i < 12; i++)
				{
					if(successfulAccess[i] > '9')
					{
						successfulAccess[i] = successfulAccess[i] - 'A' + 10;
					}
					else
					{
						successfulAccess[i] -= '0';
					}
					if(key[i-4] > '9')
					{
						key[i-4] = key[i-4] - 'A' + 10;
					}
					else
					{
						key[i-4] -= '0';
					}

					cipher[i-4]= successfulAccess[i] ^ key[i-4];

					if(cipher[i-4] > 9)
					{
						cipher[i-4] = cipher[i-4] - 10 +'A';
					}
					else
					{
						cipher[i-4] += '0';
					}
				}
				cipher[8] = '\0';
				lcd_vidGotoRowColumn(1,0);
				lcd_vidDisplyStr(cipher);
			}
			else if(memcmp(data, "3101AA00", 8) == 0)
			{
				if(securityAccess == 1)
				{
					lcd_vidDisplyStr((u8*)"7101AA00");
					dio_vidWriteChannel(DIO_PORTC,DIO_PIN7,STD_HIGH);
				}
				else
				{
					lcd_vidDisplyStr((u8*)"7F3135");
				}
			}
			else if(memcmp(data, "2702", 4) == 0)
			{
				for(u8 i = 4; i < 12; i++)
				{
					if(cipher[i-4] != data[i])
					{
						errorFlag = 1;
						break;
					}
				}
				if(errorFlag == 0)
				{
					lcd_vidDisplyStr((u8*)"6702");
					securityAccess = 1;
				}
				else
				{
					lcd_vidDisplyStr((u8*)"7F2735");
				}

			}
			RX_Index = 0;
		}
    }
	return 0;
}

void int2HexStr(unsigned long num, char *str)
{

	int i = 12;
	int j = 0;

	do{
		str[i] = "0123456789ABCDEF"[num % 16];
		i--;
		num = num/16;
	}while( num > 0);

	while( ++i < 13){
		str[j++] = str[i];
	}

	str[j] = 0;

}

void RX_CallBack(void)
{
	u8 temp = UART_ReceiveChrINT();
	if(temp == '\r')
	{
		data[RX_Index] = '\0';
		doneFlag = 1;
		lcd_vidSendCmd(_LCD_CLEAR);
	}
	else if(temp == 0x08)
	{
		data[--RX_Index] = '\0';
	}
	else
	{
		data[RX_Index] = temp;
		RX_Index++;
	}
}
