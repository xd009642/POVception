#include "dotstar.h"
#include "PinNames.h"
#include "mbed.h"
#include "display_settings.h"

// Arduino style connectors
SPI outer_ring(SPI_MOSI, SPI_MISO, SPI_SCK);
// Male connectors on CN12
SPI inner_ring(PB_5, PB_4, PA_5);

static constexpr uint32_t DOTSTAR_FREQUENCY = 2'000'000;

static constexpr size_t HEADER_SIZE = 2;
static constexpr size_t FOOTER_SIZE = 0;

// Force it to be full brightness at the same time.
static constexpr uint32_t LED_ENABLE = 0xFF000000u;


ds::ring::ring(render::framebuffer& buffer, const ds::strip_cfg& cfg, LCD_DISCO_F469NI& l):
    buffer(buffer),
    strip(cfg.mosi, cfg.miso, cfg.clk),
    lcd(l)
{
    strip.frequency(DOTSTAR_FREQUENCY);
    size_t footer = 4;
    payload_length = buffer.n_row() * 2;
    length = HEADER_SIZE + payload_length + footer;
    ring_buffer = new uint32_t[length];
    for(size_t i=0; i<HEADER_SIZE+payload_length; i++)
    {
        if(i>=HEADER_SIZE)
        {
            ring_buffer[i] = 0xFF000000;
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
        ring_buffer[BACK_START+i] = buffer.pixel_at(opposite_col, 
            buffer.n_row()-(i+1));
    }
    strip.write((const char*)ring_buffer, 
        length*sizeof(uint32_t), 
        nullptr, 
        0);
}

void ds::ring::slow_display(const size_t col)
{
    strip.format(32,0);
    const size_t opposite_col = (col+buffer.n_col()/2)%buffer.n_col();
    strip.write(0x00);
    for(size_t i=0; i<buffer.n_row(); i++)
    {
        lcd.DisplayStringAt(0, LINE(16), (uint8_t*)"SLOW DISPLAY", LEFT_MODE);
        uint32_t p = buffer.pixel_at(col, i);
        strip.write(p);
    }
    for(size_t i=0; i<(buffer.n_row()*15)/16; i++)
    {
        strip.write(0xFF);
    }
}
