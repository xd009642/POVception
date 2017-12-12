#include "gui.h"

static constexpr uint32_t WIDTH_OFFSET = 40;
static constexpr uint32_t HEIGHT_OFFSET = 150;
static constexpr size_t COLUMN_COUNT = 4;

gui::interface::interface(LCD_DISCO_F469NI& screen, size_t n_buttons):
    screen(screen),
    len(n_buttons),
    buttons(nullptr)
{
    if(n_buttons > 0u)
    {
        buttons = new gui::button[n_buttons];
        int c = 0; 
        int r = 0;
        int i = 0;
        while(i<n_buttons)
        {
            buttons[i].x = WIDTH_OFFSET + c*(150+WIDTH_OFFSET);
            buttons[i].y = HEIGHT_OFFSET + r*(110);
            buttons[i].width = 150;
            buttons[i].height = 100;
            buttons[i].border = LCD_COLOR_GREEN;
            buttons[i].text_colour = LCD_COLOR_WHITE;
            c++;
            if(c== COLUMN_COUNT) {
                c = 0;
                r++;
            }
            i++;
        }
    }
}


gui::interface::~interface()
{
    if(buttons != nullptr)
    {
        delete [] buttons;
    }
}


void gui::interface::render(size_t n)
{
    if(n>len)
    {
        n = len;
    }
    for(size_t i=0; i<n; i++)
    {
        buttons[i].render(screen);
    }
}


void gui::interface::render_all()
{
    render(len);
}


gui::button& gui::interface::get_button(const size_t index)
{
    if(index >= len)
    {
        return buttons[len-1];
    }
    else
    {
        return buttons[index];
    }
}


void gui::interface::update(const TS_StateTypeDef& pos)
{
    if(pos.touchDetected != 1)
        return;
    for(size_t i=0; i<len; i++)
    {
        if(buttons[i].poll_event(pos))
        {
            break;
        }
    }
}
