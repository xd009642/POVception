#ifndef PONG_H
#define PONG_H

#include "game_types.h"
#include "stddef.h"
#include "stdint.h"


namespace pong
{
    enum class player 
    {
        one, two
    };

    void set_player_position(player p, size_t x, size_t y);
    
    void update();

    void reset();
}


#endif
