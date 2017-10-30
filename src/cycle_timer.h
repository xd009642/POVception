#ifndef CYCLE_TIMER_H
#define CYCLE_TIMER_H

#include "stdint.h"
#include "memory_access.h"

namespace ct
{
    namespace 
    {
        static constexpr uint32_t DEMCR = 0xE000EDFC;
        static constexpr uint32_t DWT_CTRL = 0xE0001000;
        static constexpr uint32_t CYCLE_COUNT = 0xE0001004;
    
        static constexpr uint32_t DEMCR_TRCENA = 0x01000000;
        static constexpr uint32_t COUNT_ENABLE = 0x2;
    }

    void reset() 
    {
        access::memory(DEMCR) |= DEMCR_TRCENA;
        access::memory(CYCLE_COUNT) = 0;
        access::memory(DWT_CTRL) |= COUNT_ENABLE;
    }
    
    uint32_t get_ticks() 
    {
        return access::memory(CYCLE_COUNT);
    }

    void delay(const uint32_t& ticks)
    {
        const uint32_t end = ticks + get_ticks();
        while(1)
        {
            if(get_ticks() >= end)
                break;
        }
    }

}


#endif
