// 初期設定
#define SPEPN 13
#define OUTFREQ 1000

// ディレイ計算
#define DTIME 1/(OUTFREQ*2*0.000001)

//セットアップ
void setup(){
  pinMode(SPEPN, OUTPUT);
}

void loop(){
  digitalWrite(SPEPN,HIGH);
  delayMicroseconds(DTIME);
  digitalWrite(SPEPN,LOW);
  delayMicroseconds(DTIME);
}
