void checkRecognition()
{
  //Serial.println("cehcking");
  int ret;
  ret = myVR.recognize(buf, 50);
  if(ret>0){
    switch(buf[1]){
      case patay: //record 7 to lol
        /** turn on LED */
        digitalWrite(led, LOW);
        break;
      case holdup:
        /** turn off LED*/
        digitalWrite(led, HIGH);
        Serial.println("=== sending message ===");
        sendGSM();
        break;
      case taasKamay:
        /** turn off LED*/
        digitalWrite(led, HIGH);
        Serial.println("=== sending message ===");
        sendGSM();
        break;
      case wagGagalaw:
        /** turn off LED*/
        digitalWrite(led, HIGH);
        Serial.println("=== sending message ===");
        sendGSM();
        break;

      case bigayMo:
        /** turn off LED*/
        digitalWrite(led, HIGH);
        Serial.println("=== sending message ===");
        sendGSM();
        break;

      case wagKikilos:
        /** turn off LED*/
        digitalWrite(led, HIGH);
        Serial.println("=== sending message ===");
        sendGSM();
        break;

      case wagPo:
        /** turn off LED*/
        digitalWrite(led, HIGH);
        Serial.println("=== sending message ===");
        sendGSM();
        break;
      default:
        Serial.println("Record function undefined");
        break;
    }
    /** voice recognized */
    printVR(buf);
  }
}

