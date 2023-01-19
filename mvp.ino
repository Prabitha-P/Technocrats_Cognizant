#define MQ2pin 13

float sensorValue; 
const int sensorMin = 0;     
const int sensorMax = 1024; 

void setup()   {
  Serial.begin(9600);   
}
void loop() {
  int sensorReading   = analogRead(A0);
  int range = map(sensorReading,   sensorMin, sensorMax, 0, 3);
  
 
  switch (range) {
   case 0:    
    Serial.println("** CLOSE FIRE **");
    break;
  case 1:   
    Serial.println("**   SMOKE DETECTED **");
    sensorValue = analogRead(A1);

    Serial.print("Sensor Value: ");
    Serial.println(sensorValue);
    break;
  case 2:    
    Serial.println("NO FIRE");
    break;
  }
  delay(500); 
}
