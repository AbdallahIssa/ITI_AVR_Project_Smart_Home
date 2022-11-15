#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "TIMERS_interface.h"
#include "TIMERS_private.h"
#include "TIMERS_config.h"



static void (*GS_TIMER0_OVF_CallBack)(void);
static void (*GS_TIMER0_COM_CallBack)(void);
static void (*GS_TIMER1_OVF_CallBack)(void);
static void (*GS_TIMER1_COMA_CallBack)(void);
static void (*GS_TIMER1_COMB_CallBack)(void);

static void (*GS_TIMER2_OVF_CallBack)(void);
static void (*GS_TIMER2_COM_CallBack)(void);

void TIMERS_vInit(void)
{
	#if TIMER0_ENABLE == ENABLED
		#if TIMER0_MODE == TIMER0_NORMAL
			//1- Waveform Generation Mode
			CLEAR_BIT(TCCR0, TCCR0_WGM00);
			CLEAR_BIT(TCCR0, TCCR0_WGM01);
			//2- Compare Output Mode : No compare Output mode in normal mode(OC0 disconnected)
			CLEAR_BIT(TCCR0, TCCR0_COM00);
			CLEAR_BIT(TCCR0, TCCR0_COM01);
			//3- Here No OCR0 value
			//4- Preload
			TCNT0 = TIMER0_PRELOAD;
			//5- Interrupt Enable/Disable
			#if TIMER0_INTERRUPT_ENABLE == ENABLED
				SET_BIT(TIMSK, TIMSK_TOIE0);
			#elif TIMER0_INTERRUPT_ENABLE == DISABLED
				CLEAR_BIT(TIMSK, TIMSK_TOIE0);
			#endif


		#elif TIMER0_MODE == TIMER0_CTC
			//1- Waveform Generation Mode
			CLEAR_BIT(TCCR0, TCCR0_WGM00);
			SET_BIT(TCCR0, TCCR0_WGM01);
			//2- Compare Output Mode
			#if TIMER0_CTC_OC0_MODE == DISCONNECTED_OC
				CLEAR_BIT(TCCR0, TCCR0_COM00);
				CLEAR_BIT(TCCR0, TCCR0_COM01);
			#elif TIMER0_CTC_OC0_MODE == TOGGLE_OC
				SET_BIT(TCCR0, TCCR0_COM00);
				CLEAR_BIT(TCCR0, TCCR0_COM01);
			#elif TIMER0_CTC_OC0_MODE == CLEAR_OC
				CLEAR_BIT(TCCR0, TCCR0_COM00);
				SET_BIT(TCCR0, TCCR0_COM01);
			#elif TIMER0_CTC_OC0_MODE == SET_OC
				SET_BIT(TCCR0, TCCR0_COM00);
				SET_BIT(TCCR0, TCCR0_COM01);
			#else
				#error "TIMER0_CTC_OC0_MODE isn't configured properly"
			#endif
			//3- OCR0 value
			OCR0 = TIMER0_OCR0_VALUE;
			//4- Preload
			TCNT0 = TIMER0_PRELOAD;
			//5- Interrupt Enable/Disable
			#if TIMER0_INTERRUPT_ENABLE == ENABLED
				SET_BIT(TIMSK, TIMSK_OCIE0);
			#elif TIMER0_INTERRUPT_ENABLE == DISABLED
				CLEAR_BIT(TIMSK, TIMSK_OCIE0);
			#endif


		#elif TIMER0_MODE == TIMER0_FASTPWM
			//1- Waveform Generation Mode
			SET_BIT(TCCR0, TCCR0_WGM00);
			SET_BIT(TCCR0, TCCR0_WGM01);
			//2- Compare Output Mode
			#if TIMER0_FAST_PWM_OC0_MODE == DISCONNECTED_OC
				CLEAR_BIT(TCCR0, TCCR0_COM00);
				CLEAR_BIT(TCCR0, TCCR0_COM01);
			#elif TIMER0_FAST_PWM_OC0_MODE == CLEAR_OC
				SET_BIT(TCCR0, TCCR0_COM01);
				CLEAR_BIT(TCCR0, TCCR0_COM00);
			#elif TIMER0_FAST_PWM_OC0_MODE == SET_OC
				SET_BIT(TCCR0, TCCR0_COM00);
				SET_BIT(TCCR0, TCCR0_COM01);
			#else
				#error "TIMER0_FAST_PWM_OC0_MODE isn't configured properly"
			#endif
			//3- OCR0 value
			OCR0 = TIMER0_OCR0_VALUE;
			//4- Preload
			// there is no Preload here in FASTPWM mode
			//5- Interrupt Enable/Disable
			// there is no Interrupt here in FASTPWM mode



		#elif TIMER0_MODE == TIMER0_PHASE_CORRECT_PWM
			//1- Waveform Generation Mode
			SET_BIT(TCCR0, TCCR0_WGM00);
			CLEAR_BIT(TCCR0, TCCR0_WGM01);
			//2- Compare Output Mode
			#if TIMER0_PHASE_CORRECT_OC0_MODE == DISCONNECTED_OC
				CLEAR_BIT(TCCR0, TCCR0_COM00);
				CLEAR_BIT(TCCR0, TCCR0_COM01);
			#elif TIMER0_PHASE_CORRECT_OC0_MODE == CLEAR_OC
				CLEAR_BIT(TCCR0, TCCR0_COM00);
				SET_BIT(TCCR0, TCCR0_COM01);
			#elif TIMER0_PHASE_CORRECT_OC0_MODE == SET_OC
				SET_BIT(TCCR0, TCCR0_COM00);
				SET_BIT(TCCR0, TCCR0_COM01);
			#else
				#error "TIMER0_PHASE_CORRECT_OC0_MODE isn't configured properly"
			#endif
			//3- OCR0 value
			OCR0 = TIMER0_OCR0_VALUE;
			//4- Preload
			// there is no Preload here in FASTPWM mode
			//5- Interrupt Enable/Disable
			// there is no Interrupt here in FASTPWM mode
		#endif
	#endif


	#if TIMER1_ENABLE == ENABLED
		#if TIMER1_MODE == TIMER1_NORMAL
			//1- Waveform Generation Mode
			CLEAR_BIT(TCCR1A, TCCR1A_WGM10);
			CLEAR_BIT(TCCR1A, TCCR1A_WGM11);
			CLEAR_BIT(TCCR1B, TCCR1B_WGM12);
			CLEAR_BIT(TCCR1B, TCCR1B_WGM13);
			//2- Compare Output Mode : No compare Output mode in normal mode
			// (OC1A disconnected)
			CLEAR_BIT(TCCR1A, TCCR1A_COM1A0);
			CLEAR_BIT(TCCR1A, TCCR1A_COM1A1);
			// (OC1B disconnected)
			CLEAR_BIT(TCCR1A, TCCR1A_COM1B0);
			CLEAR_BIT(TCCR1A, TCCR1A_COM1B1);
			//3- OCR1A/B value : Here No OCR1A/B value
			//4- Preload
			TCNT1 = TIMER1_PRELOAD;
			//5- Interrupt Enable/Disable
			#if TIMER1_INTERRUPT_ENABLE == ENABLED
				SET_BIT(TIMSK, TIMSK_TOIE1);
			#elif TIMER1_INTERRUPT_ENABLE == DISABLED
				CLEAR_BIT(TIMSK, TIMSK_TOIE1);
			#endif

		#elif TIMER1_MODE == TIMER1_CTC
			//1- Waveform Generation Mode
			CLEAR_BIT(TCCR1A, TCCR1A_WGM10);
			CLEAR_BIT(TCCR1A, TCCR1A_WGM11);
			SET_BIT(TCCR1B, TCCR1B_WGM12);
			CLEAR_BIT(TCCR1B, TCCR1B_WGM13);

			//2- Compare Output Mode : We here Have 2 Channels-> A, B
			#if TIMER1_CHANNEL == CHANNEL_A
				#if TIMER1_CTC_OC1A_MODE == DISCONNECTED_OC
					CLEAR_BIT(TCCR1A, TCCR1A_COM1A0);
					CLEAR_BIT(TCCR1A, TCCR1A_COM1A1);
				#elif TIMER1_CTC_OC1A_MODE == TOGGLE_OC
					SET_BIT(TCCR1A, TCCR1A_COM1A0);
					CLEAR_BIT(TCCR1A, TCCR1A_COM1A1);
				#elif TIMER1_CTC_OC1A_MODE == CLEAR_OC
					CLEAR_BIT(TCCR1A, TCCR1A_COM1A0);
					SET_BIT(TCCR1A, TCCR1A_COM1A1);
				#elif TIMER1_CTC_OC1A_MODE == SET_OC
					SET_BIT(TCCR1A, TCCR1A_COM1A0);
					SET_BIT(TCCR1A, TCCR1A_COM1A1);
				#else
					#error "TIMER1_CTC_OC1A_MODE isn't configured properly"
				#endif
				//3- OCR1A value
				OCR1A = TIMER1_OCR1A_VALUE;
				//4- Preload
				TCNT1 = TIMER1_PRELOAD;
				//5- Interrupt Enable/Disable
				#if TIMER1_INTERRUPT_ENABLE == ENABLED
					SET_BIT(TIMSK, TIMSK_OCIE1A);
				#elif TIMER1_INTERRUPT_ENABLE == DISABLED
					CLEAR_BIT(TIMSK, TIMSK_OCIE1A);
				#endif

			#elif TIMER1_CHANNEL == CHANNEL_B
				#if TIMER1_CTC_OC1B_MODE == DISCONNECTED_OC
					CLEAR_BIT(TCCR1A, TCCR1A_COM1B0);
					CLEAR_BIT(TCCR1A, TCCR1A_COM1B1);
				#elif TIMER1_CTC_OC1B_MODE == TOGGLE_OC
					SET_BIT(TCCR1A, TCCR1A_COM1B0);
					CLEAR_BIT(TCCR1A, TCCR1A_COM1B1);
				#elif TIMER1_CTC_OC1B_MODE == CLEAR_OC
					CLEAR_BIT(TCCR1A, TCCR1A_COM1B0);
					SET_BIT(TCCR1A, TCCR1A_COM1B1);
				#elif TIMER1_CTC_OC1B_MODE == SET_OC
					SET_BIT(TCCR1A, TCCR1A_COM1B0);
					SET_BIT(TCCR1A, TCCR1A_COM1B1);
				#else
					#error "TIMER1_CTC_OC1B_MODE isn't configured properly"
				#endif
				//3- OCR1B value
				OCR1B = TIMER1_OCR1B_VALUE;
				//4- Preload
				TCNT1 = TIMER1_PRELOAD;
			#endif
			//5- Interrupt Enable/Disable
			#if TIMER1_INTERRUPT_ENABLE == ENABLED
				SET_BIT(TIMSK, TIMSK_OCIE1B);
			#elif TIMER1_INTERRUPT_ENABLE == DISABLED
				CLEAR_BIT(TIMSK, TIMSK_OCIE1B);
			#endif

		#elif TIMER1_MODE == TIMER1_FASTPWM
			//1- Waveform Generation Mode
			CLEAR_BIT(TCCR1A, TCCR1A_WGM10);
			SET_BIT(TCCR1A, TCCR1A_WGM11);
			SET_BIT(TCCR1B, TCCR1B_WGM12);
			SET_BIT(TCCR1B, TCCR1B_WGM13);

			//2- Compare Output Mode : We here Have 2 Channels-> A, B
			#if TIMER1_CHANNEL == CHANNEL_A
				#if TIMER1_FAST_PWM_OC1A_MODE == DISCONNECTED_OC
					CLEAR_BIT(TCCR1A, TCCR1A_COM1A0);
					CLEAR_BIT(TCCR1A, TCCR1A_COM1A1);
				#elif TIMER1_FAST_PWM_OC1A_MODE == TOGGLE_OC
					SET_BIT(TCCR1A, TCCR1A_COM1A0);
					CLEAR_BIT(TCCR1A, TCCR1A_COM1A1);
				#elif TIMER1_FAST_PWM_OC1A_MODE == CLEAR_OC
					CLEAR_BIT(TCCR1A, TCCR1A_COM1A0);
					SET_BIT(TCCR1A, TCCR1A_COM1A1);
				#elif TIMER1_FAST_PWM_OC1A_MODE == SET_OC
					SET_BIT(TCCR1A, TCCR1A_COM1A0);
					SET_BIT(TCCR1A, TCCR1A_COM1A1);
				#else
					#error "TIMER1_FAST_PWM_OC1A_MODE isn't configured properly"
				#endif
				//3- OCR1A value
				OCR1A = TIMER1_OCR1A_VALUE;
				//4- Preload
				// there is no Preload here in FASTPWM mode
				//5- Interrupt Enable/Disable
				// there is no Interrupt here in FASTPWM mode

			#elif TIMER1_CHANNEL == CHANNEL_B
				#if TIMER1_FAST_PWM_OC1B_MODE == DISCONNECTED_OC
					CLEAR_BIT(TCCR1A, TCCR1A_COM1B0);
					CLEAR_BIT(TCCR1A, TCCR1A_COM1B1);
				#elif TIMER1_FAST_PWM_OC1B_MODE == TOGGLE_OC
					SET_BIT(TCCR1A, TCCR1A_COM1B0);
					CLEAR_BIT(TCCR1A, TCCR1A_COM1B1);
				#elif TIMER1_FAST_PWM_OC1B_MODE == CLEAR_OC
					CLEAR_BIT(TCCR1A, TCCR1A_COM1B0);
					SET_BIT(TCCR1A, TCCR1A_COM1B1);
				#elif TIMER1_FAST_PWM_OC1B_MODE == SET_OC
					SET_BIT(TCCR1A, TCCR1A_COM1B0);
					SET_BIT(TCCR1A, TCCR1A_COM1B1);
				#else
					#error "TIMER1_CTC_OC1B_MODE isn't configured properly"
				#endif
				//3- OCR1B value :
				OCR1B = TIMER1_OCR1B_VALUE;
				//4- Preload
				// there is no Preload here in FASTPWM mode
				//5- Interrupt Enable/Disable
				// there is no Interrupt here in FASTPWM mode
			#endif
			

		// @TODO : TIMER0_PHASE_CORRECT_PWM
		#elif TIMER1_MODE == TIMER1_PHASE_CORRECT_PWM
			#error "TIMER1_PHASE_CORRECT_PWM Still in development"
		//	//1- Waveform Generation Mode
		//	CLEAR_BIT(TCCR1A, TCCR1A_WGM10);
		//	SET_BIT(TCCR1A, TCCR1A_WGM11);
		//	SET_BIT(TCCR1B, TCCR1B_WGM12);
		//	SET_BIT(TCCR1B, TCCR1B_WGM13);
		//
		//	//2- Compare Output Mode : We here Have 2 Channels-> A, B
		//	#if TIMER1_CHANNEL == CHANNEL_A
		//		#if TIMER1_CTC_OC1A_MODE == DISCONNECTED_OC
		//			CLEAR_BIT(TCCR1A, TCCR1A_COM1A0);
		//			CLEAR_BIT(TCCR1A, TCCR1A_COM1A1);
		//		#elif TIMER1_CTC_OC1A_MODE == TOGGLE_OC
		//			SET_BIT(TCCR1A, TCCR1A_COM1A0);
		//			CLEAR_BIT(TCCR1A, TCCR1A_COM1A1);
		//		#elif TIMER1_CTC_OC1A_MODE == CLEAR_OC
		//			CLEAR_BIT(TCCR1A, TCCR1A_COM1A0);
		//			SET_BIT(TCCR1A, TCCR1A_COM1A1);
		//		#elif TIMER1_CTC_OC1A_MODE == SET_OC
		//			SET_BIT(TCCR1A, TCCR1A_COM1A0);
		//			SET_BIT(TCCR1A, TCCR1A_COM1A1);
		//		#else
		//			#error "TIMER1_CTC_OC1A_MODE isn't configured properly"
		//		#endif
		//		//3- OCR1A value
		//		OCR1A = TIMER1_OCR1A_VALUE;
		//		//4- Preload
		//		// there is no Preload here in FASTPWM mode
		//		//5- Interrupt Enable/Disable
		//		// there is no Interrupt here in FASTPWM mode
		//
		//		#elif TIMER1_CHANNEL == CHANNEL_B
		//			#if TIMER1_CTC_OC1B_MODE == DISCONNECTED_OC
		//				CLEAR_BIT(TCCR1A, TCCR1A_COM1B0);
		//				CLEAR_BIT(TCCR1A, TCCR1A_COM1B1);
		//			#elif TIMER1_CTC_OC1B_MODE == TOGGLE_OC
		//				SET_BIT(TCCR1A, TCCR1A_COM1B0);
		//				CLEAR_BIT(TCCR1A, TCCR1A_COM1B1);
		//			#elif TIMER1_CTC_OC1B_MODE == CLEAR_OC
		//				CLEAR_BIT(TCCR1A, TCCR1A_COM1B0);
		//				SET_BIT(TCCR1A, TCCR1A_COM1B1);
		//			#elif TIMER1_CTC_OC1B_MODE == SET_OC
		//				SET_BIT(TCCR1A, TCCR1A_COM1B0);
		//				SET_BIT(TCCR1A, TCCR1A_COM1B1);
		//			#else
		//				#error "TIMER1_CTC_OC1B_MODE isn't configured properly"
		//			#endif
		//		//3- OCR1B value :
		//		OCR1B = TIMER1_OCR1B_VALUE;
		//		//4- Preload
		//		// there is no Preload here in FASTPWM mode
		//		//5- Interrupt Enable/Disable
		//		// there is no Interrupt here in FASTPWM mode
		//	#endif
		#endif
	#endif


	#if TIMER2_ENABLE == ENABLED
		#if TIMER2_MODE == TIMER2_NORMAL
			//1- Waveform Generation Mode
			CLEAR_BIT(TCCR2, TCCR2_WGM20);
			CLEAR_BIT(TCCR2, TCCR2_WGM21);
			//2- Compare Output Mode : No compare Output mode in normal mode(OC2 disconnected)
			CLEAR_BIT(TCCR2, TCCR2_COM20);
			CLEAR_BIT(TCCR2, TCCR2_COM21);
			//3- Here No OCR2 value
			//4- Preload
			TCNT2 = TIMER2_PRELOAD;
			//5- Interrupt Enable/Disable
			#if TIMER2_INTERRUPT_ENABLE == ENABLED
				SET_BIT(TIMSK, TIMSK_TOIE2);
			#elif TIMER2_INTERRUPT_ENABLE == DISABLED
				CLEAR_BIT(TIMSK, TIMSK_TOIE2);
			#endif


		#elif TIMER2_MODE == TIMER2_CTC
			//1- Waveform Generation Mode
			CLEAR_BIT(TCCR2, TCCR2_WGM20);
			SET_BIT(TCCR2, TCCR2_WGM21);
			//2- Compare Output Mode
			#if TIMER2_CTC_OC2_MODE == DISCONNECTED_OC
				CLEAR_BIT(TCCR2, TCCR2_COM20);
				CLEAR_BIT(TCCR2, TCCR2_COM21);
			#elif TIMER2_CTC_OC2_MODE == TOGGLE_OC
				SET_BIT(TCCR2, TCCR2_COM20);
				CLEAR_BIT(TCCR2, TCCR2_COM21);
			#elif TIMER2_CTC_OC2_MODE == CLEAR_OC
				CLEAR_BIT(TCCR2, TCCR2_COM20);
				SET_BIT(TCCR2, TCCR2_COM21);
			#elif TIMER2_CTC_OC2_MODE == SET_OC
				SET_BIT(TCCR2, TCCR2_COM20);
				SET_BIT(TCCR2, TCCR2_COM21);
			#else
				#error "TIMER2_CTC_OC2_MODE isn't configured properly"
			#endif
			//3- OCR2 value
			OCR2 = TIMER2_OCR2_VALUE;
			//4- Preload
			TCNT2 = TIMER2_PRELOAD;
			//5- Interrupt Enable/Disable
			#if TIMER2_INTERRUPT_ENABLE == ENABLED
				SET_BIT(TIMSK, TIMSK_OCIE2);
			#elif TIMER2_INTERRUPT_ENABLE == DISABLED
				CLEAR_BIT(TIMSK, TIMSK_OCIE2);
			#endif


		#elif TIMER2_MODE == TIMER2_FASTPWM
			//1- Waveform Generation Mode
			SET_BIT(TCCR2, TCCR2_WGM20);
			SET_BIT(TCCR2, TCCR2_WGM21);
			//2- Compare Output Mode
			#if TIMER2_FAST_PWM_OC2_MODE == DISCONNECTED_OC
				CLEAR_BIT(TCCR2, TCCR2_COM20);
				CLEAR_BIT(TCCR2, TCCR2_COM21);
			#elif TIMER2_FAST_PWM_OC2_MODE == CLEAR_OC
				CLEAR_BIT(TCCR2, TCCR2_COM20);
				SET_BIT(TCCR2, TCCR2_COM21);
			#elif TIMER2_FAST_PWM_OC2_MODE == SET_OC
				SET_BIT(TCCR2, TCCR0_COM20);
				SET_BIT(TCCR2, TCCR0_COM21);
			#else
				#error "TIMER2_FAST_PWM_OC2_MODE isn't configured properly"
			#endif
			//3- OCR2 value
			OCR2 = TIMER2_OCR2_VALUE;
			//4- Preload
			// there is no Preload here in FASTPWM mode
			//5- Interrupt Enable/Disable
			// there is no Interrupt here in FASTPWM mode



		#elif TIMER2_MODE == TIMER2_PHASE_CORRECT_PWM
			//1- Waveform Generation Mode
			SET_BIT(TCCR2, TCCR2_WGM20);
			CLEAR_BIT(TCCR2, TCCR2_WGM21);
			//2- Compare Output Mode
			#if TIMER2_PHASE_CORRECT_OC2_MODE == DISCONNECTED_OC
				CLEAR_BIT(TCCR2, TCCR2_COM20);
				CLEAR_BIT(TCCR2, TCCR2_COM21);
			#elif TIMER2_PHASE_CORRECT_OC2_MODE == CLEAR_OC
				CLEAR_BIT(TCCR2, TCCR2_COM20);
				SET_BIT(TCCR2, TCCR2_COM21);
			#elif TIMER2_PHASE_CORRECT_OC2_MODE == SET_OC
				SET_BIT(TCCR2, TCCR0_COM20);
				SET_BIT(TCCR2, TCCR0_COM21);
			#else
				#error "TIMER2_PHASE_CORRECT_OC2_MODE isn't configured properly"
			#endif
			//3- OCR2 value
			OCR2 = TIMER2_OCR2_VALUE;
			//4- Preload
			// there is no Preload here in PHASE CORRECT mode
			//5- Interrupt Enable/Disable
			// there is no Interrupt here in PHASE CORRECT mode
		#endif
	#endif


}

void TIMERS_vSetBusyWait_sync(TIMER_TYPE_t TimerId, u32 Copy_u32Ticks)
{
	//polling
}

void TIMERS_vStartTimer(TIMER_TYPE_t TimerId)
{
	switch (TimerId)
	{
		case TIMER0:
			#if TIMER0_ENABLE == ENABLED
				TCCR0 &= ~(0b111);
				TCCR0 |= TIMER0_PRESCALER;
			#endif
			break;
		case TIMER1:
			#if TIMER1_ENABLE == ENABLED
				TCCR1B &= ~(0b111);
				TCCR1B |= TIMER1_PRESCALER;
			#endif
			break;
		case TIMER2:
			#if TIMER2_ENABLE == ENABLED
				TCCR2 &= ~(0b111);
				TCCR2 |= TIMER2_PRESCALER;
			#endif
			break;
		default:
			/*  Error : Invalid TIMER_TYPE_t */
			break;
	}
}

void TIMERS_vStopTimer(TIMER_TYPE_t TimerId)
{
	switch (TimerId)
	{
		case TIMER0:
			TCCR0 &= ~(0b111);
			TCCR0 |= PS_NOCLK;
			break;
		case TIMER1:
			TCCR1B &= ~(0b111);
			TCCR1B |= PS_NOCLK;
			break;
		case TIMER2:
			TCCR2 &= ~(0b111);
			TCCR2 |= PS_NOCLK;
			break;
		default:
			/*  Error : Invalid TIMER_TYPE_t */
			break;
	}



}



void TIMERS_vSetCallback(TIMER_TYPE_t TimerId,void (*Copy_Fptr)(void))
{
	switch (TimerId)
	{
		case TIMER0:
			#if TIMER0_MODE == TIMER0_NORMAL
				G_TIMER0_OVF_CallBack = Copy_Fptr;
			#elif TIMER0_MODE == TIMER0_CTC
				G_TIMER0_COM_CallBack = Copy_Fptr;
			#endif
			break;
		case TIMER1:
			#if TIMER1_MODE == TIMER1_NORMAL
				G_TIMER1_OVF_CallBack = Copy_Fptr;
			#elif TIMER1_MODE == TIMER1_CTC
				#if TIMER1_CHANNEL == CHANNEL_A
					G_TIMER1_COMA_CallBack = Copy_Fptr;
				#elif TIMER1_CHANNEL == CHANNEL_A
					G_TIMER1_COMB_CallBack = Copy_Fptr;
				#else 
					#error "TIMER1_CHANNEL isn't configured properly!"
				#endif
			#endif
			break;
		case TIMER2:
			#if TIMER2_MODE == TIMER2_NORMAL
				GS_TIMER2_OVF_CallBack = Copy_Fptr;
			#elif TIMER2_MODE == TIMER2_CTC
				GS_TIMER2_COM_CallBack = Copy_Fptr;
			#endif
			break;
		default:
			/*  Error : Invalid TIMER_TYPE_t */
			break;
		}
}


void TIMERS_vSetPreloadValue(TIMER_TYPE_t TimerId, u16 Copy_u16Preload)
{
	switch (TimerId)
	{
		case TIMER0:
			TCNT0 = Copy_u16Preload;
			break;
		case TIMER1:
			TCNT1 = Copy_u16Preload;
			break;
		case TIMER2:
			TCNT2 = Copy_u16Preload;
			break;
		default:
			/*  Error : Invalid TIMER_TYPE_t */
			break;
	}
}

void TIMERS_vSetCompareMatchValue(TIMER_TYPE_t TimerId, TIMER1_Channel_t Copy_u16OcrChannel, u16 Copy_u16OcrVal)
{
	switch (TimerId)
	{
		case TIMER0:
			OCR0 = Copy_u16OcrVal;
			break;

		case TIMER1:
			switch (Copy_u16OcrChannel)
			{
				case Channel_A:
					OCR1A = Copy_u16OcrVal;
					break;
				case Channel_B:
					OCR1B = Copy_u16OcrVal;
					break;
				default:
					/*  Error : Invalid TIMER1_Channel_t */
					break;
			}
			break;

		case TIMER2:
			OCR2 = Copy_u16OcrVal;
			break;
		default:
			/*  Error : Invalid TIMER_TYPE_t */
			break;
	}
}


void TIMERS_vSetICR(u16 Copy_16IcrValue)
{
    #if TIMER1_ENABLE == ENABLED
		ICR1 = Copy_16IcrValue; // Top value can be changed through this register in FastPWM mode
    #endif
}


void __vector_4(void) __attribute__((signal)); // TIMER2 COMP
void __vector_5(void) __attribute__((signal)); // TIMER2 OVF

void __vector_7(void) __attribute__((signal));  // TIMER1 COMPA
void __vector_8(void) __attribute__((signal));  // TIMER1 COMPB
void __vector_9(void) __attribute__((signal));  // TIMER1 OVF
void __vector_10(void) __attribute__((signal)); // TIMER0 COMP
void __vector_11(void) __attribute__((signal)); // TIMER0 OVF



void __vector_4(void)
{
	if(GS_TIMER2_COM_CallBack != NULL)
	{
		GS_TIMER2_COM_CallBack();
	}
}

void __vector_5(void)
{
	if(GS_TIMER2_OVF_CallBack != NULL)
	{
		GS_TIMER2_OVF_CallBack();
	}
}


void __vector_7(void)
{
	if(GS_TIMER1_COMA_CallBack != NULL)
	{
		GS_TIMER1_COMA_CallBack();
	}
}

void __vector_8(void)
{
	if(GS_TIMER1_COMB_CallBack != NULL)
	{
		GS_TIMER1_COMB_CallBack();
	}
}

void __vector_9(void)
{
	if(GS_TIMER1_OVF_CallBack != NULL)
	{
		GS_TIMER1_OVF_CallBack();
	}
}

void __vector_10(void)
{
	if(GS_TIMER0_COM_CallBack != NULL)
	{
		GS_TIMER0_COM_CallBack();
	}
}

void __vector_11(void)
{
	if(GS_TIMER0_OVF_CallBack != NULL)
	{
		GS_TIMER0_OVF_CallBack();
	}
}
