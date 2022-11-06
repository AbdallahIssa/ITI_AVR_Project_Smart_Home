#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../GPIO/GPIO_interface.h"
#include "../EXTI/EXTI_interface.h"
#include "../EXTI/EXTI_private.h"
#include "../EXTI/EXTI_config.h"


static void (*GS_EXTI0_Callback)(void);
static void (*GS_EXTI1_Callback)(void);
static void (*GS_EXTI2_Callback)(void);


void EXTI_vEnable(EXTI_Source_t Copy_u8ExtIntNum, EXTI_Edge_Interrupt_Source_t Copy_u8EdgeIntSource)
{
	switch(Copy_u8ExtIntNum)
	{
	case EXTI_INT0:
		//Input Direction
		GPIO_vSetPinDirection(GPIO_PORTD, PIN2, INPUT_PIN);
		//Set the sense control
		EXTI_vSetSenseCtrl(EXTI_INT0, Copy_u8EdgeIntSource);
		//Enable Interrupt
		SET_BIT(GICR, GICR_INT0);
		break;
	case EXTI_INT1:
		//Input Direction
		GPIO_vSetPinDirection(GPIO_PORTD, PIN3, INPUT_PIN);
		//Set the sense control
		EXTI_vSetSenseCtrl(EXTI_INT1, Copy_u8EdgeIntSource);
		//Enable Interrupt
		SET_BIT(GICR, GICR_INT1);
		break;
	case EXTI_INT2:
		//Input Direction
		GPIO_vSetPinDirection(GPIO_PORTB, PIN2, INPUT_PIN);
		//Set the sense control
		EXTI_vSetSenseCtrl(EXTI_INT2, Copy_u8EdgeIntSource);
		//Enable Interrupt
		SET_BIT(GICR, GICR_INT2);
		break;
	default:
		/* Error Invalid EXTI number */
		break;
	}
}

void EXTI_vDisable(EXTI_Source_t Copy_u8ExtIntNum)
{
	switch (Copy_u8ExtIntNum)
	{
		case EXTI_INT0:
			CLEAR_BIT(GICR, GICR_INT0);
			break;
		case EXTI_INT1:
			CLEAR_BIT(GICR, GICR_INT1);
			break;
		case EXTI_INT2:
			CLEAR_BIT(GICR, GICR_INT2);
			break;
		default:
			/* Error Invalid EXTI number */
			break;
	}
}




void EXTI_vSetSenseCtrl(EXTI_Source_t Copy_u8ExtIntNum, EXTI_Edge_Interrupt_Source_t Copy_u8EdgeIntSource)
{
	switch(Copy_u8ExtIntNum)
	{
	case EXTI_INT0:
		switch(Copy_u8EdgeIntSource)
		{
		case EXTI_ON_CHANGE:
			CLEAR_BIT(MCUCR,MCUCR_ISC01);
			SET_BIT(MCUCR,MCUCR_ISC00);
			break;
		case EXTI_FALLING_EDGE:
			SET_BIT(MCUCR,MCUCR_ISC01);
			CLEAR_BIT(MCUCR,MCUCR_ISC00);
			break;
		case EXTI_RISING_EDGE:
			SET_BIT(MCUCR,MCUCR_ISC01);
			SET_BIT(MCUCR,MCUCR_ISC00);
			break;
		case EXTI_LOW_LEVEL:
			CLEAR_BIT(MCUCR,MCUCR_ISC01);
			CLEAR_BIT(MCUCR,MCUCR_ISC00);
			break;
		default:
			/* Error Invalid EdgeIntSource */
			break;
		}
		break;
	case EXTI_INT1:
		switch(Copy_u8EdgeIntSource)
		{
		case EXTI_ON_CHANGE:
			CLEAR_BIT(MCUCR,MCUCR_ISC11);
			SET_BIT(MCUCR,MCUCR_ISC10);

			break;
		case EXTI_FALLING_EDGE:
			SET_BIT(MCUCR,MCUCR_ISC11);
			CLEAR_BIT(MCUCR,MCUCR_ISC10);
			break;
		case EXTI_RISING_EDGE:
			SET_BIT(MCUCR,MCUCR_ISC11);
			SET_BIT(MCUCR,MCUCR_ISC10);
			break;
		case EXTI_LOW_LEVEL:
			CLEAR_BIT(MCUCR,MCUCR_ISC11);
			CLEAR_BIT(MCUCR,MCUCR_ISC10);
			break;
		default:
			/* Error Invalid EdgeIntSource */
			break;
		}
		break;
	case EXTI_INT2:
		switch(Copy_u8EdgeIntSource)
		{
		case EXTI_FALLING_EDGE:
			CLEAR_BIT(MCUCSR,MCUCSR_ISC2);
			break;
		case EXTI_RISING_EDGE:
			SET_BIT(MCUCSR,MCUCSR_ISC2);
			break;
		default:
			/* Error Invalid EdgeIntSource */
			break;
		}
		break;
	default:
		/* Error Invalid EXTI number */
		break;
	}
}

void __vector_1(void) __attribute__((signal));
void __vector_2(void) __attribute__((signal));
void __vector_3(void) __attribute__((signal));


void __vector_1(void)
{
	if(GS_EXTI0_Callback != NULL)
	{
		GS_EXTI0_Callback();
	}
}

void __vector_2(void)
{
	if(GS_EXTI1_Callback != NULL)
	{
		GS_EXTI1_Callback();
	}
}

void __vector_3(void)
{
	if(GS_EXTI2_Callback != NULL)
	{
		GS_EXTI2_Callback();
	}
}

void EXTI_vSetCallBack(EXTI_Source_t Copy_u8ExtIntNum, void(*Copy_pfun)(void))
{
	switch (Copy_u8ExtIntNum) {
		case EXTI_INT0:
			GS_EXTI0_Callback = Copy_pfun;
			break;
		case EXTI_INT1:
			GS_EXTI1_Callback = Copy_pfun;
			break;
		case EXTI_INT2:
			GS_EXTI2_Callback = Copy_pfun;
			break;
		default:
			/* Error Invalid EXTI number */
			break;
	}
}



