/*Arduino UnoでのKXSC7-2050加速度センサーのスケッチ*/
const int R_X_PIN = A0;
const int R_Y_PIN = A1;
const int R_Z_PIN = A2;
const int L_X_PIN = A3;
const int L_Y_PIN = A4;
const int L_Z_PIN = A5;
int InByte;

/* 加速度センサの値の構造体 */
struct Coordinate {long cx;long cy;long cz;};
/* 角度の構造体 */
struct Angle {int ax;int ay;int az;};

void setup() {
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(9,OUTPUT);
  Serial.begin(9600) ;
}
void loop() {
  if(Serial.available()>0){
    InByte=Serial.read();
  }
  switch (InByte){
    case 101:
      digitalWrite(13,HIGH);
      //Serial.println("121_13_HIGH");
      break;
    case 1:
      digitalWrite(13,LOW);
      //Serial.println("121_13_LOW");
      break;
    case 103:
      digitalWrite(12,HIGH);
      //Serial.println("123_12_HIGH");
      break;
    case 3:
      digitalWrite(12,LOW);
      //Serial.println("123_12_LOW");
      break;
    case 106:
      digitalWrite(11,HIGH);
      //Serial.println("126_11_HIGH");
      break;
    case 6:
      digitalWrite(11,LOW);
      //Serial.println("126_11_LOW");
      break;
    case 109:
      digitalWrite(10,HIGH);
     // Serial.println("129_10_HIGH");
      break;
    case 9:
      digitalWrite(10,LOW);
     // Serial.println("129_10_LOW");
      break;
    case 112:
      digitalWrite(9,HIGH);
      //Serial.println("132_9_HIGH");
      break;
    case 12:
      digitalWrite(9,LOW);
      //Serial.println("32_9_LOW");
      break;
    case 121:
      digitalWrite(13,HIGH);
      //Serial.println("121_13_HIGH");
      break;
    case 21:
      digitalWrite(13,LOW);
      //Serial.println("121_13_LOW");
      break;
    case 123:
      digitalWrite(12,HIGH);
      //Serial.println("123_12_HIGH");
      break;
    case 23:
      digitalWrite(12,LOW);
      //Serial.println("123_12_LOW");
      break;
    case 126:
      digitalWrite(11,HIGH);
      //Serial.println("126_11_HIGH");
      break;
    case 26:
      digitalWrite(11,LOW);
     //Serial.println("126_11_LOW");
      break;
    case 129:
      digitalWrite(10,HIGH);
      //Serial.println("129_10_HIGH");
      break;
    case 29:
      digitalWrite(10,LOW);
      //Serial.println("129_10_LOW");
      break;
    case 132:
      digitalWrite(9,HIGH);
      //Serial.println("132_9_HIGH");
      break;
    case 32:
      digitalWrite(9,LOW);
      //Serial.println("32_9_LOW");
      break;
    case 444:
      digitalWrite(13,HIGH);
      //Serial.println("TEST_HIGH");
      break;
    case 555:
      digitalWrite(13,LOW);
      //Serial.println("TEST_LOW");
      break;
    case 222:
      digitalWrite(13,LOW);
      digitalWrite(12,LOW);
      digitalWrite(11,LOW);
      digitalWrite(10,LOW);
      digitalWrite(9,LOW);
     // Serial.println("ALL_LOW");
      break;
  }
  
  Coordinate Rc = RgetCoordinate();
  Coordinate Lc = LgetCoordinate();
  //showCoordinate(Rc); //最大値・最小値を記録
  //showCoordinate(Lc); //最大値・最小値を記録
  Angle R = RangleCalculation(Rc);
  Angle L = LangleCalculation(Lc);
  //RshowAngle(R);
  LshowAngle(L);
  delay(50) ;
}

/*加速度センサーの値を取得する関数*/
Coordinate RgetCoordinate() {
  Coordinate Rc;
  long Rx = 0, Ry = 0, Rz = 0;
  // 各データを100回読込んで平均化する
  for (int i = 0; i < 100; i++) {
    Rx = Rx + analogRead(R_X_PIN);  // Ｘ軸を読込む
    Ry = Ry + analogRead(R_Y_PIN);  // Ｙ軸を読込む
    Rz = Rz + analogRead(R_Z_PIN);  // Ｚ軸を読込む
  }
  Rc.cx = Rx / 100;
  Rc.cy = Ry / 100;
  Rc.cz = Rz / 100;
  return Rc;
}
Coordinate LgetCoordinate() {
  Coordinate Lc;
  long Lx = 0, Ly = 0, Lz = 0;
  // 各データを100回読込んで平均化する
  for (int i = 0; i < 100; i++) {
    Lx = Lx + analogRead(L_X_PIN);  // Ｘ軸を読込む
    Ly = Ly + analogRead(L_Y_PIN);  // Ｙ軸を読込む
    Lz = Lz + analogRead(L_Z_PIN);  // Ｚ軸を読込む
  }
  Lc.cx = Lx / 100;
  Lc.cy = Ly / 100;
  Lc.cz = Lz / 100;
  return Lc;
}

/*センサの値から各座標の角度を計算する関数*/
Angle RangleCalculation(Coordinate c){
  // 以下のx,y,zの最大値最小値は各自で測定してください
  int MAX_X = 414, MAX_Y = 409, MAX_Z = 414;
  int MIN_X = 275, MIN_Y = 271, MIN_Z = 275;

  // 各座標の1度あたりの角度を計算
  float oneAngleX = (MAX_X - MIN_X) / 180.000;
  float oneAngleY = (MAX_Y - MIN_Y) / 180.000;
  float oneAngleZ = (MAX_Z - MIN_Z) / 180.000;

  // 各座標の角度を計算
  Angle a;
  a.ax = (c.cx - MIN_X) / oneAngleX - 90;
  a.ay = (c.cy - MIN_Y) / oneAngleY - 90;
  a.az = (c.cz - MIN_Z) / oneAngleZ - 90;
  return a;
}
Angle LangleCalculation(Coordinate c){
  // 以下のx,y,zの最大値最小値は各自で測定してください
  int MAX_X = 413, MAX_Y = 410, MAX_Z = 416;
  int MIN_X = 273, MIN_Y = 273, MIN_Z = 276;

  // 各座標の1度あたりの角度を計算
  float oneAngleX = (MAX_X - MIN_X) / 180.000;
  float oneAngleY = (MAX_Y - MIN_Y) / 180.000;
  float oneAngleZ = (MAX_Z - MIN_Z) / 180.000;

  // 各座標の角度を計算
  Angle a;
  a.ax = (c.cx - MIN_X) / oneAngleX - 90;
  a.ay = (c.cy - MIN_Y) / oneAngleY - 90;
  a.az = (c.cz - MIN_Z) / oneAngleZ - 90;
  return a;
}

/**
 * 角度を表示する関数
 */
void RshowAngle(Angle a) {
  Serial.print("1");
  Serial.print(",");  
  Serial.print(a.ax);
  Serial.print(",");
  Serial.print(a.ay);
  Serial.print(",");
  Serial.println(a.az);
}
void LshowAngle(Angle a) {
  Serial.print("2");
  Serial.print(",");  
  Serial.print(a.ax);
  Serial.print(",");
  Serial.print(a.ay);
  Serial.print(",");
  Serial.println(a.az);
}

/**
 * 加速度センサーの値を表示する関数
 */
void showCoordinate(Coordinate c) {
  Serial.print("x:");
  Serial.print(c.cx);
  Serial.print(" y:");
  Serial.print(c.cy);
  Serial.print(" z:");
  Serial.println(c.cz);
}
