#include "DHT.h"

#define DHT1PIN 4
#define DHT2PIN 16
#define DHT3PIN 17
#define DHT4PIN 5

#define DHT1TYPE DHT11
#define DHT2TYPE DHT11
#define DHT3TYPE DHT11
#define DHT4TYPE DHT11


DHT dht1(DHT1PIN, DHT1TYPE); // constructeur pour déclarer notre capteur
DHT dht2(DHT2PIN, DHT2TYPE);
DHT dht3(DHT3PIN, DHT3TYPE);
DHT dht4(DHT4PIN, DHT4TYPE);

void setup() {
  Serial.begin(115200);
  dht1.begin();
  dht2.begin();
  dht3.begin();
  dht4.begin();
}

void loop() 
{ 
  delay(1000);
  
  // Le DHT11 renvoie au maximum une mesure toute les 1s
  float t1 = dht1.readTemperature();
  float t2 = dht2.readTemperature();
  float t3 = dht3.readTemperature();
  float t4 = dht4.readTemperature();
  //Lis la température en degré celsius

  if ( isnan(t1)||isnan(t2)||isnan(t3)||isnan(t4))
  {
    Serial.println("Echec reception");
    return;
    //Renvoie une erreur si l'ESP32 ne reçoit aucune mesure
  }
  float  T =(t1+t2+t3+t4)/4 ;
  Serial.print("  Temperature: ");
  Serial.print(T);
  Serial.print("°C, ");
  Serial.println("");

  // Transmet les mesures reçues dans le moniteur série
}
