#include "motor_control.h"
#include "mbed.h"
extern "C" {
#include "bldc_motor_controller_switch.h"
}

LCD_DISCO_F469NI* mlcd = nullptr;

PwmOut motor_1(D5);
PwmOut motor_2(D6);

InterruptIn he1(D3);
InterruptIn he2(D2);

void h1_trigger()
{
    rtU.hall_effect_trig = true;
}

void h2_trigger()
{

}


void motors::init()
{
    he1.rise(&h1_trigger);
    he2.rise(&h2_trigger);
    bldc_motor_controller_switch_initialize();
    motor_1.period_us(20'000);
    motor_1.write(0.0f);
}


void motors::set_state(const motors::state s)
{
    switch(s)
    {
        case motors::state::stop: 
            rtU.halt_motor_req = true;
            break;
        case motors::state::spin:
            rtU.arm_motor_req = true;
            rtU.halt_motor_req = false;
            break;
    }
}


void motors::update()
{
    bldc_motor_controller_switch_step();
    motor_1.write(rtY.outer_motor_pwm);
    if(nullptr != mlcd)
    {
        char text[30] = {0};
        if(rtU.hall_effect_trig) 
        {
            mlcd->DisplayStringAt(0, LINE(11), (uint8_t*)"TRIGGERED", RIGHT_MODE);
        }
        else 
        {
            mlcd->DisplayStringAt(0, LINE(11), (uint8_t*)"         ", RIGHT_MODE);
        }
        sprintf((char*)text, "PWM %lf", rtY.outer_motor_pwm);
        mlcd->DisplayStringAt(0, LINE(14), (uint8_t*)text, LEFT_MODE);
    }
    if(rtU.hall_effect_trig) {
        rtU.hall_effect_trig = false;
    }
}
    
void motors::set_lcd(LCD_DISCO_F469NI* lcd_)
{
    mlcd = lcd_;
}
