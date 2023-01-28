#include "Button.h"


void BUTTON_init(uint8_t buttonPort,uint8_t buttonPin)
{
		DIO_init(BUTTON_PORT,BUTTON_PIN,IN);
		GICR |= (1<<6); //enabling external interrupt 0
}

void BUTTON_read(uint8_t buttonPort,uint8_t buttonPin,uint8_t *value)
{	
	DIO_read(BUTTON_PORT,BUTTON_PIN,value);
}
