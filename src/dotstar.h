#ifndef DOTSTAR_H
#define DOTSTAR_H

#include "stdint.h"
#include "stddef.h"
#include "framebuffer.h"
#include "mbed.h"
#include "PinNames.h"

namespace ds
{
    static constexpr uint32_t WHITE = 0xE00F0F0F;
    static constexpr uint32_t BLUE = 0xE07A0101;
    static constexpr uint32_t GREEN = 0xE007A00A;
    static constexpr uint32_t RED = 0xE001017A;
    static constexpr uint32_t BLACK = 0xE0010101;

    struct strip_cfg
    {
        PinName mosi;
        PinName miso;
        PinName clk;
    };

    static constexpr strip_cfg inner{SPI_MOSI, SPI_MISO, SPI_SCK};
    static constexpr strip_cfg outer{PB_5, PB_4, PA_5};

    class ring
    {
    public:
        ring(render::framebuffer& buffer, const strip_cfg& cfg);
        ~ring();
        void display(const size_t col);
        
    private:
        render::framebuffer& buffer;
        size_t payload_length;
        size_t length;
        uint32_t* ring_buffer;
        bool ready;
        SPI strip;
    };

}


#endif
