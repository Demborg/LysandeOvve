#include <Adafruit_NeoPixel.h>

#define LEDPIN     11
#define BUTTONPIN 4
#define N_LEDS 156

Adafruit_NeoPixel strip = Adafruit_NeoPixel(N_LEDS, LEDPIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  pinMode(BUTTONPIN, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  clearStrand();
  strip.show();
  while(digitalRead(BUTTONPIN)){
    delay(100);
  }
  delay(100); //debounce
  
  flashLight();
  while(!digitalRead(BUTTONPIN)){
    delay(100);
  }
  delay(100); //debounce
  
  while(digitalRead(BUTTONPIN)){
    sparkle();
  }
  delay(100); //debounce
  
  flashLight();
  while(!digitalRead(BUTTONPIN)){
    delay(100);
  }
  delay(100); //debounce
  
}


static void clearStrand() {
  for(int i = 0;i <= N_LEDS;i++){
    strip.setPixelColor(i,0);
  }
}

static void sparkle(){
  clearStrand();
  for(int i = 1;i <= 5;i++){
    strip.setPixelColor(random(N_LEDS), strip.Color(random(256),random(256),random(256)));
  }
  strip.show();
  delay(10);
}

static void flashLight(){
  clearStrand();
  //strip.setPixelColor(37,255,255,255);
  strip.setPixelColor(38,255,255,255);
  strip.setPixelColor(39,255,255,255);
  //strip.setPixelColor(40,255,255,255);
  
  //strip.setPixelColor(115,255,255,255);
  strip.setPixelColor(116,255,255,255);
  strip.setPixelColor(117,255,255,255);
  //strip.setPixelColor(118,255,255,255);
  strip.show();
}
