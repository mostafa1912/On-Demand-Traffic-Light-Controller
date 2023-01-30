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

}

EN_carColor_t carColor = GREEN;
void blinkYellow()
{
	for (uint8_t i = 0; i < 5;i++)
	{
		LED_on(LED_CAR_PORT,LED_CAR_PORT_Y_PIN);
		LED_on(LED_PED_PORT,LED_PED_PORT_Y_PIN);
		TIMER_delay(500);
		LED_off(LED_CAR_PORT,LED_CAR_PORT_Y_PIN);
		LED_off(LED_PED_PORT,LED_PED_PORT_Y_PIN);
		TIMER_delay(500);
	}
}

void normalMode()
{
	DIO_write(PORT_D,PIN0,HI);
	//turn all LEDs off to clear whatever was done in pedestrian mode (if coming from there)
	LED_off(LED_CAR_PORT,LED_CAR_PORT_G_PIN);
	LED_off(LED_CAR_PORT,LED_CAR_PORT_R_PIN);
	LED_off(LED_CAR_PORT,LED_CAR_PORT_Y_PIN);
	
	LED_off(LED_PED_PORT,LED_PED_PORT_G_PIN);
	LED_off(LED_PED_PORT,LED_PED_PORT_Y_PIN);
	LED_off(LED_PED_PORT,LED_PED_PORT_R_PIN);
	
	
	//1.car green on & pedestrian red on for 5 seconds
	LED_on(LED_CAR_PORT,LED_CAR_PORT_G_PIN);
	LED_on(LED_PED_PORT,LED_PED_PORT_R_PIN);
	carColor = GREEN;	
	TIMER_delay(5000); //delay 5 seconds
	LED_off(LED_CAR_PORT,LED_CAR_PORT_G_PIN); //turn green led off while pedestrian red still on
	
	//car yellow light to blink for 5 seconds	
	carColor = YELLOW;
	for (uint8_t i = 0; i < 5;i++)
	{
		LED_on(LED_CAR_PORT,LED_CAR_PORT_Y_PIN);
		TIMER_delay(500);
		LED_off(LED_CAR_PORT,LED_CAR_PORT_Y_PIN);
		TIMER_delay(500);
	}
	
	LED_off(LED_CAR_PORT,LED_CAR_PORT_Y_PIN); //turning off the car yellow light  -- pedestrian red still on
	
	//card red on, pedestrian red off, pedestrian green on
	carColor = RED;
	LED_on(LED_CAR_PORT,LED_CAR_PORT_R_PIN);
	LED_off(LED_PED_PORT,LED_PED_PORT_R_PIN);
	LED_on(LED_PED_PORT,LED_PED_PORT_G_PIN);
	TIMER_delay(5000);
	LED_off(LED_CAR_PORT,LED_CAR_PORT_R_PIN); //turn car red off
	LED_off(LED_PED_PORT,LED_PED_PORT_G_PIN); //turn ped green off
	LED_on(LED_PED_PORT,LED_PED_PORT_R_PIN); //turn ped red on
	
	
	//start blinking car yellow light
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
			//car red on and ped green on for 5 seconds
			LED_on(LED_CAR_PORT,LED_CAR_PORT_R_PIN);
			LED_on(LED_PED_PORT,LED_PED_PORT_G_PIN);		
			TIMER_delay(5000);	
			
			/*
				continue as if in normal mode to complete the cycle since the ISR returns to the
				place it came from.
			*/
			
			
			LED_off(LED_CAR_PORT,LED_CAR_PORT_R_PIN);
			//while green still on for pedestrians
			for (uint8_t i = 0; i < 5;i++)
			{
				LED_on(LED_CAR_PORT,LED_CAR_PORT_Y_PIN);
				TIMER_delay(500);
				LED_off(LED_CAR_PORT,LED_CAR_PORT_Y_PIN);
				TIMER_delay(500);
			} 
			
			//turn off ped green and turn on ped red and car green
			LED_off(LED_PED_PORT,LED_CAR_PORT_G_PIN);
			LED_on(LED_PED_PORT,LED_CAR_PORT_R_PIN);//ped red on
			LED_on(LED_CAR_PORT,LED_CAR_PORT_G_PIN); //car green	
			TIMER_delay(5000);
			
			LED_off(LED_CAR_PORT,LED_CAR_PORT_G_PIN); //turn off car green 
			blinkYellow(); //blink both yellow
			LED_on(LED_CAR_PORT,LED_CAR_PORT_R_PIN);//turn on car red and back to normal mode
			//LED_off(LED_PED_PORT,LED_CAR_PORT_R_PIN);
			
			
			break;
		
		case YELLOW:
			//1.both yellow blink for 5 seconds
			blinkYellow();
		
		
			LED_on(LED_CAR_PORT,LED_CAR_PORT_R_PIN); //car red on
			LED_on(LED_PED_PORT,LED_PED_PORT_G_PIN); //ped green on	
			LED_off(LED_PED_PORT,LED_PED_PORT_R_PIN);	
			TIMER_delay(5000);
			
			LED_off(LED_CAR_PORT,LED_CAR_PORT_R_PIN);
			blinkYellow();
		
			LED_off(LED_PED_PORT,LED_PED_PORT_G_PIN); //ped green off
			LED_on(LED_CAR_PORT,LED_CAR_PORT_G_PIN); //car green on
			LED_on(LED_PED_PORT,LED_PED_PORT_R_PIN); //ped red on
			TIMER_delay(5000);
			
			LED_off(LED_CAR_PORT,LED_CAR_PORT_G_PIN);
			
			for (uint8_t i = 0; i < 5;i++)
			{
				LED_on(LED_CAR_PORT,LED_CAR_PORT_Y_PIN);
				TIMER_delay(500);
				LED_off(LED_CAR_PORT,LED_CAR_PORT_Y_PIN);
				TIMER_delay(500);
			}
			
			break;
			
		case GREEN:
			blinkYellow();
			
			LED_on(LED_CAR_PORT,LED_CAR_PORT_R_PIN); //car red on
			LED_off(LED_CAR_PORT,LED_CAR_PORT_G_PIN); //car green off
			
			LED_on(LED_PED_PORT,LED_PED_PORT_G_PIN); //ped green on
			LED_off(LED_PED_PORT,LED_PED_PORT_R_PIN); //ped red off
			TIMER_delay(5000);
			
			LED_off(LED_CAR_PORT,LED_CAR_PORT_R_PIN);
			blinkYellow();
			
			LED_off(LED_PED_PORT,LED_PED_PORT_G_PIN); //ped green off
			LED_on(LED_PED_PORT,LED_PED_PORT_R_PIN); //ped red on
			
			LED_on(LED_CAR_PORT,LED_CAR_PORT_G_PIN); //car green on
			
			TIMER_delay(5000);
			
			break;
		
	}
	
	
}



void appStart()
{	
	while(1)
	{
		normalMode();			
	}
	
}


ISR(EXT_INT_0){
	//cli();
	pedestrianMode();
	//GIFR |= (1<<6); done automatically
	//sei();		
	
}