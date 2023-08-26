m1,m2,m3,m4,m5;
int moisture;
int sensor_analog1,sensor_analog2,sensor_analog3,sensor_analog4,sensor_analog5;
const int sensor_pin1 = A1;  /* Soil moisture sensor O/P pin */
const int sensor_pin2 = A2;
const int sensor_pin3 = A3;
const int sensor_pin4 = A4;
const int sensor_pin5 = A5;

void setup(void){
  Serial.begin(115200);     /* Set the baudrate to 115200*/
}

void loop(void){
  sensor_analog1 = analogRead(sensor_pin1);
  sensor_analog2 = analogRead(sensor_pin2);
  sensor_analog3 = analogRead(sensor_pin3);
  sensor_analog4 = analogRead(sensor_pin4);
  sensor_analog5 = analogRead(sensor_pin5);

  m1 = sensor_analog1;
  m2 = sensor_analog2;
  m3 = sensor_analog3;
  m4 = sensor_analog4;
  m5 = sensor_analog5;

  moisture = (m1,m2,m3,m4,m5)/5;


 // moisture = ( 100 - ( (sensor_analog/4095.00) * 100 ) );
 moisture = map(moisture,0,4095,0,100);
 
  Serial.print("Moisture = ");
  Serial.print(moisture);  /* Print Temperature on the serial window */
  Serial.println("%");
  delay(1000);              /* Wait for 1000mS */
}
