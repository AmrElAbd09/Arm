
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
* Service Name: DioReadChannel
* Service ID[hex]: 0x00
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): ChannelId - DioChannel_t
* Parameters (inout): None
* Parameters (out): None
* Return value: enuDioLevel_t
* Description: Function for DIO read Channel API
*******************************************************************************/
enuDioLevel_t DioReadChannel(DioChannel_t ChannelId);

/*******************************************************************************
* Service Name: DioWriteChannel
* Service ID[hex]: 0x00
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): ChannelId - DioChannel_t, Level - enuDioLevel_t
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function for DIO write Channel API
*******************************************************************************/
void DioWriteChannel(DioChannel_t ChannelId, enuDioLevel_t Level);

/*******************************************************************************
* Service Name: DioToggleChannel
* Service ID[hex]: 0x00
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): ChannelId - DioChannel_t
* Parameters (inout): None
* Parameters (out): None
* Return value: enuDioLevel_t
* Description: Function for DIO flip Channel, then read Channel API
*******************************************************************************/
enuDioLevel_t DioToggleChannel(DioChannel_t ChannelId);

/*******************************************************************************
* Service Name: DioReadPort
* Service ID[hex]: 0x00
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): PortId - enuDioPort_t
* Parameters (inout): None
* Parameters (out): None
* Return value: DioPortLevel_t
* Description: Function for DIO read Port API
*******************************************************************************/
DioPortLevel_t DioReadPort(enuDioPort_t PortId);

/*******************************************************************************
* Service Name: DioWritePort
* Service ID[hex]: 0x00
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): PortId - enuDioPort_t, Level - DioPortLevel_t
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function for DIO write Port API
*******************************************************************************/
void DioWritePort(enuDioPort_t PortId, DioPortLevel_t Level);
 
#endif  /* DIO_H_ */
/**********************************************************************************************************************
 *  END OF FILE: Dio.h
 *********************************************************************************************************************/
