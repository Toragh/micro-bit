#include <stdint.h>
#include "uart.h"
#include "gpio.h"


int main(){
	// Configure LED Matrix
	for(int i = 4; i <= 15; i++){
		GPIO->DIRSET = (1 << i);
		GPIO->OUTCLR = (1 << i);
	}


	// Configure buttons
	GPIO->PIN_CNF[17] = 0;
	GPIO->PIN_CNF[26] = 0;

	uart_init();
	GPIO->OUTCLR = (1<<13);
	GPIO->OUTCLR = (1<<14);
	GPIO->OUTCLR = (1<<15);
	int led = 0;

	

	while (1)
	{
		if ((uart_read() != '\0') & (led))
		{
			led = 0;			
			GPIO->OUTCLR = (1<<13);
			GPIO->OUTCLR = (1<<14);
			GPIO->OUTCLR = (1<<15);
		}
		if ((uart_read() != '\0') & (!led))
		{
			led = 1;
			GPIO->OUTSET = (1<<13);
			GPIO->OUTSET = (1<<14);
			GPIO->OUTSET = (1<<15);
		}


		/*
		if (!((GPIO->IN & (1<<26))>>26))
		{
			uart_send('B');
		}
		if (!((GPIO->IN & (1<<17))>>17))
		{
			uart_send('A');
		}*/

	}

	return 0;
}
