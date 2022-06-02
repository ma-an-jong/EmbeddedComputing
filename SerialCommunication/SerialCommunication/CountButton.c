#define F_CPU 16000000L

#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>
#include "UART.h"
#include <avr/sfr_defs.h>

FILE OUTPUT =
 FDEV_SETUP_STREAM(UART_transmit,NULL,_FDEV_SETUP_WRITE);
 FILE INPUT = 
 FDEV_SETUP_STREAM(NULL,UART_receive,_FDEV_SETUP_READ);
 
 
 
void INIT_PORT(void)
{
	DDRB = 0x20; //PB5번
	PORTB = 0x00; // 출력 0
	
	DDRD = 0x00; //버튼 입력
	PORTD = 0x04;
}

unsigned char button_pressed(void)
{
	
	if(bit_is_clear(PIND,PIND2))
	{
		_delay_ms(10);
		if(bit_is_clear(PIND,PIND2))
		{
			return 1;
		}
		
	}
	return 0;
}

unsigned char button_unpressed(void)
{
	
	if(bit_is_set(PIND,PIND2))
	{
		_delay_ms(10);
		if(bit_is_set(PIND,PIND2))
		{
			return 1;
		}
		
	}
	return 0;
}


int main(int argc, char *argv[])
{
	
	unsigned char data;
	
	stdout = &OUTPUT;
	stdin = &INPUT;
	
	INIT_PORT();
	UART_INIT();
	int state = 0;
	
	while(1){
		
		/*if((PIND & 0x04))*/
		if(!button_unpressed())
		{
			state = 0;
			PORTB = 0x00;
		}
		else if(!button_pressed())
		{
			if(state == 0) UART_transmit('*');
			state = 1;
			PORTB = 0x20;
		}
		
	}
	
	return 0;
}

