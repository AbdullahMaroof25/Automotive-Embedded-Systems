
#ifndef PWM_H_
#define PWM_H_


#include "bit_math.h"
#include "std_types.h"
#include "pwm_reg.h"

typedef enum
{
    channel1,
    channel2,
	channel3,
	channel4

}PWM_Channel;

void PWM_Init(void);
void PWM_Start(PWM_Channel  channel , u8 Duty);


void Tim2_Init(void);
void Tim2_Start(void);
u32 Tim2_Read(void);



#endif /* PWM_H_ */
