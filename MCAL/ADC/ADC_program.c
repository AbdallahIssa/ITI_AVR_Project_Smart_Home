#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "ADC_interface.h"
#include "ADC_private.h"
#include "ADC_config.h"


static void (*GS_ADC_Complete_Callback)(void);

void ADC_vInit(void)
{
	//1- reference voltage through ADMUX
	#if ADC_REFERENCE_VOLTAGE == ADC_INTERNAL_AREF
		CLEAR_BIT(ADMUX, ADMUX_REFS0);
		CLEAR_BIT(ADMUX, ADMUX_REFS1);
	#elif ADC_REFERENCE_VOLTAGE == ADC_AVCC
		SET_BIT(ADMUX, ADMUX_REFS0);
		CLEAR_BIT(ADMUX, ADMUX_REFS1);
	#elif ADC_REFERENCE_VOLTAGE == ADC_INTERNAL_2_56
		SET_BIT(ADMUX, ADMUX_REFS0);
		SET_BIT(ADMUX, ADMUX_REFS1);
	#else
		#error "You entered invalid ADC_REFERENCE_VOLTAGE value"
	#endif

	//2- ALWAYS adjustment right (10-bit precision)
	CLEAR_BIT(ADMUX, ADMUX_ADLAR);

	//3- Enable ADC prepherial
	SET_BIT(ADCSRA, ADCSRA_ADEN);

	//4- Enable/Disable Interrupt
	#if INTERRUPT_ENABLE == ENABLED
		SET_BIT(ADCSRA, ADCSRA_ADIE);
	#elif INTERRUPT_ENABLE == DISABLED
		CLEAR_BIT(ADCSRA, ADCSRA_ADIE);
	#else
		#error "You entered invalid INTERRUPT_ENABLE value"
	#endif

	//5- Auto trigger config.
	#if AUTO_TRIGGERRING_ENABLE == ENABLED
		//ADC Auto Trigger Enable
		SET_BIT(ADCSRA, ADCSRA_ADATE);
		//choose the Trigger source
		SFIOR &= ~(0b11100000);
		SFIOR |= (AUTO_TRIGGERRING_SOURCE << 5);
	#elif AUTO_TRIGGERRING_ENABLE == DISABLED
		//ADC Auto Trigger Disable
		CLEAR_BIT(ADCSRA, ADCSRA_ADATE);
	#else
		#error "You entered invalid AUTO_TRIGGERRING_ENABLE value"
	#endif


}

u16 ADC_u16ReadDigitalValue_Sync(ADC_Channel_t Copy_ChannelId)
{
	//1- Select Channel.
	ADMUX &= ~(0b00011111);
	ADMUX |= (Copy_ChannelId & 0x07);// ANDing with 0x07 For kind of input validation
	//2- start conversion.
	SET_BIT(ADCSRA, ADCSRA_ADSC);
	//3- waiting for the completion of ADC conversion.
	while(GET_BIT(ADCSRA, ADCSRA_ADSC));
	//4- clear flag by writing one
	SET_BIT(ADCSRA, ADCSRA_ADIF);
	//5- get the value inside the ADCL and ADCH with pointer to them.
	return ADC_DATA;
}



void ADC_vStartConversion(ADC_Channel_t Copy_ChannelId)
{
	//1- Select Channel.
	ADMUX &= ~(0b00011111);
	ADMUX |= (Copy_ChannelId & 0x07);// ANDing with 0x07 For kind of input validation
	//2- start conversion.
	SET_BIT(ADCSRA, ADCSRA_ADSC);
}

u16 ADC_u16ReadDigitalValue_Async(ADC_Channel_t Copy_ChannelId)
{
	ADMUX &= ~(0b00011111);
	ADMUX |= (Copy_ChannelId & 0x07);// ANDing with 0x07 For kind of input validation
	return ADC_DATA;
}

void ADC_vEnableInterrupt(void)
{
	SET_BIT(ADCSRA, ADCSRA_ADIE);
}
void ADC_vDisableInterrupt(void)
{
	CLEAR_BIT(ADCSRA, ADCSRA_ADIE);
}

void ADC_vEnable(void)
{
	SET_BIT(ADCSRA, ADCSRA_ADEN);
}
void ADC_vDisable(void)
{
	CLEAR_BIT(ADCSRA, ADCSRA_ADEN);
}


void __vector_16(void) __attribute__((signal));

void __vector_16(void)
{
	if(GS_ADC_Complete_Callback != NULL)
	{
		GS_ADC_Complete_Callback();
	}
}
void ADC_vCallBack(void(*Copy_pfun)(void))
{
	GS_ADC_Complete_Callback = Copy_pfun;
}













