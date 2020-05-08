
/*
 * ADC.c
 *
 * Created: 10/17/2019 12:09:04 AM
 *  Author: Mostafa Tarek
 */ 

#include "macros.h"
#include <avr/io.h>

void Adc_initialize(void)
{
	/*7th's bit in the register ADCSRA which enables the ADC in port A */
	SET_BIT(ADCSRA,ADEN);
	/*
	 refs is the last 2 bits in the register which used to choose the ref voltage 
	 refs1  refs0
	  0       0  -> AREF,internal vref turned off
	  0       1  -> AVCC with external capacitor at AREF pin 
	  1       0  -> reserved
   	  1       1  -> internal 2.56 v with external capacitor at AREF pin 
	*/
	SET_BIT(ADMUX,REFS0);
	CLR_BIT(ADMUX,REFS1); 
	
	/*
	  first 2 bits in ADCSRA register is used to control the clk of the ADC 
	   
	   ADPS2   ADPS1   ADPS0
	    0       0        0   -> 2
		0       0        1   -> 2
		0       1        0   -> 4
		0       1        1   -> 8
		1       0        0   -> 16 
		1       0        1   -> 32
		1       1        0   -> 64
		1       1        1   -> 128
	
	*/
	
	SET_BIT(ADCSRA,ADPS2);
    SET_BIT(ADCSRA,ADPS1);
}

unsigned short Adc_read(void)
{   
	unsigned short data;
	
	
	SET_BIT(ADCSRA,ADSC);
	while(READ_BIT(ADCSRA,ADSC)==1);
	
     data =(ADCL);
     data|=(ADCH<<8);
	 return data ;
}
