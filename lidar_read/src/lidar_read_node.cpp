#include"ros/ros.h"
#include "sensor_msgs/LaserScan.h"
#include <cmath>
#include <iostream>

void scanCallback(const sensor_msgs::LaserScan::ConstPtr& scan)
{
    float angle_min = scan->angle_min;
    float angle_increment = scan->angle_increment;
    int ranges_size = scan->ranges.size();

    for (int i = 0; i < ranges_size; ++i)
    {
        float distance = scan->ranges[i];                      //mengambil jarak dari array (ranges) pada index ke [i]
        float angle = angle_min + i * angle_increment;         //Sudut awal + i * peningkatan sudut
        
        float adjusted_angle = angle + M_PI;
        if (adjusted_angle > M_PI)
        {
            adjusted_angle -= 2 * M_PI;
        }
        float angle_deg = adjusted_angle * 180.0 / M_PI;
        
        //if(angle_deg >= -90 && angle_deg <= 90)
        if(angle_deg >= -90 && angle_deg <= 90)
        {
            float x = distance * cos(angle);
            float y = distance * sin(angle);

            ROS_INFO("--------------------------------");
            ROS_INFO("Angle: %.2f deg", angle_deg);
            ROS_INFO("Distance: %.2f m", distance);
            ROS_INFO("Coordinates: (%.2f, %.2f)", x, y);
        }
    }
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "lidar_scan_node");
    ros::NodeHandle n;
    ros::Subscriber sub = n.subscribe("/scan", 1000, scanCallback);
    ros::spin();

    return 0;
}


