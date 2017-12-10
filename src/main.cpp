#include "mbed.h"
#include "TS_DISCO_F469NI.h"
#include "LCD_DISCO_F469NI.h"
#include "SD_DISCO_F469NI.h"
#include "neopixel.h"
#include "dotstar.h"
#include "framebuffer.h"
#include "SDFileSystem.h"
#include "background.h"
#include "gui.h"
#include "display_settings.h"
#include "motor_control.h"

//Do I need to set the alt functions for the pins?
LCD_DISCO_F469NI lcd;
TS_DISCO_F469NI ts;
SDFileSystem sd("sd");
Timer t;

static constexpr uint32_t BACKGROUND_COLOUR = 0xFFED0000;
static constexpr uint32_t SCREEN_WIDTH = 800;
static constexpr uint32_t SCREEN_HEIGHT = 480;
// These are approximates just to give decent spacing
static constexpr uint32_t BORDER_HEIGHT = 60;
static constexpr uint32_t BORDER_WIDTH = 120;

bool init_sd_card() {
    return sd.disk_initialize() == 0;
}

void prepare_background()
{
    const uint32_t margin = 30;
    const uint32_t spacing = 5;
    for(uint32_t i=margin; i<SCREEN_WIDTH-margin; i+=(spacing+BORDER_WIDTH))
    {
        lcd.DrawBitmap(i, margin, resources_border_top_bmp);
        lcd.DrawBitmap(i, SCREEN_HEIGHT-BORDER_HEIGHT-margin, resources_border_bottom_bmp);
    }
}

void launch_pong()
{
    lcd.DisplayStringAt(0, LINE(1), (uint8_t*)"PLAYING PONG", RIGHT_MODE);
}

void halt_motor()
{
    lcd.DisplayStringAt(0, LINE(10), (uint8_t*)"HALTING ", RIGHT_MODE);
    motors::set_state(motors::state::stop);
}


void spin_up()
{
    lcd.DisplayStringAt(0, LINE(10), (uint8_t*)"SPINNING", RIGHT_MODE);
    motors::set_state(motors::state::spin);
}


int main()
{
    TS_StateTypeDef touch;
    lcd.SetTextColor(LCD_COLOR_WHITE);
    lcd.Clear(BACKGROUND_COLOUR);
    lcd.SetBackColor(BACKGROUND_COLOUR);
    BSP_LCD_SetFont(&Font24);
    // not checking status
    ts.Init(lcd.GetXSize(), lcd.GetYSize());
    prepare_background();
    // 0 means good, non-zero is error code. 
    lcd.DisplayStringAt(0, LINE(2), (uint8_t *)"XMAS CHALLENGE SPIN", CENTER_MODE);
    render::framebuffer outer_buffer(OUTER_WIDTH, OUTER_HEIGHT);
    render::framebuffer inner_buffer(INNER_WIDTH, INNER_HEIGHT);
    ds::ring outer(outer_buffer, ds::outer); 
    ds::ring inner(inner_buffer, ds::inner); 
    inner_buffer.clear(ds::RED);
    outer_buffer.clear(ds::BLUE);
    for(int i=0; i<OUTER_WIDTH; i++)
    {
        outer_buffer.pixel_at(i, 25) = ds::GREEN; 
        outer_buffer.pixel_at(i, 26) = ds::GREEN; 
        outer_buffer.pixel_at(i, 27) = ds::GREEN; 
    }
    int outer_col = 0;
    int inner_col = 0;
    outer_buffer.swap();
    inner_buffer.swap();
    gui::interface ui(lcd, 3);
    // Assume 3 apps and hack out a button
    ui.get_button(0).text = "PONG";
    ui.get_button(0).action = launch_pong;
    ui.get_button(1).text = "Spin";
    ui.get_button(1).action = spin_up;
    ui.get_button(2).text = "Halt";
    ui.get_button(2).action = halt_motor;
    motors::set_lcd(&lcd);
    motors::init(); 
    while(1)
    {
        ts.GetState(&touch);
        ui.render_all();
        ui.update(touch);
        outer.display(outer_col);
    //    inner.display(inner_col);
        inner_col++;
        outer_col++;
        if(outer_col == OUTER_WIDTH) {
            outer_buffer.swap();
            outer_col = 0;
        }
        if(inner_col == INNER_WIDTH) {
            inner_buffer.swap();
            inner_col = 0;
        }

        motors::update();
    }
}
