
#ifndef Dio_CFG_H_
#define Dio_CFG_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Dio_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
 /* Number of the configured Dio Channels */
#define NUM_CONFIGURED_CHANNELS              		(11U)  //should be 12 for EN
/*----------------------------------INDEX----------------------------------*/
/* Channel Index in the array of structures in Dio_Lcfg.c */
#define DIO_CONFIG_LED1_CHANNEL_ID        			(uint8)0x00
#define DIO_CONFIG_LED2_CHANNEL_ID        			(uint8)0x01
#define DIO_CONFIG_LED3_CHANNEL_ID        			(uint8)0x02
#define DIO_CONFIG_LED4_CHANNEL_ID        			(uint8)0x03

#define DIO_CONFIG_SWITCH1_CHANNEL_ID        		(uint8)0x04
#define DIO_CONFIG_SWITCH2_CHANNEL_ID        		(uint8)0x05

#define DIO_CONFIG_MOTOR1_D1A_CHANNEL_ID                  	    (uint8)0x06
#define DIO_CONFIG_MOTOR1_D1B_CHANNEL_ID                 	      (uint8)0x07
#define DIO_CONFIG_MOTOR2_D2A_CHANNEL_ID                  	    (uint8)0x08
#define DIO_CONFIG_MOTOR2_D2B_CHANNEL_ID                  	    (uint8)0x09

#define DIO_CONFIG_MOTOR1_EN_CHANNEL_ID                  	      (uint8)0x0A
//#define DIO_CONFIG_MOTOR2_EN_CHANNEL_ID                 	      (uint8)0x0B
/*---------------------------------PORT_ID--------------------------------*/
/* DIO Configured Port's ID  */
#define DIO_CONFIG_LED1_PORT                		(Dio_PortType)PORTF
#define DIO_CONFIG_LED2_PORT                		(Dio_PortType)PORTF
#define DIO_CONFIG_LED3_PORT                		(Dio_PortType)PORTF
#define DIO_CONFIG_LED4_PORT                		(Dio_PortType)PORTE

#define DIO_CONFIG_SWITCH1_PORT                 	(Dio_PortType)PORTF
#define DIO_CONFIG_SWITCH2_PORT                 	(Dio_PortType)PORTF


/* Motor Ports ID */
#define DIO_CONFIG_MOTOR1_D1A_PORT                  	    (Dio_PortType)PORTE
#define DIO_CONFIG_MOTOR1_D1B_PORT                 	      (Dio_PortType)PORTE
#define DIO_CONFIG_MOTOR2_D2A_PORT                  	    (Dio_PortType)PORTE
#define DIO_CONFIG_MOTOR2_D2B_PORT                  	    (Dio_PortType)PORTE

#define DIO_CONFIG_MOTOR1_EN_PORT                  	      (Dio_PortType)PORTB
//#define DIO_CONFIG_MOTOR2_EN_PORT                 	      (Dio_PortType)PORTF

/*------------------------------Channel's ID-------------------------------*/

/* DIO Configured Channel's ID */
#define DIO_CONFIG_LED1_CHANNEL             		(Dio_PinType)PIN1
#define DIO_CONFIG_LED2_CHANNEL             		(Dio_PinType)PIN2
#define DIO_CONFIG_LED3_CHANNEL             		(Dio_PinType)PIN3
#define DIO_CONFIG_LED4_CHANNEL             		(Dio_PinType)PIN1


#define DIO_CONFIG_SWITCH1_CHANNEL              	(Dio_PinType)PIN4
#define DIO_CONFIG_SWITCH2_CHANNEL              	(Dio_PinType)PIN0

/* Motor Channel ID */
#define DIO_CONFIG_MOTOR1_D1A_CHANNEL                  	    PIN2
#define DIO_CONFIG_MOTOR1_D1B_CHANNEL                 	    PIN3
#define DIO_CONFIG_MOTOR2_D2A_CHANNEL                  	    PIN4
#define DIO_CONFIG_MOTOR2_D2B_CHANNEL                  	    PIN5

#define DIO_CONFIG_MOTOR1_EN_CHANNEL                  	    PIN7
//#define DIO_CONFIG_MOTOR2_EN_CHANNEL                 	      PIN0
/*------------------------------------------------------------------------*/
/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
/* Structure to gather the configured channels to be used and manipulated easily */
typedef struct
{
	Dio_ChannelConfigType channels[NUM_CONFIGURED_CHANNELS];
} str_DioConfigType;

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
extern const str_DioConfigType configList;

#endif  /* DIO_CFG_H_ */
/**********************************************************************************************************************
 *  END OF FILE: Dio_Cfg.h
 *********************************************************************************************************************/
