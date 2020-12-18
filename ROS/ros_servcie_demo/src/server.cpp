#include"ros/ros.h"
#include"ros_service_demo/SrvTutorial.h"

bool calculation(ros_service_demo::SrvTutorial::Request &req, ros_service_demo::SrvTutorial::Response &res){
	res.result=req.a+req.b;
	ROS_INFO("request : x=%ld, y=%ld",(long int)req.a,(long int)req.b);
	ROS_INFO("sending back response: %ld",(long int)res.result);
	return true;
}

int main(int argc,char**argv){
	ros::init(argc,argv,"service_server");
	ros::NodeHandle nh;
	ros::ServiceServer ros_service_demo_server=nh.advertiseService("ros_demo_srv",calculation);
	ROS_INFO("ready srv server!");
	ros::spin();
	return 0;
}

