
#include <SoftwareSerial.h>
#include <stdlib.h>

//Initialize the Serial Communication 
SoftwareSerial mySerial(10, 11); // RX, TX


void setup() {
  
  Serial.begin(9600);
  mySerial.begin(9600);

  
}

void loop() {

  char num[2];

  //If the data is available serially, then receive it
  if(mySerial.available()>0){
    for(int i= 0 ;i<3;i++){
      num[i] = mySerial.read();
      delay(10);
    }
    
    ;
   
    Serial.print("\n");
    Serial.print(num[0]);
    Serial.print(num[1]);
    Serial.print(num[2]);
      
  
  }
}
