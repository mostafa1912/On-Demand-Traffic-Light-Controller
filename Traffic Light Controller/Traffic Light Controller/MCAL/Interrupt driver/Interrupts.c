#include "../../Utilities/Registers.h"

void cli() //using it to disable interrupts
{
	SREG &= ~(1<<7);
}
void sei() //to enable interrupts
{
	SREG |= (1<<7);
}