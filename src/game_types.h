#ifndef GAME_TYPES_H
#define GAME_TYPES_H

#include "stdint.h"

namespace app
{
    template<typename T>
    struct point2
    {
        T x;
        T y;

        bool zero() const 
        {
            return (x==0) && (y==0);
        }
        
        void set(T _x, T _y)
        {
            x=_x;
            y=_y;
        }
    };

    template<typename T>
    void operator+=(point2<T>& lhs, const point2<T>& rhs)
    {
        lhs.x += rhs.x;
        lhs.y += rhs.y;
    }
}

#endif
