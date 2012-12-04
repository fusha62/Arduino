#include <stdint.h>
#include <TouchScreen.h> 
#include <TFT.h>

#ifdef SEEEDUINO
  #define YP A2   // must be an analog pin, use "An" notation!
  #define XM A1   // must be an analog pin, use "An" notation!
  #define YM 14   // can be a digital pin, this is A0
  #define XP 17   // can be a digital pin, this is A3 
#endif

#ifdef MEGA
  #define YP A2   // must be an analog pin, use "An" notation!
  #define XM A1   // must be an analog pin, use "An" notation!
  #define YM 54   // can be a digital pin, this is A0
  #define XP 57   // can be a digital pin, this is A3 
#endif

// Modify Values
#define TS_MINX 140
#define TS_MAXX 900

#define TS_MINY 120
#define TS_MAXY 940

// Touch Screen Init
TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);

void setup()
{

Tft.init();  //init TFT library

}

void loop()
{
  // a point object holds x y and z coordinates
  Point p = ts.getPoint();
  p.x = map(p.x, TS_MINX, TS_MAXX, 240, 0);
  p.y = map(p.y, TS_MINY, TS_MAXY, 320, 0);
  
  if (p.z > ts.pressureThreshhold) {
    Tft.drawLine(0,0,p.x,p.y,RED);
  }
}
