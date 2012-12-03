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

// Touch Screen Init
TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);

void setup()
{
  Serial.begin(9600); // Serial Init
  Tft.init(); // init TFT library
  
  Tft.drawString(" Please Write Circle ...",0,280,1,WHITE); 
}

void loop()
{
  // a point object holds x y and z coordinates
  Point p = ts.getPoint();
  
  if (p.z > ts.pressureThreshhold) {
     Serial.print("Raw X = "); Serial.print(p.x);
     Serial.print("\tRaw Y = "); Serial.print(p.y);
     Serial.print("\tPressure = "); Serial.println(p.z);
  }
  
}
