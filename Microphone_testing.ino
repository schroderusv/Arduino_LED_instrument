

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

//The loop runs forever
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  
  if (sensorValue >= 300){ 
    Serial.println(sensorValue);} //printing the values from microphone
  }
