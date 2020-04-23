/*
 * DIO.h
 *
 * Created: 9/5/2019 7:42:21 PM
 *  Author: Mostafa Tarek
 */ 


#ifndef DIO_H_
#define DIO_H_

void DIO_SET_BIT_DIRECTION(char port_name  , unsigned char BIT , unsigned char direction );
void DIO_SET_BIT_OUTPUT(char port_name , unsigned char  BIT , unsigned char output);
unsigned char DIO_READ_BIT( char port_name , unsigned char BIT);
void DIO_TOGGLE(char port_name , unsigned char BIT);
void DIO_SET_PORT_DIRECTION(char port_name , unsigned char direction);
void DIO_SET_PORT_OUTPUT(char port_name , unsigned char output );
unsigned char DIO_READ_PORT(char port_name );
void DIO_connect_pullup(char port_name, unsigned char BIT,char connect_pullup );


#endif /* DIO_H_ */