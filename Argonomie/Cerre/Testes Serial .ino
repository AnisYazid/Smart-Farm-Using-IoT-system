#include <WiFiClient.h>
#include "DHT.h"

// Your WiFi credentials.
// Set password to "" for open networks.

char ssid[] = "Nissou";        //Enter your wifi name
char pass[] = "Nissou2004";    // Enter wifi password

#define DHT1PIN 17             // What digital pin we're connected to select yours accordingly
#define DHT2PIN 16
#define DHT3PIN 5 


#define DHTTYPE DHT11         // DHT 11


DHT dht1(DHT1PIN, DHTTYPE);
DHT dht2(DHT2PIN, DHTTYPE);
DHT dht3(DHT3PIN, DHTTYPE);


// Soil moisture define pin 

#define sensor_pin1  &&           
#define sensor_pin2  &&
#define sensor_pin3  &&
#define sensor_pin4  &&
#define sensor_pin5  &&
#define sensor_pin6  &&            
#define sensor_pin7  &&
#define sensor_pin8  && 
#define sensor_pin9  &&

void sendSensor()
{

  float t1 = dht1.readTemperature();
  float t2 = dht2.readTemperature();
  float t3 = dht3.readTemperature();


  if ( isnan(t1)||isnan(t2)||isnan(t3) ) 
  {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
   float T =(t1+t2+t3)/3 ;
}

void setup()
{
  
  // Debug console
  Serial.begin(115200);
   delay(1000);
  Blynk.begin(auth, ssid, pass);

  int value1,value2,value3,value4,value5,value6,value7,value8,value9 ;
  int V ;
  
  dht1.begin();
  dht2.begin();
  dht3.begin();

}

void loop()
{

  value1= analogRead(sensor_pin1);
  value2= analogRead(sensor_pin2);
  value3= analogRead(sensor_pin3);
  value4= analogRead(sensor_pin4);
  value5= analogRead(sensor_pin5);
  value6= analogRead(sensor_pin6);
  value7= analogRead(sensor_pin7);
  value8= analogRead(sensor_pin8);
  value9= analogRead(sensor_pin9);

  
  

  V= value1+value2+value3+value4+value5+value6+value7+value8+value9 ;
  V = map(value,0,1023,0,100);
  
  Serial.print("Moisture : ");
  Serial.print(V);
  Serial.println("%");
  Serial.print("Temperature :");
  Serial.println(T)
  delay(500);
  
}