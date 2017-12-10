#include "motor_control.h"
#include "mbed.h"
extern "C" {
#include "bldc_motor_controller_full_count.h"
}

LCD_DISCO_F469NI* mlcd = nullptr;

Timer motor_timer;

PwmOut motor_1(D5);
PwmOut motor_2(D6);

InterruptIn he1(D3);
InterruptIn he2(D2);

void h1_trigger()
{
    bldc_motor_controller_full_co_U.hall_effect_trig = true;
}

void h2_trigger()
{

}


void motors::init()
{
    he1.rise(&h1_trigger);
    he2.rise(&h2_trigger);
    bldc_motor_controller_full_count_initialize();
    motor_1.period_us(20'000);
    motor_1.write(0.0f);
    motor_timer.start();
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


void motors::update()
{
    bldc_motor_controller_full_co_U.rotation_count_in = 
        static_cast<double>(motor_timer.read_us());
    bldc_motor_controller_full_count_step();
    motor_1.write(bldc_motor_controller_full_co_Y.outer_motor_pwm);
    if(nullptr != mlcd)
    {
        char text[50] = {0};
        if(bldc_motor_controller_full_co_U.hall_effect_trig) 
        {
            mlcd->DisplayStringAt(0, LINE(11), (uint8_t*)"TRIGGERED", RIGHT_MODE);
        }
        else 
        {
            mlcd->DisplayStringAt(0, LINE(11), (uint8_t*)"         ", RIGHT_MODE);
        }
        sprintf((char*)text, "PWM %lf", bldc_motor_controller_full_co_Y.outer_motor_pwm);
        mlcd->DisplayStringAt(0, LINE(14), (uint8_t*)text, LEFT_MODE);
        sprintf(text, "ring pos %f", bldc_motor_controller_full_co_Y.ring_position_ratio);
        mlcd->DisplayStringAt(0, LINE(15), (uint8_t*)text, LEFT_MODE);
        sprintf(text, "prev_speed %0.5f", 
                bldc_motor_controller_full_co_Y.prev_frame_speed);
        mlcd->DisplayStringAt(0, LINE(16), (uint8_t*)text, LEFT_MODE);
    }
    if(bldc_motor_controller_full_co_U.hall_effect_trig) {
        bldc_motor_controller_full_co_U.hall_effect_trig = false;
    }
    if(bldc_motor_controller_full_co_Y.rot_count_load) {
        motor_timer.reset();
    }
}
    
void motors::set_lcd(LCD_DISCO_F469NI* lcd_)
{
    mlcd = lcd_;
}
