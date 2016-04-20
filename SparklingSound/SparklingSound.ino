#include <Adafruit_NeoPixel.h>
#define BUFFERSIZE 20

Adafruit_NeoPixel strip = Adafruit_NeoPixel(8, 1, NEO_GRB + NEO_KHZ800);

int buffered_input[BUFFERSIZE];
int dc;

void setup() {
  // put your setup code here, to run once:
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  Serial.begin(9600);
  
  for(int i = BUFFERSIZE-1;i>=0;i--){
    buffered_input[i] = analogRead(0);
  }
  dc = bufferMean();
}

void loop() {
  // put your main code here, to run repeatedly:
  bufferAppend(analogRead(0));
  //printBuffer();
  Serial.println(bufferMean()-dc);
  delay(2);
}

static void bufferAppend(int element) {
  for(int i = BUFFERSIZE-1;i>0;i--){
    buffered_input[i] = buffered_input[i-1];
  }
  buffered_input[0] = element;
}

static int bufferMean(){
  int retVal = 0;
  for(int i = 0;i<BUFFERSIZE;i++){
    retVal += buffered_input[i]/BUFFERSIZE;
  }
  return retVal;
}

static void printBuffer(){
  for(int i = 0;i<BUFFERSIZE;i++){
    Serial.print(i);
    Serial.print(": ");
    Serial.print(buffered_input[i]);
    Serial.print(", ");
  }
  Serial.println("\n-----------------");
}
