
#include <SoftwareSerial.h>
#include <stdlib.h>

const int ACKpin=2;

const int stepPinX = 8; 
const int dirPinX = 9;
 
const int stepPinY = A0; 
const int dirPinY = A1;


SoftwareSerial mySerial(10, 11); // RX, TX

void setup() 
{
  pinMode(stepPinX,OUTPUT); 
  pinMode(dirPinX,OUTPUT);
  
  pinMode(stepPinY,OUTPUT); 
  pinMode(dirPinY,OUTPUT);


  pinMode(ACKpin,OUTPUT);

  digitalWrite(dirPinX,HIGH);
  digitalWrite(dirPinY,LOW);

  digitalWrite(ACKpin,LOW);
  
  Serial.begin(9600);
  mySerial.begin(9600);
  
 
  
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
for (int i=0;i<=3*n;i++)
{
  digitalWrite(stepPinX,HIGH); 
  delayMicroseconds(500); 
  digitalWrite(stepPinX,LOW); 
  delayMicroseconds(500);
}


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
  
