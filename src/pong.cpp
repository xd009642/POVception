#include "pong.h"
#include "display_settings.h"

app::pong::pong(render::framebuffer& buffer):graphics(buffer)
{
    p1.paddle_width = 0.2*graphics.get_height();
    p2.paddle_width = 0.2*graphics.get_height();
    reset();
}

bool app::pong::collides_with_player()
{
    if(ball.pos.x == 0)
    {
        return ball.pos.x < p1.pos.y || 
            (ball.pos.x > p1.pos.y + p1.paddle_width);
    }
    else if(ball.pos.x == static_cast<int16_t>(graphics.get_width()))
    {
        return ball.pos.x<p2.pos.y || 
            (ball.pos.x > p2.pos.y + p2.paddle_width);
    }
    return false;
}

bool app::pong::collides_with_wall()
{
    return ball.pos.y < 1 || ball.pos.y > static_cast<int16_t>(graphics.get_height() -1 );
}

bool app::pong::ball_out() 
{
    return ball.pos.x < 0 || ball.pos.x >static_cast<int16_t>(graphics.get_width());
}

void app::pong::update() 
{
    if(ball.vel.zero())
    {
        ball.vel.set(1,-1);
    }
    if(collides_with_player())
    {
        ball.vel.x *= -1;
    } 
    else if(collides_with_wall()) 
    {
        ball.vel.y *= -1;
    } 
    else if(ball_out()) {
        if(ball.pos.x < 0)
            p2.score++;
        else 
            p1.score++;
        reset_positions();
    }
    render();
    ball.pos += ball.vel;
}


void app::pong::render()
{
    // Blank where I might be drawing (super simple right now)
    graphics.fill_rect(0,p1.pos.y,2, graphics.get_height(), 0);
    graphics.fill_rect(graphics.get_width()-2, 0, 2, graphics.get_height(), 0);
    graphics.fill_rect(ball.pos.x-ball.size, ball.pos.y-ball.size, ball.size*2,ball.size*2, 0);

    // Draw!
    graphics.fill_rect(p1.pos.x, p1.pos.y, 2, p1.paddle_width, 0xFFFFFFFF);
    graphics.fill_rect(p2.pos.x, p2.pos.y, 2, p2.paddle_width, 0xFFFFFFFF);
    graphics.fill_rect(ball.pos.x, ball.pos.y, ball.size, ball.size, 0xFFFFFFFF);
}


void app::pong::reset() 
{
    p1.score = 0;
    p2.score = 0;
    reset_positions();
}


void app::pong::reset_positions()
{
    auto y_pos = graphics.get_height()/2;
    p1.pos.set(0, y_pos);
    p2.pos.set(graphics.get_width()-1, y_pos);
    ball.pos.set(graphics.get_width()/2, y_pos);
}
