int sensorPin = 0; //analog pin 0
int min_value = 100, max_value = 0; 
float abs_max = 0, current = 0;
void setup(){
  Serial.begin(115200);
}

void loop(){
  int val = analogRead(sensorPin);
  Serial.print("Actual value: ");
  Serial.print(val);
  Serial.print("    \t MaxReading: ");
  Serial.print(max_value);
  Serial.print("\t MinReading: ");
  Serial.print(min_value);
  abs_max = max_value - min_value;
  current = val - min_value;
  Serial.print("\t SignalStrength: ");
  Serial.println(100.0 * (current/abs_max));

  delay(10);
  if(val> max_value)
    max_value = val;
  if(val< min_value)
    min_value = val;
}
