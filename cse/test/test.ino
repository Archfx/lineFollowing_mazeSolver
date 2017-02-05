#include <EEPROM.h>
#include <Servo.h>

Servo leftservo;
Servo rightservo;
//r=73
//l=70

void setup() {
  Serial.begin(9600);

}

void loop() {
  if( Serial.available()){
  //char inChar = (char)Serial.read();
  int n = (int)Serial.read();
  Serial.println(n);

      leftservo.attach(8);
      rightservo.attach(7);
      leftservo.write(65);//180
      rightservo.write(78);//0
}
}
