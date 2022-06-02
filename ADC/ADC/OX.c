/*
 * main.c
 *
 * Created: 2022-04-12 오후 2:08:35
 *  Author: KIMMINJONG
 */ 

#define F_CPU 16000000L

#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>
#include "UART.h"
 
void INIT_PORT(void)
{
	DDRB = 0x20; //PB5번
	PORTB = 0x00; // 출력 0
	
	DDRD = 0x00; //버튼 입력
	PORTD = 0xF0;
}


int main(void)
{
	
	char buffer[5];


	INIT_PORT();
	UART_INIT();
	
	while(1){
		_delay_ms(1000);
		for(int i = 7; i >= 4;i--)
		{
			if( PIND & (0x01 << i) )
			{
				buffer[7-i] = 'O';
			}
			else
			{
				buffer[7-i] = 'X';
			}
		}
		
		buffer[4] = '\0';
		UART_printString(buffer);
		UART_printString("\n");
	}
	
	return 0;
}

//리바운싱 코드

