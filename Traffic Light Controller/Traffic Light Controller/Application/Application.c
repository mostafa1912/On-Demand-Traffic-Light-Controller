#include "../EUCAL/Button driver/Button.h"
#include "../MCAL/Timer driver/Timer.h"
#include "../Utilities/Types.h"
#include "../Utilities/Registers.h"
#include "../Utilities/Interrupts.h"
#include "../EUCAL/LED driver/LED.h"

void appInit(){
//initializing LEDs
LED_init(LED_CAR_PORT,LED_CAR_PORT_R_PIN);
LED_init(LED_CAR_PORT,LED_CAR_PORT_Y_PIN);
LED_init(LED_CAR_PORT,LED_CAR_PORT_G_PIN);

LED_init(LED_PED_PORT,LED_PED_PORT_R_PIN);
LED_init(LED_PED_PORT,LED_PED_PORT_Y_PIN);
LED_init(LED_PED_PORT,LED_PED_PORT_G_PIN);

//initialize timer to normal mode
TIMER_init();

//initialize button
BUTTON_init(BUTTON_PORT,BUTTON_PIN);

//initializing mode




}
EN_mode_t mode;
EN_carColor_t carColor;


void normalMode()
{
	//turn green led on
	LED_on(LED_CAR_PORT,LED_CAR_PORT_G_PIN);
	LED_off(LED_CAR_PORT,LED_CAR_PORT_R_PIN);
	LED_off(LED_CAR_PORT,LED_CAR_PORT_Y_PIN);
	carColor = GREEN;
	
	
	TIMER_delay(5000); //delay 5 seconds
	LED_off(LED_CAR_PORT,LED_CAR_PORT_G_PIN); //turn green led off
	
	//now i need the yellow light to blink for 5 seconds
	
	carColor = YELLOW;
	for (uint8_t i = 0; i < 5;i++)
	{
		LED_on(LED_CAR_PORT,LED_CAR_PORT_Y_PIN);
		TIMER_delay(500);
		LED_off(LED_CAR_PORT,LED_CAR_PORT_Y_PIN);
		TIMER_delay(500);
	}
	
	LED_off(LED_CAR_PORT,LED_CAR_PORT_Y_PIN);
	
	
	
	//Turn on Red LED
	carColor = RED;
	LED_on(LED_CAR_PORT,LED_CAR_PORT_R_PIN);
	TIMER_delay(5000);
	LED_off(LED_CAR_PORT,LED_CAR_PORT_R_PIN); //turn red off
	
	carColor = YELLOW;
	for (uint8_t i = 0; i < 5;i++)
	{
		LED_on(LED_CAR_PORT,LED_CAR_PORT_Y_PIN);
		TIMER_delay(500);
		LED_off(LED_CAR_PORT,LED_CAR_PORT_Y_PIN);
		TIMER_delay(500);
	}
	LED_off(LED_CAR_PORT,LED_CAR_PORT_Y_PIN);
	
}



void pedestrianMode()
{
	switch(carColor)
	{
		case RED :
		//car LEDs
		LED_on(LED_CAR_PORT,LED_CAR_PORT_R_PIN);
		LED_off(LED_CAR_PORT,LED_CAR_PORT_G_PIN);
		LED_off(LED_CAR_PORT,LED_CAR_PORT_Y_PIN);
		
		//pedestrian LEDs
		LED_on(LED_PED_PORT,LED_PED_PORT_G_PIN);
		LED_off(LED_PED_PORT,LED_PED_PORT_R_PIN);
		LED_off(LED_PED_PORT,LED_PED_PORT_Y_PIN);
		
		TIMER_delay(5000);
		
		LED_off(LED_CAR_PORT,LED_CAR_PORT_R_PIN);
		
		for (uint8_t i = 0; i < 5;i++)
		{
			LED_on(LED_CAR_PORT,LED_CAR_PORT_Y_PIN);
			LED_on(LED_PED_PORT,LED_PED_PORT_Y_PIN);
			TIMER_delay(500);
			LED_off(LED_CAR_PORT,LED_CAR_PORT_Y_PIN);
			LED_off(LED_PED_PORT,LED_PED_PORT_Y_PIN);
			TIMER_delay(500);
		}
		
		LED_off(LED_PED_PORT,LED_PED_PORT_G_PIN);
		LED_on(LED_CAR_PORT,LED_CAR_PORT_R_PIN);
		LED_on(LED_PED_PORT,LED_PED_PORT_R_PIN);
		
		
		mode = NORMAL ;
		break;
		
		case (YELLOW || GREEN):
		//car LEDs
		LED_off(LED_CAR_PORT,LED_CAR_PORT_R_PIN);
		LED_off(LED_CAR_PORT,LED_CAR_PORT_G_PIN);
		LED_off(LED_CAR_PORT,LED_CAR_PORT_Y_PIN);
		
		//pedestrian LEDs
		LED_off(LED_PED_PORT,LED_PED_PORT_G_PIN);
		LED_on(LED_PED_PORT,LED_PED_PORT_R_PIN);
		LED_off(LED_PED_PORT,LED_PED_PORT_Y_PIN);
		
		TIMER_delay(5000);
		
		for (uint8_t i = 0; i < 5;i++)
		{
			LED_on(LED_CAR_PORT,LED_CAR_PORT_Y_PIN);
			LED_on(LED_PED_PORT,LED_PED_PORT_Y_PIN);
			TIMER_delay(500);
			LED_off(LED_CAR_PORT,LED_CAR_PORT_Y_PIN);
			LED_off(LED_PED_PORT,LED_PED_PORT_Y_PIN);
			TIMER_delay(500);
		}
		
		LED_on(LED_CAR_PORT,LED_CAR_PORT_R_PIN);
		LED_on(LED_PED_PORT,LED_PED_PORT_G_PIN);
		
		TIMER_delay(5000);
		LED_off(LED_CAR_PORT,LED_CAR_PORT_R_PIN);
		
		for (uint8_t i = 0; i < 5;i++)
		{
			LED_on(LED_CAR_PORT,LED_CAR_PORT_Y_PIN);
			LED_on(LED_PED_PORT,LED_PED_PORT_Y_PIN);
			TIMER_delay(500);
			LED_off(LED_CAR_PORT,LED_CAR_PORT_Y_PIN);
			LED_off(LED_PED_PORT,LED_PED_PORT_Y_PIN);
			TIMER_delay(500);
		}
		
		LED_off(LED_PED_PORT,LED_PED_PORT_G_PIN);
		LED_on(LED_CAR_PORT,LED_CAR_PORT_R_PIN);
		LED_on(LED_PED_PORT,LED_PED_PORT_R_PIN);
		
		mode = NORMAL ;
		
		break;
	}
	
	
}



void appStart()
{	
	while(1)
	{
		if (mode == NORMAL)
		{
			normalMode();	
		}
		else if (mode == PEDESTRIAN)
		{
			pedestrianMode();
		}
	}
}





ISR(EXT_INT_0)
{	
	cli();
	pedestrianMode();
	sei();
}