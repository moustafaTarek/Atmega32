/*
 * led.c
 *
 * Created: 9/9/2019 11:25:02 AM
 *  Author: Mostafa Tarek
 */ 
#include "macros.h"
#include "DIO.h"

void LED_INITIALIZE(char portname , unsigned char bit)
{
	DIO_SET_BIT_DIRECTION(portname,bit,1);
}

void LED_ON(char portname , unsigned char bit)
{
	DIO_SET_BIT_OUTPUT(portname,bit,1);
}

void LED_OFF(char portname , unsigned char bit)
{
	DIO_SET_BIT_OUTPUT(portname,bit,0);
}

void LED_TOGGLE(char portname,unsigned char bit)
{
	DIO_TOGGLE(portname,bit);
}

char READ_LED (char portname ,unsigned char bit)
{
	 return DIO_READ_BIT(portname,bit);
}