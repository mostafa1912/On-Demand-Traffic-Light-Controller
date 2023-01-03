#ifndef #ifndef Timer_h__
#define Timer_h__

#include "../../Utilities/Registers.h"


void TIMER_init();//initialize Timer0
void TIMER_delay(uint16_t millisec); //delay of specific amount default uses 256 prescaler

#endif // Timer_h__
