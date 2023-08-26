#define RELAY_PIN 17

void setup() 
{
  pinMode(RELAY_PIN, OUTPUT);
}

void loop() 
{
  digitalWrite(RELAY_PIN, HIGH);
  delay(10000);
  digitalWrite(RELAY_PIN, LOW);
  delay(1
  0000);
}
