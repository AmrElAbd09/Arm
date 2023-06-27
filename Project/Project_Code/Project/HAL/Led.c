
 
 /**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Led.h"


/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
/*******************************************************************************
* Service Name: Led_Init
* Service ID[hex]: 0x00
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): None
* Return value: void
* Description: Function to initialize the connected channel using Port MCAL
*******************************************************************************/
enu_ErrorReturn Led_Init(void)
{
	Port_Init(&Port_ConfigType);
	return Sys_ok;
}
 
/*******************************************************************************
* Service Name: Led_TurnOn
* Service ID[hex]: 0x01
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): LedChannel - An identifier for the dedicated led
* Parameters (inout): None
* Parameters (out): None
* Return value: void
* Description: Function to turn on the Led using Dio MCAL
*******************************************************************************/
enu_ErrorReturn Led_TurnOn(Led_LedChannelType LedChannel)
{
	Dio_WriteChannel(LedChannel, DIO_LEVEL_HIGH);
	return Sys_ok;
}
 
/*******************************************************************************
* Service Name: Led_TurnOff
* Service ID[hex]: 0x02
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): LedChannel - An identifier for the dedicated led
* Parameters (inout): None
* Parameters (out): None
* Return value: void
* Description: Function to turn off the Led using Dio MCAL
*******************************************************************************/
enu_ErrorReturn Led_TurnOff(Led_LedChannelType LedChannel)
{
	Dio_WriteChannel(LedChannel, DIO_LEVEL_LOW);
	return Sys_ok;
}

/*******************************************************************************
* Service Name: Led_Toggle
* Service ID[hex]: 0x03
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): LedChannel - An identifier for the dedicated led
* Parameters (inout): None
* Parameters (out): None
* Return value: void
* Description: Function to toggle the Led using Dio MCAL
*******************************************************************************/
enu_ErrorReturn Led_Toggle(Led_LedChannelType LedChannel)
{
	Dio_FlipChannel(LedChannel);
	return Sys_ok;
}

/*******************************************************************************
* Service Name: Led_RefreshOutput
* Service ID[hex]: 0x04
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): LedChannel - An identifier for the dedicated led
* Parameters (inout): None
* Parameters (out): None
* Return value: void
* Description: Function to refresh the Led's state using Dio MCAL
*******************************************************************************/
enu_ErrorReturn Led_RefreshOutput(Led_LedChannelType LedChannel)
{
	/* Read the current state */
    enu_DioLevelType state = Dio_ReadChannel(LedChannel);
	
	/* Re-write the same state */
    Dio_WriteChannel(LedChannel, state);
	return Sys_ok;
}
 /**********************************************************************************************************************
 *  END OF FILE: Led.c
 *********************************************************************************************************************/