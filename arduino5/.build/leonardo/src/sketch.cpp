#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
void setup();
void loop();
void startBleu();
void redLed(int numL,int rap, int decal, int decal2);
void fadeLed(int numL,int rap, int decal, int decal2);
void fadeLedB(int numL,int rap, int decal, int decal2);
void colorWipe(uint32_t c, uint8_t wait);
void rainbow(uint8_t wait);
void rainbowCycle(uint8_t wait);
void theaterChase(uint32_t c, uint8_t wait);
void theaterChaseRainbow(uint8_t wait);
uint32_t Wheel(byte WheelPos);
uint8_t readCapacitivePin(int pinToMeasure);
#line 1 "src/sketch.ino"
//#include <Adafruit_NeoPixel.h>
#define PIN 6
#define PIXEL 15

// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXEL, PIN, NEO_GRB + NEO_KHZ800);

// note durations: 4 = quarter note, 8 = eighth note, etc.:

int brightness = 0;    // how bright the LED is
int fadeAmount = 5;    // how many points to fade the LED by

int valueColor1 = 0;
int valueColor2 = 0;
int valueColor3 = 0;

int sensibility = 6;
// IMPORTANT: To reduce NeoPixel burnout risk, add 1000 uF capacitor across
// pixel power leads, add 300 - 500 Ohm resistor on first pixel's data input
// and minimize distance between Arduino and first pixel.  Avoid connecting
// on a live circuit...if you must, connect GND first.
boolean boolCap1 = false;
boolean boolCap2 = false;
boolean boolCap3 = false;


void setup() {  
  Serial.begin(9600);
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  startBleu();
}

void loop() {
    int capacitiv1 = readCapacitivePin(11);
    int capacitiv2 = readCapacitivePin(12);
    int capacitiv3 = readCapacitivePin(13);
    ////
    if(capacitiv1>sensibility){
      if(valueColor1<250){
         valueColor1++;    
      }
      if(boolCap1){
        Serial.print("A");
        boolCap1 = false;
      }
    }else if(valueColor1>0){
       boolCap1 = true;
       valueColor1--;    
    }
    if(capacitiv2>sensibility && valueColor2<250){
      if(capacitiv2<250){
         capacitiv2++;    
      }
      if(boolCap2){
        Serial.print("B");
        boolCap2 = false;
      }
    }else if(valueColor2>0){
       boolCap2 = true;
       valueColor2--;    
    }
    if(capacitiv3>sensibility && valueColor3<250){
      if(capacitiv3<250){
         capacitiv3++;    
      }
      if(boolCap3){
        Serial.print("C");
        boolCap3 = false;
      }
    }else if(valueColor3>0){
      boolCap3 = true;
       valueColor3--;    
    }
    
    if (Serial.available())
    {
      switch (Serial.read()){ 
         case 'A': 
           valueColor1=255;
         break;
         case 'B': 
           valueColor2=255;
         break;      
         case 'C': 
           valueColor3=255;
         break;      
      }
    }  
    for(int i=2; i<5; i++) {
      strip.setPixelColor(i, strip.Color(valueColor1, valueColor2, valueColor3));
      strip.setPixelColor(i+6, strip.Color(valueColor1, valueColor2, valueColor3));
      strip.show();
    }
}
void startBleu(){
  for(uint16_t i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, strip.Color(0, 0, 255));
      strip.show();
  }  
}
void redLed(int numL,int rap, int decal, int decal2){
    for(int i=decal; i<decal+3; i++) {
      strip.setPixelColor(i, strip.Color(100, 0, 0));
      strip.setPixelColor(i+decal2, strip.Color(100, 0, 0));
      strip.show();
    }  
}
void fadeLed(int numL,int rap, int decal, int decal2){
   int R = 100;
   int G = 100;
   int B = 100;
  for(R && G && B; R<255 && G<255 && B<255; R++ && G++ && B++) {
    for(int i=decal; i<decal+3; i++) {
      strip.setPixelColor(i, strip.Color(R, 0, 0));
      strip.setPixelColor(i+decal2, strip.Color(R, 0, 0));
      strip.show();
    }
    delay(rap);
  }
  for(R && G && B; R>100 && G>100 && B>100; R-- && G-- && B--) {
    for(int i=decal; i<decal+3; i++) {
      strip.setPixelColor(i, strip.Color(R, 0, 0));
      strip.setPixelColor(i+decal2, strip.Color(R, 0, 0));
      strip.show();
    }
    delay(rap);
  }  
}
void fadeLedB(int numL,int rap, int decal, int decal2){
   int R = 100;
   int G = 100;
   int B = 100;
  for(R && G && B; R<255 && G<255 && B<255; R++ && G++ && B++) {
    for(int i=decal; i<decal+3; i++) {
      strip.setPixelColor(i, strip.Color(0, 0, B));
      strip.setPixelColor(i+decal2, strip.Color(0, 0, B));
      strip.show();
    }
    delay(rap);
  }
  for(R && G && B; R>100 && G>100 && B>100; R-- && G-- && B--) {
    for(int i=decal; i<decal+3; i++) {
      strip.setPixelColor(i, strip.Color(0, 0, B));
      strip.setPixelColor(i+decal2, strip.Color(0, 0, B));
      strip.show();
    }
    delay(rap);
  }  
}

// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, c);
      strip.show();
      delay(wait);
  }
}

void rainbow(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel((i+j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

// Slightly different, this makes the rainbow equally distributed throughout
void rainbowCycle(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
    for(i=0; i< strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

//Theatre-style crawling lights.
void theaterChase(uint32_t c, uint8_t wait) {
  for (int j=0; j<10; j++) {  //do 10 cycles of chasing
    for (int q=0; q < 3; q++) {
      for (int i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, c);    //turn every third pixel on
      }
      strip.show();
     
      delay(wait);
     
      for (int i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, 0);        //turn every third pixel off
      }
    }
  }
}

//Theatre-style crawling lights with rainbow effect
void theaterChaseRainbow(uint8_t wait) {
  for (int j=0; j < 256; j++) {     // cycle all 256 colors in the wheel
    for (int q=0; q < 3; q++) {
        for (int i=0; i < strip.numPixels(); i=i+3) {
          strip.setPixelColor(i+q, Wheel( (i+j) % 255));    //turn every third pixel on
        }
        strip.show();
       
        delay(wait);
       
        for (int i=0; i < strip.numPixels(); i=i+3) {
          strip.setPixelColor(i+q, 0);        //turn every third pixel off
        }
    }
  }
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  if(WheelPos < 85) {
   return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  } else if(WheelPos < 170) {
   WheelPos -= 85;
   return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } else {
   WheelPos -= 170;
   return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
}
uint8_t readCapacitivePin(int pinToMeasure) {
  // Variables used to translate from Arduino to AVR pin naming
  volatile uint8_t* port;
  volatile uint8_t* ddr;
  volatile uint8_t* pin;
  // Here we translate the input pin number from
  //  Arduino pin number to the AVR PORT, PIN, DDR,
  //  and which bit of those registers we care about.
  byte bitmask;
  port = portOutputRegister(digitalPinToPort(pinToMeasure));
  ddr = portModeRegister(digitalPinToPort(pinToMeasure));
  bitmask = digitalPinToBitMask(pinToMeasure);
  pin = portInputRegister(digitalPinToPort(pinToMeasure));
  // Discharge the pin first by setting it low and output
  *port &= ~(bitmask);
  *ddr  |= bitmask;
  //delay(1);
  // Prevent the timer IRQ from disturbing our measurement
  noInterrupts();
  // Make the pin an input with the internal pull-up on
  *ddr &= ~(bitmask);
  *port |= bitmask;

  // Now see how long the pin to get pulled up. This manual unrolling of the loop
  // decreases the number of hardware cycles between each read of the pin,
  // thus increasing sensitivity.
  uint8_t cycles = 17;
       if (*pin & bitmask) { cycles =  0;}
  else if (*pin & bitmask) { cycles =  1;}
  else if (*pin & bitmask) { cycles =  2;}
  else if (*pin & bitmask) { cycles =  3;}
  else if (*pin & bitmask) { cycles =  4;}
  else if (*pin & bitmask) { cycles =  5;}
  else if (*pin & bitmask) { cycles =  6;}
  else if (*pin & bitmask) { cycles =  7;}
  else if (*pin & bitmask) { cycles =  8;}
  else if (*pin & bitmask) { cycles =  9;}
  else if (*pin & bitmask) { cycles = 10;}
  else if (*pin & bitmask) { cycles = 11;}
  else if (*pin & bitmask) { cycles = 12;}
  else if (*pin & bitmask) { cycles = 13;}
  else if (*pin & bitmask) { cycles = 14;}
  else if (*pin & bitmask) { cycles = 15;}
  else if (*pin & bitmask) { cycles = 16;}

  // End of timing-critical section
  interrupts();

  // Discharge the pin again by setting it low and output
  //  It's important to leave the pins low if you want to 
  //  be able to touch more than 1 sensor at a time - if
  //  the sensor is left pulled high, when you touch
  //  two sensors, your body will transfer the charge between
  //  sensors.
  *port &= ~(bitmask);
  *ddr  |= bitmask;

  return cycles;
}