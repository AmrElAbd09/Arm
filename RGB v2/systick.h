


/**********************************************************************
 *  											INCLUDES
 *********************************************************************/
#include "System_Status.h"
#include "Macros.h"
#include "Mcu_Hw.h"


/**********************************************************************
 *  											Macros
 *********************************************************************/
 #define FIRING_TICK 1
 #define MS_FREQ_CONVERT 1000
 
/******** STCTRL bits ****************/

#define STCTRL_ENABLE 		(0)
#define STCTRL_INTEN			(1)
#define	STCTRL_CLK_SRC		(2)
#define	STCTRL_COUNT			(16)

/******** STCURRENT bits ****************/
#define STCURRENT_BIT 		(0)

/**********************************************************************
 *  											Typedefs
 *********************************************************************/
 
typedef enum {
	
	SYSTICK_SINGLE_INTERVAL = 0,
	SYSTICK_PERIODIC_INTERVAL,
	TOTAL_SYSTICK_INTERVAL
	
}enuSystickIntervalMode_t;


typedef enum {
	
	INTERNAK_CLK_BY_FOUR = 0,
	SYSTEM_CLK,
	TOTAL_CLK
	
}enuSystickClkSource_t;


enuErrorStatus_t Systick_Init (void);
enuErrorStatus_t Systick_SetIntervalSingle(uint32 a_u32Interval_ms);
enuErrorStatus_t Systick_SetIntervalPeriodic(uint32 a_u32Interval_ms);
enuErrorStatus_t Systick_StopInterval(void);
enuErrorStatus_t Systick_GetElapsedTime(uint32* u32ElapsedTime);
enuErrorStatus_t Systick_GetRemainingTime(uint32* u32RemainingTime);
void SysTick_SetCallBack(void(*LocalFptr)(void));
