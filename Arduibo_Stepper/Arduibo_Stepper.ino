const int stepPinX = 8; 
const int dirPinX = 9; 
const int stepPinY = 10; 
const int dirPinY = 11; 

 
void setup() {
  // Sets the two pins as Outputs
  pinMode(stepPinX,OUTPUT); 
  pinMode(dirPinX,OUTPUT);
  pinMode(stepPinY,OUTPUT); 
  pinMode(dirPinY,OUTPUT);
  pinMode(13,OUTPUT);
  pinMode(3,OUTPUT);

  pinMode(2,INPUT);
  digitalWrite(dirPinX,LOW);
  digitalWrite(dirPinY,HIGH);
  initialCalibration();
  

 
}
void loop() {
  
  

  for(int x=0;x<=20;x++)
    {
//    digitalWrite(stepPinY,HIGH); 
//    delayMicroseconds(730); 
//    digitalWrite(stepPinY,LOW); 
//    delayMicroseconds(730);

    digitalWrite(stepPinX,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPinX,LOW); 
    delayMicroseconds(500);

    }

delay(100);
    
 
}

void initialCalibration()
{
  boolean switchVal=digitalRead(2);


while (switchVal==LOW)
  {
    digitalWrite(stepPinX,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPinX,LOW); 
    delayMicroseconds(500);
    switchVal=digitalRead(2);
    }

for(int x=0;x<=20;x++)
{
    digitalWrite(stepPinX,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPinX,LOW); 
    delayMicroseconds(500);

    }
    
digitalWrite(dirPinX,HIGH);
digitalWrite(3,HIGH);


}
