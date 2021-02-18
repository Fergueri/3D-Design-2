
#include <Adafruit_NeoPixel.h>
#define PIN 2
#define NUMPIXELS 4

Adafruit_NeoPixel strip(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  // put your setup code here, to run once:
  strip.begin();
  strip.setBrightness(50);
  strip.show();
  
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(A0);
  if(sensorValue <= 512){
      right();
    } 
  else if(sensorValue > 512){
      left();
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
  for(uint32_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }  
}
