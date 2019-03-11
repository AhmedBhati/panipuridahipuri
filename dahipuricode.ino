#include <Servo.h>


Servo myservo1,myservo2,myservo6,myservo7,myservo8,myservo9,myservo10,myservo11,myservo12,myservo3,myservo4,myservo5;
const int stepPin = 5; 
const int dirPin = 4; 
const int enPin = 8;
void setup() {
  // Sets the two pins as Outputs
  pinMode(stepPin,OUTPUT); 
  pinMode(34,OUTPUT);
  pinMode(35,OUTPUT);
  pinMode(36,OUTPUT);
  pinMode(37,OUTPUT);
  pinMode(38,OUTPUT);
  pinMode(39,OUTPUT);
  pinMode(dirPin,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(enPin,OUTPUT);
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
  digitalWrite(enPin,LOW); 
  digitalWrite(dirPin,LOW); 
  myservo1.attach(22);//ragda.....13
  myservo2.attach(23);//ragda........14
  myservo3.attach(24);//ragda........15
  myservo4.attach(25);
  myservo5.attach(26);
  myservo6.attach(27);
  myservo7.attach(28);
  myservo8.attach(29);
  myservo9.attach(30);
  myservo10.attach(31);
  myservo11.attach(32);
  myservo12.attach(33);
}

void loop()
{
  if(analogRead(A2)>=700)
  {
  puri_phod();
 delay(800);
// digitalWrite(34,LOW);
//  digitalWrite(35,HIGH);
//  delay(12000);
//  digitalWrite(34,HIGH);
//  digitalWrite(35,LOW);
//  delay(12000);
//  digitalWrite(34,LOW);
//  digitalWrite(35,LOW);
//  digitalWrite(44,HIGH);
//  digitalWrite(45,LOW);
//  delay(10000);
//  digitalWrite(44,LOW);
//  digitalWrite(45,LOW);
//  step_2_back();
//  delay(1000);
//  step_4_forward();
//  digitalWrite(dirPin,LOW);
//  digitalWrite(10,LOW);
//  digitalWrite(44,LOW);
//  digitalWrite(45,HIGH);
//  delay(10000);
//  digitalWrite(44,LOW);
//  digitalWrite(45,LOW);
//  delay(1000);
  //................................
  ragda();
  myservo1.write(170);
  myservo2.write(180);
  myservo3.write(0);
  delay(1500);
  myservo1.write(90);
  myservo2.write(100);
  myservo3.write(100);
  delay(4500);
  //.......................
  //..................
  mithi_chatni();
  myservo4.write(95);
  myservo5.write(135);
  myservo6.write(145);
  delay(3000);
  myservo4.write(50);
  myservo5.write(100);
  myservo6.write(110);
  delay(2000);
  //.....................
  tez_chatni();
  digitalWrite(36,HIGH);
  digitalWrite(37,LOW);
  digitalWrite(38,LOW);
  digitalWrite(39,HIGH);
  delay(4000);
  digitalWrite(36,LOW);
  digitalWrite(37,LOW);
  digitalWrite(38,LOW);
  digitalWrite(39,LOW);
 dahi();
 myservo10.write(105);
  myservo11.write(110);
  myservo12.write(135);
  delay(2000);
  myservo10.write(50);
  myservo11.write(75);
  myservo12.write(90);
   delay(3000);
  //.................
  serve();
  delay(10000);
  original_pos();
  delay(3000);
  }
}
void puri_phod()
{
  for(int i=0;i<=24;i++)
  {
  digitalWrite(stepPin,HIGH);
  delay(30);
  digitalWrite(stepPin,LOW);
  delay(30);
  }
}
void ragda()
{
   for(int i=0;i<=23;i++)
  {
  digitalWrite(stepPin,HIGH);
  delay(30);
  digitalWrite(stepPin,LOW);
  delay(30);
}
}
void mithi_chatni()
{
  for(int i=0;i<=24;i++)
  {
  digitalWrite(stepPin,HIGH);
  delay(30);
  digitalWrite(stepPin,LOW);
  delay(30);
  }
}
void tez_chatni()
{
  for(int i=0;i<=24;i++)
  {
    digitalWrite(stepPin,HIGH);
    delay(30);
    digitalWrite(stepPin,LOW);
    delay(30);
}
}
void dahi()
{
  for(int i=0; i<=51;i++)
  {
     digitalWrite(stepPin,HIGH);
    delay(30);
    digitalWrite(stepPin,LOW);
    delay(30);
  }
}
void serve()
{
   for(int i=0; i<=24;i++)
  {
     digitalWrite(stepPin,HIGH);
    delay(30);
    digitalWrite(stepPin,LOW);
    delay(30);
  }
}
void original_pos()
{
  for(int i=0; i<=24 ;i++)
  {
     digitalWrite(stepPin,HIGH);
    delay(30);
    digitalWrite(stepPin,LOW);
    delay(30);
  }
}
// void step_2_back()
//{
//  for(int i=0; i<=2 ;i++)
//  {
//     digitalWrite(stepPin,HIGH);
//    delay(30);
//    digitalWrite(stepPin,LOW);
//    delay(30);
//  }
//}
//void step_4_forward()
//{
//  for(int i=0; i<=2 ;i++)
//  {
//    digitalWrite(dirPin,HIGH);
//    digitalWrite(10,LOW);
//     digitalWrite(stepPin,HIGH);
//    delay(30);
//    digitalWrite(stepPin,LOW);
//    delay(30);
//  }
//}
