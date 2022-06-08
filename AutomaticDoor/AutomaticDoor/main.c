#define F_CPU 16000000L

#include "TEXT_LCD.h"
#include "Motor.h"
#include "UART.h"
#include "MicroSensor.h"

volatile int count = 0;
int state = 0;

void INIT_BUTTON(void)
{
	DDRC = 0x00;
	DDRC |= 0x02;
	DDRC &= 0xFA;
	PORTC = 0x01;
}

void open(void)
{
	UART_printString("open\n");
	_delay_ms(10);
	OCR1A = PULSE_MIN;
	count = 0;
	LCD_write_string("Welcome!!");
}

void check_button(void)
{
	if(!(PINC & 0x01))
	{
		
		if(!state)
		{
			state = 1;
			open();
		}
		else
		{
			count = 0;
		}
		
	}
}

void check_sensor(uint8_t distance) 
{
	UART_printNumber(distance);
	UART_transmit('\n');
	if( (distance >= 5) && (distance <= 15) )
	{
		if(!state)
		{
			state = 1;
			open();
		}
		else
		{
			
		}
	}
}


ISR(TIMER0_COMPA_vect)
{
	if(state)
	{
		count++;
		
		if(count >= 320)
		{
			count = 0;
			UART_printString("close\n");
			_delay_ms(10);
			OCR1A = PULSE_MAX;
			state = 0;
			LCD_clear();
		}
	}
	
}

void INIT_TIMER0(void)
{
	TCCR0B |= (1 << CS02) | (1 << CS00);
	OCR0A = 128;
	TIMSK0 |= (1 << OCIE0A);
	sei();
}

int main(void)
{
	volatile uint8_t distance;
	LCD_init();
	_delay_ms(100);
	LCD_write_string("initialize...");
	OCR1A = PULSE_MAX;
	INIT_TIMER1();
	INIT_TIMER0();
	UART_INIT();
	INIT_BUTTON();
	_delay_ms(3000);
	LCD_clear();

	while (1)
	{
		check_button();
		
		if(!state)
		{
			distance = measure_distance();
 			check_sensor(distance);
		}


		_delay_ms(100);
	}
}

