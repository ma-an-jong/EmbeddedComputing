#define F_CPU 16000000L

#include "TEXT_LCD.h"
#include "Motor.h"
#include "UART.h"

volatile int count = 0;
int state = 0;

void open(void)
{
	state = !state;
	OCR1A = PULSE_MIN;
	count = 0;
	
}

ISR(TIMER0_COMPA_vect)
{
	if(state)
	{
		count++;
		TCNT0 = 0;
		if(count == 640)
		{
			count = 0;
			UART_printString("close\n");
			OCR1A = PULSE_MAX;
			state = !state;
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
	
    LCD_init();
	OCR1A = PULSE_MAX;
	INIT_TIMER1();
	INIT_TIMER0();
	UART_INIT();
	

	
// 	LCD_goto_XY(0,0);
// 	LCD_write_data('1');
// 	
// 	LCD_goto_XY(0,5);
// 	LCD_write_data('2');
// 	
// 	LCD_goto_XY(1,0);
// 	LCD_write_data('3');
// 	
// 	LCD_goto_XY(1,5);
// 	LCD_write_data('4');
// 	

	_delay_ms(1000);
	open();
	
    while (1)
	{
		LCD_write_string("HELLO WORLD!");
		UART_printNumber(count);
		UART_printString("\n");
		_delay_ms(1000);
		LCD_clear();
		_delay_ms(1000);
	}
}

