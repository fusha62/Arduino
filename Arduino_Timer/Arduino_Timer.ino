#include <stdint.h>
#include <stdio.h>
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

  int N;
  char buf[5];

void setup()
{
  Tft.init();  //init TFT library
  N = 300;
  sprintf(buf,"%d",N);
  Tft.drawString(buf,0,240,6,WHITE);
}

void loop()
{
  delay(1000);
  N = N - 1;
  sprintf(buf,"%d",N);
  Tft.fillRectangle(0,240,200,60,BLACK);
  Tft.drawString(buf,0,240,6,WHITE);
}
