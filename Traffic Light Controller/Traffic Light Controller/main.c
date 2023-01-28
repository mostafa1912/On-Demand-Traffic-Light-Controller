#include "MCAL/DIO driver/DIO.h"
#include "MCAL/Timer driver/Timer.h"

int main(void)
{
// 	//uint8_t value = 1;
// 	//DIO_init(PORT_A,1,IN);
// 	DIO_init(PORT_A,2,OUT);
// 	//DIO_init(PORT_A,3,OUT);
// 	TIMER_init();
// 	
//     /* Replace with your application code */
//     while (1) 
//     {
// 		//DIO_read(PORT_A,PIN1,&value);
// 		
// 		TIMER_delay(5000);
// 		DIO_toggle(PORT_A,PIN2);
// 		
// 		
//     }
	appInit();
	appStart();
}

