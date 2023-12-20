

#ifndef ADC_H_
#define ADC_H_


#include "bit_math.h"
#include "std_types.h"
#include "adc_types.h"

#include "adc_reg.h"

void ADC_Init(ADC_Vref_Type vref,ADC_Scaler_Type scaler);
u16 ADC_Read(ADC_Channel_Type ch);
void ADC_Interrupt(Interrupt_statue statue);
void ADC_SetCallBack(void(*func)(void));

u16 TEMP_Read(ADC_Channel_Type ch);

#endif /* ADC_H_ */