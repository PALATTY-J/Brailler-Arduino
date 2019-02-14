
#include <SoftwareSerial.h>
#include <stdlib.h>

const int ACKpin=12;

const int stepPinX = 8; 
const int dirPinX = 9;
 
const int stepPinY = A0; 
const int dirPinY = A1;

const int rightSwitch = 2; 
const int leftSwitch = A2;

const int solenoidPin=13;


SoftwareSerial mySerial(10, 11); // RX, TX

void setup() 
{
  pinMode(stepPinX,OUTPUT); 
  pinMode(dirPinX,OUTPUT);
  
  pinMode(stepPinY,OUTPUT); 
  pinMode(dirPinY,OUTPUT);


  pinMode(ACKpin,OUTPUT);

  pinMode(leftSwitch,INPUT);
  pinMode(rightSwitch,INPUT); 

  pinMode(solenoidPin,OUTPUT);

  digitalWrite(dirPinX,HIGH);
  digitalWrite(dirPinY,LOW);

  digitalWrite(ACKpin,LOW);

  
   mySerial.begin(9600);
   


   attachInterrupt(digitalPinToInterrupt(rightSwitch),resetPosition,HIGH);

 }
 
void loop()
{

char num[2];
int tensplace=0;
int unitsplace=0;
int tosend=0;

  if(mySerial.available()>0)
  {
    for(int i= 0 ;i<3;i++)
    {
      num[i] = mySerial.read();
      delay(10);
    }
tensplace=10*(dataConversion(num[1]));
unitsplace=dataConversion(num[2]);
tosend=tensplace+unitsplace;
Serial.print("\n");
Serial.print(tosend);
Serial.print("\n");
Serial.print(num);

  }



if (tosend!=0)
{
 char o=num[0];
    switch (o)
    {
      case 'x':
      X(tosend);
      break;

      case 'y':
      Y(tosend);
      break;

      case 'z':
      Z(tosend);
      break;

      case 's':
      initialCalibration();
      break;
      

    }
 
  }
}


void sendAck()
{
  digitalWrite(ACKpin,HIGH);
  delay(1);
  digitalWrite(ACKpin,LOW);
}

int dataConversion(char XYZ)
{
   
    byte receivedByte=XYZ;
    byte corrected=receivedByte-B110000;
    

    int correctedData=corrected;
    return correctedData;
    
}

void X(int n)
{
for (int i=0;i<=n;i++)
{
  digitalWrite(stepPinX,HIGH); 
  delayMicroseconds(500); 
  digitalWrite(stepPinX,LOW); 
  delayMicroseconds(500);
}

checkForSpace();
sendAck();
}

void Y(int n)
{
for (int i=0;i<=18*n;i++)
{
  digitalWrite(stepPinY,HIGH); 
  delayMicroseconds(500); 
  digitalWrite(stepPinY,LOW); 
  delayMicroseconds(500);
}
sendAck();
}

void Z(int n)
{
  if (n==1)
  {
    digitalWrite(solenoidPin,HIGH);
    delay(200);
    digitalWrite(solenoidPin,LOW);
  }

   sendAck();

}

  void initialCalibration()
{
  digitalWrite(dirPinX,LOW);

  boolean switchVal=digitalRead(leftSwitch);


while (switchVal==HIGH)
  {
    digitalWrite(stepPinX,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPinX,LOW); 
    delayMicroseconds(500);
    switchVal=digitalRead(leftSwitch);
    
    }
    
   digitalWrite(dirPinX,HIGH);

    for(int i=0;i<16;i++)
   {
    digitalWrite(stepPinX,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPinX,LOW); 
    delayMicroseconds(500);

   }
   sendAck();
   
   }

    


void resetPosition()
{
  
  digitalWrite(dirPinX,LOW);
  boolean VAL;
  VAL=digitalRead(leftSwitch);


while (VAL==1)
  {
    digitalWrite(stepPinX,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPinX,LOW); 
    delayMicroseconds(500);
    VAL=digitalRead(leftSwitch);
  }
   
  
   digitalWrite(dirPinX,HIGH);

   for(int i=0;i<=3*5;i++)
   {
    digitalWrite(stepPinX,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPinX,LOW); 
    delayMicroseconds(500);
   }

   }
void checkForSpace()
{
  for (int i=0;i<=3*10;i++)
  {
    digitalWrite(stepPinX,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPinX,LOW); 
    delayMicroseconds(500);
  }
   
 digitalWrite(dirPinX,LOW);

 for (int i=0;i<=3*10;i++)
  {
    digitalWrite(stepPinX,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPinX,LOW); 
    delayMicroseconds(500);
  }
 digitalWrite(dirPinX,HIGH);

}
