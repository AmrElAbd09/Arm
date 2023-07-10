
 #ifndef BUTTON_H_
 #define BUTTON_H_
 
/**********************************************************************************************************************
* INCLUDES
*********************************************************************************************************************/
#include "Std_Types.h"
#include "Port.h"
#include "Dio.h"

/**********************************************************************************************************************
*  GLOBAL DATA PROTOTYPES
*********************************************************************************************************************/
typedef Dio_ChannelType Button_ButtonChannelType;
typedef Port_PinInternalAttachType Button_ButtonAttachType;

#define 	BUTTON_1		DIO_CONFIG_SWITCH1_CHANNEL_ID
#define 	BUTTON_2		DIO_CONFIG_SWITCH2_CHANNEL_ID


typedef enum
{
	BUTTON_RELEASED = 0,
	BUTTON_PRESSED = 1
} enu_ButtonState;

/**********************************************************************************************************************
*  GLOBAL FUNCTIONS PROTOTYPES
*********************************************************************************************************************/
/*******************************************************************************
* Service Name: Button_Init
* Service ID[hex]: 0x00
* Sync/Async: Asynchronous
* Reentrancy: Reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): None
* Return value: void
* Description: Function to initialize the connected channel using Port MCAL
*******************************************************************************/
enu_ErrorReturn Button_Init(void);
 
/*******************************************************************************
* Service Name: Button_GetState
* Service ID[hex]: 0x01
* Sync/Async: Asynchronous
* Reentrancy: Reentrant
* Parameters (in): ButtonChannel - An identifier for the dedicated Button
* 				   ButtonAttach  - Identification for the connection type (PULL_UP or PULL_DOWN)
* Parameters (inout): None
* Parameters (out): None
* Return value: enu_ButtonState
* Description: Function to get the state of the Button using Dio MCAL
*******************************************************************************/
enu_ButtonState Button_GetState(Button_ButtonChannelType a_ButtonChannel, Button_ButtonAttachType a_ButtonAttach);



enu_ErrorReturn Button_IntSetCallback (void (*a_Ptrf)(void));

 #endif /* BUTTON_H_ */
 /**********************************************************************************************************************
 *  END OF FILE: Button.h
 *********************************************************************************************************************/