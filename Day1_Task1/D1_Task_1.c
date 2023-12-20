#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define enc  0
#define dec  1


int main(void)
{
    unsigned char msg[100];
    unsigned int key;
    unsigned int choice;

    printf("enc = 0  or dce = 1 : ");
    scanf("%d",&choice);

    printf("enter the key ");
    scanf("%d",&key);

    if(key >26)
    key%=26;

    fflush(stdin);

    printf("Enter the msg : ");
    gets(msg);
  
    if( choice == dec )
    {
        for(int i = 0 ; msg[i] != '\0' ; i++)
        {
            
            if(  msg[i] >= 'a' && msg[i] <= 'z' )
            {
                msg[i] -= key;
                if( msg[i] < 'a' )
                {
                    msg[i] += 26;
                }
            }
            else if(  msg[i] >= 'A' && msg[i] <= 'Z' )
            {
                msg[i] -= key;
                if( msg[i] < 'A' )
                {
                    msg[i] += 26;
                }

            }
            else
            {
                continue;
            }            
        }
    }
    else if ( choice == enc )
    {
        
        for(int i = 0 ; msg[i] != '\0' ; i++)
        {
        
            if(  msg[i] >= 'a' && msg[i] <= 'z' )
            {
                msg[i] += key;
                if( msg[i] > 'z' )
                {
                    msg[i] -= 26;
                }
            }
            else if(  msg[i] >= 'A' && msg[i] <= 'Z' )
            {
                msg[i] += key;
                if( msg[i] > 'Z' )
                {
                    msg[i] -= 26;
                }

            }
            else
            {
                continue;
            }
        }     
    }

    printf("the new msg is : ");
    
    for(int i = 0 ; msg[i] != '\0' ; i++)
    {
        printf("%c",msg[i]);
    }

	return 0;
}