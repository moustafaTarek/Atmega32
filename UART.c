/*
 * UART.c
 *
 * Created: 11/9/2019 4:42:08 PM
 *  Author: Mostafa Tarek
 */ 

#include <avr/io.h>
#define F_CPU 8000000ul
#include <util/delay.h>
#include "macros.h"

void UART_initizalize(unsigned long buad)
{
	/* u mast write the values in the high register first cause after writting in the low one the buad rate is updated*/
	
	unsigned short UBRR ;
	UBRR=(F_CPU/(16*buad))-1;
	
	UBRRH = (unsigned char)(UBRR>>8) ;
	UBRRL = (unsigned char)(UBRR);
	
	/* enables 2 pins pin the microcontroler of the TX and RX */
	SET_BIT(UCSRB,TXEN);
	SET_BIT(UCSRB,RXEN);
	
	/* setting the mode of the USART --> asynchronous or synchronous 
	
	 0 --> asynchronous
	 1 --> synchronous
	 
	 bit 6 : UMSEL --> in register UCSRC
	
	*/
	CLR_BIT(UCSRC,UMSEL); // asynchronous
	
	/*parity mode by 2 bits : UPM1 and UPM0 in register UCSRC*/
	//SET_BIT(UCSRC,UPM1);
	//CLR_BIT(UCSRC,UPM0);
	
	/* stop bit select */
	CLR_BIT(UCSRC,USBS); // 1 bit for stop bit 
	
	/* chosing the character size */
	
	UCSRC=(1<<URSEL)|(1<<UCSZ0)|(1<<UCSZ1);
	
	
}

void UART_TX(unsigned char data  )
{
	/* waiting until the flag of the TX complete --> trasmiting data is completed*/
 	while(READ_BIT(UCSRA,UDRE)==0); // TXC could be used instead f UDRE
	/* writing data in UDR register --> "TX"--> UDR(write) */ 
  	UDR = data ;
}

char UART_RX(void)
{
	/* waiting until the flag of the RX complete --> recieving data is completed */
	while(READ_BIT(UCSRA,RXC)==0);
	return UDR ;
}
void UART_SEND_STRING(char *ptr)
{
	while(*ptr != 0)
	{
		UART_TX(*ptr);
		ptr++;
		_delay_ms(100);
	}
}
