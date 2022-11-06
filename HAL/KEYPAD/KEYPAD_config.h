/*****************************************************************/
/*****************************************************************/
/*************	 Author  : Abdallah Issa	    ******************/
/*************	 Layer   : HAL					******************/
/*************	 SWC   	 : KEYPAD  				******************/
/*************	 Date    : 11 May 2022			******************/
/*************	 Version : V1.0					******************/
/*****************************************************************/
/*****************************************************************/


#ifndef KEYPAD_KEYPAD_CONFIG_H_
#define KEYPAD_KEYPAD_CONFIG_H_

#include "../../MCAL/GPIO/GPIO_interface.h"


/*
 * Choose between these values only:
 * - GPIO_PORTA
 * - GPIO_PORTB
 * - GPIO_PORTC
 * - GPIO_PORTD
 */
#define KEYPAD_PORT				GPIO_PORTB

/*
 * Choose between these values only:
 * - HIGH_NIBBLE
 * - LOW_NIBBLE
 */
#define KEYPAD_PORT_INPUT		HIGH_NIBBLE

#define ROWS_NO		     		4
#define COLUMNS_NO				4




#endif /* KEYPAD_KEYPAD_CONFIG_H_ */
