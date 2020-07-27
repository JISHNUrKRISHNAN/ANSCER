#include <Wire.h>
#define SLAVE_ADDR 9           // Define Slave I2C Address
#define ANSWERSIZE             // Define Slave answer size


int trigger=8;                 //set digital pin 8  as trigger pin             
int echoe  =9;                 //set digital pin 9  as echoe pin
float duration;
int distance;
const int delay1=2,delay2=.5;

//ultrasonic sensor distance calculation
void ultra()
    {
      digitalWrite(trigger,HIGH);
      delayMicroseconds(delay1);
      digitalWrite(trigger,LOW);
      delayMicroseconds(delay2);
      duration=pulseIn(echoe,HIGH);
      distance=duration*.034/2;
    }

//function to write data to master
void write_to_master() 
    {
       Wire.write(distance);
       // Print to Serial Monitor
       Serial.println("Request event");
    }
 
void setup() 
    {
      Wire.begin(SLAVE_ADDR);          // Initialize I2C communications as Slave
      Wire.onRequest(write_to_master); // Function to run when data requested from master
      Serial.begin(9600);              // Setup Serial Monitor 
  
    }
 
void loop() 
    {
     ultra();
     write_to_master();
     delay(50);
    }
