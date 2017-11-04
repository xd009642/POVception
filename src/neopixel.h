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
#include "stddef.h"
#include "mbed.h"
#include "InterruptManager.h"


#define MAX_SEGMENT_SIZE 26u
#define NP_COLOUR_DEPTH 3u

namespace np {

    struct strip;

    enum segment_id {
        INNER_0 = 0u,
        INNER_1,
        OUTER_0,
        OUTER_1,
        OUTER_2,
        OUTER_3,
        SEGMENT_COUNT
    };
    /**
     * Initialise all Neopixel strips and interrupts
     */
    bool init_all();
    /**
     * Render given Neopixel strip
     */
    int render_segment(const segment_id id, uint32_t* data, const size_t len);
}


#endif 
