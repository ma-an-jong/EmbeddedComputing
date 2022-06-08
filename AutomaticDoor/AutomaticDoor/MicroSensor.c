#include "MicroSensor.h"

void Timer_init(void)
{
	TCCR0B |= (1 << CS02) | (1 << CS00);
}

uint8_t measure_distance(void)
{
	PORTC |= (1 << PC1);
	_delay_us(10);
	PORTC &= ~(1 << PC1);

	TCNT0 = 0;
	while(!(PINC & 0x04))
		if(TCNT0 > 250) return 255;
	
	TCNT0 = 0;
	while(PINC & 0x04){
		if(TCNT0 > 250)
		{
			TCNT0 = 0;
			break;
		}
	}
	
	
	double pulse_width = TCNT0 * PRESCALER * 1000000.0 / F_CPU;
	return pulse_width/58;
}