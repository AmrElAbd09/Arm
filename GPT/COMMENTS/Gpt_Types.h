
#ifndef GPT_TYPES_H_
#define GPT_TYPES_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "IntCtrl_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define TOTAL_NUM_TIMERS				(12U)

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
/* enum for all the channels */
typedef enum
{
	TIMER0_16BIT = 0,
	TIMER1_16BIT = 1,
	TIMER2_16BIT = 2,
	TIMER3_16BIT = 3,
	TIMER4_16BIT = 4,
	TIMER5_16BIT = 5,
	TIMER0_32BIT = 6,
	TIMER1_32BIT = 7,
	TIMER2_32BIT = 8,
	TIMER3_32BIT = 9,
	TIMER4_32BIT = 10,
	TIMER5_32BIT = 11
} enu_GptChannelType;

/* enum for the half type */
typedef IntCtrl_InterruptType Gpt_TimerInterruptType;

/* enum for the size of the channel */
typedef enum
{
    FULL = 0x0,
	HALF = 0x4
} enu_GptChannelSizeType;

/* enum to specify the counting direction */
typedef enum
{
	DOWN = 0x0,
	UP   = 0x1
} enu_GptDirectionType;

/* Flag to know if i want to use this timer of not */
typedef enum
{
	DISABLED = 0,
	ENABLED  = 1
} enu_GptEnableType;

/* The mode of operation for the timer */
typedef enum
{
	GPT_MODE_NORMAL = 0,
	GPT_MODE_SLEEP  = 1
} enu_GptModeType;

/* Channel Tick Frequency in MHz */
typedef uint64 Gpt_ChannelTickFrequencyType;

/* The modes of periodic timers */
typedef enum
{
	GPT_CHANNEL_MODE_ONESHOT   = 0x1,
	GPT_CHANNEL_MODE_CONTINOUS = 0x2
} enu_GptChannelModeType;

/* The value if the timers' counters (registers) */
typedef uint64 Gpt_ValueType;

/* A pointer to the callback function (Notification) */
typedef void (*Gpt_NotificationType)(void);

/* A priority for the interrupt attached to the channel's timer */
typedef uint8 Gpt_NotificationPriority;

/* GPT configuration set for each channel */
/*
typedef struct
{
	enu_GptChannelType channelId;
	enu_GptEnableType	enable;
	enu_GptChannelSizeType size;
	Gpt_TimerType half;
	enu_GptDirectionType direction;
	Gpt_ChannelTickFrequencyType frequency;
	Gpt_ChannelTickValueType startingTickValue;
	Gpt_ChannelTickValueType stopTickValue;
	Gpt_ChannelTickValueType TickValueMax;
	enu_GptChannelModeType mode;
	Gpt_NotificationType notification;
	Gpt_NotificationPriority priority;
} str_GptChannelConfigType;
*/

typedef struct
{
	enu_GptChannelType channelId;
	enu_GptEnableType isEnabled;
	enu_GptDirectionType direction;
	Gpt_ChannelTickFrequencyType frequency;
	// [TODO] Gpt_ChannelTickValueType TickValueMax;
	enu_GptChannelModeType mode;
	Gpt_NotificationType notification;
	Gpt_NotificationPriority priority;
} str_GptChannelConfigType;

/* A type for the predefined timers */
typedef uint8 Gpt_PredefTimerType;

/* Gpt config structure for an array of 12 timers */
typedef struct
{
	str_GptChannelConfigType channels[TOTAL_NUM_TIMERS];
} str_GptConfigType;

#endif  /* GPT_TYPES_H_ */

/**********************************************************************************************************************
 *  END OF FILE: Gpt_Types.h
 *********************************************************************************************************************/
