/*****************************************************************/
/*****************************************************************/
/*************	 Author  : Abdallah Issa	    ******************/
/*************	 Layer   : HAL					******************/
/*************	 SWC   	 : LCD_I2C   			******************/
/*************	 Date    : 15 Nov 2022			******************/
/*************	 Version : V1.0					******************/
/*****************************************************************/
/*****************************************************************/


#ifndef LCD_I2C_CONFIG_H_
#define LCD_I2C_CONFIG_H_

#include "../../MCAL/GPIO/GPIO_private.h"


/*
 * Here are the ports that your LCD connected to:
 * LCD_DATA_PORT : for the value of port that is connected to PIN0:PIN7 (either in 4-bit or 8-bit mode)
 * LCD_CTRL_PORT : for the direction of port that is connected to PIN0:PIN7 (either in 4-bit or 8-bit mode)
 */

#define LCD_I2C_DATA_PORT		GPIO_PORTC
#define LCD_I2C_CTRL_PORT		GPIO_PORTD

/*
 * Here are your control port pins:
 * For Setting the register select pin just set LCD_RS_PIN to PIN0:PIN7
 * For Setting the read and write pin just set LCD_RW_PIN to PIN0:PIN7
 * For Setting the enable pin just set LCD_EN_PIN to PIN0:PIN7
 */

#define LCD_I2C_RS_PIN			PIN0
#define LCD_I2C_RW_PIN			PIN1
#define LCD_I2C_EN_PIN			PIN2


/*
 * To enable the cursor just set LCD_CURSOR_ENABLE to 1
 * To enable the blinking of the cursor just set LCD_BLINK_ENABLE to 1
 */
#define LCD_I2C_CURSOR_ENABLE	0
#define LCD_I2C_BLINK_ENABLE	0







#endif
