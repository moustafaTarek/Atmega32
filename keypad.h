/*
 * keypad.h
 *
 * Created: 10/8/2019 9:23:20 PM
 *  Author: Mostafa Tarek
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "DIO.h"
void keypad_initialize(char PORTNAME);
char keypad_check();




#endif /* KEYPAD_H_ */