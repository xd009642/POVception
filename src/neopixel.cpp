#include "neopixel.h"
#include "PinNames.h"
#include "cycle_timer.h"


struct strip_cfg {
    PinName pin;
    uint8_t length;
};
struct np::strip {
    gpio_t handle;
};

// lets use D10 (P13 PH6
const strip_cfg config = {D9, 16};

np::strip buffer;

bool np::init_all()
{
    if(config.pin != NC)
    {
        gpio_init_out(&buffer.handle, config.pin);
        buffer.handle.gpio->OSPEEDR |=  0xffffffff;
    }
    return true;
}


inline void write_bit(gpio_t* handle, const bool value)
{
    if(value) 
    {
        gpio_write(handle, 1);
        ct::delay(110);
        gpio_write(handle, 0);
        ct::delay(95);
    }else {
        gpio_write(handle, 1);
        ct::delay(50);
        gpio_write(handle, 0);
        ct::delay(120);
    }
}

void np::write_byte(gpio_t* handle, uint8_t data)
{
    for(uint8_t b=0; b<8; b++) 
    {
        write_bit(handle, (data)&0x01);
        data = data >> 1;
    }
}

int np::render_segment(uint32_t* data, const size_t len) 
{
    ct::reset();
    int res = 0;
    uint32_t temp=0;
    for(uint32_t i=0; i<len; i++)
    {
        temp = data[i];
        write_byte(&buffer.handle, temp&0xFF);
        temp >>= 8;
        write_byte(&buffer.handle, temp&0xFF);
        temp >>= 8;
        write_byte(&buffer.handle, temp&0xFF);
        res++;
    }
    return res;
}
