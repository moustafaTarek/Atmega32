/*
 * keypad.c
 *
 * Created: 10/8/2019 7:58:05 PM
 *  Author: Mostafa Tarek
 */
#define  NOTPRESSED 0xff;
#include "DIO.h"

void keypad_initialize(char PORTNAME)
{
	switch(PORTNAME)
	{
		case 'A':
		case 'a':
		    /* output pins */
			DIO_SET_BIT_DIRECTION('A',0,1);
		    DIO_SET_BIT_DIRECTION('A',1,1);
			DIO_SET_BIT_DIRECTION('A',2,1);
			DIO_SET_BIT_DIRECTION('A',3,1);
			
			/* input pins */
			DIO_SET_BIT_DIRECTION('A',4,0);
			DIO_SET_BIT_DIRECTION('A',5,0);
			DIO_SET_BIT_DIRECTION('A',6,0);
	    	DIO_SET_BIT_DIRECTION('A',7,0);
			
			/* connect pull_up pins -> for input pins */
		    DIO_connect_pullup('A',4,1);
		    DIO_connect_pullup('A',5,1);
		    DIO_connect_pullup('A',6,1);
		    DIO_connect_pullup('A',7,1);
            break;
			
		case 'B':
		case 'b':
		    /* output pins */
            DIO_SET_BIT_DIRECTION('B',0,1);
			DIO_SET_BIT_DIRECTION('B',1,1);
			DIO_SET_BIT_DIRECTION('B',2,1);
			DIO_SET_BIT_DIRECTION('B',3,1);
			
			/* input pins */
			DIO_SET_BIT_DIRECTION('B',4,0);
			DIO_SET_BIT_DIRECTION('B',5,0);
			DIO_SET_BIT_DIRECTION('B',6,0);
			DIO_SET_BIT_DIRECTION('B',7,0);
			
			/* connect pull_up pins -> for input pins */
			DIO_connect_pullup('B',4,1);
			DIO_connect_pullup('B',5,1);
			DIO_connect_pullup('B',6,1);
			DIO_connect_pullup('B',7,1);
			break;
			
			
		case 'c':
		case 'C':
		    /* output pins */		
			DIO_SET_BIT_DIRECTION('C',0,1);
			DIO_SET_BIT_DIRECTION('C',1,1);
			DIO_SET_BIT_DIRECTION('C',2,1);
			DIO_SET_BIT_DIRECTION('C',3,1);
			
			/* input pins */			
			DIO_SET_BIT_DIRECTION('C',4,0);
			DIO_SET_BIT_DIRECTION('C',5,0);
			DIO_SET_BIT_DIRECTION('C',6,0);
			DIO_SET_BIT_DIRECTION('C',7,0);	
			
			/* connect pull_up pins -> for input pins */
			DIO_connect_pullup('C',4,1);
			DIO_connect_pullup('C',5,1);
			DIO_connect_pullup('C',6,1);
			DIO_connect_pullup('C',7,1);
		    break;
		
		
		case 'd':
		case 'D':
		    /* output pins */		
			DIO_SET_BIT_DIRECTION('D',0,1);
			DIO_SET_BIT_DIRECTION('D',1,1);
			DIO_SET_BIT_DIRECTION('D',2,1);
			DIO_SET_BIT_DIRECTION('D',3,1);
			
			/* input pins */			
			DIO_SET_BIT_DIRECTION('D',4,0);
			DIO_SET_BIT_DIRECTION('D',5,0);
			DIO_SET_BIT_DIRECTION('D',6,0);
			DIO_SET_BIT_DIRECTION('D',7,0);
			
			/* connect pull_up pins -> for input pins */
			DIO_connect_pullup('D',4,1);
			DIO_connect_pullup('D',5,1);
			DIO_connect_pullup('D',6,1);
			DIO_connect_pullup('D',7,1);
			break;
		
		default:
		break;
		
	}
	
	
}
char keypad_check()
{
	 char arr[4][4]={{'7','8','9','/'},{'4','5','6','*'},{'1','2','3','-'},{'A','0','=','+'}};
	 char row , coloumn ,x ;
	 char  val=NOTPRESSED;
	 
	 for(row=0;row<4;row++)
	 {
		 
		 DIO_SET_BIT_OUTPUT('D',0,1);
		 DIO_SET_BIT_OUTPUT('D',1,1);
		 DIO_SET_BIT_OUTPUT('D',2,1);
		 DIO_SET_BIT_OUTPUT('D',3,1);
		 
		 DIO_SET_BIT_OUTPUT('D',row,0);
		 
		 for(coloumn=0;coloumn<4;coloumn++)
		 {
			x=DIO_READ_BIT('D',(coloumn+4));
			if(x==0)
			{
				val=arr[row][coloumn];
				break;
		 	}
		 }
	     if(x==0)
		 {
			break;
		 }
			
			
     }
         
	 return val ;	 
		 
}
		 
		 
		 
		 