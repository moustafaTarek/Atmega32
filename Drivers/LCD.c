/*
 * LCD.c
 *
 * Created: 9/28/2019 5:11:29 PM
 *  Author: Mostafa Tarek
 */ 
#include "DIO.h"
#include "macros_LCD.h"
#define F_CPU 8000000ul
#include <util/delay.h>

void send_enable_pulse(void)
{
	/*
	giving a pulse on the enable pin for 1-5 msec.
	*/
	DIO_SET_BIT_OUTPUT(control_portname,EN,1);
	_delay_ms(2);
	DIO_SET_BIT_OUTPUT(control_portname,EN,0);
	_delay_ms(2);
		
}
void LCD_send_chracter(unsigned char data )
{
	DIO_SET_PORT_OUTPUT(LCD_portname,data);
	DIO_SET_BIT_OUTPUT(control_portname,RS,1);
	send_enable_pulse();
  
}
void LCD_send_command(unsigned char command)
{
	DIO_SET_PORT_OUTPUT(LCD_portname,command);
	DIO_SET_BIT_OUTPUT(control_portname,RS,0);
	send_enable_pulse();
}
void LCD_initialize(void)
{ 
	_delay_ms(40);
	DIO_SET_PORT_DIRECTION(LCD_portname,0xff);
	
	/* 
	   enable pin      -> output pin
	   register select -> output pin
	*/
	DIO_SET_BIT_DIRECTION(control_portname,EN,1); 
	DIO_SET_BIT_DIRECTION(control_portname,RS,1);
	
	LCD_send_command(EIGHT_BITS_MODE);
	_delay_ms(1);
	LCD_send_command(CURSOR_ON_DISPLAY_ON);
	_delay_ms(1);
	LCD_send_command(CLR_SCREEN);
	_delay_ms(1);
	LCD_send_command(ENTRY_MODE);
	_delay_ms(1);
	
}
void LCD_send_string(char *ptr)
{
	while(*ptr!='\0')
	{
		LCD_send_chracter(*ptr);
		_delay_ms(250);
		ptr++;	
	}
}
void clean_screen()
{
	LCD_send_command(CLR_SCREEN);
	_delay_ms(10);
}

