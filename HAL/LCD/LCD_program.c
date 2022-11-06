/*****************************************************************/
/*****************************************************************/
/*************	 Author  : Abdallah Issa	    ******************/
/*************	 Layer   : HAL					******************/
/*************	 SWC   	 : LCD  				******************/
/*************	 Date    : 12 Sep 2022			******************/
/*************	 Version : V1.0					******************/
/*****************************************************************/
/*****************************************************************/

#include "../../MCAL/GPIO/GPIO_interface.h"
#include "../../HAL/LCD/LCD_config.h"
#include "../../HAL/LCD/LCD_interface.h"
#include "../../HAL/LCD/LCD_private.h"


void LCD_vInit(void)
{
	GPIO_vSetPortDirection(LCD_DATA_PORT, OUTPUT_PORT);
	GPIO_vSetPinDirection(LCD_CTRL_PORT, LCD_RS_PIN, OUTPUT_PIN);
	GPIO_vSetPinDirection(LCD_CTRL_PORT, LCD_RW_PIN, OUTPUT_PIN);
	GPIO_vSetPinDirection(LCD_CTRL_PORT, LCD_EN_PIN, OUTPUT_PIN);

#if LCD_BIT_MODE==LCD_8BIT_MODE
	_delay_ms(40);
	LCD_vSendCommand(LCD_8BIT_FUNCTION_SET);
	_delay_ms(1);
	LCD_vSendCommand(LCD_DISPLAY_ON_CURSOR_OFF|(LCD_CURSOR_ENABLE<<1)|(LCD_BLINK_ENABLE<<0));
	_delay_ms(1);
	LCD_vClear();
	_delay_ms(2);
	LCD_vSendCommand(LCD_ENTRY_MODE_SET);
	_delay_ms(1);

#elif LCD_BIT_MODE == LCD_4BIT_MODE
	_delay_ms(40);
	LCD_vSendCommand(LCD_4BIT_FUNCTION_SET);
	_delay_ms(1);
	LCD_vSendCommand(LCD_DISPLAY_ON_CURSOR_OFF|(LCD_CURSOR_ENABLE<<1)|(LCD_BLINK_ENABLE<<0));
	_delay_ms(1);
	LCD_vClear();
	_delay_ms(2);
	LCD_vSendCommand(LCD_ENTRY_MODE_SET);
	_delay_ms(1);

#endif
}

void LCD_vSendChar(char character)
{
//	static u8 digitCount = 0, lineRepeated = 0;
#if LCD_BIT_MODE==LCD_8BIT_MODE
	/*Select RS -> 1*/
	GPIO_vSetPinValue(LCD_CTRL_PORT, LCD_RS_PIN, HIGH);
	/*Select RW -> 0*/
	GPIO_vSetPinValue(LCD_CTRL_PORT, LCD_RW_PIN, LOW);
	/*Put data on port*/
	GPIO_vSetPortValue(LCD_DATA_PORT, character);
	/*Trigger the Enable*/
	GPIO_vSetPinValue(LCD_CTRL_PORT, LCD_EN_PIN, HIGH);
	_delay_ms(1);
	GPIO_vSetPinValue(LCD_CTRL_PORT, LCD_EN_PIN, LOW);
	_delay_ms(1);

#elif LCD_BIT_MODE==LCD_4BIT_MODE
	/*Select RS -> 1*/
	GPIO_vSetPinValue(LCD_CTRL_PORT, LCD_RS_PIN, HIGH);
	/*Select RW -> 0*/
	GPIO_vSetPinValue(LCD_CTRL_PORT, LCD_RW_PIN, LOW);
	/*Put upper nipple on port*/
	GPIO_vSetPortValue(LCD_DATA_PORT, ((LCD_DATA_PORT & 0x0F) | (character & 0xF0)));
	/*Trigger the Enable*/
	GPIO_vSetPinValue(LCD_CTRL_PORT, LCD_EN_PIN, HIGH);
	_delay_ms(1);
	GPIO_vSetPinValue(LCD_CTRL_PORT, LCD_EN_PIN, LOW);
	_delay_ms(1);
	/*Put lower nipple on port*/
	GPIO_vSetPortValue(LCD_DATA_PORT, ((LCD_DATA_PORT & 0xF0) | (character << 4)));
	/*Trigger the Enable*/
	GPIO_vSetPinValue(LCD_CTRL_PORT, LCD_EN_PIN, HIGH);
	_delay_ms(1);
	GPIO_vSetPinValue(LCD_CTRL_PORT, LCD_EN_PIN, LOW);
	_delay_ms(1);
//	digitCount++;
//	if(digitCount == 16*(lineRepeated+1))
//	{
//		LCD_vSetCursorPosition(1,0);
//	}
//	if(digitCount == 32*(lineRepeated+1))
//	{
//		lineRepeated++;
//		LCD_vSetCursorPosition(0,0);
//	}
#endif
}

void LCD_vSendCommand(u8 command)
{
#if LCD_BIT_MODE==LCD_8BIT_MODE
	/*Select RS -> 0*/
	GPIO_vSetPinValue(LCD_CTRL_PORT, LCD_RS_PIN, LOW);
	/*Select RW -> 0*/
	GPIO_vSetPinValue(LCD_CTRL_PORT, LCD_RW_PIN, LOW);
	/*Put data on port*/
	GPIO_vSetPortValue(LCD_DATA_PORT, command);
	/*Trigger the Enable*/
	GPIO_vSetPinValue(LCD_CTRL_PORT, LCD_EN_PIN, HIGH);
	_delay_ms(1);
	GPIO_vSetPinValue(LCD_CTRL_PORT, LCD_EN_PIN, LOW);
	_delay_ms(1);
#elif LCD_BIT_MODE==LCD_4BIT_MODE
	/*Select RS -> 0*/
	GPIO_vSetPinValue(LCD_CTRL_PORT, LCD_RS_PIN, LOW);
	/*Select RW -> 0*/
	GPIO_vSetPinValue(LCD_CTRL_PORT, LCD_RW_PIN, LOW);
	/*Put upper nipple on port*/
	GPIO_vSetPortValue(LCD_DATA_PORT, ((LCD_DATA_PORT & 0x0F) | (command & 0xF0)));
	/*Trigger the Enable*/
	GPIO_vSetPinValue(LCD_CTRL_PORT, LCD_EN_PIN, HIGH);
	_delay_ms(1);
	GPIO_vSetPinValue(LCD_CTRL_PORT, LCD_EN_PIN, LOW);
	_delay_ms(1);
	/*Put lower nipple on port*/
	GPIO_vSetPortValue(LCD_DATA_PORT, ((LCD_DATA_PORT & 0xF0) | (command << 4)));
	/*Trigger the Enable*/
	GPIO_vSetPinValue(LCD_CTRL_PORT, LCD_EN_PIN, HIGH);
	_delay_ms(1);
	GPIO_vSetPinValue(LCD_CTRL_PORT, LCD_EN_PIN, LOW);
	_delay_ms(1);
#endif
}

void LCD_vClear(void)
{
	LCD_vSendCommand(0x01);
}


void LCD_vSendString(const char *str)
{
	while(*str != '\0')
	{
		LCD_vSendChar(*str);
		str++;
	}
}

void LCD_vWriteNumber(s32 num)//500
{
	s32 reverse = 0, count = 0;
	if(num == 0)
	{
		LCD_vSendChar('0');
	}
	else
	{
		while(num)
		{
			reverse = reverse * 10 + num % 10;
			num/=10;
			count++;
		}

		while(count > 0)//005
		{
			LCD_vSendChar((reverse%10) + '0');
			reverse/=10;
			count--;
		}
	}
}
void LCD_vSendNumber(s32 num)
{
	if(num >= 0)
	{
		LCD_vWriteNumber(num);
	}
	else
	{
		LCD_vSendChar('-');
		LCD_vWriteNumber(-1*num);
	}
}

void LCD_vDisplayCustomChar(u8 charId)
{
	if(charId < 8)
	{
		LCD_vSendChar(charId);
	}
	else
	{
		//Error
	}
}

void LCD_vSaveCustomChar(u8* charArr, u8 charId)
{
	if(charId < 8)
	{
		LCD_vSendCommand(LCD_CGRAM_BASE_ADDRESS + (charId * 8));
		for(u8 i=0; i<8; i++)
		{
			LCD_vSendChar(charArr[i]);
		}
		LCD_vSendCommand(LCD_DDRAM_BASE_ADDRESS);
	}
	else
	{
		//Error
	}
}

void LCD_vSetCursorPosition(u8 xPos,u8 yPos)
{
	//Location is at first line
	if(xPos==0)
	{
		LCD_vSendCommand(0x80 + yPos);
	}
	//Location is at second line
	else if(xPos == 1)
	{
		LCD_vSendCommand(0x80 + 0x40 + yPos);
	}
	else
	{
		//Error
	}
}


void LCD_vSendFloat(f32 floatNumber, u8 precision)//123.4567
{
	u32 i = (u32) floatNumber;//123
	u32 f = poW(10, precision) * (floatNumber - (f32)i);//4567
	LCD_vSendNumber(i);
	LCD_vSendChar('.');
	LCD_vSendNumber(f);
}

int poW(int base, int exponent)
{
	int l=1, i;
	if(base == 0)
	{
		if(exponent == 0)
		{
			l = -1;
		}
		else
		{
			l = 0;
		}
	}
	else
	{
		for(i=0; i<exponent; i++)
		{
			l *= base;
		}
	}
	return l;
}
