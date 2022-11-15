/*****************************************************************/
/*****************************************************************/
/*************	 Author  : Abdallah Issa	    ******************/
/*************	 Layer   : HAL					******************/
/*************	 SWC   	 : LCD_I2C   			******************/
/*************	 Date    : 15 Nov 2022			******************/
/*************	 Version : V1.0					******************/
/*****************************************************************/
/*****************************************************************/


#ifndef LCD_I2C_INTERFACE_H_
#define LCD_I2C_INTERFACE_H_

#include <util/delay.h>

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

void LCD_I2C_vInit(void);
void LCD_I2C_vtoggleEnable(void);
void LCD_I2C_vSendChar(u8 character);
void LCD_I2C_vSendCommand(u8 command);
void LCD_I2C_vSendCommand_hf(u8 command);
void LCD_I2C_vClear(void);
void LCD_I2C_vSendString(const char *str);
void LCD_I2C_vSendNumber(s32 num);
void LCD_I2C_vDisplayCustomChar(u8 charId);
void LCD_I2C_vSaveCustomChar(u8* charArr, u8 charId);
void LCD_I2C_vSetCursorPosition(u8 xPos,u8 yPos);
void LCD_I2C_vSendFloat(f32 floatNumber, u8 precision);


//Auxiliary functions
void LCD_I2C_vWriteNumber(s32 num);
int LCD_I2C_poW(int base, int exponent);

#endif
