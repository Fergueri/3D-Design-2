
#include <Adafruit_NeoPixel.h>
#define PIN 2
#define NUMPIXELS 4
const int buttonPin1 = 5;
const int buttonPin2 = 6;
int buttonState1 = 0
int buttonState2 = 0
Adafruit_NeoPixel strip(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  // put your setup code here, to run once:
  strip.begin();
  strip.setBrightness(50);
  strip.show();
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
}

void loop() {
  buttonState = digitalRead(buttonPin);
  if(buttonState1 == 1){
    right();  
  }
 if(buttonState1 == 1){
    right();  
  }

}
void right() {
  colorWipe1(strip.Color(255, 0, 0),50); // Red
  colorWipe1(strip.Color(0, 255, 0), 50); // Green
  colorWipe1(strip.Color(0, 0, 255), 50); // Blue
    
}
void left() {
  colorWipe2(strip.Color(255, 0, 0),50); // Red
  colorWipe2(strip.Color(0, 255, 0), 50); // Green
  colorWipe2(strip.Color(0, 0, 255), 50); // Blue
    
}


void colorWipe2(uint32_t c, uint8_t wait){
  for(uint32_t i=4; i<=4; i--) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }  
}
void colorWipe1(uint32_t c, uint8_t wait){
  for(uint32_t i=0; i<strip.numPixels; i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }  
}
