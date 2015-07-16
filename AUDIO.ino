
byte GetTrack()
{
  byte storedValue= EEPROM.read( eepromAddress);

  if(storedValue >= totalTracks)
  {
    EEPROM.write( eepromAddress, 0);//reset the track number
  }
  else
  {
    storedValue++;
    EEPROM.write( eepromAddress, storedValue);
  }
  
  byte track = EEPROM.read(eepromAddress);
  //DigiKeyboard.println((int)EEPROM.read(eepromAddress));
  
  return track;
}

