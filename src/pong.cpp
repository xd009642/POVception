#include "pong.h"



app::pong::pong(render::framebuffer& buffer):graphics(buffer)
{
    p1.paddle_width = 0.2*graphics.get_height();
    p1.paddle_depth = 2;
    p2.paddle_width = 0.2*graphics.get_height();
    p2.paddle_depth = 2;
    ball.size = 1;
    reset();
}

bool app::pong::collides_with_player()
{
    if(ball.pos.x == p1.paddle_depth)
    {
        return (ball.pos.y >= p1.pos.y) && (ball.pos.y <= p1.pos.y+p1.paddle_width);
    }
    else if(ball.pos.x == graphics.get_width()-p2.paddle_depth)
    {
        return (ball.pos.y >= p2.pos.y) && (ball.pos.y <= p2.pos.y+p2.paddle_width);
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
    update_player(p1, app::stick_1);
    update_player(p2, app::stick_2);
    graphics.fill_rect(ball.pos.x, ball.pos.y, ball.size, ball.size, 0xFF000000);
    ball.pos += ball.vel;
    if(ball.vel.zero())
    {
        ball.vel.set(-1,1);
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
}


void app::pong::update_player(app::player_state& player, app::joystick& stick)
{
    //Apply controls \todo may need to actually apply a larger delta than 1
    auto state = stick.y_state();
    if(state == app::y_motion::down && player.pos.y>0)
    {
        player.pos.y++;
    } 
    else if(state == app::y_motion::up && (player.pos.y+player.paddle_width)<graphics.get_height())
    {
        player.pos.y--;
    }
}


void app::pong::render()
{
    // Blank where I might be drawing (super simple right now)
    graphics.fill_rect(0, 0, p1.paddle_depth, graphics.get_height(), 0xFF000000);
    graphics.fill_rect(graphics.get_width()-p2.paddle_depth, 0, p2.paddle_depth, graphics.get_height(), 0xFF000000);

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
    p2.pos.set(graphics.get_width()-p2.paddle_depth, y_pos);
    ball.pos.set(graphics.get_width()/2, y_pos);
}
