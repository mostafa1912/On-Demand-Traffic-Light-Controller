/*
 * CFile1.c
 *
 * Created: 03-Jan-23 8:03:56 PM
 *  Author: mostafa
 */ 
#ifndef Types_h__
#define Types_h__


typedef unsigned char uint8_t; 
typedef unsigned short uint16_t;
typedef unsigned long uint32_t;

// enum for mode
typedef enum EN_mode_t
{
	NORMAL, PEDESTRIAN
}EN_mode_t;

typedef enum EN_carColor_t
{
	RED,YELLOW,GREEN
}EN_carColor_t;

typedef enum EN_buttonPressed_t 
{
	NO,YES
	}EN_buttonPressed_t;
#endif // Types_h__