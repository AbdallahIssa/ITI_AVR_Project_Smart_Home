/*****************************************************************/
/*****************************************************************/
/*************	 Author  : Abdallah Issa	    ******************/
/*************	 Layer   : MCAL					******************/
/*************	 SWC   	 : TIMERS  				******************/
/*************	 Date    : 23 Sep 2022			******************/
/*************	 Version : V1.0					******************/
/*****************************************************************/
/*****************************************************************/

#ifndef MCAL_TIMER_TIMERS_CONFIG_H_
#define MCAL_TIMER_TIMERS_CONFIG_H_


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
		#define TIMER0_PRELOAD      		        224
		/*
		 * choose from these modes only:
		 * ENABLED
		 * DISABLED
		 */
		#define TIMER0_INTERRUPT_ENABLE		        ENABLED
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
	#elif TIMER0_MODE == TIMER0_PHASE_CORRECT_PWM
		#define TIMER0_PHASE_CORRECT_OC0_MODE		CLEAR_OC
	#elif TIMER0_MODE == TIMER0_FASTPWM
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

#if TIMER1_ENABLE == ENABLED
	/*
	 * choose from these modes only:
	 * TIMER_NORMAL
	 * TIMER_PHASE_CORRECT_PWM
	 * TIMER_CTC
	 * TIMER_FASTPWM
	 */
	#define TIMER1_MODE					       	 	TIMER1_FASTPWM

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
	#define TIMER1_PRESCALER    					PS_8

	#if (TIMER1_MODE == TIMER1_NORMAL) || (TIMER1_MODE == TIMER1_CTC)
		#define TIMER1_PRELOAD      		        0
	#endif


	#if TIMER1_MODE != TIMER1_NORMAL
		#if TIMER1_MODE == TIMER1_CTC
			/*
			 * choose from these modes only:
			 * ENABLED
			 * DISABLED
			 */
			#define TIMER1_INTERRUPT_ENABLE		        DISABLED
		#endif

	   /*
	    * choose from these modes only:
	    * - CHANNEL_A
	    * - CHANNEL_B
	    */
		#define TIMER1_CHANNEL CHANNEL_A

		#if TIMER1_CHANNEL == CHANNEL_A
			#define TIMER1_OCR1A_VALUE			        0
		#elif TIMER1_CHANNEL == CHANNEL_B
			#define TIMER1_OCR1B_VALUE			        0
		#else
			#error "TIMER1_CHANNEL isn't configured properly"
		#endif
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
		#define TIMER1_CTC_OC1A_MODE					DISCONNECTED_OC
		#define TIMER1_CTC_OC1B_MODE					TOGGLE_OC
	#elif TIMER1_MODE == TIMER1_PHASE_CORRECT_PWM
		#define TIMER1_PHASE_CORRECT_OC1A_MODE		    CLEAR_OC
		#define TIMER1_PHASE_CORRECT_OC1B_MODE		    CLEAR_OC
	#elif TIMER1_MODE == TIMER1_FASTPWM
		#define TIMER1_FAST_PWM_OC1A_MODE			    CLEAR_OC
		#define TIMER1_FAST_PWM_OC1B_MODE			    CLEAR_OC
	#endif

#endif


/*********************************   TIMER2   *********************************/

/*
 * choose from these modes only:
 * ENABLED
 * DISABLED
 */
#define TIMER2_ENABLE			            		ENABLED

/*
 * choose from these modes only:
 * TIMER_NORMAL
 * TIMER_PHASE_CORRECT_PWM
 * TIMER_CTC
 * TIMER_FASTPWM
 */
#if TIMER2_ENABLE == ENABLED
	#define TIMER2_MODE					       		TIMER2_FASTPWM

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
	#define TIMER2_PRESCALER    					PS_8

	#if (TIMER2_MODE == TIMER2_NORMAL) || (TIMER2_MODE == TIMER2_CTC)
		#define TIMER2_PRELOAD      		        224
		/*
		 * choose from these modes only:
		 * ENABLED
		 * DISABLED
		 */
		#define TIMER2_INTERRUPT_ENABLE		        ENABLED
	#endif

	#if TIMER2_MODE != TIMER2_NORMAL
		#define TIMER2_OCR2_VALUE			        0
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

	#if TIMER2_MODE == TIMER2_CTC
		#define TIMER2_CTC_OC2_MODE					TOGGLE_OC
	#elif TIMER2_MODE == TIMER2_PHASE_CORRECT_PWM
		#define TIMER2_PHASE_CORRECT_OC2_MODE		CLEAR_OC
	#elif TIMER2_MODE == TIMER2_FASTPWM
		#define TIMER2_FAST_PWM_OC2_MODE			CLEAR_OC
	#endif
#endif






#endif
