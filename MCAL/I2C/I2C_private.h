/*****************************************************************/
/*****************************************************************/
/*************	 Author  : Abdallah Issa	    ******************/
/*************	 Layer   : MCAL					******************/
/*************	 SWC   	 : I2C  				******************/
/*************	 Date    : 14 Oct 2022			******************/
/*************	 Version : V1.0					******************/
/*****************************************************************/
/*****************************************************************/


#ifndef MCAL_I2C_I2C_PRIVATE_H_
#define MCAL_I2C_I2C_PRIVATE_H_



#define TWCR     *((volatile u8*)(0x56))
#define TWBR     *((volatile u8*)(0x20))
#define TWSR     *((volatile u8*)(0x21))
#define TWAR     *((volatile u8*)(0x22))
#define TWDR     *((volatile u8*)(0x23))

#define TWCR_TWIE	        0
#define TWCR_TWEN	        2
#define TWCR_TWWC	        3
#define TWCR_TWSTO	        4
#define TWCR_TWSTA	        5
#define TWCR_TWEA	        6
#define TWCR_TWINT	        7


#define TWSR_TWPS0	        0
#define TWSR_TWPS1	        1
#define TWSR_TWS3	        3
#define TWSR_TWS4	        4
#define TWSR_TWS5	        5
#define TWSR_TWS6	        6
#define TWSR_TWS7	        7


#define TWAR_TWGCE	        0
#define TWAR_TWA0	        1
#define TWAR_TWA1	        2
#define TWAR_TWA2	        3
#define TWAR_TWA3	        4
#define TWAR_TWA4	        5
#define TWAR_TWA5	        6
#define TWAR_TWA6	        7


#define DISABLED			0
#define ENABLED				1


#define I2C_START           0x08
#define I2C_REP_START       0x10
#define I2C_MT_SLA_W_ACK    0x18
#define I2C_MT_DATA_ACK     0x28
#define I2C_MR_SLA_R_ACK    0x40
#define I2C_MR_DATA_ACK     0x50
#define I2C_MR_DATA_NACK    0x58


#endif
