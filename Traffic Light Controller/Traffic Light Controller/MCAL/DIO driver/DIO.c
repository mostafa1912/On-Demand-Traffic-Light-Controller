#include "DIO.h"


void DIO_init(uint8_t portName, uint8_t pinNumber,uint8_t direction) //sets the wanted pin on the atmega 32 as either input or output by modifying the registers
{
	switch (portName){
		case PORT_A:
			if (direction == IN)
			{
				DDRA &= ~(1<<pinNumber);
			}
			else if (direction == OUT) 
			{
				DDRA |= (1<<pinNumber);
			}
			else 
			{
				//error handling
			}
			break;
		case PORT_B:
			if (direction == IN)
			{
				DDRB &= ~(1<<pinNumber);
			}
			else if (direction == OUT)
			{
				DDRB |= (1<<pinNumber);
			}
			else
			{
				//error handling
			}
			break;
		case PORT_C:
			if (direction == IN)
			{
				DDRC &= ~(1<<pinNumber);
			}
			else if (direction == OUT)
			{
				DDRC |= (1<<pinNumber);
			}
			else
			{
				//error handling
			}
			break;
		
		case PORT_D:
			if (direction == IN)
			{
				DDRD &= ~(1<<pinNumber);
			}
			else if (direction == OUT)
			{
				DDRD |= (1<<pinNumber);
			}
			else
			{
				//error handling
			}
			break;
	}
			
}

void DIO_write(uint8_t portName, uint8_t pinNumber,uint8_t value)
{
	switch (portName)
	{
		case PORT_A:
			if (value == LO)
			{	
				PORTA &= ~(1<<pinNumber);
			}
			else if(value == HI)
			{
				PORTA |= (1<<pinNumber);
			}
			else
			{
				//error handling
			}
			break;
		case PORT_B:
			if (value == LO)
			{
				PORTB &= ~(1<<pinNumber);
			}
			else if(value == HI)
			{
				PORTB |= (1<<pinNumber);
			}
			else
			{
				//error handling
			}
			break;
		case PORT_C:
			if (value == LO)
			{
				PORTC &= ~(1<<pinNumber);
			}
			else if(value == HI)
			{
				PORTC |= (1<<pinNumber);
			}
			else
			{
				//error handling
			}
			break;
		case PORT_D:
			if (value == LO)
			{
				PORTD &= ~(1<<pinNumber);
			}
			else if(value == HI)
			{
				PORTD |= (1<<pinNumber);
			}
			else
			{
				//error handling
			}
			break;
	}
}

void DIO_read(uint8_t portName, uint8_t pinNumber,uint8_t* value)
{
	switch(portName){
		case PORT_A:
			*value = (PINA&(1<<pinNumber))>>pinNumber;
			
			break;
		case PORT_B:
			*value = ((PINB&(1<<pinNumber))>>pinNumber);
			break;
		case PORT_C:
			*value = ((PINC&(1<<pinNumber))>>pinNumber);
			break;
		case PORT_D:
			*value = ((PIND&(1<<pinNumber))>>pinNumber);
			break;
	}
}

void DIO_toggle(uint8_t portName, uint8_t pinNumber)
{
	switch (portName)
	{
		case PORT_A:
			PORTA ^= (1<<pinNumber);
			break;
		case PORT_B:
			PORTB ^= (1<<pinNumber);
			break;
		case PORT_C:
			PORTC ^= (1<<pinNumber);
			break;
		case PORT_D:
			PORTD ^= (1<<pinNumber);
			break;
	}
}