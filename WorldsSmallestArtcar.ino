#include <Wtv020sd16p.h>
#include <Adafruit_NeoPixel.h>
//#include "DigiKeyboard.h"
#include "EEPROM.h"

int resetPin = 2;  // The pin number of the reset pin.
int clockPin = 3;  // The pin number of the clock pin.
int dataPin = 4;  // The pin number of the data pin.
int busyPin = 5;  // The pin number of the busy pin.

Wtv020sd16p wtv020sd16p(resetPin,clockPin,dataPin,busyPin);

unsigned short eepromAddress = 0;

unsigned int track = 4; 
int totalTracks = 9;
int data = 2;

int currentLedProgram = 0;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(1, 8, NEO_GRB + NEO_KHZ400);
int  brightness = 64;
 
void setup(void)
{
  Serial.begin(9600);
  Serial.println("## Starting ##");
 // pinMode(1,OUTPUT);

  strip.begin();
  strip.show();

  track = GetTrack();
  Serial.print("Track: ");Serial.println(track);

  wtv020sd16p.reset();
  Serial.println("Reset Audio");
  delay(500);
  wtv020sd16p.asyncPlayVoice(0);
  Serial.println("Play Audio");
}

void loop()
{
  Serial.print("Loop: ");Serial.println(millis());
  AnimateLed();
//  PulseYellowLed();
delay(1000);
}





