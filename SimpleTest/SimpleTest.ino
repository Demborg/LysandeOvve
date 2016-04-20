#include <Adafruit_NeoPixel.h>
 
#define PIN     11
#define N_LEDS 156
 
Adafruit_NeoPixel strip = Adafruit_NeoPixel(N_LEDS, PIN, NEO_GRB + NEO_KHZ800);
 
void setup() {
  strip.begin();
  
  //Test all the pixles
  chase(strip.Color(0, 0, 255));
  chase(strip.Color(0, 255, 0));
  chase(strip.Color(255, 0, 0));
}
 
void loop() {
  chase(strip.Color(random(256), random(256), random(256)));
}
 
static void chase(uint32_t c) {
  for(uint16_t i=0; i<strip.numPixels()+4; i++) {
      strip.setPixelColor(i  , c); // Draw new pixel
      strip.setPixelColor(i-4, 0); // Erase pixel a few steps back
      strip.show();
      delay(25);
  }
}
