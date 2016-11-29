#include <stdint.h>
#include "stm32f0xx.h"

void init_LED(void);

int main(void)
{
	init_LED();

	while(1);
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

