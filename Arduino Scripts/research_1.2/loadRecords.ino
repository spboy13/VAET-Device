void loadRecords()
{
  if(myVR.clear() == 0){
    Serial.println("Recognizer cleared.");
  }
  
  else{
    Serial.println("Not find VoiceRecognitionModule.");
    Serial.println("Please check connection and restart Arduino.");
    while(1);
  }
  
  if(myVR.load((uint8_t)patay) >= 0){
    Serial.println("onRecord loaded");
  }
  
  if(myVR.load((uint8_t)holdup) >= 0){
    Serial.println("offRecord loaded");
  }

  if(myVR.load((uint8_t)taasKamay) >= 0){
    Serial.println("offRecord loaded");
  }

  if(myVR.load((uint8_t)wagGagalaw) >= 0){
    Serial.println("offRecord loaded");
  }

  if(myVR.load((uint8_t)bigayMo) >= 0){
    Serial.println("offRecord loaded");
  }

  if(myVR.load((uint8_t)wagKikilos) >= 0){
    Serial.println("offRecord loaded");
  }

  if(myVR.load((uint8_t)wagPo) >= 0){
    Serial.println("offRecord loaded");
  }

  
}

