/*****************************************************************/
/*****************************************************************/
/*************	 Author  : Abdallah Issa	    ******************/
/*************	 Layer   : MCAL					******************/
/*************	 SWC   	 : TIMERS  				******************/
/*************	 Date    : 23 Sep 2022			******************/
/*************	 Version : V1.0					******************/
/*****************************************************************/
/*****************************************************************/

#ifndef MCAL_TIMER_TIMERS_INTERFACE_H_
#define MCAL_TIMER_TIMERS_INTERFACE_H_

typedef enum
{
	TIMER0,
	TIMER1,
	TIMER2,
}TIMER_TYPE_t;

typedef enum
{
	Channel_A,
	Channel_B,
}TIMER1_Channel_t;

void TIMERS_vInit(void);
/*
 * for TimerId you can choose:
 * 	- TIMER0
 * 	- TIMER1
 * 	- TIMER2
 */
void TIMERS_vStartTimer(TIMER_TYPE_t TimerId);

void TIMERS_vStopTimer(TIMER_TYPE_t TimerId);

void TIMERS_vSetCallback(TIMER_TYPE_t TimerId,void (*Copy_Fptr)(void));

void TIMERS_vSetPreloadValue(TIMER_TYPE_t TimerId, u16 Copy_u16Preload);

/*
 * for Copy_u16OcrChannel you can choose:
 * 		0 : For TIMER0 because there is no channels just one OCR0
 * 		Channel_A : For TIMER1 channel A
 * 		Channel_B : For TIMER1 channel B
 */
void TIMERS_vSetCompareMatchValue(TIMER_TYPE_t TimerId, TIMER1_Channel_t Copy_u16OcrChannel, u16 Copy_u16OcrVal);

void TIMERS_vSetICR(u16 Copy_16IcrValue);

void TIMERS_vSetBusyWait_sync(TIMER_TYPE_t TimerId, u32 Copy_u32Ticks);

#endif
