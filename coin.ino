void setup() {
  // put your setup code here, to run once:
pinMode(A0,INPUT);
pinMode(A1,INPUT);
pinMode(A2,INPUT);
pinMode(A3,INPUT);
pinMode(A4,INPUT);
pinMode(6,OUTPUT);
pinMode(7,OUTPUT);
pinMode(8,OUTPUT);
pinMode(9,OUTPUT);
pinMode(10,OUTPUT);
pinMode(11,OUTPUT);
pinMode(12,OUTPUT);
Serial.begin(9600);
digitalWrite(10,LOW);
digitalWrite(11,LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
int check= analogRead(A0);
int check2=analogRead(A3);
Serial.println(check);
if(check>=1000)
{
  digitalWrite(6,HIGH);
  digitalWrite(7,HIGH);
  Serial.println("entered check");
  check1();
  }
else if(check2>=1000)
{
  digitalWrite(6,HIGH);
  digitalWrite(7,HIGH);
  check1();
}
else
{}
}
void check1()
{
  delay(2000);
 int d1 = analogRead(A1);
 int d2 = analogRead(A2);
  if(d1>=700)
  {
    Serial.println("panipuri is pressed"); 
    digitalWrite(8,HIGH);
    digitalWrite(7,LOW);
    digitalWrite(6,LOW);
    digitalWrite(9,LOW);
    digitalWrite(11,HIGH);
    delay(500);
    digitalWrite(11,LOW);
    delay(9000);
    digitalWrite(8,LOW);
    }
else if(d2>=700)
  {
      Serial.println("dahipuri is pressed");
    digitalWrite(8,LOW);
    digitalWrite(7,LOW);
    digitalWrite(6,LOW);
    digitalWrite(9,HIGH);
    digitalWrite(10,HIGH);
    delay(500);
    digitalWrite(10,LOW);
    delay(9000);
    digitalWrite(9,LOW);
    }
    delay(10000);
}
