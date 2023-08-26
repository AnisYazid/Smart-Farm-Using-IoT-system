int sensor_pin = 14;
int value ;

void setup()
{
  Serial.begin(9600);
  Serial.println("Reading");
  delay(2000);
}

void loop()
{
xx
  value= analogRead(sensor_pin);
  value = map(value,4095,0,0,100);
  Serial.print("Moisture : ");
  Serial.print(value);
  Serial.println("%");
  delay(1000);
}
