#ifndef FRAME_BUFFER_H
#define FRAME_BUFFER_H

#include "stdint.h"
#include <cstdlib>
#include "game_types.h"


namespace render
{
    class framebuffer
    {
    public:
        //! Construct a framebuffer class with given width and height
        framebuffer(const size_t& width, const size_t& height);
        ~framebuffer();
        bool is_valid() const;
        //! Swap render and processing buffer
        //! Call this to get your current changes rendered.
        void swap();
        //! Get column to render
        uint32_t* get_render_column(size_t index);
        //! Gets mutable pixel at a location. 
        //! Mutable operations happen on processing buffer 
        uint32_t& pixel_at(size_t x, size_t y);
        const size_t& n_row() const;
        const size_t& n_col() const;
        //! Clear the image and fill with the given colour. 
        void clear(const uint32_t& clear_colour);
        void fill_rect(const size_t& x, const size_t y, const size_t w, const size_t h, const uint32_t c);
        app::point2<size_t> size() const;
        size_t get_width() const; 
        size_t get_height() const; 
    private:
        uint32_t* render_buffer;
        uint32_t* proc_buffer;
        const size_t width;
        const size_t height;
        bool valid;
    };
}


#endif
