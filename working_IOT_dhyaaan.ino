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
const int trigPin1 = D1;
const int echoPin1 = D2;
const int trigPin2= D3;
const int echoPin2= D5;
const int trigPin3= D6;
const int echoPin3= D7;
const int trigPin4 = D8;
const int echoPin4= 10;
long duration;
int distance;
int check1,check2,check3,check4;
int pred1,pred2,pred3,pred4;
void setup() {
  pinMode(trigPin1, OUTPUT); 
pinMode(echoPin1, INPUT); 
pinMode(trigPin2, OUTPUT); 
pinMode(echoPin2, INPUT); 
pinMode(trigPin3, OUTPUT); 
pinMode(echoPin3, INPUT); 
pinMode(trigPin4, OUTPUT); 
pinMode(echoPin4, INPUT); 
  Serial.begin(115200);
  client.setDebug(true); 
  client.wifiConnection(WIFINAME, WIFIPASS);
  client.begin(callback);
  }
  
void loop() {
  if(!client.connected()){
      client.reconnect();
      }
  cent(trigPin1,echoPin1);
  check1= distance;
  cent(trigPin2,echoPin2);
  check2=distance;
  cent(trigPin3,echoPin3);
  check3=distance;
  cent(trigPin4,echoPin4);
  check4=distance;
  Serial.print("distance1 is");
  Serial.println(check1);
  Serial.print("distance2 is");
  Serial.println(check2);
  Serial.print("distance3 is");
  Serial.println(check3);
  Serial.print("distance4 is");
  Serial.println(check4);
  check1=16-check1;
  check2=16-check2;
  check3=15-check3;
  check4=14-check4;
  pred1=check1*6.66*3;
  pred2=check2*3.33*3;
  pred3=check3*3.33*3;
  pred4=check4*2.083*2;
  client.add("dist", check1); 
  client.add("pred", pred1); 
  client.ubidotsPublish("ragda");
  client.add("dist", check2); 
  client.add("pred", pred2); 
  client.ubidotsPublish("chatni");
  client.add("dist", check3); 
  client.add("pred", pred3); 
  client.ubidotsPublish("pani");
  client.add("dist", check4); 
  client.add("pred", pred4); 
  client.ubidotsPublish("dahi");
  client.loop();
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
