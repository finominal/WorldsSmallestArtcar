
byte GetTrack()
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
