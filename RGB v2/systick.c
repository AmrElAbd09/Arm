

#include "systick_cfg.h"



static void (*SYSTICK_PfCallBack) (void)=NULL_PTR;

enuErrorStatus_t Systick_Init (void)
{
	enuErrorStatus_t enuErrorStatus = SYSTEM_ERROR;
	
	#if		SYSTICK_CLK_SOURCE	== INTERNAK_CLK_BY_FOUR

		CLEAR_BIT(SYSTICK_STCTRL, STCTRL_CLK_SRC); 
		enuErrorStatus = SYSTEM_OK;

#elif	SYSTICK_CLK_SOURCE	== SYSTEM_CLK
		SET_BIT(SYSTICK_STCTRL, STCTRL_CLK_SRC);
		enuErrorStatus = SYSTEM_OK;

#else
		#error "Wrong Systick Initialization"
		enuErrorStatus = SYSTEM_ERROR;
#endif

	return enuErrorStatus;
}


enuErrorStatus_t Systick_SetIntervalSingle(uint32 u32Interval_ms)
{
	enuErrorStatus_t enuErrorStatus = SYSTEM_ERROR;

	uint32 u32Ticks = (F_CPU / (u32Interval_ms / MS_FREQ_CONVERT)) - FIRING_TICK;  
	
  SYSTICK_STRELOAD = u32Ticks;
	SET_BIT(SYSTICK_STCTRL, STCTRL_ENABLE);
	SET_BIT(SYSTICK_STCTRL, STCTRL_INTEN);
	SET_BIT(SYSTICK_STCTRL, STCTRL_CLK_SRC);
	
	return enuErrorStatus;
}


enuErrorStatus_t Systick_SetIntervalPeriodic(uint32 u32Interval_ms)
{
	enuErrorStatus_t enuErrorStatus = SYSTEM_ERROR;

	uint32 u32Ticks = (F_CPU / (u32Interval_ms / MS_FREQ_CONVERT)) - FIRING_TICK;
	


	CLEAR_BIT(SYSTICK_STCTRL, STCTRL_ENABLE);
	SYSTICK_STCURRENT = NULL;	
	
	SYSTICK_STRELOAD = u32Ticks;

	SET_BIT(SYSTICK_STCTRL, STCTRL_ENABLE);
		
	SYSTICK_u8IntervalMode = SYSTICK_PERIODIC_INTERVAL;
	
	SET_BIT(SYSTICK_STCTRL, STCTRL_INTEN);
	
	
	return enuErrorStatus;
}

enuErrorStatus_t Systick_StopInterval(void)
{
	enuErrorStatus_t enuErrorStatus = SYSTEM_ERROR;
	
	CLEAR_BIT(SYSTICK_STCTRL, STCTRL_INTEN);
					
	CLEAR_BIT(SYSTICK_STCTRL, STCTRL_ENABLE);

	SYSTICK_STRELOAD = NULL;
	SYSTICK_STCURRENT = NULL;
	
	enuErrorStatus = SYSTEM_OK;
	
	return enuErrorStatus;
}

enuErrorStatus_t Systick_GetElapsedTime(uint32* u32ElapsedTime)
{
	enuErrorStatus_t enuErrorStatus = SYSTEM_ERROR;
	*u32ElapsedTime = SYSTICK_STRELOAD - SYSTICK_STCURRENT;
	enuErrorStatus = SYSTEM_OK;
	
	return enuErrorStatus;
}

enuErrorStatus_t Systick_GetRemainingTime(uint32* u32RemainingTime)
{
	enuErrorStatus_t enuErrorStatus = SYSTEM_ERROR;
	*u32RemainingTime = SYSTICK_STCURRENT;
	enuErrorStatus = SYSTEM_OK;
	
	return enuErrorStatus;
}


void SysTick_SetCallBack(void(*LocalFptr)(void))
{
  if (LocalFptr!=NULL_PTR)  
	{	
	SYSTICK_PfCallBack=LocalFptr;
	}
}

void SysTick_Handler(void)  
{
	SYSTICK_PfCallBack();	
}

