/* SysTick scheduler
 * 
 * Copyright 2013-2015 The MathWorks, Inc.
 */
 
#include "MW_target_hardware_resources.h"

unsigned long schdl_counter;
unsigned long schdl_counter_max;

static void SysTick_Isr(void)
{
    __DSB();
    __ISB();
	
	if (schdl_counter >= schdl_counter_max)
	{
		schdl_counter = 0;
	}
	
    if (0 == schdl_counter++)	/* Compare with zero before increament */
	{
		/* The rt_OneStep() function expects interrupts to be disabled. 
           Hence disable interrupt before rt_OneStep(). */
        __disable_irq();
        rt_OneStep();
        /* The rt_OneStep() function disables interrupt. 
           Hence enable interrupt immediately after rt_OneStep(). */
        __enable_irq();
	}
}

#if defined(MW_SCHEDULER_INTERRUPT_SOURCE) && (MW_SCHEDULER_INTERRUPT_SOURCE == 0) && (MW_MULTI_TASKING_MODE == 1)
__attribute__ ((naked)) void SysTick_Handler(void)
{
    /* Multi tasking, enable re-entrancy to interrupt */
    ARM_CORTEX_M_PUSH_THREADS_PSR_AND_RET_ADDR();
    arm_cortex_m_call_thread_with_context_switch(SysTick_Isr);
}
#else
void SysTick_Handler(void)
{
    /* Single tasking */
    SysTick_Isr();
}
#endif

void ARMCM_SysTick_Config(float modelBaseRate)
{
#if !defined(MW_DONT_USE_SYSTICK)    
#if defined(MW_SCHEDULER_INTERRUPT_SOURCE) && (MW_SCHEDULER_INTERRUPT_SOURCE == 0)
	/* SysTick Scheduler is selected */
	unsigned long tick_counter;
	
	tick_counter = (unsigned long)(SystemCoreClock * modelBaseRate);
	
	if (tick_counter > SysTick_LOAD_RELOAD_Msk)
	{
		schdl_counter_max = (unsigned long)((float)tick_counter / (float)SysTick_LOAD_RELOAD_Msk) + 1;
		SysTick_Config(tick_counter/schdl_counter_max);		
	}
	else
	{
		schdl_counter_max = 0;
		SysTick_Config(tick_counter);
	}
	
	schdl_counter = 0;
	
	/* Set the SysTick priority */
	#ifdef MW_SCHEDULER_PRIORITY
		NVIC_SetPriority((IRQn_Type)(-1), MW_SCHEDULER_PRIORITY);
	#endif
#endif
#endif        
}

