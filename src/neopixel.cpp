#include "neopixel.h"
#include "PinNames.h"
#include "gpio_object.h"
#include "gpio_api.h"

struct strip_cfg {
    PinName pin;
    uint8_t length;
    uint8_t irq;
  //  IRQn_Type irq;
};

struct np::strip {
    gpio_t handle;
    uint8_t pixels[MAX_SEGMENT_SIZE*3u];
};

// lets use D10 (P13 PH6
strip_cfg configs[np::SEGMENT_COUNT] = {{D0, 1 ,0}};

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
            for(int j=0; j<configs[i].length*3; j++) {
                buffer[i].pixels[j] = 0;
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
        count *= 3;
        for(size_t i=start*3; i<count; i+=3) 
        {
            buffer[id].pixels[i] = rgb[i];
            buffer[id].pixels[i+1] = rgb[i+1];
            buffer[id].pixels[i+2] = rgb[i+2];
        }
    }
}

inline void write_bit(gpio_t* handle, const bool value)
{
    gpio_write(handle, 0);
    gpio_write(handle, value);
    gpio_write(handle, 1);
}

int np::render_segment(const segment_id id) 
{
    int res = 0;
    np::strip* strip = &buffer[id];
    int b=0;
    uint8_t data=0;
    for(int32_t i=0; i<configs[id].length*3; i++)
    {
        data = strip->pixels[i];
        for(b=0; b<8; b++) 
        {
            write_bit(&strip->handle, (data)&0x01);
            data = data >> 1;
        }
        res++;
    }
    return res;
}
