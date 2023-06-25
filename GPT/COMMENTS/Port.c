

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Port.h"
#include "Port_regs.h"
#include "Macros.h"
#include "Mcu_Hw.h"

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
 
/*******************************************************************************
* Service Name: PortInit
* Service ID[hex]: 0x00
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): ConfigPtr - Pointer to post-build (Linking) configuration data
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to Setup the pin configuration:
*              - Setup the pin as Digital GPIO pin
*              - Setup the direction of the GPIO pin
*              - Set the passed initial values for the GPIO pin
*              - Setup the mode of the GPIO pin
*              - Setup the internal resistor for i/p pin
*              - Setup the output current in case of output pin
*******************************************************************************/
enu_ErrorReturn Port_Init(const Port_configType* ConfigPtr)
{
	/* Check that ConfigPtr is not pointing to NULL */
	if (ConfigPtr == NULL_PTR)
	{
		return Sys_NotOK;
	}
	
	uint8 pin = 0;
	for (pin = 0; pin < TOTAL_PORT_NUMBER_OF_PINS; pin++)
	{
		Port_PortType PortNum = ConfigPtr->pinConfigType[pin].portType;
		Port_PinType PinNum = ConfigPtr->pinConfigType[pin].pinType;
		
		/* To not configure all the channels by the default, otherwise it is requested */
		if (ConfigPtr->pinConfigType[pin].isEnabled == CHANNEL_DISABLED)
			continue;
		
		/* Enable the clock for the dedicated port */
		SET_BIT(RCGCGPIO, PortNum);
		
		switch (ConfigPtr->pinConfigType[pin].pinModeType)
		{
			case DIO_MODE:
				/* Clear the corresponding bit to the dedicated pin in GPIOAMSEL */
				CLEAR_BIT(GPIOAMSEL(PortNum), PinNum);
				
				/* Clear the corresponding bit to the dedicated pin in GPIOAFSEL */
				CLEAR_BIT(GPIOAFSEL(PortNum), PinNum);
				
				/* Clear the PMCx bits for the dedicated pin */
				GPIOPCTL(PortNum) &= ~(0x0000000F << (PinNum * 4));
				
				/* Set the corresponding bit of the dedicated pin in GPIODEN register to enable the digital functionality to this pin */
				SET_BIT(GPIODEN(PortNum), PinNum);
				break;
			case ICU_MODE:
				/* [TODO] Setup the configurations for ICU_MODE */
				break;
			case ADC_MODE:
				/* [TODO] Setup the configurations for ADC_MODE */
				break;
			default: /* Default is DIO_MODE */
				/* Clear the corresponding bit to the dedicated pin in GPIOAMSEL */
				CLEAR_BIT(GPIOAMSEL(PortNum), PinNum);
				
				/* Clear the corresponding bit to the dedicated pin in GPIOAFSEL */
				CLEAR_BIT(GPIOAFSEL(PortNum), PinNum);
				
				/* Clear the PMCx bits for the dedicated pin */
				GPIOPCTL(PortNum) &= ~(0x0000000F << (PinNum * 4));
				
				/* Set the corresponding bit of the dedicated pin in GPIODEN register to enable the digital functionality to this pin */
				SET_BIT(GPIODEN(PortNum), PinNum);
				break;
		}
		
		if (ConfigPtr->pinConfigType[pin].pinDirectionType == OUTPUT)
		{
			/* Set the corresponding bit of the dedicated pin in GPIODIR */
			SET_BIT(GPIODIR(PortNum), PinNum);
			
			switch (ConfigPtr->pinConfigType[pin].pinOutputCurrentType)
			{
				case DRIVE_2mA:
					SET_BIT(GPIODR2R(PortNum), PinNum);
					CLEAR_BIT(GPIODR4R(PortNum), PinNum);
					CLEAR_BIT(GPIODR8R(PortNum), PinNum);
					break;
				case DRIVE_4mA:
					CLEAR_BIT(GPIODR2R(PortNum), PinNum);
					SET_BIT(GPIODR4R(PortNum), PinNum);
					CLEAR_BIT(GPIODR8R(PortNum), PinNum);
					break;
				case DRIVE_8mA:
					CLEAR_BIT(GPIODR2R(PortNum), PinNum);
					CLEAR_BIT(GPIODR4R(PortNum), PinNum);
					SET_BIT(GPIODR8R(PortNum), PinNum);
					break;
				default:
					SET_BIT(GPIODR2R(PortNum), PinNum);
					CLEAR_BIT(GPIODR4R(PortNum), PinNum);
					CLEAR_BIT(GPIODR8R(PortNum), PinNum);
					break;
			}
			
			if (ConfigPtr->pinConfigType[pin].pinLevelType == PIN_LEVEL_HIGH)
			{
				/* Set the corresponding bit of the dedicated pin in GPIODATA */
				SET_BIT(GPIODATA(PortNum), PinNum);
			}
			else
			{
				/* Clear the corresponding bit of the dedicated pin in GPIODATA */
				CLEAR_BIT(GPIODATA(PortNum), PinNum);
			}
		}
		else if (ConfigPtr->pinConfigType[pin].pinDirectionType == INPUT)
		{
			/* Set the corresponding bit of the dedicated pin in GPIODIR */
			CLEAR_BIT(GPIODIR(PortNum), PinNum);
		
			switch (ConfigPtr->pinConfigType[pin].pinInternalAttachType)
			{
				case PULL_UP:
					SET_BIT(GPIOPUR(PortNum), PinNum);
					CLEAR_BIT(GPIOPDR(PortNum), PinNum);
					CLEAR_BIT(GPIOODR(PortNum), PinNum);
					CLEAR_BIT(GPIOSLR(PortNum), PinNum);
					break;
				case PULL_DOWN:
					CLEAR_BIT(GPIOPUR(PortNum), PinNum);
					SET_BIT(GPIOPDR(PortNum), PinNum);
					CLEAR_BIT(GPIOODR(PortNum), PinNum);
					CLEAR_BIT(GPIOSLR(PortNum), PinNum);
					break;
				case OPEN_DRAIN:
					CLEAR_BIT(GPIOPUR(PortNum), PinNum);
					CLEAR_BIT(GPIOPDR(PortNum), PinNum);
					SET_BIT(GPIOODR(PortNum), PinNum);
					CLEAR_BIT(GPIOSLR(PortNum), PinNum);
					break;
				case SLEW_RATE:
					CLEAR_BIT(GPIOPUR(PortNum), PinNum);
					CLEAR_BIT(GPIOPDR(PortNum), PinNum);
					CLEAR_BIT(GPIOODR(PortNum), PinNum);
					SET_BIT(GPIOSLR(PortNum), PinNum);
					break;
				default: /* Default is PULL_UP */
					SET_BIT(GPIOPUR(PortNum), PinNum);
					CLEAR_BIT(GPIOPDR(PortNum), PinNum);
					CLEAR_BIT(GPIOODR(PortNum), PinNum);
					CLEAR_BIT(GPIOSLR(PortNum), PinNum);
					break;
			}
		}
		else
		{
			/* TODO: Report the error using Det_ReportError */
			return Sys_NotOK;
		}
		/* set Interrupt configuration */
     if(ConfigPtr->pinConfigType[pin].Interrupt == Port_IntDisable)
     {  
         			CLEAR_BIT(GPIOIM(PortNum), PinNum) ; 
     }
     else
     {
         SET_BIT(GPIOIM(PortNum), PinNum);
		
         if( ConfigPtr->pinConfigType[pin].Interrupt == Port_IntRisingEdge)
         {
           SET_BIT(GPIOIEV(PortNum), PinNum)  ;		
         }
         else if( ConfigPtr->pinConfigType[pin].Interrupt == Port_IntFallingEdge)
         {
             CLEAR_BIT(GPIOIEV(PortNum), PinNum)  ;
         }
         else if( ConfigPtr->pinConfigType[pin].Interrupt == Port_IntBothEdges)
         {   
						SET_BIT(GPIOIBE(PortNum), PinNum)  ;
				 }
     }
	}
}
/**********************************************************************************************************************
 *  END OF FILE: Port.c
 *********************************************************************************************************************/