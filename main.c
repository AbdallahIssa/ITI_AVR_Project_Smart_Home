/************************ LIB & utils ************************/
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include <util/delay.h>

/*********************** MCAL libraries ***********************/
#include "MCAL/GIE/GIE_interface.h"
#include "MCAL/GPIO/GPIO_interface.h"
#include "MCAL/EXTI/EXTI_interface.h"
#include "MCAL/TIMER/TIMERS_interface.h"
#include "MCAL/ADC/ADC_interface.h"

/************************ HAL libraries ***********************/
#include "HAL/KEYPAD/KEYPAD_interface.h"
#include "HAL/LCD/LCD_interface.h"
#include "HAL/SERVOM/SERVOM_interface.h"

/*********************** APP libraries ************************/
#include "App/APP_interface.h"

/*********************** main Function ************************/
int main(void)
{
	/*************** peripheral initializations ***************/
	APP_vInit();

	APP_vWelcomeScreen();
	/********************** infinite loop *********************/
	while(1)
	{
		APP_vStartTheSystem();
	}
	return 0;
}

