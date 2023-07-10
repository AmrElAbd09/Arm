


/**********************************************************************
 *  						INCLUDES
 *********************************************************************/
#include "Pwm.h"


/**********************************************************************
 *  						GLOBAL MACROS
 *********************************************************************/
#define SIGNAL_DURATION 	(200)
#define PERCENT				(100)
/**********************************************************************
 *  						GLOBAL VARIABLES
 *********************************************************************/
static volatile uint8 g_u8flag = SET_FLAG;
uint16 g_u16OnPeriod  ,g_u16OffPeriod, g_u16SignalDuration = SIGNAL_DURATION;
static Service_TimerChannelType g_TimerChannle;
static  Service_DeviceChannel g_DeviceChannel;


/**********************************************************************
 *  						LOCAL FUNCTIONS PROTOTYPES 
 *********************************************************************/
 void Pwm_CallBack (void);
 
/**********************************************************************
 *  						FUNCTIONS IMPLEMENTATION
 *********************************************************************/

enu_ErrorReturn Pwm_Init (Service_TimerChannelType TimerChannle, Service_DeviceChannel a_DeviceChannel)
{ 
	g_TimerChannle =TimerChannle ;
	g_DeviceChannel=a_DeviceChannel;
	Gpt_Config.channels[TimerChannle].isEnabled = ENABLED;
	Gpt_Config.channels[TimerChannle].mode = GPT_CHANNEL_MODE_ONESHOT;
	Gpt_Config.channels[TimerChannle].notification = Pwm_CallBack;
	
	Gpt_Init(&Gpt_Config.channels[TimerChannle]);

	return Sys_ok;
}




enu_ErrorReturn Pwm_Start( uint8 a_u8Duty)
{ 
		g_u16OnPeriod= (a_u8Duty * g_u16SignalDuration)/PERCENT ; 
    g_u16OffPeriod= g_u16SignalDuration - g_u16OnPeriod;
	Dio_WriteChannel(g_DeviceChannel,DIO_LEVEL_LOW);
  	Gpt_StartTimer(g_TimerChannle, MSECONDS(g_u16OffPeriod));

	   g_u8flag = SET_FLAG;
	
	return Sys_ok;
}

void Pwm_CallBack(void)
{
	
  if(g_u8flag == SET_FLAG)
	{
		Gpt_StartTimer(g_TimerChannle, MSECONDS(g_u16OnPeriod));
		g_u8flag = CLEAR_FLAG;
		Dio_WriteChannel(g_DeviceChannel,DIO_LEVEL_HIGH);
	}
	else
	{
		Gpt_StartTimer(g_TimerChannle, MSECONDS(g_u16OffPeriod));
		g_u8flag = SET_FLAG;
	  Dio_WriteChannel(g_DeviceChannel,DIO_LEVEL_LOW);
	}
} 


enu_ErrorReturn Pwm_Stop(void)
{
	/* Stop the assosiated */
	Gpt_StopTimer(g_TimerChannle);
	
	/* Turn off the led to stop blinking */
	Led_TurnOff(g_DeviceChannel);
}
