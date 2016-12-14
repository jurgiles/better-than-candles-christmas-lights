#include <FastLED.h>
#define NUM_LEDS 50
#define NUM_LEAD_DOTS 5
#define DATA_PIN 6

CRGB leds[NUM_LEDS];

void setup() { 
  LEDS.addLeds<NEOPIXEL,DATA_PIN>(leds, NUM_LEDS);
  randomSeed(analogRead(0));
}

void loop() 
{
  sparkle_leds();
  
  FastLED.show();

  delay(10);
}

void sparkle_leds(){
  for(int dot = 0; dot < NUM_LEDS; ++dot)
  {
    if(random(0,2)){
      leds[dot].fadeToBlackBy(16);
    } 
    
    if(!random(0,100)){
      leds[dot] = CRGB(random(0,256), random(0,256), random(0,256));
    } 
  }
}
