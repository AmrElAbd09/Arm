
 
 /**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Led.h"
#include "Port.h"

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
/*******************************************************************************
* Service Name: LedInit
* Service ID[hex]: 0x00
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): None
* Return value: void
* Description: Function to initialize the connected channel using Port MCAL
*******************************************************************************/
void LedInit(void)
{
	PortInit(&strPortConfig);
}
 
/*******************************************************************************
* Service Name: LedTurnOn
* Service ID[hex]: 0x01
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): LedChannel - An identifier for the dedicated led
* Parameters (inout): None
* Parameters (out): None
* Return value: void
* Description: Function to turn on the Led using Dio MCAL
*******************************************************************************/
void LedTurnOn(LedChannel_t LedChannel)
{
	DioWriteChannel(LedChannel, DIO_LEVEL_HIGH);
}
 
/*******************************************************************************
* Service Name: LedTurnOff
* Service ID[hex]: 0x02
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): LedChannel - An identifier for the dedicated led
* Parameters (inout): None
* Parameters (out): None
* Return value: void
* Description: Function to turn off the Led using Dio MCAL
*******************************************************************************/
void LedTurnOff(LedChannel_t LedChannel)
{
	DioWriteChannel(LedChannel, DIO_LEVEL_LOW);
}

/*******************************************************************************
* Service Name: LedToggle
* Service ID[hex]: 0x03
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): LedChannel - An identifier for the dedicated led
* Parameters (inout): None
* Parameters (out): None
* Return value: void
* Description: Function to toggle the Led using Dio MCAL
*******************************************************************************/
void LedToggle(LedChannel_t LedChannel)
{
	DioToggleChannel(LedChannel);
}


 /**********************************************************************************************************************
 *  END OF FILE: Led.c
 *********************************************************************************************************************/
