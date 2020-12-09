#include"map_load_node.h"

MapLoad::MapLoad(){
	map_topic="/map";
	loop_check=false;
}

void MapLoad::mapCallBack(const nav_msgs::OccupancyGrid::ConstPtr &grid){
	std::cout<<"map_data_test_msgCall"<<std::endl;
	std::cout<<"map : position_x : "<< grid->info.origin.position.x<<std::endl;
	std::cout<<"map : data_size : "<<sizeof(grid->data)<<std::endl;
	std::cout<<"map : data : " << grid->data[0]<<std::endl;
	std::cout<<"map_data_test_end"<<std::endl;
	loop_check=true;
}

void MapLoad::mapLoadRun(){
	sub_map=node.subscribe<nav_msgs::OccupancyGrid>(map_topic,10,&MapLoad::mapCallBack,this);
	std::cout<<"map_loadge_run"<<std::endl;
	ros::Rate r(10);
	while(ros::ok()){
		ros::spinOnce();
		r.sleep();
		if(loop_check){
			break;
		}
	}
}

int main(int argc, char* argv[]){
	ros::init(argc,argv,"map_load");
	MapLoad map_load;
       	map_load.mapLoadRun();
	return 0;
}
