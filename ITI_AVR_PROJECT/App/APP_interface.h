/*****************************************************************/
/*****************************************************************/
/*************	 Author  : Abdallah & Anis	    ******************/
/*************	 Layer   : APP					******************/
/*************	 Date    : 26 Oct 2022			******************/
/*************	 Version : V1.0					******************/
/*****************************************************************/
/*****************************************************************/


#ifndef APP_APP_INTERFACE_H_
#define APP_APP_INTERFACE_H_

void APP_vWelcomeScreen (void);
void APP_vUserWelcomeScreen (void);
void APP_vEnterLandingState (void);
void APP_vStartTheSystem(void);

void APP_vEnterRunningState(void);
void APP_vOpenTheDoor(void);
void APP_vEnterBlockedState(void);

void APP_vInittheSystem(void);

#endif /* APP_APP_INTERFACE_H_ */
