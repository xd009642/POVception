/* Wrapper for Multi tasking.
 * 
 * Copyright 2013-2014 The MathWorks, Inc.
 */
 
/* Header file for multitasking */
#ifndef _ARM_CORTEX_M_MULTITASKING_
#define _ARM_CORTEX_M_MULTITASKING_

#if defined (__GNUC__)
	#define MW_ASM	__asm volatile
#elif defined (__TMS470__)
	#define MW_ASM	__asm
#endif


/* In GCC, functions with 'naked' attributes doesn't include prolog. */ 
/* For TI ARM toolchain, the below prolog is added only in DEBUG (-g) mode. This prolog needs to be 
   added in non-debug mode. */
/*This macro should be called before calling arm_cortex_m_call_thread_with_context_switch(). */
#if defined (__GNUC__) || (defined (__TMS470__) && !defined (_DEBUG))
#define ARM_CORTEX_M_PUSH_THREADS_PSR_AND_RET_ADDR()  MW_ASM (" MRS R0, APSR    \n"      \
                                                              " PUSH {R0, LR}   \n");
#else
#define ARM_CORTEX_M_PUSH_THREADS_PSR_AND_RET_ADDR()
#endif
                                                                      
extern void arm_cortex_m_call_thread_with_context_switch(void (*isr_routine_ptr)(void));

#endif /* _ARM_CORTEX_M_MULTITASKING_ */
