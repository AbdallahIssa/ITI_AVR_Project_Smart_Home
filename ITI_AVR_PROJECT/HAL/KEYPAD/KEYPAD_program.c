#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include <util/delay.h>
#include "../../HAL/KEYPAD/KEYPAD_config.h"
#include "../../HAL/KEYPAD/KEYPAD_interface.h"
#include "../../HAL/KEYPAD/KEYPAD_private.h"

u8 KEYPAD_u8Values[ROWS_NO][COLUMNS_NO] = {
		{'/', '9', '8', '7'},
		{'X', '6', '5', '4'},
		{'-', '3', '2', '1'},
		{'+', '=', '0', 'd'}
};

void KEYPAD_vInit(void)
{
	#if KEYPAD_PORT_INPUT == HIGH_NIBBLE
		GPIO_vSetPortDirection(KEYPAD_PORT, 0x0F);
		GPIO_vSetPortValue(KEYPAD_PORT, 0xF0);//Activate Pull-up resistor
	#elif KEYPAD_PORT_INPUT == LOW_NIBBLE
		GPIO_vSetPortDirection(KEYPAD_PORT, 0xF0);
		GPIO_vSetPortValue(KEYPAD_PORT, 0x0F);//Activate Pull-up resistor
	#endif
}

u8   KEYPAD_u8GetPressed(void)
{
#if 0
	u8 Local_u8ReturnValue = 10; // Indication for Nothing
	u8 Local_u8RowIdx=0, Local_u8ColumnIdx=0;
	for(Local_u8ColumnIdx=0; Local_u8ColumnIdx<COLUMNS_NO; Local_u8ColumnIdx++)
	{
		GPIO_vSetPinValue(KEYPAD_PORT, Local_u8ColumnIdx, LOW);
		for(Local_u8RowIdx=0; Local_u8RowIdx<ROWS_NO; Local_u8RowIdx++)
		{
			if(GPIO_u8GetPinValue(KEYPAD_PORT, Local_u8RowIdx + 4) == 0)
			{
				Local_u8ReturnValue = KEYPAD_u8Values[Local_u8RowIdx][Local_u8ColumnIdx];
				while(GPIO_u8GetPinValue(KEYPAD_PORT, Local_u8RowIdx + 4) == 0);
				_delay_ms(10);
				return Local_u8ReturnValue;
			}
		}
		GPIO_vSetPinValue(KEYPAD_PORT, Local_u8ColumnIdx, HIGH);
	}
	return Local_u8ReturnValue;
#endif

#if 1
	u8 pressed_key=0;
	u8 col, row;
	u8 flag = 0;
	while (flag == 0)
	{
		for(col=0;col<COLUMNS_NO;col++)
		{
			CLEAR_BIT(PORTA,col);
			for(row=0;row<ROWS_NO;row++)
			{
				if(GET_BIT(PINA,(row+4))==0)
				{
					pressed_key = (row+(col*4)+1);
					while(GET_BIT(PINA,(row+4))==0);//tool mnt dayes mt3ml4 haga lma t4il eidk
					_delay_ms(5);
					flag = 1;
					break;
				}
			}
			SET_BIT(PORTA,col);
			if (flag == 1)
				break;
		}
	}
	return pressed_key;

#endif

}
