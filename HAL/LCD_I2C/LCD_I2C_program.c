/*****************************************************************/
/*****************************************************************/
/*************	 Author  : Abdallah Issa	    ******************/
/*************	 Layer   : HAL					******************/
/*************	 SWC   	 : LCD_I2C   			******************/
/*************	 Date    : 15 Nov 2022			******************/
/*************	 Version : V1.0					******************/
/*****************************************************************/
/*****************************************************************/



#include "../../MCAL/GPIO/GPIO_interface.h"
#include "../../MCAL/I2C/I2C_interface.h"

#include "LCD_I2C_config.h"
#include "LCD_I2C_interface.h"
#include "LCD_I2C_private.h"


void LCD_I2C_vInit(void)
{
	_delay_ms(40);
	LCD_I2C_vSendCommand_hf(0x30);
	LCD_I2C_vSendCommand_hf(0x20);
	LCD_I2C_vSendCommand(LCD_I2C_4BIT_FUNCTION_SET);
	_delay_ms(1);
	LCD_I2C_vSendCommand(LCD_I2C_DISPLAY_ON_CURSOR_OFF|(LCD_I2C_CURSOR_ENABLE<<1)|(LCD_I2C_BLINK_ENABLE<<0));
	_delay_ms(1);
	LCD_I2C_vSendCommand(LCD_I2C_CLEAR);
	_delay_ms(2);
	LCD_I2C_vSendCommand(LCD_I2C_ENTRY_MODE_SET);
	_delay_ms(1);
}

void LCD_I2C_vtoggleEnable(void)
{
	TWDR |= 0x02;
	TWCR = (1<<TWCR_TWINT) | (1<<TWCR_TWEN);
	while(!(TWCR &(1<<TWCR_TWINT)));
	_delay_ms(1);
	TWDR &= ~0x02;
	TWCR = (1<<TWCR_TWINT) | (1<<TWCR_TWEN);
	while(!(TWCR &(1<<TWCR_TWINT)));
}


void LCD_I2C_vSendCommand_hf(u8 command)
{
	TWDR &=~0x01;
	TWCR = (1<<TWCR_TWINT) | (1<<TWCR_TWEN);
	while(!(TWCR &(1<<TWCR_TWINT)));
	TWDR &= 0x0F;
	TWCR = (1<<TWCR_TWINT) | (1<<TWCR_TWEN);
	while(!(TWCR &(1<<TWCR_TWINT)));
	TWDR |= (command & 0xF0);
	TWCR = (1<<TWCR_TWINT) | (1<<TWCR_TWEN);
	while(!(TWCR &(1<<TWCR_TWINT)));
	LCD_I2C_vtoggleEnable();
}


void LCD_I2C_vSendCommand(u8 command)
{
	TWDR&=~0x01;								// rs = 0; Selecting register as command register
	TWCR = (1<<TWCR_TWINT) | (1<<TWCR_TWEN);	// Enable I2C and clear interrupt
	while(!(TWCR &(1<<TWCR_TWINT)));

	TWDR &= 0x0F;                   			// clearing the Higher 4 bits
	TWCR = (1<<TWCR_TWINT) | (1<<TWCR_TWEN);	// Enable I2C and clear interrupt
	while(!(TWCR &(1<<TWCR_TWINT)));
	TWDR |= (command & 0xF0);						// Masking higher 4 bits and sending to LCD
	TWCR = (1<<TWCR_TWINT) | (1<<TWCR_TWEN);	//Enable I2C and clear interrupt
	while(!(TWCR &(1<<TWCR_TWINT)));
	LCD_I2C_vtoggleEnable();

	TWDR &= 0x0F;                    			// clearing the Higher 4 bits
	TWCR = (1<<TWCR_TWINT) | (1<<TWCR_TWEN);	// Enable I2C and clear interrupt
	while(!(TWCR &(1<<TWCR_TWINT)));
	TWDR |= ((command & 0x0F)<<4);					// Masking lower 4 bits and sending to LCD
	TWCR = (1<<TWCR_TWINT) | (1<<TWCR_TWEN);	// Enable I2C and clear interrupt
	while(!(TWCR &(1<<TWCR_TWINT)));
	LCD_I2C_vtoggleEnable();

}

void LCD_I2C_vSendChar(u8 character)
{
	TWDR|=0x01;
	TWCR = (1<<TWCR_TWINT) | (1<<TWCR_TWEN);
	while  (!(TWCR &(1<<TWCR_TWINT)));
	TWDR &= 0x0F;
	TWCR = (1<<TWCR_TWINT) | (1<<TWCR_TWEN);
	while  (!(TWCR &(1<<TWCR_TWINT)));
	TWDR |= (character & 0xF0);
	TWCR = (1<<TWCR_TWINT) | (1<<TWCR_TWEN);
	while  (!(TWCR &(1<<TWCR_TWINT)));
	LCD_I2C_vtoggleEnable();

	TWDR &= 0x0F;
	TWCR = (1<<TWCR_TWINT) | (1<<TWCR_TWEN);
	while  (!(TWCR &(1<<TWCR_TWINT)));
	TWDR |= ((character & 0x0F)<<4);
	TWCR = (1<<TWCR_TWINT) | (1<<TWCR_TWEN);
	while  (!(TWCR &(1<<TWCR_TWINT)));
	LCD_I2C_vtoggleEnable();
}





void LCD_I2C_vClear(void)
{
	LCD_I2C_vSendCommand(0x01);
}


void LCD_I2C_vSendString(const char *str)
{
	while(*str != '\0')
	{
		LCD_I2C_vSendChar(*str++);
	}
}

void LCD_I2C_vWriteNumber(s32 num)//500
{
	s32 reverse = 0, count = 0;
	if(num == 0)
	{
		LCD_I2C_vSendChar('0');
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
			LCD_I2C_vSendChar((reverse%10) + '0');
			reverse/=10;
			count--;
		}
	}
}
void LCD_I2C_vSendNumber(s32 num)
{
	if(num >= 0)
	{
		LCD_I2C_vWriteNumber(num);
	}
	else
	{
		LCD_I2C_vSendChar('-');
		LCD_I2C_vWriteNumber(-1*num);
	}
}

void LCD_I2C_vDisplayCustomChar(u8 charId)
{
	if(charId < 8)
	{
		LCD_I2C_vSendChar(charId);
	}
	else
	{
		//Error
	}
}

void LCD_I2C_vSaveCustomChar(u8* charArr, u8 charId)
{
	if(charId < 8)
	{
		LCD_I2C_vSendCommand(LCD_I2C_CGRAM_BASE_ADDRESS + (charId * 8));
		for(u8 i=0; i<8; i++)
		{
			LCD_I2C_vSendChar(charArr[i]);
		}
		LCD_I2C_vSendCommand(LCD_I2C_DDRAM_BASE_ADDRESS);
	}
	else
	{
		//Error
	}
}

void LCD_I2C_vSetCursorPosition(u8 xPos,u8 yPos)
{
	//Location is at first line
	if(xPos==0)
	{
		LCD_I2C_vSendCommand(0x80 + yPos);
	}
	//Location is at second line
	else if(xPos == 1)
	{
		LCD_I2C_vSendCommand(0x80 + 0x40 + yPos);
	}
	else
	{
		//Error
	}
}


void LCD_I2C_vSendFloat(f32 floatNumber, u8 precision)//123.4567
{
	u32 i = (u32) floatNumber;//123
	u32 f = poW(10, precision) * (floatNumber - (f32)i);//4567
	LCD_I2C_vSendNumber(i);
	LCD_I2C_vSendChar('.');
	LCD_I2C_vSendNumber(f);
}

int LCD_I2C_poW(int base, int exponent)
{
	int returnValue=1, i;
	if(base == 0)
	{
		if(exponent == 0)
		{
			returnValue = -1;
		}
		else
		{
			returnValue = 0;
		}
	}
	else
	{
		for(i=0; i<exponent; i++)
		{
			returnValue *= base;
		}
	}
	return returnValue;
}
