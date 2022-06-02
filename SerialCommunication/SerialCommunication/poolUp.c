/*
 * main.c
 *
 * Created: 2022-04-12 오후 2:08:35
 *  Author: KIMMINJONG
 */ 

#define F_CPU 16000000L

#include <avr/io.h>
#include <stdio.h>
#include "UART.h"
 
void INIT_PORT(void)
{
	DDRB = 0x20; //PB5번
	PORTB = 0x00; // 출력 0
	
	DDRD = 0x00; //버튼 입력
}


int main(void)
{
	
	
	INIT_PORT();
	
	while(1){
		
		if((PIND & 0x04) == 0x04) //PD2의 입력이 VCC
		{
			PORTB = 0x00;
		}
		else
		{
			PORTB = 0x20;
		}
		
	}
	
	return 0;
}

