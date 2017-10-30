#include "mbed.h"
#include "TS_DISCO_F469NI.h"
#include "LCD_DISCO_F469NI.h"
#include "SD_DISCO_F469NI.h"
#include "neopixel.h"

SD_DISCO_F469NI sd;
LCD_DISCO_F469NI lcd;
TS_DISCO_F469NI ts;
Timer t;
int main()
{
    //TS_StateTypeDef TS_State;
    uint8_t text[30];
    uint8_t status;
    sd.Init();
    if(sd.IsDetected()) {
        // Load gui elements!    
    }
  
    BSP_LCD_SetFont(&Font24);
  
    lcd.DisplayStringAt(0, LINE(5), (uint8_t *)"XMAS CHALLENGE", CENTER_MODE);
    wait(1);
  
    status = ts.Init(lcd.GetXSize(), lcd.GetYSize());
    lcd.SetBackColor(LCD_COLOR_BLUE);
    lcd.SetTextColor(LCD_COLOR_WHITE);
    uint8_t colours[] = {
        255, 255, 255,
        0, 255, 0,
        255, 0, 0,
        0, 0, 255, 
        0, 0, 0,
        255, 255, 0
    };
    np::init_all();
    np::write_pixels(np::INNER_0, (uint8_t*)colours, 0, 6);
    while(1)
    {
        t.start();
        int bytes = np::render_segment(np::INNER_0);
        t.stop();
        sprintf((char*)text, "Rendered %d bytes in %fs", bytes, np::toggle_time());
        lcd.DisplayStringAt(0, LINE(10), text, CENTER_MODE);
        wait_us(16666);
    }
}
