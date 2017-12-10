#ifndef DOTSTAR_H
#define DOTSTAR_H

#include "stdint.h"
#include "stddef.h"
#include "framebuffer.h"
#include "mbed.h"
#include "PinNames.h"
#include "LCD_DISCO_F469NI.h"

namespace ds
{
    static constexpr uint32_t WHITE = 0xFF424242;
    static constexpr uint32_t RED = 0xFF000072;
    static constexpr uint32_t GREEN = 0xFF072000;
    static constexpr uint32_t BLUE = 0xFF720000;
    static constexpr uint32_t BLACK = 0xFF010101;

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
        ring(render::framebuffer& buffer, const strip_cfg& cfg, LCD_DISCO_F469NI& l);
        ~ring();
        void display(const size_t col);
        void slow_display(const size_t col); 
    private:
        render::framebuffer& buffer;
        size_t payload_length;
        size_t length;
        size_t footer;
        uint32_t* ring_buffer;
        bool ready;
        SPI strip;
        LCD_DISCO_F469NI& lcd;
    };

}


#endif
