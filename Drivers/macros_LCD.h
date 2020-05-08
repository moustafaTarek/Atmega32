/*
 * macros_LCD.h
 *
 * Created: 9/28/2019 5:11:58 PM
 *  Author: Mostafa Tarek
 */ 


#ifndef MACROS_LCD_H_
#define MACROS_LCD_H_

#define EN 0       // enable pin of the LCD
#define RS 1       // register select of the LCD 
#define Read_write // connected to the ground to save pins
#define LCD_portname 'A'
#define control_portname 'C'
/* used to make the cursor shifted to left or to right when writing of the reading data (access address counter and inc. it by 1) */
#define ENTRY_MODE 0x06 
/* used to force the cursor to move to the first location of the lcd (writing 0 in the address counter of DDRAM) */  
#define RETURN_HOME 0x02  
/* used to clear all data as to clear data in the DDRAM */
#define CLR_SCREEN 0x01

#define CURSOR_ON_DISPLAY_ON 0x0e


//#ifdef eight_bits_mode 
#define EIGHT_BITS_MODE 0x38

/* prototyoes of the functions in the c file */
void send_enable_pulse(void);
void LCD_send_chracter(unsigned char data );
void LCD_send_command(unsigned char command);
void LCD_initialize(void);
void LCD_send_string(char *ptr);
void clean_screen();


#endif /* MACROS_LCD_H_ */