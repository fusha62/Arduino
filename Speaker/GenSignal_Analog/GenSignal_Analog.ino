// 初期設定
#define SPEPN 13
#define OUTFREQ 1000
#define ANAAMP 128

// ディレイ計算
#define DTIME 1/(OUTFREQ*2*0.000001)

//セットアップ
void setup(){
  pinMode(SPEPN, OUTPUT);
}

void loop(){
  analogWrite(SPEPN,ANAAMP);
  delayMicroseconds(DTIME);
  analogWrite(SPEPN,0);
  delayMicroseconds(DTIME);
}
