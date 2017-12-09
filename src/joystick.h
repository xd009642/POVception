#ifndef JOYSTICK_H
#define JOYSTICK_H
#include "mbed.h"
#include "stdint.h"
// Joysticks only used to control apps so in app namespace

namespace app
{
    enum class y_motion
    {
        up, down, none
    };
    enum class x_motion
    {
        left, right, none
    };

    static constexpr uint16_t LOWER_DEADZONE = 0x7FE0;
    static constexpr uint16_t UPPER_DEADZONE = 0x8020;

    struct joystick
    {
        AnalogIn x_axis;
        AnalogIn y_axis;

        y_motion y_state() 
        {
            auto state = y_axis.read_u16();
            if(state < LOWER_DEADZONE)
            {
                return y_motion::down;
            }
            else if(state > UPPER_DEADZONE)
            {
                return y_motion::up;
            }
            return y_motion::none;
        }

        x_motion x_state()
        {
            auto state = x_axis.read_u16();
            if(state < LOWER_DEADZONE)
            {
                return x_motion::left;
            }
            else if(state > UPPER_DEADZONE)
            {
                return x_motion::right;
            }
            return x_motion::none;
        }
    };

    extern joystick stick_1;
    extern joystick stick_2;
}


#endif 
