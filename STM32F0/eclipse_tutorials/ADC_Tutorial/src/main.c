#include <stdint.h>
#include "stm32f0xx.h"

void init_LED(void);
void init_ADC(void);

int32_t sum_ADC(void);

int32_t temp = 0;

void main(void)
{
	init_LED();
	init_ADC();

	while(1)
	{
		// start ADC conversion
		ADC1->CR |= ADC_CR_ADSTART;

		// wait for end of conversion: EOC == 1. Not necessary to clear EOC as we read from DR
		while((ADC1->ISR & ADC_ISR_EOC) == 0);

		GPIOB->ODR = sum_ADC();
	}
}

void init_LED(void)
{
	//enable clock for LEDs
	RCC->AHBENR |= RCC_AHBENR_GPIOBEN;

	GPIOB->MODER |= GPIO_MODER_MODER0_0; //set PB0 to output
	GPIOB->MODER |= GPIO_MODER_MODER1_0; //set PB1 to output
	GPIOB->MODER |= GPIO_MODER_MODER2_0; //set PB2 to output
	GPIOB->MODER |= GPIO_MODER_MODER3_0; //set PB3 to output
	GPIOB->MODER |= GPIO_MODER_MODER4_0; //set PB4 to output
	GPIOB->MODER |= GPIO_MODER_MODER5_0; //set PB5 to output
	GPIOB->MODER |= GPIO_MODER_MODER6_0; //set PB6 to output
	GPIOB->MODER |= GPIO_MODER_MODER7_0; //set PB7 to output
}

void init_ADC(void)
{
	RCC->APB2ENR |= RCC_APB2ENR_ADCEN; //enable clock for ADC
	RCC->AHBENR |= RCC_AHBENR_GPIOAEN; //enable clock for port which ADC samples from

	GPIOA->MODER |= GPIO_MODER_MODER6; //set PA6 to analog mode
	//ADC1->CHSELR |= ADC_CHSELR_CHSEL6; // select channel 6

	GPIOA->MODER |= GPIO_MODER_MODER5; //set PA5 to analog mode
	//ADC1->CHSELR |= ADC_CHSELR_CHSEL5; // select channel 5

	ADC1->CFGR1 |= ADC_CFGR1_RES_1;    // resolution to 8 bit
	ADC1->CR |= ADC_CR_ADEN;           // set ADEN=1 in the ADC_CR register
	while((ADC1->ISR & ADC_ISR_ADRDY) == 0); //wait until ADRDY==1 in ADC_ISR
}

int32_t sum_ADC(void)
{
	temp = 0;
	ADC1->CHSELR |= ADC_CHSELR_CHSEL5; // select channel 5
	temp = ADC1->DR;
	ADC1->CHSELR |= ADC_CHSELR_CHSEL6; // select channel 6
	temp += ADC1->DR;

	return temp;
}
