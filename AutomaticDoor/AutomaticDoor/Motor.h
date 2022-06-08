#ifndef MOTOR_H_
#define MOTOR_H_

#include <avr/io.h>
#include <avr/interrupt.h>

#define ROTATION_DELAY 5000
#define PULSE_MIN 1500
#define PULSE_MAX 5200
#define FALSE_STATE 0;
#define TRUE_STATE 1;

void INIT_TIMER1(void);
void convert_state(void);

#endif