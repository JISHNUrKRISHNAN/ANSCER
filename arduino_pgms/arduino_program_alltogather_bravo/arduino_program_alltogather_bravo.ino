//#define USE_USBCON  //this statement is incas of arduino due

#include <ros.h>
#include <std_msgs/Bool.h>
#include <std_msgs/Int16.h>
#include <std_msgs/Int16MultiArray.h>
#include <std_msgs/MultiArrayLayout.h>


int trig1= 51;
int trig2=35;
int trig3=27;
////
int echo1=53;
int echo2=33;
int echo3=25;


int vcc1=49,vcc2=37,vcc3=29;
int gnd2=31,gnd3=23;
const int d1=2,d2=.5;
float dur1;
float dur2;
float dur3;
//float dur4;
//float dur5;
//float dur6;

    
ros::NodeHandle nh;
int relay=7;
int pin=10,com=11,button=0;
long start_time=0,end_time=0,diff_time=0;
std_msgs::Bool Status;
std_msgs::Int16MultiArray arr;

void power()
    {
      Status.data=0;
      button=digitalRead(pin);
      if(button==1)
          {
          
          Status.data=1;
          
         }
     
          
    }


void uvlight_callback( const std_msgs::Bool& toggle_msg)
   {
   if( toggle_msg.data==1)
        digitalWrite(relay,HIGH);
    else
        digitalWrite(relay,LOW);


   }
   
   ros::Subscriber<std_msgs::Bool> sub("uvlight", &uvlight_callback );
   ros::Publisher POWER("POWER_BUTTON", &Status);
   ros::Publisher ultra("ultra", &arr);

   void setup()
   {
    nh.initNode();
    Serial.begin(115200);
    nh.subscribe(sub);
    nh.advertise(POWER);
    nh.advertise(ultra);


    
    arr.layout.dim = (std_msgs::MultiArrayDimension *)
    malloc(sizeof(std_msgs::MultiArrayDimension)*2);
    arr.layout.dim[0].label = "data";
    arr.layout.dim[0].size = 3;
    arr.layout.dim[0].stride = 1*3;
    arr.layout.data_offset = 0;
    arr.data = (int *)malloc(sizeof(int)*3);
    arr.data_length = 3;
   
    pinMode(relay, OUTPUT);
    pinMode(pin,INPUT);
    pinMode(com,OUTPUT);
    digitalWrite(com,HIGH);

    pinMode(trig1,OUTPUT);
    pinMode(trig2,OUTPUT);
    pinMode(trig3,OUTPUT);


    pinMode(echo1,INPUT);
    pinMode(echo2,INPUT);
    pinMode(echo3,INPUT);

    pinMode(vcc1,OUTPUT);
    pinMode(vcc2,OUTPUT);
    pinMode(vcc3,OUTPUT);


//    pinMode(gnd1,OUTPUT);
    pinMode(gnd2,OUTPUT);
    pinMode(gnd3,OUTPUT);

    
    ///////////////////////
    digitalWrite(vcc1,HIGH);
    digitalWrite(vcc2,HIGH);
    digitalWrite(vcc3,HIGH);
    //digitalWrite(vcc4,HIGH);
//    digitalWrite(vcc5,HIGH);
//    digitalWrite(vcc6,HIGH);

//    digitalWrite(gnd1,LOW);
    digitalWrite(gnd2,LOW);
    digitalWrite(gnd3,LOW);
//    digitalWrite(gnd4,LOW);
//    digitalWrite(gnd5,LOW);
//    digitalWrite(gnd6,LOW);
   }
   void loop()
   {
     power();
     
     POWER.publish(&Status);
     digitalWrite(trig1,HIGH);
    delayMicroseconds(d1);
    digitalWrite(trig1,LOW);
    delayMicroseconds(d2);
    dur1=pulseIn(echo1,HIGH);
//    Serial.print("dur1");
//Serial.print(dur1);

    digitalWrite(trig2,HIGH);
    delayMicroseconds(d1);
    digitalWrite(trig2,LOW);
    delayMicroseconds(d2);
    dur2=pulseIn(echo2,HIGH);
//  Serial.print("dur2");
// Serial.print(dur2);

    digitalWrite(trig3,HIGH);
    delayMicroseconds(d1);
    digitalWrite(trig3,LOW);
    delayMicroseconds(d2);
    dur3=pulseIn(echo3,HIGH);
//Serial.print("dur3");
//
//  Serial.println(dur3);

    
      //publish////////////
      arr.data[0]=dur1;
      arr.data[1]=dur2;
      arr.data[2]=dur3;

    ultra.publish(&arr);
    nh.spinOnce();
    delay(1);
   }
