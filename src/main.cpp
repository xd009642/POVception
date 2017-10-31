#include "mbed.h"
#include "TS_DISCO_F469NI.h"
#include "LCD_DISCO_F469NI.h"
#include "SD_DISCO_F469NI.h"
#include "neopixel.h"
#include "framebuffer.h"


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
    render::framebuffer buffer(26, 26);
    if(buffer.is_valid() == false)
    {
        lcd.DisplayStringAt(0, LINE(15), (uint8_t*)"BUFFER NOT ALLOCATED", CENTER_MODE);
    }
    buffer.clear(0x00000000);
    for(size_t i=0; i<26; i++)
    {
        buffer.pixel_at(i,i) = 0; 
    }
    buffer.swap();
    np::init_all();

    size_t col = 0;
    lcd.DisplayStringAt(0, LINE(7), (uint8_t*) "STARTING", CENTER_MODE);
    uint32_t colour = 0x0000FF00;
    while(1)
    {
        t.start();
        int bytes = np::render_segment(np::INNER_0, buffer.get_render_column(col), 26);
        t.stop();
        sprintf((char*)text, "Rendered %d bytes in %fs", bytes, t.read());
        t.reset();
        lcd.DisplayStringAt(0, LINE(10), text, LEFT_MODE);
        buffer.pixel_at(col,col)+=20;
        col++;
        if(col==26) {
            buffer.swap();
            col = 0;
        }
    }
}
