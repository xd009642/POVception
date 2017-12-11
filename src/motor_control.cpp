#include "motor_control.h"
#include "mbed.h"
extern "C" {
#include "bldc_motor_controller_full_count.h"
}


Timer motor_timer;
Timer inner_timer;

PwmOut motor_1(D5);
PwmOut motor_2(D6);

InterruptIn he1(D3);
InterruptIn he2(D2);

void h1_trigger()
{
    bldc_motor_controller_full_co_U.outer_hall_effect_trig = true;
}

void h2_trigger()
{
    bldc_motor_controller_full_co_U.inner_hall_effect_trig = true;
}


void motors::init()
{
    he1.rise(&h1_trigger);
    he2.rise(&h2_trigger);
    bldc_motor_controller_full_count_initialize();
    motor_1.period_us(20'000);
    motor_1.write(0.0f);
    motor_2.period_us(20'000);
    motor_2.write(0.0f);
    motor_timer.start();
    inner_timer.start();
}

bool motors::is_spinning() 
{
    return !bldc_motor_controller_full_co_U.halt_motor_req;
}

void motors::set_state(const motors::state s)
{
    switch(s)
    {
        case motors::state::stop: 
            bldc_motor_controller_full_co_U.halt_motor_req = true;
            break;
        case motors::state::spin:
            bldc_motor_controller_full_co_U.arm_motor_req = true;
            bldc_motor_controller_full_co_U.halt_motor_req = false;
            break;
    }
}
    

float motors::position(motors::motor m)
{
    float ratio=0.0f;
    switch(m) 
    {
    case motors::motor::inner:
        ratio = bldc_motor_controller_full_co_Y.inner_ring_position_ratio;
        break;
    case motors::motor::outer:
        ratio = bldc_motor_controller_full_co_Y.outer_ring_position_ratio;
        break;
    }
    if(ratio < 0.0f)
    {
        ratio = 0.0f;
    }
    else if(ratio > 1.0f)
    {
        ratio = 1.0f;
    }
    return ratio;
}


void motors::update()
{
    bldc_motor_controller_full_co_U.outer_rotation_count_in = 
        static_cast<double>(motor_timer.read_us());
    bldc_motor_controller_full_co_U.inner_rotation_count_in = 
        static_cast<double>(inner_timer.read_us());

    bldc_motor_controller_full_count_step();
    motor_1.write(bldc_motor_controller_full_co_Y.outer_motor_pwm);
    motor_2.write(bldc_motor_controller_full_co_Y.inner_motor_pwm);

    bldc_motor_controller_full_co_U.inner_hall_effect_trig = false;
    bldc_motor_controller_full_co_U.outer_hall_effect_trig = false;
    if(bldc_motor_controller_full_co_Y.outer_rot_count_load) {
        motor_timer.reset();
    }
    if(bldc_motor_controller_full_co_Y.inner_rot_count_load) {
        inner_timer.reset();
    }
}

