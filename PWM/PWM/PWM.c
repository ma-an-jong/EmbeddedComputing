#define F_CPU 16000000L
#include <util/delay.h>
#include <avr/io.h>
#define LED_TIME 20


void turn_on_LED_in_PWM_manner(int dim)
{
	
	int  i;
	PORTB = 0xFF;
	
	for(i = 0; i < 256;i++)
	{
		
		if(i > dim) PORTB = 0x00;
		_delay_us(LED_TIME);
	}
	
}
int main(void)
{
	DDRD |= (1 << PD3);
	
	TCCR2A |= (1 << WGM21) | (1 << WGM20);
	TCCR2B |= (1 << WGM22);
	
	TCCR2A |= (1 << COM2B1);
	
	
	TCCR2B |= (1 << CS22);
	
	OCR2A =  128;
	
	while(1)
	{
		
		for(int i = 0; i < 128; i++)
		{
			OCR2B = i;
			_delay_ms(10);
		}
	}
	
	
}

