#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

//#define F_CPU 16000000L

#define ROTATION_DELAY 10000

#define PULSE_MIN 1300
#define PULSE_MID 3000
#define PULSE_MAX 4700

void INIT_TIMER1(void)
{
	
	//Fast PWM 모드, TOP = ICR1
	TCCR1A |= ( 1 << WGM11 );
	TCCR1B |= ( 1 << WGM12 ) | ( 1 << WGM13 );

	TCCR1B |= (1 << CS11);
	
	ICR1 = 40000;
	
	TCCR1A |= ( 1 << COM1A1 );
	
	//OC1A(PB1 , 아두이노 9번) 핀을 출력으로 설정
	DDRB |= ( 1 << PB1 );

}
int main(void)
{
	INIT_TIMER1();
   
    while (1) 
    {
		OCR1A = PULSE_MIN;
		_delay_ms(ROTATION_DELAY);
		
		OCR1A = PULSE_MID;
		_delay_ms(ROTATION_DELAY);
		
		OCR1A = PULSE_MAX;
		_delay_ms(ROTATION_DELAY);
    }
	
}

