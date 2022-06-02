/*
 * TextLED.c
 *
 * Created: 2022-05-26 오후 5:31:24
 * Author : KIMMINJONG
 */ 

#include "TEXT_LCD.h"


int main(void)
{
	
    LCD_init();
	
	LCD_write_string("HELLO WORLD!");
	
	_delay_ms(1000);
	
	LCD_clear();
	
	LCD_goto_XY(0,0);
	LCD_write_data('1');
	
	LCD_goto_XY(0,5);
	LCD_write_data('2');
	
	LCD_goto_XY(1,0);
	LCD_write_data('3');
	
	LCD_goto_XY(1,5);
	LCD_write_data('4');
	
    while (1);
}

