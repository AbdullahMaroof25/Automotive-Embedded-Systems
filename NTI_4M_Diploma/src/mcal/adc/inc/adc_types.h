
/*
 * adc_types.h
 *
 * Created: 10/23/2023 3:06:43 PM
 *  Author: 2022
 */ 

#ifndef  ADC_TYPES_H_
#define  ADC_TYPES_H_

typedef enum{
	
	VREF_AVCC,
	VREF_AREF,
	VREF_256
	
}ADC_Vref_Type;

typedef enum{
	
	ADC_SCALER_2=1,
	ADC_SCALER_4,
	ADC_SCALER_8,
	ADC_SCALER_16,
	ADC_SCALER_32,
	ADC_SCALER_64,
	ADC_SCALER_128
	
}ADC_Scaler_Type;

typedef enum {
	ch_0=0,
	ch_1,
	ch_2,
	ch_3,
	ch_4,
	ch_5,
	ch_6,
	ch_7
	
}ADC_Channel_Type;




#endif