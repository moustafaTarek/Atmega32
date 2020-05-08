/*
 * button.h
 *
 * Created: 9/11/2019 11:18:45 AM
 *  Author: Mostafa Tarek
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

void button_initialize(char portname , char bit);
char button_read(char portname ,char bit);

#endif /* BUTTON_H_ */