#ifndef PONG_H
#define PONG_H

#include "game_types.h"
#include "stddef.h"
#include "stdint.h"
#include "framebuffer.h"

namespace app
{
    enum class player 
    {
        one, two
    };

    struct player_state
    {
        uint16_t score;
        point2<uint16_t> pos;
        uint16_t paddle_width;
    };
    struct ball_state
    {
        point2<int16_t> pos;
        point2<int16_t> vel;
        uint8_t size;
    };
    class pong
    {
    public:
        pong(render::framebuffer& buffer);
        void set_player_position(player p, size_t x, size_t y);
        void update();
        void reset();
        void reset_positions();
    protected:
        void render();
        bool collides_with_player();
        bool collides_with_wall();
        bool ball_out();
    private:
        render::framebuffer& graphics; 
        player_state p1;
        player_state p2;
        ball_state ball;

    };
}


#endif
