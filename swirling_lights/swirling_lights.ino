#include <FastLED.h>
#define NUM_LEDS 100
#define NUM_LEAD_DOTS 5
#define DATA_PIN 6

CRGB leds[NUM_LEDS];
int lead_dots[NUM_LEAD_DOTS];

void setup() { 
  LEDS.addLeds<NEOPIXEL,DATA_PIN>(leds, NUM_LEDS);
  
  init_lead_dots();
}

void loop() 
{
  fade_leds();
  
  move_lead_dots();
  
  FastLED.show();

  delay(50);
}

void init_lead_dots(){
  for(int i = 0 ; i < NUM_LEAD_DOTS ; ++i){
    lead_dots[i] = i * (NUM_LEDS / NUM_LEAD_DOTS);
  }
}

void fade_leds(){
  for(int dot = 0; dot < NUM_LEDS; dot++)
  {
    leds[dot].fadeToBlackBy(16);
  }
}

void move_lead_dots(){
  for(int lead_dot = 0; lead_dot < NUM_LEAD_DOTS; ++lead_dot){
    color_led(lead_dots[lead_dot]);
    lead_dots[lead_dot] = (lead_dots[lead_dot] + 1) % NUM_LEDS;
  }
}

void color_led(int dotIndex){
  leds[dotIndex] = CRGB(random(0,150), random(0,150), random(0,150));
}


