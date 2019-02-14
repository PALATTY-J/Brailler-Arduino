volatile int N=469;
void setup() 
{
 pinMode(13,OUTPUT);
 pinMode(12,OUTPUT);
 pinMode(11,INPUT);
 Serial.begin(9600);

 digitalWrite(13,HIGH);


}



void loop() 
{
  
if (digitalRead(11)==HIGH)
{
  
  for (int i=0;i<=47;i++)
  {
    digitalWrite(12,HIGH);
    delayMicroseconds(900);
    digitalWrite(12,LOW);
    delayMicroseconds(900);
  }
  N=N+1;
  Serial.print("N=");
  Serial.print(N);
  Serial.print("\n");
  delay(10);
  

}


  
}
