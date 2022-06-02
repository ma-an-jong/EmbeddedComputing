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

FILE OUTPUT =
 FDEV_SETUP_STREAM(UART_transmit,NULL,_FDEV_SETUP_WRITE);
 FILE INPUT = 
 FDEV_SETUP_STREAM(NULL,UART_receive,_FDEV_SETUP_READ);
 
int main(int argc, char *argv[])
{
	
	unsigned char data;
	
	stdout = &OUTPUT;
	stdin = &INPUT;
	
	UART_INIT();
	
	while(1){
		scanf("%c",&data);
		printf("You typed %c\n",data);
	}
	
	return 0;
}

