#define F_CPU 16000000L
#include "UART.c"

int main(int argc , char* argv[])
{
    /* Replace with your application code */
	
	unsigned char data;
	
	UART_INIT();

    while (1) 
    {
		data = UART_receive();
		//UART_transmit(data);
		UART_printString(data);
		
		
	}
	
	return 1;
}

