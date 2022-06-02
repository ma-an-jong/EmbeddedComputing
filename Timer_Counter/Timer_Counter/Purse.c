#define H_CPU 16000000;
#include <avr/io.h>
#include <avr/interrupt.h>
#include "UART.h"

int main(void)
{

	TCCR1B |= (1 << CS12) | (1 << CS10);
	
	OCR1A = 0x2000;
	
	TCCR1A |= (1 << COM1A0);
	TCCR1B |= (1 << WGM12); 
	DDRB |= (1 << PB1);
	
	/* Replace with your application code */
	while (1) { }
}

