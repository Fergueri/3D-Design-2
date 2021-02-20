
#include <Adafruit_NeoPixel.h>
#define PIN 2 //what pin the neopixel is in
#define NUMPIXELS 4 // how many neopixels there are

Adafruit_NeoPixel strip(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  // put your setup code here, to run once:
  strip.begin();//starts the neopixels
  strip.setBrightness(50);// sets the brightness of the neopixel
  strip.show();
  
  Serial.begin(9600);
}

void loop() {// reads the serial numbner of the potentiometer at anytime to adjust
  int sensorValue = analogRead(A0);
  if(sensorValue <= 512){//if the serial is below or equal to 512 the colorWipe goes right
      right();
    } 
  else if(sensorValue > 512){//else the color wipe goes right
      left();
    }
}
  void right() { //initalizes the colorWipes and sets their colors
    colorWipe1(strip.Color(255, 0, 0),50); // Red
    colorWipe1(strip.Color(0, 255, 0), 50); // Green
    colorWipe1(strip.Color(0, 0, 255), 50); // Blue
      
  }
  void left() {
   colorWipe2(strip.Color(255, 0, 0),50); // Red
   colorWipe2(strip.Color(0, 255, 0), 50); // Green
   colorWipe2(strip.Color(0, 0, 255), 50); // Blue
      
  }


void colorWipe2(uint32_t c, uint8_t wait){ //loop for the color wipe the goes right
  for(uint32_t i=4; i<=4; i--) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }  
}
void colorWipe1(uint32_t c, uint8_t wait){//loop for the color wipe the goes left
  for(uint32_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }  
}
