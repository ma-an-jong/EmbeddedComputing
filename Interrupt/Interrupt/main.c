/*
 * Interrupt.c
 *
 * Created: 2022-05-03 오후 12:05:05
 * Author : KIMMINJONG
 */ 

#define F_CPU 16000000L
#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#include "UART.h"


void ADC_INIT(unsigned char channel){
	ADMUX |= 0x40;
	
	ADCSRA |= 0x07;
	ADCSRA |= (1 << ADEN);
	ADCSRA |= (1 << ADATE);
	
	ADMUX |= ((ADMUX & 0xE0) | channel);
	ADCSRA |= (1 << ADSC);
}

int read_ADC(void){
	while(!(ADCSRA & (1 << ADIF)));
	
	return ADC;
}

int main(void)
{
	UART_INIT();
	ADC_INIT(0);
	
	UART_printString("** START **");
	srand(read_ADC());
		
    while (1) 
    {
		uint32_t randomNumber = rand()%100 + 1;
		UART_printNumber(randomNumber);
		UART_transmit('\n');
		_delay_ms(1000);
			
    }
}

