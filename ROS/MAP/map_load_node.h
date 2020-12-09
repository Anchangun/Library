#include<iostream>
#include "ros/ros.h"
#include "nav_msgs/OccupancyGrid.h"
class MapLoad{
private :
	bool loop_check;
	std::string map_topic;
	void mapCallBack(const nav_msgs::OccupancyGrid::ConstPtr &grid);
	ros::NodeHandle node;
	ros::Subscriber sub_map;
public :
	MapLoad();
	void mapLoadRun();
};
