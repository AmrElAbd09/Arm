
#ifndef PORT_TYPES_H_
#define PORT_TYPES_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define TOTAL_PORT_NUMBER_OF_PINS				43U

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
typedef enum
{
	PIN0 = 0,
	PIN1 = 1,
	PIN2 = 2,
	PIN3 = 3,
	PIN4 = 4,
	PIN5 = 5,
	PIN6 = 6,
	PIN7 = 7,
} enuPortPinNum_t;

typedef enum
{
	PORTA = 0,
	PORTB = 1,
	PORTC = 2,
	PORTD = 3,
	PORTE = 4,
	PORTF = 5
} enuPortPortNum_t;

/* Flag to know if i want to use this timer of not */
typedef enum
{
	CHANNEL_DISABLED = 0,
	CHANNEL_ENABLED  = 1
} enuPortEnable_t;

typedef enum
{
	INPUT  = 0,		// Default
	OUTPUT = 1
} enuPortPinDirection_t;

/* TODO: Add the other modes */
typedef enum
{
	DIO_MODE = 0,	// Default
	ICU_MODE = 1,
	ADC_MODE = 2
} enuPortPinMode_t;

typedef enum
{
	PULL_UP = 0,	// Default
	PULL_DOWN = 1,
	OPEN_DRAIN = 2,
	SLEW_RATE = 3
} enuPortPinInternalAttach_t;

typedef enum
{
	DRIVE_2mA = 0,	// Default
	DRIVE_4mA = 1,
	DRIVE_8mA = 2
} enuPortPinOutputCurrent_t;

typedef enum
{
	PIN_LEVEL_LOW = 0,
	PIN_LEVEL_HIGH = 1
} enuPortPinLevel_t;

typedef enum
{
    Port_IntDisable,
    Port_IntFallingEdge,
    Port_IntRisingEdge,
    Port_IntBothEdges
}enuIntCtrType_t;
/* 
 * Description: Structure to configure an individual pin:
 *		1. The id of the PORT.
 *		2. The id of the pin in the PORT.
 *  	3. The direction of pin: INPUT or OUTPUT
 *  	4. The initial value of the port pin
 *  	5. The initial port pin mode
 *  	6. The internal resistor: Pull up, Pull down, open-drain, or slew rate
 *  	7. The driven current in case of output
 */
typedef struct
{
	enuPortPortNum_t portType;
	enuPortPinNum_t pinType;
	enuPortEnable_t isEnabled;
	enuPortPinDirection_t pinDirectionType;
	enuPortPinLevel_t pinLevelType;
	enuPortPinMode_t pinModeType;
	enuPortPinInternalAttach_t pinInternalAttachType;
	enuPortPinOutputCurrent_t pinOutputCurrentType;
	enuIntCtrType_t Interrupt;
} strPortPinConfig_t;

 /* 
 * Description: Structure to configure an individual pin:
 *  	=> Array of structure containing all the pin configuration for each pin in the port
 */
typedef struct
{
	strPortPinConfig_t pinConfigType[TOTAL_PORT_NUMBER_OF_PINS];
} strPortConfig_t;

#endif  /* PORT_TYPES_H_ */

/**********************************************************************************************************************
 *  END OF FILE: Port_Types.h
 *********************************************************************************************************************/
