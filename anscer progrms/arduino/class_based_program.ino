#include <Adafruit_NeoPixel.h>
#include <Wire.h>                                  //i2c communication header file
#include <ros.h>
#include <std_msgs/Bool.h>                         //power button status
#include <std_msgs/Int16MultiArray.h>              //LED indicator
#include <sensor_msgs/Range.h>                     //Ultra sonic sensor
#define slave1 0000000001
#define slave2 0000000010
#define slave3 0000000011
#define slave4 0000000100
#define slave5 0000000101
#define slave6 0000000110
#define slave7 0000000111
#define data_size 6

ros::NodeHandle nh;

class ultrasonic_sensor
      {
        public:
          sensor_msgs::Range  range_msg1; 
          sensor_msgs::Range  range_msg2;
          sensor_msgs::Range  range_msg3;                                                             //range msg declaration 
          sensor_msgs::Range  range_msg4; 
          sensor_msgs::Range  range_msg5;
          sensor_msgs::Range  range_msg6;
          sensor_msgs::Range  range_msg7;
        public:
          inline void read_data();
                 
      };

inline void ultrasonic_sensor::read_data()
    {
//////////getting data from 1st slave/////////
      
      Wire.requestFrom(slave1, data_size);     // request 6 bytes from slave device1     slave may send less than requested

      while (Wire.available()) 
          { 
           range_msg1.range= Wire.read();     // receive a byte as character
           
          }
      Wire.requestFrom(slave1,data_size,true);

//////////getting data from 2nd slave/////////

      Wire.requestFrom(slave2, data_size);     // request 6 bytes from slave device2     slave may send less than requested

      while (Wire.available()) 
          { 
           range_msg2.range= Wire.read();     // receive a byte as character
           
          }
      Wire.requestFrom(slave2,data_size,true);

//////////getting data from 3rd slave/////////

      Wire.requestFrom(slave3, data_size);     // request 6 bytes from slave device3     slave may send less than requested

      while (Wire.available()) 
          { 
           range_msg3.range= Wire.read();     // receive a byte as character
           
          }
      Wire.requestFrom(slave3,data_size,true);

//////////getting data from 4th slave/////////

      Wire.requestFrom(slave4, data_size);     // request 6 bytes from slave device4     slave may send less than requested

      while (Wire.available()) 
          { 
           range_msg4.range= Wire.read();     // receive a byte as character
           
          }
      Wire.requestFrom(slave4,data_size,true);

//////////getting data from 5th slave/////////

      Wire.requestFrom(slave5, data_size);     // request 6 bytes from slave device5     slave may send less than requested

      while (Wire.available()) 
          { 
           range_msg5.range= Wire.read();     // receive a byte as character
           
          }
      Wire.requestFrom(slave5,data_size,true);

//////////getting data from 6th slave/////////

      Wire.requestFrom(slave6, data_size);     // request 6 bytes from slave device6     slave may send less than requested

      while (Wire.available()) 
          { 
           range_msg6.range= Wire.read();     // receive a byte as character
           
          }
      Wire.requestFrom(slave6,data_size,true);

//////////getting data from 7th slave/////////

      Wire.requestFrom(slave7, data_size);     // request 6 bytes from slave device7     slave may send less than requested

      while (Wire.available()) 
          { 
           range_msg7.range= Wire.read();     // receive a byte as character
           
          }
      Wire.requestFrom(slave7,data_size,true);

     
     
    }

ultrasonic_sensor r;
ros::Publisher ultrasonic1("ultrasonic1",&r.range_msg1);
ros::Publisher ultrasonic2("ultrasonic2",&r.range_msg2);
ros::Publisher ultrasonic3("ultrasonic3",&r.range_msg3);
ros::Publisher ultrasonic4("ultrasonic4",&r.range_msg4);
ros::Publisher ultrasonic5("ultrasonic5",&r.range_msg5);
ros::Publisher ultrasonic6("ultrasonic6",&r.range_msg6);
ros::Publisher ultrasonic7("ultrasonic7",&r.range_msg7);



void setup() 
   {

     nh.initNode();
     Serial.begin(115200);
     nh.advertise(ultrasonic1);
     nh.advertise(ultrasonic2);
     nh.advertise(ultrasonic3);
     nh.advertise(ultrasonic4);
     nh.advertise(ultrasonic5);
     nh.advertise(ultrasonic6);
     nh.advertise(ultrasonic7);
    
    }

void loop() 
    {
  
    }
