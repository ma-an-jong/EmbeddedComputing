

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

void ADC_INIT(unsigned char channel)
{
	ADMUX |= 0x40;
	ADCSRA |= 0x07;
	ADCSRA |= (1 << ADEN);
	ADCSRA |= (1 << ADATE);
	
	ADMUX |= ((ADMUX & 0xE0) | channel);
	ADCSRA |= (1 << ADSC);
	
}

int read_ADC(void)
{
	while( ! ( ADCSRA & (1 << ADIF) ) );
	return ADC;
	
}

int main(void)
{
	int read;
	
	ADC_INIT(0);
	INIT_TIMER1();
	
	while (1)
	{
		
		read = read_ADC();
		
		OCR1A = PULSE_MIN + (int)(3.79 * read);		
		_delay_ms(ROTATION_DELAY);
	}
	
	return 0;
	
}

