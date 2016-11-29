#define STM32F051

#include "stdint.h"
#include "stm32f0xx.h"
#include "temp_sensor_lib.h"

void main(void);
void init_leds(void);

void main(void)
{
	init_leds();
	temp_sensor_init_iic();

	uint8_t sensor_value = 0;
	for(;;)
	{
		sensor_value = temp_sensor_read();
		GPIOB->ODR = sensor_value;
	}

}

void init_leds(void) {
	RCC->AHBENR |= RCC_AHBENR_GPIOBEN; //enable clock for LEDs
	GPIOB->MODER |= GPIO_MODER_MODER0_0; //set PB0 to output
	GPIOB->MODER |= GPIO_MODER_MODER1_0; //set PB1 to output
	GPIOB->MODER |= GPIO_MODER_MODER2_0; //set PB2 to output
	GPIOB->MODER |= GPIO_MODER_MODER3_0; //set PB3 to output
	GPIOB->MODER |= GPIO_MODER_MODER4_0; //set PB4 to output
	GPIOB->MODER |= GPIO_MODER_MODER5_0; //set PB5 to output
	GPIOB->MODER |= GPIO_MODER_MODER6_0; //set PB6 to output
	GPIOB->MODER |= GPIO_MODER_MODER7_0; //set PB7 to output
}
