#include <Wire.h>
#define slave1 0000000100
#define slave2 0000000011
#define slave3 0000000010
#define slave4 0000000001
#define data_size 6
void setup() 
{
  // put your setup code here, to run once:
Wire.begin();          // Initialize I2C communications as Slave

Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
Wire.requestFrom(slave1, data_size);     // request 6 bytes from slave device1     slave may send less than requested

      while (Wire.available()>0) 
          { 
           int c= Wire.read();     // receive a byte as character                                                                                                                           1
           Serial.println(c);
          }
Wire.requestFrom(slave1,data_size,true);
Wire.requestFrom(slave2, data_size);  
while (Wire.available()>0) 
          { 
           int c= Wire.read();     // receive a byte as character
           //Serial.println(c);
          }
      Wire.requestFrom(slave2,data_size,true);

Wire.requestFrom(slave3, data_size);  
while (Wire.available()>0) 
          { 
           int c= Wire.read();     // receive a byte as character
           //Serial.println(c);
          }
      Wire.requestFrom(slave3,data_size,true);

Wire.requestFrom(slave4, data_size);  
while (Wire.available()>0) 
          { 
           int c= Wire.read();     // receive a byte as character
           Serial.println(c);
          }
      Wire.requestFrom(slave4,data_size,true);
}
