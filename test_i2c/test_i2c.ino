#include <Wire.h>
#define SLAVE_ADDR 0000000001           // Define Slave I2C Address
#define ANSWERSIZE   




int trigger=9;
int echo=11;
float distance,duration;
int Distance;

void write_to_master() 
    {
       if(distance<=50&&distance>10)
       {
         Distance=1;
         digitalWrite(13,HIGH);

       }
       else
       {
         Distance=0;         
         digitalWrite(13,LOW);

       }
       Wire.write(Distance);
       // Print to Serial Monitor
       Serial.println("Request event");
    }




void setup() {
  // put your setup code here, to run once:
      pinMode(13,OUTPUT);
      pinMode(echo,INPUT);
      pinMode(trigger,OUTPUT);
      Wire.begin(SLAVE_ADDR);          // Initialize I2C communications as Slave
      Wire.onRequest(write_to_master); // Function to run when data requested from master
      Serial.begin(115200);              // Setup Serial Monito
      }

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(trigger,LOW);
 delayMicroseconds(2);
 digitalWrite(trigger,HIGH);
 delayMicroseconds(10);
 digitalWrite(trigger,LOW);
 delayMicroseconds(2);
 duration=pulseIn(echo,HIGH);
 distance=duration*0.0340/2;
 
 //Serial.println(distance);
 write_to_master();
 delay(10);

}
