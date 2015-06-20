#include <Adafruit_NeoPixel.h>
#include <MicroView.h>
#include <CapacitiveSensor.h>

#define PIN 6
#define PIXEL 29
CapacitiveSensor   cs_4_2 = CapacitiveSensor(3,5);        // 10M resistor between pins 4 & 2, pin 2 is sensor pin, add a wire and or foil if desired

//CapacitiveSensor   cs_4_7 = CapacitiveSensor(4,7);        // 10M resistor between pins 4 & 2, pin 2 is sensor pin, add a wire and or foil if desired


// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXEL, PIN, NEO_GRB + NEO_KHZ800);
#define SHAPE_SIZE 600
#define ROTATION_SPEED 0 // ms delay between cube draws

//int SCREEN_WIDTH = uView.getLCDWidth();
//int SCREEN_HEIGHT = uView.getLCDHeight();

float d = 3;
float px[] = { -d,  d,  d, -d, -d,  d,  d, -d };
float py[] = { -d, -d,  d,  d, -d, -d,  d,  d };
float pz[] = { -d, -d, -d, -d,  d,  d,  d,  d };

float p2x[] = {0,0,0,0,0,0,0,0};
float p2y[] = {0,0,0,0,0,0,0,0};

float r[] = {0,0,0};
// note durations: 4 = quarter note, 8 = eighth note, etc.:

int brightness = 0;    // how bright the LED is
int fadeAmount = 5;    // how many points to fade the LED by

int valueColor1 = 0;
int valueColor2 = 0;
int valueColor3 = 0;

int sensibility = 2500;
int sensibility2 = 1600;
// IMPORTANT: To reduce NeoPixel burnout risk, add 1000 uF capacitor across
// pixel power leads, add 300 - 500 Ohm resistor on first pixel's data input
// and minimize distance between Arduino and first pixel.  Avoid connecting
// on a live circuit...if you must, connect GND first.
boolean boolCap1 = false;
boolean boolCap2 = false;
boolean boolCap3 = false;
int arrayRed[PIXEL];
int arrayGreen[PIXEL];
int arrayBleu[PIXEL];
int arrayRandom[PIXEL] = {2,1,4,0,5};
long starto1 = millis();
long starto2 = millis();
long starto3 = millis();

int time1 = 10000;
int time2 = 13000;
int xCos = 0;
long time=0;

int periode[PIXEL] = {};
int periodeProgress[PIXEL] = {};
int periodeCible[PIXEL] = {};
int displace[PIXEL] = {};
int valCos = 0;

int total = 0;                  // the running total
int average = 0;                // the averag
int averageCible = 0;                // the averag
int randomI = 0;

int zeroRed = 0;
int zeroBleu = 0;
int zeroGreen = 0;
int idOnde = 0;
int speedOnde = 300;

int redOnde = 0;
int bleuOnde = 0;
int greenOnde = 0;

int randomArray[PIXEL] = {0,1,2,3,4};

int amplitudeR[PIXEL] = {122,122,122,122,122};                // the averag
int amplitudeG[PIXEL] = {0,0,0,0,0};                // the averag
int amplitudeB[PIXEL] = {0,0,0,0,0};                // the averag

int amplitudeRCible[PIXEL] = {122,122,122,122,122};                 // the averag
int amplitudeGCible[PIXEL] = {0,0,0,0,0};               // the averag
int amplitudeBCible[PIXEL] =  {0,0,0,0,0};                // the averag

long timeTouch = 3000;
long timePeriode = 3000;
long timePulse = 0;
long timePulseA = 0;
long timePulseB = 0;
long timeOnde = 0;
int timingOnde = 2000;
int polarity[PIXEL] = {1,1,1,1,1};

boolean boolPositiv=false;
boolean boolNegativ=false;
boolean boolColor=false;

boolean boolPulse=false;
boolean boolPulseA=false;
boolean boolPulseB=false;

boolean boolOnde=false;
String Data = "";

void setup() {  
  Serial.begin(9600);
  strip.begin();
  strip.show();
  //cs_4_2.set_CS_AutocaL_Millis(5000);     // turn off autocalibrate on channel 1 - just as an example
  //cs_4_7.set_CS_AutocaL_Millis(200000);     // turn off autocalibrate on channel 1 - just as an example
  uView.begin();
  uView.clear(ALL);
  uView.display();  
  // Set UP pulsation led for all
  startInt(periode,300,0,2,0,PIXEL);
  startInt(periodeCible,1000,0,2,0,PIXEL);
  startInt(amplitudeR,0,0,2,0,PIXEL);
  startInt(amplitudeG,0,0,2,0,PIXEL);
  startInt(amplitudeB,0,0,2,0,PIXEL);
  startInt(amplitudeRCible,0,0,2,0,PIXEL);
  startInt(amplitudeGCible,0,0,2,0,PIXEL);
  startInt(amplitudeBCible,0,0,2,0,PIXEL);
  startInt(polarity,1,0,2,0,PIXEL);
  decalLedFour(arrayRandom,50,100);

//  startInt(arrayRandom,0,10,80,0,PIXEL);

  // Set UP pulsation led for the 4 last
  startInt(amplitudeR,0,0,2,PIXEL-4,PIXEL);
  startInt(amplitudeG,0,0,2,PIXEL-4,PIXEL);
  startInt(amplitudeB,0,0,2,PIXEL-4,PIXEL);
  startInt(amplitudeRCible,0,0,2,PIXEL-4,PIXEL);
  startInt(amplitudeGCible,0,0,2,PIXEL-4,PIXEL);
  startInt(amplitudeBCible,0,0,2,PIXEL-4,PIXEL);
  /////////////////////////////////////
  selectLed(0,26,0,0,90);

}
void loop() {
    time = millis();
    long start = millis();
    //long total1 =  cs_4_2.capacitiveSensor(5);    
    //cs_4_2.set_CS_Timeout_Millis(300);

    //long total2 =  cs_4_7.capacitiveSensor(30);    
    //int capacitiv1 = readCapacitivePin(5);
    ////
    //Serial.print(millis() - start);        // check on performance in milliseconds
    //Serial.print("\t");                    // tab character for debug windown spacing
    //Serial.print("total1 ");
    //Serial.println(total1);
    //Serial.print(" total2 ");
    //Serial.println(total2);
     /*if(total1>sensibility){
      Serial.println("A");
      boolPulseA=true;
      timePulseA = millis();
      //startInt(periodeCible,500,0,2);
      selectLed(0,PIXEL,90,0,0);
    }
    if(total2>sensibility2){
      Serial.println("B");
      boolPulseB=true;
      timePulseB = millis();
      //startInt(periodeCible,500,0,2);
      selectLed(0,PIXEL,0,90,0);
    }*/
    if (Serial.available())
    {
      int mode = Serial.parseInt(); 
      int red = Serial.parseInt(); 
      int green = Serial.parseInt(); 
      int blue = Serial.parseInt(); 
      int start = Serial.parseInt(); 
      int stop = Serial.parseInt(); 
      int phase = Serial.parseInt(); 
      if (Serial.read() == '\n') {
        switch (mode){ 
           case 0: 
              //boolColor=false;
              boolPulse=false;
              timePulse = millis();
              selectLed(start,stop,red,green,blue);
           break;        
           case 1:
              //boolColor=false;
              boolPulse=true;
              timePulse = millis();
              selectLed(start,stop,red,green,blue);
           break;        
           case 2: 
             startInt(periodeCible,red,green,blue,0,PIXEL);
           break;        
           case 3: 
             startInt(arrayRandom,red,green,blue,0,PIXEL);
           break;        
           case 4: 
             if(red==0){
               boolPositiv=true;
             }else{
               boolNegativ=true;
             }
             break;        
           case 5:
              boolPulse=false;
              boolOnde=true;
              timeOnde = millis();
              speedOnde = start;
              redOnde = red;
              bleuOnde = blue;
              greenOnde = green;
           break;
           case 6:
              boolPulse=true;
              boolOnde=true;
              timePulse = millis();
              timeOnde = millis();
              speedOnde = start;
              redOnde = red;
              bleuOnde = blue;
              greenOnde = green;
              timingOnde = stop;
           break;
           case 7: 
             ondeLed(start,stop,red,green,blue);
           break;        
           case 8: 
             phaseLedA(start,stop,red,green,blue,phase);
           break;        
           case 9: 
             phaseLedB(start,stop,red,green,blue,phase);
           break;  
           case 10: 
             phaseLed_cible(start,stop,red,green,blue);
           break;  
           case 11: 
             decalLedFour(arrayRandom,start,stop);
           break;  
           case 12: 
              startInt(amplitudeRCible,red,0,2,0,PIXEL);
              startInt(amplitudeGCible,green,0,2,0,PIXEL);
              startInt(amplitudeBCible,blue,0,2,0,PIXEL);
           break;             
           case 100:
              zeroRed=red;
              zeroBleu=blue;
              zeroGreen=green;
           break;
        }
      }
    }  
    uView.clear(PAGE);    // clear page
    uView.setCursor(0,0); // set cursor to 0,0
    uView.print(timePulse); // display Mid
    uView.setCursor(0,10); // set cursor to 0,0
    uView.print(boolPulse); // display Mid
    uView.setCursor(0,20); // set cursor to 0,0
    uView.print(122+122*cos(2*PI/2000*((300)-time))); // display Mid
    uView.display();
    if(millis()-timePulseA>1000 && boolPulseA==true){
      selectLed(0,PIXEL,0,0,90);
      //startInt(periodeCible,1500,0,true,0,PIXEL);      
      boolPulse=false;
    }
    if(millis()-timePulseB>1000 && boolPulseB==true){
      selectLed(0,PIXEL,0,0,90);
      //startInt(periodeCible,1500,0,true,0,PIXEL);      
      boolPulse=false;
    }
    if(millis()-timePulse>timingOnde   && boolPulse==true){
      selectLed(0,PIXEL,0,0,90);
      //startInt(periodeCible,1500,0,true);      
      boolPulse=false;
    }    
    if(millis()-timeOnde>speedOnde && boolOnde==true){
      phaseLed(idOnde,idOnde+1,redOnde,bleuOnde,greenOnde);
      timeOnde=millis();
      if(idOnde>5){
        boolOnde=false;        
        idOnde=0;
      }else{
        idOnde++;
      }
    }    
    if(boolPositiv){
       if(amplitudeBCible[0]<100){
        amplitudeBCible[0]=amplitudeBCible[0]+1;          
       }else{
        boolPositiv=false;
       }
    }else if(boolNegativ){
       if(amplitudeBCible[0]>0){
        amplitudeBCible[0]=amplitudeBCible[0]-1;          
       }else{
        boolNegativ=false;
       }
    }    
    for(int i=0; i<strip.numPixels(); i++) {
      /*if(boolColor){
        amplitudeR[i]=amplitudeRCible[i];                 
        amplitudeG[i]=amplitudeGCible[i];                 
        amplitudeB[i]=amplitudeBCible[i];           
      }else if(floor(amplitudeR[i]+amplitudeR[i]*cos(2*PI/periode[randomArray[i]]*((300*arrayRandom[i])-time)))==0 && floor(amplitudeG[i]+amplitudeG[i]*cos(2*PI/periode[randomArray[i]]*((300*arrayRandom[i])-time)))==0 && floor(amplitudeB[i]+amplitudeB[i]*cos(2*PI/periode[randomArray[i]]*((300*arrayRandom[i])-time)))==0){
        amplitudeR[i]=amplitudeRCible[i];                 
        amplitudeG[i]=amplitudeGCible[i];                 
        amplitudeB[i]=amplitudeBCible[i];                   
      }*/
      if(floor(amplitudeR[i]+amplitudeR[i]*cos(2*PI/periode[i]*((300*arrayRandom[i])-time)))==0 && floor(amplitudeG[i]+amplitudeG[i]*cos(2*PI/periode[i]*((300*arrayRandom[i])-time)))==0 && floor(amplitudeB[i]+amplitudeB[i]*cos(2*PI/periode[i]*((300*arrayRandom[i])-time)))==0){
          //randomArray[i] = random(0,5); 
          //Serial.println(i);
          amplitudeR[i]=amplitudeRCible[i];                 
          amplitudeG[i]=amplitudeGCible[i];                 
          amplitudeB[i]=amplitudeBCible[i];                   
          if(periode[i]!=periodeCible[i]){
            polarity[i] = 0;
          }
          //int randomPeriode = random(0,5);
      }
      if(periode[i]!=periodeCible[i]){
        if(floor(amplitudeR[i]+amplitudeR[i]*cos(2*PI/periodeCible[i]*((300*arrayRandom[i])-time)))==0 && floor(amplitudeG[i]+amplitudeG[i]*cos(2*PI/periodeCible[randomArray[i]]*((300*arrayRandom[i])-time)))==0 && floor(amplitudeB[i]+amplitudeB[i]*cos(2*PI/periodeCible[randomArray[i]]*((300*arrayRandom[i])-time)))==0){
          periode[i]=periodeCible[i]; 
          //periodeCible[i]=random(1000,4000); 
          polarity[i] = 1;
        }            
      }
      /*if(millis()-timePeriode>=3000){
        int randomPeriode = floor(random(0,PIXEL));
        periodeCible[i] = periodeProgress[randomPeriode];
        timePeriode=millis();
      }*/
      int colorRdbCos = zeroRed+floor(amplitudeR[i]+amplitudeR[i]*cos(2*PI/periode[i]*((arrayRandom[i])-time)))*polarity[i];
      int colorGdbCos = zeroBleu+floor(amplitudeG[i]+amplitudeG[i]*cos(2*PI/periode[i]*((arrayRandom[i])-time)))*polarity[i];
      int colorBbCos = zeroGreen+floor(amplitudeB[i]+amplitudeB[i]*cos(2*PI/periode[i]*((arrayRandom[i])-time)))*polarity[i];
      strip.setPixelColor(i, strip.Color(colorRdbCos, colorGdbCos,colorBbCos));
      strip.show();
    }
}
void randomize(){
  for(int i=0; i<PIXEL; i++) {
    arrayRandom[i]=floor(random()*PIXEL);
  }
}
void ondeLed(int ledStart,int ledStop, int cibleRed, int cibleGreen, int cibleBleu){
  for(int i=ledStart; i<ledStop; i++) {
    triOndeColor(i, cibleRed, cibleGreen, cibleBleu);
    triOndeColor(12-i, cibleRed, cibleGreen, cibleBleu);
    triOndeColor(24-i, cibleRed, cibleGreen, cibleBleu);
    triOndeColor(13+i, cibleRed, cibleGreen, cibleBleu);
  }
}
void phaseLed(int ledStart,int ledStop, int cibleRed, int cibleGreen, int cibleBleu){
  for(int i=ledStart; i<ledStop; i++) {
    triOndeColor(i, cibleRed, cibleGreen, cibleBleu);
    triOndeColor(12-i, cibleRed, cibleGreen, cibleBleu);
    triOndeColor(24-i, cibleRed, cibleGreen, cibleBleu);
    triOndeColor(13+i, cibleRed, cibleGreen, cibleBleu);
  }
}
void phaseLed_cible(int ledStart,int ledStop, int cibleRed, int cibleGreen, int cibleBleu){
  for(int i=ledStart; i<ledStop; i++) {
    triColor(i, cibleRed, cibleGreen, cibleBleu);
    triColor(12-i, cibleRed, cibleGreen, cibleBleu);
    triColor(24-i, cibleRed, cibleGreen, cibleBleu);
    triColor(13+i, cibleRed, cibleGreen, cibleBleu);
  }
}

void decalLedFour(int cible[], int valueStart,int value){
  for(int i=0; i<6; i++) {
    cible[i]=valueStart+value*i;
    cible[13+i]=valueStart+value*i;
    cible[12-i]=valueStart+value*i;
    cible[24-i]=valueStart+value*i;
  }
}
void phaseLedA(int ledStart,int ledStop, int cibleRed, int cibleGreen, int cibleBleu, int phase){
  for(int i=ledStart; i<ledStop; i++) {
    triOndeColor(phase+i, cibleRed, cibleGreen, cibleBleu);
  }
}
void phaseLedB(int ledStart,int ledStop, int cibleRed, int cibleGreen, int cibleBleu, int phase){
  for(int i=ledStart; i<ledStop; i++) {
    triOndeColor(phase-i, cibleRed, cibleGreen, cibleBleu);
  }
}
void triColor(int cible, int cibleRed, int cibleGreen, int cibleBleu){
    amplitudeRCible[cible]=cibleRed;
    amplitudeGCible[cible]=cibleGreen;
    amplitudeBCible[cible]=cibleBleu;  
}
void triOndeColor(int cible, int cibleRed, int cibleGreen, int cibleBleu){
    amplitudeR[cible]=cibleRed;
    amplitudeG[cible]=cibleGreen;
    amplitudeB[cible]=cibleBleu;  
    amplitudeRCible[cible]=cibleRed;
    amplitudeGCible[cible]=cibleGreen;
    amplitudeBCible[cible]=cibleBleu;  
}
void triOndeColor_All(int cibleRed, int cibleGreen, int cibleBleu){
  for(int i=0; i<PIXEL; i++) {
    amplitudeR[i]=cibleRed;
    amplitudeG[i]=cibleGreen;
    amplitudeB[i]=cibleBleu;  
  }
}
void selectLed(int ledStart,int ledStop, int cibleRed, int cibleGreen, int cibleBleu){
  for(int i=ledStart; i<ledStop; i++) {
    amplitudeRCible[i]=cibleRed;
    amplitudeGCible[i]=cibleGreen;
    amplitudeBCible[i]=cibleBleu;
  }
}
void selectPyramid(int cibleLed, int cibleRed, int cibleGreen, int cibleBleu){
    arrayRed[cibleLed]=cibleRed;
    arrayGreen[cibleLed]=cibleGreen;
    arrayBleu[cibleLed]=cibleBleu;
}
void startBleu(){
  for(uint16_t i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, strip.Color(0, 0, 255));
      strip.show();
  }  
}
void startInt(int cible[], int valueStart, int value, int valueBool, int valueA, int valueB){
  for(uint16_t i=valueA; i<valueB; i++) {
      if(valueBool==1){
        cible[i]=valueStart+value*i;        
      }else if(valueBool==2){
        cible[i]=valueStart;                
      }else if(valueBool==3){
        int randChoice = valueStart+random(0,value);
        cible[i]=randChoice;                
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