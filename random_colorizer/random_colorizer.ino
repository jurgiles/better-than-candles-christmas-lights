#include <FastLED.h>
#define NUM_LEDS 50
#define DATA_PIN 6
#define NUM_RANDOMS NUM_LEDS/3

CRGB leds[NUM_LEDS];

void setup() { 
  LEDS.addLeds<NEOPIXEL,DATA_PIN>(leds, NUM_LEDS);
  randomSeed(analogRead(0));

  for(int dot = 0; dot < NUM_LEDS; ++dot){
    leds[dot] = CRGB(random(0,256), random(0,256), random(0,256));
  }
}

void loop() 
{
  for(int i = 0; i < NUM_RANDOMS ; ++i){
    leds[random(0, NUM_LEDS)] = CRGB(random(0,256), random(0,256), random(0,256));
  }

  FastLED.show();

  delay(2500);
}
