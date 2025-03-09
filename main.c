#include <stdint.h>

#define LM35_PIN 0
#define GREENLED_PIN 1
#define YELLOWLED_PIN 2
#define REDLED_PIN 3
#define FAN_PIN 7
#define BUZZER_PIN 8
#define BUTTON_PIN 10

#define VREF 3.3f

int main(void)
{
	//Enable Clocks
	RCC->‎AHB1ENR‎ |= (0b01 << 0); // GPIOA
	RCC->‎AHB1ENR‎ |= (0b01 << 1); // GPIOB
	RCC->APB2ENR |= (0b01 << 8); // ADC1

	ADC1->CR2 |= (0b01 << 0);   // Enable ADC
	ADC1->CR1 |= (0b00 << 24);  // 12 bit

	for(int i = 0; i < 1000; ++i);

	ADC1->SQR3 = 0;      	   // Channel 0 -> PA0

	//OUTPUTs
	GPIOA->MODER |= (1 << (2 * GREENLED_PIN) | 1 << (2 * YELLOWLED_PIN) | 1 << (2 * REDLED_PIN) | 1 << (2 * FAN_PIN) | 1 << (2 * BUZZER_PIN));

	//INPUTs
	GPIOA->MODER &= ~(0b11 << (2 * BUTTON_PIN));
	GPIOA->PUPDR |= (0b10 << (2 * BUTTON_PIN));

	// Clear pins
	GPIOA->MODER = 0;

	while(1){
		// Start conversion
		ADC1->CR2 |= (1 << 30);

		while(!(ADC1->SR & (1 << 1))); // Check End Of Conversion

		int ADC_read = ADC1->DR;
		float volt = (ADC_read * VREF)/ 4095; // read * 3.3 / 2 ^ resolution
		float temp = volt * 100; // 10mv -> 1c

	        GPIOA->ODR &= ~((1 << GREENLED_PIN) | (1 << YELLOWLED_PIN) | (1 << REDLED_PIN) | (1 << FAN_PIN) | (1 << BUZZER_PIN));

		if(temp < 25)
		{
			GPIOA->ODR |= (1 << GREENLED_PIN);
		}
		else if(temp < 35)
		{
			GPIOA->ODR |= (1 << YELLOWLED_PIN);
			GPIOA->ODR |= (1 << FAN_PIN);
		}
		else if(temp > 35 && temp < 45)
		{
			GPIOA->ODR |= (1 << REDLED_PIN);
			GPIOA->ODR |= (1 << FAN_PIN);
		}
		else if(temp > 45)
		{
			GPIOA->ODR |= (1 << REDLED_PIN);
			GPIOA->ODR |= (1 << BUZZER_PIN);
		}
	}

}
