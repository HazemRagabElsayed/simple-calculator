/*
 * Keypad_driver.h
 *
 * Created: 19/03/2024 12:54:33 ص
 *  Author: FREINDS
 */ 


#ifndef KEYPAD_DRIVER_H_
#define KEYPAD_DRIVER_H_

#define NOTPRESSED 0xff
#define COLUMN 4+
void keypad_init(char portname);
char keypad_read(char portname);


#endif /* KEYPAD_DRIVER_H_ */