/*
 * button.c
 *
 * Created: 9/11/2019 11:13:51 AM
 *  Author: Mostafa Tarek
 */ 
#include "DIO.h"

void button_initialize(char portname , char bit)
{
	DIO_SET_BIT_DIRECTION(portname,bit,0);
}

char button_read(char portname ,char bit)
{
	 return DIO_READ_BIT(portname,bit);
}