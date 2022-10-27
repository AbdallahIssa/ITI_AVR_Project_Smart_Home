#include "../GPIO/GPIO_private.h"
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"


void GPIO_vSetPortDirection(u8 Copy_u8Port, u8 Copy_u8Direction)
{
	switch(Copy_u8Port)
	{
	case GPIO_PORTA:
		DDRA = Copy_u8Direction;
		break;
	case GPIO_PORTB:
		DDRB = Copy_u8Direction;
		break;
	case GPIO_PORTC:
		DDRC = Copy_u8Direction;
		break;
	case GPIO_PORTD:
		DDRD = Copy_u8Direction;
		break;
	default:
		/* Wrong GPIO port */
		break;
	}
}

void GPIO_vSetPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Direction)
{
	if(Copy_u8Pin <= PIN7)
	{
		if(Copy_u8Direction == OUTPUT_PIN)
		{
			switch(Copy_u8Port)
			{
			case GPIO_PORTA:
				SET_BIT(DDRA, Copy_u8Pin);
				break;
			case GPIO_PORTB:
				SET_BIT(DDRB, Copy_u8Pin);
				break;
			case GPIO_PORTC:
				SET_BIT(DDRC, Copy_u8Pin);
				break;
			case GPIO_PORTD:
				SET_BIT(DDRD, Copy_u8Pin);
				break;
			default:
				/* Wrong GPIO port */
				break;
			}
		}
		else if(Copy_u8Direction == INPUT_PIN)
		{
			switch(Copy_u8Port)
			{
			case GPIO_PORTA:
				CLEAR_BIT(DDRA, Copy_u8Pin);
				break;
			case GPIO_PORTB:
				CLEAR_BIT(DDRB, Copy_u8Pin);
				break;
			case GPIO_PORTC:
				CLEAR_BIT(DDRC, Copy_u8Pin);
				break;
			case GPIO_PORTD:
				CLEAR_BIT(DDRD, Copy_u8Pin);
				break;
			default:
				/* Wrong GPIO port */
				break;
			}
		}
		else
		{
			/*#error "You Enter Wrong Direction"*/
		}
	}
	else
	{
		/* You Enter Wrong PIN */
	}

}


void GPIO_vSetPortValue(u8 Copy_u8Port, u8 Copy_u8Value)
{
	switch(Copy_u8Port)
	{
		case GPIO_PORTA:
			PORTA = Copy_u8Value;
			break;
		case GPIO_PORTB:
			PORTB = Copy_u8Value;
			break;
		case GPIO_PORTC:
			PORTC = Copy_u8Value;
			break;
		case GPIO_PORTD:
			PORTD = Copy_u8Value;
			break;
		default:
			/* Wrong GPIO port */
			break;
	}
}

void GPIO_vSetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value)
{
	if(Copy_u8Pin <= PIN7)
	{
		if(Copy_u8Value == HIGH)
		{
			switch(Copy_u8Port)
			{
			case GPIO_PORTA:
				SET_BIT(PORTA, Copy_u8Pin);
				break;
			case GPIO_PORTB:
				SET_BIT(PORTB, Copy_u8Pin);
				break;
			case GPIO_PORTC:
				SET_BIT(PORTC, Copy_u8Pin);
				break;
			case GPIO_PORTD:
				SET_BIT(PORTD, Copy_u8Pin);
				break;
			default:
				/* You Enter Wrong GPIO port */
				break;
			}
		}
		else if(Copy_u8Value == LOW)
		{
			switch(Copy_u8Port)
			{
			case GPIO_PORTA:
				CLEAR_BIT(PORTA, Copy_u8Pin);
				break;
			case GPIO_PORTB:
				CLEAR_BIT(PORTB, Copy_u8Pin);
				break;
			case GPIO_PORTC:
				CLEAR_BIT(PORTC, Copy_u8Pin);
				break;
			case GPIO_PORTD:
				CLEAR_BIT(PORTD, Copy_u8Pin);
				break;
			default:
				/* You Enter Wrong GPIO port */
				break;
			}
		}
		else
		{
			/* Wrong Copy_u8Value */
		}
	}
	else
	{
		/* You Enter Wrong PIN */
	}
}


u8 GPIO_u8GetPortValue(u8 Copy_u8Port)
{
	u8 Local_u8Result = 0;
	switch(Copy_u8Port)
	{
	case GPIO_PORTA:
		Local_u8Result = PINA;
		break;
	case GPIO_PORTB:
		Local_u8Result = PINB;
		break;
	case GPIO_PORTC:
		Local_u8Result = PINC;
		break;
	case GPIO_PORTD:
		Local_u8Result = PIND;
		break;
	default:
		/* You Enter Wrong GPIO port */
		break;
	}
	return Local_u8Result;
}


u8 GPIO_u8GetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin)
{
	u8 Local_u8Result = 0;
	if(Copy_u8Pin <= PIN7)
	{
		switch (Copy_u8Port)
		{
		case GPIO_PORTA:
			Local_u8Result = GET_BIT(PINA, Copy_u8Pin);
			break;
		case GPIO_PORTB:
			Local_u8Result = GET_BIT(PINB, Copy_u8Pin);
			break;
		case GPIO_PORTC:
			Local_u8Result = GET_BIT(PINC, Copy_u8Pin);
			break;
		case GPIO_PORTD:
			Local_u8Result = GET_BIT(PIND, Copy_u8Pin);
			break;
		default:
			/* You Enter Wrong GPIO port */
			break;
		}
	}
	else
	{
		/* You Enter Wrong PIN */
	}
	return Local_u8Result;
}
