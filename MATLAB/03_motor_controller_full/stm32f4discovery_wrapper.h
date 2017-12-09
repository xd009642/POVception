/* Wrapper header for STM32F4-Discovery 
 * 
 * Copyright 2013 The MathWorks, Inc.
 */
#ifndef STM32F4DISCOVERY_WRAPPER_H
#define STM32F4DISCOVERY_WRAPPER_H

#ifdef _MSC_VER
#define __INLINE inline
#define __STATIC_INLINE static inline
#define __DSB()
#endif

#include "stm32f4xx.h"

#include "misc.h"
#include "stm32f4xx_adc.h"
#include "stm32f4xx_can.h"
#include "stm32f4xx_crc.h"
#include "stm32f4xx_cryp.h"
#include "stm32f4xx_dac.h"
#include "stm32f4xx_dbgmcu.h"
#include "stm32f4xx_dcmi.h"
#include "stm32f4xx_dma.h"
#include "stm32f4xx_exti.h"
#include "stm32f4xx_flash.h"
#include "stm32f4xx_fsmc.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_hash.h"
#include "stm32f4xx_i2c.h"
#include "stm32f4xx_iwdg.h"
#include "stm32f4xx_pwr.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_rng.h"
#include "stm32f4xx_rtc.h"
#include "stm32f4xx_sdio.h"
#include "stm32f4xx_spi.h"
#include "stm32f4xx_syscfg.h"
#include "stm32f4xx_tim.h"
#include "stm32f4xx_usart.h"
#include "stm32f4xx_wwdg.h"

#ifndef __STATIC_INLINE
#define __STATIC_INLINE static __INLINE
#endif

/* Hardware resource file */
/* This header file generated during code generation */
#include "MW_target_hardware_resources.h"

/* Multi tasking related header file */
#include "arm_cortex_m_multitasking.h"

/* Board Initialise header file */
#include "stm32f4xx_init_board.h"

/* Peripheral wrapper header file */
#include "stm32f4xx_gpio_wrapper.h"
#include "stm32f4xx_adc_wrapper.h"

/* SysTick Scheduler */
#include "SysTickScheduler.h"

/* Audio Blocks */
#include "stm32f4discovery_audio_common.h"
#include "stm32f4discovery_mp45dt02_mems_mic.h"
#include "stm32f4discovery_cs43l22_codec.h"

#define MW_BitEnableClockToPeripheral(pos, offset) ((uint32_t)(1U << ((pos)+(offset))))


#endif // STM32F4DISCOVERY_WRAPPER_H
