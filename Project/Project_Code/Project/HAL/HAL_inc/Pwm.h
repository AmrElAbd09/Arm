

#ifndef PWM_H_
#define PWM_H_

/**********************************************************************
 *  						INCLUDES
 *********************************************************************/
#include "Service_Types.h"

/**********************************************************************
 *  						FUNCTIONS PROTOTYPES
 *********************************************************************/
 
enu_ErrorReturn Pwm_Init (Service_TimerChannelType TimerChannle, Service_DeviceChannel a_DeviceChannel);
enu_ErrorReturn Pwm_Start( uint8 a_u8Duty);
enu_ErrorReturn Pwm_Stop(void);

#endif