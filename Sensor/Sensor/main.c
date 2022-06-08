
#define F_CPU 16000000L

#include <avr/io.h>
#include <util/delay.h>
#include "UART.h"

void ADC_INIT(unsigned char channel)
{
	ADMUX |= 0x40;
	ADCSRA |= 0x07;
	ADCSRA |= (1 << ADEN);
	ADCSRA |= (1 << ADATE);
	ADMUX |= ((ADMUX & 0xE0) | channel);
	ADCSRA |= ( 1 << ADSC);	
}

int read_ADC(void)
{
	while(!(ADCSRA & ( 1 << ADIF)));
	return ADC;
}
int main(void)
{
	int read;
	UART_INIT();
	ADC_INIT(0);
	DDRB = 0x08;
	PORTB = 0x00;
	
    while (1) 
    {
		read = read_ADC();
		UART_printNumber(read);
		UART_transmit('\n');
		if(read > 500) PORTB = 0x00;
		else PORTB = 0x08;
		
		_delay_ms(50);
    }
	
}

