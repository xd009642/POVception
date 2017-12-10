#include "dotstar.h"
#include "PinNames.h"
#include "mbed.h"
#include "display_settings.h"
#include <functional>


// Arduino style connectors
SPI outer_ring(SPI_MOSI, SPI_MISO, SPI_SCK);
// Male connectors on CN12
SPI inner_ring(PB_5, PB_4, PA_5);

static constexpr uint32_t DOTSTAR_FREQUENCY = 10'000'000;

static constexpr size_t HEADER_SIZE = 4;
static constexpr size_t FOOTER_SIZE = 0;

// Force it to be full brightness at the same time.
static constexpr uint32_t LED_ENABLE = 0xFF000000u;


ds::ring::ring(render::framebuffer& buffer, const ds::strip_cfg& cfg, LCD_DISCO_F469NI& l):
    buffer(buffer),
    strip(cfg.mosi, cfg.miso, cfg.clk),
    lcd(l)
{
    strip.frequency(DOTSTAR_FREQUENCY);
    strip.set_dma_usage(DMA_USAGE_ALLOCATED);
    payload_length = buffer.n_row() * 2;
    footer = payload_length/16;
    if(footer<4)
    {
        footer = 4;
    }
    length = HEADER_SIZE + payload_length + footer;
    ring_buffer = new uint32_t[length];
    for(size_t i=0; i<length; i++)
    {
        if(i>=HEADER_SIZE && i<HEADER_SIZE+payload_length)
        {
            ring_buffer[i] = ds::BLACK;
        }
        else
        {
            ring_buffer[i] = 0;
        }
    }
    for(size_t i = length - footer; i< length; i++)
    {
       ring_buffer[i] = static_cast<uint32_t>(-1);
    }
    ready = true;
}

ds::ring::~ring()
{
    delete [] ring_buffer;
}

void ds::ring::display(const size_t col) 
{
    const size_t opposite_col = (col+buffer.n_col()/2)%buffer.n_col();
    const size_t row_byte_count = sizeof(uint32_t)*buffer.n_row();
    const size_t BACK_START = buffer.n_row() + HEADER_SIZE;
    memcpy(&ring_buffer[HEADER_SIZE], buffer.get_render_column(col), row_byte_count);
    for(size_t i=0; i<buffer.n_row(); i++)
    {
        ring_buffer[HEADER_SIZE+i] = __REV(buffer.pixel_at(col, i));
    }
    for(size_t i=0; i<buffer.n_row(); i++)
    {
        ring_buffer[BACK_START+i] = __REV(buffer.pixel_at(opposite_col, 
            buffer.n_row()-(i+1)));
    }
    strip.transfer<char*>((char* const*)ring_buffer, length*sizeof(uint32_t), nullptr, 0u, [](int){});
}

void ds::ring::slow_display(const size_t col)
{
    uint32_t blank = 0;
    strip.write((const char*)&blank, sizeof(uint32_t), nullptr, 0);
    for(int i=0; i<1; i++)
    {
        strip.write((const char*)&ds::RED, sizeof(uint32_t), nullptr, 0);
        strip.write((const char*)&ds::BLUE, sizeof(uint32_t), nullptr, 0);
        strip.write((const char*)&ds::WHITE, sizeof(uint32_t), nullptr, 0);
    }
    strip.write((const char*)&blank, sizeof(uint32_t), nullptr, 0);
}
