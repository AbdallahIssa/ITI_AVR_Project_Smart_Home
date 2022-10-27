#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

#include "../HAL/KEYPAD/KEYPAD_interface.h"
#include "../HAL/LCD/LCD_interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"

#include "APP_interface.h"
#include "APP_private.h"
#include "APP_config.h"

#include <util/delay.h>

u8 heart[8]=
{
	0b00000,
	0b01010,
	0b11111,
	0b11111,
	0b01110,
	0b01110,
	0b00100,
	0b00000
};



void APP_vWelcomeScreen (void)
{
	/*welcome screen*/
	for(u8 j=0; j<2; j++)
	{
		for(u8 i = 2; i< 5;i++)
		{
			LCD_vSetCursorPosition(0,i);
			LCD_vSendString(" M  A  M  ");
			LCD_vSetCursorPosition(1,i);
			LCD_vSendString("Smart Home");
			_delay_ms(300);
			LCD_vClear();
		}
		for(u8 i = 5; i> 2;i--)
		{
			LCD_vSetCursorPosition(0,i);
			LCD_vSendString(" M  A  M  ");
			LCD_vSetCursorPosition(1,i);
			LCD_vSendString("Smart Home");
			_delay_ms(300);
			LCD_vClear();
		}
	}
}

void APP_vUserWelcomeScreen(void)
{
	LCD_vClear();
	LCD_vSendString("WELCOME ");
	LCD_vSetCursorPosition(0, 10);
	LCD_vDisplayCustomChar(0);
	_delay_ms(1000);
	LCD_vClear();
}

void APP_vEnterLandingState (void)
{
	u16 Pass =0;
	u8 PassTryFlag =0;
	u8 PassKey =0;
	LCD_vSetCursorPosition(0,0);
	LCD_vSendString("ENTER PASS:");
	u16 i= 1000;

	do{
	LCD_vSetCursorPosition(1,1);
	Pass = 0;
	PassTryFlag++;
	while(1)
	{
		PassKey = KEYPAD_u8GetPressed();
		LCD_vSendChar('*');
		Pass += PassKey*i;
		i=i/10;
		if (Pass == 1234)
		{
			APP_vEnterRunningState();
		}
		if (i == 0)
		{
			i=1000;
			break;
		}

	}
	if(Pass == 1234)
	{
		break;
	}
	LCD_vSetCursorPosition(1,1);
	LCD_vSendString("Try again !");
	_delay_ms(500);
	LCD_vSetCursorPosition(1,1);
	LCD_vSendString("            ");

	}while(PassTryFlag < 3 && Pass != 1234);
	//After 3 fail attempts it will go out from the while and Enter the Blocked Mode
	if((PassTryFlag == 1 || PassTryFlag == 2 || PassTryFlag == 3)&& Pass != 1234)
	{
		APP_vEnterBlockedState();
	}

}

void APP_vInittheSystem(void)
{
	//Buzzer direction
	GPIO_vSetPinDirection(BUZZER_PORT, BUZZER_PIN, OUTPUT_PIN);
	//DCM direction
	GPIO_vSetPinDirection(DCM_PORT, DCM_PIN, OUTPUT_PIN);
	//LCD Saving the heart arrary emoji in the CGRAM of LCD
	LCD_vSaveCustomChar(heart, 0);
}

void APP_vStartTheSystem(void)
{
	APP_vInittheSystem();
	APP_vEnterLandingState();
}

void APP_vEnterRunningState(void)
{
	// Opening Mode
	APP_vUserWelcomeScreen();
	APP_vOpenTheDoor();
	LCD_vSendString("Ebrahim Erhamni");
	while(1){}
	// Room Temp. Mode

	// AC : Servo

	// Go to Terminate State

}

void APP_vOpenTheDoor(void)
{
	LCD_vClear();
	LCD_vSendString("Opening the door ...");
	GPIO_vSetPinValue(DCM_PORT, DCM_PIN, HIGH);
	_delay_ms(3000);
	GPIO_vSetPinValue(DCM_PORT, DCM_PIN, LOW);
	LCD_vClear();
}

void APP_vEnterBlockedState(void)
{
	for(u8 i=0; i<3; i++)
	{
		LCD_vClear();
		LCD_vSendString("Access is denied");
		// Buzzer will Beep 3 times
		GPIO_vSetPinValue(BUZZER_PORT, BUZZER_PIN, HIGH);
		_delay_ms(500);
		LCD_vSendString("                   ");
		GPIO_vSetPinValue(BUZZER_PORT, BUZZER_PIN, LOW);
		_delay_ms(500);
	}
	while(1){}
}




