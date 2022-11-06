/*****************************************************************/
/*****************************************************************/
/*************	 Author  : Abdallah & Anis	    ******************/
/*************	 Layer   : APP					******************/
/*************	 Date    : 26 Oct 2022			******************/
/*************	 Version : V1.0					******************/
/*****************************************************************/
/*****************************************************************/

#ifndef APP_APP_CONFIG_H_
#define APP_APP_CONFIG_H_


// Welcome to the Configuration DashBoard ^_^



/************** User-Configurations  **************/
#define APP_DEFAULT_PASS 		        1234
#define APP_MAX_BEARABLE_TEMP			40


/******************** BUZZER **********************/
#define APP_BUZZER_PORT			        GPIO_PORTD
#define APP_BUZZER_PIN			        PIN7

/********************* RED_LED ********************/
#define APP_RED_LED_PORT		        GPIO_PORTA
#define	APP_RED_LED_PIN			        PIN0

/********************** DCM ***********************/
#define APP_DCM_PORT			        GPIO_PORTA
#define APP_DCM_PIN				        PIN1

/********************** LM35 **********************/
#define	APP_LM35_PORT			        GPIO_PORTA
#define	APP_LM35_PIN			        PIN2

/************ Air Conditioning BUTTON *************/

#define	APP_AC_ON_OFF_BUTTON_PORT       GPIO_PORTD
#define	APP_AC_ON_OFF_BUTTON_PIN        PIN3

/******************* EXIT BUTTON *******************/
#define	APP_EXIT_BUTTON_PORT		    GPIO_PORTD
#define	APP_EXIT_BUTTON_PIN			    PIN2

///******************* SERVO motor *******************/
#define	APP_SERVOM_PORT					GPIO_PORTD
#define APP_SERVOM_PIN					PIN5
#define SERVOM_TIMER					TIMER1
#define SERVOM_TIMER_Channel			Channel_A




#endif /* APP_APP_CONFIG_H_ */
