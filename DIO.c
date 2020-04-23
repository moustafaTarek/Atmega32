/*
 * DIO.c
 *
 * Created: 9/5/2019 2:59:34 AM
 *  Author: Mostafa Tarek
 */ 
#include "macros.h"
#include <avr/io.h>


void DIO_SET_BIT_DIRECTION(char port_name  , unsigned char BIT , unsigned char direction )
{
 switch( port_name) 
  {
	case 'A':
	case 'a':
		if(direction==1)
		{
			SET_BIT(DDRA,BIT);
		}
		else 
		{
			CLR_BIT(DDRA,BIT);	
		}
		break;
	case 'B':
	case 'b':
		if(direction==1)
		{
			SET_BIT(DDRB,BIT);
		}
		else
		{
			CLR_BIT(DDRB,BIT);
		}
		break;
	case 'c':
	case 'C':
		if(direction==1)
		{
			SET_BIT(DDRC,BIT);
		}
		else
		{
			CLR_BIT(DDRC,BIT);
		}
		break; 
	case 'd':
	case 'D':
		if(direction==1)
		{
			SET_BIT(DDRD,BIT);
		}
		else
		{
			CLR_BIT(DDRD,BIT);
		}
		break;
	default:
	    break;	
  }
	
	
}
void DIO_SET_BIT_OUTPUT(char port_name , unsigned char  BIT , unsigned char output)
{
	switch(port_name)
	{
		case'A':
		case'a':
			if(output==1) 
			{
				SET_BIT(PORTA,BIT);
			}
			else
			{
				CLR_BIT(PORTA,BIT);
			}
			break;
		case'b':
		case'B':
			if(output==1)
			{
				SET_BIT(PORTB,BIT);
			}
			else
			{
				CLR_BIT(PORTB,BIT);
			}
			break;			
		case'c':
		case'C':
			if(output==1)
			{
				SET_BIT(PORTC,BIT);
			}
			else
			{
				CLR_BIT(PORTC,BIT);
			}			
			break;
		case'D':
		case'd':
			if(output==1)
			{
				SET_BIT(PORTD,BIT);
			}
			else
			{
				CLR_BIT(PORTD,BIT);
			}				
			break;
		default :
			break;	
		
	}
	
	
}
unsigned char DIO_READ_BIT( char port_name , unsigned char BIT)
{
	unsigned char read_value=0;
	switch(port_name)
	{
		case 'a':
		case 'A':
			read_value=READ_BIT(PINA,BIT);
			break;
		case 'b':
		case 'B':
			read_value=READ_BIT(PINB,BIT);
			break;	
		case 'c':
		case 'C':
			read_value=READ_BIT(PINC,BIT);
			break;
		case 'd':
		case 'D':
			read_value=READ_BIT(PIND,BIT);
			break;
		default :
			break;	
				
			
	}
	return read_value;
}
void DIO_TOGGLE(char port_name , unsigned char BIT)
{
	switch(port_name)
	{
		case 'a':
		case 'A':
			TOG_BIT(PORTA,BIT);
			break;
		case 'b':
		case 'B':
			TOG_BIT(PORTB,BIT);
			break;
		case 'c':
		case 'C':
			TOG_BIT(PORTC,BIT);
			break;
		case 'd':
		case 'D':
			TOG_BIT(PORTD,BIT);
			break;
		default:
			break;	
		
	}
}
void DIO_SET_PORT_DIRECTION(char port_name , unsigned char direction)
{
	switch(port_name)
	{
		case 'a':
		case 'A':
			DDRA=direction;
			break;
			
		case 'b':
		case 'B':
			DDRB=direction;
			break;
			
		case 'c':
		case 'C':
			DDRC=direction;
			break;
			
		case 'd':
		case 'D':
			DDRD=direction;
			break;
			
		default:
			break;	
				
	}
}
void DIO_SET_PORT_OUTPUT(char port_name , unsigned char output )
{
	switch(port_name)
	{
		case 'a':
		case 'A':
			PORTA=output;
			break;
		
		case 'b':
		case 'B':
			PORTB=output;
			break;
		
		case 'c':
		case 'C':
			PORTC=output;
			break;
		
		case 'd':
		case 'D':
			PORTD=output;
			break;
		
		default:
			break;
		
	}
	
}
unsigned char DIO_READ_PORT(char port_name )
{
	unsigned char read_value=0;
	switch(port_name)
	{
		case 'a':
		case 'A':
			read_value=PINA;
			break;
		
		case 'b':
		case 'B':
			read_value=PINB;
			break;
		
		case 'c':
		case 'C':
			read_value=PINC;
			break;
		
		case 'd':
		case 'D':
			read_value=PIND;
			break;
		
		default:
			break;
		
	}

	return read_value;
}
void DIO_connect_pullup(char port_name, unsigned char BIT,char connect_pullup )
{
	switch(port_name)
	{
		case 'a':
		case 'A':
			
			if(connect_pullup==1)
			{
				SET_BIT(PORTA,BIT);
			}
			else
			{
				CLR_BIT(PORTA,BIT);
			}
			break;
			
			
			
					 
			
		case 'b':
		case 'B':
			if(connect_pullup==1)
			{
				SET_BIT(PORTB,BIT);
			}
			else
			{
				CLR_BIT(PORTB,BIT);
			}
			break; 
			 
			 	
	
        case 'c':
        case 'C':
           if(connect_pullup==1)
           {
	           SET_BIT(PORTC,BIT);
           }
           else
           {
	           CLR_BIT(PORTC,BIT);
           }
           break;
                   	
	
	    case 'd':
	    case 'D':
			if(connect_pullup==1)
			{
				SET_BIT(PORTD,BIT);
			}
			else
			{
				CLR_BIT(PORTD,BIT);
			}
			break;
			
			
			
		
		
	}
}
