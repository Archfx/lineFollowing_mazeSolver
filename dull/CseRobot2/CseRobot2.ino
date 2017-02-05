#include <EEPROM.h>
#include <Servo.h>


Servo leftservo;
Servo rightservo;
int ms;
int ls;
int rs;
int lms;
int rms;
int path[300];
int i;
int n;
//define variables for directions
int L=-1;//left
int R=1;//right
int S=0;//start
int E=99;//end
int t1=216;//turn time left90
int t2=210;//turn time right90
int t3=430;//turn time 180
int t;
void setup() {
  Serial.begin(9600);

//beep();
//left();
////testrun();
//finalbeep();
}

void loop() {
  ms = analogRead(A2);
  rms = analogRead(A0);
  rs = analogRead(A1);
  ls = analogRead(A6);
  lms = analogRead(A7);
  left();
}

void testrun(){
  beep();
  EEPROM.write(0,1);
  
        left();
        if (ms>500 && lms>500 && ls>500 && rs<500 && rms<500){//left turn
            //left90();
            EEPROM.write(i,L);
            beep();
            i++;
            }
        if (ms>500 && rms>500 && rs>500 && lms<500 && ls<500){//right turn
            //right90();
            EEPROM.write(i,R);
            beep();
            i++;
            }
        if (ms>500 && rms>500 && rs>500 && lms>500 && ls>500){//yeah,i found the end
            //turn180();
            EEPROM.write(i,E);
            beep();
            i++;
            }
        if (ms<500 && rms<500 && rs<500 && lms<500 && ls<500){//idiot this is a dead end turn around
            //turn180();
            EEPROM.write(i,E);
            beep();
            i++;
            }
        
  }

void shortestpath(){//pixxu algorythm
  while(n=0,n<i){}
  }

void left(){
t=millis();

if (ls>500 && lms>500 && ms>500 && rms<500  && rs<500 ){
 // Serial.println(t);
  beep();
  left90();
  t=0;
  }
else if (rs>500 && rms>500 && ms>500 && ls<500 && lms<500 ){
//  Serial.println(t);
//  Serial.print("2");
  beep();
  right90();
  t=0;
  }
if (ls<500 && lms<500 && ms<500 && rms<500 && rs<500 ){
 // Serial.println(t);
  finalbeep();
  turn180();
//
//  t=0;
  }
if(ls>500){
  leftservo.attach(8);
  rightservo.attach(7);
  leftservo.write(70);
  rightservo.write(0);
//  delay(10);
//  leftservo.detach();
//  rightservo.detach();
}else if(lms>500){
  leftservo.attach(8);
  rightservo.attach(7);
  leftservo.write(25);
  rightservo.write(0);
//  delay(10);
//  leftservo.detach();
//  rightservo.detach();
}
else if(ms>500){
  leftservo.attach(8);
  rightservo.attach(7);
  leftservo.write(180);
  rightservo.write(0);
//  delay(10);
//  leftservo.detach();
//  rightservo.detach();
}else if(rs>500){
  leftservo.attach(8);
  rightservo.attach(7);
  leftservo.write(180);
  rightservo.write(75);
//  delay(10);
//  leftservo.detach();
//  rightservo.detach();
}else if(rms>500){
  leftservo.attach(8);
  rightservo.attach(7);
  leftservo.write(180);
  rightservo.write(90);
//  delay(10);
//  leftservo.detach();
//  rightservo.detach();
}else{
  leftservo.write(180);
  rightservo.write(180);
//  delay(10);
//  leftservo.detach();
//  rightservo.detach();
}


  }
//void right(){
//ms = analogRead(A2);
//rms = analogRead(A0);
//rs = analogRead(A1);
//ls = analogRead(A6);
//lms = analogRead(A7);
//if(rs>500){
//  leftservo.attach(8);
//  rightservo.attach(7);
//  leftservo.write(180);
//  rightservo.write(75);
//}else if(rms>500){
//  leftservo.attach(8);
//  rightservo.attach(7);
//  leftservo.write(180);
//  rightservo.write(90);
//}else if(ms>500){
//  leftservo.attach(8);
//  rightservo.attach(7);
//  leftservo.write(180);
//  rightservo.write(0);
//}else if(ls>500){
//  leftservo.attach(8);
//  rightservo.attach(7);
//  leftservo.write(70);
//  rightservo.write(0);
//}else if(lms>500){
//  leftservo.attach(8);
//  rightservo.attach(7);
//  leftservo.write(25);
//  rightservo.write(0);
//}else{
//  leftservo.write(180);
//  rightservo.write(180);
//
//} 
//}
void forward(){
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
}
void left90(){
  leftservo.attach(8);
  rightservo.attach(7);
  leftservo.write(180);
  rightservo.write(0);
  delay(100);
  leftservo.write(0);
  rightservo.write(0);
  
  delay(t1);
  leftservo.detach();
  rightservo.detach();
  }
void right90(){
  leftservo.attach(8);
  rightservo.attach(7);
  leftservo.write(180);
  rightservo.write(0);
  delay(100);
  leftservo.write(180);
  rightservo.write(180);
  
  delay(t2);
  leftservo.detach();
  rightservo.detach();
  }

void turn180(){
  leftservo.attach(8);
  rightservo.attach(7);
  leftservo.write(180);
  rightservo.write(180);
  delay(t3);
  leftservo.detach();
  rightservo.detach();
  }

void beep(){
  pinMode(12,OUTPUT);
 leftservo.detach();
 rightservo.detach();
//  tone(12,660,100);
//  delay(60);
//  tone(12,660,100);
//  delay(120);
//  tone(12,660,100);
//  delay(120);
//  tone(12,510,100);
//  delay(50);
  tone(12,660,100);
  delay(120);


}
void finalbeep(){
  pinMode(12,OUTPUT);
 leftservo.detach();
 rightservo.detach();
  tone(12,660,100);
  delay(300);
//  tone(12,510,100);
//  delay(100);
//  tone(12,660,100);
//  delay(300);
//  tone(12,770,100);
//  delay(550);
//  tone(12,380,100);
//  delay(575);


  }
