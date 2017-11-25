#ifndef DOTSTAR_H
#define DOTSTAR_H

#include "stdint.h"
#include "stddef.h"
#include "framebuffer.h"
#include "mbed.h"
#include "PinNames.h"

namespace ds
{
    struct strip_cfg
    {
        PinName mosi;
        PinName miso;
        PinName clk;
    };

    static constexpr strip_cfg outer{SPI_MOSI, SPI_MISO, SPI_SCK};
    static constexpr strip_cfg inner{SPI_MOSI, SPI_MISO, SPI_SCK};

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
