//#define USE_USBCON  //this statement is incas of arduino due

#include <ros.h>
#include <std_msgs/Bool.h>
#include <std_msgs/Int16.h>
#include <std_msgs/Int16MultiArray.h>
#include <std_msgs/MultiArrayLayout.h>


int echo1= 3;
int echo2=7;
int echo3=22;
int echo4=30;
int echo5=38;
int echo6=46;

////
int trig1=4;
int trig2=8;
int trig3=24;
int trig4=32;
int trig5=40;
int trig6=48;



int vcc1=2,vcc2=6,vcc4=28,vcc5=36,vcc6=44;
int gnd1=5,gnd2=9,gnd3=26,gnd4=34,gnd5=42,gnd6=50;
const int d1=2,d2=.5;
float dur1;
float dur2;
float dur3;
float dur4;
float dur5;
float dur6;

    
ros::NodeHandle nh;
int relay=52;
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
    arr.layout.dim[0].size = 6;
    arr.layout.dim[0].stride = 1*6;
    arr.layout.data_offset = 0;
    arr.data = (int *)malloc(sizeof(int)*6);
    arr.data_length = 6;
   
    pinMode(relay, OUTPUT);
    pinMode(pin,INPUT);
    pinMode(com,OUTPUT);
    digitalWrite(com,HIGH);

    pinMode(trig1,OUTPUT);
    pinMode(trig2,OUTPUT);
    pinMode(trig3,OUTPUT);
    pinMode(trig4,OUTPUT);
    pinMode(trig5,OUTPUT);
    pinMode(trig6,OUTPUT);


    pinMode(echo1,INPUT);
    pinMode(echo2,INPUT);
    pinMode(echo3,INPUT);
    pinMode(echo4,INPUT);
    pinMode(echo5,INPUT);
    pinMode(echo6,INPUT);


    pinMode(vcc1,OUTPUT);
    pinMode(vcc2,OUTPUT);
    //pinMode(vcc3,OUTPUT);
    pinMode(vcc4,OUTPUT);
    pinMode(vcc5,OUTPUT);
    pinMode(vcc6,OUTPUT);


    pinMode(gnd1,OUTPUT);
    pinMode(gnd2,OUTPUT);
    pinMode(gnd3,OUTPUT);
    pinMode(gnd4,OUTPUT);
    pinMode(gnd5,OUTPUT);
    pinMode(gnd6,OUTPUT);

    
    ///////////////////////
    digitalWrite(vcc1,HIGH);
    digitalWrite(vcc2,HIGH);
//    digitalWrite(vcc3,HIGH);
    digitalWrite(vcc4,HIGH);
    digitalWrite(vcc5,HIGH);
    digitalWrite(vcc6,HIGH);

    digitalWrite(gnd1,LOW);
    digitalWrite(gnd2,LOW);
    digitalWrite(gnd3,LOW);
    digitalWrite(gnd4,LOW);
    digitalWrite(gnd5,LOW);
    digitalWrite(gnd6,LOW);
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


    digitalWrite(trig2,HIGH);
    delayMicroseconds(d1);
    digitalWrite(trig2,LOW);
    delayMicroseconds(d2);
    dur2=pulseIn(echo2,HIGH);


    digitalWrite(trig3,HIGH);
    delayMicroseconds(d1);
    digitalWrite(trig3,LOW);
    delayMicroseconds(d2);
    dur3=pulseIn(echo3,HIGH);

    digitalWrite(trig4,HIGH);
    delayMicroseconds(d1);
    digitalWrite(trig4,LOW);
    delayMicroseconds(d2);
    dur4=pulseIn(echo4,HIGH);

    digitalWrite(trig5,HIGH);
    delayMicroseconds(d1);
    digitalWrite(trig5,LOW);
    delayMicroseconds(d2);
    dur5=pulseIn(echo5,HIGH);

    digitalWrite(trig6,HIGH);
    delayMicroseconds(d1);
    digitalWrite(trig6,LOW);
    delayMicroseconds(d2);
    dur6=pulseIn(echo6,HIGH);


    
      //publish////////////
      arr.data[0]=dur1;
      arr.data[1]=dur2;
      arr.data[2]=dur3;
      arr.data[3]=dur4;
      arr.data[4]=dur5;
      arr.data[5]=dur6;

    ultra.publish(&arr);
    nh.spinOnce();
    delay(1);
   }
