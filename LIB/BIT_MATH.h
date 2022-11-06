/*****************************************************************/
/*****************************************************************/
/*************	 Author  : Abdallah Issa	    ******************/
/*************	 Layer   : LIB					******************/
/*************	 SWC   	 : DIO  				******************/
/*************	 Date    : 11 May 2022			******************/
/*************	 Version : V1.0					******************/
/*****************************************************************/
/*****************************************************************/



#ifndef LIB_BIT_MATH_H_
#define LIB_BIT_MATH_H_

#define SET_BIT(BYTE,BIT)			((BYTE)|=(1<<(BIT)))
#define CLEAR_BIT(BYTE,BIT)			((BYTE)&=~(1<<(BIT)))
#define TOGGLE_BIT(BYTE,BIT)		((BYTE)^=(1<<(BIT)))
#define GET_BIT(BYTE,BIT)			(((BYTE)>>(BIT))&(0x01))
	
	
#define SET_BYTE(BYTE)				((BYTE) |= (0xFF))
#define CLEAR_BYTE(BYTE)			((BYTE) &= (0x00))
#define SET_NIBBLE_HIGH(Byte)   	((Byte) |=(0xF0))
#define SET_NIBBLE_LOW(Byte)    	((Byte) |=(0x0F))
#define CLEAR_NIBBLE_HIGH(Byte) 	((Byte) &=(0x0F))
#define CLEAR_NIBBLE_LOW(Byte)  	((Byte) &=(0xF0))


#endif
