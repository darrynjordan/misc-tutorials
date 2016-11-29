#include <stdint.h>
#include "stm32f0xx.h"

void init_timer(void);

void main(void)
{
  init_timer();

  while(1);
}

void init_timer(void)
{
	  RCC->AHBENR |= RCC_AHBENR_GPIOBEN;

	  RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;

	  GPIOB->MODER |= GPIO_MODER_MODER0_1;
	  GPIOB->MODER |= GPIO_MODER_MODER1_1;

	  GPIOB->AFR[0] |= (1 << 0);
	  GPIOB->AFR[0] |= (1 << 4);

	  TIM3->PSC |= 5000;
	  TIM3->ARR = 960;		// f = 10 Hz

	  // specify PWM mode: OCxM bits in CCMRx. We want mode 1
	  TIM3->CCMR2 |= (TIM_CCMR2_OC3M_2 | TIM_CCMR2_OC3M_1);
	  TIM3->CCMR2 |= (TIM_CCMR2_OC4M_2 | TIM_CCMR2_OC4M_1);

	  // set PWM percentages
	  TIM3->CCR3 = 96;
	  TIM3->CCR4 = 96;

	  // enable the OC channels
	  TIM3->CCER |= TIM_CCER_CC3E;
	  TIM3->CCER |= TIM_CCER_CC4E;

	  TIM3->CR1 |= TIM_CR1_CEN;
}
