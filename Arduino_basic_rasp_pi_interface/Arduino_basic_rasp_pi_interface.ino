void setup() {
 pinMode(9,INPUT);
 pinMode(13,OUTPUT);
}

void loop() {
if(digitalRead(9)==HIGH)
{
  digitalWrite(13,HIGH);
 }

 else
 {
  digitalWrite(13,LOW);
 }
}
