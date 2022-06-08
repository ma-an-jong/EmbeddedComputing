#ifndef _MICRO_SENSOR_H

#define _MICRO_SENSOR_H 
	#define F_CPU 16000000L
	#include <avr/io.h>
	#include <util/delay.h>

	#define PRESCALER 1024


	uint8_t measure_distance(void);
	void Timer_init(void);


#endif