#include "App.h"


int main(void)
{ 
	uint8 u8LedCounter=0;
	LedInit();
	ButtonInit();
	
	
	while(1)
	{
		if (ButtonGetState(BUTTON_2,PULL_UP )== BUTTON_PRESSED)
	{	
	    	u8LedCounter++;	
	} 
	switch (u8LedCounter)
	{ 
		case 0 :
		LedTurnOff(LED_1); //all off at first 
		LedTurnOff(LED_2);
		LedTurnOff(LED_3);
		break;
		case 1 :
		LedTurnOn(LED_1);  //red
		LedTurnOff(LED_2);
		LedTurnOff(LED_3);
		break;
		case 2 :
		LedTurnOn(LED_3);  //green
		LedTurnOff(LED_1);
		LedTurnOff(LED_2);
		break;
		case 3 :
		LedTurnOn(LED_2);  //blue
		LedTurnOff(LED_1);
		LedTurnOff(LED_3);
		break;
		case 4 :
		LedTurnOn(LED_1);  //allon
		LedTurnOn(LED_2);
		LedTurnOn(LED_3);
		break;
		case 5 :
		LedTurnOff(LED_1);
		LedTurnOff(LED_2);
		LedTurnOff(LED_3);
		u8LedCounter=0;
		break;	
	} 	
	}	
	return 0;
}
