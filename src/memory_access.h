#ifndef MEMORY_ACCESS_H
#define MEMORY_ACCESS_H

#include "stdint.h"

// 0x2000'0000-0x3fff'ffff SRAM
// 0x4000'0000-0x5fff'ffff peripheral
// 0x6000'0000-0x9fff'ffff external ram
// 0xa000'0000-0xdfff'ffff external device
// 0xed00'0000-0xed0f'ffff private peripheral bus
// 0xed10'0000-0xffff'ffff memory mapped peripheral

namespace regions
{
    static constexpr uint32_t SRAM              = 0x20000000;
    static constexpr uint32_t PERIPH            = 0x40000000;
    static constexpr uint32_t EXT_RAM           = 0x60000000;
    static constexpr uint32_t EXT_DEV           = 0xa0000000;
    static constexpr uint32_t PRIV_PERIPH_BUS   = 0xed000000;
    static constexpr uint32_t MEM_MAP_PERIPH    = 0xed100000;
}
namespace access
{
    //Read a word from given address
    volatile uint32_t &memory(const uint32_t loc) 
    {
        return *reinterpret_cast<uint32_t*>(loc);
    }

}




#endif
