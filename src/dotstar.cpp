#include "dotstar.h"
#include "PinNames.h"
#include "mbed.h"
#include "display_settings.h"

// Arduino style connectors
SPI outer_ring(SPI_MOSI, SPI_MISO, SPI_SCK);
// Male connectors on CN12
SPI inner_ring(PB_5, PB_4, PA_5);

static constexpr uint32_t DOTSTAR_FREQUENCY = 500'000;

static constexpr size_t HEADER_SIZE = 1;
static constexpr size_t FOOTER_SIZE = 0;

static constexpr size_t INNER_BUFFER_SIZE = (2u * OUTER_HEIGHT) + HEADER_SIZE + FOOTER_SIZE;
static constexpr size_t OUTER_BUFFER_SIZE = (2u * INNER_HEIGHT) + HEADER_SIZE + FOOTER_SIZE;

// Force it to be full brightness at the same time.
static constexpr uint32_t LED_ENABLE = 0xE1000000u;


ds::ring::ring(render::framebuffer& buffer, const ds::strip_cfg& cfg):
    buffer(buffer),
    strip(cfg.mosi, cfg.miso, cfg.clk)
{
    strip.frequency(DOTSTAR_FREQUENCY);
    payload_length = buffer.n_row() * 2;
    length = HEADER_SIZE + payload_length + FOOTER_SIZE;
    ring_buffer = new uint32_t[length];
    for(size_t i=0; i<HEADER_SIZE+FOOTER_SIZE+payload_length; i++)
    {
        ring_buffer[i] = 0;
    }
    for(size_t i = length - FOOTER_SIZE; i< length; i++)
    {
       ring_buffer[i] = 0xFFFFFFFF;
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
            buffer.n_row()-i-1);
    }
    strip.write((const char*)ring_buffer, 
        length*sizeof(uint32_t), 
        nullptr, 
        0);
}
