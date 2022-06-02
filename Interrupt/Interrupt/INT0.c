/*
 * INT0.c
 *
 * Created: 2022-05-10 오전 11:38:06
 *  Author: KIMMINJONG
 */ 

#define F_CPU 16000000L
#include <avr/io.h>
#include <avr/interrupt.h>

ISR(INT0_vect){
	
	if(PIND & 0x04) PORTB = 0x00;
	else			PORTB = 0x20;
}

ISR(PCINT2_vect){
	
	if(PIND & 0x04) PORTB = 0x00;
	else			PORTB = 0x20;
}

void INIT_PORT(void)
{
	
	DDRB = 0x20;
	PORTB = 0x00;
	
	DDRD = 0x00;
	PORTD = 0x04;
}


void INIT_INT0(void){
	EICRA |= (1 << INT0);
	EIMSK |= (1 << ISC00);
	sei();
}


void INIT_PCINT2(void)
{
	
	PCICR |= (1 << PCIE2);
	PCMSK2 |= (1 << PCINT18);
	sei();
	
}

int main(void){
	
	INIT_PORT();
	INIT_PCINT2();
	
	while(1){ }
}
