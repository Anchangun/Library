#include"ros/ros.h"
#include"ros_service_demo/SrvTutorial.h"
#include<cstdlib>

int main(int argc, char**argv){
	ros::init(argc,argv,"service_client");
	if(argc != 3){
		ROS_INFO("cmd : rosrun ros_demo_service service_client arg0 arg1");
		return 1;
	}
	ros::NodeHandle nh;
	ros::ServiceClient ros_service_demo_client=nh.serviceClient<ros_service_demo::SrvTutorial>("ros_demo_srv");
	
	ros_service_demo::SrvTutorial srv;
	srv.request.a =atoll(argv[1]);
	srv.request.b =atoll(argv[2]);

	if(ros_service_demo_client.call(srv)){
		ROS_INFO("send srv, srv.Request.a and b: %ld, %ld",(long int)srv.request.a,(long)srv.request.b);
		ROS_INFO("receive srv result : %ld",(long int)srv.response.result);
	}
	else{
		ROS_ERROR("Failed to call service ros_service_demo");
		return 1;
	}
	return 0;
}
