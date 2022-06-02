/*
 * UART.h
 *
 * Created: 2022-04-12 오전 11:50:15
 *  Author: KIMMINJONG
 */ 


#ifndef UART_H_
#define UART_H_

#include <avr/io.h>

void UART_INIT(void);
unsigned char UART_receive(void);
void UART_transmit(unsigned char data);
void UART_printString(char *str);
void UART_printNumber(uint32_t num);

#endif /* UART_H_ */