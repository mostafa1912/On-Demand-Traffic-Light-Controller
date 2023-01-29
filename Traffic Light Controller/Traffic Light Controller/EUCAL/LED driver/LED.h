#ifndef LED_h__
#define LED_h__

#include "../../MCAL/DIO driver/DIO.h"

//LED set 1
#define LED_CAR_PORT PORT_A
#define LED_CAR_PORT_G_PIN PIN2
#define LED_CAR_PORT_Y_PIN PIN1 
#define LED_CAR_PORT_R_PIN PIN0

//LED set 2 for pedestrians
#define LED_PED_PORT PORT_B
#define LED_PED_PORT_G_PIN PIN2
#define LED_PED_PORT_Y_PIN PIN1
#define LED_PED_PORT_R_PIN PIN0

void LED_init(uint8_t ledPort,uint8_t ledPin);
void LED_on(uint8_t ledPort,uint8_t ledPin);
void LED_off(uint8_t ledPort,uint8_t ledPin);
void LED_toggle(uint8_t ledPort,uint8_t ledPin);

#endif // LED_h__

