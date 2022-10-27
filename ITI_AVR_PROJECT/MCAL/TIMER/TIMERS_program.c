#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"


#include "TIMERS_interface.h"
#include "TIMERS_private.h"
#include "TIMERS_config.h"

void TIMERS_vInit(void)
{
	#if TIMER0_ENABLE == ENABLED
		#if TIMER0_MODE == TIMER0_NORMAL
			//1- Waveform Generation Mode
			CLEAR_BIT(TCCR0, TCCR0_WGM00);
			CLEAR_BIT(TCCR0, TCCR0_WGM01);
			//2- Compare Output Mode : No compare Output mode in normal mode
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
				CLEAR_BIT(TCCR0, TCCR0_COM00);
				SET_BIT(TCCR0, TCCR0_COM01);
			#elif TIMER0_FAST_PWM_OC0_MODE == SET_OC
				SET_BIT(TCCR0, TCCR0_COM00);
				SET_BIT(TCCR0, TCCR0_COM01);
			#else
				#error "TIMER0_FAST_PWM_OC0_MODE isn't configured properly"
			#endif
			//3- OCR0 value
			OCR0 = TIMER0_OCR0_VALUE;



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
		#endif
	#endif



	#if TIMER1_ENABLE == ENABLED
		#if TIMER1_MODE == TIMER1_NORMAL
				//1- Waveform Generation Mode
				CLEAR_BIT(TCCR1A, TCCR1A_WGM10);
				CLEAR_BIT(TCCR1A, TCCR1A_WGM11);
				CLEAR_BIT(TCCR1B, TCCR1B_WGM12);
				CLEAR_BIT(TCCR1B, TCCR1B_WGM13);
				/* OR By masking:
				 * 	TCCR1A &=~(0b00000011);
				 * 	TCCR1B &=~(0b00011000);
				 */

				//2- Compare Output Mode : No compare Output mode in normal mode
				CLEAR_BIT(TCCR1A, TCCR1A_COM1A0);
				CLEAR_BIT(TCCR1A, TCCR1A_COM1A1);
				CLEAR_BIT(TCCR1A, TCCR1A_COM1B0);
				CLEAR_BIT(TCCR1A, TCCR1A_COM1B1);
				// OR By masking: TCCR1A &=~(0b11110000);

				//3- Preload
				TCNT1 = TIMER1_PRELOAD;
				//4- Interrupt Enable/Disable
				#if TIMER1_INTERRUPT_ENABLE == ENABLED
					SET_BIT(TIMSK, TIMSK_TOIE1);
				#elif TIMER1_INTERRUPT_ENABLE == DISABLED
					CLEAR_BIT(TIMSK, TIMSK_TOIE1);
				#endif

		#elif TIMER1_MODE == TIMER1_CTC
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
				CLEAR_BIT(TCCR0, TCCR0_COM00);
				SET_BIT(TCCR0, TCCR0_COM01);
			#elif TIMER0_FAST_PWM_OC0_MODE == SET_OC
				SET_BIT(TCCR0, TCCR0_COM00);
				SET_BIT(TCCR0, TCCR0_COM01);
			#else
				#error "TIMER0_FAST_PWM_OC0_MODE isn't configured properly"
			#endif
			//3- OCR0 value
			OCR0 = TIMER0_OCR0_VALUE;



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
		#endif
	#endif



	#if TIMER2_ENABLE == ENABLED
		#if TIMER0_MODE == TIMER_NORMAL
				//1- Waveform Generation Mode
				CLEAR_BIT(TCCR0, TCCR0_WGM00);
				CLEAR_BIT(TCCR0, TCCR0_WGM01);
				//2- Compare Output Mode
				CLEAR_BIT(TCCR0, TCCR0_COM00);
				CLEAR_BIT(TCCR0, TCCR0_COM01);
				//3- Preload
				TCNT0 = TIMER0_PRELOAD;
				//4- Interrupt Enable/Disable
				#if TIMER0_INTERRUPT_ENABLE == ENABLED
				SET_BIT(TIMSK, TIMSK_TOIE0);
				#elif TIMER0_INTERRUPT_ENABLE == DISABLED
				CLEAR_BIT(TIMSK, TIMSK_TOIE0);
				#endif

			#elif TIMER_MODE == TIMER_PHASE_CORRECT_PWM

				//1- Waveform Generation Mode
				CLEAR_BIT(TCCR0, TCCR0_WGM00);
				CLEAR_BIT(TCCR0, TCCR0_WGM01);
				//2- Compare Output Mode
				CLEAR_BIT(TCCR0, TCCR0_COM00);
				CLEAR_BIT(TCCR0, TCCR0_COM01);
				//3- Preload
				TCNT0 = TIMER0_PRELOAD;
				//4- Interrupt Enable/Disable
				#if TIMER0_INTERRUPT_ENABLE == ENABLED
				SET_BIT(TIMSK, TIMSK_TOIE0);
				#elif TIMER0_INTERRUPT_ENABLE == DISABLED
				CLEAR_BIT(TIMSK, TIMSK_TOIE0);
				#endif

			#elif TIMER_MODE == TIMER_CTC
				//TODO
			#elif TIMER_MODE == TIMER_FASTPWM
				//TODO
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
			TCCR0 &= ~(0b111);
			TCCR0 |= TIMER0_PRESCALER;
			break;
		case TIMER1:
			//TODO
			break;
		case TIMER2:
			//TODO
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
			//TODO
			break;
		case TIMER2:
			//TODO
			break;
		default:
			/*  Error : Invalid TIMER_TYPE_t */
			break;
	}



}

static void (*G_TIMER0_OVF_CallBack)(void);
static void (*G_TIMER0_COM_CallBack)(void);
static void (*G_TIMER1_OVF_CallBack)(void);
static void (*G_TIMER1_COMA_CallBack)(void);
static void (*G_TIMER1_COMB_CallBack)(void);

void TIMERS_vSetCallback(TIMER_TYPE_t TimerId,void (*Copy_Fptr)(void))
{
	switch (TimerId)
	{
		case TIMER0:
			if(TimerId == TIMER0)
			{
				#if TIMER0_MODE == TIMER0_NORMAL
					G_TIMER0_OVF_CallBack = Copy_Fptr;
				#elif (TIMER0_MODE == TIMER0_CTC || TIMER0_MODE == TIMER0_PHASE_CORRECT_PWM || TIMER0_MODE == TIMER0_FASTPWM)
					G_TIMER0_COM_CallBack = Copy_Fptr;
				#else
					/* Error */
				#endif
			}
			break;
		case TIMER1:
			//TODO
			break;
		case TIMER2:
			//TODO
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
			//TODO
			break;
		case TIMER2:
			//TODO
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
			//TODO : TIMERS_vSetCompareMatchValue
			break;
		default:
			/*  Error : Invalid TIMER_TYPE_t */
			break;
	}
}
void __vector_7(void) __attribute__((signal)); // TIMER1 COMPA
void __vector_8(void) __attribute__((signal)); // TIMER1 COMPB
void __vector_9(void) __attribute__((signal)); // TIMER1 OVF
void __vector_10(void) __attribute__((signal)); // TIMER0 COMP
void __vector_11(void) __attribute__((signal)); // TIMER0 OVF


void __vector_7(void)
{
	if(G_TIMER1_COMA_CallBack != NULL)
	{
		G_TIMER1_COMA_CallBack();
	}
}

void __vector_8(void)
{
	if(G_TIMER1_COMB_CallBack != NULL)
	{
		G_TIMER1_COMB_CallBack();
	}
}

void __vector_9(void)
{
	if(G_TIMER1_OVF_CallBack != NULL)
	{
		G_TIMER1_OVF_CallBack();
	}
}

void __vector_10(void)
{
	if(G_TIMER0_COM_CallBack != NULL)
	{
		G_TIMER0_COM_CallBack();
	}
}

void __vector_11(void)
{
	if(G_TIMER0_OVF_CallBack != NULL)
	{
		G_TIMER0_OVF_CallBack();
	}
}
