#include "pong.h"
#include "dotstar.h"


app::pong::pong(render::framebuffer& buffer):graphics(buffer)
{
    far_left = buffer.n_col() - 7;
    far_right = buffer.n_col() - (buffer.n_col()/2);
    centre_column = far_right + (far_left - far_right)/2;
    p1.paddle_width = 0.2*graphics.get_height();
    p1.paddle_depth = 1;
    p2.paddle_width = 0.2*graphics.get_height();
    p2.paddle_depth = 1;
    ball.size = 1;
    reset();
}

bool app::pong::collides_with_player()
{
    if(ball.pos.x == far_left - p1.paddle_depth)
    {
        return (ball.pos.y >= p1.pos.y) && (ball.pos.y <= p1.pos.y+p1.paddle_width);
    }
    else if(ball.pos.x == far_right + p2.paddle_depth)
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
    return ball.pos.x > far_left || ball.pos.x < far_right;
}

void app::pong::update() 
{
    update_player(p1, app::stick_2);
    update_player(p2, app::stick_1);
    graphics.fill_rect(ball.pos.x, ball.pos.y, ball.size, ball.size, ds::BLACK);
    ball.pos += ball.vel;
    if(ball.vel.zero())
    {
        ball.vel.set(1,1);
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
        player.pos.y-=2;
    } 
    else if(state == app::y_motion::up && (player.pos.y+player.paddle_width)<graphics.get_height())
    {
        player.pos.y+=2;
    }
}


void app::pong::render()
{
    graphics.clear(ds::BLACK);
    // Blank where I might be drawing (super simple right now)
    //graphics.fill_rect(far_left-p1.paddle_depth, 0, p1.paddle_depth, graphics.get_height(), ds::BLACK);
   // graphics.fill_rect(far_right, 0, p2.paddle_depth, graphics.get_height(), ds::BLACK);

    // Draw!
    graphics.fill_rect(p1.pos.x, p1.pos.y, 2, p1.paddle_width, ds::WHITE);
    graphics.fill_rect(p2.pos.x, p2.pos.y, 2, p2.paddle_width, ds::WHITE);
    graphics.fill_rect(ball.pos.x, ball.pos.y, ball.size, ball.size, ds::WHITE);
}


void app::pong::reset() 
{
    graphics.clear(ds::BLACK);
    p1.score = 0;
    p2.score = 0;
    reset_positions();
}


void app::pong::reset_positions()
{
    auto y_pos = graphics.get_height()/2;
    p1.pos.set(far_left, y_pos);
    p2.pos.set(far_right, y_pos);
    ball.pos.set(centre_column, y_pos);
}
