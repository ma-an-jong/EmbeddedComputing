#include <avr/io.h>
#include "UART.h"
void UART_INIT(void){

	/*
	 UART  통신의 제어와 상태를 알아보기 위한 레지스터 중 하나
	'_BV'는 지정한 비트만을 1로 하고, 나머지를 0으로 하는 비트 마스크를 생성하는 매크로
	*/
	
	
	UCSR0A |= _BV(U2X0); //2배속 모드
	
	/*
	하위 4비트(상위4비트는 사용하지 않는다.)를 나타내는 UBRR0H,
	하위 8비트를 나타내는 UBRR0L 레지스터로 구성되어 Baud Rate를 12비트로 표현한다
	*/
	
	UBRR0H = 0x00; //보율 지정
	UBRR0L = 207; // 9600 == 207
	
	/*
	
	UART 통신에서의 데이터 형식 및 통신 방법을 결정하기 위해 사용
	비트 6 UMSEL00과 비트 7 UMSEL01은 동기 또는 비동기 통신 모드를 지정하기 위해 사용된다. 00 비동기 01 동기 
	
	비트 4 UPM00과 비트 5 UPM01은 패리티 모드를 설정하는 비트로, 홀수 패리티, 짝수 패리티, 패리티 사용 안 함 중 선택할 수 있다. 
	00 사용 안함 10 짝수 패리티 11 홀수 패리티
	
	비트 3 USBS0는 정지 비트의 수를 지정하기 위해 사용된다 0 1비트 1 2비트
	
	비트 1 UCSZ00과 비트 2 UCSZ01은 데이터 비트의 수를 결정하기 위해 사용되며,	이 때 UCSR0B 레지스터의 비트 2 UCSZ02가 함께 사용된다.
	
	마지막 비트 0 UCPOL0은 클록(XCK)의 극성을 지정하는 비트로, 동기 모드에서만 사용이 가능하며,
	비동기 모드에서는 0의 값을 가져야 한다.
	
	*/
	
				//00 00 1 10 0	
	UCSR0C |= 0x06; // 비동기 , 8비트 데이터 , 패리티 없음, 1비트 정지모드
	
	UCSR0B |= _BV(RXEN0); // 송수신 가능
	UCSR0B |= _BV(TXEN0);
}

unsigned char UART_receive(void)
{
	//데이터를 수신될 때까지 기다리기 위해, 즉 RXC0 비트가 1이 될 때까지 기다리기 위해 사용
	// RXCO : 수신 완료 상태 확인 비트
	// RXC0 는	수신 버퍼(UDR0)에 읽지 않은 문자가 있을 때는 1이되고, 버퍼가 비어있을때는 0이 된다
	while(!( UCSR0A & (1<<RXC0)) ); 
	return UDR0; 

}

void UART_transmit(unsigned char data)
{
	//데이터가 완전히 전송되고 다음 데이터를 전송할 준비가 되어 있는지를 확인 하기위해 
	//UDRE0 : 송신 가능 상태 확인 비트
	//송신 버퍼(UDR0)가 비어 있어 데이터를 받을 준비가 되어 있을때 1이 된다
	while(! ( UCSR0A & ( 1<< UDRE0)));
	UDR0 = data;
}

void UART_printString(char *str){
	for(int i = 0 ; str[i];i++)
		UART_transmit(str[i]);
}

void UART_printNumber(uint32_t num)
{
	int i;
	char buf[10];
	
	for(i=0; num > 0; i++)
	{
		buf[i] = num%10 + '0';
		num /= 10;		
	}	
	
	for(int j = i - 1; j >= 0 ; --j)
		UART_transmit(buf[j]);
}