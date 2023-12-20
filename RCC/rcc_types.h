

#ifndef RCC_TYPES_H_
#define RCC_TYPES_H_

typedef enum{
	HSI,
	HSE,
	PLL
}rcc_sysClk_t;

typedef enum {
	AHB,
	APB1,
	APB2
}rcc_busId_t;

#endif /* RCC_TYPES_H_ */
