
byte servoID_1 = 0xFE;

 

void setup(){

   pinMode(7,OUTPUT);
   pinMode(8,OUTPUT);


  Serial.begin(115200);

  Serial.flush();

}

 

void loop(){

//moveServo(servoID_1, 0); // Move to position 200

//delay(1000);

moveServo(servoID_1, 0); // Move to position 500

delay(1000);
//moveServo(servoID_1, 200); // Move to position 500
//
//delay(1000);
}

 

void moveServo(byte servoID, int Position){

  char Position_H = Position >> 8;  //same as /256 and truncating

  char Position_L = Position % 256;

  byte notchecksum = ~lowByte(servoID + 0x07 + 0x03 + 0x1E + Position_L + Position_H+ 0xc8 + 0x00);

  digitalWrite(7,1); // put MAX485 into transmitting mode
  digitalWrite(8,0);

  delay(1);
  Serial.write(0xFF); // Start bytes

  Serial.write(0xFF);

  Serial.write(servoID); // Servo ID

  Serial.write(0x07); // Length of message (2 + 3 parameters)

  Serial.write(0x03); // Write

  Serial.write(0x1E); // Parameter 1

  Serial.write(Position_L); // Parameter 2

  Serial.write(Position_H); // Parameter 3
  Serial.write(0xc8);//speed
  Serial.write(0x00);//speed
  Serial.write(notchecksum); // notCheckSum*/
  Serial.flush(); // for good measure
  
  digitalWrite(7,0); // put MAX485 back into receiving mode
  digitalWrite(8,1);

  delay(1);

}
