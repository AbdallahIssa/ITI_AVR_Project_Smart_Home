/*****************************************************************/
/*****************************************************************/
/*************	 Author  : Abdallah Issa	    ******************/
/*************	 Layer   : MCAL					******************/
/*************	 SWC   	 : ADC  				******************/
/*************	 Date    : 23 Sep 2022			******************/
/*************	 Version : V1.0					******************/
/*****************************************************************/
/*****************************************************************/

#ifndef ADC_ADC_PRIVATE_H_
#define ADC_ADC_PRIVATE_H_

#define ADMUX			                    *((volatile u8*) 0x27)
#define ADCSRA			                    *((volatile u8*) 0x26)
#define ADCL			                    *((volatile u8*) 0x24)
#define ADCH			                    *((volatile u8*) 0x25)
#define SFIOR			                    *((volatile u8*) 0x50)
#define ADC_DATA		                    *((volatile u16*) 0x24)

#define ADMUX_MUX0		                    0
#define ADMUX_MUX1		                    1
#define ADMUX_MUX2		                    2
#define ADMUX_MUX3		                    3
#define ADMUX_MUX4		                    4
#define ADMUX_ADLAR		                    5
#define ADMUX_REFS0		                    6
#define ADMUX_REFS1		                    7

#define ADCSRA_ADPS0	                    0
#define ADCSRA_ADPS1	                    1
#define ADCSRA_ADPS2	                    2
#define ADCSRA_ADIE		                    3
#define ADCSRA_ADIF		                    4
#define ADCSRA_ADATE	                    5
#define ADCSRA_ADSC		                    6
#define ADCSRA_ADEN		                    7

#define SFIOR_ADTS0		                    5
#define SFIOR_ADTS1		                    6
#define SFIOR_ADTS2		                    7


#define ADC_INTERNAL_AREF	                0
#define ADC_AVCC			                1
#define ADC_INTERNAL_2_56	                3


#define ENABLED			                    1
#define DISABLED		                    0

#define FREE_RUNNING_MODE					0
#define ANALOG_COMPARATOR					1
#define EXTERNAL_INTERRUPT_REQUEST_0		2
#define TIMER_COUNTER0_COMPARE_MATCH		3
#define TIMER_COUNTER0_OVERFLOW				4
#define TIMER_COUNTER1_COMPARE_MATCH_B		5
#define TIMER_COUNTER1_OVERFLOW				6
#define TIMER_COUNTER1_CAPTURE_EVENT		7


#define ADC0		                        0
#define ADC1                                1
#define ADC2                                2
#define ADC3                                3
#define ADC4                                4
#define ADC5                                5
#define ADC6                                6
#define ADC7                                7



#endif
