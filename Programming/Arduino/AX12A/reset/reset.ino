
byte servoID_1 = 0xFE;

void setup() {
  // put your setup code here, to run once:
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);

  Serial.begin(1000000);

  digitalWrite(7, 1); // put MAX485 into transmitting mode
  digitalWrite(8, 0);
  delay(1);
  Serial.write(0xFF); // Start bytes
  Serial.write(0xFF);
  Serial.write(0xFE); // Servo ID
  Serial.write(0x02); // Length of message (2 + 3 parameters)
  Serial.write(0x06); // Write
  Serial.write(0xF9); // notCheckSum
  Serial.flush(); // for good measure
  digitalWrite(7, 0); // put MAX485 into transmitting mode
  digitalWrite(8, 1);
}

void loop() {
  // put your main code here, to run repeatedly:

}
