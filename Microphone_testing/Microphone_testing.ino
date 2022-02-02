

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
 // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

//The loop runs forever
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  
  if (sensorValue >= 300){ //SensorValue has to be changed depending on the instrument
    Serial.println(sensorValue); //printing the values from microphone
    digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on when sensorvalue is >= 300
    delay(1);                           // Short delay, as it looks better
    digitalWrite(LED_BUILTIN, LOW);    // turn the LED off almost immediadly
    delay(1);                       // Delay
  }
  }
