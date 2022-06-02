/*
 * Motor.h
 *
 * Created: 2022-05-31 오전 11:29:59
 *  Author: KIMMINJONG
 */ 

#define F_CPU 16000000L

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define ROTATION_DELAY 10
#define PULSE_MIN 1580
#define PULSE_MAX 5200

void INIT_TIMER1(void);

void convert_state(void);