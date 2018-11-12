int RB[14];
#define rx1 9
#define rx2 10
#define ack 8



void setup(void)
{
  Serial.begin(9600);
  pinMode(ack,OUTPUT);
  pinMode(rx1,INPUT);
  pinMode(rx2,INPUT);
  
  
  

}

void loop(void) 

{

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
    digitalWrite(ack,LOW);
   }

for (int i=0;i<=12;i++)
   {
    Serial.print( RB[i] ) ;
   }
 

 
}

void ackjp(void)
{
  digitalWrite(ack,HIGH);
  return 0;
}
