#ifndef Interrupts_h__
#define Interrupts_h__

#define EXT_INT_0 __vector_2
#define EXT_INT_1 __vector_3
#define EXT_INT_2 __vector_4



#define ISR(INT_VECT)void INT_VECT(void) __attribute__ ((signal,used));\
void INT_VECT(void)

void sei();
void cli();




#endif // Interrupts_h__

