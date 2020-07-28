int led=13;

 int pin = 11;  
void setup() {
//  Wire.begin(0000000001);                // join i2c bus with address #8
//  Wire.onRequest(requestEvent); 
//   Serial.begin(9600);
   pinMode(pin, INPUT);
   pinMode(led,OUTPUT);
  Serial.begin(9600);

}
void loop() {
  if(digitalRead(pin)==LOW){
     Serial.println("0");//not detected
     digitalWrite(led,LOW);
  }
    
  else
  {
    Serial.println("1");//motion detected 
    digitalWrite(led,HIGH);
  }
}
