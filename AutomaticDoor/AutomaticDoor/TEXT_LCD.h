
#ifndef TEXT_LCD_H_
#define TEXT_LCD_H_

#include <avr/io.h>
#include <util/delay.h>

#define PORT_DATA		PORTD
#define PORT_CONTROL	PORTB
#define DDR_DATA		DDRD
#define DDR_CONTROL		DDRB

#define RS_PIN			0
#define E_PIN			2 //원래 1인데 모터랑 중복되서 2로 교체

#define COMMAND_CLEAR_DISPLAY	0x01
#define COMMAND_8_BIT_MODE		0x38
#define COMMAND_4_BIT_MODE		0x28

#define COMMAND_DISPLAY_ON_OFF_BIT	2
#define COMMAND_CURSOR_ON_OFF_BIT	1
#define COMMAND_BLINK_ON_OFF_BIT	0

extern uint8_t MODE;
void changeMode(void);
void LCD_pulse_enable(void);
void LCD_write_data(uint8_t data);
void LCD_write_command(uint8_t command);
void LCD_clear(void);
void LCD_write_string(char *string);
void LCD_goto_XY(uint8_t row,uint8_t col);
void LCD_init(void);

#endif