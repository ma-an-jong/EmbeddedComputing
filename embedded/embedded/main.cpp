
#define F_CPU 16000000L


#include <avr/io.h>
#include <math.h>
#include <stdio.h>
#define __DELAY_BACKWARD_COMPATIBLE__
#include <util/delay.h>

int main(void)
{
    /* Replace with your application code */
	
	DDRD = 0xFF;
	int delay = 333;
	
    while (1) 
    {
		
		char arr[9] = {0x00,0x01,0x03,0x07,0x0F,0x1F,0x3F,0x7F,0xFF};
		
		for(int i = 0 ; i < 9 ; i++){
			PORTD = arr[i];
			int value = sqrt(delay*i)*i;
			_delay_ms(value);
		}
		

	}
	
	return 1;
}

