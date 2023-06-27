

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Dio_Cfg.h"

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
const Dio_ConfigType configList =
{
	DIO_CONFIG_LED1_PORT, DIO_CONFIG_LED1_CHANNEL,			/* LED 1 @ PF1 */
	DIO_CONFIG_LED2_PORT, DIO_CONFIG_LED2_CHANNEL,			/* LED 2 @ PF2 */
	DIO_CONFIG_LED3_PORT, DIO_CONFIG_LED3_CHANNEL,			/* LED 3 @ PF3 */
	DIO_CONFIG_LED4_PORT, DIO_CONFIG_LED4_CHANNEL,			/* LED 3 @ PF3 */
	
	
	DIO_CONFIG_SWITCH1_PORT, DIO_CONFIG_SWITCH1_CHANNEL,	/* Switch 1 @ PF0 */
	DIO_CONFIG_SWITCH2_PORT, DIO_CONFIG_SWITCH2_CHANNEL,	/* Switch 2 @ PF4 */
	
 DIO_CONFIG_MOTOR1_D1A_PORT,DIO_CONFIG_MOTOR1_D1A_CHANNEL,                  	   
 DIO_CONFIG_MOTOR1_D1B_PORT,DIO_CONFIG_MOTOR1_D1B_CHANNEL,                 	   
 DIO_CONFIG_MOTOR2_D2A_PORT,DIO_CONFIG_MOTOR2_D2A_CHANNEL,                  	   
 DIO_CONFIG_MOTOR2_D2B_PORT,DIO_CONFIG_MOTOR2_D2B_CHANNEL,                  	   

 DIO_CONFIG_MOTOR1_EN_PORT,DIO_CONFIG_MOTOR1_EN_CHANNEL,                  	   
// DIO_CONFIG_MOTOR2_EN_PORT ,DIO_CONFIG_MOTOR2_EN_CHANNEL,                 	      
};
    
/**********************************************************************************************************************
 *  END OF FILE: Port_Lcfg.c
 *********************************************************************************************************************/
