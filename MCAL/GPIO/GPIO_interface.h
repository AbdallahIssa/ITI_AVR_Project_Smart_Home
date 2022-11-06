/*****************************************************************/
/*****************************************************************/
/*************	 Author  : Abdallah Issa	    ******************/
/*************	 Layer   : MCAL					******************/
/*************	 SWC   	 : GPIO  				******************/
/*************	 Date    : 12 Sep 2022			******************/
/*************	 Version : V1.0					******************/
/*****************************************************************/
/*****************************************************************/

#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_

#include "../../LIB/STD_TYPES.h"
#include "GPIO_private.h"

/*
  Generally:

  For Copy_u8Port you can choose only 4 ports options:
  GPIO_PORTA
  GPIO_PORTB
  GPIO_PORTC
  GPIO_PORTD

  For Copy_u8Pin you can choose only 7 pins options:
   PIN0
   PIN1
   PIN2
   PIN3
   PIN4
   PIN5
   PIN6
   PIN7
*/




/* For Copy_u8Direction you can choose between:
   OUTPUT_PORT to make all the port pins output
   INPUT_PORT  to make all the port pins input
   or you can add any value to set the port as you need (any value like : 0xA5)
*/
void GPIO_vSetPortDirection(u8 Copy_u8Port, u8 Copy_u8Direction);


/* For Copy_u8Direction you can choose only between:
   OUTPUT_PIN to make this pin as output pin
   INPUT_PIN  to make this pin as input pin
*/
void GPIO_vSetPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Direction);

/* For Copy_u8Value you can choose between:
   OUTPUT_PORT to make all the port pins output high signal
   INPUT_PORT  to make all the port pins output low signal
   or you can add any value to set the port as you need (any value like : 0xA5)
*/
void GPIO_vSetPortValue(u8 Copy_u8Port, u8 Copy_u8Value);

/* For Copy_u8Value you can choose only between:
   HIGH to make this pin output high signal
   LOW  to make this pin output low signal
*/
void GPIO_vSetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value);


/* This function returns the value of the specific port */
u8 GPIO_u8GetPortValue(u8 Copy_u8Port);
/* This function returns the value of the pin on the specific port */
u8 GPIO_u8GetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin);



#endif
