#include "dotstar.h"
#include "PinNames.h"
#include "mbed.h"
#include "display_settings.h"

// Arduino style connectors
SPI outer_ring(SPI_MOSI, SPI_MISO, SPI_SCK);
// Male connectors on CN12
SPI inner_ring(PB_5, PB_4, PA_5);

static constexpr uint32_t DOTSTAR_FREQUENCY = 45'000'000;

static constexpr size_t HEADER_SIZE = 1;
static constexpr size_t FOOTER_SIZE = 0;

static constexpr size_t OUTER_BUFFER_SIZE = OUTER_HEIGHT + HEADER_SIZE + FOOTER_SIZE;
static constexpr size_t INNER_BUFFER_SIZE = INNER_HEIGHT + HEADER_SIZE + FOOTER_SIZE;

// Force it to be full brightness at the same time.
static constexpr uint32_t LED_ENABLE = 0xE1000000u;

// Set the display to show something at startup just for debugging
static uint32_t outer_buffer [OUTER_BUFFER_SIZE];
static uint32_t inner_buffer [INNER_BUFFER_SIZE];




void ds::init()
{
    outer_ring.frequency(DOTSTAR_FREQUENCY);
//    outer_ring.set_dma_usage(DMA_USAGE_OPPORTUNISTIC);
    inner_ring.frequency(DOTSTAR_FREQUENCY);
//    inner_ring.set_dma_usage(DMA_USAGE_OPPORTUNISTIC);
    for(size_t i=0; i<HEADER_SIZE; i++) 
    {
        outer_buffer[i] = 0x00000000;
        inner_buffer[i] = 0x00000000;
    }
    for(size_t i=HEADER_SIZE; i<(OUTER_HEIGHT+HEADER_SIZE); i++)
    {
        outer_buffer[i] = LED_ENABLE | 0xFF0000;
    }
    for(size_t i=0; i<FOOTER_SIZE; i++)
    {
        outer_buffer[HEADER_SIZE+OUTER_HEIGHT + i] = 0xFFFFFFFFu;
        inner_buffer[HEADER_SIZE+INNER_HEIGHT + i] = 0xFFFFFFFFu;
    }
}

void ds::display(const ds::ring id) 
{
    if(id == ds::ring::outer)
    {
        outer_ring.write((const char*)outer_buffer, sizeof(uint32_t)*OUTER_BUFFER_SIZE, nullptr, 0); 
    } 
    else if(id == ds::ring::inner)
    {
        inner_ring.write((const char*)inner_buffer, sizeof(uint32_t)*INNER_BUFFER_SIZE, nullptr, 0); 
    }
}

// No DMA support
void ds::render_segment(const ds::ring id, uint32_t* data, const size_t len)
{
    if(id == ds::ring::outer)
    {
        if(len <= OUTER_HEIGHT)
        {
            memcpy(reinterpret_cast<void*>(outer_buffer + HEADER_SIZE), reinterpret_cast<void*>(data), len);
        }
    } 
    else if (id == ds::ring::inner)
    {
        if(len <= INNER_HEIGHT)
        {
            memcpy(reinterpret_cast<void*>(inner_buffer + HEADER_SIZE), reinterpret_cast<void*>(data), len);
        }
        
    }
    ds::display(id);
}
