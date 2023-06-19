/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  File:  		  Led.h
 *  Module:  	  Led
 *  Description:  Header file for Led driver
 *  -------------------------------------------------------------------------------------------------------------------
 *********************************************************************************************************************/
#ifndef LED_H_
#define LED_H_

/**********************************************************************************************************************
* INCLUDES
*********************************************************************************************************************/
#include "Std_Types.h"
#include "Dio.h"
 
/**********************************************************************************************************************
*  GLOBAL DATA PROTOTYPES
*********************************************************************************************************************/
typedef DioChannel_t LedChannel_t;
 
 /**********************************************************************************************************************
 *  GLOBAL FUNCTIONS PROTOTYPES
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
 void Led_Init(void);
 
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
 void Led_TurnOn(LedChannel_t LedChannel);
 
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
 void Led_TurnOff(LedChannel_t LedChannel);
 
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
void LedToggle(LedChannel_t LedChannel);

 
 #endif /* LED_H_ */
 /**********************************************************************************************************************
 *  END OF FILE: Led.h
 *********************************************************************************************************************/
 