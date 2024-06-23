/*
 * LCD.h
 *
 * Created: 19/03/2024 01:35:22 ص
 *  Author: FREINDS
 */ 


#ifndef LCD_H_
#define LCD_H_
#define RW 2
#define RS 3
#define EN 0
#define CLRSCREEN 0X01
#define CURSOR_ON_DISPLAY_ON 0X0e
#define CURSOR_OFF_DISPLAY_ON 0X0c
#define RETURN_HOME 0X02
#define ENTRY_MODE 0x06
#define EIGHT_BIT_MODE 0X38

void LCD_init();
void LCD_movecursor(char row,char col);
void LCD_send_cmd(char command);
void LCD_send_char(char character);
void LCD_send_string(char* string);
void LCD_send_falling_edge();

#endif /* LCD_H_ */