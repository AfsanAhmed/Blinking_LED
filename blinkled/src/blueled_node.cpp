#include "ros/ros.h"        // Need Ros library 
#include "std_msgs/Bool.h"  // Topic Bool type
#include "wiringPi.h"     // Need wiringPi Library for Gpio connection. Add -lwiringPi in target link(Cmakelists.txt)
#include <iostream>
using namespace std;       

#define Blue_LED 23;      // BCM pin 13 is used (WiringPi nr 23). If port changes, Just change the portnumber here.




void setLEDmode(const std_msgs::Bool::ConstPtr &msg){            //function to response setmode topic.

    std_msgs::Bool message;
    //bool led=false;                                           
    message.data=msg->data;
    
    
    //ros::Rate loop_rate(1);                                      //set Up Frequency to 1Hz.
   
      if(message.data == 1)
      {
          while(ros::ok())
              {
                  //led=true;                                     
                  digitalWrite(Blue_LED, HIGH);               //Led turns On.
                   cout << "blue led is on " << endl;
                  delay(500);                                 //remains On for 0,5 seconds.
                  
                  //led=false;
                  digitalWrite(Blue_LED, LOW);                 //Led turns Off.
                    cout << "blue led is off" << endl;
                  delay(500);                                 // reamins Off for 0.5 seconds.
                  
                  ros::spinOnce();

              }
          }


          else if(message.data == 0){

                 digitalWrite(Blue_LED, LOW);
                   cout<<"blue led is off"<< endl;            // Led Turns Off.
                 pinMode(Blue_LED, INPUT);                    // Blue led set to Input mode again.
                 ros::shutdown();                             // Termination of the node.
          } 


          else{
                   cout<<"TYPE TRUE/FALSE TO TURN LED ON/OFF" << endl;
                 ros::spinOnce();
              
          }
          
        
    }





  
int main(int argc, char **argv) {                            //Main Funstion
 
           ros::init(argc, argv, "blueled");   
           ROS_INFO("BlueLED Node Started");
           wiringPiSetup();                                  // initial set up for WiringPi.
           pinMode(Blue_LED, OUTPUT);                        //Blue led set to Output mode.                     //Initialize New Ros Node.
    
           ros::NodeHandle handler;
           ros::Subscriber sub= handler.subscribe<std_msgs::Bool>("led_status", 100, setLEDmode ); //subscribing the topic led_status with setLEDmode function.


           ros::spin();

      return 0;
}
