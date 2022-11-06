/*****************************************************************/
/*****************************************************************/
/*************	 Author  : Abdallah Issa	    ******************/
/*************	 Layer   : MCAL					******************/
/*************	 SWC   	 : TIMERS  				******************/
/*************	 Date    : 23 Sep 2022			******************/
/*************	 Version : V1.0					******************/
/*****************************************************************/
/*****************************************************************/

#ifndef MCAL_TIMER_TIMERS_PRIVATE_H_
#define MCAL_TIMER_TIMERS_PRIVATE_H_
/*********************************   TIMER0   *********************************/
//TIMER0 Registers
#define TCNT0                           *((volatile u8*)(0x52))
#define TCCR0                           *((volatile u8*)(0x53))
#define OCR0                            *((volatile u8*)(0x5C))

//TIMER0 bits
#define TCCR0_CS00		                0
#define TCCR0_CS01		                1
#define TCCR0_CS02		                2
#define TCCR0_WGM01		                3
#define TCCR0_COM00		                4
#define TCCR0_COM01		                5
#define TCCR0_WGM00		                6
#define TCCR0_FOC0		                7

#define TIMSK_TOIE0		                0
#define TIMSK_OCIE0		                1

//Timer0 Modes
#define TIMER0_NORMAL					1
#define TIMER0_PHASE_CORRECT_PWM		2
#define TIMER0_CTC						3
#define TIMER0_FASTPWM					4


/*********************************   TIMER1   *********************************/

//TIMER1 Registers
#define TCCR1A                          *((volatile u8*)(0x4F))
#define TCCR1B                          *((volatile u8*)(0x4E))
#define TCNT1                           *((volatile u16*)(0x4C))
#define OCR1A                         	*((volatile u16*)(0x4A))
#define OCR1B                           *((volatile u16*)(0x48))
#define ICR1                            *((volatile u16*)(0x46))//Top value can be changed through this register in FastPWM mode

//TIMER1 bits
#define TCCR1A_WGM10					0
#define TCCR1A_WGM11					1
#define TCCR1A_FOC1B					2
#define TCCR1A_FOC1A					3
#define TCCR1A_COM1B0					4
#define TCCR1A_COM1B1					5
#define TCCR1A_COM1A0					6
#define TCCR1A_COM1A1					7

#define TCCR1B_CS10						0
#define TCCR1B_CS11						1
#define TCCR1B_CS12						2
#define TCCR1B_WGM12					3
#define TCCR1B_WGM13					4
#define TCCR1B_ICES1					6
#define TCCR1B_ICNC1					7

#define TIMSK_TOIE1			            2
#define TIMSK_OCIE1B		            3
#define TIMSK_OCIE1A		            4
#define TIMSK_TICIE1		            5

//Timer1 Modes
#define TIMER1_NORMAL					1
#define TIMER1_PHASE_CORRECT_PWM		2
#define TIMER1_CTC						3
#define TIMER1_FASTPWM					4

//Timer1 Channels
#define CHANNEL_A						1
#define CHANNEL_B						2

/*********************************   TIMER2   *********************************/

//TIMER2 Registers
#define TCNT2                           *((volatile u8*)(0x44))
#define TCCR2                           *((volatile u8*)(0x45))
#define OCR2                            *((volatile u8*)(0x43))

//TIMER0 bits
#define TCCR2_CS20		                0
#define TCCR2_CS21		                1
#define TCCR2_CS22		                2
#define TCCR2_WGM21		                3
#define TCCR2_COM20		                4
#define TCCR2_COM21		                5
#define TCCR2_WGM20		                6
#define TCCR2_FOC2		                7

#define TIMSK_TOIE2		                6
#define TIMSK_OCIE2		                7

//Timer2 Modes
#define TIMER2_NORMAL					1
#define TIMER2_PHASE_CORRECT_PWM		2
#define TIMER2_CTC						3
#define TIMER2_FASTPWM					4


/*********************************   TIMER interrupt Register   *********************************/
// I put it here because it doesn't belong to a specific timer
#define TIMSK                          *((volatile u8*)(0x59))
#define TIFR                           *((volatile u8*)(0x58))


/*********************************   Prescaler   *********************************/
#define PS_NOCLK	                    0b000
#define PS_1		                    0b001
#define PS_8		                    0b010
#define PS_64		                    0b011
#define PS_256		                    0b100
#define PS_1024		                    0b101
#define PS_EXT_T0_FALIING		        0b110
#define PS_EXT_T0_RISING			    0b111


/*********************************   ENABLED/DISABLED   *********************************/
#define ENABLED							1
#define DISABLED						0


/*********************************   Compare output modes   *********************************/
#define DISCONNECTED_OC					1
#define TOGGLE_OC				        2
#define CLEAR_OC				        3	//In case of Fast PWM : Clear OC has the meaning of non-Inverting mode
#define SET_OC					        4	//In case of Fast PWM : Set OC has the meaning of Inverting mode




#endif
