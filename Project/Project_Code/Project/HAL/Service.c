


/**********************************************************************
 *  						INCLUDES
 *********************************************************************/
#include "Service.h"




/**********************************************************************
 *  						FUNCTIONS IMPLEMENTATION
 *********************************************************************/

enu_ErrorReturn Service_TimerInit (Service_TimerChannelType TimerChannle , void(*ptrf)(void))
{
	if(ptrf == NULL_PTR)
	{
		return Sys_NotOK;
	}
	Gpt_Config.channels[TimerChannle].isEnabled = ENABLED;
	Gpt_Config.channels[TimerChannle].mode = GPT_CHANNEL_MODE_ONESHOT;
	Gpt_Config.channels[TimerChannle].notification = ptrf;	
	Gpt_Init(&Gpt_Config.channels[TimerChannle]);
	
	return Sys_ok;
}



enu_ErrorReturn Service_TimerStart (Service_TimerChannelType TimerChannle, uint16 a_u16Time)
{
	Gpt_StartTimer(TimerChannle, MSECONDS(a_u16Time));
	
	return Sys_ok;
}









