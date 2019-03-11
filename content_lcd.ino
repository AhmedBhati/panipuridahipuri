/*
  *
  * Project Name:   pani_puri dahi_puri vending machine.
  * Author List:    Pranjali Bhopte, Anuja Indore
  * Filename:     content_lcd
  * Functions:    setup(),loop(),
  * Global Variables:ragda,chatni,pani,dahi,duration,duration1,duration2,duration3,duration4,distance1,distance2,distance3,distance4,distance,containers_volume, volume_in_pipe
  *                 no_of_puris1_can_make,no_of_puris2_can_make,no_of_puris3_can_make,no_of_puris4_can_make, volume_in_pipe1,volume_in_pipe2,volume_in_pipe3,volume_in_pipe4
  *
  */
#include<LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);  // sets the interfacing pins for the lcd to display the content
LiquidCrystal lcd1(22, 24, 25, 26, 27, 28); //sets the interfacing pins for the lcd to display the prediction
const int trigPin1 = 30; // ultrasonic for ragda
const int echoPin1 = 31;
const int trigPin2 = 32; // ultrasonic for chatni
const int echoPin2 = 33;
const int trigPin3 = 34; // ultrasonic for pani
const int echoPin3 = 35;
const int trigPin4 = 36; // ultrasonic for dahi
const int echoPin4 = 37;
long int  ragda,chatni,pani,dahi,duration,duration1,duration2,duration3,duration4;
int distance1,distance2,distance3,distance4,distance;
int containers_volume, volume_in_pipe1,volume_in_pipe2,volume_in_pipe3,volume_in_pipe4;
int no_of_puris1_can_make=50,no_of_puris2_can_make=50,no_of_puris3_can_make=50,no_of_puris4_can_make=50;
void setup()
{
  Serial.begin(9600);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  digitalWrite(6,LOW); // grounding to attach another lcd on the same mega
  digitalWrite(7,LOW); // grounding to attach another lcd on the same mega
  pinMode(23,OUTPUT);
  digitalWrite(23,LOW);
  pinMode(8,OUTPUT);
  digitalWrite(8,LOW);
 lcd.begin(16, 2);
 lcd1.begin(16, 2); 
 // initializes the 16x2 LCD
 pinMode(trigPin1, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin1, INPUT); // Sets the echoPin as an Input
pinMode(trigPin2, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin2, INPUT); // Sets the echoPin as an Input
pinMode(trigPin3, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin3, INPUT); // Sets the echoPin as an Input
pinMode(trigPin4, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin4, INPUT); // Sets the echoPin as an Input
}
/*
  *
  * Function Name:  loop()
  * Output:    return value is void
  * Logic:    ultrasonic sensors are use to claculate the distance from which the volume is calculated of each tank seperately and then 
  * compared with each other, one having minimum volume is then divided with the maximum no of puris whcih is then displayed to the user
  * Example Call:   not called
  *
  */
void loop()
{
content(trigPin1, echoPin1);
ragda = distance;
content(trigPin2, echoPin2);
chatni = distance;
content(trigPin3, echoPin3);
pani = distance;
content(trigPin4,echoPin4);
dahi=distance;
Serial.print(ragda);
Serial.print(" - ");
Serial.print(chatni);
Serial.print(" - ");
Serial.println(pani);
Serial.print(" - ");
Serial.println(dahi);

lcd.setCursor(0,0);           //sets the cursor at row 0 column 0
  lcd.print("ragda");
  lcd.print(ragda);          //sets the cursor at row 1 column 2
  lcd.print("chatni");
  lcd.print(chatni);
  lcd.setCursor(0,1);   
  lcd.print("pani"); 
  lcd.print(pani);
  lcd.print("dahi");
  lcd.print(dahi);
  lcd1.print("predict");
    lcd1.setCursor(0,1);   
    int fdist1=18-distance1;         // the actual level of ingredient from the bottom of the container in cms
   int fdist2=18-distance2;
   int fdist3=18-distance3;
   int fdist4=18-distance4;
   int vol1=0.5*fdist1*22*38;      //current volume of each container      
   int vol2=0.5*fdist2*26*22;
   int vol3=0.5*fdist3*23*36;
   int vol4=0.5*fdist3*24*22;
  int smallest_volume[]={vol1,vol2,vol3,vol4};
  for(int i=0;i<=3;i++)
  {
    if(smallest_volume[i]>smallest_volume[i+1])
    {
      int a= smallest_volume[i];
      int b= smallest_volume[i+1];
     smallest_volume[i]=b;
     smallest_volume[i+1]=a;
    }
  }
  if(smallest_volume[0]==vol1)
  {
    int total_puris= (containers_volume+volume_in_pipe)/no_of_puris1_can_make;
  }
   if(smallest_volume[0]==vol2)
  {
        total_puris= (containers_volume+volume_in_pipe)/no_of_puris2_can_make;
  }
   if(smallest_volume[0]==vol3)
  {
        total_puris= (containers_volume+volume_in_pipe)/no_of_puris3_can_make;
  }
   if(smallest_volume[0]==vol4)
  {
        total_puris= (containers_volume+volume_in_pipe)/no_of_puris4_can_make;
  }
lcd1.print(total_puris);
     delay(4000);
  lcd.clear();
  lcd1.clear();
}
/*
  *
  * Function Name:  content()
  * Input:    trigpin,echopin
  * Output:   returns void
  * Logic:    will calulate the distance of the tank
  * Example Call:  content(trig,echo)
  *
  */
void content(int trigPin,int echoPin)
{
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = (duration/2) / 29.1;
}
