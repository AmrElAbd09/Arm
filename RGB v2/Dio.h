
#ifndef DIO_H_
#define DIO_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Dio_Cfg.h"

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS PROTOTYPES
 *********************************************************************************************************************/
/*******************************************************************************
* Service Name: Dio_ReadChannel
* Service ID[hex]: 0x00
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): ChannelId - DioChannel_t
* Parameters (inout): None
* Parameters (out): None
* Return value: enuDioLevel_t
* Description: Function for DIO read Channel API
*******************************************************************************/
enuDioLevel_t Dio_ReadChannel(DioChannel_t ChannelId);

/*******************************************************************************
* Service Name: Dio_WriteChannel
* Service ID[hex]: 0x00
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): ChannelId - DioChannel_t, Level - enuDioLevel_t
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function for DIO write Channel API
*******************************************************************************/
enuDioLevel_t Dio_WriteChannel(DioChannel_t ChannelId, enuDioLevel_t Level);

/*******************************************************************************
* Service Name: Dio_ToggleChannel
* Service ID[hex]: 0x00
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): ChannelId - DioChannel_t
* Parameters (inout): None
* Parameters (out): None
* Return value: enuDioLevel_t
* Description: Function for DIO flip Channel, then read Channel API
*******************************************************************************/
enuDioLevel_t Dio_ToggleChannel(DioChannel_t ChannelId);

 
#endif  /* DIO_H_ */
/**********************************************************************************************************************
 *  END OF FILE: Dio.h
 *********************************************************************************************************************/
