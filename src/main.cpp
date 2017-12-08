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

//Do I need to set the alt functions for the pins?
LCD_DISCO_F469NI lcd;
TS_DISCO_F469NI ts;
SDFileSystem sd("sd");
Timer t;
InterruptIn wire(PA_1);
InterruptIn wire2(PG_13);

static constexpr uint32_t BACKGROUND_COLOUR = 0xFFED0000;
static constexpr uint32_t SCREEN_WIDTH = 800;
static constexpr uint32_t SCREEN_HEIGHT = 480;
// These are approximates just to give decent spacing
static constexpr uint32_t BORDER_HEIGHT = 60;
static constexpr uint32_t BORDER_WIDTH = 120;

volatile bool triggered = false;
volatile bool triggered2 = false;
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

void trig()
{
    triggered = true;
}

void trig2()
{
    triggered2 = true;
}

int main()
{
    t.start();
    TS_StateTypeDef touch;
    wire.rise(&trig);
    wire2.rise(&trig2);
    uint8_t text[30];
    uint8_t status;
    lcd.SetTextColor(LCD_COLOR_WHITE);
    lcd.Clear(BACKGROUND_COLOUR);
    lcd.SetBackColor(BACKGROUND_COLOUR);
    BSP_LCD_SetFont(&Font24);
    status = ts.Init(lcd.GetXSize(), lcd.GetYSize());
    prepare_background();
    // 0 means good, non-zero is error code. 
    lcd.DisplayStringAt(0, LINE(2), (uint8_t *)"XMAS CHALLENGE SPIN", CENTER_MODE);
    auto a0 = AnalogIn(A0);
    auto a1 = AnalogIn(A1);
    auto a2 = AnalogIn(A2);
    auto a3 = AnalogIn(A3);
    auto he1 = DigitalIn(D2);
    auto he2 = DigitalIn(D3);
    np::init_all();
    uint32_t np_leds[16] ={0xFF00u};
    int pwmwid = 0;
    int delta = 2;
    int maxpwm = 1400;
    auto m1 = PwmOut(D5);
    auto m2 = PwmOut(D6);
    wait_ms(1500);
    m1.period_ms(20);
    m2.period_ms(20);
    m1.pulsewidth_us(pwmwid);
    m2.pulsewidth_us(pwmwid);
    render::framebuffer outer_buffer(OUTER_WIDTH, OUTER_HEIGHT);
    render::framebuffer inner_buffer(INNER_WIDTH, INNER_HEIGHT);
    ds::ring outer(inner_buffer, ds::outer); 
    ds::ring inner(outer_buffer, ds::inner); 
    inner_buffer.clear(0x00FFFFFF);
    outer_buffer.clear(0x00FFFFFF);
    outer_buffer.swap();
    inner_buffer.swap();
    while(1)
    {
        np::render_segment(np_leds, 16);
        sprintf((char*)text, "A0 = %f", a0.read());
        lcd.DisplayStringAt(0, LINE(3), (uint8_t*)text, LEFT_MODE);
        sprintf((char*)text, "A1 = %f", a1.read());
        lcd.DisplayStringAt(0, LINE(4), (uint8_t*)text, LEFT_MODE);
        sprintf((char*)text, "A2 = %f", a2.read());
        lcd.DisplayStringAt(0, LINE(5), (uint8_t*)text, LEFT_MODE);
        sprintf((char*)text, "A3 = %f", a3.read());
        lcd.DisplayStringAt(0, LINE(6), (uint8_t*)text, LEFT_MODE);
        if(he1.read())
        {
            lcd.DisplayStringAt(0, LINE(7), (uint8_t*)"Hall effect 1 high", LEFT_MODE);
        }
        else
        {
            lcd.DisplayStringAt(0, LINE(7), (uint8_t*)"Hall effect 1 low", LEFT_MODE);
        }
        if(he2.read())
        {
            lcd.DisplayStringAt(0, LINE(8), (uint8_t*)"Hall effect 2 high", LEFT_MODE);
        }
        else
        {
            lcd.DisplayStringAt(0, LINE(8), (uint8_t*)"Hall effect 2 low", LEFT_MODE);
        }
        outer.display(0);
        inner.display(0);
        if(pwmwid == maxpwm || (pwmwid + delta == 0))
        {
            delta *= -1;
        }
        pwmwid += delta;
        sprintf((char*)text, "PWM width is %dus", pwmwid);
        lcd.DisplayStringAt(0, LINE(9), text, LEFT_MODE);
        m1.pulsewidth_us(pwmwid);
        m2.pulsewidth_us(pwmwid);
        wait_ms(16);
    }
    
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
    sprintf((char*)text, "Startup time %fs", t.read());
    lcd.DisplayStringAt(0, LINE(14), text, LEFT_MODE);
    t.reset();
    while(1)
    {
        ts.GetState(&touch);
        btn.poll_event(touch);
        t.start();
        outer.display(col);
        int bytes = 23*sizeof(uint32_t);
        //int bytes = np::render_segment(np::INNER_0, buffer.get_render_column(col), 26);
        t.stop();
        if(!triggered)
            sprintf((char*)text, "Rendered %d bytes in %fs", bytes, t.read());
        else 
            sprintf((char*)text, "I'm triggered");
        if(triggered2) {
            uint8_t text2[] = "hello";
            lcd.DisplayStringAt(0, LINE(14), text2, LEFT_MODE);
        }
        t.reset();
        lcd.DisplayStringAt(0, LINE(15), text, LEFT_MODE);
        outer_buffer.pixel_at(col,col)+=20;
        col++;
        if(col==26) {
            outer_buffer.swap();
            col = 0;
        }
    }
}
