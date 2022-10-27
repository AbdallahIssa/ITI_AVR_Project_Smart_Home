#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "GIE_private.h"

void GIE_vEnableGIE(void)
{
	SET_BIT(SREG, SREG_BIT_I);
}

void GIE_vDisableGIE(void)
{
	CLEAR_BIT(SREG, SREG_BIT_I);
}
