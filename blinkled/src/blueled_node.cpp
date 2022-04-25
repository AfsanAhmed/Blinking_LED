#include "ros/ros.h"        // Need Ros library 
#include "std_msgs/Bool.h"  // Topic Bool type
//#include "wiringPi.h"     // Need wiringPi Library for Gpio connection. Add -lwiringPi in target link(Cmakelists.txt)
#include <iostream>
using namespace std;       

#define Blue_LED 13;      // Gpio pin 13 is used . If port changes, Just change the portnumber here.
#define LED_On 0;         // True =0 
#define LED_Off 1;        //False =1



void setLEDmode(const std_msgs::Bool::ConstPtr &msg){            //function to response setmode topic.

    std_msgs::Bool message;
    bool led=false;                                        
    message.data=msg->data;
    //wiringPiSetup();                                           // initial set up for WiringPi.
    //pinMode(Blue_LED, OUTPUT);                                 //Blue led set to Output mode.
    
    
    ros::Rate loop_rate(1);                                      //set Up Frequency to 1Hz.
   
          if(true == message.data)
          {
              while(ros::ok())
              {
                  led=true;                                     
                  //digitalWrite(Blue_LED, LED_On;               //Led turns On.
                  cout << "blue led is on " << endl;
                  //delay(500);                                 //remains On for 0,5 seconds.
                  
                  led=false;
                  //digitalWrite(Blue_LED, LED_Off);            //Led turns Off.
                  cout << "blue led is off" << endl;
                  //delay(500);                                 // reamins Off for 0.5 seconds.
                  
                  ros::spinOnce();

              }
          }


          else if(false == message.data){
              
                cout<<"blue led is off"<< endl;
                 //digitalWrite(Blue_LED, LED_Off);            // Led Turns Off.
                 //pinMode(Blue_LED, INPUT);                   // Blue led set to Input mode again.
                ros::shutdown();                               // Termination of the node.
          } 


          else{


              cout<<"blue led is off" << led << endl;
              ros::spinOnce();
              
          }
          
        
    }





  
int main(int argc, char **argv) {                            //Main Funstion
 
    ros::init(argc, argv, "blueled");                        //Initialize New Ros Node.
    ros::NodeHandle handler;

    ros::Subscriber sub= handler.subscribe<std_msgs::Bool>("led_status", 100, setLEDmode );


    ros::spin();

    return 0;
}
