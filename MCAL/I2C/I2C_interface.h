/*****************************************************************/
/*****************************************************************/
/*************	 Author  : Abdallah Issa	    ******************/
/*************	 Layer   : MCAL					******************/
/*************	 SWC   	 : I2C  				******************/
/*************	 Date    : 14 Oct 2022			******************/
/*************	 Version : V1.0					******************/
/*****************************************************************/
/*****************************************************************/


#ifndef MCAL_I2C_I2C_INTERFACE_H_
#define MCAL_I2C_I2C_INTERFACE_H_

#include "../../LIB/STD_TYPES.h"
#include "I2C_private.h"


#define I2C_READ    1
#define I2C_WRITE   0

#define I2C_ACK		1
#define I2C_NACK    0


#if 0
void TWI_vInit(void);
u8   TWI_u8SendStartCondition(void);
u8   TWI_u8SendSlaveAddress(u8 A_u8Sla, u8 A_u8Rw);
u8   TWI_u8SendByte(u8 A_u8Byte);
u8   TWI_u8SendStopCondition(void);
u8   TWI_u8SendRepeatedStart(void);
u8   TWI_u8GetStatusCode(void);
#endif

// For Now:

void I2C_vInit(void);

void I2C_vStart(void);

void I2C_vWrite(u8 Copy_u8Data);

u8 I2C_u8Read(void);



#endif
