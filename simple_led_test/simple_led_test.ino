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
  strip1.setPixelColor(0  , 255,0,0);
   strip1.setPixelColor(1  , 255,0,0); 
   strip1.setPixelColor(2  , 255,0,0); 
   strip1.setPixelColor(3 , 255,0,0); 
   strip1.setPixelColor(4 , 255,0,0); 
   strip1.setPixelColor(5  , 255,0,0); 
   strip1.setPixelColor(6  , 255,0,0); 
   strip1.setPixelColor(7  , 255,0,0); 
   strip1.setPixelColor(8  , 255,0,0); 
   strip1.setPixelColor(9  , 255,0,0); 
   strip1.setPixelColor(10  , 255,0,0); 
   strip1.setPixelColor(11 , 255,0,0); 
   strip1.setPixelColor(12  , 255,0,0); 
   strip1.setPixelColor(13  , 255,0,0); 
   strip1.setPixelColor(14  , 255,0,0); 
   strip1.setPixelColor(15  , 255,0,0); 
   strip1.setPixelColor(16  , 255,0,0); 
      strip1.setPixelColor(17  , 255,0,0); 


    strip2.setPixelColor(0  , 255,0,0);
   strip2.setPixelColor(1  , 255,0,0); 
   strip2.setPixelColor(2  , 255,0,0); 
   strip2.setPixelColor(3 , 255,0,0); 
   strip2.setPixelColor(4 , 255,0,0); 
   strip2.setPixelColor(5  , 255,0,0); 
   strip2.setPixelColor(6  , 255,0,0); 
   strip2.setPixelColor(7  , 255,0,0); 
   strip2.setPixelColor(8  , 255,0,0); 
   strip2.setPixelColor(9  , 255,0,0); 
   strip2.setPixelColor(10  , 255,0,0); 
   strip2.setPixelColor(11 , 255,0,0); 
   strip2.setPixelColor(12  , 255,0,0); 
   strip2.setPixelColor(13  , 255,0,0); 
   strip2.setPixelColor(14  , 255,0,0); 
strip2.setPixelColor(15 , 255,0,0);
strip2.setPixelColor(16  , 255,0,0);
strip2.setPixelColor(17  , 255,0,0);
   strip1.show();
   strip2.show();
  
}
 
void loop() {
//   strip1.setPixelColor(0  , 255,0,0);
//   strip1.setPixelColor(1  , 255,0,0); 
//   strip1.setPixelColor(2  , 255,0,0); 
//   strip1.setPixelColor(3 , 255,0,0); 
//   strip1.setPixelColor(4 , 255,0,0); 
//   strip1.setPixelColor(5  , 255,0,0); 
//   strip1.setPixelColor(6  , 255,0,0); 
//   strip1.setPixelColor(7  , 255,0,0); 
//   strip1.setPixelColor(8  , 255,0,0); 
//   strip1.setPixelColor(9  , 255,0,0); 
//   strip1.setPixelColor(10  , 255,0,0); 
//   strip1.setPixelColor(11 , 255,0,0); 
//   strip1.setPixelColor(12  , 255,0,0); 
//   strip1.setPixelColor(13  , 255,0,0); 
//   strip1.setPixelColor(14  , 255,0,0); 
//
//    strip2.setPixelColor(0  , 255,0,0);
//   strip2.setPixelColor(1  , 255,0,0); 
//   strip2.setPixelColor(2  , 255,0,0); 
//   strip2.setPixelColor(3 , 255,0,0); 
//   strip2.setPixelColor(4 , 255,0,0); 
//   strip2.setPixelColor(5  , 255,0,0); 
//   strip2.setPixelColor(6  , 255,0,0); 
//   strip2.setPixelColor(7  , 255,0,0); 
//   strip2.setPixelColor(8  , 255,0,0); 
//   strip2.setPixelColor(9  , 255,0,0); 
//   strip2.setPixelColor(10  , 255,0,0); 
//   strip2.setPixelColor(11 , 255,0,0); 
//   strip2.setPixelColor(12  , 255,0,0); 
//   strip2.setPixelColor(13  , 255,0,0); 
//   strip2.setPixelColor(14  , 255,0,0); 
//
//   strip1.show();
//   strip2.show();
//   

  }
 
