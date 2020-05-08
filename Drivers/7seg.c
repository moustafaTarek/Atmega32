/*
 * _7seg.c
 *
 * Created: 9/17/2019 11:42:19 PM
 *  Author: Mostafa Tarek
 */ 

void seven_seg_initialze(char portname)
{
	DIO_SET_PORT_DIRECTION(portname,0xff);
}
void seven_seg_write_number(char portname , char number)
{
    char arr[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f/*0x77,0x7f,0x39,0x3f,0x79,0x71*/};
	DIO_SET_PORT_OUTPUT(portname,arr[number]);
}