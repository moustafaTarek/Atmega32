/*
 * I2C.c
 *
 * Created: 4/10/2020 6:24:12 PM
 *  Author: Mostafa Tarek
 */ 
#include <avr/io.h>
#include "macros.h"
#define F_CPU 8000000ul
#define prescaler 1
/* master init must be the clk generator so on this function we will declare registers that will generate the clk*/
void I2C_Master_init(unsigned long SCL_Clock)
{
	TWBR =(unsigned char)(((F_CPU/SCL_Clock)-16)/(2*prescaler));
	if(prescaler == 1)
	{
		TWSR=0;
	}
	else if(prescaler == 4)
	{
		TWSR=1;
	}
	else if(prescaler ==16)
	{
		TWSR=2;	
	}
	else if(prescaler==64)
	{
		TWSR=3;
	}
}

void I2C_start(void)
{
	/*
	TWSTA : written one to start the *start condition*
	TWEN  : used to make 2 pins of SDA and CLK reserved for I2C , this bit must be written to one in each operation , in data sheet code in written like that but not written in the bit's shar7
	TWINT : the interrupt flag of I2C
	note:-
	-before making any operation the interrupt flag must be cleared first
	-after making any operation the interrupt flag is set
	*/
	TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWSTA);
	while(READ_BIT(TWCR,TWINT)==0);
	while((TWSR & 0xF8)!=0x08);
}

void I2c_write_address(unsigned char address)
{
	TWDR=address;
	TWCR=(1<<TWINT)|(1<<TWEN);
	while (READ_BIT(TWCR,TWINT)==0); // wait to finish
	while ((TWSR & 0xF8)!=0x18); // TWSR : status register  
}
void I2C_write_data(unsigned char data)
{
	/*
	TWDR: data register 
	*/
	TWDR=data;
	TWCR=(1<<TWINT)|(1<<TWEN);
	while(READ_BIT(TWCR,TWINT)==0);
	while((TWSR & 0xF8) != 0x28);
}
void I2C_stop(void)
{
	/*
	TWSTO : written one to start the * stop condtion *
	*/	
	TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWSTO);
}
void I2C_set_address(unsigned char address)
{   /* TWAR : address register used to set the address of the salve*/
	TWAR=address;
}
unsigned char I2C_slave_read(void)
{
	TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWEA);
	while (READ_BIT(TWCR,TWINT)==0);
	while((TWSR & 0xF8)!=0x60);
	TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWEA);
	while(READ_BIT(TWCR,TWINT)==0);
	while((TWSR & 0xF8)!=0x80);
	return TWDR;

}