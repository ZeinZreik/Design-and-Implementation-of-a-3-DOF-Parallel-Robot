#include "MyXL320.h"
#include <SoftwareSerial.h>

SoftwareSerial MSerial(2, 3);
XL320 robot;
int cnt = 0;
int en = 4;
int zero1 = 540;
int zero2 = 590;
int zero3 = 512;
int ratio = 1024/360*3;

void setup() {

  MSerial.begin(9600);
  Serial.begin(115200);

  pinMode(en, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  digitalWrite(en, 1);

  robot.begin(MSerial);
  delay(100);

  /* 0: 9600, 1: 57600, 2: 115200, 3: 1Mbps */
  //robot.sendPacket(254, XL_BAUD_RATE, 3);
  //robot.sendPacket(254, XL_ID, 3);
}

void loop() {
  digitalWrite(5,0);
  if (cnt < 5)
  {
    //LED(1, 0);
    //LED(2, 1);
    LED(254, 2);
    MovePos(1, zero1-35*ratio);
    MovePos(2, zero2-4*ratio);
    MovePos(3, zero3+4*ratio);
  }
  else
  {
    LED(1, 0);
    LED(2, 1);
    LED(3, 2);
    //MovePos(1, zero1+45*ratio);
    //MovePos(2, zero2+45*ratio);
    //MovePos(3, zero3+45*ratio);
  }
  cnt = (cnt + 1) % 10; 
  //Serial.println(GetPos(2));
  delay(100);
}

void LED(int id, int c)
{
  char rgb[] = "rgbypcwo";
  digitalWrite(en, 0);
  robot.LED(id, &rgb[c] );
  delay(20);
  digitalWrite(en, 1);
}

void MovePos(int id, int pos)
{
  digitalWrite(en, 0);
  robot.moveJoint(id, pos);
  delay(1);
  digitalWrite(en, 1);
}

int GetPos(int id)
{
  /*digitalWrite(en, 0);
  robot.getJointPosition1(id);
  delay(20);
  digitalWrite(en, 1);
  int x;
  robot.getJointPosition2(id, x);
  delay(20);
  return x;*/
  //int x = robot.getJointPosition(id);
  int x = robot.getJointTemperature(id);
  return x;
}


