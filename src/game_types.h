#ifndef GAME_TYPES_H
#define GAME_TYPES_H

#include "stdint.h"

namespace app
{
    struct point2i
    {
        int32_t x;
        int32_t y;

        bool zero() const 
        {
            return (x==0) && (y==0);
        }
    };

    void operator+=(point2i& lhs, const point2i& rhs)
    {
        lhs.x += rhs.x;
        lhs.y += rhs.y;
    }
}

#endif
