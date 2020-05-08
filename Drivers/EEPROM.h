/*
 * EEPROM.h
 *
 * Created: 9/21/2019 1:22:02 PM
 *  Author: Mostafa Tarek
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_

unsigned char EEPROM_read(unsigned char address);
void EEPROM_write( unsigned short address , unsigned char data);




#endif /* EEPROM_H_ */