
#ifndef DIO_TYPES_H_
#define DIO_TYPES_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Port_Types.h"

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
/* Type definition for Dio_ChannelType used by the DIO APIs */
typedef uint8 Dio_ChannelType;

/* Type definition for Dio_PinType used by the DIO APIs */
typedef Port_PinType Dio_PinType;

/* Type definition for Dio_PortType used by the DIO APIs */
typedef Port_PortType Dio_PortType;

/* Type definition for enu_DioChannelConfigType used by the DIO APIs */
typedef struct
{
	Dio_PortType portId;
	Dio_PinType pinId;
} str_DioChannelConfigType;

/* Type definition for enu_DioLevelType used by the DIO APIs */
typedef enum
{
	DIO_LEVEL_ERROR = -1,
	DIO_LEVEL_LOW = 0,
	DIO_LEVEL_HIGH = 1
} enu_DioLevelType;

/* Type definition for Dio_PortLevelType used by the DIO APIs */
typedef uint8 Dio_PortLevelType;

#endif  /* DIO_TYPES_H_ */

/**********************************************************************************************************************
 *  END OF FILE: Dio_Types.h
 *********************************************************************************************************************/
