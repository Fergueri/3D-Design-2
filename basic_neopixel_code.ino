
#include <Adafruit_NeoPixel.h>
#define PIN 2 //pin the neopixels are in
#define NUMPIXEL 4 // how many neopixels there are

Adafruit_NeoPixel strip(NUMPIXEL, PIN);

void setup() {
  // put your setup code here, to run once:
  strip.begin(); //starts the neopixels
  strip.setBrightness(20);
  
}

void loop() {//loops the colors
  colorWipe(strip.Color(255, 0, 0),50); // Red
  colorWipe(strip.Color(0, 255, 0), 50); // Green
  colorWipe(strip.Color(0, 0, 255), 50); // Blue
  
  


}

void colorWipe(uint32_t c, uint8_t wait){
  for(uint32_t i=0; i<strip.numPixels(); i++) { //loops the colorWipe
    strip.setPixelColor(i, c);//sets the colors. i is the pixel number and c is the rgb code
    strip.show(); //shows the neopixels
    delay(250);
  }  
}
