

void AnimateLed()
{
  switch(currentLedProgram)
  {
    case 0:
      Rainbow(20);
      break;
    case 1:
      Random();
      break;
    case 2:
     Flasher();
     break;
  }
}



void Rainbow(int wait)
{}

void Random()
{}

void Flasher()
{}

void DisplayLed(long col)
{
  strip.setPixelColor(0, col);
  strip.show();
}

/*
void PulseYellowLed()
{
  digitalWrite(1,HIGH);
  delay(5);
  digitalWrite(1,LOW);
  
}



void flashes(int r)
{
  for(int i = 0; i<r;i++)
  {
  PulseYellowLed();
  delay(300);
  }
}
*/
