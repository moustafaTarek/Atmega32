/*
 * UART.h
 *
 * Created: 11/9/2019 4:42:26 PM
 *  Author: Mostafa Tarek
 */ 


#ifndef UART_H_
#define UART_H_

void UART_SEND_STRING(char *ptr);
char UART_RX(void);
void UART_TX(unsigned char data);
void UART_initizalize(unsigned long buad);


#endif /* UART_H_ */