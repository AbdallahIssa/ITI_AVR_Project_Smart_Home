/*****************************************************************/
/*****************************************************************/
/*************	 Author  : Abdallah Issa	    ******************/
/*************	 Layer   : MCAL					******************/
/*************	 SWC   	 : ADC  				******************/
/*************	 Date    : 23 Sep 2022			******************/
/*************	 Version : V1.0					******************/
/*****************************************************************/
/*****************************************************************/

#ifndef ADC_ADC_CONFIG_H_
#define ADC_ADC_CONFIG_H_
/*
 * choose from the followings:
 * ADC_INTERNAL_AREF
 * ADC_AVCC
 * ADC_INTERNAL_2_56
 */
#define ADC_REFERENCE_VOLTAGE	ADC_AVCC

/*
 * choose from the followings:
 * ENABLED :  if you want to serve interrupts after completion.
 * DISABLED : if you entered Single Conversion Mode.
 */
#define INTERRUPT_ENABLE		DISABLED

/*
 * choose from the followings:
 * ENABLED
 * DISABLED
 */
#define AUTO_TRIGGERRING_ENABLE		DISABLED

/*
 * choose from the followings:
 * FREE_RUNNING_MODE
 * ANALOG_COMPARATOR
 * EXTERNAL_INTERRUPT_REQUEST_0
 * TIMER_COUNTER0_COMPARE_MATCH
 * TIMER_COUNTER0_OVERFLOW
 * TIMER_COUNTER1_COMPARE_MATCH_B
 * TIMER_COUNTER1_OVERFLOW
 * TIMER_COUNTER1_CAPTURE_EVENT
 */

#if AUTO_TRIGGERRING_ENABLE == ENABLED
	#define AUTO_TRIGGERRING_SOURCE		FREE_RUNNING_MODE
#endif

#endif
