/*****************************************************************/
/*****************************************************************/
/*************	 Author  : Abdallah Issa	    ******************/
/*************	 Layer   : HAL					******************/
/*************	 SWC   	 : LCD  				******************/
/*************	 Date    : 12 Sep 2022			******************/
/*************	 Version : V1.0					******************/
/*****************************************************************/
/*****************************************************************/

#ifndef LCD_LCD_INTERFACE_H_
#define LCD_LCD_INTERFACE_H_

#include <util/delay.h>

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

void LCD_vInit(void);
void LCD_vSendChar(char character);
void LCD_vSendCommand(u8 command);
void LCD_vClear(void);
void LCD_vSendString(const char *str);
void LCD_vSendNumber(s32 num);
void LCD_vDisplayCustomChar(u8 charId);
void LCD_vSaveCustomChar(u8* charArr, u8 charId);
void LCD_vSetCursorPosition(u8 xPos,u8 yPos);
void LCD_vSendFloat(f32 floatNumber, u8 precision);


//Auxiliary functions
void LCD_vWriteNumber(s32 num);
int poW(int base, int exponent);

#endif
