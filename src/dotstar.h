#ifndef DOTSTAR_H
#define DOTSTAR_H

#include "stdint.h"
#include "stddef.h"
#include "framebuffer.h"
#include "mbed.h"
#include "PinNames.h"

namespace ds
{
    static constexpr uint32_t WHITE = 0xE0424242;
    static constexpr uint32_t BLUE = 0xE0740000;
    static constexpr uint32_t GREEN = 0xE0072000;
    static constexpr uint32_t RED = 0xE0000074;
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
