int currentLedProgram = 0;
long nextLedChange = 0;

void AnimateLed()
{
  //cycles through the programs
  if(millis() > nextLedChange)
  {
    //set the next program
    currentLedProgram++;
    currentLedProgram = currentLedProgram % 3;//mod max fames, go back to zero if required

    //set the next time to change program
    nextLedChange = millis()+10000;

     //customer short time for flasher program, otherwise it will be annoying
    if(currentLedProgram == 2) //flasher
    nextLedChange = nextLedChange - 7000; 
  }

   // Serial.print("currentLedProgram = " );  Serial.println(currentLedProgram ); 
  switch(currentLedProgram)
  {
    case 0:
      rainbowCycle(20);
      break;
    case 1:
      Random();
      break;
    case 2:
     Flasher();
     break;
  }
}


void Random()
{
  strip.setPixelColor(0, pickColor());
  strip.show();
  delay(500);
  
  strip.setPixelColor(1, pickColor());
  strip.show();
  delay(500);
  
  strip.setPixelColor(2, pickColor());
  strip.show();
  delay(500);


}

void Flasher()
{
  strip.setPixelColor(0,strip.Color(brightness,brightness,brightness));
  strip.setPixelColor(1,strip.Color(brightness,brightness,brightness));
  strip.setPixelColor(2,strip.Color(brightness,brightness,brightness));
  strip.show();
  delay(100);
  
  strip.setPixelColor(0,0);
  strip.setPixelColor(1,0);
  strip.setPixelColor(2,0);
  strip.show();
  delay(100);
  }

void Pulses()
{
  strip.setPixelColor(0,strip.Color(brightness/2,brightness/2,brightness/2));
  strip.setPixelColor(1,strip.Color(brightness/2,brightness/2,brightness/2));
  strip.setPixelColor(2,strip.Color(brightness/2,brightness/2,brightness/2));
  strip.show();
  delay(30);
  
  strip.setPixelColor(0,strip.Color(brightness,brightness,brightness));
  strip.setPixelColor(1,strip.Color(brightness,brightness,brightness));
  strip.setPixelColor(2,strip.Color(brightness,brightness,brightness));
  strip.show();
  delay(30);

  strip.setPixelColor(0,strip.Color(brightness/2,brightness/2,brightness/2));
  strip.setPixelColor(1,strip.Color(brightness/2,brightness/2,brightness/2));
  strip.setPixelColor(2,strip.Color(brightness/2,brightness/2,brightness/2));
  strip.show();
  delay(30);
  
  
  strip.setPixelColor(0,0);
  strip.setPixelColor(1,0);
  strip.setPixelColor(2,0);
  strip.show();
  delay(50);
  }


long pickColor()
{
  int color;
  int rand = random(1,7);
  
  Serial.println(rand);
  switch(rand)
  {
        case 1:
     return strip.Color(0, 255, 0);
    break;
        case 2:
     return strip.Color(0, 0, 255);
    break;
        case 3:
     return strip.Color(127, 127, 0);
    break;
        case 4:
     return strip.Color(127, 0, 127);
    break;
        case 5:
     return strip.Color(0, 127, 127);
    break;
    case 6:
      return strip.Color(254, 0, 0);
    break;

  }
  //Serial.println(color);
  return color;
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


/*
PulseYellowLed();

void flashes(int r)
{
  for(int i = 0; i<r;i++)
  {
  PulseYellowLed();
  delay(300);
  }
}
*/
