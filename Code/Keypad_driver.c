/*
 * Keypad_driver.c
 *
 * Created: 19/03/2024 12:59:21 ص
 *  Author: Hazem Ragab Elsayed
 */ 
#include<avr/io.h>
#define F_CPU 8000000UL
#include<util/delay.h>
#include "Keypad_driver.h"
#include "DIO.h"

void keypad_init(char portname)
{
	DIO_vsetPINDir(portname,0,1);
	DIO_vsetPINDir(portname,1,1);
	DIO_vsetPINDir(portname,2,1);
	DIO_vsetPINDir(portname,3,1);
	DIO_vsetPINDir(portname,4,0);
	DIO_vsetPINDir(portname,5,0);
	DIO_vsetPINDir(portname,6,0);
	DIO_vsetPINDir(portname,7,0);
	DIO_write(portname,4,1);
	DIO_write(portname,5,1);
	DIO_write(portname,6,1);
	DIO_write(portname,7,1);
	
}

char keypad_read(char portname)
{
	char returnvalue=NOTPRESSED,col,row,arr[4][4] = {{'7','8','9','/'},{'4','5','6','*'},{'1','2','3','-'},{'o','0','=','+'}};
	
	for(row=0;row<=3;row++)
	{
		DIO_write(portname,0,1);
		DIO_write(portname,1,1);
		DIO_write(portname,2,1);
		DIO_write(portname,3,1);
		DIO_write(portname,row,0);
		for(col= 0;col<=3;col++)
		{
			if(DIO_u8read(portname,col+4)==0)
			{
				returnvalue = arr[row][col];
				break;
			}
			if(0 == returnvalue)
			{
				break;
			}
			
			
		}
		
	}
	return returnvalue;
}
