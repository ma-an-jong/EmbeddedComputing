/*
 * Motor.c
 *
 * Created: 2022-05-31 오전 11:29:42
 *  Author: KIMMINJONG
 */ 


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

void convert_state(void){
	if(OCR1A == PULSE_MAX)
	{
		OCR1A = PULSE_MIN;
	}
	else
	{
		OCR1A = PULSE_MAX;
	}
	_delay_ms(ROTATION_DELAY);
	
}