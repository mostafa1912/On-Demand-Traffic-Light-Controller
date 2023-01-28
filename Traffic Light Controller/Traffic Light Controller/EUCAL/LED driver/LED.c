
#include "LED.h"


void LED_init(uint8_t ledPort,uint8_t ledPin)
{
	DIO_init(ledPort,ledPin,OUT);	
}
void LED_on(uint8_t ledPort,uint8_t ledPin)
{
	DIO_write(ledPort,ledPin,HI);
}
void LED_off(uint8_t ledPort,uint8_t ledPin)
{
	DIO_write(ledPort,ledPin,LO);
}
void LED_toggle(uint8_t ledPort,uint8_t ledPin)
{
	DIO_toggle(ledPort,ledPin);
}