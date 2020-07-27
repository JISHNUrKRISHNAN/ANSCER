#include <ros.h>
#include <std_msgs/Bool.h>
    
ros::NodeHandle nh;
int relay=52;

void uvlight_callback( const std_msgs::Bool& toggle_msg)
   {
   if( toggle_msg.data==1)
        digitalWrite(relay,HIGH);
    else
        digitalWrite(relay,LOW);


   }
   
   ros::Subscriber<std_msgs::Bool> sub("uvlight", &uvlight_callback );
   
   void setup()
   {
   
    nh.initNode();
    nh.subscribe(sub);
    Serial.begin(115200);
    pinMode(relay, OUTPUT);
   }
   void loop()
   {
     
     Serial.print("hello");
     nh.spinOnce();
     delay(1);

   }
