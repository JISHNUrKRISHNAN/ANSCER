#define USE_USBCON  //this statement is incas of arduino due

#include <Wire.h>
#include <ros.h>
#include <std_msgs/Int16MultiArray.h>
#include<std_msgs/Int16.h>
#include <sensor_msgs/Range.h>
//////////////////define slve id////////////
#define slave1 0000000001
#define slave2 0000000010
#define slave3 0000000011
#define slave4 0000000100
#define slave5 0000000101
#define slave6 0000000110
#define slave7 0000000111
#define data_size 6
#define buzzerpin 44


int flag=0;


ros::NodeHandle nh;
bool pir1,pir2,pir3,pir4,pir5,pir6,pir7;
inline void read_data()
    {
//////////getting data from 1st slave/////////
      
      Wire.requestFrom(slave1, data_size);     // request 6 bytes from slave device1     slave may send less than requested

      while (Wire.available()) 
          { 
           pir1= Wire.read();     // receive a byte as character
           
          }
      Wire.requestFrom(slave1,data_size,true);

//////////getting data from 2nd slave/////////

      Wire.requestFrom(slave2, data_size);     // request 6 bytes from slave device2     slave may send less than requested

      while (Wire.available()) 
          { 
           pir2= Wire.read();     // receive a byte as character
           
          }
      Wire.requestFrom(slave2,data_size,true);

//////////getting data from 3rd slave/////////

      Wire.requestFrom(slave3, data_size);     // request 6 bytes from slave device3     slave may send less than requested

      while (Wire.available()) 
          { 
           pir3= Wire.read();     // receive a byte as character
           
          }
      Wire.requestFrom(slave3,data_size,true);

//////////getting data from 4th slave/////////

      Wire.requestFrom(slave4, data_size);     // request 6 bytes from slave device4     slave may send less than requested

      while (Wire.available()) 
          { 
           pir4= Wire.read();     // receive a byte as character
           
          }
      Wire.requestFrom(slave4,data_size,true);

//////////getting data from 5th slave/////////

      Wire.requestFrom(slave5, data_size);     // request 6 bytes from slave device5     slave may send less than requested

      while (Wire.available()) 
          { 
           pir5= Wire.read();     // receive a byte as character
           
          }
      Wire.requestFrom(slave5,data_size,true);

//////////getting data from 6th slave/////////

      Wire.requestFrom(slave6, data_size);     // request 6 bytes from slave device6     slave may send less than requested

      while (Wire.available()) 
          { 
           pir6= Wire.read();     // receive a byte as character
           
          }
      Wire.requestFrom(slave6,data_size,true);

//////////getting data from 7th slave/////////

      Wire.requestFrom(slave7, data_size);     // request 6 bytes from slave device7     slave may send less than requested

      while (Wire.available()) 
          { 
           pir7= Wire.read();     // receive a byte as character
           
          }
      Wire.requestFrom(slave7,data_size,true);
     
    }


std_msgs::Int16MultiArray PIR;

ros::Publisher ultra("ultra", &PIR);
void setup() 
    {
  PIR.layout.dim = (std_msgs::MultiArrayDimension *)
    malloc(sizeof(std_msgs::MultiArrayDimension)*2);
    PIR.layout.dim[0].label = "height";
  PIR.layout.dim[0].size = 7;
  PIR.layout.dim[0].stride = 1,6;
  PIR.layout.data_offset = 0;
  //PIR.data = (int *)malloc(sizeof(int)*8);
  PIR.data_length = 7;
        
     nh.initNode();
     Serial.begin(115200);             //this same baud rate has to be used in main processor program
     
     Wire.begin();                     // join i2c bus (address optional for master)
     
    }

void loop()  
    {
      if(pir1==1)
        {
          flag=1;
          digitalWrite(buzzerpin,HIGH);
          Serial.println(pir1);
        }
      else
          digitalWrite(buzzerpin,LOW);
      PIR.data[0]=pir1;
      PIR.data[1]=pir2;
      PIR.data[2]=pir3;
      PIR.data[3]=pir4;
      PIR.data[4]=pir5;
      PIR.data[5]=pir6;
      PIR.data[6]=pir7;
      
      
      
      nh.spinOnce();
      delay(1);
    }
