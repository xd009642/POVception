#include "pong.h"
#include "display_settings.h"


struct pong_state
{
    size_t player1_score;
    size_t player2_score;
    size_t player1_y;
    size_t player2_y;
    app::point2i ball;
    app::point2i ball_velocity;
    size_t paddle_width;
};

#define PONG_RESET {0,0,0,0,{30,30},{0,0},10}

pong_state state = PONG_RESET;

bool collides_with_player()
{
    if(state.ball.x == 0)
    {
        return state.ball.x < state.player1_y || 
            (state.ball.x > state.player1_y + state.paddle_width);
    }
    else if(state.ball.x == OUTER_WIDTH)
    {
        return state.ball.x<state.player2_y || 
            (state.ball.x > state.player2_y + state.paddle_width);
    }
    return false;
}

bool collides_with_wall()
{
    return state.ball.y < 1 || state.ball.y > (OUTER_HEIGHT -1 );
}

bool ball_out() 
{
    return state.ball.x < 0 || state.ball.x > OUTER_WIDTH;
}

void update() 
{
    if(state.ball_velocity.zero())
    {
        state.ball_velocity = {1,-1};
    }
    state.ball += state.ball_velocity;
    if(collides_with_player())
    {
        state.ball_velocity.x *= -1;
    } 
    else if(collides_with_wall()) 
    {
        state.ball_velocity.y *= -1;
    } 
    else if(ball_out()) {
        if(state.ball.x < 0)
            state.player2_score++;
        else 
            state.player1_score++;
    }
}


void reset() 
{
    state = PONG_RESET;
}

