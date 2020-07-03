const int trigPin1 = D1;
const int echoPin1 = D2;
const int trigPin2= D3;
const int echoPin2= D5;
const int trigPin3= D6;
const int echoPin3= D7;
const int trigPin4 = D8;
const int echoPin4= 10;
// defines variables
long duration;
int distance;
int check1,check2,check3,check4;

void setup() {
pinMode(trigPin1, OUTPUT); 
pinMode(echoPin1, INPUT); 
pinMode(trigPin2, OUTPUT); 
pinMode(echoPin2, INPUT); 
pinMode(trigPin3, OUTPUT); 
pinMode(echoPin3, INPUT); 
pinMode(trigPin4, OUTPUT); 
pinMode(echoPin4, INPUT); 
Serial.begin(9600); 
}
void loop()
{
 cent(trig1,echo1);
check1=distance;
cent(trig2,echo2);
check2=distance;
cent(trig3,echo3);
check3=distance;
cent(trig4,echo4);
check4=distance;
Serial.print("distance1 is");
Serial.println(check1);
Serial.print("distance2 is");
Serial.println(check2);
Serial.print("distance3 is");
Serial.println(check3);
Serial.print("distance4 is");
Serial.println(check4);
}
}
void cent(int trigPin, int echoPin)
{
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance= duration*0.034/2;
}
