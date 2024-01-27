#include "MyXL320.h"
#include <SoftwareSerial.h>

SoftwareSerial MSerial(2, 3);
XL robot;

char rgb[] = "rgbypcwo";
void setup() {
  MSerial.begin(9600);
  Serial.begin(115200);

  robot.begin(MSerial);
  delay(100);

}

void loop() {
  robot.LED(1, &rgb[1] );
  delay(10);
  robot.LED(2, &rgb[2] );
  delay(10);
  robot.LED(3, &rgb[3] );
  delay(10);
}
