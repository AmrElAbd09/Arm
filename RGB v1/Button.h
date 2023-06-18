/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  File:  		  Button.h
 *  Module:  	  Button
 *  Description:  Header file for Button driver
 *  -------------------------------------------------------------------------------------------------------------------
 *********************************************************************************************************************/
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
typedef DioChannel_t ButtonChannel_t;
typedef enuPortPinInternalAttach_t enuButtonAttach_t;

typedef enum
{
	BUTTON_RELEASED = 0,
	BUTTON_PRESSED = 1
} enuButtonState_t;

/**********************************************************************************************************************
*  GLOBAL FUNCTIONS PROTOTYPES
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
void ButtonInit(void);
 
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
enuButtonState_t ButtonGetState(ButtonChannel_t ButtonChannel, enuButtonAttach_t ButtonAttach);

 #endif /* BUTTON_H_ */
 /**********************************************************************************************************************
 *  END OF FILE: Button.h
 *********************************************************************************************************************/
 