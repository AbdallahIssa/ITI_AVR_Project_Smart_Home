/*****************************************************************/
/*****************************************************************/
/*************	 Author  : Abdallah Issa	    ******************/
/*************	 Layer   : HAL					******************/
/*************	 SWC   	 : LCD  				******************/
/*************	 Date    : 12 Sep 2022			******************/
/*************	 Version : V1.0					******************/
/*****************************************************************/
/*****************************************************************/

#ifndef LCD_LCD_PRIVATE_H_
#define LCD_LCD_PRIVATE_H_

#define LCD_8BIT_FUNCTION_SET    			0x38
#define LCD_4BIT_FUNCTION_SET 				0x28
#define LCD_DISPLAY_ON_CURSOR_OFF         	0x0C
#define LCD_ENTRY_MODE_SET					0x06


#define LCD_DDRAM_BASE_ADDRESS				0b10000000
#define LCD_CGRAM_BASE_ADDRESS				0b01000000

#define LCD_8BIT_MODE						1
#define LCD_4BIT_MODE						2



#endif
