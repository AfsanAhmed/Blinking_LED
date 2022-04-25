#include "ros/ros.h"
#include "std_msgs/Bool.h"
#include <iostream>
using namespace std;


int main(int argc, char **argv) {
    ros::init(argc, argv, "xbox");
    ros::NodeHandle nh;

    ros::Publisher pub= nh.advertise<std_msgs::Bool>("led_status",100);
    ros::Rate loop_rate(1);

    while(ros::ok()){
      std_msgs::Bool msg;
      
      cout << "Press x to set Blinkling LED mode" << endl;
      pub.publish(msg);
      ros::spinOnce();
      loop_rate.sleep();
    }

    
   
   
   
   
    return 0;
}