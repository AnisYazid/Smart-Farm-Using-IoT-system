
#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "TMPL2Myi4FZ_J"
#define BLYNK_TEMPLATE_NAME "TEMPERATURE"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include "DHT.h"

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).

char auth[] = "lY25We_hf2TFpQ7d2qVUgIQF0-43b5C8";  //Paste auth token you copied

// Your WiFi credentials.
// Set password to "" for open networks.

char ssid[] = "Nissou";///Enter your wifi name
char pass[] = "Nissou2004";// Enter wifi password

#define DHTPIN 17         // What digital pin we're connected to select yours accordingly


#define DHTTYPE DHT11     // DHT 11


DHT dht(DHTPIN, DHTTYPE);

BlynkTimer timer;

void sendSensor()
{
  float t = dht.readTemperature(); // or dht.readTemperature(true) for Fahrenheit

  if ( isnan(t)) 
  {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  
  Blynk.virtualWrite(V6, t); // select your virtual pins accordingly
}

void setup()
{
  // Debug console
  Serial.begin(115200);
   delay(1000);
  Blynk.begin(auth, ssid, pass);
  

  dht.begin();

  // Setup a function to be called every second
  timer.setInterval(1000L, sendSensor);
}

void loop()
{
  Blynk.run();
  timer.run();
}
