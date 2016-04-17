#include <Adafruit_NeoPixel.h>

#define PIN     11
#define N_LEDS 156
#define PIXLES_TO_RUN 5

Adafruit_NeoPixel strip = Adafruit_NeoPixel(N_LEDS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
}

void loop() {
  //generate colors for PIXLES_TO_RUN num pixles
  
  clearStrand();
  for(int i = 1;i <= PIXLES_TO_RUN;i++){
    strip.setPixelColor(random(N_LEDS), strip.Color(random(256),random(256),random(256)));
  }
  strip.show();
  delay(10);
}
    
static void clearStrand() {
  for(int i = 0;i <= N_LEDS;i++){
    strip.setPixelColor(i,0);
  }
}
