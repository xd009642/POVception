#ifndef MOTOR_CONTROL_H
#define MOTOR_CONTROL_H

#include "mbed.h"
#include "LCD_DISCO_F469NI.h"

namespace motors
{
    enum class state {
        stop, spin  
    };

    void init();

    void set_state(const motors::state s);

    void update();

    void set_lcd(LCD_DISCO_F469NI* lcd);
}


#endif
