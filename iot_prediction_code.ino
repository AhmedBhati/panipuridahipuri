#include <PubSubClient.h>

#include <BearSSLHelpers.h>
#include <CertStoreBearSSL.h>
#include <ESP8266WiFi.h>
#include <ESP8266WiFiAP.h>
#include <ESP8266WiFiGeneric.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266WiFiScan.h>
#include <ESP8266WiFiSTA.h>
#include <ESP8266WiFiType.h>
#include <WiFiClient.h>
#include <WiFiClientSecure.h>
#include <WiFiClientSecureAxTLS.h>
#include <WiFiClientSecureBearSSL.h>
#include <WiFiServer.h>
#include <WiFiServerSecure.h>
#include <WiFiServerSecureAxTLS.h>
#include <WiFiServerSecureBearSSL.h>
#include <WiFiUdp.h>
#include "UbidotsESPMQTT.h"
#define TOKEN "A1E-LSaomTmmMhGdhvKXdboMMn4NNkF0Rc" // Your Ubidots TOKEN
#define WIFINAME "redmi" //Your SSID
#define WIFIPASS "mohammed456" // Your Wifi Pass
Ubidots client(TOKEN);
void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i=0;i<length;i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();
}
int containers_volume, volume_in_pipe;
int no_of_puris1_can_make,no_of_puris2_can_make,no_of_puris3_can_make,no_of_puris4_can_make;
int const echo1=D1;
int const trig1=D2;
int const echo2=D5;
int const trig2=D6;
int const echo3=D7;
int const trig3=D8;
int echo4=10; 
int const trig4=14;
int dist1,dist2,dist3,dist4;     //distance between the ultrasonic and the level of content
int vol1,vol2,vol3,vol4;                   //volume of ingredient in each tank
int fdist1,fdist2,fdist3,fdist4;             //the actual level of each ingredient in each tank
long duration1,duration2,duration3,duration4,Cm;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  client.setDebug(true); // Pass a true or false bool value to activate debug messages
  client.wifiConnection(WIFINAME, WIFIPASS);
  client.begin(callback);
   pinMode(trig1,OUTPUT);
   pinMode(trig2, OUTPUT);
   pinMode(trig3,OUTPUT);
   pinMode(trig4,OUTPUT);
   pinMode(echo1, INPUT);
   pinMode(echo2, INPUT);
   pinMode(echo3,INPUT);
   pinMode(echo4,INPUT);
  }
void loop() {
  if(!client.connected())
  {
      client.reconnect();
      }
   digitalWrite(trig1, LOW);
   digitalWrite(trig2, LOW);
   digitalWrite(trig3, LOW);
   digitalWrite(trig4, LOW);
   delayMicroseconds(2); 
   digitalWrite(trig1, HIGH);
   digitalWrite(trig2, HIGH);
   digitalWrite(trig3, HIGH);
   digitalWrite(trig4, HIGH);
   delayMicroseconds(10);
   digitalWrite(trig1, LOW);
   digitalWrite(trig2, LOW);
   digitalWrite(trig3, LOW);
   digitalWrite(trig4, LOW);
   duration1 = pulseIn(echo1, HIGH);
   duration2 = pulseIn(echo2, HIGH);
   duration3=  pulseIn(echo3,HIGH);
   duration4=  pulseIn(echo4,HIGH);
   int distance1= duration1*0.034/2;   //distance between ultrasonic and the level of ingredient in cms
   int distance2= duration2*0.034/2;
   int distance3= duration3*0.034/2;
   int distance4= duration4*0.034/2;
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
   client.add("fdist1",fdist1); 
  client.ubidotsPublish("tank1-level"); 
  client.add("fdist4",fdist4);
  client.ubidotsPublish("tank4-level");
  client.add("vol1",vol1);
  client.ubidotsPublish("tank1-vol");
  client.add("vol2",vol2);
  client.ubidotsPublish("tank2-vol");
  client.add("vol3",vol3);
  client.ubidotsPublish("tank3-vol");
  client.add("vol4",vol4);
  client.ubidotsPublish("tank4-vol"); 
  client.add("fdist2",fdist2);
  client.ubidotsPublish("tank2-level");
  client.add("fdist3",fdist3);
  client.ubidotsPublish("tank3-level");
  client.add("totalpuris",total_puris);
  client.ubidotsPublish("Total_Puris");
  client.loop();
  }
