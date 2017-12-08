#ifndef NEOPIXEL_H
#define NEOPIXEL_H

#ifdef __cplusplus 
extern "C" {
#endif
#include "stm32469i_discovery.h"
#ifdef __cplusplus 
}
#endif
#include "stdint.h"
#include "gpio_object.h"
#include "gpio_api.h"
#include "stddef.h"
#include "mbed.h"
#include "InterruptManager.h"


#define MAX_SEGMENT_SIZE 26u
#define NP_COLOUR_DEPTH 3u

namespace np {

    struct strip;

    /**
     * Initialise all Neopixel strips and interrupts
     */
    bool init_all();
    /**
     * Render given Neopixel strip
     */
    int render_segment(uint32_t* data, const size_t len);
    void write_byte(gpio_t* handle, uint8_t data);
}


#endif 
