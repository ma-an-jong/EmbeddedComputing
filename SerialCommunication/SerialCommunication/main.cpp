/*
 * SerialCommunication.cpp
 *
 * Created: 2022-04-12 오후 12:08:31
 * Author : KIMMINJONG
 */ 

#define F_CPU 16000000L
#define TERMINATOR '$'


#include "UART.h"
#include <string.h>

int main(void)
{
	
	int counter = 100;
	int index = 0;
	int process_data = 0;
	char buffer[20] = "";
	char data;
	
	UART_INIT();
    
	UART_printString("Current Counter value: ");
	UART_printNumber(counter);
	UART_printString("\n");	
	
	/* Replace with your application code */
    while (1) 
    {
		data = UART_receive();
		
		if(data == TERMINATOR){
			buffer[index] = '\0';
			process_data = 1;
		}
		else
		{
			buffer[index] = data;
			index++;
		}
		
		if(process_data == 1)
		{
			
			if(strcmp(buffer,"DOWN") == 0){
				counter--;
				UART_printString("Current Count value : ");
				UART_printNumber(counter);
				UART_printString("\n");
			}
			else if(strcmp(buffer,"UP") == 0){
				counter++;
				UART_printString("Current Count value : ");
				UART_printNumber(counter);
				UART_printString("\n");
			}
			else{
				UART_printString("** Unknown Commnad **:");
				UART_printString(buffer);
				UART_printString("\n");
			}
			index = 0;
			process_data = 0;
			
		}
		
		
    }
	
	return 0;
}

