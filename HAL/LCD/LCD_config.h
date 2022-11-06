/*****************************************************************/
/*****************************************************************/
/*************	 Author  : Abdallah Issa	    ******************/
/*************	 Layer   : HAL					******************/
/*************	 SWC   	 : LCD  				******************/
/*************	 Date    : 12 Sep 2022			******************/
/*************	 Version : V1.0					******************/
/*****************************************************************/
/*****************************************************************/


#ifndef LCD_LCD_CONFIG_H_
#define LCD_LCD_CONFIG_H_

#include "../../MCAL/GPIO/GPIO_private.h"


/*
 * Here are the ports that your LCD connected to:
 * LCD_DATA_PORT : for the value of port that is connected to PIN0:PIN7 (either in 4-bit or 8-bit mode)
 * LCD_CTRL_PORT : for the direction of port that is connected to PIN0:PIN7 (either in 4-bit or 8-bit mode)
 */

#define LCD_DATA_PORT		GPIO_PORTC
#define LCD_CTRL_PORT		GPIO_PORTD

/*
 * Here are your control port pins:
 * For Setting the register select pin just set LCD_RS_PIN to PIN0:PIN7
 * For Setting the read and write pin just set LCD_RW_PIN to PIN0:PIN7
 * For Setting the enable pin just set LCD_EN_PIN to PIN0:PIN7
 */

#define LCD_RS_PIN			PIN0
#define LCD_RW_PIN			PIN1
#define LCD_EN_PIN			PIN6


/*
 * To enable the cursor just set LCD_CURSOR_ENABLE to 1
 * To enable the blinking of the cursor just set LCD_BLINK_ENABLE to 1
 */
#define LCD_CURSOR_ENABLE	0
#define LCD_BLINK_ENABLE	0


/* if you choose:
    LCD_4BIT_MODE you can only SEND your data on D4 to D7
	LCD_8BIT_MODE you can use all your lines from D0 to D7
*/
#define LCD_BIT_MODE		LCD_8BIT_MODE




#endif
