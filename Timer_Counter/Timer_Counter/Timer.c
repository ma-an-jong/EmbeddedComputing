#define H_CPU 16000000;
#include <avr/io.h>
#include <avr/interrupt.h>
#include "UART.h"


volatile int count = 0;
int state = 0;

ISR(TIMER1_COMPA_vect){
	TCNT1 = 0;
	state = !state;
	if(state) PORTB = 0xFF;
	else PORTB = 0x00;		
}	

int main(void)
{

	DDRB = 0x20;
	PORTB = 0x00;
	
	TCCR1B |= (1 << CS12) | (1 << CS10);
	
	OCR1A = 0x2000;
	
	TIMSK1 |= (1 << OCIE1A);
	sei();
	
    /* Replace with your application code */
    while (1) { }
}

