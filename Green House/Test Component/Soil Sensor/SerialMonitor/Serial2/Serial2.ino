int sensor_pin = 18; 
int output_value ;

void setup() {
  Serial.begin(115200);
  Serial.println("Reading From the Sensor ...");
  delay(2000);
  }

void loop() {

  output_value= analogRead(sensor_pin);
  output_value = map(output_value,0,1023,0,100);
  Serial.print("Mositure : ");
  Serial.println(output_value);
  Serial.println("%");
  delay(1000);
  }
