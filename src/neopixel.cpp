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
        }
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
        ct::delay(40);
        gpio_write(handle, 0);
        ct::delay(120);
    }
}

inline void write_byte(gpio_t* handle, uint8_t data)
{
    for(uint8_t b=0; b<8; b++) 
    {
        write_bit(handle, (data)&0x01);
        data = data >> 1;
    }
}

int np::render_segment(const segment_id id, 
        uint32_t* data, const size_t len) 
{
    ct::reset();
    int res = 0;
    np::strip* strip = &buffer[id];
    int b=0;
    uint32_t temp=0;
    for(int32_t i=0; i<len; i++)
    {
        temp = data[i];
        write_byte(&strip->handle, temp&0xFF);
        temp >>= 8;
        write_byte(&strip->handle, temp&0xFF);
        temp >>= 8;
        write_byte(&strip->handle, temp&0xFF);
        res++;
    }
    return res;
}
