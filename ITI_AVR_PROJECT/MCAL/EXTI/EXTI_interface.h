/*****************************************************************/
/*****************************************************************/
/*************	 Author  : Abdallah Issa	    ******************/
/*************	 Layer   : MCAL					******************/
/*************	 SWC   	 : EXTI  				******************/
/*************	 Date    : 12 Sep 2022			******************/
/*************	 Version : V1.0					******************/
/*****************************************************************/
/*****************************************************************/

#include "../EXTI/EXTI_private.h"

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_


typedef enum
{
	EXTI_LOW_LEVEL,
	EXTI_ON_CHANGE,
	EXTI_FALLING_EDGE,
	EXTI_RISING_EDGE,
}EXTI_Edge_Interrupt_Source_t;

typedef enum
{
	EXTI_INT0,
	EXTI_INT1,
	EXTI_INT2,
}EXTI_Source_t;

/*
 * You can choose which Interrupt to handle from these options:
 * 1- EXTI_INT0
 * 2- EXTI_INT1
 * 3- EXTI_INT2
 * */

/*
 * You can choose the sense control mode from these options:
 * 1- EXTI_LOW_LEVEL
 * 2- EXTI_ON_CHANGE
 * 3- EXTI_FALLING_EDGE
 * 4- EXTI_RAISING_EDGE
 *
 * Note that EdgeIntSource for EXTI_INT2 is only one of two options:
 * - EXTI_FALLING_EDGE
 * - EXTI_RAISING_EDGE
 * */

void EXTI_vEnable(EXTI_Source_t Copy_u8ExtIntNum, EXTI_Edge_Interrupt_Source_t Copy_u8EdgeIntSource);
void EXTI_vDisable(EXTI_Source_t Copy_u8ExtIntNum);
void EXTI_vSetCallBack(EXTI_Source_t Copy_u8ExtIntNum, void(*Copy_pfun)(void));
void EXTI_vSetSenseCtrl(EXTI_Source_t Copy_u8ExtIntNum, EXTI_Edge_Interrupt_Source_t Copy_u8EdgeIntSource);


#endif
