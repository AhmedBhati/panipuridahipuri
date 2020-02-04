/*
 * * Project Name:   pani-puri dahi-puri vending machine.
  * Author List:   Mohammed Ahmed eyantra-Team
  * Filename:     master_code
  * Functions:   setup(),loop(),puri_phod(),ragda(),tez_chatni(),serve_panipuri(),serve_dahipuri(),original_pos(),check(), panipuri(),dahipuri()
  * Global Variables: myservo1,myservo2,myservo6,myservo7,myservo8,myservo9,myservo10,myservo11,myservo12,myservo3,myservo4,myservo5,stepPin,dirPin,enPIN
  *     
  *     
 * The following code is actually divided into two parts while uploading i.e coin testing and implementation.
 *The coin testing part is done using arduino uno controller.
 *The implementation part is done using arduino mega controller. 
 *Seperate controllers were used only to serve a single purpose because the  amount of current could pose a danger to the controller. 
 *
 *
 *The following code consist of panipuri and dahipuri making as well as coin testing and accepting from the user.
  */

#include <Servo.h>
Servo myservo1,myservo2,myservo6,myservo7,myservo8,myservo9,myservo10,myservo11,myservo12,myservo3,myservo4,myservo5;
const int stepPin = 5; 
const int dirPin = 4; 
const int enPin = 8;

void setup() {
  pinMode(A0,INPUT);//input in for slot sensor present in the coin module
  pinMode(A1,INPUT);//Used to check whether button is pressed or not
  pinMode(A2,INPUT);//Used to chk whether button is pressed or not
//pinMode(6,OUTPUT);//mounted on arduino uno to display that IP is done.
//pinMode(7,OUTPUT);//mounted on arduino uno to display that IP is done.
//pinMode(8,OUTPUT);//mounted on arduino uno to display that button is pressed and data is recieved by the system.
//pinMode(9,OUTPUT);//mounted on arduino uno to display that button is pressed and data is recieved by the system.
//pinMode(10,OUTPUT);// mounted on arduino uno to indicate that button is pressed to send a high pulse
//pinMode(11,OUTPUT);//mounted on arduino uno to indicate that button is pressed to send a high pulse 
  pinMode(34,OUTPUT);//For dc motor for breaking of puris
  pinMode(35,OUTPUT);//For dc motor for breaking of puris
  pinMode(36,OUTPUT);//For dc motor for shev
  pinMode(37,OUTPUT);//For dc motor for shev
  pinMode(38,OUTPUT);//For dc motor for shev
  pinMode(39,OUTPUT);//For dc motor for shev
   pinMode(52,OUTPUT);//For dc motor for PICKING
  pinMode(53,OUTPUT);//For dc motor for PICKING
 pinMode(stepPin,OUTPUT); //clk pin of the stepper motor driver tb6560
  pinMode(dirPin,OUTPUT);  // cw pin of the stepper motor driver of tb6560
   pinMode(enPin,OUTPUT);  // enable pin of stepper motor driver
   pinMode(9,OUTPUT);  //cw(-) pin of the stepper motor driver of tb6560
  pinMode(11,OUTPUT);  //clk(-) pin of the stepper motor driver of tb6560
  pinMode(12,OUTPUT);  //en(-) pin of the stepper motor driver of tb6560
 digitalWrite(9,LOW);  // making the cw(-) low
  digitalWrite(11,LOW); //making the clk(-) low
  digitalWrite(12,LOW); //making the en(-) low
  digitalWrite(enPin,LOW); // enable pin is set to active low 
  analogWrite(dirPin,LOW); // moves in clockwise direction
  myservo1.attach(22);//ragda
  myservo2.attach(23);//ragda
  myservo3.attach(24);//ragda
  myservo4.attach(25);//chatni
  myservo5.attach(26);//chatni
  myservo6.attach(27);//chatni
  myservo7.attach(28);//paani
  myservo8.attach(29);//paani
  myservo9.attach(30);//paani
  myservo10.attach(31);//dahi
  myservo11.attach(32);//dahi
  myservo12.attach(33);//dahi
}
void loop() {
 if(analogRead(A0)>=700)// if a square wave is recieved at this pin it will run, make and serve dahipuri
 panipuri();
else if (analogRead(A2)>=700)//if a square wave is recieved at this pin it will run, make and serve dahipuri
dahipuri();
}

void panipuri()
{
 puri_phod(); // calling of the stepper motor function
delay(800);
digitalWrite(35,LOW); // breaking of puris, i.e action of conical cutter down.
  digitalWrite(34,HIGH);
  delay(11000);
  digitalWrite(35,HIGH); // this will bring the conical cutter up
  digitalWrite(34,LOW);
  delay(11000);
  digitalWrite(35,LOW); // this will bring the conical cutter up
  digitalWrite(34,LOW);
  //delay(1000);
  //................................
  //................................
  ragda();// calling of the stepper motor function
  delay(500);
 myservo1.write(170);
  myservo2.write(180);
  myservo3.write(0);
  delay(3500);
  myservo1.write(90);
  myservo2.write(90);
  myservo3.write(100);
  delay(4500);
  //.......................
  masala();
  delay(500);// calling of the stepper motor function
  myservo7.write(15);
  myservo8.write(0);
  myservo9.write(140);
  delay(1300);
  myservo7.write(105);
  myservo8.write(90);
  myservo9.write(50);
  delay(2000);
  //.................
  serve_panipuri();// calling of the stepper motor function
//  digitalWrite(52,HIGH);
//  digitalWrite(53,LOW);
//  delay(1000);
//  digitalWrite(52,LOW);
//  digitalWrite(53,LOW);
//  delay(10000);
//  digitalWrite(52,LOW);
//  digitalWrite(53,HIGH);
for(int z=0; z<=4; z++)
{
  digitalWrite(52,HIGH);
  digitalWrite(53,LOW);
  delay(1000);
  digitalWrite(52,LOW);
  digitalWrite(53,LOW);
  delay(1000);
}
delay(2000);
  //.........................
  original_pos();// calling of the stepper motor function
  delay(3000);
//  digitalWrite(52,LOW);
//  digitalWrite(53,LOW); 
}
void dahipuri()
{
 puri_phod();// calling of the stepper motor function
 delay(800);
 digitalWrite(35,LOW); // breaking of puris, i.e action of conical cutter down.
  digitalWrite(34,HIGH);
  delay(11000);
  digitalWrite(35,HIGH); // this will bring the conical cutter up
  digitalWrite(34,LOW);
  delay(10000);
  digitalWrite(35,LOW);
  digitalWrite(34,LOW);
  //................................
  ragda();// calling of the stepper motor function
  myservo1.write(170);
  myservo2.write(180);
  myservo3.write(0);
  delay(3000);
  myservo1.write(90);
  myservo2.write(90);
  myservo3.write(100);
  delay(3000);
  //.......................
  //..................
  mithi_chatni();// calling of the stepper motor function
  myservo4.write(0);
  myservo5.write(135);
  myservo6.write(145);
  delay(1500);
  myservo4.write(90);
  myservo5.write(90);
  myservo6.write(110);
  delay(2000);
  //.....................
  tez_chatni();// calling of the stepper motor function
  digitalWrite(36,HIGH);
  digitalWrite(37,LOW);
  digitalWrite(38,LOW);
  digitalWrite(39,HIGH);
  delay(4000);
  digitalWrite(36,LOW);
  digitalWrite(37,LOW);
  digitalWrite(38,LOW);
  digitalWrite(39,LOW);
 dahi();// calling of the stepper motor function
 myservo10.write(115);
  myservo11.write(120);
  myservo12.write(155);
  delay(2000);
  myservo10.write(50);
  myservo11.write(70);
  myservo12.write(90);
   delay(3000);
  //.................
  serve_dahipuri();// calling of the stepper motor function
//  digitalWrite(52,HIGH);
//  digitalWrite(53,LOW);
//  delay(4000);
//  digitalWrite(52,LOW);
//  digitalWrite(53,LOW);
//  delay(10000);
//  digitalWrite(52,LOW);
//  digitalWrite(53,HIGH);
//delay(10000);
for(int z=0; z<=4; z++)
{
  digitalWrite(52,HIGH);
  digitalWrite(53,LOW);
  delay(1000);
  digitalWrite(52,LOW);
  digitalWrite(53,LOW);
  delay(1000);
}
delay(2000);

  original_pos();// calling of the stepper motor function
  delay(3000);
//  digitalWrite(52,LOW);
//  digitalWrite(53,LOW); 
}
/*
  *
  * Function Name:  puri_phod()
  
  * Output:     return type is void
  * Logic:    this will move the stepper motor plate according to the value of i given.
  * Example Call:   puri_phod()
  *
  */
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
/*
  *
  * Function Name:  ragda()
  
  * Output:     return type is void
  * Logic:    this will move the stepper motor plate according to the value of i given.
  * Example Call:   ragda()
  *
  */
void ragda()
{
   for(int i=0;i<=24;i++)
  {
    
  digitalWrite(stepPin,HIGH);
  delay(30);
  digitalWrite(stepPin,LOW);
  delay(30);
}
}
/*
  *
  * Function Name:  masala()
  
  * Output:     return type is void
  * Logic:    this will move the stepper motor plate according to the value of i given.
  * Example Call:   masala()
  *
  */
void masala()
{
  for(int i=0; i<=75;i++)
  {
    digitalWrite(stepPin,HIGH);
    delay(30);
    digitalWrite(stepPin,LOW);
    delay(30);
  }
}
/*
  *
  * Function Name: serve_panipuri()
  
  * Output:     return type is void
  * Logic:    this will move the stepper motor plate according to the value of i given.
  * Example Call:   serve_panipuri()
  *
  */
void serve_panipuri()
{
   for(int i=0; i<=49;i++)
  {
     digitalWrite(stepPin,HIGH);
    delay(30);
    digitalWrite(stepPin,LOW);
    delay(30);
  }
}
/*
  *
  * Function Name:  original_pos()
  
  * Output:     return type is void
  * Logic:    this will move the stepper motor plate according to the value of i given.
  * Example Call:   original_pos()
  *
  */
void original_pos()
{
  for(int i=0; i<=23;i++)
  {
     digitalWrite(stepPin,HIGH);
    delay(30);
    digitalWrite(stepPin,LOW);
    delay(30);
  }
}
/*
  *
  * Function Name:  serve_dahipuri()
  
  * Output:     return type is void
  * Logic:    this will move the stepper motor plate according to the value of i given.
  * Example Call:   serve_dahipuri()
  *
  */
void serve_dahipuri()
{
   for(int i=0; i<=23;i++)
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
