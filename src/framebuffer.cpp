#include "framebuffer.h"
#include "string.h"

render::framebuffer::framebuffer(const size_t& width, const size_t& height):
    width(width),
    height(height)
{
    render_buffer = new uint32_t[width*height]();
    proc_buffer = new uint32_t[width*height]();
    valid = render_buffer && proc_buffer;
}


render::framebuffer::~framebuffer()
{
    delete [] render_buffer;
    delete [] proc_buffer;
}


void render::framebuffer::swap()
{
    memcpy(render_buffer, proc_buffer, sizeof(uint32_t)*width*height);
}


uint32_t* render::framebuffer::get_render_column(size_t index)
{
    return &render_buffer[index*width];
}


uint32_t& render::framebuffer::pixel_at(size_t x, size_t y)
{
    return proc_buffer[x*width + y];
}


void render::framebuffer::clear(const uint32_t& clear)
{
    for(size_t i=0; i<width*height; i++)
    {
        proc_buffer[i] = clear;
    }
}


void render::framebuffer::fill_rect(const size_t& x, const size_t y, 
                                    const size_t w, const size_t h, 
                                    const uint32_t c)
{
    size_t xend = x+w;
    if(xend>width) { 
        xend= width;
    }
    size_t yend = y+h;
    if(yend>height) { 
        yend= height;
    }
    for(size_t xp=x; xp<xend; xp++)
    {
        for(size_t yp=y; yp<yend; yp++)
        {
            pixel_at(xp, yp) = c;
        }
    }
}


const size_t& render::framebuffer::n_row() const
{
    return height;
}


const size_t& render::framebuffer::n_col() const
{
    return width;
}


bool render::framebuffer::is_valid() const {
    return valid;
}
        

app::point2<size_t> render::framebuffer::size() const
{
    return {width, height};
}

size_t render::framebuffer::get_width() const 
{
    return width;
}

size_t render::framebuffer::get_height() const 
{
    return height;
}

