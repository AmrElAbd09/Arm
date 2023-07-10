/**********************************************************************
 *  						INCLUDES
 *********************************************************************/
#include "App.h"


/**********************************************************************
 *  						GLOBAL VARIABLES
 *********************************************************************/	
static uint8 g_u8Sequence = READY_STAGE;
static uint8 g_u8StartFlag = CLEAR_FLAG;
static uint8 g_u8TimerFlag = SET_FLAG;


/**********************************************************************
 *  						LOCAL FUNCTIONS PROTOTYPES 
 *********************************************************************/
 void App_CarReadyStage (void);
 void App_CarStopStage (void);
 void App_LongSideStage(void);
 void App_Rotate90degreeStage (void);
 void App_ShortSideStage(void);
 void App_SequenceChange (void); 
 void App_ButtonInterrupt (void);

/**********************************************************************
 *  						FUNCTIONS IMPLEMENTATION
 *********************************************************************/

void App_ButtonInterrupt (void)
{
	Led_TurnOff(LED_1);
	Led_TurnOff(LED_2);
	Led_TurnOff(LED_3);
	g_u8StartFlag = CLEAR_FLAG;
	 Pwm_Stop();
}

void App_init(void)
{
	Led_Init();	
	Button_Init();
	Service_TimerInit(SERVICE_GPTM, App_SequenceChange);
	Button_IntSetCallback(App_ButtonInterrupt);
	Pwm_Init (PWM_GPTM, MOTOR_EN);
}

/*******************************************************************************************************************************************
**DESCRIPTION:-
this function is used to do the following :
 - led 3 on
 - motor stop
 - Load timer with 1000 milliseconds
*/
void App_CarReadyStage (void)
{
	Led_TurnOff(LED_1);
	Led_TurnOff(LED_2);
	Led_TurnOff(LED_3);
	Led_TurnOn(LED_3);
	
	Service_TimerStart(SERVICE_GPTM, READY_STAGE_TIME);
	
	Pwm_Stop();	
	MOTOR_Stop(); 
	
	

}

/*******************************************************************************************************************************************
**DESCRIPTION:-
this function is used to do the following :
 - led 3 on
 - motor stop
 - Load timer with 500 milliseconds
*/
void App_CarStopStage (void)
{
	Led_TurnOff(LED_1);
	Led_TurnOff(LED_2);
	Led_TurnOff(LED_3);
	Led_TurnOn(LED_3);
	
	Service_TimerStart(SERVICE_GPTM, STOP_TIME);
	
	Pwm_Stop();	
	MOTOR_Stop();


}


/*******************************************************************************************************************************************
**DESCRIPTION:-
this function is used for the following :
 - led 1 on
 - motors move forward
 - speed of motors is 50%
 - Load timer with 3000 milliseconds 
*/
void App_LongSideStage(void)
{
	Led_TurnOff(LED_1);
	Led_TurnOff(LED_2);
	Led_TurnOff(LED_3);
	Led_TurnOn(LED_1);
	
	Service_TimerStart(SERVICE_GPTM, LONG_SIDE_TIME);
	
	Pwm_Start(LONG_SIDE_PWM);
	MOTOR_Forward();

}


/*******************************************************************************************************************************************
**DESCRIPTION:-
this function is used for the following :
 - led 4 is on
 - motors rotate to the right
*/
void App_Rotate90degreeStage (void)
{
	Led_TurnOff(LED_1);
	Led_TurnOff(LED_2);
	Led_TurnOff(LED_3);
	Led_TurnOn(LED_1);
	Led_TurnOn(LED_2);
	Led_TurnOn(LED_3);

	Service_TimerStart(SERVICE_GPTM, ROTATING_TIME);
	
	Pwm_Start(ROTATING_PWM);
	MOTOR_RotateRight();
	
}


/*******************************************************************************************************************************************
**DESCRIPTION:-
this function is used for the following :
 - led 2 on
 - motors move forward
 - speed of motors is 30%
Load timer with 2000 milliseconds
*/
void App_ShortSideStage()
{
	Led_TurnOff(LED_1);
	Led_TurnOff(LED_2);
	Led_TurnOff(LED_3);
	Led_TurnOn(LED_2);
	
	Service_TimerStart(SERVICE_GPTM, SHORT_SIDE_TIME);
	
	Pwm_Start(SHORT_SIDE_PWM);
	MOTOR_Forward();
}

/*******************************************************************************************************************************************
**DESCRIPTION:-
this function is used for the following :
 -increment g_u8Sequence by 1 unless it's in the last stage
*/
void App_SequenceChange (void)
{
	if(g_u8Sequence < LAST_STAGE)
	{
		g_u8Sequence++ ;
		g_u8TimerFlag = SET_FLAG;
	}
	else
	{
		g_u8Sequence = FIRST_STAGE;
		g_u8TimerFlag = SET_FLAG;
	}	
}



void App_start(void)
{
	if (Button_GetState(BUTTON_1,PULL_UP )== BUTTON_PRESSED)
	{
			g_u8StartFlag = SET_FLAG;
	}
	
	while(g_u8StartFlag == SET_FLAG) 					//Button 2 interrupt to Clear this flag
		{
		
			if (g_u8Sequence == READY_STAGE && g_u8TimerFlag == SET_FLAG)
			{
				App_CarReadyStage();
				g_u8TimerFlag = CLEAR_FLAG;
			}
		
			else if(g_u8Sequence == FIRST_STAGE && g_u8TimerFlag == SET_FLAG)
			{
				App_LongSideStage();
				g_u8TimerFlag = CLEAR_FLAG;
			}
	
			else if (g_u8Sequence == SECOND_STAGE && g_u8TimerFlag == SET_FLAG)
			{		
				App_CarStopStage();
				g_u8TimerFlag = CLEAR_FLAG;
			}
	
			else if (g_u8Sequence == THIRD_STAGE && g_u8TimerFlag == SET_FLAG)
			{				
				App_Rotate90degreeStage();
				g_u8TimerFlag = CLEAR_FLAG;				
			}
	
			else if(g_u8Sequence == FOURTH_STAGE && g_u8TimerFlag == SET_FLAG)
			{			
				App_CarStopStage();
				g_u8TimerFlag = CLEAR_FLAG;
			}
			
			else if(g_u8Sequence == FIFTH_STAGE && g_u8TimerFlag == SET_FLAG)
			{		
				App_ShortSideStage();
				g_u8TimerFlag = CLEAR_FLAG;
			}
			
			else if(g_u8Sequence == SIXTH_STAGE && g_u8TimerFlag == SET_FLAG)
			{
				App_CarStopStage();
				g_u8TimerFlag = CLEAR_FLAG;
			}
			
			else if (g_u8Sequence == SEVENTH_STAGE && g_u8TimerFlag == SET_FLAG)
			{	
				App_Rotate90degreeStage();
				g_u8TimerFlag = CLEAR_FLAG;				
			}
			
			else if (g_u8Sequence == LAST_STAGE && g_u8TimerFlag == SET_FLAG)
			{		
				App_CarStopStage();	
				g_u8TimerFlag = CLEAR_FLAG;
			}
			else
			{
				//Do nothing
			}
			
		}
}

