/*
 * hw4_2.c
 *
 * Created: 2022-05-21 오후 6:58:32
 * Author : KIMMINJONG
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include "UART.h"
#define F_CPU 16000000L;


int index = 0;
char data[6] = {0x01,0x03,0x0F,0xFF,0x0F,0x03};

ISR(TIMER1_COMPA_vect)
{
	TCNT1 = 0;
	index = (index+1) % 6;
	PORTD = data[index];

}

int main(void)
{

	DDRD = 0xFF;
	PORTD = data[index];
	
	TCCR1B |= (1 << CS12) | (1 << CS10 );
	
	OCR1A = 0x2000;
	
	TIMSK1 |= (1 << OCIE1A);
	sei();

    while (1) { }
		
}

