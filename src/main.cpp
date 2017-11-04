#include "mbed.h"
#include "TS_DISCO_F469NI.h"
#include "LCD_DISCO_F469NI.h"
#include "SD_DISCO_F469NI.h"
#include "neopixel.h"
#include "framebuffer.h"
#include "SDFileSystem.h"
#include "background.h"
#include "gui.h"

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
    lcd.DisplayStringAt(0, LINE(10), (uint8_t*)"PLAYING PONG", RIGHT_MODE);
}

int main()
{
    TS_StateTypeDef touch;
    uint8_t text[30];
    uint8_t status;
    lcd.SetTextColor(LCD_COLOR_WHITE);
    lcd.Clear(BACKGROUND_COLOUR);
    lcd.SetBackColor(BACKGROUND_COLOUR);
    BSP_LCD_SetFont(&Font24);
    status = ts.Init(lcd.GetXSize(), lcd.GetYSize());
    prepare_background();
    // 0 means good, non-zero is error code. 
    lcd.DisplayStringAt(0, LINE(5), (uint8_t *)"XMAS CHALLENGE", CENTER_MODE);
  
    render::framebuffer buffer(26, 26);
    if(buffer.is_valid() == false)
    {
        lcd.DisplayStringAt(0, LINE(15), (uint8_t*)"BUFFER NOT ALLOCATED", CENTER_MODE);
    }
    buffer.clear(0x00000000);
    for(size_t i=0; i<26; i++) 
    {
        buffer.pixel_at(i,i)= 30;
    }
    buffer.fill_rect(5, 0, 2, 5, 0x0000FF00);
    buffer.swap();
    np::init_all();
    
    // Assume 3 apps and hack out a button
    gui::button btn;
    btn.x = 330;
    btn.y = 200;
    btn.width = 150;
    btn.height = 100;
    btn.border = LCD_COLOR_GREEN;
    btn.text_colour = LCD_COLOR_WHITE;
    btn.text = "PONG";
    btn.action = launch_pong;
    btn.render(lcd);

    size_t col = 0;
    while(1)
    {
        ts.GetState(&touch);
        btn.poll_event(touch);
        t.start();
        int bytes = np::render_segment(np::INNER_0, buffer.get_render_column(col), 26);
        t.stop();
        sprintf((char*)text, "Rendered %d bytes in %fs", bytes, t.read());
        t.reset();
        lcd.DisplayStringAt(0, LINE(15), text, LEFT_MODE);
        buffer.pixel_at(col,col)+=20;
        col++;
        if(col==26) {
            buffer.swap();
            col = 0;
        }
    }
}
