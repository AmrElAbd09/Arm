
 
 /**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Button.h"

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
/*******************************************************************************
* Service Name: ButtonInit
* Service ID[hex]: 0x00
* Sync/Async: Asynchronous
* Reentrancy: Reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): None
* Return value: void
* Description: Function to initialize the connected channel using Port MCAL
*******************************************************************************/
void ButtonInit(void)
{
	PortInit(&strPortConfig);
}
 
/*******************************************************************************
* Service Name: ButtonGetState
* Service ID[hex]: 0x01
* Sync/Async: Asynchronous
* Reentrancy: Reentrant
* Parameters (in): ButtonChannel - An identifier for the dedicated Button
* 				   ButtonAttach  - Identification for the connection type (PULL_UP or PULL_DOWN)
* Parameters (inout): None
* Parameters (out): None
* Return value: enuButtonState_t
* Description: Function to get the state of the Button using Dio MCAL
*******************************************************************************/
enuButtonState_t ButtonGetState(ButtonChannel_t ButtonChannel, enuButtonAttach_t ButtonAttach)
{
	enuDioLevel_t testLevel = DIO_LEVEL_LOW;
	
	enuButtonState_t state= BUTTON_RELEASED;
	
	if (ButtonAttach == PULL_UP)
		testLevel = DIO_LEVEL_LOW;
	else if (ButtonAttach == PULL_DOWN)
		testLevel = DIO_LEVEL_HIGH;
	
	if (DioReadChannel(ButtonChannel) == testLevel)
	{
      state=BUTTON_PRESSED;
		
		while (DioReadChannel(ButtonChannel) == testLevel);
		
	}
		return state;
	
}

 /**********************************************************************************************************************
 *  END OF FILE: Button.c
 *********************************************************************************************************************/
