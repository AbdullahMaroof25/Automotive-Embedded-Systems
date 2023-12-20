/*
 * adc_reg.h
 *
 * Created: 10/23/2023 3:08:22 PM
 *  Author: 2022
 */ 


#ifndef ADC_REG_H_
#define ADC_REG_H_


#define ADMUX (*(volatile unsigned char*)0x27)
#define ADLAR 5
#define REFS0 6
#define REFS1 7

#define ADCSRA (*(volatile u8*)0x26)
#define ADPS0 0
#define ADPS1 1
#define ADPS2 2
#define ADIE  3
#define ADIF  4
#define ADATE 5
#define ADSC  6
#define ADEN  7

#define ADCL (*(volatile u8*)0x24)
#define ADCH (*(volatile u8*)0x25)
#define ADC_result (*(volatile u16*)0x24)

/* ADC Conversion Complete */
#define ADC_vect			   __vector_16


#endif /* ADC_REG_H_ */