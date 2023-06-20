

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Dio.h"
#include "Dio_regs.h"
#include "Macros.h"

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
 
/*******************************************************************************
* Service Name: Dio_ReadChannel
* Service ID[hex]: 0x00
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): ChannelId - DioChannel_t
* Parameters (inout): None
* Parameters (out): None
* Return value: enuDioLevel_t
* Description: Function for DIO read Channel API
*******************************************************************************/
enuDioLevel_t Dio_ReadChannel(DioChannel_t ChannelId)
{
	/* Index Error */
	if (ChannelId >= NUM_CONFIGURED_CHANNELS)
		return DIO_LEVEL_ERROR;
	
	switch (ConfigList.channels[ChannelId].portId)
	{
		case PORTA:
			if (GET_BIT(GPIO_PORTA_GPIODATA, ConfigList.channels[ChannelId].pinId) == DIO_LEVEL_HIGH)
				return DIO_LEVEL_HIGH;
			else
				return DIO_LEVEL_LOW;
			break;	/* Unreachable */
			
		case PORTB:
			if (GET_BIT(GPIO_PORTB_GPIODATA, ConfigList.channels[ChannelId].pinId) == DIO_LEVEL_HIGH)
				return DIO_LEVEL_HIGH;
			else
				return DIO_LEVEL_LOW;
			break;	/* Unreachable */
			
		case PORTC:
			if (GET_BIT(GPIO_PORTC_GPIODATA, ConfigList.channels[ChannelId].pinId) == DIO_LEVEL_HIGH)
				return DIO_LEVEL_HIGH;
			else
				return DIO_LEVEL_LOW;
			break;	/* Unreachable */
			
		case PORTD:
			if (GET_BIT(GPIO_PORTD_GPIODATA, ConfigList.channels[ChannelId].pinId) == DIO_LEVEL_HIGH)
				return DIO_LEVEL_HIGH;
			else
				return DIO_LEVEL_LOW;
			break;	/* Unreachable */
			
		case PORTE:
			if (GET_BIT(GPIO_PORTE_GPIODATA, ConfigList.channels[ChannelId].pinId) == DIO_LEVEL_HIGH)
				return DIO_LEVEL_HIGH;
			else
				return DIO_LEVEL_LOW;
			break;	/* Unreachable */
			
		case PORTF:
			if (GET_BIT(GPIO_PORTF_GPIODATA, ConfigList.channels[ChannelId].pinId) == DIO_LEVEL_HIGH)
				return DIO_LEVEL_HIGH;
			else
				return DIO_LEVEL_LOW;
			break;	/* Unreachable */
			
		default:
			return DIO_LEVEL_ERROR;
			break; /* Unreachable */
	}
}

/*******************************************************************************
* Service Name: Dio_WriteChannel
* Service ID[hex]: 0x00
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): ChannelId - DioChannel_t, Level - enuDioLevel_t
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function for DIO write Channel API
*******************************************************************************/
enuDioLevel_t Dio_WriteChannel(DioChannel_t ChannelId, enuDioLevel_t Level)
{
	/* Index Error */
	if (ChannelId >= NUM_CONFIGURED_CHANNELS)
		return;
	
	switch (ConfigList.channels[ChannelId].portId)
	{
		case PORTA:
			if (Level == DIO_LEVEL_HIGH)
				SET_BIT(GPIO_PORTA_GPIODATA, ConfigList.channels[ChannelId].pinId);
			else
				CLEAR_BIT(GPIO_PORTA_GPIODATA, ConfigList.channels[ChannelId].pinId);
			break;	/* Unreachable */
			
		case PORTB:
			if (Level == DIO_LEVEL_HIGH)
				SET_BIT(GPIO_PORTB_GPIODATA, ConfigList.channels[ChannelId].pinId);
			else
				CLEAR_BIT(GPIO_PORTB_GPIODATA, ConfigList.channels[ChannelId].pinId);
			break;	/* Unreachable */
			
		case PORTC:
			if (Level == DIO_LEVEL_HIGH)
				SET_BIT(GPIO_PORTC_GPIODATA, ConfigList.channels[ChannelId].pinId);
			else
				CLEAR_BIT(GPIO_PORTC_GPIODATA, ConfigList.channels[ChannelId].pinId);
			break;	/* Unreachable */
			
		case PORTD:
			if (Level == DIO_LEVEL_HIGH)
				SET_BIT(GPIO_PORTD_GPIODATA, ConfigList.channels[ChannelId].pinId);
			else
				CLEAR_BIT(GPIO_PORTD_GPIODATA, ConfigList.channels[ChannelId].pinId);
			break;	/* Unreachable */
			
		case PORTE:
			if (Level == DIO_LEVEL_HIGH)
				SET_BIT(GPIO_PORTE_GPIODATA, ConfigList.channels[ChannelId].pinId);
			else
				CLEAR_BIT(GPIO_PORTE_GPIODATA, ConfigList.channels[ChannelId].pinId);
			break;	/* Unreachable */
			
		case PORTF:
			if (Level == DIO_LEVEL_HIGH)
				SET_BIT(GPIO_PORTF_GPIODATA, ConfigList.channels[ChannelId].pinId);
			else
				CLEAR_BIT(GPIO_PORTF_GPIODATA, ConfigList.channels[ChannelId].pinId);
			break;	/* Unreachable */
	}
}

/*******************************************************************************
* Service Name: Dio_ToggleChannel
* Service ID[hex]: 0x00
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): ChannelId - DioChannel_t
* Parameters (inout): None
* Parameters (out): None
* Return value: enuDioLevel_t
* Description: Function for DIO flip Channel, then read Channel API
*******************************************************************************/
enuDioLevel_t Dio_ToggleChannel(DioChannel_t ChannelId)
{
	/* Index Error */
	if (ChannelId >= NUM_CONFIGURED_CHANNELS)
		return DIO_LEVEL_ERROR;
	
	switch (ConfigList.channels[ChannelId].portId)
	{
		case PORTA:
			if (GET_BIT(GPIO_PORTA_GPIODATA, ConfigList.channels[ChannelId].pinId) == DIO_LEVEL_HIGH)
			{
				CLEAR_BIT(GPIO_PORTA_GPIODATA, ConfigList.channels[ChannelId].pinId);
				return DIO_LEVEL_LOW;
			}
			else
			{
				SET_BIT(GPIO_PORTA_GPIODATA, ConfigList.channels[ChannelId].pinId);
				return DIO_LEVEL_HIGH;
			}
			break;	/* Unreachable */
			
		case PORTB:
			if (GET_BIT(GPIO_PORTB_GPIODATA, ConfigList.channels[ChannelId].pinId) == DIO_LEVEL_HIGH)
			{
				CLEAR_BIT(GPIO_PORTB_GPIODATA, ConfigList.channels[ChannelId].pinId);
				return DIO_LEVEL_LOW;
			}
			else
			{
				SET_BIT(GPIO_PORTB_GPIODATA, ConfigList.channels[ChannelId].pinId);
				return DIO_LEVEL_HIGH;
			}
			break;	/* Unreachable */
			
		case PORTC:
			if (GET_BIT(GPIO_PORTC_GPIODATA, ConfigList.channels[ChannelId].pinId) == DIO_LEVEL_HIGH)
			{
				CLEAR_BIT(GPIO_PORTC_GPIODATA, ConfigList.channels[ChannelId].pinId);
				return DIO_LEVEL_LOW;
			}
			else
			{
				SET_BIT(GPIO_PORTC_GPIODATA, ConfigList.channels[ChannelId].pinId);
				return DIO_LEVEL_HIGH;
			}
			break;	/* Unreachable */
			
		case PORTD:
			if (GET_BIT(GPIO_PORTD_GPIODATA, ConfigList.channels[ChannelId].pinId) == DIO_LEVEL_HIGH)
			{
				CLEAR_BIT(GPIO_PORTD_GPIODATA, ConfigList.channels[ChannelId].pinId);
				return DIO_LEVEL_LOW;
			}
			else
			{
				SET_BIT(GPIO_PORTD_GPIODATA, ConfigList.channels[ChannelId].pinId);
				return DIO_LEVEL_HIGH;
			}
			break;	/* Unreachable */
			
		case PORTE:
			if (GET_BIT(GPIO_PORTE_GPIODATA, ConfigList.channels[ChannelId].pinId) == DIO_LEVEL_HIGH)
			{
				CLEAR_BIT(GPIO_PORTE_GPIODATA, ConfigList.channels[ChannelId].pinId);
				return DIO_LEVEL_LOW;
			}
			else
			{
				SET_BIT(GPIO_PORTE_GPIODATA, ConfigList.channels[ChannelId].pinId);
				return DIO_LEVEL_HIGH;
			}
			break;	/* Unreachable */
			
		case PORTF:
			if (GET_BIT(GPIO_PORTF_GPIODATA, ConfigList.channels[ChannelId].pinId) == DIO_LEVEL_HIGH)
			{
				CLEAR_BIT(GPIO_PORTF_GPIODATA, ConfigList.channels[ChannelId].pinId);
				return DIO_LEVEL_LOW;
			}
			else
			{
				SET_BIT(GPIO_PORTF_GPIODATA, ConfigList.channels[ChannelId].pinId);
				return DIO_LEVEL_HIGH;
			}
			break;	/* Unreachable */
	}
}


/**********************************************************************************************************************
 *  END OF FILE: Dio.c
 *********************************************************************************************************************/
