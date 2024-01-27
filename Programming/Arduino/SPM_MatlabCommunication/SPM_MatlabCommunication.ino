#include "MyXL320.h"
#include <SoftwareSerial.h>

SoftwareSerial MSerial(2, 3);
XL320 robot;
int cnt = 0;
int zerox = 512-50;
int zeroy = 512-10;
int zeroz = 512+50;
double ratio = 8.87;
double x = 0;
double y = 0;
double z = 0;
double Currx = 0;
double Curry = 0;
double Currz = 0;
int k=1;

void setup() {
  MSerial.begin(9600);
  Serial.begin(115200);
  robot.begin(MSerial);
  delay(100);
  robot.setJointSpeed(254, 128);
  MovePos(1, zerox + x * ratio);
  MovePos(2, zeroy + y * ratio);
  MovePos(3, zeroz + z * ratio);
  LED(1, 0);
  LED(2, 1);
  LED(3, 2);
  delay(100);
}

void loop() {
  if (Serial.available())
  {
    String in = Serial.readStringUntil('\n');
    Serial.println(in);
    x = getValue(in, ',', 0).toDouble();
    y = getValue(in, ',', 1).toDouble();
    z = getValue(in, ',', 2).toDouble();
    Serial.print(x);
    Serial.print(",");
    Serial.print(y);
    Serial.print(",");
    Serial.println(z);
    robot.setJointSpeed(1, max(abs((zerox + x * ratio)-Currx)*k,1));
    robot.setJointSpeed(2, max(abs((zeroy + y * ratio)-Curry)*k,1));
    robot.setJointSpeed(3, max(abs((zeroz + z * ratio)-Currz)*k,1));
    MovePos(1, zerox + x * ratio);
    MovePos(2, zeroy + y * ratio);
    MovePos(3, zeroz + z * ratio);
    Currx = zerox + x * ratio;
    Curry = zeroy + y * ratio;
    Currz = zeroz + z * ratio;

    delay(30);
  }
}

void LED(int id, int c)
{
  char rgb[] = "rgbypcwo";
  robot.LED(id, &rgb[c] );
  delay(1);
}

void MovePos(int id, int pos)
{
  robot.moveJoint(id, pos);
  //delay(1);
}

String getValue(String data, char separator, int index)
{
  int found = 0;
  int strIndex[] = {0, -1};
  int maxIndex = data.length() - 1;

  for (int i = 0; i <= maxIndex && found <= index; i++) {
    if (data.charAt(i) == separator || i == maxIndex) {
      found++;
      strIndex[0] = strIndex[1] + 1;
      strIndex[1] = (i == maxIndex) ? i + 1 : i;
    }
  }

  return found > index ? data.substring(strIndex[0], strIndex[1]) : "";
}


