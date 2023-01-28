/*
 * DIO.H
 *
 * Created: 03-Jan-23 9:04:17 PM
 *  Author: mosta
 */ 

#ifndef DIO_h__
#define DIO_h__

#include "../../Utilities/Registers.h"
/*	This file will include all internal driver typedefs,
	all driver macros,
	all driver function prototypes.
*/

//port defines
#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_C 'C'
#define PORT_D 'D'

//direction defines
#define IN 0
#define OUT 1

//state defines 
#define HI 1 
#define LO 0

//function prototypes 
void DIO_init(uint8_t portName, uint8_t pinNumber,uint8_t direction);
void DIO_write(uint8_t portName, uint8_t pinNumber,uint8_t value);
void DIO_read(uint8_t portName, uint8_t pinNumber,uint8_t* value);
void DIO_toggle(uint8_t portName, uint8_t pinNumber);
#endif // DIO_h__
