/*****************************************************************/
/*****************************************************************/
/*************	 Author  : Abdallah Issa	    ******************/
/*************	 Layer   : MCAL					******************/
/*************	 SWC   	 : TIMERS  				******************/
/*************	 Date    : 23 Sep 2022			******************/
/*************	 Version : V1.0					******************/
/*****************************************************************/
/*****************************************************************/

#ifndef TIMERS_CONFIG_H_
#define TIMERS_CONFIG_H_


/*********************************   TIMER0   *********************************/
/*
 * choose from these modes only:
 * ENABLED
 * DISABLED
 */
#define TIMER0_ENABLE			            DISABLED

/*
 * choose from these modes only:
 * TIMER_NORMAL
 * TIMER_PHASE_CORRECT_PWM
 * TIMER_CTC
 * TIMER_FASTPWM
 */
#if TIMER0_ENABLE == ENABLED
	#define TIMER0_MODE					       		TIMER0_FASTPWM

	/*
	 * choose from these modes only:
	 * PS_NOCLK
	 * PS_1
	 * PS_8
	 * PS_64
	 * PS_256
	 * PS_1024
	 * PS_EXT_T0_FALIING
	 * PS_EXT_T0_RISING
	 */
	#define TIMER0_PRESCALER    					PS_8

	#if (TIMER0_MODE == TIMER0_NORMAL) || (TIMER0_MODE == TIMER0_CTC)
		#define TIMER0_PRELOAD      		        0
		/*
		 * choose from these modes only:
		 * ENABLED
		 * DISABLED
		 */
		#define TIMER0_INTERRUPT_ENABLE		        DISABLED
	#endif

	#if TIMER0_MODE != TIMER0_NORMAL
		#define TIMER0_OCR0_VALUE			        0
	#endif

	/*
	 * choose from these modes only:
	 * DISCONNECTED_OC
	 * TOGGLE_OC
	 * CLEAR_OC
	 * SET_OC
	 *
	 * please note that, In case of Fast PWM :
	 * - Clear OC has the meaning of non-Inverting mode
	 * - Set OC has the meaning of Inverting mode
	 */

	#if TIMER0_MODE == TIMER0_CTC
		#define TIMER0_CTC_OC0_MODE					TOGGLE_OC
	#endif

	#if TIMER0_MODE == TIMER0_PHASE_CORRECT_PWM
		#define TIMER0_PHASE_CORRECT_OC0_MODE		CLEAR_OC
	#endif

	#if TIMER0_MODE == TIMER0_FASTPWM
		#define TIMER0_FAST_PWM_OC0_MODE			CLEAR_OC
	#endif
#endif





/*********************************   TIMER1   *********************************/

/*
 * choose from these modes only:
 * ENABLED
 * DISABLED
 */
#define TIMER1_ENABLE			            		ENABLED

/*
 * choose from these modes only:
 * TIMER_NORMAL
 * TIMER_PHASE_CORRECT_PWM
 * TIMER_CTC
 * TIMER_FASTPWM
 */
#if TIMER1_ENABLE == ENABLED
	#define TIMER1_MODE					       	 	TIMER1_NORMAL

	/*
	 * choose from these modes only:
	 * PS_NOCLK
	 * PS_1
	 * PS_8
	 * PS_64
	 * PS_256
	 * PS_1024
	 * PS_EXT_T0_FALIING
	 * PS_EXT_T0_RISING
	 */
	#define TIMER0_PRESCALER    					PS_8

	#if (TIMER1_MODE == TIMER1_NORMAL) || (TIMER0_MODE == TIMER1_CTC)
		#define TIMER1_PRELOAD      		        0
		/*
		 * choose from these modes only:
		 * ENABLED
		 * DISABLED
		 */
		#define TIMER1_INTERRUPT_ENABLE		        DISABLED
	#endif

	#if TIMER1_MODE != TIMER1_NORMAL
		#define TIMER1_OCR0_VALUE			        0
	#endif

	/*
	 * choose from these modes only:
	 * DISCONNECTED_OC
	 * TOGGLE_OC
	 * CLEAR_OC
	 * SET_OC
	 *
	 * please note that, In case of Fast PWM :
	 * - Clear OC has the meaning of non-Inverting mode
	 * - Set OC has the meaning of Inverting mode
	 */

	#if TIMER1_MODE == TIMER1_CTC
		#define TIMER1_CTC_OC0_MODE					TOGGLE_OC
	#endif

	#if TIMER1_MODE == TIMER1_PHASE_CORRECT_PWM
		#define TIMER1_PHASE_CORRECT_OC0_MODE		CLEAR_OC
	#endif

	#if TIMER1_MODE == TIMER1_FASTPWM
		#define TIMER1_FAST_PWM_OC0_MODE			CLEAR_OC
	#endif
#endif


/*********************************   TIMER2   *********************************/

//TODO : TIMER2 Config.





#endif
