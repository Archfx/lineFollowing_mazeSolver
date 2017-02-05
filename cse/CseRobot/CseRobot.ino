#include <EEPROM.h>
#include <Servo.h>


Servo leftservo;
Servo rightservo;
int ms;
int ls;
int rs;
int lms;
int rms;
char path[600];
int i=0;
int n;
int t1=226;//turn time left90
int t2=230;//turn time right90
int t3=465;//turn time 180
int t=0;//number of junctions
boolean endfound=false;

void setup() {
  Serial.begin(9600);
  maprun();


}

void loop() {

}

void testrun(){
  beep();
  }

void shortestpath(){//pixxu algorythm
  while(n=0,n<i){}
  }

void left(){
if (ls<500 && lms<500 && ms<500 && rms<500 && rs<500 ){
  path[i]='E';
  i++;
  finalbeep();
  turn180();
  }
if(ls>500){
  if (ls>500 && lms>500 && ms>500 && rms<500  && rs<500 ){
    path[i]='L';
    i++;
    beep();
    left90();
    t++;
  }
  else{
    leftservo.attach(8);
    rightservo.attach(7);
    leftservo.write(70);
    rightservo.write(70);
  }
}
else if(lms>500){
  if (ls>500 && lms>500 && ms>500 && rms<500  && rs<500 ){
  path[i]='L';
  i++;
  beep();
  left90();
  t++;
  }
  else{
    leftservo.attach(8);
    rightservo.attach(7);
    leftservo.write(65);
    rightservo.write(70);
  }
}
else if(ms>500){
      leftservo.attach(8);
      rightservo.attach(7);
      leftservo.write(75);//180
      rightservo.write(70);//0

}
else if(rs>500){
  if (rs>500 && rms>500 && ms>500 && ls<500 && lms<500 ){
    path[i]='R';
    i++;
    beep();
    right90();
    t++;
  }
  else{
    leftservo.attach(8);
    rightservo.attach(7);
    leftservo.write(75);
    rightservo.write(73);
  }
}
else if(rms>500){
    if (rs>500 && rms>500 && ms>500 && ls<500 && lms<500 ){
      path[i]='R';
      i++;
      beep();
      right90();
      t++;
    }
  else{
    leftservo.attach(8);
    rightservo.attach(7);
    leftservo.write(75);
    rightservo.write(78);
     }
}
else if(rs>500 && rms>500 && ms>500 && ls>500 && lms>500){
//  callchatta():
  }
else{
  leftservo.write(100);
  rightservo.write(100);
}


  }
  
void left90(){
    leftservo.attach(8);
    rightservo.attach(7);
    leftservo.write(75);
    rightservo.write(70);
  delay(600);
  leftservo.write(65);
  rightservo.write(70);
  delay(300);
  leftservo.detach();
  rightservo.detach();
  while(true){
  
  ms = analogRead(A2);
  rms = analogRead(A0);
  rs = analogRead(A1);
  ls = analogRead(A6);
  lms = analogRead(A7);
  leftservo.attach(8);
  rightservo.attach(7);
  leftservo.write(65);
  rightservo.write(70);
  if(rs<500 && rms<500 && ms>500 && ls<500 && lms<500){break;}


  }
  }
void right90(){
   leftservo.attach(8);
   rightservo.attach(7);
   leftservo.write(75);
   rightservo.write(70);
  delay(600);
  leftservo.write(75);
  rightservo.write(78);
  delay(300);
  leftservo.detach();
  rightservo.detach();

  while(true){
  ms = analogRead(A2);
  rms = analogRead(A0);
  rs = analogRead(A1);
  ls = analogRead(A6);
  lms = analogRead(A7);
  leftservo.attach(8);
  rightservo.attach(7);
  leftservo.write(75);
  rightservo.write(78);
  if(rs<500 && rms<500 && ms>500 && ls<500 && lms<500){break;}


  }
  }

void turn180(){
  while(true){
  ms = analogRead(A2);
  rms = analogRead(A0);
  rs = analogRead(A1);
  ls = analogRead(A6);
  lms = analogRead(A7);
  leftservo.attach(8);
  rightservo.attach(7);
  leftservo.write(75);
  rightservo.write(78
  );
  if(rs<500 && rms<500 && ms>500 && ls<500 && lms<500){break;}


  }
  }

void beep(){
  //pinMode(12,OUTPUT);
 leftservo.detach();
 rightservo.detach();
  tone(12,660,100);
//  delay(60);
//  tone(12,660,100);
//  delay(100);
//  tone(12,660,100);
//  delay(100);
//  tone(12,510,100);
//  delay(50);
  //tone(12,660,100);
 // delay(1000);


}
void finalbeep(){
  pinMode(12,OUTPUT);
 leftservo.detach();
 rightservo.detach();
 tone(12,660,100);
//  delay(600);
//  tone(12,510,100);
//  delay(100);
//  tone(12,660,100);
//  delay(600);
//  tone(12,770,100);
//  delay(600);
//  tone(12,380,100);
//  delay(575);


  }
void maprun(){
  while(!endfound){
      ms = analogRead(A2);
      rms = analogRead(A0);
      rs = analogRead(A1);
      ls = analogRead(A6);
      lms = analogRead(A7);
      left();
      Serial.println();
      for(int j=0;j<i+1;j++){
              Serial.print(path[j]);
              Serial.print(path[j]+" ");
                              }
      Serial.println();
  
  }
  }
