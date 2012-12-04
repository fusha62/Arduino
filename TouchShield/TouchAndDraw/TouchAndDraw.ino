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
int bufx=0;
int bufy=0;
int seq=0;

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
    if (sqrt(abs((double)p.x-(double)bufx)
            +abs((double)p.y-(double)bufy)
        )>3){
      seq=0;
    }else{
      seq=1;
    }
    
    if (seq==1){
      Tft.drawLine(bufx,bufy,p.x,p.y,RED);
      bufx=p.x;
      bufy=p.y;
    }else{
      bufx=p.x;
      bufy=p.y;
    }
  }
}
