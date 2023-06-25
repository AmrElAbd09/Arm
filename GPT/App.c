/**********************************************************************
 *  						INCLUDES
 *********************************************************************/
#include "App.h"

/**********************************************************************
 *  						GLOBAL VARIABLES
 *********************************************************************/
 
uint16 g_u16OnPeriod ,g_u16OffPeriod, g_u16SignalDuration ;

/**********************************************************************
 *  						LOCAL FUNCTIONS PROTOTYPES 
 *********************************************************************/
 
void app_PwmParameters (uint16 a_u16Frequency ,uint16 a_u16Duty ) ;

/**********************************************************************
 *  						FUNCTIONS IMPLEMENTATION
 *********************************************************************/
 
 
void app_start (void)
{
		
 uint8 u8DutyPercentage = FIRST_BLINKING_MODE;
 uint8 u8StateFlag = CLEAR_FLAG;
 uint8 u8Stage = SET_FLAG;
 uint8 u8PressFlag = CLEAR_FLAG;
	
	if (Button_GetState(BUTTON_1,PULL_UP )== BUTTON_PRESSED)
	{	      
	   u8StateFlag=SET_FLAG;
			app_PwmParameters (FREQUENCY_CHOICE,FIRST_BLINKING_MODE);  
	}   	
  while(u8StateFlag==SET_FLAG)
	{	
		Blink_Start2(BLINKING_GPTM, g_u16SignalDuration , g_u16OnPeriod, g_u16OffPeriod);	
	
		if (Button_GetState(BUTTON_1,PULL_UP )== BUTTON_PRESSED)
		{	      
			 u8PressFlag=SET_FLAG;
		}   
		if ( u8PressFlag==SET_FLAG)
		{ 
			u8Stage++;  
			if (u8Stage == FIRST_STAGE) 
			{
				u8DutyPercentage = FIRST_BLINKING_MODE;
			} 
			else if (u8Stage == SECOND_STAGE) 
			{
				u8DutyPercentage = SECOND_BLINKING_MODE;
			} 
			else if (u8Stage == THIRD_STAGE) 
			{
				u8DutyPercentage = THIRD_BLINKING_MODE;
			} 
			else 
			{
				Blink_Stop(BLINKING_GPTM, LED_3);
				u8StateFlag = CLEAR_FLAG;
				u8Stage = FIRST_STAGE;
			}
			app_PwmParameters (FREQUENCY_CHOICE,u8DutyPercentage);            
			u8PressFlag=CLEAR_FLAG;
		}

	
	  
	}
}
void app_PwmParameters (uint16 a_u16Frequency ,uint16 a_u16Duty ) 
{
    g_u16SignalDuration=(SIGNAL_CONV/a_u16Frequency);                   //in ms   
	  g_u16OnPeriod= (a_u16Duty * g_u16SignalDuration)/PERCENT ; 
    g_u16OffPeriod= g_u16SignalDuration-g_u16OnPeriod;

} 
void app_init(void)
{
	
			Led_Init();
	  Button_Init();
	  blink_init(BLINKING_GPTM,LED_3);
}
