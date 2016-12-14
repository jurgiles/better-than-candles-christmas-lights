#include <FastLED.h>

#define NUM_LEDS 50
#define DATA_PIN 6

CRGB leds[NUM_LEDS];

void setup() { 
  randomSeed(analogRead(0));
  
  LEDS.addLeds<NEOPIXEL,DATA_PIN>(leds, NUM_LEDS);
  
  color_all_leds_randomly();
}

void loop() 
{
  int dot = random(0, NUM_LEDS);
  
  dim_dot(dot);
  
  brighten_dot(dot);
  
  delay(1000);
}

void dim_dot(int dot){
  while(leds[dot]){
    leds[dot].fadeToBlackBy(1);
    FastLED.show();
  }
}

void brighten_dot(int dot){
  CRGB target_color = random_color();
  
  while(leds[dot].r <= target_color.r || leds[dot].g <= target_color.g || leds[dot].b <= target_color.b){ 
    if(leds[dot].r <= target_color.r){ ++leds[dot].r;}
    if(leds[dot].g <= target_color.g){ ++leds[dot].g;}
    if(leds[dot].b <= target_color.b){ ++leds[dot].b;}
   
    FastLED.show();
    delay(30);
  }
}

void color_all_leds_randomly(){
  for(int dot = 0; dot < NUM_LEDS; ++dot){
    leds[dot] = random_color();
  }
}

CRGB random_color(){
  return CRGB(random(0,256), random(0,256), random(0,256));
}

