#include <FastLED.h>

#define NUM_LEDS 50
#define DATA_PIN 6
int delayLights = 1000;

CRGB leds[NUM_LEDS];

void setup() { 
  Serial.begin(9600);
  randomSeed(analogRead(0));
  LEDS.addLeds<WS2812B,DATA_PIN, RGB>(leds, NUM_LEDS);
  christmas_baby();
  FastLED.show();
 }

void loop() 
{
//  int dot = random(0, NUM_LEDS);
//  Serial.print("|dot:"); 
//  Serial.print(dot);
  move();
  FastLED.show();
  delay(2000);
}

void christmas_baby() {
  CRGB red = CRGB(255,0,0);
  CRGB green = CRGB(55,139,41);
  CRGB white = CRGB::White;
  
  for (int dot = 0; dot < NUM_LEDS; ++dot){
    if (dot % 2 == 0) {
      leds[dot] = red;
    }
    else {
      leds[dot] = green;
    }
  }
}

void move() {
  for (int dot = 0; dot < NUM_LEDS; ++dot){
    if (dot == (NUM_LEDS-1)) {
      leds[dot] = leds[dot-2];
    }
    else {
      leds[dot] = leds[dot+1];
    }
  }
}
