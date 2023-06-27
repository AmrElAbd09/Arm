
 #ifndef APP_H_
 #define APP_H_
 
 /**********************************************************************************************************************
 * 							INCLUDES
 *********************************************************************************************************************/
#include "Led.h"
#include "Button.h"
#include "motor.h"
#include "Service.h"
#include "Pwm.h"
/**********************************************************************************************************************
*   						GLOBAL CONSTANT MACROS
*********************************************************************************************************************/
#define 	LED_1			DIO_CONFIG_LED1_CHANNEL_ID
#define 	LED_2			DIO_CONFIG_LED2_CHANNEL_ID
#define 	LED_3			DIO_CONFIG_LED3_CHANNEL_ID
#define 	LED_4			DIO_CONFIG_LED4_CHANNEL_ID

#define 	BUTTON_1		DIO_CONFIG_SWITCH1_CHANNEL_ID
#define 	BUTTON_2		DIO_CONFIG_SWITCH2_CHANNEL_ID

#define 	MOTOR1_D1A			DIO_CONFIG_MOTOR1_D1A_CHANNEL_ID  
#define 	MOTOR1_D1B			DIO_CONFIG_MOTOR1_D1B_CHANNEL_ID
#define 	MOTOR2_D2A			DIO_CONFIG_MOTOR2_D2A_CHANNEL_ID
#define 	MOTOR2_D2B			DIO_CONFIG_MOTOR2_D2B_CHANNEL_ID

#define 	MOTOR1_EN		   	DIO_CONFIG_MOTOR1_EN_CHANNEL_ID  
#define 	MOTOR2_EN			DIO_CONFIG_MOTOR2_EN_CHANNEL_ID


#define		BLINKING_GPTM		TIMER0_16BIT
#define 	SERVICE_GPTM		TIMER0_16BIT
#define		PWM_GPTM				TIMER1_16BIT

#define LONG_SIDE_TIME	(3000)
#define LONG_SIDE_PWM	(50)

#define SHORT_SIDE_TIME	(2000)
#define SHORT_SIDE_PWM	(30)

#define ROTATING_TIME	(1000)
#define ROTATING_PWM	(20)
 
#define READY_STAGE_TIME (1000)
#define STOP_TIME (500)
 
 
 #define READY_STAGE		(0)
 #define FIRST_STAGE 		(1)
 #define SECOND_STAGE 		(2)
 #define THIRD_STAGE 		(3)
 #define FOURTH_STAGE 		(4)
 #define FIFTH_STAGE 		(5)
 #define SIXTH_STAGE 		(6)
 #define SEVENTH_STAGE		(7)
 #define LAST_STAGE			(8)
 
/**********************************************************************************************************************
*   						GLOBAL FUNCTIONS PROTOTYPES
*********************************************************************************************************************/
void App_init(void);
void App_start (void);
 
 #endif /* APP_H_ */
 /**********************************************************************************************************************
 *  END OF FILE: App.h
 *********************************************************************************************************************/