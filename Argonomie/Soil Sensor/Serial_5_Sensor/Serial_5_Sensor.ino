int sensor_pin1 = 14;
int sensor_pin2 = 36;
int sensor_pin3 = 23;
int sensor_pin4 = 8;
int sensor_pin5 = 1;

int value1,value2,value3,value4,value5 ;
int V ;

void setup()
{
  Serial.begin(9600);
  Serial.println("Reading");
  delay(2000);
}

void loop()
{

  value1= analogRead(sensor_pin1);
  value2= analogRead(sensor_pin2);
  value3= analogRead(sensor_pin3);
  value4= analogRead(sensor_pin4);
  value5= analogRead(sensor_pin5);

  V= value1+value2+value3+value4+value5 ;
  V = map(value,4095,0,0,100);
  
  Serial.print("Moisture : ");
  Serial.print(V);
  Serial.println("%");
  delay(1000);
}
