#include <Wtv020sd16p.h>

#include <Adafruit_NeoPixel.h>
//#include "DigiKeyboard.h"
#include "EEPROM.h"

int resetPin = 2;  // The pin number of the reset pin.
int clockPin = 3;  // The pin number of the clock pin.
int dataPin = 4;  // The pin number of the data pin.
int busyPin = 5;  // The pin number of the busy pin.

Wtv020sd16p wtv020sd16p(resetPin,clockPin,dataPin,busyPin);




int numLeds = 3;
int ledPin = 9;
Adafruit_NeoPixel strip = Adafruit_NeoPixel(numLeds, ledPin, NEO_GRB + NEO_KHZ800);
int  brightness = 64;
 
void setup(void)
{
  Serial.begin(9600);
  Serial.println("## Starting ##");
 
 // pinMode(1,OUTPUT); yellow led on the attiny

  strip.begin();
  strip.show();

  PlayNextTrack();

}

void loop()
{
  //Serial.print("Loop: ");Serial.println(millis());
  AnimateLed();
  serialEvent();//look for incoming track change via serial
  CheckForTrackChange();//look for end of track;
}





