/*
 * ADC.cpp
 *
 * Created: 2022-04-21 오후 5:04:13
 * Author : KIMMINJONG
 */ 
#define F_CPU 16000000L
#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>
#include "UART.h"

void ADC_INIT(unsigned char channel)
{
	ADMUX |= 0x40;		//AVCC를 기준 전압으로 선택
	
	ADCSRA |= 0x07;		// 분주비 설정
	ADCSRA |= (1 << ADEN);	// ADC 활성화
	ADCSRA |= (1 << ADATE); // 자동 트리거 모드
	
	ADMUX |= ((ADMUX & 0xE0) | channel); // 채널 선택
	ADCSRA |= (1 << ADSC); // 변환 시작
	
}

int read_ADC(void)
{
	
	while(!(ADCSRA & (1 << ADIF))); //변환 종료 대기
	
	return ADC; //10비트 값을 반환
}

void int_to_string(int n , char *buffer)
{
	
	sprintf(buffer,"%04d",n);
	buffer[4] = '\0';
}

int main(void)
{

	int value;
	uint8_t on_off;
	
	ADC_INIT(0);		//AD 변환기 초기화
	DDRD = 0xFF;
    
	while (1) 
    {

		value = read_ADC() >> 7;	// 가변저항 값을 읽기
		PORTD = (0x01 << value);
		
    }
}

