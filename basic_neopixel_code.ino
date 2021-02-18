
#include <Adafruit_NeoPixel.h>
#define PIN 2
#define NUMPIXEL 4

Adafruit_NeoPixel strip(NUMPIXEL, PIN);

void setup() {
  // put your setup code here, to run once:
  strip.begin();
  strip.setBrightness(20);
  
}

void loop() {
  colorWipe(strip.Color(255, 0, 0),50); // Red
  colorWipe(strip.Color(0, 255, 0), 50); // Green
  colorWipe(strip.Color(0, 0, 255), 50); // Blue
  
  


}

void colorWipe(uint32_t c, uint8_t wait){
  for(uint32_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(250);
  }  
}
