
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
/* Type definition for DioChannel_t used by the DIO APIs */
typedef uint8 DioChannel_t;

/* Type definition for enuDioPin_t used by the DIO APIs */
typedef enuPortPinNum_t enuDioPin_t;

/* Type definition for enuDioPort_t used by the DIO APIs */
typedef enuPortPortNum_t enuDioPort_t;

/* Type definition for strDioChannelConfig_t used by the DIO APIs */
typedef struct
{
	enuDioPort_t portId;
	enuDioPin_t pinId;
} strDioChannelConfig_t;

/* Type definition for enuDioLevel_t used by the DIO APIs */
typedef enum
{
	DIO_LEVEL_ERROR = -1,
	DIO_LEVEL_LOW = 0,
	DIO_LEVEL_HIGH = 1
} enuDioLevel_t;

/* Type definition for DioPortLevel_t used by the DIO APIs */
typedef uint8 DioPortLevel_t;

#endif  /* DIO_TYPES_H_ */

/**********************************************************************************************************************
 *  END OF FILE: Dio_Types.h
 *********************************************************************************************************************/
