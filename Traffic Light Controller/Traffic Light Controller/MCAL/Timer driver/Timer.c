#include "Timer.h"
#include "..\..\Utilities\Registers.h"


#define F_CPU 8000000
#define tickTime 0.032
void TIMER_init()
{
	// Set timer 0 to normal mode
	TCCR0 = 0x00;
	

	// Enable timer 0 overflow interrupt
	//TIMSK |= (1 << 0);

	// Enable global interrupts
	SREG |= (1<<7);
	MCUCR |= (1<<1)|(1<<0); //setting interrupts to rising edge
}

void TIMER_delay(uint16_t millisec)
{
	uint16_t numberOfOverflows, TimerInitial, overflow_Counter ;
	double maxDelay;
	overflow_Counter = 0;
	maxDelay = 8.192; //max delay in ms possible with this timer configuration
	
	
	if(millisec<maxDelay)
	{
		TimerInitial = (maxDelay-millisec)/tickTime;
		numberOfOverflows = 1;
	}
	else if (millisec == (uint16_t) maxDelay)
	{
		TimerInitial = 0;
		numberOfOverflows = 1;
	}
	else
	{
		numberOfOverflows = (uint16_t) (millisec/maxDelay);
		TimerInitial = 256 - (maxDelay-millisec)/tickTime;
	}
	
	TCNT0 = TimerInitial;
	// Set prescaler to 256 and start timer
	TCCR0 |= (1 << 2);
	while (overflow_Counter != numberOfOverflows)
	{
		while((TIFR & (1<<0)) == 0);
		TIFR |= (1<<0); //reset overflow flag
		overflow_Counter = overflow_Counter + 1 ;
		
	}
	TCCR0 = 0; //stop timer
	return ;
}

