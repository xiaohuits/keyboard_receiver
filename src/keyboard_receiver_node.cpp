/*=======================================================
created by Hui Xiao - University of Connecticut - 2018
hui.xiao@uconn.edu
========================================================*/
#include <iostream>
#include "ros/ros.h"
#include "opencv2/highgui/highgui.hpp"
#include "std_msgs/Int64.h"

int main(int argc, char** argv)
{
    ros::init(argc, argv, "keyboard_receiver");
    ros::NodeHandle nh;
    ros::Publisher msg_pub = nh.advertise<std_msgs::Int64>("key_pressed",3);

    cv::namedWindow("keyboard capturing window",1);
    cv::Mat image = cv::imread("/home/macs/UR3_ws/src/keyboard_receiver/pictures/JonathanStill.jpg");
    std_msgs::Int64 key_msg;
    while(ros::ok())
    {
        cv::imshow("keyboard capturing window",image);
        int key = cv::waitKey(1);
        if (key != -1)
        {
            key_msg.data = key;
            msg_pub.publish(key_msg);
        }
        ros::spinOnce();
    }
}
