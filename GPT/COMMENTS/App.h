
 #ifndef APP_H_
 #define APP_H_
 
 /**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Led.h"
#include "Button.h"
 #include "Blink.h"
/**********************************************************************************************************************
*  GLOBAL CONSTANT MACROS
*********************************************************************************************************************/
#define 	LED_1			DIO_CONFIG_LED1_CHANNEL_ID
#define 	LED_2			DIO_CONFIG_LED2_CHANNEL_ID
#define 	LED_3			DIO_CONFIG_LED3_CHANNEL_ID
#define 	BUTTON_1		DIO_CONFIG_SWITCH1_CHANNEL_ID
#define 	BUTTON_2		DIO_CONFIG_SWITCH2_CHANNEL_ID

#define		BLINKING_GPTM	TIMER0_16BIT
 
 #define SET_FLAG	(1)
 #define CLEAR_FLAG (0)
 #define FIRST_STAGE (1)
 #define SECOND_STAGE (2)
 #define THIRD_STAGE (3)
 
 #define FIRST_BLINKING_MODE	(30)
 #define SECOND_BLINKING_MODE	(60)
 #define THIRD_BLINKING_MODE	(90)
 
 #define SIGNAL_CONV 			(1000)
 #define PERCENT					(100)
 
 #define FREQUENCY_CHOICE (2)
/**********************************************************************************************************************
*  GLOBAL FUNCTIONS PROTOTYPES
*********************************************************************************************************************/
void app_init(void);
void app_start (void);
 
 #endif /* APP_H_ */
 /**********************************************************************************************************************
 *  END OF FILE: App.h
 *********************************************************************************************************************/