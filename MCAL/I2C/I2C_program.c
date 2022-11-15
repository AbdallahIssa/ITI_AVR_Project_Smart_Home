#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "I2C_interface.h"
#include "I2C_private.h"
#include "I2C_config.h"



#if 0
static void (*GS_I2C_CALLBACK) (void);

void TWI_vInit(void)
{
	// Enable I2C
	SET_BIT(TWCR, TWCR_TWEN);
	TWBR = 0x02;//To achieve SCL_CLOCK=400Kbps
	#if I2C_INTERRUPT_ENABLE == ENABLED
		SET_BIT(TWCR,TWCR_TWIE);
	#elif I2C_INTERRUPT_ENABLE == DISABLED

	#else
		#error "You chose wrong I2C_INTERRUPT_ENABLE option"
	#endif

	//own slave address
	TWAR = I2C_OWN_SLA;
}

u8   TWI_u8SendStartCondition(void)
{
	u8 returnVal = 0;
	SET_BIT(TWCR, TWCR_TWSTA);
	#if I2C_INTERRUPT_ENABLE == ENABLED
		returnVal = (TWSR & 0xF8);
	#elif I2C_INTERRUPT_ENABLE == DISABLED
		while (!(TWCR & (1<<TWCR_TWINT)));
		CLEAR_BIT(TWCR, TWCR_TWSTA);
		returnVal = (TWSR & 0xF8);
	#else
		#error "You chose wrong I2C_INTERRUPT_ENABLE option"
	#endif
	return returnVal;
}

u8   TWI_u8SendSlaveAddress(u8 A_u8Sla, u8 A_u8Rw)
{
	u8 returnVal = 0;
	return returnVal;
}

u8   TWI_u8SendByte(u8 A_u8Byte)
{
	u8 returnVal = 0;
	return returnVal;
}
u8   TWI_u8SendStopCondition(void)
{
	u8 returnVal = 0;
	SET_BIT(TWCR, TWCR_TWSTO);
	#if I2C_INTERRUPT_ENABLE == ENABLED

	#elif I2C_INTERRUPT_ENABLE == DISABLED
		while (!(TWCR & (1<<TWCR_TWSTO)));
		CLEAR_BIT(TWCR, TWCR_TWSTO);
	#else
		#error "You chose wrong I2C_INTERRUPT_ENABLE option"
	#endif

	return returnVal;
}

u8   TWI_u8SendRepeatedStart(void)
{
	u8 returnVal = 0;
	return returnVal;
}
u8   TWI_u8GetStatusCode(void)
{
	return (TWSR & 0xF8);
}


void __vector_2(void)
{
	if(GS_I2C_CALLBACK != NULL)
	{
		GS_I2C_CALLBACK();
	}
	CLEAR_BIT(TWCR, TWCR_TWINT);
}
#endif

void I2C_vInit(void)
{
	TWSR = 0x00;
	TWBR = 0x20;
	TWCR = (1<<TWCR_TWEN);
}

void I2C_vStart(void)
{
	TWCR = (1<<TWCR_TWINT) | (1<<TWCR_TWEN) | (1<<TWCR_TWSTA);
	while (!(TWCR & (1<<TWCR_TWINT)));
}

void I2C_vWrite(u8 Copy_u8Data)
{
	TWDR = Copy_u8Data;
	TWCR = (1<<TWCR_TWINT) | (1<<TWCR_TWEN);
	while  (!(TWCR &(1<<TWCR_TWINT)));
}

u8 I2C_u8Read(void)
{
	TWCR  = (1<<TWCR_TWEN) | (1<<TWCR_TWINT);
	while (!(TWCR & (1<<TWCR_TWINT)));
	return TWDR;
}




