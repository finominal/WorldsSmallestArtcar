unsigned short eepromAddress = 0;
unsigned int track = 0; 
int totalTracks = 17;




void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    int inByte = Serial.read(); 
    Serial.print("DataRecieved: "); Serial.println(inByte);
    inByte -= 48;
    Serial.print("DataModified: "); Serial.println(inByte);
     if(inByte <=totalTracks-1)
     {
       track = inByte;
       Serial.print("Track Set To "); Serial.println(inByte);
       wtv020sd16p.asyncPlayVoice(track);
     }
     
  } 

}

void CheckForTrackChange()
{
  if(digitalRead(busyPin)==LOW)//busy pin is high when in operation
  {
    PlayNextTrack();
  }
}

void PlayNextTrack()
{
  track = GetNextTrack();
  Serial.print("Playing Track: ");Serial.println(track);

  delay(200);//startup
  wtv020sd16p.reset();
  Serial.println("Reset Audio");
  delay(600);//resetting
  wtv020sd16p.asyncPlayVoice(track);
  Serial.println("Play Audio");
}

  
byte GetNextTrack()
{
  byte storedValue= EEPROM.read( eepromAddress);
  Serial.print("EepromRead: "); Serial.println((int)storedValue);

  if(storedValue >= totalTracks-1)
  {
    Serial.println("ResetEepromTo 0"); 
    EEPROM.write( eepromAddress, 0);//reset the track number
  }
  else
  {
    storedValue++;
    Serial.print("AdvancedEepromTo: "); Serial.println(storedValue);
    EEPROM.write( eepromAddress, storedValue);
  }
  
  byte track = EEPROM.read(eepromAddress);
  
  return track;
}

/*scumfrog 12
 * heq 13
 * emancipator 14
 * epikur 15
 * dnoxbeckers 16
 * 
 * 
 */
