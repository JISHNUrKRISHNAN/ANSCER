#define USE_USBCON  //this statement is incas of arduino due

#include <Adafruit_NeoPixel.h>
#include <Wire.h>
#include <ros.h>
#include <std_msgs/Bool.h>
#include <std_msgs/Int16MultiArray.h>
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

sensor_msgs::Range  range_msg1; 
sensor_msgs::Range  range_msg2;
sensor_msgs::Range  range_msg3;                                                             //range msg declaration 
sensor_msgs::Range  range_msg4; 
sensor_msgs::Range  range_msg5;
sensor_msgs::Range  range_msg6;
sensor_msgs::Range  range_msg7;


#define LED_PIN1  45
#define LED_PIN2  46
#define LED_COUNT 7
int d1=0,d2=0,d3=255,d4=255,d5=0,d6=0;


Adafruit_NeoPixel strip1 = Adafruit_NeoPixel(LED_COUNT, LED_PIN1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip2 = Adafruit_NeoPixel(LED_COUNT, LED_PIN2, NEO_GRB + NEO_KHZ800);


ros::NodeHandle nh;
int relay=7;
int pin=5,com=6,button=0,flag=0;
long start_time=0,end_time=0,diff_time=0;
std_msgs::Bool Status;

////callback function for led indication
inline void light_indication_callback(const std_msgs::Int16MultiArray& arr)
    {
      d1=arr.data[0];
      d2=arr.data[1];
      d3=arr.data[2];
      d4=arr.data[3];
      d5=arr.data[4];
      d6=arr.data[5];
      indication();
    }

inline void indication()
    {
     for(int i=0;i<7;i++)
        {
          strip1.setPixelColor(i, d1, d2,d3);
          
          strip1.show();


        }



     
     for(int i=0;i<15;i++)
        {
          strip2.setPixelColor(i, d4, d5,d6);
          strip2.show();

        }
    
    }

inline void read_data()
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

///////////////function for turning of the system using power button///////////////    
inline void power_button()
    {
      Status.data=0;
      button=digitalRead(pin);
      if(button==1)
          {
          
          button=digitalRead(pin);
          if(button==1&&flag==0)
            {
             start_time=millis();
             flag=1;
            }
          if(button==1&&diff_time<=5000)
             {
              end_time=millis();
              diff_time=end_time-start_time;
             }
           else
            {
              end_time=0;
              flag=0;
              diff_time=0;
              
            }

          }
          
      if(diff_time>=4900)
         {
          Status.data=1;
          
         }
    }

inline void uvlight_callback( const std_msgs::Bool& toggle_msg)
   {
   if( toggle_msg.data==1)
        digitalWrite(relay,HIGH);
    else
        digitalWrite(relay,LOW);


   }


std_msgs::Int16MultiArray arr;

ros::Subscriber<std_msgs::Bool> sub("uvlight", &uvlight_callback );
ros::Subscriber<std_msgs::Int16MultiArray>light("light", &light_indication_callback);
ros::Publisher POWER("POWER_BUTTON", &Status);
ros::Publisher ultrasonic1("ultrasonic1",&range_msg1);
ros::Publisher ultrasonic2("ultrasonic2",&range_msg2);
ros::Publisher ultrasonic3("ultrasonic3",&range_msg3);
ros::Publisher ultrasonic4("ultrasonic4",&range_msg4);
ros::Publisher ultrasonic5("ultrasonic5",&range_msg5);
ros::Publisher ultrasonic6("ultrasonic6",&range_msg6);
ros::Publisher ultrasonic7("ultrasonic7",&range_msg7);




void setup() 
    {

        range_msg1.header.frame_id="front_left";
        range_msg1.range=0.0;
        range_msg1.radiation_type=1;
        range_msg1.field_of_view=15;
        range_msg1.min_range=2;
        range_msg1.max_range=400.;

        range_msg2.header.frame_id="front_centre";
        range_msg2.range=0.0;
        range_msg2.radiation_type=1;
        range_msg2.field_of_view=15;
        range_msg2.min_range=2;
        range_msg2.max_range=400.;

        range_msg3.header.frame_id="front_right";
        range_msg3.range=0.0;
        range_msg3.radiation_type=1;
        range_msg3.field_of_view=15;
        range_msg3.min_range=2;
        range_msg3.max_range=400.;

        range_msg4.header.frame_id="back_left";
        range_msg4.range=0.0;
        range_msg4.radiation_type=1;
        range_msg4.field_of_view=15;
        range_msg4.min_range=2;
        range_msg4.max_range=400.;

        range_msg5.header.frame_id="back_centre";
        range_msg5.range=0.0;
        range_msg5.radiation_type=1;
        range_msg5.field_of_view=15;
        range_msg5.min_range=2;
        range_msg5.max_range=400.;
        
        range_msg6.header.frame_id="back_right";
        range_msg6.range=0.0;
        range_msg6.radiation_type=1;
        range_msg6.field_of_view=15;
        range_msg6.min_range=2;
        range_msg6.max_range=400.;

     strip1.begin();
     strip1.show();
     strip2.begin();
     strip2.show();
     nh.initNode();
     Serial.begin(115200);             //this same baud rate has to be used in main processor program
     nh.subscribe(sub);                //subscriber for UV light
     nh.subscribe(light);                //subscriber for UV light
     nh.advertise(POWER);              //publisher for power button
//     nh.advertise(ultra);              //publisher  for ultrasonic
     nh.advertise(ultrasonic1);
     nh.advertise(ultrasonic2);
     nh.advertise(ultrasonic3);
     nh.advertise(ultrasonic4);
     nh.advertise(ultrasonic5);
     nh.advertise(ultrasonic6);
     nh.advertise(ultrasonic7);
     
     
     

    //pin declaration
     pinMode(relay, OUTPUT);
     pinMode(pin,INPUT);
     pinMode(com,OUTPUT);
     digitalWrite(com,HIGH);
     Wire.begin();                     // join i2c bus (address optional for master)
     
    }

void loop()  
    {
      button=0;
      button=digitalRead(pin);
      if(button==1)
        {
          power_button;
        }
      POWER.publish(&Status);
      read_data();

      
      //ultra.publish(&arr);
      ultrasonic1.publish(&range_msg1);
      ultrasonic2.publish(&range_msg2);
      ultrasonic3.publish(&range_msg3);
      ultrasonic4.publish(&range_msg4);
      ultrasonic5.publish(&range_msg5);
      ultrasonic6.publish(&range_msg6);
      ultrasonic7.publish(&range_msg7);

//indication();


      nh.spinOnce();
      delay(1);
    }
