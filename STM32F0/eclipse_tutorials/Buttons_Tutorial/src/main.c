#include <stdint.h>
#include "stm32f0xx.h"

void init_LED(void);
void init_Buttons(void);
void poll_Buttons(void);

int main(void)
{
	init_LED();
	init_Buttons();

	while(1)
	{poll_Buttons();}
}

void init_LED(void)
{
	//Enable port B clock
	RCC->AHBENR |= RCC_AHBENR_GPIOBEN;

	//Set pins to output mode
	GPIOB->MODER |= GPIO_MODER_MODER0_0;
	GPIOB->MODER |= GPIO_MODER_MODER1_0;
	GPIOB->MODER |= GPIO_MODER_MODER2_0;
	GPIOB->MODER |= GPIO_MODER_MODER3_0;
	GPIOB->MODER |= GPIO_MODER_MODER4_0;
	GPIOB->MODER |= GPIO_MODER_MODER5_0;
	GPIOB->MODER |= GPIO_MODER_MODER6_0;
	GPIOB->MODER |= GPIO_MODER_MODER7_0;

	//Set output data
	GPIOB->ODR = 0x000F;
}

void init_Buttons(void)
{
	//Enable port A clock
	RCC->AHBENR |= RCC_AHBENR_GPIOAEN;

	// set pins to inputs
	GPIOA->MODER &= ~GPIO_MODER_MODER0; //set PA0 to input
	GPIOA->MODER &= ~GPIO_MODER_MODER1; //set PA1 to input
	GPIOA->MODER &= ~GPIO_MODER_MODER2; //set PA2 to input
	GPIOA->MODER &= ~GPIO_MODER_MODER3; //set PA3 to input
	// enable pull-down resistors
	GPIOA->PUPDR |= GPIO_PUPDR_PUPDR0_0; //enable pull up for PA0
	GPIOA->PUPDR |= GPIO_PUPDR_PUPDR1_0; //enable pull up for PA1
	GPIOA->PUPDR |= GPIO_PUPDR_PUPDR2_0; //enable pull up for PA2
	GPIOA->PUPDR |= GPIO_PUPDR_PUPDR3_0; //enable pull up for PA3
}

void poll_Buttons(void)
{
	if ((GPIOA->IDR & GPIO_IDR_0) == 0) GPIOB->ODR = 1;
	else if ((GPIOA->IDR & GPIO_IDR_1) == 0) GPIOB->ODR = 2;
	else if ((GPIOA->IDR & GPIO_IDR_2) == 0) GPIOB->ODR = 4;
	else if ((GPIOA->IDR & GPIO_IDR_3) == 0) GPIOB->ODR = 8;
	else GPIOB->ODR = 0;
}
