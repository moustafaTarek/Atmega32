/*
 * led.h
 *
 * Created: 9/9/2019 11:37:04 AM
 *  Author: Mostafa Tarek
 */ 


#ifndef LED_H_
#define LED_H_
void LED_INITIALIZE(char portname , unsigned char bit);
void LED_ON(char portname , unsigned char bit);
void LED_OFF(char portname , unsigned char bit);
void LED_TOGGLE(char portname,unsigned char bit);
char READ_LED (char portname ,unsigned char bit);

#endif /* LED_H_ */