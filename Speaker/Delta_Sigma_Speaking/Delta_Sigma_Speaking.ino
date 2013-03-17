#include <stdlib.h>

// Initial Define
#define SPEPN 13
#define INFS 44100

// Calcurate delay time
#define DTIME 1/(INFS*0.000001)

// Initalization
int inbuf=0;
char binbuf[8];
int i;

// Arduino setup
void setup(){
  pinMode(SPEPN, OUTPUT);
  Serial.begin(57600);
}

void loop(){
  if (Serial.available()>0)
  {
    inbuf = Serial.read();
    itoa(inbuf,binbuf,2);
  }
  for (i=1;i<8;i++){
    if (binbuf[i]=='0'){
      digitalWrite(SPEPN,LOW);
      delayMicroseconds(DTIME);
    }
    else{
      digitalWrite(SPEPN,HIGH);
      delayMicroseconds(DTIME);
    }
  }
}
