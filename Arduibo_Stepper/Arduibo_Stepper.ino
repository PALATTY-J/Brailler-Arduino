const int stepPinX = 8; 
const int dirPinX = 9; 
const int stepPinY = A0; 
const int dirPinY = A1;


const int RX = 10; 
const int TX = 11;

const int LlimitSwitch = 2;
const int LlimitLED=4;

const int RlimitSwitch = 3;
const int RlimitLED=5;

const int solenoidIP1 = 7;
const int solenoidIP2 = 6;

const int ackPin= A5;

#include <SoftwareSerial.h>
#include <stdlib.h>


SoftwareSerial mySerial(RX, TX); // RX, TX


 
void setup() 
{
  pinMode(stepPinX,OUTPUT); 
  pinMode(dirPinX,OUTPUT);
  
  pinMode(stepPinY,OUTPUT); 
  pinMode(dirPinY,OUTPUT);
  
  pinMode(LlimitLED,OUTPUT);
  pinMode(LlimitSwitch,INPUT);
  
  pinMode(solenoidIP1,OUTPUT);
  pinMode(solenoidIP2,OUTPUT);

  pinMode(RlimitLED,OUTPUT);
  pinMode(RlimitSwitch,INPUT);

  pinMode(ackPin,OUTPUT);



  digitalWrite(dirPinX,LOW);
  digitalWrite(dirPinY,LOW);

  digitalWrite(ackPin,HIGH);


  attachInterrupt(digitalPinToInterrupt(RlimitSwitch),resetPosition,LOW);
  initialCalibration();
  mySerial.begin(9600);
   Serial.begin(9600);
  

 
}
void loop()
{

//  for (int x=0;x<=500;x++)
//  {
//    digitalWrite(stepPinY,HIGH); 
//    delayMicroseconds(730); 
//    digitalWrite(stepPinY,LOW); 
//    delayMicroseconds(730);
//  }
//
//  for (int x=0;x<=500;x++)
//  {
//    digitalWrite(stepPinX,HIGH); 
//    delayMicroseconds(500); 
//    digitalWrite(stepPinX,LOW); 
//    delayMicroseconds(500);
//  }

  
   char num[2];

  if(mySerial.available()>0)
  {
    for(int i= 0 ;i<3;i++)
    {
      num[i] = mySerial.read();
      delay(1);
    }

    int tensPlace=dataConversion(num[1]);
    int unitsPlace=dataConversion(num[2]);

    

    int toSend=(tensPlace*10)+(unitsPlace*0);
    
    
    char o=num[0];
    switch (o)
    {
      case 'x':
      Xstepper(toSend);
      break;

      case 'y':
      Ystepper(toSend);
      break;

      case 'z':
      Zsolenoid();
      break;
    }
   
   
    
      
  
}

  

 }

void initialCalibration()
{
  boolean switchVal=digitalRead(LlimitSwitch);


while (switchVal==LOW)
  {
    digitalWrite(stepPinX,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPinX,LOW); 
    delayMicroseconds(500);
    switchVal=digitalRead(LlimitSwitch);
    }
    
digitalWrite(dirPinX,HIGH);
digitalWrite(LlimitLED,HIGH);


}


void resetPosition()
{
  digitalWrite(RlimitLED,HIGH);
  digitalWrite(dirPinX,LOW);
  


  for (int x=0;x<=870;x++)
  {
    digitalWrite(stepPinX,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPinX,LOW); 
    delayMicroseconds(500);
  }

  for (int x=0;x<=18*6;x++)
  {
    digitalWrite(stepPinY,HIGH); 
    delayMicroseconds(730); 
    digitalWrite(stepPinY,LOW); 
    delayMicroseconds(730);
  }
   digitalWrite(dirPinX,HIGH);
   digitalWrite(RlimitLED,LOW);


}

void Xstepper (int rounds)
{
  for (int x=0;x<=(3*rounds);x++)
  {
    digitalWrite(stepPinX,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPinX,LOW); 
    delayMicroseconds(500);
    
  }
  delay(100);
  sendACK();
  
  
}

void Ystepper (int rounds)
{
    digitalWrite(dirPinY,LOW);

  for (int x=0;x<=(18*rounds);x++)
  {
    digitalWrite(stepPinY,HIGH); 
    delayMicroseconds(730); 
    digitalWrite(stepPinY,LOW); 
    delayMicroseconds(730);
    
  }
  delay(100);

  sendACK();
}

void Zsolenoid()
{
  sendACK();
  return;
}


int dataConversion(char XYZ)
{
   
    byte receivedByte=XYZ;
    byte corrected=receivedByte-B110000;
    

    int correctedData=corrected;
    return correctedData;
    
}

void sendACK()
{
  digitalWrite(ackPin,LOW);
  delayMicroseconds(25);
  digitalWrite(ackPin,HIGH);
  
  

  
 
}
  
