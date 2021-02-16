/**
  ******************************************************************************
  * @file    vr_sample_control_led.ino
  * @author  JiapengLi
  * @brief   This file provides a demostration on 
              how to control led by using VoiceRecognitionModule
  ******************************************************************************
  * @note:
        voice control led
  ******************************************************************************
  * @section  HISTORY
    
    2013/06/13    Initial version.
  */
  
#include <SoftwareSerial.h>
#include "VoiceRecognitionV3.h"

//gsm
#include <Sim800L.h>
#include <SoftwareSerial.h>               

#define RX  10
#define TX  11

Sim800L GSM(RX, TX);

char* text;
char* number;
bool error;           //to catch the response of 

/**        
  Connection
  Arduino    VoiceRecognitionModule
   2   ------->     TX
   3   ------->     RX
*/
VR myVR(9,8);    // 2:RX 3:TX, you can choose your favourite pins.

uint8_t records[7]; // save record
uint8_t buf[64];

int led = 13;

#define patay    (7)
#define holdup   (1) 
#define taasKamay   (2)
#define wagGagalaw   (3)
#define bigayMo   (4)
#define wagKikilos   (5)
#define wagPo   (6)



void setup()
{

  //gsm initialize
  GSM.begin(4800);       
  text="ma tulong";     //text for the message. 
  number="09494553385";     //change to a valid number.


  
  //AVRM initialize
  myVR.begin(9600);
  loadRecords();
  
  Serial.begin(115200);
  
  pinMode(led, OUTPUT);
    
}

void loop()
{
  int ret;
  ret = myVR.recognize(buf, 50);
  if(ret>0){
    switch(buf[1]){
      case patay:
        /** turn on LED */
        digitalWrite(led, LOW);
        break;
      case holdup:
        /** turn off LED*/
        digitalWrite(led, HIGH);
        Serial.println("=== sending message ===");
        error=GSM.sendSms(number,text);
        break;
      case taasKamay:
        /** turn off LED*/
        digitalWrite(led, HIGH);
        Serial.println("=== sending message ===");
        error=GSM.sendSms(number,text);
        break;
      case wagGagalaw:
        /** turn off LED*/
        digitalWrite(led, HIGH);
        Serial.println("=== sending message ===");
        error=GSM.sendSms(number,text);
        break;

      case bigayMo:
        /** turn off LED*/
        digitalWrite(led, LOW);
        break;

      case wagKikilos:
        /** turn off LED*/
        digitalWrite(led, HIGH);
        Serial.println("=== sending message ===");
        error=GSM.sendSms(number,text);
        break;

      case wagPo:
        /** turn off LED*/
        digitalWrite(led, HIGH);
        Serial.println("=== sending message ===");
        error=GSM.sendSms(number,text);
        break;
      default:
        Serial.println("Record function undefined");
        break;
    }
    /** voice recognized */
    printVR(buf);
  }
}



