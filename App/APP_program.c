/************************ LIB & utils ************************/
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include <util/delay.h>

/*********************** MCAL libraries ***********************/
#include "../MCAL/GIE/GIE_interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include "../MCAL/TIMER/TIMERS_interface.h"
#include "../MCAL/ADC/ADC_interface.h"
#include "../MCAL/EXTI/EXTI_interface.h"
#include "../MCAL/I2C/I2C_interface.h"

/************************ HAL libraries ***********************/
#include "../HAL/KEYPAD/KEYPAD_interface.h"
#include "../HAL/LCD_I2C/LCD_I2C_interface.h"
#include "../HAL/SERVOM/SERVOM_interface.h"

/*********************** APP libraries ************************/
#include "APP_interface.h"
#include "APP_private.h"
#include "APP_config.h"


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

static void GS_APP_vEnterOpeningMode(void);
void GS_APP_vON_OFFTheAC(void);
void G_APP_vStartACMotion(void);
u8 G_ON_OFFTheACFlag = 0;

void APP_vInit(void)
{
	I2C_vInit();
	I2C_vStart();
	I2C_vWrite(0x70);
	LCD_I2C_vInit();
	KEYPAD_vInit();
	TIMERS_vInit();
	SERVOM_vInit();
	ADC_vInit();
}


void APP_vInitTheSystem(void)
{
	// Buzzer direction
	GPIO_vSetPinDirection(APP_BUZZER_PORT, APP_BUZZER_PIN, OUTPUT_PIN);
	// RED LED direction
	GPIO_vSetPinDirection(APP_RED_LED_PORT, APP_RED_LED_PIN, OUTPUT_PIN);
	// DCM direction
	GPIO_vSetPinDirection(APP_DCM_PORT, APP_DCM_PIN, OUTPUT_PIN);
	// LCD Saving the heart arrary emoji in the CGRAM of LCD
	LCD_I2C_vSaveCustomChar(heart, 0);
	// AC OFF button direction
	GPIO_vSetPinDirection(APP_AC_ON_OFF_BUTTON_PORT, APP_AC_ON_OFF_BUTTON_PIN, OUTPUT_PIN);
	// AC OFF button Pull-up activation
	GPIO_vSetPinValue(APP_AC_ON_OFF_BUTTON_PORT, APP_AC_ON_OFF_BUTTON_PIN, HIGH);
	// Global Interrupt Activation
	GIE_vEnableGIE();
	// INT0 Enable (APP EXIT button)
	EXTI_vEnable(EXTI_INT0, EXTI_FALLING_EDGE);
}

void APP_vStartTheSystem(void)
{
	APP_vInitTheSystem();
	APP_vEnterLandingState();
}

void APP_vWelcomeScreen (void)
{
	/*welcome screen*/
	for(u8 j=0; j<3; j++)
	{
		LCD_I2C_vSetCursorPosition(0, 4);
		LCD_I2C_vSendString(" M  A  M  ");
		LCD_I2C_vSetCursorPosition(1, 3);
		LCD_I2C_vSendString("Smart Home");
		_delay_ms(300);
		LCD_I2C_vClear();
		_delay_ms(300);
	}
}

void APP_vUserWelcomeScreen(void)
{
	LCD_I2C_vClear();
	LCD_I2C_vSendString("Welcome ");
	LCD_I2C_vSetCursorPosition(0, 10);
	LCD_I2C_vDisplayCustomChar(0);
	_delay_ms(1000);
	LCD_I2C_vClear();
}

void APP_vEnterLandingState(void)
{
	u16 Pass = 0;
	u8 PassTryFlag = 0;
	u8 PassKey = 0;
	LCD_I2C_vSetCursorPosition(0, 0);
	LCD_I2C_vSendString("Enter pass:");
	u16 i= 1000;

	do{
		LCD_I2C_vSetCursorPosition(1,1);
		Pass = 0;
		PassTryFlag++;
	while(1)
	{
		PassKey = KEYPAD_u8GetPressed();
		LCD_I2C_vSendChar('*');
		Pass += PassKey*i;
		i=i/10;
		if (Pass == 1234)//1235 : 5 not 4 because of + in keypad (connection purpose)
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
	LCD_I2C_vSetCursorPosition(1,1);
	LCD_I2C_vSendString("Try again !");
	_delay_ms(500);
	LCD_I2C_vSetCursorPosition(1,1);
	LCD_I2C_vSendString("            ");

	}while(PassTryFlag < 3 && Pass != 1234);
	//After 3 fail attempts it will go out from the while and Enter the Blocked Mode
	if((PassTryFlag == 1 || PassTryFlag == 2 || PassTryFlag == 3)&& Pass != 1234)
	{
		APP_vEnterBlockedState();
	}

}

static void GS_APP_vEnterOpeningMode(void)
{
	APP_vUserWelcomeScreen();
	APP_vOpenTheDoor();
}

void APP_vEnterRunningState(void)
{
	// Opening Mode
	GS_APP_vEnterOpeningMode();
	while(1)
	{
		// Conversion of the ADC :
		u16 Local_u16DigitalValue = ADC_u16ReadDigitalValue_Sync(ADC_Channel_2);
		u16 Local_u16Temp = ((Local_u16DigitalValue*500UL)/(1024));
		LCD_I2C_vClear();
		LCD_I2C_vSendString("Temp=   ");
		LCD_I2C_vSendNumber(Local_u16Temp);
		LCD_I2C_vSendString(" C");
		_delay_ms(500);

		// if INT0 is entered
		EXTI_vSetCallBack(EXTI_INT0, APP_vEnterTerminationState);
		// if is ACC_OFF button pressed
		if(GPIO_u8GetPinValue(APP_AC_ON_OFF_BUTTON_PORT, APP_AC_ON_OFF_BUTTON_PIN) != 0)
		{
			if(Local_u16Temp >= APP_MAX_BEARABLE_TEMP)
			{
				LCD_I2C_vSetCursorPosition(1, 0);
				LCD_I2C_vSendString("AC is working..");
				G_APP_vStartACMotion();
			}
			else
			{
				// The weather is beautiful, No need for AC
				LCD_I2C_vSetCursorPosition(1, 0);
				LCD_I2C_vSendString("Fine Weather");
				_delay_ms(1000);
				SERVOM_vStart(0);
				SERVOM_vStop();
			}
		}
		else
		{
			LCD_I2C_vSetCursorPosition(1, 0);
			LCD_I2C_vSendString("AC is disabled");
			_delay_ms(1000);
			GS_APP_vON_OFFTheAC();
		}

	}
}

// Once the ACC_OFF button is pressed
void GS_APP_vON_OFFTheAC(void)
{
	LCD_I2C_vSetCursorPosition(1, 0);
	LCD_I2C_vSendString("AC is disabled");
	// Stop AC
	TIMERS_vStartTimer(SERVOM_TIMER);
	SERVOM_vStop();
	TIMERS_vStopTimer(SERVOM_TIMER);
}


void G_APP_vStartACMotion(void)
{
	TIMERS_vStartTimer(SERVOM_TIMER);
	// A try to simulate the AC motor motion
	SERVOM_vStop();
	_delay_ms(1000);
	SERVOM_vStart(45);
	_delay_ms(1000);
	SERVOM_vStart(90);
	_delay_ms(1000);
	SERVOM_vStart(135);
	_delay_ms(1000);
	SERVOM_vStart(180);
	_delay_ms(1000);
	SERVOM_vStart(135);
	_delay_ms(1000);
	SERVOM_vStart(90);
	_delay_ms(1000);
	SERVOM_vStart(45);
	_delay_ms(1000);
	TIMERS_vStopTimer(SERVOM_TIMER);
}

// Once the Exit button is pressed, this callback function will executed
void APP_vEnterTerminationState(void)
{
	// Let's stop all the working peripherials first before being stuck in the infinte loop
	ADC_vDisable();
	EXTI_vDisable(EXTI_INT0);

	TIMERS_vStartTimer(SERVOM_TIMER);
	SERVOM_vStop();
	TIMERS_vStopTimer(SERVOM_TIMER);

	// say GoodBye to your System :)
	LCD_I2C_vClear();
	LCD_I2C_vSendString("happy to serve");
	LCD_I2C_vSetCursorPosition(1, 5);
	LCD_I2C_vSendString("^_^");
	while(1){}
}

void APP_vOpenTheDoor(void)
{
	LCD_I2C_vClear();
	LCD_I2C_vSendString("Opening the door ...");
	GPIO_vSetPinValue(APP_DCM_PORT, APP_DCM_PIN, HIGH);
	_delay_ms(3000);
	GPIO_vSetPinValue(APP_DCM_PORT, APP_DCM_PIN, LOW);
	LCD_I2C_vClear();
}

void APP_vEnterBlockedState(void)
{
	TIMERS_vStartTimer(TIMER2);
	for(u8 i=0; i<3; i++)
	{
		LCD_I2C_vClear();
		LCD_I2C_vSendString("Access is denied");
		// Buzzer will Beep 3 times with the red led at the same time
		TIMERS_vSetCompareMatchValue(TIMER2, 0, 128);
		GPIO_vSetPinValue(APP_RED_LED_PORT, APP_RED_LED_PIN, HIGH);
		_delay_ms(500);
		LCD_I2C_vSendString("                   ");
		TIMERS_vSetCompareMatchValue(TIMER2, 0, 0);
		GPIO_vSetPinValue(APP_RED_LED_PORT, APP_RED_LED_PIN, LOW);
		_delay_ms(500);
	}
	TIMERS_vStopTimer(TIMER2);
	while(1){}
}



