#include <Adafruit_NeoPixel.h>

#define PIN 13

// People seem to make their matrixes in two modes...
// Seeedstudio - flip each row (uncomment)
// Adafruit - don't flip each row
// #define FLIPMODE

// Used for matrix calculations
#define ROW_8

// rows of 8
#ifdef ROW_8
#define ROW_SIZE 8
byte mask[][ROW_SIZE] = {
    {1,1,1,1,1,1,1,1},
    {0,0,0,0,0,0,0,0},    
    {1,1,1,1,1,1,1,1},
    {0,0,0,0,0,0,0,0},   
    {1,1,1,1,1,1,1,1},
    {0,0,0,0,0,0,0,0},
    {1,1,1,1,1,1,1,1}, 
    {0,0,0,0,0,0,0,0}
  };
  
byte mask2[][ROW_SIZE] = {
    {1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1}, 
    {1,1,1,1,1,1,1,1},
  };

byte mask3[][ROW_SIZE] = {
    {1,0,1,0,1,0,1,0},
    {0,1,0,1,0,1,0,1},
    {1,0,1,0,1,0,1,0},
    {0,1,0,1,0,1,0,1},
    {1,0,1,0,1,0,1,0},
    {0,1,0,1,0,1,0,1},
    {1,0,1,0,1,0,1,0}, 
    {0,1,0,1,0,1,0,1},
  };


byte mask4[][ROW_SIZE] = {
    {1,1,1,1,0,0,0,0},
    {1,1,1,1,0,0,0,0},
    {1,1,1,1,0,0,0,0},
    {1,1,1,1,0,0,0,0},
    {0,0,0,0,1,1,1,1},
    {0,0,0,0,1,1,1,1},
    {0,0,0,0,1,1,1,1}, 
    {0,0,0,0,1,1,1,1},
  };


byte mask5[][ROW_SIZE] = {
    {1,1,0,0,1,1,0,0},
    {1,1,0,0,1,1,0,0},
    {0,0,1,1,0,0,1,1},
    {0,0,1,1,0,0,1,1},
    {1,1,0,0,1,1,0,0},
    {1,1,0,0,1,1,0,0},
    {0,0,1,1,0,0,1,1}, 
    {0,0,1,1,0,0,1,1},
  };
  
byte maskEmpty[][ROW_SIZE] = {
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0}
};  

byte doubleheart[][ROW_SIZE] = {
  {0,0,0,0,0,0,0,0},
  {0,1,1,0,1,1,0,0},
  {1,1,1,1,1,1,1,0},
  {1,1,1,1,1,1,1,0},
  {0,1,1,1,1,1,0,0},
  {0,0,1,1,1,0,0,0},
  {0,0,0,1,0,0,0,0},
  {0,0,0,0,0,0,0,0}
};


byte doubleArrow[][ROW_SIZE] = {
  {0,1,0,0,0,0,0,0},
  {0,0,1,0,0,0,0,0},
  {0,0,0,1,0,0,0,0},
  {0,0,0,0,1,0,0,0},
  {0,0,0,0,1,0,0,0},
  {0,0,0,1,0,0,0,0},
  {0,0,1,0,0,0,0,0},
  {0,1,0,0,0,0,0,0}
};

byte flatline[][ROW_SIZE] = {
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,1,0,0,0,0},
  {0,0,1,0,1,0,0,0},
  {1,1,0,0,0,1,1,},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0}
};  

byte dna2[][ROW_SIZE] = {
  {0,0,0,0,0,0,0,0},
  {1,1,0,0,0,0,1,1},
  {0,0,1,0,0,1,0,0},
  {0,0,0,1,1,0,0,0},
  {0,0,0,1,1,0,0,0},
  {0,0,1,1,0,1,0,0},
  {1,1,0,0,0,0,1,1},
  {0,0,0,0,0,0,0,0}
};    

byte heart[][ROW_SIZE] = {
    {0,0,0,0,0,0,0,0}, 
    {1,1,0,0,1,1,0,0},
    {0,0,0,0,0,0,0,0}, 
    {0,0,1,1,0,0,1,1}, 
    {0,0,0,0,0,0,0,0},    
    {0,0,0,0,1,1,1,1}, 
    {0,0,0,0,0,0,0,0},
    {1,1,1,1,0,0,0,0}
  };  
#endif

// TODO (gguuss) Move to separate file.
// rows of 16
#undef ROW_16
#ifdef ROW_16
#define ROW_SIZE 16
byte mask[][ROW_SIZE] = {
    {1,1,1,1,1,1,1,1, 0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0, 1,1,1,1,1,1,1,1},
    
    {1,1,1,1,1,1,1,1, 0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0, 1,1,1,1,1,1,1,1},
    
    {1,1,1,1,1,1,1,1, 0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0, 1,1,1,1,1,1,1,1},
    
    {1,1,1,1,1,1,1,1, 0,0,0,0,0,0,0,0}, 
    {0,0,0,0,0,0,0,0, 1,1,1,1,1,1,1,1}
  };
  
byte maskEmpty[][ROW_SIZE] = {
  {0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0}
};  

byte doubleheart[][ROW_SIZE] = {
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,1,1,0,1,1,0,0,0,1,1,0,1,1,0,0},
  {1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,0},
  {1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,0},
  {0,1,1,1,1,1,0,0,0,1,1,1,1,1,0,0},
  {0,0,1,1,1,0,0,0,0,0,1,1,1,0,0,0},
  {0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};


byte dna[][ROW_SIZE] = {
  {0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0},
  {1,1,1,0,0,1,1,1, 1,1,0,0,0,1,1,1},
  {1,0,0,1,1,0,1,0, 1,0,1,1,1,1,0,0},
  {1,0,0,1,1,0,1,0, 1,0,0,1,0,1,0,0},
  {1,0,0,1,1,0,1,0, 1,0,1,1,0,1,0,0},
  {1,0,1,1,1,0,1,0, 1,1,0,1,1,1,0,0},
  {1,1,0,0,0,1,1,1, 1,0,0,0,0,1,1,1},
  {0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0}
};  

byte dna2[][ROW_SIZE] = {
  {0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0},
  {1,1,0,0,0,0,1,1, 1,1,0,0,0,0,1,1},
  {0,0,1,0,0,1,0,0, 0,0,1,0,0,1,0,0},
  {0,0,0,1,1,0,0,0, 0,0,0,1,1,0,0,0},
  {0,0,0,1,1,0,0,0, 0,0,0,1,1,0,0,0},
  {0,0,1,1,0,1,0,0, 0,1,0,0,0,1,0,0},
  {1,1,0,0,0,0,1,1, 1,1,0,0,0,0,1,1},
  {0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0}
};  


byte doubleArrow[][ROW_SIZE] = {
  {0,1,0,1,0,0,0,0, 0,1,0,1,0,0,0,0},
  {0,0,1,0,1,0,0,0, 0,0,1,0,1,0,0,0},
  {0,0,0,1,0,1,0,0, 0,0,0,1,0,1,0,0},
  {0,0,0,0,1,0,1,0, 0,0,0,0,1,0,1,0},
  {0,0,0,0,1,0,1,0, 0,0,0,0,1,0,1,0},
  {0,0,0,1,0,1,0,0, 0,0,0,1,0,1,0,0},
  {0,0,1,0,1,0,0,0, 0,0,1,0,1,0,0,0},
  {0,1,0,1,0,0,0,0, 0,1,0,1,0,0,0,0}
};  
  

byte heart[][ROW_SIZE] = {
    {0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0}, 
    {0,0,0,0,0,0,0,0, 0,1,1,0,0,1,1,0},
    {0,0,0,0,0,0,0,0, 1,1,1,1,1,1,1,1}, 
    {0,0,0,0,0,0,0,0, 1,1,1,1,1,1,1,1},    
    {0,0,0,0,0,0,0,0, 0,1,1,1,1,1,1,0}, 
    {0,0,0,0,0,0,0,0, 0,0,1,1,1,1,0,0},
    {0,0,0,0,0,0,0,0, 0,0,0,1,1,0,0,0}, 
    {0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0}
  };  

byte smallHeart[][ROW_SIZE] = {
    {0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0}, 
    {0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0},    
    {0,0,1,0,0,1,0,0, 0,0,0,0,0,0,0,0}, 
    {0,0,0,0,0,0,0,0, 0,1,1,1,1,1,1,0},    
    {0,0,1,1,1,1,0,0, 0,0,0,0,0,0,0,0}, 
    {0,0,0,0,0,0,0,0, 0,0,0,1,1,0,0,0},    
    {0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0}, 
    {0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0}
  };
  
#endif


// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(128, PIN, NEO_GRB + NEO_KHZ800);

// IMPORTANT: To reduce NeoPixel burnout risk, add 1000 uF capacitor across
// pixel power leads, add 300 - 500 Ohm resistor on first pixel's data input
// and minimize distance between Arduino and first pixel.  Avoid connecting
// on a live circuit...if you must, connect GND first.

int inPin = 7;

void setup() {
  pinMode(inPin, INPUT); // Pushbutton
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

int pattern = 15;
#define patternLimit 17
int val;
int bounceCount = 0;
int bounceLimit = 3;
boolean strobeOn = false;
int colorLooper = 0;
void loop() { 
  val = digitalRead(inPin);
  checkButton();

  //if (strobeOn) strobe(strip.Color(0,0,0), 10);
  switch (pattern) {
    case 0:
      patternRotate(50, 256, flatline);  
      break;
    case 1:
      patternRotate(50, 32, doubleheart);
      break;
    case 2:
      patternRotate(50, 256, doubleArrow);  
      break;
    case 3:
      patternRotate(50, 256, heart);
      break;
    case 4:
      patternRotate(50, 256, mask);
      break;
    case 5:
      patternRotate(50, 256, dna2);
      break;
    case 6:
      patternRotate(50, 256, mask2);
      break;
    case 7:
      patternRotate(50, 256, mask3);
      break;
    case 8:
      patternRotate(50,256,mask4);
      break;
    case 9:
      patternRotate(100, 128, mask3);
      break;
    case 10:
      patternRotate(50, 128, mask5);
      break;    
    case 11:
      strobe(strip.Color(0,0,255), 10);
      break;
    case 12:
      strobe(strip.Color(0,255,0), 10);
      break;  
    case 13:
      strobe(strip.Color(255,255,255), 10);
      break;
    case 14:
      scan(25);
      break;
    case 15:
      grid(50, Wheel(colorLooper));
      colorLooper += 10;
      break;
    case 16:
      box(50, Wheel(colorLooper));
      colorLooper += 10;
      break;      
    case patternLimit:
      // Warning: The final pattern must debounce current pattern to 0.
      heartPulse();      
      break;      
  }
}

void checkButton () {
  if (val == HIGH) {
    if (bounceCount < bounceLimit){
      bounceCount++;
    }else{
      pattern++;
      bounceCount = 0;
    }
    if (pattern > patternLimit){
      pattern = 0;
    }
  }
}

// TODO: Draw boxes of varying size
void grid(int delayMs, uint32_t color) {
  uint16_t i, j, displace;
  displace = 0;

  for (displace = 0; displace < ROW_SIZE; displace++){
    for (int i=0; i < ROW_SIZE; i++){
      for (int j=0; j < ROW_SIZE; j++){
        if (i == displace || j == displace || (i == (ROW_SIZE-1) - displace) || (j == (ROW_SIZE-1) - displace)){
          //strip.setBrightness(brightness);
          strip.setPixelColor(j + (i * ROW_SIZE), color);
        }else{
          strip.setPixelColor(j + (i * ROW_SIZE), 0);
        }
      }
    }
    strip.show();
    delay(delayMs);
  }
}

// TODO: Draw boxes of varying size
void box(int delayMs, uint32_t color) {
  uint16_t i, j, displace;
  displace = 0;

  for (displace = 0; displace < ROW_SIZE; displace++){
    for (int i=0; i < ROW_SIZE; i++){
      for (int j=0; j < ROW_SIZE; j++){
        if ( (i >= displace && i <= (ROW_SIZE-1)-displace) && (j >= displace && (j <= (ROW_SIZE-1) - displace)) ){
          //strip.setBrightness(brightness);
          strip.setPixelColor(j + (i * ROW_SIZE), color);
        }else{
          strip.setPixelColor(j + (i * ROW_SIZE), 0);
        }
      }
    }
    strip.show();
    delay(delayMs);
  }

  for (displace = ROW_SIZE-1; displace > 0; displace--){
    for (int i=0; i < ROW_SIZE; i++){
      for (int j=0; j < ROW_SIZE; j++){
        if ( (i >= displace && i <= (ROW_SIZE-1)-displace) && (j >= displace && (j <= (ROW_SIZE-1) - displace)) ){
          //strip.setBrightness(brightness);
          strip.setPixelColor(j + (i * ROW_SIZE), color);
        }else{
          strip.setPixelColor(j + (i * ROW_SIZE), 0);
        }
      }
    }
    strip.show();
    delay(delayMs);
  }
}


void scan(int delayMs) {
  uint16_t i, j, rowOn;
  rowOn = 0;
  uint32_t color = strip.Color(255,0,137);
  for (rowOn = 0; rowOn < ROW_SIZE; rowOn++){
    for (int i=0; i < ROW_SIZE; i++){
      for (int j=0; j < ROW_SIZE; j++){
        if (i == rowOn){
          //strip.setBrightness(brightness);
          strip.setPixelColor(j + (i * ROW_SIZE), color);
        }else{
          strip.setPixelColor(j + (i * ROW_SIZE), 0);
        }
      }
    }
    strip.show();
    delay(delayMs);
  }
  for (rowOn = ROW_SIZE-1; rowOn > 0; rowOn--){
    for (int i=0; i < ROW_SIZE; i++){
      for (int j=0; j < ROW_SIZE; j++){
        if (i == rowOn){
          //strip.setBrightness(brightness);
          strip.setPixelColor(j + (i * ROW_SIZE), color);
        }else{
          strip.setPixelColor(j + (i * ROW_SIZE), 0);
        }
      }
    }
    strip.show();
    delay(delayMs);
  }
}

void heartPulse() {
  // New test patterns.
  int steps = 20;
  int speed = 40;
  uint32_t color = strip.Color(255,0,137);
  
  for (int i=0; i < steps; i++){  
    maskedColorWipe(speed, color, (100 / steps) * i, 0, doubleheart);
  }
  maskedColorWipe(250, color, 100, 0, doubleheart);
  checkButton();
  
  for (int i=steps; i > 0; i--){  
    maskedColorWipe(speed, color, (100 / steps) * i, 0, doubleheart);
    checkButton();
  }
  
  maskedColorWipe(500, color, 100, 0, maskEmpty);
  checkButton();
  
  // Prevents bouncing.
  if (pattern < patternLimit) pattern = 0;
  return;
}


void strobe(uint32_t color, int strobeRate) {
  maskedColorWipe(strobeRate, color, 255, 0, mask2);
  maskedColorWipe(strobeRate * 4, strip.Color(0,0,0), 0, 0, maskEmpty);
}



uint8_t shiftty = 1;
int scrollDir = 1;
//  speed - Speed to draw (lower is faster).
//  scrollLimit - # times to show before reversing pattern scrolling.
//  pattern - The displayed pattern, defined by 0's (off) and 1's (on).
void patternRotate(int speed, int scrollLimit, byte pattern[][ROW_SIZE]) {
  uint32_t color = strip.Color(255,0,137);
  if (true) {
    maskedColorWipe(speed, Wheel(shiftty*5), 50, shiftty, pattern);  
  } else if (true) {
    maskedRainbowCycle(speed, 50, shiftty, pattern);
  } else {
  }
  shiftty += scrollDir;
  
  if(shiftty > scrollLimit){
    scrollDir = -1;
  }
  if (shiftty <= 0){
    scrollDir = 1;
  }
  return;
}



boolean drawGivenMask(int row, int col, int shift, byte mask[][ROW_SIZE]){
  #ifdef FLIPMODE
  if (row & 1) {
    col = ROW_SIZE - (col + 1);
  }  
  #endif
  col = (col + shift) % ROW_SIZE;
  
  if (mask[row][col] & 1){
    return true;
  }
  return false;
}


void maskedColorWipe(uint8_t wait, uint32_t color, uint8_t brightness, uint8_t shift, byte mask[][ROW_SIZE]) {
  uint16_t i, j;

  for(i=0; i<strip.numPixels(); i++) {
    if (drawGivenMask(i / ROW_SIZE, i % ROW_SIZE, shift, mask)){
      strip.setBrightness(brightness);
      strip.setPixelColor(i, color);
    }else{
      strip.setPixelColor(i, 0);
    }
  }
  
  strip.show();
  delay(wait);
}


// Slightly different, this makes the rainbow equally distributed throughout
uint16_t col_bold = 0;
void maskedRainbowCycle(uint8_t wait, uint8_t colSpeed, uint8_t shift, byte mask[][ROW_SIZE]) {
  if (col_bold >= 255) { col_bold = 0; };
    for(int i=0; i< strip.numPixels(); i++) {
      if (drawGivenMask(i / ROW_SIZE, i % ROW_SIZE, shift, mask)) {
        strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + col_bold) & 255));
      } else {
        strip.setPixelColor(i, 0);
      }
    }
  col_bold += colSpeed;
  strip.show();
  delay(wait);
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
   return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } else if(WheelPos < 170) {
    WheelPos -= 85;
   return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  } else {
   WheelPos -= 170;
   return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  }
}

