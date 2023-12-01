//Tech Trends Shameer
//Display Text in TFT Display

#include <Adafruit_TFTLCD.h> 
#include <Adafruit_GFX.h>    
#include <TouchScreen.h>

#define LCD_CS A3 
#define LCD_CD A2 
#define LCD_WR A1 
#define LCD_RD A0 
#define LCD_RESET A4 

#define TS_MINX 122
#define TS_MINY 111
#define TS_MAXX 942
#define TS_MAXY 890

#define YP A3
#define XM A2
#define YM 9
#define XP 8

#define BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF

Adafruit_TFTLCD tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);

TouchScreen ts = TouchScreen(XP, YP, XM, YM, 364);

boolean buttonEnabled = true;

void setup() {
  
  tft.reset();
  uint16_t identifier = tft.readID();
  tft.begin(identifier);
  tft.setRotation(1);
  tft.fillScreen(WHITE);
  tft.drawRect(0,0,319,240,YELLOW);
  
  tft.setCursor(30,40);
  tft.setTextColor(BLACK);
  tft.setTextSize(2);
  tft.print("Touch Screen LCD Display");
  
  tft.setCursor(115,80);
  tft.setTextColor(BLACK);
  tft.setTextSize(2);
  tft.print("\n            by");

  tft.fillRect(25,140, 240, 30, BLACK);
  tft.drawRect(25,140,240,30,BLACK);
  tft.setCursor(35,150);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);
  tft.print("Tech Trends Shameer");
  
  tft.fillRect(50,180, 210, 30, RED);
  tft.drawRect(50,180,210,30,BLACK);
  tft.setCursor(60,190);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);
  tft.print("Please Subscribe");

}

void loop() {
  TSPoint p = ts.getPoint();
  
  if (p.z > ts.pressureThreshhold) {
    
   p.x = map(p.x, TS_MAXX, TS_MINX, 0, 320);
   p.y = map(p.y, TS_MAXY, TS_MINY, 0, 480);
       
   if(p.x>50 && p.x<260 && p.y>180 && p.y<270 && buttonEnabled){
    
    buttonEnabled = false;
    
    pinMode(XM, OUTPUT);
    pinMode(YP, OUTPUT);
    
    tft.fillScreen(WHITE);
    tft.drawRect(0,0,319,240,YELLOW);
    tft.setCursor(50,70);
    tft.setTextColor(BLACK);
    tft.setTextSize(3);
    tft.print(" Thank you\n\n       for\n\n     support");
   }  
  }
}
