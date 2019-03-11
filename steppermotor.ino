#include <Servo.h>
Servo myservo1,myservo2,myservo3,myservo4,myservo5,myservo15; 
const int stepPin = 5; 
const int dirPin = 2; 
const int enPin = 8;
int k=75,m=26,o=0;
void setup() {
  
  
  // Sets the two pins as Outputs
  pinMode(stepPin,OUTPUT); 
  pinMode(dirPin,OUTPUT);
   pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(enPin,OUTPUT);
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
  digitalWrite(enPin,LOW); 
  analogWrite(dirPin,HIGH ); 
 Serial.begin(9600);
 myservo1.attach(22);//ragda
  myservo2.attach(23);//ragda
  myservo15.attach(43);//ragda
  myservo3.attach(24);//paani
  myservo4.attach(25);//paani
  myservo5.attach(26);//paani
  
}
void loop() {
  //o++;
  puri_phod();
  delay(5000);
  //..................
  ragda();
  myservo15.write(170);
  myservo1.write(5);
  myservo2.write(150);
  delay(3000);
  myservo15.write(60);
  myservo1.write(100);
  myservo2.write(60);
  delay(2000);
  //.................
  mithi_chatni();
  delay(3000);
  tez_chatni();
  delay(3000);
  dahi();
  myservo3.write(5);
  myservo4.write(5);
  myservo5.write(75);
  delay(3000);
  myservo3.write(100);
  myservo4.write(100);
  myservo5.write(160);
  delay(2000);
  //................
  delay(5000);
  serve();
  delay(5000);

  starting_position();
  delay(5000);
}
void puri_phod()
{
  for(int i=0;i<=24;i++)
  {
  digitalWrite(stepPin,HIGH);
  delay(150);
  digitalWrite(stepPin,LOW);
  delay(150);
  }
}
void ragda()
{
   for(int i=0;i<=24;i++)
  {
  digitalWrite(stepPin,HIGH);
  delay(150);
  digitalWrite(stepPin,LOW);
  delay(150);
}
}
void mithi_chatni()
{
  for(int i=0;i<=24;i++)
  {
  digitalWrite(stepPin,HIGH);
  delay(150);
  digitalWrite(stepPin,LOW);
  delay(150);
  }
}
void tez_chatni()
{
  for(int i=0;i<=24;i++)
  {
    digitalWrite(stepPin,HIGH);
    delay(150);
    digitalWrite(stepPin,LOW);
    delay(150);
}
}
void dahi()
{
  for(int i=0; i<=49;i++)
  {
     digitalWrite(stepPin,HIGH);
    delay(150);
    digitalWrite(stepPin,LOW);
    delay(150);
  }
}
void serve()
{
   for(int i=0; i<=24;i++)
  {
     digitalWrite(stepPin,HIGH);
    delay(150);
    digitalWrite(stepPin,LOW);
    delay(150);
  }
}
void starting_position()
{
  for(int i=0; i<=24 ;i++)
  {
     digitalWrite(stepPin,HIGH);
    delay(150);
    digitalWrite(stepPin,LOW);
    delay(150);
  }
}
 
