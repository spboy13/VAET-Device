void sendGSM()
{
  number = "09777936587";
  text = "Notice: AVRM Triggered";
  error=GSM.sendSms(number,text);
  Serial.println("SMS done");
}

