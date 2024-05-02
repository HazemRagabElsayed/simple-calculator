
#include <avr/io.h>
#include<math.h>
#include "LCD.h"
#include "Keypad_driver.h"
#define F_CPU 8000000UL
#include"util/delay.h"
char input;
int main(void)
{
	char number1,number2,modifier,flag,operation;
	long int result;
	location1 : LCD_init();
	keypad_init('C');
	LCD_send_cmd(CLRSCREEN);
	_delay_ms(10);
	
	number1=0,number2=0,modifier = 10,flag=0,operation = 't';
	input =NOTPRESSED;
	result =0;
	while(1)
    {

			do{
			input = keypad_read('C');
			 }while(input == NOTPRESSED);
			LCD_send_char(input);
		    if(input != '+' && input != '-' && input != '*' && input != '/'  )
			  {
				  if(0 == flag)
				  {
					  number1 = number1+(input-48)*modifier;
				  }
				  else
				  {
					  number2 = number2 +(input-48)*modifier;
				  }
				  modifier = modifier/10;
			  }
		    else if (input == '+' || input == '-' || input == '*' || input == '/')
			{
				operation = input;
				modifier = 10;
				flag = 1;
			}
			_delay_ms(300);
			if (input == '=')
			{
				break;
			}
				}
			
			if (operation == '+')
			{
				result = number1+number2;
			}
			else if (operation == '-')
			{
				result = number1 - number2;
			}
			else if (operation == '*')
			{
				result = number1 * number2;
			}
			else if (operation == '/')
			{
				result = number1 / number2;
			}
			if(result<10 && 1 == flag)
			{
				LCD_send_char(result+48);
			}
			else if (result<100 && 1 == flag)
			{
				LCD_send_char(result/10+48);
				LCD_send_char(result%10+48);
				
			}
			else if (result<1000 && 1 == flag)
			{
				LCD_send_char(result/100 + 48);
				LCD_send_char((result%100)/10 + 48);
				LCD_send_char((result%100)%10+48);
				
				
			}
			else if(result <10000 && 1 == flag)
			{
				LCD_send_char(result/1000 + 48);
				LCD_send_char((result%1000)/100 + 48);
				LCD_send_char((result%1000)%100/10+48);
				LCD_send_char((result%1000)% 100 %10 + 48);
			}
			input =NOTPRESSED;
			do{
				input =keypad_read('C');
			}while(input==NOTPRESSED);
				if (input == 'o')
				{
					LCD_send_cmd(CLRSCREEN);
					_delay_ms(300);
					goto location1;
				}
			
		}