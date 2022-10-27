#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"

#include "MCAL/GIE/GIE_interface.h"
#include "MCAL/GPIO/GPIO_interface.h"
#include "MCAL/EXTI/EXTI_interface.h"

#include "HAL/KEYPAD/KEYPAD_interface.h"
#include "HAL/LCD/LCD_interface.h"
#include "HAL/ADC/ADC_interface.h"

#include "App/APP_interface.h"

#include <util/delay.h>

int main(void)
{
	LCD_vInit();
	KEYPAD_vInit();

	APP_vWelcomeScreen();

	while(1)
	{
		APP_vStartTheSystem();
	}
	return 0;
}

