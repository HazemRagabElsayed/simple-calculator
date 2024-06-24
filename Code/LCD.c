/*
 * LCD.c
 *
 * Created: 19/03/2024 01:31:24 ص
 *  Author: Hazem Ragab Elsayed
 */ 
#include"DIO.h"
#include"LCD.h"
#define F_CPU 8000000UL
#include<util/delay.h>
void LCD_init()
{
	_delay_ms(200);
	DIO_vsetPINDir('A',0,1);
	DIO_vsetPINDir('A',1,1);
	DIO_vsetPINDir('A',2,1);
	DIO_vsetPINDir('A',3,1);
	DIO_vsetPINDir('A',4,1);
	DIO_vsetPINDir('A',5,1);
	DIO_vsetPINDir('A',6,1);
	DIO_vsetPINDir('A',7,1);
	
	DIO_vsetPINDir('B',RW,1);
	DIO_vsetPINDir('B',RS,1);
	DIO_vsetPINDir('B',EN,1);
	LCD_send_cmd(EIGHT_BIT_MODE);
	LCD_send_cmd(CURSOR_OFF_DISPLAY_ON);
	LCD_send_cmd(ENTRY_MODE);
	LCD_send_cmd(CLRSCREEN);
	_delay_ms(10);
		
}

void LCD_send_cmd(char command)
{
	DIO_write('B',RS,0);
	DIO_write_port('A',command);
	LCD_send_falling_edge();
	_delay_ms(1);
	
}

void LCD_movecursor(char row,char col)
{
	 if (row == 1)
	 {
		 LCD_send_cmd(0x80 + col-1);
	 }
	 else if (row ==2)
	 {
		 LCD_send_cmd(0xC0 + col-1);
	 }
	 else if(row<0 || row>2 || col >16 || col<0 )
	{
		LCD_send_cmd(RETURN_HOME);
	}
}
void LCD_send_char(char character)
{
	DIO_write('B',RS,1);
	DIO_write_port('A',character);
	LCD_send_falling_edge();
}
void LCD_send_string(char* string)
{
	while((*string) != '\0')
	{
		LCD_send_char(*string);
		++string;
	}
}
void LCD_send_falling_edge()
{
	DIO_write('B',EN,1);
	_delay_ms(2);
	DIO_write('B',EN,0);
	_delay_ms(2);
}
