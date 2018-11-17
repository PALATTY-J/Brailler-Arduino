const int stepPinX = 8; 
const int dirPinX = 9; 
const int stepPinY = 10; 
const int dirPinY = 11;

const int LlimitSwitch = 2;
const int LlimitLED=4;

const int RlimitSwitch = 3;
const int RlimitLED=5;

const int solenoidIP1 = 7;
const int solenoidIP2 = 6;


 
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



  digitalWrite(dirPinX,LOW);
  digitalWrite(dirPinY,LOW);

  attachInterrupt(digitalPinToInterrupt(RlimitSwitch),resetPosition,LOW);
  initialCalibration();
  

 
}
void loop() {
  
  

  for(int x=0;x<=100;x++)
    {

    digitalWrite(stepPinX,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPinX,LOW); 
    delayMicroseconds(500);

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
