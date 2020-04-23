/*
 * EEPROM.c
 *
 * Created: 9/21/2019 1:21:32 PM
 *  Author: Mostafa Tarek
 */ 
 #include <avr/io.h>

#include "macros.h"

void EEPROM_write( unsigned short address , unsigned char data)
{
	/* put the address of the location in the EEPROM you want to access in the EEAR register */
	EEARL=(char) address ;    // first 8 bits in the low register
	EEARH=(char)(address>>8); // last 2 bits of the 10 bits in the high register 
	
	/* put data u want to be saved in the EEPROM in data register of the EEEPROM and the mp will put it on the data lines */
	EEDR=data; 
	
	/*
	must be enabled to give permission to the EEWE bit to make writing process
	life time : 4 clk cycles , and HARDWARE will change it to zero
	EEMWE : bit 2
	*/
	SET_BIT(EECR,EEMWE); 
	/*
	enables writing on the EEPROM.
	you must check if the data is written or not as to wait until EEWE becomes zero
	EEWE : bit 1
	*/
	SET_BIT(EECR,EEWE);
	while (READ_BIT(EECR,EEWE)==1);
	
				
}

unsigned char EEPROM_read(unsigned char address)
{
	EEARL=(char) address ;    // first 8 bits in the low register
	EEARH=(char)(address>>8); // last 2 bits of the 10 bits in the high register
	SET_BIT(EECR,EERE);
	
	return EEDR ;
}