#include<Wire.h>
#define echoPin 3
#define trigPin 2
long duration;
int distance;
const int buzzer=8;
const int light=13;
const int light2=12;
void setup()
{
pinMode(trigPin,OUTPUT);
pinMode(echoPin,INPUT);
Serial.begin(9600);
pinMode(buzzer,OUTPUT);
pinMode(light,OUTPUT);
Serial.println("DistanceMeasureProgram");
}
void loop()
{
digitalWrite(trigPin,LOW);
delayMicroseconds(2);
digitalWrite(trigPin,HIGH);
delayMicroseconds(10);
digitalWrite(trigPin,LOW);
duration=pulseIn(echoPin,HIGH);
distance=duration*0.034/2;
Serial.print("Distance:");
Serial.print(distance);
Serial.println("cm");
digitalWrite(light,LOW);
digitalWrite(light2,LOW);
if(distance<=10)
{
Serial.println("VeryClose");
digitalWrite(light,HIGH);
tone(buzzer,1000);//Send1KHzsoundsignal...
delay(1000); //...for1sec
digitalWrite(light2,LOW);
tone(buzzer,500);
noTone(buzzer); //Stopsound...
}
else if(distance>=11&&distance<=50)
{
Serial.println("NearRange");
digitalWrite(light2,HIGH);
digitalWrite(light,LOW);
delay(1000);
}
else
{
Serial.println("FarRange");
}}
