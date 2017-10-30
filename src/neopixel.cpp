#include "neopixel.h"
#include "PinNames.h"
#include "gpio_object.h"
#include "gpio_api.h"
#include "cycle_timer.h"


struct strip_cfg {
    PinName pin;
    uint8_t length;
    uint8_t irq;
  //  IRQn_Type irq;
};
struct np::strip {
    gpio_t handle;
    uint8_t pixels[MAX_SEGMENT_SIZE*NP_COLOUR_DEPTH];
};

// lets use D10 (P13 PH6
strip_cfg configs[np::SEGMENT_COUNT] = {{D8, 26,0}};

np::strip buffer[np::SEGMENT_COUNT];

bool np::init_all()
{
    for(int i=0; i<np::SEGMENT_COUNT; i++) 
    {
        if(configs[i].irq != 0) 
        {
            //InterruptManager::get()->add_handler(configs ...
        }
        if(configs[i].pin != 0)
        {
            gpio_init_out(&buffer[i].handle, configs[i].pin);
            buffer[i].handle.gpio->OSPEEDR |=  0xffffffff;
            for(int j=0; j<configs[i].length*NP_COLOUR_DEPTH; j++) {
                buffer[i].pixels[j] = 0xCC;
            }
        }
    }
    return true;
}


void np::write_pixels(const np::segment_id id, 
        const uint8_t* rgb, 
        const size_t start,
        const size_t n_pixels) 
{
    if(start >= MAX_SEGMENT_SIZE) {
        return;
    } else {
        size_t count = (n_pixels+start)<=MAX_SEGMENT_SIZE ? n_pixels:(MAX_SEGMENT_SIZE-start);
        count *= NP_COLOUR_DEPTH;
        for(size_t i=start; i<count; i+=NP_COLOUR_DEPTH) 
        {
            buffer[id].pixels[i] = rgb[i];
            buffer[id].pixels[i+1] = rgb[i+1];
            buffer[id].pixels[i+2] = rgb[i+2];
            if( NP_COLOUR_DEPTH == 4) {
                buffer[id].pixels[i+3] = rgb[i+3];
            }
        }
    }
}

inline void write_bit(gpio_t* handle, const bool value)
{
    if(value) 
    {
        gpio_write(handle, 1);
        ct::delay(110);
        gpio_write(handle, 0);
        ct::delay(90);
    }else {
        gpio_write(handle, 1);
        ct::delay(40);
        gpio_write(handle, 0);
        ct::delay(120);
    }
}

int np::render_segment(const segment_id id) 
{
    ct::reset();
    int res = 0;
    np::strip* strip = &buffer[id];
    int b=0;
    uint8_t data=0;
    for(int32_t i=0; i<configs[id].length*NP_COLOUR_DEPTH; i++)
    {
        data = strip->pixels[i];
        for(b=0; b<8; b++) 
        {
            write_bit(&strip->handle, (data)&0x01);
            data = data >> 1;
        }
        res++;
    }
    wait_us(50);
    return res;
}
