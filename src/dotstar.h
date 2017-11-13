#ifndef DOTSTAR_H
#define DOTSTAR_H

#include "stdint.h"
#include "stddef.h"

namespace ds
{
    enum class ring {
        inner,
        outer
    };

    void init();
    void display(const ring id);
    void render_segment(const ring id, uint32_t* data, const size_t len);


}


#endif
