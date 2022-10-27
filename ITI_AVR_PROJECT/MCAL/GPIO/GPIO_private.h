/*****************************************************************/
/*****************************************************************/
/*************	 Author  : Abdallah Issa	    ******************/
/*************	 Layer   : MCAL					******************/
/*************	 SWC   	 : GPIO  				******************/
/*************	 Date    : 12 Sep 2022			******************/
/*************	 Version : V1.0					******************/
/*****************************************************************/
/*****************************************************************/

#ifndef GPIO_PRIVATE_H_
#define GPIO_PRIVATE_H_

#include "../../LIB/STD_TYPES.h"

#define OUTPUT_PORT		0xFF
#define INPUT_PORT		0x00


#define OUTPUT_PIN		1
#define INPUT_PIN		0


#define	GPIO_PORTA		1
#define	GPIO_PORTB		2
#define	GPIO_PORTC		3
#define	GPIO_PORTD		4


#define PIN0    		0
#define PIN1            1
#define PIN2            2
#define PIN3            3
#define PIN4            4
#define PIN5            5
#define PIN6            6
#define PIN7			7


#define HIGH 			1
#define LOW		 		0


#define PORTA	*((volatile u8*)0x3B)
#define DDRA	*((volatile u8*)0x3A)
#define PINA	*((volatile u8*)0x39)

#define PORTB	*((volatile u8*)0x38)
#define DDRB	*((volatile u8*)0x37)
#define PINB	*((volatile u8*)0x36)

#define PORTC	*((volatile u8*)0x35)
#define DDRC	*((volatile u8*)0x34)
#define PINC	*((volatile u8*)0x33)

#define PORTD	*((volatile u8*)0x32)
#define DDRD	*((volatile u8*)0x31)
#define PIND	*((volatile u8*)0x30)


#endif
