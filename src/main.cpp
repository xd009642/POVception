#include "mbed.h"
#include "TS_DISCO_F469NI.h"
#include "LCD_DISCO_F469NI.h"
#include "neopixel.h"
#include "framebuffer.h"
#include "SDFileSystem.h"

//Do I need to set the alt functions for the pins?
SDFileSystem sd(PC_9, PC_8, PC_12, PC_11, "sd");
LCD_DISCO_F469NI lcd;
TS_DISCO_F469NI ts;
Timer t;
int main()
{
    //TS_StateTypeDef TS_State;
    uint8_t text[30];
    uint8_t status;
     
    BSP_LCD_SetFont(&Font24);
    lcd.SetTextColor(LCD_COLOR_WHITE);
    status = ts.Init(lcd.GetXSize(), lcd.GetYSize());
    
    if(sd.disk_initialize())
    {
        lcd.DisplayStringAt(0, LINE(0), (uint8_t*)"FAILED TO FIND SD CARD", CENTER_MODE);
    }
    else
    {
        lcd.DisplayStringAt(0, LINE(0), (uint8_t*)"SD card initialised", CENTER_MODE);
        FILE* background = fopen("/sd/background.bmp", "rb");
        if(background)
        {
            fseek(background, 0, SEEK_END);
            auto length = ftell(background);
            fseek(background, 0, SEEK_SET);
            char temp[30];
            sprintf((char*)temp, "Loaded %d bytes", length);
            lcd.DisplayStringAt(0, LINE(2),  (uint8_t*)temp, CENTER_MODE);
            uint8_t* img = new uint8_t[length];
            if(length == fread(img, 1, length, background))
            {
                lcd.DrawBitmap(0,0,img);
            }
            delete [] img;
            fclose(background);
        }
    }
    lcd.DisplayStringAt(0, LINE(5), (uint8_t *)"XMAS CHALLENGE", CENTER_MODE);
    wait(1);
  
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

    size_t col = 0;
    lcd.DisplayStringAt(0, LINE(7), (uint8_t*) "STARTING", CENTER_MODE);
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
