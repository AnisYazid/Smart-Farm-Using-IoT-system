#define BLYNK_TEMPLATE_ID "TMPL2Myi4FZ_J" // choose yout Template ID from your own App 
#define BLYNK_TEMPLATE_NAME "AGRO HOUSE" // select the name of Your Template 
#define BLYNK_AUTH_TOKEN "lY25We_hf2TFpQ7d2qVUgIQF0-43b5C8"

#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#include <DHT.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

// Replace with your network credentials
char ssid[] = "Nissou";
char pass[] = "Nissou09022004";

// Replace with your Blynk authentication token
char auth[] = "lY25We_hf2TFpQ7d2qVUgIQF0-43b5C8";

#define DHTPIN1 12      // Pin connected to the DHT sensor
#define DHTPIN2 13      // Pin connected to the DHT sensor

#define DHTTYPE DHT11  //DHT sensor type

DHT dht1(DHTPIN1, DHTTYPE);
DHT dht2(DHTPIN2, DHTTYPE); 

const int numSoilSensors = 7;
int soilPins[numSoilSensors] = { 4, 19, 15, 34, 32, 26, 14};
int soilReadings[numSoilSensors];
int soilAverage = 0;

#define RELAY_AIR   33           // Pin connected to the relay control
#define RELAY_FLOW  25          // Pin connected to the relay control
#define RELAY_POMPE 27            // Pin connected to the relay control

void setup() 
{
// Initialize serial communication
  Serial.begin(115200);

    // Connect to Wi-Fi
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("connecting...");
  }
  Serial.println("Connectedddd");

    // Initialize Blynk
  Blynk.begin(auth, WiFi.SSID().c_str(), WiFi.psk().c_str());

  // Initialize DHT sensor
  dht1.begin();
  dht2.begin();

  // Initialize relay pin
  pinMode(RELAY_AIR, OUTPUT);
  digitalWrite(RELAY_AIR, LOW);

  pinMode(RELAY_FLOW, OUTPUT);
  digitalWrite(RELAY_FLOW, LOW);  

  pinMode(RELAY_POMPE, OUTPUT);
  digitalWrite(RELAY_POMPE, LOW);


  pinMode(19, OUTPUT);
  digitalWrite(19, HIGH);
  for (int i = 0; i < numSoilSensors; i++) 
  {
    pinMode(soilPins[i], INPUT);
  }
}

void loop() 
{
  delay(500);


  for (int i = 0; i < numSoilSensors; i++) 
  {
    soilReadings[i] = analogRead(soilPins[i]);
    soilAverage += soilReadings[i];
  }

  soilAverage = soilAverage / numSoilSensors;
  moisture = ( 100 - ( (soilAverage/4095.00) * 100 ) );

  float t1 = dht1.readTemperature();
  float t2 = dht2.readTemperature();
  float h1 = dht1.readHumidity();
  float h2 = dht2.readHumidity();
  

  float Temperature = (t1+t2)/2 ;
  float AirhHumidity = (h1+h2)/2 ;
  
  
   // Send sensor data to Blynk
  Blynk.virtualWrite(V0, soilAverage);
  Blynk.virtualWrite(V1, Temperature);
  Blynk.virtualWrite(V2,AirhHumidity );

  // Process of automation
  if (Temperature > 27)
  { 
    digitalWrite(RELAY_AIR,HIGH);
    digitalWrite(RELAY_FLOW,HIGH);

  }

  if ((soilAverage < 20) && (soilAverage > 70))
  {
    digitalWrite(RELAY_POMPE,HIGH);;
  }

}
