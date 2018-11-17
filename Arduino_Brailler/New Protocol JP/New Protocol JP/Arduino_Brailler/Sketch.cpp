/*Begining of Auto generated code by Atmel studio */
#include <Arduino.h>

/*End of auto generated code by Atmel studio */


//Beginning of Auto generated function prototypes by Atmel Studio
void setup(void );
void loop(void );
void ackjp(void );
//End of Auto generated function prototypes by Atmel Studio

int RB[14];
#define rx1 9
#define rx2 10
#define ack 8
#define mode 11


void setup(void)
{
  Serial.begin(9600);
  pinMode(ack,OUTPUT);
  pinMode(rx1,INPUT);
  pinMode(rx2,INPUT);
  pinMode(mode,INPUT);
 
  
  
  

}

void loop(void) 

{


while (digitalRead(mode)==HIGH)
{
   Serial.print("Transmission Begins");
   for (int i=0;i<=12;i+2)
   {
    if (digitalRead(rx1)==HIGH)
    {
      RB[i]=1;
    }
    else
    {
      RB[i]=0;
    }

    
    if (digitalRead(rx2)==HIGH)
    {
      RB[i+1]=1;
    }
     else
    {
      RB[i+1]=0;
    }
    ackjp();
    Serial.print(RB[i]);
    Serial.print(RB[i+1]);
    Serial.print("\n End OF PAcKET RECEPTION");

    digitalWrite(ack,LOW);
    break;
   }

Serial.print("\n IAM OUT");
 
}
 Serial.print("\n IAM OUT");

}

void ackjp(void)
{
  digitalWrite(ack,HIGH);
  
}
