/*****************************************************************/
/*****************************************************************/
/*************	 Author  : Abdallah Issa	    ******************/
/*************	 Layer   : MCAL					******************/
/*************	 SWC   	 : ADC  				******************/
/*************	 Date    : 23 Sep 2022			******************/
/*************	 Version : V1.0					******************/
/*****************************************************************/
/*****************************************************************/

#ifndef ADC_ADC_INTERFACE_H_
#define ADC_ADC_INTERFACE_H_


typedef enum{
	ADC_Channel_0 = 0,
	ADC_Channel_1,
	ADC_Channel_2,
	ADC_Channel_3,
	ADC_Channel_4,
	ADC_Channel_5,
	ADC_Channel_6,
	ADC_Channel_7,
}ADC_Channel_t;

void ADC_vInit(void);

void ADC_vEnable(void);

void ADC_vDisable(void);

u16 ADC_u16ReadDigitalValue_Sync(ADC_Channel_t Copy_ChannelId); // For Sync. (Polling)

void ADC_vStartConversion(ADC_Channel_t Copy_ChannelId);

u16 ADC_u16ReadDigitalValue_Async(ADC_Channel_t Copy_ChannelId); // For Async. (Interrupt)

void ADC_vEnableInterrupt(void);

void ADC_vDisableInterrupt(void);

void ADC_vCallBack(void (*fptr)(void));






#endif
