/*
 * hw4.c
 *
 * Created: 2022-05-21 오후 5:40:42
 * Author : KIMMINJONG
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/sfr_defs.h>

#define F_CPU 16000000L;
#include "UART.h"

int count = 0;
int flag = 0;

unsigned char button_pressed(void)
{
	
	if(bit_is_clear(PIND,PIND7) | bit_is_clear(PIND,PIND6) | bit_is_clear(PIND,PIND5) | bit_is_clear(PIND,PIND4))
	{
		_delay_ms(10);
		if(bit_is_clear(PIND,PIND7) | bit_is_clear(PIND,PIND6) | bit_is_clear(PIND,PIND5) | bit_is_clear(PIND,PIND4))
		{
			return 1;
		}
	}
	return 0;
}

ISR(PCINT2_vect)
{

	if(button_pressed()) {
		if(flag == 1)
		{
			count++;
			if(count % 5 == 0)
			{
				UART_printString("Current Count: ");
				UART_printNumber(count);
				UART_printString("\n");
			}
		}
		flag = 0;
		_delay_ms(100);
			
	}
	else
	{
		if(flag == 0)
		{
			count++;
			if(count % 5 == 0)
			{
				UART_printString("Current Count: ");
				UART_printNumber(count);
				UART_printString("\n");
			}
			
		}
		flag = 1;
		_delay_ms(100);
	}
}


void INIT_PORT(void)
{
	DDRB = 0x20;
	PORTB = 0x00;
	
	DDRD = 0x00;
	PORTD = 0xF0;
}

void INIT_PCINT2(void)
{
	
	PCICR |= (1 << PCIE2);
	PCMSK2 |= (1 << PCINT20) | (1 << PCINT21) | (1 << PCINT22) | (1 << PCINT23);
	sei();	
}

int main(void)
{
	
	UART_INIT();
	INIT_PORT();
	INIT_PCINT2();
	
    while (1) 
    {
		
		
    }
}