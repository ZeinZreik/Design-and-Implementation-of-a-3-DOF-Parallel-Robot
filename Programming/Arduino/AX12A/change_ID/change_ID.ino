byte servoID_1 = 0x09;
byte servoALL = 0xFE; // 0xFE is the broadcast ID...No status packets are returned from Dynamixels in broadcast mode!

void setup() {

  pinMode(7, OUTPUT);    // this pin controls the MAX485 enable
  pinMode(8, OUTPUT);
  Serial.begin(1000000);     // Start a serial stream for the serial monitor

  //Serial.begin(1000000);     // Start a serial stream for the Dynamixels

  Serial.flush();     // Flush the serial stream

  setID(servoID_1);     // Use this fuction to set the ID of a single Dynamixel to &amp;amp;amp;amp;amp;amp;amp;amp;amp;amp;quot;0x00&amp;amp;amp;amp;amp;amp;amp;amp;amp;amp;quot;. You can plug each of them in, 1 by 1, and give them all unique IDs...don't forget to load new code onto Arduino afterwards (before hooking up multiple servos), otherwise, it is easy to accidentally set all of them to the same ID.

}

void loop() {



}



void setID(byte newID) {

  byte notchecksum = ~lowByte(0xFE + 0x04 + 0x03 + 0x03 + newID); // broadcast ID + length + instruction (Write) + address of ID + newID
  Serial.println(notchecksum);
  digitalWrite(7, 1); // Notify max485 transciever to accept tx
  digitalWrite(8, 0);

  delay(1); // Allow this to take effect

  Serial.write(0xFF);     // 1.These 2 bytes are 'start message'

  Serial.write(0xFF);     // 2.These 2 bytes are 'start message'

  Serial.write(0xFE);     // 3.ID is 0xFE, which broadcast mode (all Servos hear this message)

  Serial.write(0x04);     // 4.Length of string (number of parameters + 2)

  Serial.write(0x03);     // 5.Ping read write or syncwrite 0x01,2,3,83

  Serial.write(0x03);     // 6.Start address for data to be written (ADDRESS OF ID) (parameter 1)

  Serial.write(newID);     // 7.Turning on signal (parameter 2)

  Serial.write(notchecksum);     //8. the notchecksum

  Serial.flush();

  digitalWrite(7, 0);     // Notify MAX485 transciever to recieve
  digitalWrite(8, 1);

  delay(1);

}
