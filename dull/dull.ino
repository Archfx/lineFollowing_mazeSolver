#include <Servo.h>
Servo leftservo;
Servo rightservo;
int ms;
int ls;
int rs;
int lms;
int rms;

void setup() {
  // put your setup code here, to run once:
pinMode(12,OUTPUT);
delay(3000);
  analogWrite(12,255);
  delay(500);
  analogWrite(12,0);
}

void loop() {
  // put your main code here, to run repeatedly:
ms = analogRead(A2);
rms = analogRead(A0);
rs = analogRead(A1);
ls = analogRead(A6);
lms = analogRead(A7);

if(ms>500){
  leftservo.attach(8);
  rightservo.attach(7);
  leftservo.write(180);
  rightservo.write(0);
}else if(rs>500){
  leftservo.attach(8);
  rightservo.attach(7);
  leftservo.write(180);
  rightservo.write(75);
}else if(rms>500){
  leftservo.attach(8);
  rightservo.attach(7);
  leftservo.write(180);
  rightservo.write(90);
}else if(ls>500){
  leftservo.attach(8);
  rightservo.attach(7);
  leftservo.write(70);
  rightservo.write(0);
}else if(lms>500){
  leftservo.attach(8);
  rightservo.attach(7);
  leftservo.write(25);
  rightservo.write(0);
}else{
  leftservo.write(180);
  rightservo.write(180);

}

 // leftservo.detach();
 // rightservo.detach();
delay(10);

}
