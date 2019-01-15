
#include <SoftwareSerial.h>
#include <stdlib.h>

//Initialize the Serial Communication 
SoftwareSerial mySerial(10, 11); // RX, TX

void setup() 
{
  
  Serial.begin(9600);
  mySerial.begin(9600);
  pinMode(2,OUTPUT);
    pinMode(3,OUTPUT);

  pinMode(4,OUTPUT);

  digitalWrite(2,LOW);
  
}
void loop()
{
//digitalWrite(3,HIGH);
//digitalWrite(4,HIGH);

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

void sendAck()
{
  digitalWrite(2,HIGH);
  delay(10);
  digitalWrite(2,LOW);
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
  digitalWrite(3,HIGH);
  delay(100);
  digitalWrite(3,LOW);
  delay(100);

}
sendAck();
}

void Y(int n)
{
for (int i=0;i<=n;i++)
{
  digitalWrite(4,HIGH);
  delay(100);
  digitalWrite(4,LOW);
  delay(100);

}
sendAck();
}
  
