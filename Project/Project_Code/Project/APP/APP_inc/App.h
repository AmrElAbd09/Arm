
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
#define 	SERVICE_GPTM		TIMER0_16BIT
#define		PWM_GPTM			TIMER1_16BIT

#define LONG_SIDE_TIME	(3000)
#define LONG_SIDE_PWM	(50)

#define SHORT_SIDE_TIME	(2000)
#define SHORT_SIDE_PWM	(30)

#define ROTATING_TIME	(1000)
#define ROTATING_PWM	(20)
 
#define READY_STAGE_TIME (1000)
#define STOP_TIME 		(500)
 
 
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