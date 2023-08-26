#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include "DHT.h"

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).

char auth[] = "lY25We_hf2TFpQ7d2qVUgIQF0-43b5C8"; //Paste auth token you copied

// Your WiFi credentials.
// Set password to "" for open networks.

char ssid[] = "Nissou";        //Enter your wifi name
char pass[] = "Nissou2004";    // Enter wifi password

#define DHT1PIN 17             // What digital pin we're connected to select yours accordingly
#define DHT2PIN 16
#define DHT3PIN 5 
#define DHT4PIN 4

#define DHT1TYPE DHT11         // DHT 11
#define DHT2TYPE DHT11
#define DHT3TYPE DHT11
#define DHT4TYPE DHT11


DHT dht1(DHT1PIN, DHT1TYPE);
DHT dht2(DHT2PIN, DHT2TYPE);
DHT dht3(DHT3PIN, DHT3TYPE);
DHT dht4(DHT4PIN, DHT4TYPE);

BlynkTimer timer;

   float T ;

void sendSensor()
{

  float t1 = dht1.readTemperature();
  float t2 = dht2.readTemperature();
  float t3 = dht3.readTemperature();
  float t4 = dht4.readTemperature();

  if ( isnan(t1)||isnan(t2)||isnan(t3)||isnan(t4) ) 
  {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  T =(t1+t2+t3+t4)/4 ;

  Blynk.virtualWrite(V6, T); // select your virtual pins accordingly
}

void setup()
{
  
  // Debug console
  Serial.begin(115200);
   delay(1000);
  Blynk.begin(auth, ssid, pass);
  

  dht1.begin();
  dht2.begin();
  dht3.begin();
  dht4.begin();

  // Setup a function to be called every second
  timer.setInterval(1000L, sendSensor);
}

void loop()
{
  float T ;
  Blynk.run();
  timer.run();
  Serial.println(T);
}
