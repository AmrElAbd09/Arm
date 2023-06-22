/**********************************************************************
 *  						INCLUDES
 *********************************************************************/
#include "App.h"

/**********************************************************************
 *  						GLOBAL VARIABLES
 *********************************************************************/
 
uint16 u16OnPeriod =150 ,u16OffPeriod=350, u16SignalDuration=500 ;

/**********************************************************************
 *  						LOCAL FUNCTIONS PROTOTYPES 
 *********************************************************************/
void pwm_G (uint16 u16Frequency ,uint16 u16Duty ) ;

/**********************************************************************
 *  						FUNCTIONS IMPLEMENTATION
 *********************************************************************/
 
 
void app_start (void)
{
		
 uint8 u8DutyPercentage = 30;
 uint8 u8StateFlag = CLEAR_FLAG;
 uint8 u8Stage = SET_FLAG;
 uint8 u8PressFlag = CLEAR_FLAG;
	
	if (Button_GetState(BUTTON_1,PULL_UP )== BUTTON_PRESSED)
	{	      
	   u8StateFlag=SET_FLAG;
			pwm_G (2,30);  
	}   	
  while(u8StateFlag==SET_FLAG)
	{	
		Blink_Start2(BLINKING_GPTM, u16SignalDuration , u16OnPeriod, u16OffPeriod);	
	
		if (Button_GetState(BUTTON_1,PULL_UP )== BUTTON_PRESSED)
		{	      
			 u8PressFlag=SET_FLAG;
		}   
		if ( u8PressFlag==SET_FLAG)
		{ 
			u8Stage++;  
			if (u8Stage == FIRST_STAGE) 
			{
				u8DutyPercentage = 30;
			} 
			else if (u8Stage == SECOND_STAGE) 
			{
				u8DutyPercentage = 60;
			} 
			else if (u8Stage == THIRD_STAGE) 
			{
				u8DutyPercentage = 90;
			} 
			else 
			{
				Blink_Stop(BLINKING_GPTM, LED_3);
				u8StateFlag = CLEAR_FLAG;
				u8Stage = 1;
			}
			pwm_G (2,u8DutyPercentage);            
			u8PressFlag=CLEAR_FLAG;
		}

	
	  
	}
}
void pwm_G (uint16 u16Frequency ,uint16 u16Duty ) 
{
    u16SignalDuration=(1000/u16Frequency);                   //in ms   
	  u16OnPeriod= (u16Duty * u16SignalDuration)/100 ; 
    u16OffPeriod= u16SignalDuration-u16OnPeriod;

} 
void app_init(void)
{
	
			Led_Init();
	  Button_Init();
	  blink_init(BLINKING_GPTM,LED_3);
}
