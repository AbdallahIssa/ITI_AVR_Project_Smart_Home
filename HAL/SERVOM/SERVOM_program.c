#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/GPIO/GPIO_interface.h"
#include "../../MCAL/TIMER/TIMERS_interface.h"

#include "SERVOM_interface.h"
#include "SERVOM_private.h"
#include "SERVOM_config.h"

void SERVOM_vInit()
{
	GPIO_vSetPinDirection(APP_SERVOM_PORT, APP_SERVOM_PIN, OUTPUT_PIN);
	TIMERS_vSetICR(DUTY_CYCLE_PERIOD);//TOP Value for the Timer
}


void SERVOM_vStart(u8 Copy_u8Angle)
{
	u16 mappedValue = (Copy_u8Angle/0.18F) + 1000;
	TIMERS_vSetCompareMatchValue(SERVOM_TIMER, SERVOM_TIMER_Channel, mappedValue);
}

void SERVOM_vStop(void)
{
	TIMERS_vSetCompareMatchValue(SERVOM_TIMER, SERVOM_TIMER_Channel, 1000);
}


