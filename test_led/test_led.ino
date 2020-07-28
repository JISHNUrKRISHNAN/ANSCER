#include <Adafruit_NeoPixel.h>
 
#define PIN1      8
#define PIN2      9
#define vcc       10
#define gnd      11
#define N_LEDS 30
 
Adafruit_NeoPixel strip1 = Adafruit_NeoPixel(N_LEDS, PIN1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip2 = Adafruit_NeoPixel(N_LEDS, PIN2, NEO_GRB + NEO_KHZ800);

 
void setup() {
  strip1.begin();
  strip2.begin();
  pinMode(vcc,OUTPUT);
  pinMode(gnd,INPUT);
  digitalWrite(vcc,HIGH);
  digitalWrite(gnd,LOW);
  
  
}
 
void loop() {
  chase(strip1.Color(255, 0, 0)); // Red
  //chase(strip.Color(0, 255, 0)); // Green
  
  //chase(strip.Color(0, 0, 255)); // Blue
}
 
static void chase(uint32_t c) {
  for(uint16_t i=0; i<strip1.numPixels()+4; i++) {
      strip1.setPixelColor(i  , c); // Draw new pixel
      strip2.setPixelColor(i  , c); // Draw new pixel
      
     // strip1.setPixelColor(i-4, 0); // Erase pixel a few steps back
      //strip2.setPixelColor(i  , c); // Draw new pixel
      
      strip1.show();
      strip2.show();
      
      //delay(100);
  }
}
