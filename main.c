/************************ LIB & utils ************************/
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include <util/delay.h>

/*********************** MCAL Includes ***********************/
#include "MCAL/GIE/GIE_interface.h"
#include "MCAL/GPIO/GPIO_interface.h"
#include "MCAL/EXTI/EXTI_interface.h"
#include "MCAL/TIMER/TIMERS_interface.h"
#include "MCAL/ADC/ADC_interface.h"
#include "MCAL/I2C/I2C_interface.h"

/************************ HAL Includes ***********************/
#include "HAL/KEYPAD/KEYPAD_interface.h"
/* Bye Bye Normal LCD , Welcome LCD_I2C */
#include "HAL/LCD_I2C/LCD_I2C_interface.h"
#include "HAL/SERVOM/SERVOM_interface.h"

/*********************** APP Includes ************************/
#include "App/APP_interface.h"

/*********************** main Function ************************/
int main(void)
{
	/*************** peripheral initializations ***************/
	APP_vInit();

	// welcome message on LCD at the start of the system
	APP_vWelcomeScreen();

	/********************** infinite loop *********************/
	while(1)
	{
		APP_vStartTheSystem();
	}

	return 0;
}

