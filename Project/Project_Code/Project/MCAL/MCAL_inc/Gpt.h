
#ifndef Gpt_H_
#define Gpt_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Gpt_Types.h"
#include "Gpt_Cfg.h"

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS PROTOTYPES
 *********************************************************************************************************************/
/*******************************************************************************
* Service Name: Gpt_Init
* Service ID[hex]: 0x00
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): ConfigPtr - Pointer to post-build (Linking) configuration data
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to Setup the pin configuration:
*              - Initialize the hardware time module according to config.
*              - Disable all interrupts notifications
*              - Set the operation mode of GPT to ONESHOT or CONTINOUS Mode
*              - Start all the enabled GPT Predefined timers at value = 0
*******************************************************************************/
enu_ErrorReturn Gpt_Init(const str_GptChannelConfigType* ConfigPtr);

/*******************************************************************************
* Service Name: Gpt_DisableNotification
* Service ID[hex]: 0x01
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): ChannelId - Pointer to enu_GptChannelType data
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to disable the notification when the dedicated timer hits the target
*******************************************************************************/
enu_ErrorReturn Gpt_DisableNotification(enu_GptChannelType ChannelId);

/*******************************************************************************
* Service Name: Gpt_EnableNotification
* Service ID[hex]: 0x02
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): ChannelId - Pointer to enu_GptChannelType data
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to enable the notification when the dedicated timer hits the target
*******************************************************************************/
enu_ErrorReturn Gpt_EnableNotification(enu_GptChannelType ChannelId);

/*******************************************************************************
* Service Name: Gpt_StartTimer
* Service ID[hex]: 0x03
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): ChannelId - Pointer to enu_GptChannelType data, Value - the timer value in microseconds
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to make the dedicated timer start counting
*******************************************************************************/
enu_ErrorReturn Gpt_StartTimer(enu_GptChannelType ChannelId, Gpt_ValueType Value);

/*******************************************************************************
* Service Name: Gpt_StopTimer
* Service ID[hex]: 0x04
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): ChannelId - Pointer to enu_GptChannelType data
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to make the dedicated timer stop counting
*******************************************************************************/
enu_ErrorReturn Gpt_StopTimer(enu_GptChannelType ChannelId);

/*******************************************************************************
* Service Name: Gpt_GetTimeElapsed
* Service ID[hex]: 0x05
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): ChannelId - Pointer to enu_GptChannelType data
* Parameters (inout): None
* Parameters (out): None
* Return value: Gpt_ValueType
* Description: Function to get the counted time until the call's moment
*******************************************************************************/
Gpt_ValueType Gpt_GetTimeElapsed(enu_GptChannelType ChannelId);

/*******************************************************************************
* Service Name: Gpt_GetTimeRemaining
* Service ID[hex]: 0x06
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): ChannelId - Pointer to enu_GptChannelType data
* Parameters (inout): None
* Parameters (out): None
* Return value: Gpt_ValueType
* Description: Function to get the remaining time to hit the target from the calling's moment
*******************************************************************************/
Gpt_ValueType Gpt_GetTimeRemaining(enu_GptChannelType ChannelId);

/*******************************************************************************
* Service Name: Gpt_GetPredefTimerValue
* Service ID[hex]: 0x07
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): ConfigPtr - Pointer to post-build (Linking) configuration data
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to return the current value of GPT PredefTimer passed
*******************************************************************************/
Std_ReturnType Gpt_GetPredefTimerValue(Gpt_PredefTimerType PredefTimer, uint32* TimeValuePtr);
 
#endif  /* Gpt_H_ */

/**********************************************************************************************************************
 *  END OF FILE: Gpt.h
 *********************************************************************************************************************/
