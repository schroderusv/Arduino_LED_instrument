#include <Adafruit_NeoPixel.h>
#include "FastLED.h"


//define NeoPixel Pin and Number of LEDs and brightness
#define PIN 5
#define BRIGHTNESS 20
#define NUM_LEDS 40


unsigned long previous_millis; //Millis needed for counting the time between the analog data samples
unsigned long current_millis;
int sensorValue; //Microphone's analog output values
int ranval; //Random value for getting the random colour value for the LED



//Spaghet color palette. Index will be calculated with random(0,11) and the random index decides the random colour for the RGB strip
CRGB color_array[] = {CRGB(255,0,128), CRGB(255,0,255), CRGB(128,0,255), CRGB(0,0,255), CRGB(0,125,255), CRGB(0,255,255), CRGB(0,255,128), CRGB(0,255,0), CRGB(128,255,0), CRGB(255,255,0), CRGB(255,0,0),CRGB(0,0,0)};


CRGB leds[NUM_LEDS];

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  FastLED.addLeds<NEOPIXEL, PIN>(leds, NUM_LEDS);  // GRB ordering is assumed

  pinMode(0, INPUT);
  // start the strip and blank it out
  FastLED.setBrightness(BRIGHTNESS);
  FastLED.clear();
  FastLED.show();
  randomSeed(analogRead(0));  //Set random number generator seed from analog pin 0
  previous_millis = millis();  //Millis start
  
}

//The analog pin reads value from microphone max9814. If the value from the mic is over the threshold (390) the led strip will activate a random colour from the palette defined earlier. 
//The objective is to change the colour whenever there is small gap between the sounds (with instrument: when a new note is played). Long sounds will result the led strip to present the same colour for the whole duration of the sound.


//The loop runs forever
void loop() {
  // read the input on analog pin 1:
  sensorValue = analogRead(A1);
  
  current_millis = millis();   
      
  if (sensorValue >= 390){ //SensorValue is the analog value from the microphone
    //Serial.println(sensorValue);
    
    if (current_millis - previous_millis < 70){ //The gap between the data samples that are over the threshold value is small == long sound, and colour value should not be changed
      
      fill_solid( leds, NUM_LEDS, color_array[ranval]); //random colour value for the strip
      
      }
      
    else { //current_millis - previous_millis >= 60. Meaning the gap is long and the sound has changed
      ranval = random(0,11); //deciding new colour value for the next sound
      }
      
    previous_millis = current_millis;          
  }
  else {  //sensorValue < 390

  FastLED.clear();            
    }
  FastLED.setBrightness(BRIGHTNESS);
  FastLED.show();
  
  }
  
