#include "neopixel.h"

struct strip_cfg {
    uint8_t pin;
    uint8_t length;
    unsigned int pin;
};

struct np::strip {
    uint8_t pixels[MAX_SEGMENT_SIZE*3u];
};

strip_cfg configs[np::SEGMENT_COUNT] = {{0,0,0}};

np::strip buffer[np::SEGMENT_COUNT];


bool np::init_all()
{
    for(int i=0; i<np::SEGMENT_COUNT; i++) 
    {
         
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

bool np::render_segment(const segment_id id) 
{
    return false;
}
