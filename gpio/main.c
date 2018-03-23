#include <stdint.h>
#include "uart.h"



int main(){
	// Configure LED Matrix
	for(int i = 4; i <= 15; i++){
		GPIO->DIRSET = (1 << i);
		GPIO->OUTCLR = (1 << i);
	}

	// Configure buttons
	GPIO->PIN_CNF[17] = 0;
	GPIO->PIN_CNF[26] = 0;


	int sleep = 0;
	while(1){

		/* Check if button B is pressed;
		 * turn on LED matrix if it is. */
		if (!((GPIO->IN & (1<<26))>>26))
		{
			GPIO->OUTSET = (1<<13);
			GPIO->OUTSET = (1<<14);
			GPIO->OUTSET = (1<<15);
		}

		/* Check if button A is pressed;
		 * turn off LED matrix if it is. */
		if (!((GPIO->IN & (1<<17))>>17))
		{
			GPIO->OUTCLR = (1<<13);
			GPIO->OUTCLR = (1<<14);
			GPIO->OUTCLR = (1<<15);
		}

		sleep = 10000;
		while(--sleep);
	}

	return 0;
}
