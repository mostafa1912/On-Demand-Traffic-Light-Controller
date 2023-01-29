/*
#include "button.h"
int main(void)
{
	uint8_t value;
	BUTTON_init(BUTTON_PORT, BUTTON_PIN);
	DIO_init(PORT_D,PIN0,OUT);
	
	while(1)
	{
		BUTTON_read(BUTTON_PORT, BUTTON_PIN, &value);
		
		DIO_write(PORT_D,PIN0,value);
	}
}
*/