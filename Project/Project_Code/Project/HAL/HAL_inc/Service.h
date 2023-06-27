

#ifndef SERVICE_H_
#define SERVICE_H_

/**********************************************************************
 *  						INCLUDES
 *********************************************************************/
#include "Service_Types.h"

/**********************************************************************
 *  						FUNCTIONS PROTOTYPES
 *********************************************************************/
enu_ErrorReturn Service_TimerInit (Service_TimerChannelType TimerChannle , void(*ptrf)(void));
enu_ErrorReturn Service_TimerStart (Service_TimerChannelType TimerChannle, uint16 Time);


#endif