#ifndef GUI_H
#define GUI_H

#include "stdint.h"
#include <string>
#include <functional>
#include "LCD_DISCO_F469NI.h"
#include "TS_DISCO_F469NI.h"

namespace gui
{

    struct button
    {
        uint16_t x;
        uint16_t y;
        uint16_t width;
        uint16_t height;
        uint32_t border;
        uint32_t text_colour;
        std::string text;
        std::function<void()> action;

        void render(LCD_DISCO_F469NI& lcd)
        {
            auto state = lcd.GetTextColor();
            lcd.SetTextColor(border);
            lcd.DrawRect(x,y,width,height);
            lcd.SetTextColor(text_colour);
            lcd.DisplayStringAt(x + width/4, y+height/2-4, 
                    (uint8_t*)text.c_str(), LEFT_MODE);
            lcd.SetTextColor(state);
        }

        bool poll_event(const TS_StateTypeDef& touch)
        {
            if(!action)
                return false;
            if(touch.touchDetected == 1)
            {
                if(touch.touchX[0] > x && touch.touchX[0] < (x+width) &&
                        touch.touchY[0] > y && touch.touchY[0] < (y+height))
                {
                    action();
                    return true;
                }
            }
            return false;
        }
    };

    class interface
    {
    public:
        //! n_buttons is number of buttons to be displayed.
        interface(LCD_DISCO_F469NI& screen, size_t n_buttons = 3);
        ~interface();

        void render(size_t n);
        void render_all();
        //! if overruns returns last button
        button& get_button(const size_t index);

        void update(const TS_StateTypeDef& pos);

    private:
        LCD_DISCO_F469NI& screen;
        const size_t len;
        button* buttons;
    };
}




#endif
