#include<Wire.h>
#include"DHT.h"
#define DHTPIN 2 
#define DHTTYPE DHT11 
DHT dht(DHTPIN,DHTTYPE);
const int buzzer=8;
const int light=7;
const int light1=6;
const int light2=5;
void setup()
{
Serial.begin(9600);
pinMode(buzzer,OUTPUT);
pinMode(light,OUTPUT);
pinMode(light1,OUTPUT);
pinMode(light2,OUTPUT);
Serial.println("AnnamalaiUniversityBECSE2021");
Serial.println("Tempearture&HumidityReadingProgram");
Serial.println(F("DHT11test!"));
dht.begin();
}
void loop()
{
digitalWrite(light,LOW);
delay(2000);
float h=dht.readHumidity();
float t=dht.readTemperature();
float f=dht.readTemperature(true);
if(isnan(h)||isnan(t)||isnan(f))
{
Serial.println(F("FailedtoreadfromDHTsensor!"));digitalWrite(light,HIGH);
return;
}
float hif=dht.computeHeatIndex(f,h);
float hic=dht.computeHeatIndex(t,h,false);
Serial.print(F("Humidity:"));
Serial.print(h);
Serial.print(F("%Temperature:"));
Serial.print(t);
Serial.print(F("C"));
Serial.print(f);
Serial.print(F("FHeatindex:"));
Serial.print(hic);
Serial.print(F("C"));
Serial.print(hif);
Serial.println(F("F"));
if(t>29)
{tone(buzzer,1000);//Send1KHzsoundsignal...delay(1000);
digitalWrite(light1,HIGH);
digitalWrite(light2,LOW);
tone(buzzer,500);
noTone(buzzer); 
Serial.println("Alert:HIGHTemperture");}else{
Serial.println("Alert:LowTemperture");digitalWrite(light2,HIGH);
}
delay(2000);
digitalWrite(light1,LOW);
}
