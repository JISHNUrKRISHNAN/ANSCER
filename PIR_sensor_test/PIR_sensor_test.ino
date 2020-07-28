#include<Wire.h>
int pin = 11;
int led=13;
void setup() {
  pinMode(pin,INPUT);
  pinMode(led,OUTPUT);
  Wire.begin(0000000001);
  Wire.onRequest(requestEvent);
  Serial.begin(9600);

}
void loop()
{delay(100);
}
void requestEvent() 
{
  if(digitalRead(pin)==LOW){
    digitalWrite(led,LOW);
    Wire.write(0);
    
  }
    
  else{
    digitalWrite(led,HIGH);
    Wire.write(1);
  }

}
