# ITI Smart Home with AVR

> Live demo [_here_](https://youtu.be/IB1vBMZYJQU)

## Table of Contents
* [General Info](#general-information)
* [Technologies Used](#technologies-used)
* [Screenshots](#screenshots)
* [Usage](#usage)
* [Contact](#contact)


### General Information

- Enter Password to get in the house
-	If right: the message: “Access is Authorized ^_^, Welcome to your Smart Home” will be displayed on LCD and the door will be opened.
-	If wrong: try again (only 3 attempts are allowed) after that, the buzzer will beep, and LCD shows a message “Access is denied!”.
-	After right password is entered, the user will have the ability to do the following:
    *	Turn the air conditioning on an off.
    *	See and monitor the Temperature of the house (shown on LCD).
    *	If temperature is higher than or equal to 40°C, automatically the AC will be turned on.


### Technologies Used

- C Language.
- Microcontroller : Atmega32 .
- IDE: Eclipse.
- Simulation IDE: proteus.
- The MCAL drivers of the Atmega32 are written by our team for clean and Extensible Code.
- All sensors have their drivers written by our team and implemented in the HAL layer.



## Screenshots
- System overall schema:
![System overall schema](https://user-images.githubusercontent.com/41482404/201833474-ebe98d70-4f52-439d-af29-841c713ea46d.png)

- System Simulation on proteus
![System Simulation on proteus](https://user-images.githubusercontent.com/41482404/201833735-6761a217-a539-464a-8a0c-c802a83a8355.jpeg)




### Usage

- You can start from the App_config.h file to configure your app.


### Contact
- Created by [@abdallahissa](https://www.linkedin.com/in/abdallaissa/) - feel free to contact me!

