#ifndef SNOWFALL_H
#define SNOWFALL_H

#include "framebuffer.h"
#include "stdlib.h"
#include "stdint.h"


namespace app
{
    template<size_t FLAKES>
    class snowfall
    {
    public:
        snowfall(render::framebuffer& buffer);
        void init();
        void update();
    private:
        render::framebuffer& graphics;
        point2<int8_t> flakes[FLAKES];
        bool go_left[FLAKES];
    };



    template<size_t F>
    snowfall<F>::snowfall(render::framebuffer& buffer):graphics(buffer)
    {
        init();
    }

    template<size_t F>
    void snowfall<F>::init()
    {
        for(int i=0; i<F; i++) {
            // Initial snow positions
            flakes[i].x = rand()%graphics.n_col();
            flakes[i].y = rand()%graphics.n_row();
            go_left[i] = rand()&0x01;
        }
    }

    template<size_t F>
    void snowfall<F>::update()
    {
        graphics.clear(ds::BLACK);
        for(int i=0; i<F; i++) {
            graphics.pixel_at(flakes[i].x, flakes[i].y) = ds::BLACK;
            if(flakes[i].y > 0) {
                flakes[i].y -= 2;
                if(go_left[i]) {
                    flakes[i].x-=2; 
                } else {
                    flakes[i].x+=2;
                }
                if(flakes[i].x < 0) {
                    flakes[i].x = graphics.n_col() -1;
                } else if(flakes[i].x == graphics.n_col()) {
                    flakes[i].x = 0;
                }
                go_left[i] = !go_left[i];
            } else {
                flakes[i].y = graphics.n_row() - 1;
                flakes[i].x = rand()%graphics.n_col();
            }
            graphics.pixel_at(flakes[i].x, flakes[i].y) = ds::WHITE;
        }
    }
    
}


#endif
