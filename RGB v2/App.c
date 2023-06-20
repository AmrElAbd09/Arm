
/**********************************************************************
 *  											INCLUDES
 *********************************************************************/
#include "App.h"

/**********************************************************************
 *  											GLOBAL VARIABLES
 *********************************************************************/
volatile uint8 u8LedCounter=1,flag=0;

/**********************************************************************
 *  											STATIC FUNCTIONS PROTOTYPES
 *********************************************************************/
void App_SystickLogic(void);


/**********************************************************************
 *  											FUNCTIONS IMPLEMENTATION
 *********************************************************************/
void App_SystickLogic(void)
{  

	
	Led_TurnOff(LED_1); 
	Led_TurnOff(LED_2);
	Led_TurnOff(LED_3);
	if(u8LedCounter<4)
	{
		u8LedCounter++;
	}
	else
	{
	   u8LedCounter=1 ;
	} 
	   Systick_StopInterval();
	
}
 
/*======================================================================*/
	void App_Init(void)
{
	Led_Init();
	Button_Init();
	Systick_Init();
	SysTick_SetCallBack(App_SystickLogic);
}

/*======================================================================*/

	void App_Start(void)
{
	if (Button_GetState(BUTTON_1,PULL_UP )== BUTTON_PRESSED)
	{
			     flag=1;
			     Systick_SetIntervalSingle(1000);  

	} 
	if (flag==1)
		{
			if(u8LedCounter == 0)
			{
				Led_TurnOff(LED_1); //all off at first 
				Led_TurnOff(LED_2);
				Led_TurnOff(LED_3);
				flag=0;
			}
			else if (u8LedCounter == 1)
			{
				Led_TurnOn(LED_1);  //red
				Led_TurnOff(LED_2);
				Led_TurnOff(LED_3);
				flag=0;
			}
			else if (u8LedCounter == 2)
			{
				Led_TurnOn(LED_3);  //green
				Led_TurnOff(LED_1);
				Led_TurnOff(LED_2);
				flag=0;
			}
			else if	(u8LedCounter == 3)
			{
				Led_TurnOn(LED_2);  //blue
				Led_TurnOff(LED_1);
				Led_TurnOff(LED_3);
				flag=0;
			}
			else
			{
				Led_TurnOn(LED_1);  //allon
				Led_TurnOn(LED_2);
				Led_TurnOn(LED_3);
				flag=0;
			}		
		} 
}	



